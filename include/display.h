#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdio.h>

#ifdef __APPLE__
	#include <ncurses.h>
#else
	#include <curses.h>
#endif

#include "memory_layout.h"
#include "registers.h"
#include "sprites.h"
#include "window.h"
#include "info_wins.h"

#define PIXEL_WIDTH (64 + 2)
#define PIXEL_HEIGHT (32 + 2)

#define DISPLAY_WIDTH PIXEL_WIDTH
#define DISPLAY_HEIGHT (PIXEL_HEIGHT / BYTE_SIZE)

#define PIXEL_0 0x01
#define PIXEL_1 0x02
#define PIXEL_2 0x04
#define PIXEL_3 0x08
#define PIXEL_4 0x10
#define PIXEL_5 0x20
#define PIXEL_6 0x40
#define PIXEL_7 0x80

#define X_UPPER 64
#define Y_UPPER 32

extern byte sprites[DISPLAY_HEIGHT][DISPLAY_WIDTH];
extern byte framebuffer[DISPLAY_HEIGHT * DISPLAY_WIDTH];

void displayStart();
void displaySplash();
void setPixels(int x, int y, int height, word addr);
void printDisplay();
void clearDisplay();

#endif //DISPLAY_H
