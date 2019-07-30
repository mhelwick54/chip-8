#include "display.h"

void setPixels(int x, int y, int height, word addr) {
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
			//printf("writing pixel (0x%02x << 0x%02x, %d)\n", x / BYTE_SIZE, mask, y + i);
			byte sprite_line = MEM_READ(addr + i);
			byte collision = framebuffer[start_row + (i * BYTE_SIZE) + (x / BYTE_SIZE)] ^ (sprite_line << x_offset & mask << x_offset);
			framebuffer[start_row + (i * BYTE_SIZE) + (x / BYTE_SIZE)] =
					framebuffer[start_row + (i * BYTE_SIZE) + (x / BYTE_SIZE)] ^ (sprite_line << x_offset & mask << x_offset);
			if((framebuffer[start_row + (i * BYTE_SIZE) + (x / BYTE_SIZE)] & mask) != (collision & mask)) {
				VF = 0x01;
			} else {
				VF = 0x00;
			}
			mask = mask >> 1;
		}
		if(x_offset != 0) {
			x -= BYTE_SIZE;
			if(x < 0) {
				x = X_UPPER + x;
			}
			x_offset = BYTE_SIZE - x_offset;
			mask = 0x1 << (BYTE_SIZE - x_offset - 1);
			//printf("%d %d\n", x, x_offset);
			while(mask != 0) {
				//printf("writing pixel (0x%02x << 0x%02x, %d)\n", (x + 1) / BYTE_SIZE, mask, y + i);
				byte sprite_line = MEM_READ(addr + i);
				byte collision = framebuffer[start_row + (i * BYTE_SIZE) + ((x + 1) / BYTE_SIZE)] ^ (sprite_line >> x_offset & mask);
				framebuffer[start_row + (i * BYTE_SIZE) + ((x + 1) / BYTE_SIZE)] =
						framebuffer[start_row + (i * BYTE_SIZE) + ((x + 1) / BYTE_SIZE)] ^ (sprite_line >> x_offset & mask);
				if((framebuffer[start_row + (i * BYTE_SIZE) + ((x + 1) / BYTE_SIZE)] & mask) != (collision & mask)) {
					VF = 0x01;
				} else {
					VF = 0x00;
				}
				mask = mask >> 1;
			}
		}
	}
}

void printDisplay() {
	printf("   00        10        20        30        40        50        60 63\n");
	printf("  +----------------------------------------------------------------+\n");
	int i = 0, shift = 0;
	for(i = 0; i < DISPLAY_HEIGHT * DISPLAY_WIDTH; ++i) {
		if(i % 8 == 0) {
			printf("%2d|", i / BYTE_SIZE);
		}
		for(shift = BYTE_SIZE - 1; shift >= 0; --shift) {
			if((framebuffer[i] & (0x1 << shift)) != 0) {
				printf("*");
			} else {
				printf(" ");
			}
		}
		if(i % 8 == 7) {
			printf("|%2d\n", i / BYTE_SIZE);
		}
	}
	printf("  +----------------------------------------------------------------+\n");
	printf("   00        10        20        30        40        50        60 63\n");
}

void clearDisplay() {
	int i = 0;
	for(i = 0; i < DISPLAY_HEIGHT * DISPLAY_WIDTH; ++i) {
		framebuffer[i] = 0;
	}
}