#include "keys.h"

void tty_reset() {
	tcsetattr(0, TCSANOW, &tty);
}

void tty_set() {
	struct termios nonblock_tty;
	tcgetattr(0, &tty);
	memcpy(&nonblock_tty, &tty, sizeof(nonblock_tty));
	atexit(tty_reset);
	cfmakeraw(&nonblock_tty);
	tcsetattr(0, TCSANOW, &nonblock_tty);
}

int kbhit() {
	struct timeval tv = { 0L, 0L };
	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(0, &fds);
	return select(1, &fds, NULL, NULL, &tv);
}

int kb_getch() {
	char c;
	int err;
	if((err = read(0, &c, sizeof(c))) < 0) {
		return err;
	} else {
		return c;
	}
}

void getKey(int key, char *keymap) {
	int key_byte = keymap[key / 8];
	int mask = 1 << (key % 8);
	if(key_byte & mask) {
		pressKey(key);
	} else {
		releaseKey(key);
	}
}

void getKeys() {
	FILE *kb = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
	char keymap[KEY_MAX/8 + 1];
	memset(keymap, 0, sizeof(keymap));
	ioctl(fileno(kb), EVIOCGKEY(sizeof(keymap)), keymap);

	getKey(KEYPAD_0, keymap);
	getKey(KEYPAD_1, keymap);
	getKey(KEYPAD_2, keymap);
	getKey(KEYPAD_3, keymap);
	getKey(KEYPAD_4, keymap);
	getKey(KEYPAD_5, keymap);
	getKey(KEYPAD_6, keymap);
	getKey(KEYPAD_7, keymap);
	getKey(KEYPAD_8, keymap);
	getKey(KEYPAD_9, keymap);
	getKey(KEYPAD_A, keymap);
	getKey(KEYPAD_B, keymap);
	getKey(KEYPAD_C, keymap);
	getKey(KEYPAD_D, keymap);
	getKey(KEYPAD_E, keymap);
	getKey(KEYPAD_F, keymap);
}

int keyPressed(int key) {
	switch(key) {
		case KEYPAD_0: { return keys[0]; } break;
		case KEYPAD_1: { return keys[1]; } break;
		case KEYPAD_2: { return keys[2]; } break;
		case KEYPAD_3: { return keys[3]; } break;
		case KEYPAD_4: { return keys[4]; } break;
		case KEYPAD_5: { return keys[5]; } break;
		case KEYPAD_6: { return keys[6]; } break;
		case KEYPAD_7: { return keys[7]; } break;
		case KEYPAD_8: { return keys[8]; } break;
		case KEYPAD_9: { return keys[9]; } break;
		case KEYPAD_A: { return keys[10]; } break;
		case KEYPAD_B: { return keys[11]; } break;
		case KEYPAD_C: { return keys[12]; } break;
		case KEYPAD_D: { return keys[13]; } break;
		case KEYPAD_E: { return keys[14]; } break;
		case KEYPAD_F: { return keys[15]; } break;
		default: { return -1; }
	}
}

void pressKey(int key) {
	char buff[32];
	sprintf(buff, "key pressed %d\n", key);
	setDebug(buff);
	refreshDebug();
	switch(key) {
		case KEYPAD_0: { keys[0] = 1; } break;
		case KEYPAD_1: { keys[1] = 1; } break;
		case KEYPAD_2: { keys[2] = 1; } break;
		case KEYPAD_3: { keys[3] = 1; } break;
		case KEYPAD_4: { keys[4] = 1; } break;
		case KEYPAD_5: { keys[5] = 1; } break;
		case KEYPAD_6: { keys[6] = 1; } break;
		case KEYPAD_7: { keys[7] = 1; } break;
		case KEYPAD_8: { keys[8] = 1; } break;
		case KEYPAD_9: { keys[9] = 1; } break;
		case KEYPAD_A: { keys[10] = 1; } break;
		case KEYPAD_B: { keys[11] = 1; } break;
		case KEYPAD_C: { keys[12] = 1; } break;
		case KEYPAD_D: { keys[13] = 1; } break;
		case KEYPAD_E: { keys[14] = 1; } break;
		case KEYPAD_F: { keys[15] = 1; } break;
	}
}

void releaseKey(int key) {
	char buff[32];
	sprintf(buff, "key released %d\n", key);
	setDebug(buff);
	refreshDebug();
	switch(key) {
		case KEYPAD_0: { keys[0] = 0; } break;
		case KEYPAD_1: { keys[1] = 0; } break;
		case KEYPAD_2: { keys[2] = 0; } break;
		case KEYPAD_3: { keys[3] = 0; } break;
		case KEYPAD_4: { keys[4] = 0; } break;
		case KEYPAD_5: { keys[5] = 0; } break;
		case KEYPAD_6: { keys[6] = 0; } break;
		case KEYPAD_7: { keys[7] = 0; } break;
		case KEYPAD_8: { keys[8] = 0; } break;
		case KEYPAD_9: { keys[9] = 0; } break;
		case KEYPAD_A: { keys[10] = 0; } break;
		case KEYPAD_B: { keys[11] = 0; } break;
		case KEYPAD_C: { keys[12] = 0; } break;
		case KEYPAD_D: { keys[13] = 0; } break;
		case KEYPAD_E: { keys[14] = 0; } break;
		case KEYPAD_F: { keys[15] = 0; } break;
	}
}

void resetKeys() {
	char buff[32];
	sprintf(buff, "resetting keys\n");
	setDebug(buff);
	refreshDebug();
	keys[0] = 0;
	keys[1] = 0;
	keys[2] = 0;
	keys[3] = 0;
	keys[4] = 0;
	keys[5] = 0;
	keys[6] = 0;
	keys[7] = 0;
	keys[8] = 0;
	keys[9] = 0;
	keys[10] = 0;
	keys[11] = 0;
	keys[12] = 0;
	keys[13] = 0;
	keys[14] = 0;
	keys[15] = 0;
}
