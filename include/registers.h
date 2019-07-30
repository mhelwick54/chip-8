#ifndef REGISTERS_H
#define REGISTERS_H

#include "memory_layout.h"

extern byte registers[18];

#define V0 (registers[0x0])
#define V1 (registers[0x1])
#define V2 (registers[0x2])
#define V3 (registers[0x3])
#define V4 (registers[0x4])
#define V5 (registers[0x5])
#define V6 (registers[0x6])
#define V7 (registers[0x7])
#define V8 (registers[0x8])
#define V9 (registers[0x9])
#define VA (registers[0xa])
#define VB (registers[0xb])
#define VC (registers[0xc])
#define VD (registers[0xd])
#define VE (registers[0xe])
#define VF (registers[0xf])

#define DELAY_TIMER (registers[0x10])
#define SOUND_TIMER (registers[0x11])

extern byte stack_pointer;
#define SP stack_pointer

#define INC_SP(s) (s += 2)
#define DEC_SP(s) (s -= 2)

extern word program_counter;
#define PC program_counter

#define INC_PC(p) (p += 2)
#define SET_PC(p, addr) (p = addr)

#endif //REGISTERS_H
