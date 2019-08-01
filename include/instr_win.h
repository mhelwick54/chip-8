#ifndef INSTR_WIN_H
#define INSTR_WIN_H

#ifdef __APPLE__
	#include <ncurses.h>
#else
	#include <curses.h>
#endif

#include "window.h"

void setInstr(char *msg);

#endif //INSTR_WIN_H
