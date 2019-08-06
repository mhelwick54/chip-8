#ifndef REG_WIN_H
#define REG_WIN_H

#ifdef __APPLE__
	#include <ncurses.h>
#else
	#include <curses.h>
#endif

#include "registers.h"
#include "window.h"
#include "keys.h"

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

void initRegs();
void printRegs();

/*******************************************************************************
 *	A bunch of coordinates. Look at the picture above, it's easier even if you
 *	have to count.
 ******************************************************************************/
#define VF_X 2
#define VF_Y 3
#define VE_X VF_X
#define VE_Y (VF_Y + 1)
#define VD_X VF_X
#define VD_Y (VE_Y + 1)
#define VC_X VF_X
#define VC_Y (VD_Y + 1)
#define VB_X VF_X
#define VB_Y (VC_Y + 1)
#define VA_X VF_X
#define VA_Y (VB_Y + 1)
#define V9_X VF_X
#define V9_Y (VA_Y + 1)
#define V8_X VF_X
#define V8_Y (V9_Y + 1)
#define V7_X VF_X
#define V7_Y (V8_Y + 1)
#define V6_X VF_X
#define V6_Y (V7_Y + 1)
#define V5_X VF_X
#define V5_Y (V6_Y + 1)
#define V4_X VF_X
#define V4_Y (V5_Y + 1)
#define V3_X VF_X
#define V3_Y (V4_Y + 1)
#define V2_X VF_X
#define V2_Y (V3_Y + 1)
#define V1_X VF_X
#define V1_Y (V2_Y + 1)
#define V0_X VF_X
#define V0_Y (V1_Y + 1)

#define STACK_F_X 15
#define STACK_F_Y 3
#define STACK_E_X STACK_F_X
#define STACK_E_Y (STACK_F_Y + 1)
#define STACK_D_X STACK_F_X
#define STACK_D_Y (STACK_E_Y + 1)
#define STACK_C_X STACK_F_X
#define STACK_C_Y (STACK_D_Y + 1)
#define STACK_B_X STACK_F_X
#define STACK_B_Y (STACK_C_Y + 1)
#define STACK_A_X STACK_F_X
#define STACK_A_Y (STACK_B_Y + 1)
#define STACK_9_X STACK_F_X
#define STACK_9_Y (STACK_A_Y + 1)
#define STACK_8_X STACK_F_X
#define STACK_8_Y (STACK_9_Y + 1)
#define STACK_7_X STACK_F_X
#define STACK_7_Y (STACK_8_Y + 1)
#define STACK_6_X STACK_F_X
#define STACK_6_Y (STACK_7_Y + 1)
#define STACK_5_X STACK_F_X
#define STACK_5_Y (STACK_6_Y + 1)
#define STACK_4_X STACK_F_X
#define STACK_4_Y (STACK_5_Y + 1)
#define STACK_3_X STACK_F_X
#define STACK_3_Y (STACK_4_Y + 1)
#define STACK_2_X STACK_F_X
#define STACK_2_Y (STACK_3_Y + 1)
#define STACK_1_X STACK_F_X
#define STACK_1_Y (STACK_2_Y + 1)
#define STACK_0_X STACK_F_X
#define STACK_0_Y (STACK_1_Y + 1)

#define I_X		2
#define I_Y		20
#define DT_X	2
#define DT_Y	22
#define ST_X	2
#define ST_Y	23
#define SP_X	15
#define SP_Y	22
#define PC_X	15
#define PC_Y	23

#define KEY_0_X 8
#define KEY_0_Y 29
#define KEY_1_X 4
#define KEY_1_Y 26
#define KEY_2_X 8
#define KEY_2_Y 26
#define KEY_3_X 12
#define KEY_3_Y 26
#define KEY_4_X 4
#define KEY_4_Y 27
#define KEY_5_X 8
#define KEY_5_Y 27
#define KEY_6_X 12
#define KEY_6_Y 27
#define KEY_7_X 4
#define KEY_7_Y 28
#define KEY_8_X 8
#define KEY_8_Y 28
#define KEY_9_X 12
#define KEY_9_Y 28
#define KEY_A_X 4
#define KEY_A_Y 29
#define KEY_B_X 12
#define KEY_B_Y 29
#define KEY_C_X 16
#define KEY_C_Y 26
#define KEY_D_X 16
#define KEY_D_Y 27
#define KEY_E_X 16
#define KEY_E_Y 28
#define KEY_F_X 16
#define KEY_F_Y 29

#endif //REG_WIN_H
