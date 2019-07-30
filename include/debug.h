#ifndef DEBUG_HEAD_H
#define DEBUG_HEAD_H

#ifdef __APPLE__
	#include <ncurses.h>
#else
	#include <curses.h>
#endif

#include "window.h"

void setDebug();

#endif //DEBUG_HEAD_H
