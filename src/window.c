#include "window.h"

void printBoxes() {
	//outer box
	mvwaddch(win, WIN_Y, WIN_X, ACS_ULCORNER);
	mvwaddch(win, WIN_Y, WIN_X + WIN_W - 1, ACS_URCORNER);
	mvwaddch(win, WIN_Y + WIN_H - 1, WIN_X, ACS_LLCORNER);
	mvwaddch(win, WIN_Y + WIN_H - 1, WIN_X + WIN_W - 1, ACS_LRCORNER);
	wmove(win, WIN_Y + 1, WIN_X);
	wvline(win, ACS_VLINE, WIN_H - 2);
	wmove(win, WIN_Y, WIN_X + 1);
	whline(win, ACS_HLINE, WIN_W - 2);
	wmove(win, WIN_Y + 1, WIN_X + WIN_W - 1);
	wvline(win, ACS_VLINE, WIN_H - 2);
	wmove(win, WIN_Y + WIN_H - 1, WIN_X + 1);
	whline(win, ACS_HLINE, WIN_W - 2);

	//display box
	mvwaddch(win, DISP_Y - 1, DISP_X - 1, ACS_ULCORNER);
	mvwaddch(win, DISP_Y - 1, DISP_X + DISP_W, ACS_URCORNER);
	mvwaddch(win, DISP_Y + DISP_H , DISP_X - 1, ACS_LLCORNER);
	mvwaddch(win, DISP_Y + DISP_H , DISP_X + DISP_W, ACS_LRCORNER);
	wmove(win, DISP_Y, DISP_X - 1);
	wvline(win, ACS_VLINE, DISP_H);
	wmove(win, DISP_Y - 1, DISP_X);
	whline(win, ACS_HLINE, DISP_W);
	wmove(win, DISP_Y, DISP_X + DISP_W);
	wvline(win, ACS_VLINE, DISP_H);
	wmove(win, DISP_Y + DISP_H, DISP_X);
	whline(win, ACS_HLINE, DISP_W);

	//instructions box
	mvwaddch(win, INSTR_Y - 1, INSTR_X - 1, ACS_ULCORNER);
	mvwaddch(win, INSTR_Y - 1, INSTR_X + INSTR_W, ACS_URCORNER);
	mvwaddch(win, INSTR_Y + INSTR_H, INSTR_X - 1, ACS_LLCORNER);
	mvwaddch(win, INSTR_Y + INSTR_H, INSTR_X + INSTR_W, ACS_LRCORNER);
	wmove(win, INSTR_Y, INSTR_X - 1);
	wvline(win, ACS_VLINE, INSTR_H);
	wmove(win, INSTR_Y - 1, INSTR_X);
	whline(win, ACS_HLINE, INSTR_W);
	wmove(win, INSTR_Y, INSTR_X + INSTR_W);
	wvline(win, ACS_VLINE, INSTR_H);
	wmove(win, INSTR_Y + INSTR_H, INSTR_X);
	whline(win, ACS_HLINE, INSTR_W);

	//debug box
	mvwaddch(win, DEBUG_Y - 1, DEBUG_X - 1, ACS_ULCORNER);
	mvwaddch(win, DEBUG_Y - 1, DEBUG_X + DEBUG_W, ACS_URCORNER);
	mvwaddch(win, DEBUG_Y + DEBUG_H, DEBUG_X - 1, ACS_LLCORNER);
	mvwaddch(win, DEBUG_Y + DEBUG_H, DEBUG_X + DEBUG_W, ACS_LRCORNER);
	wmove(win, DEBUG_Y, DEBUG_X - 1);
	wvline(win, ACS_VLINE, DEBUG_H);
	wmove(win, DEBUG_Y - 1, DEBUG_X );
	whline(win, ACS_HLINE, DEBUG_W);
	wmove(win, DEBUG_Y, DEBUG_X + DEBUG_W);
	wvline(win, ACS_VLINE, DEBUG_H);
	wmove(win, DEBUG_Y + DEBUG_H, DEBUG_X);
	whline(win, ACS_HLINE, DEBUG_W);
}

void refreshWins() {
	wrefresh(display);
	wrefresh(debug);
	wrefresh(instructions);
	touchwin(win);
	wrefresh(win);
}

void initWins() {
	initscr();
	win = newwin(WIN_H, WIN_W, 0, 0);
	display = subwin(win, DISP_H, DISP_W, DISP_Y, DISP_X);
	debug = subwin(win, DEBUG_H, DEBUG_W, DEBUG_Y, DEBUG_X);
	instructions = subwin(win, INSTR_H, INSTR_W, INSTR_Y, INSTR_X);

	scrollok(debug, TRUE);
	scrollok(instructions, TRUE);

	printBoxes();

	touchwin(win);
	wrefresh(win);
}
