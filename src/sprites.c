#include "sprites.h"

void setSprite(word sprite, int num_bytes, ...) {
	va_list args;
	va_start(args, num_bytes);
	int i = 0;
	while(i < num_bytes) {
		byte b = (byte)va_arg(args, int);
		MEM_WRITE(sprite + i, b);
		++i;
	}
	va_end(args);
}

/*******************************************************************************
 *	Loads the sprites for a 5-byte hex font into memory starting at 0x000. Can
 *	add extra sprites here for system fonts or images, or load them with a
 *	program.
 *
 *	setSprite uses the address, the number of bytes, and a corresponding list of
 *	the bytes as hex ints.
 ******************************************************************************/
void setSprites() {
	setSprite(SPRITE_HEX_0, 5, 0xf0, 0x90, 0x90, 0x90, 0xf0);
	setSprite(SPRITE_HEX_1, 5, 0x20, 0x60, 0x20, 0x20, 0x70);
	setSprite(SPRITE_HEX_2, 5, 0xf0, 0x10, 0xf0, 0x80, 0xf0);
	setSprite(SPRITE_HEX_3, 5, 0xf0, 0x10, 0xf0, 0x10, 0xf0);
	setSprite(SPRITE_HEX_4, 5, 0x90, 0x90, 0xf0, 0x10, 0x10);
	setSprite(SPRITE_HEX_5, 5, 0xf0, 0x80, 0xf0, 0x10, 0xf0);
	setSprite(SPRITE_HEX_6, 5, 0xf0, 0x80, 0xf0, 0x90, 0xf0);
	setSprite(SPRITE_HEX_7, 5, 0xf0, 0x10, 0x20, 0x40, 0x40);
	setSprite(SPRITE_HEX_8, 5, 0xf0, 0x90, 0xf0, 0x90, 0xf0);
	setSprite(SPRITE_HEX_9, 5, 0xf0, 0x90, 0xf0, 0x10, 0xf0);
	setSprite(SPRITE_HEX_A, 5, 0xf0, 0x90, 0xf0, 0x90, 0x90);
	setSprite(SPRITE_HEX_B, 5, 0xf0, 0x90, 0xe0, 0x90, 0xf0);
	setSprite(SPRITE_HEX_C, 5, 0xf0, 0x80, 0x80, 0x80, 0xf0);
	setSprite(SPRITE_HEX_D, 5, 0xe0, 0x90, 0x90, 0x90, 0xe0);
	setSprite(SPRITE_HEX_E, 5, 0xf0, 0x80, 0xf0, 0x80, 0xf0);
	setSprite(SPRITE_HEX_F, 5, 0xf0, 0x80, 0xf0, 0x80, 0x80);

	/*
	/	*****	*   *	*****	*****			*****
	/	*		*   *	  *		*   *			*   *
	/	*		*****	  *		*****	*****	*****
	/	*		*   *	  *		*				*   *
	/	*****	*   *	*****	*				*****
	*/

	/*
	/	1111 1000	1000 1000	1111 1000	1111 1000	0000 0000	1111 1000
	/	1000 0000	1000 1000	0010 0000	1000 1000	0000 0000	1000 1000
	/	1000 0000	1111 1000	0010 0000	1111 1000	1111 1000	1111 1000
	/	1000 0000	1000 1000	0010 0000	1000 0000	0000 0000	1000 1000
	/	1111 1000	1000 1000	1111 1000	1000 0000	0000 0000	1111 1000
	*/

	/*
	/	0xf8	0x88	0xf8	0xf8	0x00	0xf8
	/	0x80	0x88	0x20	0x88	0x00	0x88
	/	0x80	0xf8	0x20	0xf8	0xf8	0xf8
	/	0x80	0x88	0x20	0x80	0x00	0x88
	/	0xf8	0x88	0xf8	0x80	0x00	0xf8
	*/

	setSprite(SPRITE_SPLASH_C, 5, 0xf8, 0x80, 0x80, 0x80, 0xf8);
	setSprite(SPRITE_SPLASH_H, 5, 0x88, 0x88, 0xf8, 0x88, 0x88);
	setSprite(SPRITE_SPLASH_I, 5, 0xf8, 0x20, 0x20, 0x20, 0xf8);
	setSprite(SPRITE_SPLASH_P, 5, 0xf8, 0x88, 0xf8, 0x80, 0x80);
	setSprite(SPRITE_SPLASH_DASH, 5, 0x00, 0x00, 0xf8, 0x00, 0x00);
	setSprite(SPRITE_SPLASH_8, 5, 0xf8, 0x88, 0xf8, 0x88, 0xf8);

	//3-byte sprite font, not currently used or loaded into memory
	/*setSprite(SPRITE_AT, 3, 0x46, 0x3E, 0x56);
	setSprite(SPRITE_A, 3, 0x99, 0x9F, 0x4F);
	setSprite(SPRITE_B, 3, 0x5F, 0x57, 0x4F);
	setSprite(SPRITE_C, 3, 0xf0, 0x80, 0xf0);
	setSprite(SPRITE_D, 3, 0x5F, 0x55, 0x4F);
	setSprite(SPRITE_E, 3, 0x8F, 0x8F, 0x4F);
	setSprite(SPRITE_F, 3, 0x88, 0x8F, 0x4F);
	setSprite(SPRITE_G, 3, 0x9F, 0x8B, 0x4F);
	setSprite(SPRITE_H, 3, 0x99, 0x9F, 0x49);
	setSprite(SPRITE_I, 3, 0x27, 0x22, 0x47);
	setSprite(SPRITE_J, 3, 0xAE, 0x22, 0x47);
	setSprite(SPRITE_K, 3, 0xA9, 0xAC, 0x49);
	setSprite(SPRITE_L, 3, 0x8F, 0x88, 0x48);
	setSprite(SPRITE_M, 3, 0x43, 0x64, 0x53);
	setSprite(SPRITE_N, 3, 0x99, 0xDB, 0x49);
	setSprite(SPRITE_O, 3, 0x9F, 0x99, 0x4F);
	setSprite(SPRITE_P, 3, 0x88, 0x9F, 0x4F);
	setSprite(SPRITE_Q, 3, 0x9F, 0x9B, 0x4F);
	setSprite(SPRITE_R, 3, 0xA9, 0x9F, 0x4F);
	setSprite(SPRITE_S, 3, 0x1F, 0x8F, 0x4F);
	setSprite(SPRITE_T, 3, 0x22, 0x22, 0x56);
	setSprite(SPRITE_U, 3, 0x9F, 0x99, 0x49);
	setSprite(SPRITE_V, 3, 0x22, 0x55, 0x53);
	setSprite(SPRITE_W, 3, 0x55, 0x44, 0x54);
	setSprite(SPRITE_X, 3, 0x53, 0x52, 0x53);
	setSprite(SPRITE_Y, 3, 0x22, 0x52, 0x53);
	setSprite(SPRITE_Z, 3, 0xCF, 0x12, 0x4F);
	setSprite(SPRITE_L_SQ, 3, 0x8C, 0x88, 0x3C);
	setSprite(SPRITE_BKSLSH, 3, 0x10, 0xC2, 0x40);
	setSprite(SPRITE_R_SQ, 3, 0x2E, 0x22, 0x3E);
	setSprite(SPRITE_CARROT, 3, 0x30, 0x25, 0x50);
	setSprite(SPRITE_UNDER, 3, 0x06, 0x00, 0x50);
	setSprite(SPRITE_SPACE, 3, 0x00, 0x00, 0x40);
	setSprite(SPRITE_EXCL, 3, 0x0C, 0xCC, 0x2C);
	setSprite(SPRITE_DBL_Q, 3, 0x00, 0x50, 0x45);
	setSprite(SPRITE_PND, 3, 0x65, 0x65, 0x55);
	setSprite(SPRITE_DLR, 3, 0x46, 0x46, 0x56);
	setSprite(SPRITE_PER, 3, 0xDF, 0xBF, 0x4F);
	setSprite(SPRITE_AMP, 3, 0x5F, 0xAF, 0x4E);
	setSprite(SPRITE_SNG_Q, 3, 0x00, 0x80, 0x18);
	setSprite(SPRITE_L_PAR, 3, 0x21, 0x22, 0x41);
	setSprite(SPRITE_R_PAR, 3, 0x12, 0x11, 0x42);
	setSprite(SPRITE_AST, 3, 0x53, 0x56, 0x53);
	setSprite(SPRITE_PLUS, 3, 0x22, 0x26, 0x52);
	setSprite(SPRITE_COM, 3, 0x2E, 0x00, 0x30);
	setSprite(SPRITE_DASH, 3, 0x00, 0x06, 0x50);
	setSprite(SPRITE_PRD, 3, 0xCC, 0x00, 0x20);
	setSprite(SPRITE_SLASH, 3, 0xC0, 0x12, 0x40);
	setSprite(SPRITE_0, 3, 0x9F, 0x99, 0x4F);
	setSprite(SPRITE_1, 3, 0x22, 0x22, 0x32);
	setSprite(SPRITE_2, 3, 0x8F, 0x1F, 0x4F);
	setSprite(SPRITE_3, 3, 0x1F, 0x1F, 0x4F);
	setSprite(SPRITE_4, 3, 0x22, 0xAF, 0x4A);
	setSprite(SPRITE_5, 3, 0x1F, 0x8F, 0x4F);
	setSprite(SPRITE_6, 3, 0x9F, 0x8F, 0x4F);
	setSprite(SPRITE_7, 3, 0x11, 0x11, 0x4F);
	setSprite(SPRITE_8, 3, 0x9F, 0x9F, 0x4F);
	setSprite(SPRITE_9, 3, 0x1F, 0x9F, 0x4F);
	setSprite(SPRITE_COL, 3, 0x80, 0x80, 0x10);
	setSprite(SPRITE_SEMI_COL, 3, 0x2E, 0x20, 0x30);
	setSprite(SPRITE_L_ARR, 3, 0x21, 0x2C, 0x41);
	setSprite(SPRITE_EQ, 3, 0xE0, 0xE0, 0x30);
	setSprite(SPRITE_R_ARR, 3, 0x2C, 0x21, 0x4C);
	setSprite(SPRITE_QUE, 3, 0x88, 0x1F, 0x4F);*/
}

