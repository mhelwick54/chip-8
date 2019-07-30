#include "info_wins.h"

void initWins(WINDOW *mainWin) {
	instrWin = subwin(mainWin, INSTR_HEIGHT, INSTR_WIDTH, INSTR_Y, INSTR_X);
	debugWin = subwin(mainWin, DEBUG_HEIGHT, DEBUG_WIDTH, DEBUG_Y, DEBUG_X);
}

void printDebug(char *msg) {
	int y, x;
	getyx(debugWin, y, x);
	wmove(debugWin, y, x + 1);

	waddstr(debugWin, msg);
	wrefresh(debugWin);
}

void printInstr(char *msg) {
	int y, x;
	getyx(instrWin, y, x);
	wmove(instrWin, y, x + 1);

	waddstr(instrWin, msg);
	wrefresh(instrWin);
}
