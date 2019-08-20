#ifndef KEY_H
#define KEY_H

/*
 /	+---+---+---+---+	 /	+---+---+---+---+
 /	| 1 | 2 | 3 | C |	 /	| 1 | 2 | 3 | 4 |
 /	+---+---+---+---+	 /	+---+---+---+---+
 /	| 4 | 5 | 6 | D |	 /	| Q | W | E | R |
 /	+---+---+---+---+	 /	+---+---+---+---+
 /	| 7 | 8 | 9 | E |	 /	| A | S | D | F |
 /	+---+---+---+---+	 /	+---+---+---+---+
 /	| A | 0 | B | F |	 /	| Z | X | C | V |
 /	+---+---+---+---+	 /	+---+---+---+---+
 */

#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <string.h>

#include <linux/input.h>

#include "window.h"
#include "debug.h"

extern int keys[16];

extern struct termios tty;

#define KEYPAD_0 120
#define KEYPAD_1 49
#define KEYPAD_2 50
#define KEYPAD_3 51
#define KEYPAD_4 113
#define KEYPAD_5 119
#define KEYPAD_6 101
#define KEYPAD_7 97
#define KEYPAD_8 115
#define KEYPAD_9 100
#define KEYPAD_A 122
#define KEYPAD_B 99
#define KEYPAD_C 52
#define KEYPAD_D 114
#define KEYPAD_E 102
#define KEYPAD_F 118

void 	tty_reset();
void 	tty_set();
int 	kbhit();
int 	kb_getch();

void 	getKey(int key, char *keymap);
void 	getKeys();

int 	keyPressed(int key);
void 	pressKey(int key);
void 	releaseKey(int key);
void 	resetKeys();

#endif //KEY_H