/*******************************************************************************
 *	Finds a single line of a sprite and prints it.
 *	Now defunct, was used in initial testing.
 ******************************************************************************/
void printAtAddr(word addr) {
	byte line = MEM_READ(addr);
	switch(line) {
		case 0x10: printf("   *");
			break;
		case 0x20: printf("  * ");
			break;
		case 0x40: printf(" *  ");
			break;
		case 0x60: printf(" ** ");
			break;
		case 0x70: printf(" ***");
			break;
		case 0x80: printf("*   ");
			break;
		case 0x90: printf("*  *");
			break;
		case 0xe0: printf("*** ");
			break;
		case 0xf0: printf("****");
			break;
		default: printf("unkown sprite component 0x%02x\n", line);
	}
}

/*******************************************************************************
 *	Prints a 5-byte sprite.
 *	Now defunct, was used in initial testing.
 ******************************************************************************/
void printFromAddr(word sprite) {
	printAtAddr(sprite);
	printf("\n");
	printAtAddr(sprite + 1);
	printf("\n");
	printAtAddr(sprite + 2);
	printf("\n");
	printAtAddr(sprite + 3);
	printf("\n");
	printAtAddr(sprite + 4);
}

/*******************************************************************************
 *	Prints a sprite based on the char input.
 *	Now defunct, was used in initial testing.
 ******************************************************************************/
void printSprite(char c) {
	switch(c) {
		case '0': printFromAddr(SPRITE_HEX_0);
			break;
		case '1': printFromAddr(SPRITE_HEX_1);
			break;
		case '2': printFromAddr(SPRITE_HEX_2);
			break;
		case '3': printFromAddr(SPRITE_HEX_3);
			break;
		case '4': printFromAddr(SPRITE_HEX_4);
			break;
		case '5': printFromAddr(SPRITE_HEX_5);
			break;
		case '6': printFromAddr(SPRITE_HEX_6);
			break;
		case '7': printFromAddr(SPRITE_HEX_7);
			break;
		case '8': printFromAddr(SPRITE_HEX_8);
			break;
		case '9': printFromAddr(SPRITE_HEX_9);
			break;
		case 'a': printFromAddr(SPRITE_HEX_A);
			break;
		case 'b': printFromAddr(SPRITE_HEX_B);
			break;
		case 'c': printFromAddr(SPRITE_HEX_C);
			break;
		case 'd': printFromAddr(SPRITE_HEX_D);
			break;
		case 'e': printFromAddr(SPRITE_HEX_E);
			break;
		case 'f': printFromAddr(SPRITE_HEX_F);
			break;
	}
}
