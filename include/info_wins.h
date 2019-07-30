#ifndef INFO_WINS_H
#define INFO_WINS_H

#include <string.h>
#ifdef __APPLE__
	#include <ncurses.h>
#else
	#include <curses.h>
#endif

#include "display.h"

/*		64				32
 /	+---------------+-------+
 /	|				|		|
 /	|				|		| 32
 /	|				|		|
 /	+---------------+-------+
 /	|						|
 /	|						| 32
 /	|						|
 /	+-----------------------+
 /				96
 */

extern WINDOW *instrWin;
extern WINDOW *debugWin;

#define INSTR_WIDTH (32 + 2)
#define INSTR_HEIGHT (32 + 2)

#define INSTR_X (64 + 2) + 1
#define INSTR_Y 0 + 1

#define DEBUG_WIDTH (96 + 2)
#define DEBUG_HEIGHT (32 + 2)

#define DEBUG_X 0 + 1
#define DEBUG_Y (32 + 2) + 1

void initWins(WINDOW *mainWin);
void printDebug(char *msg);
void printInstr(char *msg);

#endif //INFO_WINS_H
