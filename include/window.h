#ifndef WINDOW_H
#define WINDOW_H

#ifdef __APPLE__
	#include <ncurses.h>
#else
	#include <curses.h>
#endif

#include "reg_win.h"

extern WINDOW *win;

extern WINDOW *display;
extern WINDOW *debug;
extern WINDOW *instructions;
extern WINDOW *regs;

/*								64 + 32 + 6 = 102
 /					(64)						(32)
 /	   +----------------------------------------------------+
 /	   |+--------------------------------++----------------+|
 /	   ||								 ||				   ||
 /	   ||								 ||				   ||
 /	   ||								 ||		instr	   ||
 /	   ||								 ||				   || (32)
 /	   ||		display					 ||				   ||
 /	   ||								 ||				   ||
 /	   ||								 ||				   ||
 /	   ||								 ||				   ||
 /	   |+--------------------------------++----------------+|		32 + 32 + 4 = 72
 /	   |+--------------------------------++----------------+|
 /	   ||								 ||				   ||
 /	   ||								 ||				   ||
 /	   ||								 ||				   ||
 /	   ||								 ||	  registers	   ||(32)
 /	   ||			debug				 ||				   ||
 /	   ||								 ||				   ||
 /	   ||								 ||				   ||
 /	   ||								 ||				   ||
 /	   |+--------------------------------++----------------+|
 /	   +----------------------------------------------------+
 /						(64)					(32)
 /							64 + 32 + 6 = 102
 */

#define BORDER_OFFSET 2

#define DISP_W 64
#define DISP_H 32
#define DISP_X 2
#define DISP_Y 2

#define INSTR_W 32
#define INSTR_H 32
#define INSTR_X (DISP_W + DISP_X + BORDER_OFFSET)
#define INSTR_Y DISP_Y

#define DEBUG_W 64
#define DEBUG_H 32
#define DEBUG_X DISP_X
#define DEBUG_Y (DISP_H + DISP_Y + BORDER_OFFSET)

#define REG_W 32
#define REG_H 32
#define REG_X (DEBUG_W + DEBUG_X + BORDER_OFFSET)
#define REG_Y (INSTR_H + INSTR_Y + BORDER_OFFSET)

#define WIN_W (DISP_W + INSTR_W + (BORDER_OFFSET * 3))
#define WIN_H (DISP_H + DEBUG_H + (BORDER_OFFSET * 3))
#define WIN_X 0
#define WIN_Y 0

void printBoxes();
void refreshWins();
void initWins();
void refreshInstr();
void refreshDebug();
void refreshReg();
void refreshDisplay();

#endif //WINDOW_H
