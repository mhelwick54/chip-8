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

void setSprite(word sprite, int num_bytes, ...);
void setSprites();
void printAtAddr(word addr);
void printFromAddr(word sprite);
void printSprite(char c);

#endif //SPRITES_H
