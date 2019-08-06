#ifndef REGISTERS_H
#define REGISTERS_H

#include "memory_layout.h"

/*
┌────────────────────────────────┐
│                                │
│  Registers    Stack            │
│                                │
│  VF: 0x00     0xebc: 0x0000    │
│  VE: 0x00     0xeba: 0x0000    │
│  VD: 0x00     0xeb8: 0x0000    │
│  VC: 0x00     0xeb6: 0x0000    │
│  VB: 0x00     0xeb4: 0x0000    │
│  VA: 0x00     0xeb2: 0x0000    │
│  V9: 0x00     0xeb0: 0x0000    │
│  V8: 0x00     0xeae: 0x0000    │
│  V7: 0x00     0xeac: 0x0000    │
│  V6: 0x00     0xeac: 0x0000    │
│  V5: 0x00     0xeaa: 0x0000    │
│  V4: 0x00     0xea8: 0x0000    │
│  V3: 0x00     0xea6: 0x0000    │
│  V2: 0x00     0xea4: 0x0000    │
│  V1: 0x00     0xea2: 0x0000    │
│  V0: 0x00     0xea0: 0x0000    │
│                                │
│  I:  0x0000                    │
│                                │
│  DT: 0x00      SP: 0xfe        │
│  ST: 0x00      PC: 0x0200      │
│                                │
│  ┌───────────────┐             │
│  | 1 | 2 | 3 | C |             │
│  | 4 | 5 | 6 | D |             │
│  | 7 | 8 | 9 | E |             │
│  | A | 0 | B | F |             │
│  └───────────────┘             │
│                                │
└────────────────────────────────┘
 */

/*******************************************************************************
 *	Chip-8 has 16 1-byte registers for general use, although conventionally the
 *	VF register is reserved for indicating carries and the like. See
 *	http://devernay.free.fr/hacks/chip8/C8TECH10.HTM#3.0 for a reference of
 *	instructions that set VF.
 *	There is also a register I that is one word long. It is used for addressing
 *	memory locations in instructions like DRW.
 *	Two timers, delay timer (DT) and sound timer (ST) that tick down at 60Hz.
 *	Stack pointer that is only a byte, since it addresses within the 16-byte
 *	stack only.
 *	Program counter that is one word, points to the current instruction address.
 ******************************************************************************/

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

#define DT (registers[0x10])
#define ST (registers[0x11])

extern word address_reg;
#define I address_reg

extern byte stack_pointer;
#define SP stack_pointer

#define INC_SP(s) (s += 2)
#define DEC_SP(s) (s -= 2)

extern word program_counter;
#define PC program_counter

#define INC_PC(p) (p += 2)
#define DEC_PC(p) (p -= 2)
#define SET_PC(p, addr) (p = addr)

void initRegisters();

#endif //REGISTERS_H
