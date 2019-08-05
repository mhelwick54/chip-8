#include "display.h"

void displaySplash() {
	setPixels(4, 12, 5, SPRITE_SPLASH_C);
	setPixels(14, 12, 5, SPRITE_SPLASH_H);
	setPixels(24, 12, 5, SPRITE_SPLASH_I);
	setPixels(34, 12, 5, SPRITE_SPLASH_P);
	setPixels(44, 12, 5, SPRITE_SPLASH_DASH);
	setPixels(54, 12, 5, SPRITE_SPLASH_8);
	setDisplay();
	refreshWins();
}

void setPixels(int x, int y, int height, word addr) {
	char buff[64];
	char c;
	VF = 0;
	int start_row = (y * BYTE_SIZE);
	int x_offset = x % BYTE_SIZE;
	//printf("%d %d\n", start_row, x_offset);

	int i = 0;
	for(i = 0; i < height; ++i) {
		if(x_offset != 0) {
			x += BYTE_SIZE;
			if(x > X_UPPER) {
				x = x % 8;
			}
			x_offset = BYTE_SIZE - (x % BYTE_SIZE);
		}
		if(y + i == Y_UPPER) {
			start_row -= Y_UPPER * BYTE_SIZE;
		}
		byte mask = 0x1 << (BYTE_SIZE - x_offset - 1);
		//printf("%d %d\n", x, x_offset);
		while(mask != 0) {
			sprintf(buff, "(first) writing pixel (0x%02x << 0x%02x, %d)\n", x / BYTE_SIZE, mask, y + i);
			setDebug(buff);
			refreshDebug();
			byte sprite_line = MEM_READ(addr + i);

			byte offset = start_row + (i * BYTE_SIZE) + (x / BYTE_SIZE);
			byte readfrom = FRAME_BUFF_READ(offset);
			byte collision = readfrom & mask;
			byte towrite = readfrom ^ (sprite_line << x_offset & mask << x_offset);
			FRAME_BUFF_WRITE(offset, towrite);
			offset = start_row + (i * BYTE_SIZE) + ((x + 1) / BYTE_SIZE);
			readfrom = FRAME_BUFF_READ(offset);
			if(((offset & mask) == 0) && (collision != 0)) {
				VF = 0x01;
			}
			mask = mask >> 1;
			//scanf("%c", &c);
		}
		if(x_offset != 0 && mask != 1) {
			x -= BYTE_SIZE;
			if(x < 0) {
				x = X_UPPER + x;
			}
			x_offset = BYTE_SIZE - x_offset;
			mask = 0x1 << (BYTE_SIZE - x_offset - 1);
			//printf("%d %d\n", x, x_offset);
			while(mask != 0) {
				sprintf(buff, "(second) writing pixel (0x%02x << 0x%02x, %d)\n", (x + 1) / BYTE_SIZE, mask, y + i);
				setDebug(buff);
				refreshDebug();
				byte sprite_line = MEM_READ(addr + i);

				byte offset = start_row + (i * BYTE_SIZE) + (x / BYTE_SIZE);
				byte readfrom = FRAME_BUFF_READ(offset);
				byte collision = readfrom & mask;
				offset = start_row + (i * BYTE_SIZE) + ((x + 1) / BYTE_SIZE);
				readfrom = FRAME_BUFF_READ(offset);
				byte towrite = readfrom ^ (sprite_line >> x_offset & mask);
				FRAME_BUFF_WRITE(offset, towrite);
				offset = start_row + (i * BYTE_SIZE) + ((x + 1) / BYTE_SIZE);
				readfrom = FRAME_BUFF_READ(offset);
				if(((offset & mask) == 0) && (collision != 0)) {
					VF = 0x01;
				}
				mask = mask >> 1;
				//scanf("%c", &c);
			}
		}
	}
}

void setDisplay() {
	int i = 0, shift = 0;
	wmove(display, 0, 0);
	for(i = 0; i < DISPLAY_HEIGHT * DISPLAY_WIDTH; ++i) {
		for(shift = BYTE_SIZE - 1; shift >= 0; --shift) {
			if((FRAME_BUFF_READ(i) & (0x1 << shift)) != 0) {
				waddch(display, ACS_CKBOARD);
			} else {
				waddch(display, ' ');
			}
		}
	}
}

void clearDisplay() {
	int i = 0;
	for(i = 0; i < DISPLAY_HEIGHT * DISPLAY_WIDTH; ++i) {
		FRAME_BUFF_WRITE(i, 0);
	}
	setDisplay();
}
