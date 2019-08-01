#ifndef MEM_LAYOUT_H
#define MEM_LAYOUT_H

#include <stdint.h>

/*
+---------------+= 0xFFF (4095) End of Chip-8 RAM
|               |
|               |
|               |
|               |
|               |
| 0x200 to 0xFFF|
|     Chip-8    |
| Program / Data|
|     Space     |
|               |
|               |
|               |
+- - - - - - - -+= 0x600 (1536) Start of ETI 660 Chip-8 programs
|               |
|               |
|               |
+---------------+= 0x200 (512) Start of most Chip-8 programs
| 0x000 to 0x1FF|
| Reserved for  |
|  interpreter  |
+---------------+= 0x000 (0) Start of Chip-8 RAM
*/

typedef uint8_t byte;
typedef uint16_t word;

#define BYTE_SIZE			8

#define MEM_BYTES 			0x1000
						//	4096 bytes
#define RESERVED_MEM_BYTES	0x0200
						//	512 bytes
#define RESERVED_HEX_SPACE	0x0080
						//	reserved to hold hex digit sprites
#define RESERVED_FONT_SPACE 0x0100
#define RESERVED_OFFSET		0x0000
#define DATA_OFFSET			(RESERVED_OFFSET + RESERVED_MEM_BYTES)
#define MAX_ADDR			0x0fff

extern byte *memory;

#define MEM_READ(addr) (*(memory + (addr)))
#define MEM_WRITE(addr, val) (*(memory + (addr)) = (val))

#define STACK_SIZE 	0x010
#define STACK_BOT	0xea0
#define STACK_TOP 	(STACK_BOT + STACK_SIZE)
#define STACK_START 0xfe

#define UPPER_READ(addr) ((*(memory + (addr) + 1)) << 8)
#define LOWER_READ(addr) (*(memory + (addr)))

#define UPPER_WRITE(addr, val) (*(memory + (addr) + 1) = ((val) >> 8))
#define LOWER_WRITE(addr, val) (*(memory + (addr)) = (val))

#define STACK_READ(addr) (UPPER_READ(STACK_BOT + (addr) - 1) ^ LOWER_READ(STACK_BOT + (addr) - 1))
//#define STACK_READ(addr) (((*(memory + STACK_BOT + (addr))) << 8) ^ (*(memory + STACK_BOT + (addr) - 1)))
#define STACK_WRITE(addr, val) (UPPER_WRITE(STACK_BOT + (addr) - 1, (val)), LOWER_WRITE(STACK_BOT + (addr) - 1, (val)))
//#define STACK_WRITE(addr, val) ((*(memory + STACK_BOT + (addr) - 1) = (val) & 0x00ff), (*(memory + STACK_BOT + (addr)) = ((val) & 0xff00) >> 8))

#define FRAME_BUFF_SIZE 0x100
#define FRAME_BUFF		0xf00

#define FRAME_BUFF_READ(offset) (*(memory + FRAME_BUFF + (offset)))
#define FRAME_BUFF_WRITE(offset, val) (*(memory + FRAME_BUFF + (offset)) = (val))

#endif //MEM_LAYOUT_H
