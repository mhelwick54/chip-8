#include "keys.h"

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
	releaseKey(KEYPAD_0);
	releaseKey(KEYPAD_1);
	releaseKey(KEYPAD_2);
	releaseKey(KEYPAD_3);
	releaseKey(KEYPAD_4);
	releaseKey(KEYPAD_5);
	releaseKey(KEYPAD_6);
	releaseKey(KEYPAD_7);
	releaseKey(KEYPAD_8);
	releaseKey(KEYPAD_9);
	releaseKey(KEYPAD_A);
	releaseKey(KEYPAD_B);
	releaseKey(KEYPAD_C);
	releaseKey(KEYPAD_D);
	releaseKey(KEYPAD_E);
	releaseKey(KEYPAD_F);
}
