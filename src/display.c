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

/*******************************************************************************
 *	Function to set the pixels in the frame buffer, found at addresses
 *	0xf00-0xfff. The general idea is to go through and load a sprite at the
 *	correct position by XOR'ing it with the existing pixels, causing a blank in
 *	the event of a collision.
 *
 *	Things get tricky because the frame buffer is represented by a stack of
 *	bytes, instead of a 2d array or the like. So pixels (0,0) - (7,0) make up
 *	the byte at [0xf00], (8,0) - (15,0) make up [0xf01], (1,0) - (8,1) make up
 *	[0xf08], etc. This means that a single sprite, which can be up to 15 pixels
 *	tall, could be spread over 15 byte addresses, with a range of up to
 *	15 * 8 addresses. To handle this, we have to address the byte that the
 *	sprite will exist in by calculating the base address (start_row) from the y
 *	index, and refer to the byte needed as (start_row * i), where i is the
 *	offset from the top byte of the sprite. Then, each line of the sprite is
 *	XOR'd with the appropriate byte in the frame buffer, and shifted bit by bit.
 *
 *	Things get even messier when you look at the possiblity that a sprite might
 *	exist in not only multiple bytes in the x-axis, but also multiple bytes in
 *	the y-axis. To handle this, we have two loops, one in the bytes with the
 *	right half of the sprite, and the second in the original byte calculated.
 *	The calculations for each of the starting x_offset and mask was honestly
 *	mostly found through trial and error than any cohesive approach, so there
 *	may be bugs I haven't found yet.
 ******************************************************************************/
void setPixels(int x, int y, int height, word addr) {
	//char buff[64];
	VF = 0;
	int start_row = (y * BYTE_SIZE);
	int x_offset = x % BYTE_SIZE;

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
		while(mask != 0) {
			byte sprite_line = MEM_READ(addr + i);
			//sprintf(buff, "(first) x=%d y=%d byte=%d mask=0x%02x x_offset=%d sprite=0x%02x\n", x, y + i, x / BYTE_SIZE, mask, x_offset, sprite_line);
			//setDebug(buff);
			//refreshDebug();

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
		}
		if(x_offset != 0 && mask != 1) {
			x -= BYTE_SIZE;
			if(x < 0) {
				x = X_UPPER + x;
			}
			x_offset = BYTE_SIZE - x_offset;
			mask = 0x1 << (BYTE_SIZE - x_offset - 1);
			while(mask != 0) {
				byte sprite_line = MEM_READ(addr + i);
				//sprintf(buff, "(second) x=%d y=%d byte=%d mask=0x%02x x_offset=%d sprite=0x%02x\n", x, y + i, x / BYTE_SIZE, mask, x_offset, sprite_line);
				//setDebug(buff);
				//refreshDebug();

				byte offset = start_row + (i * BYTE_SIZE) + (x / BYTE_SIZE);
				byte readfrom = FRAME_BUFF_READ(offset);
				byte collision = readfrom & mask;
				readfrom = FRAME_BUFF_READ(offset);
				byte towrite = readfrom ^ (sprite_line >> x_offset & mask);
				FRAME_BUFF_WRITE(offset, towrite);
				offset = start_row + (i * BYTE_SIZE) + ((x + 1) / BYTE_SIZE);
				readfrom = FRAME_BUFF_READ(offset);
				if(((offset & mask) == 0) && (collision != 0)) {
					VF = 0x01;
				}
				mask = mask >> 1;
			}
		}
	}
}

/*******************************************************************************
 *	This just reads from the frame buffer and writes to the display window.
 *	Simple after what you just read above.
 ******************************************************************************/
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

/*******************************************************************************
 *	Basically setDisplay but it just sets everything to blank spaces.
 ******************************************************************************/
void clearDisplay() {
	int i = 0;
	for(i = 0; i < DISPLAY_HEIGHT * DISPLAY_WIDTH; ++i) {
		FRAME_BUFF_WRITE(i, 0);
	}
	setDisplay();
}
