#ifndef REG_WIN_H
#define REG_WIN_H

#ifdef __APPLE__
	#include <ncurses.h>
#else
	#include <curses.h>
#endif

#include "registers.h"
#include "window.h"

/*
 /	+--------------------------------+
 /	| Registers		Stack			 |
 /	|								 |
 /	| V0: 0x00		0xebc: 0x0000	 |
 /	| V1: 0x00		0xeba: 0x0000	 |
 /	| V2: 0x00		0xeb8: 0x0000	 |
 /	| V3: 0x00		0xeb6: 0x0000	 |
 /	| V4: 0x00		0xeb4: 0x0000	 |
 /	| V5: 0x00		0xeb2: 0x0000 <	 |
 /	| V6: 0x00		0xeb0: 0x0000	 |
 /	| V7: 0x00		0xeae: 0x0000	 |
 /	| V8: 0x00		0xeac: 0x0000	 |
 /	| V9: 0x00		0xeac: 0x0000	 |
 /	| VA: 0x00		0xeaa: 0x0000	 |
 /	| VB: 0x00		0xea8: 0x0000	 |
 /	| VC: 0x00		0xea6: 0x0000	 |
 /	| VD: 0x00		0xea4: 0x0000	 |
 /	| VE: 0x00		0xea2: 0x0000	 |
 /	| VF: 0x00		0xea0: 0x0000	 |
 /	|								 |
 /	| I:  0x0000					 |
 /	|								 |
 /	| DT: 0x00						 |
 /	| ST: 0x00						 |
 /	|								 |
 /	| SP: 0x00						 |
 /	| PC: 0x0000					 |
 /	|								 |
 /	|								 |
 /	|								 |
 /	|								 |
 /	|								 |
 /	|								 |
 /	+--------------------------------+
 */

void initRegs();
void printRegs();

#endif //REG_WIN_H
