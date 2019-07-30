#ifndef SPRITES_H
#define SPRITES_H

#include <stdio.h>
#include <stdarg.h>

#include "memory_layout.h"

#define SPRITE_MAX_WIDTH 8
#define SPRITE_MAX_HEIGHT 15

#define SPRITE_HEX_0 (RESERVED_OFFSET + 0x00)
#define SPRITE_HEX_1 (RESERVED_OFFSET + 0x05)
#define SPRITE_HEX_2 (RESERVED_OFFSET + 0x0a)
#define SPRITE_HEX_3 (RESERVED_OFFSET + 0x0f)
#define SPRITE_HEX_4 (RESERVED_OFFSET + 0x14)
#define SPRITE_HEX_5 (RESERVED_OFFSET + 0x19)
#define SPRITE_HEX_6 (RESERVED_OFFSET + 0x1e)
#define SPRITE_HEX_7 (RESERVED_OFFSET + 0x23)
#define SPRITE_HEX_8 (RESERVED_OFFSET + 0x28)
#define SPRITE_HEX_9 (RESERVED_OFFSET + 0x2d)
#define SPRITE_HEX_A (RESERVED_OFFSET + 0x32)
#define SPRITE_HEX_B (RESERVED_OFFSET + 0x37)
#define SPRITE_HEX_C (RESERVED_OFFSET + 0x3c)
#define SPRITE_HEX_D (RESERVED_OFFSET + 0x41)
#define SPRITE_HEX_E (RESERVED_OFFSET + 0x46)
#define SPRITE_HEX_F (RESERVED_OFFSET + 0x4b)

#define SPRITE_SPLASH_C 	(RESERVED_OFFSET + 0x50)
#define SPRITE_SPLASH_H 	(RESERVED_OFFSET + 0x55)
#define SPRITE_SPLASH_I 	(RESERVED_OFFSET + 0x5a)
#define SPRITE_SPLASH_P 	(RESERVED_OFFSET + 0x5f)
#define SPRITE_SPLASH_DASH 	(RESERVED_OFFSET + 0x64)
#define SPRITE_SPLASH_8		(RESERVED_OFFSET + 0x69)

#define FONT_OFFSET (SPRITE_SPLASH_8 + 0x5)

/*
#define SPRITE_AT 		(FONT_OFFSET + 0x00)
#define SPRITE_A 		(FONT_OFFSET + 0x03)
#define SPRITE_B 		(FONT_OFFSET + 0x06)
#define SPRITE_C 		(FONT_OFFSET + 0x09)
#define SPRITE_D 		(FONT_OFFSET + 0x0c)
#define SPRITE_E 		(FONT_OFFSET + 0x0f)
#define SPRITE_F 		(FONT_OFFSET + 0x12)
#define SPRITE_G 		(FONT_OFFSET + 0x15)
#define SPRITE_H 		(FONT_OFFSET + 0x18)
#define SPRITE_I 		(FONT_OFFSET + 0x1b)
#define SPRITE_J 		(FONT_OFFSET + 0x1e)
#define SPRITE_K 		(FONT_OFFSET + 0x21)
#define SPRITE_L 		(FONT_OFFSET + 0x24)
#define SPRITE_M 		(FONT_OFFSET + 0x27)
#define SPRITE_N 		(FONT_OFFSET + 0x2a)
#define SPRITE_O 		(FONT_OFFSET + 0x2d)
#define SPRITE_P 		(FONT_OFFSET + 0x30)
#define SPRITE_Q 		(FONT_OFFSET + 0x33)
#define SPRITE_R 		(FONT_OFFSET + 0x36)
#define SPRITE_S 		(FONT_OFFSET + 0x39)
#define SPRITE_T 		(FONT_OFFSET + 0x3c)
#define SPRITE_U 		(FONT_OFFSET + 0x3f)
#define SPRITE_V 		(FONT_OFFSET + 0x42)
#define SPRITE_W 		(FONT_OFFSET + 0x45)
#define SPRITE_X 		(FONT_OFFSET + 0x48)
#define SPRITE_Y 		(FONT_OFFSET + 0x4b)
#define SPRITE_Z 		(FONT_OFFSET + 0x4e)
#define SPRITE_L_SQ 	(FONT_OFFSET + 0x51)
#define SPRITE_BKSLSH 	(FONT_OFFSET + 0x54)
#define SPRITE_R_SQ 	(FONT_OFFSET + 0x57)
#define SPRITE_CARROT 	(FONT_OFFSET + 0x5a)
#define SPRITE_UNDER 	(FONT_OFFSET + 0x5d)
#define SPRITE_SPACE 	(FONT_OFFSET + 0x60)
#define SPRITE_EXCL 	(FONT_OFFSET + 0x63)
#define SPRITE_DBL_Q 	(FONT_OFFSET + 0x66)
#define SPRITE_PND 		(FONT_OFFSET + 0x69)
#define SPRITE_DLR 		(FONT_OFFSET + 0x6c)
#define SPRITE_PER 		(FONT_OFFSET + 0x6f)
#define SPRITE_AMP 		(FONT_OFFSET + 0x72)
#define SPRITE_SNG_Q 	(FONT_OFFSET + 0x75)
#define SPRITE_L_PAR 	(FONT_OFFSET + 0x78)
#define SPRITE_R_PAR 	(FONT_OFFSET + 0x7b)
#define SPRITE_AST 		(FONT_OFFSET + 0x7e)
#define SPRITE_PLUS 	(FONT_OFFSET + 0x81)
#define SPRITE_COM 		(FONT_OFFSET + 0x84)
#define SPRITE_DASH 	(FONT_OFFSET + 0x87)
#define SPRITE_PRD 		(FONT_OFFSET + 0x8a)
#define SPRITE_SLASH 	(FONT_OFFSET + 0x8d)
#define SPRITE_0 		(FONT_OFFSET + 0x90)
#define SPRITE_1 		(FONT_OFFSET + 0x93)
#define SPRITE_2 		(FONT_OFFSET + 0x96)
#define SPRITE_3 		(FONT_OFFSET + 0x99)
#define SPRITE_4 		(FONT_OFFSET + 0x9c)
#define SPRITE_5 		(FONT_OFFSET + 0x9f)
#define SPRITE_6 		(FONT_OFFSET + 0xa2)
#define SPRITE_7 		(FONT_OFFSET + 0xa5)
#define SPRITE_8 		(FONT_OFFSET + 0xa8)
#define SPRITE_9 		(FONT_OFFSET + 0xab)
#define SPRITE_COL 		(FONT_OFFSET + 0xae)
#define SPRITE_SEMI_COL (FONT_OFFSET + 0xb1)
#define SPRITE_L_ARR 	(FONT_OFFSET + 0xb4)
#define SPRITE_EQ 		(FONT_OFFSET + 0xb7)
#define SPRITE_R_ARR 	(FONT_OFFSET + 0xba)
#define SPRITE_QUE 		(FONT_OFFSET + 0xbd)
*/

void setSprite(word sprite, int bytes, ...);
void setSprites();
void printAtAddr(word addr);
void printFromAddr(word sprite);
void printSprite(char c);

#endif //SPRITES_H
