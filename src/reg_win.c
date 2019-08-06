#include "reg_win.h"

void initRegs() {
	wmove(regs, 1, 2);
	waddstr(regs, "Registers");
	wmove(regs, 1, 15);
	waddstr(regs, "Stack");

	wmove(regs, VF_Y, VF_X);
	waddstr(regs, "VF: 0x00");
	wmove(regs, VE_Y, VE_X);
	waddstr(regs, "VE: 0x00");
	wmove(regs, VD_Y, VD_X);
	waddstr(regs, "VD: 0x00");
	wmove(regs, VC_Y, VC_X);
	waddstr(regs, "VC: 0x00");
	wmove(regs, VB_Y, VB_X);
	waddstr(regs, "VB: 0x00");
	wmove(regs, VA_Y, VA_X);
	waddstr(regs, "VA: 0x00");
	wmove(regs, V9_Y, V9_X);
	waddstr(regs, "V9: 0x00");
	wmove(regs, V8_Y, V8_X);
	waddstr(regs, "V8: 0x00");
	wmove(regs, V7_Y, V7_X);
	waddstr(regs, "V7: 0x00");
	wmove(regs, V6_Y, V6_X);
	waddstr(regs, "V6: 0x00");
	wmove(regs, V5_Y, V5_X);
	waddstr(regs, "V5: 0x00");
	wmove(regs, V4_Y, V4_X);
	waddstr(regs, "V4: 0x00");
	wmove(regs, V3_Y, V3_X);
	waddstr(regs, "V3: 0x00");
	wmove(regs, V2_Y, V2_X);
	waddstr(regs, "V2: 0x00");
	wmove(regs, V1_Y, V1_X);
	waddstr(regs, "V1: 0x00");
	wmove(regs, V0_Y, V0_X);
	waddstr(regs, "V0: 0x00");

	wmove(regs, STACK_F_Y, STACK_F_X);
	waddstr(regs, "0xebc: 0x0000");
	wmove(regs, STACK_E_Y, STACK_E_X);
	waddstr(regs, "0xeba: 0x0000");
	wmove(regs, STACK_D_Y, STACK_D_X);
	waddstr(regs, "0xeb8: 0x0000");
	wmove(regs, STACK_C_Y, STACK_C_X);
	waddstr(regs, "0xeb6: 0x0000");
	wmove(regs, STACK_B_Y, STACK_B_X);
	waddstr(regs, "0xeb4: 0x0000");
	wmove(regs, STACK_A_Y, STACK_A_X);
	waddstr(regs, "0xeb2: 0x0000");
	wmove(regs, STACK_9_Y, STACK_9_X);
	waddstr(regs, "0xeb0: 0x0000");
	wmove(regs, STACK_8_Y, STACK_8_X);
	waddstr(regs, "0xeae: 0x0000");
	wmove(regs, STACK_7_Y, STACK_7_X);
	waddstr(regs, "0xeac: 0x0000");
	wmove(regs, STACK_6_Y, STACK_6_X);
	waddstr(regs, "0xeac: 0x0000");
	wmove(regs, STACK_5_Y, STACK_5_X);
	waddstr(regs, "0xeaa: 0x0000");
	wmove(regs, STACK_4_Y, STACK_4_X);
	waddstr(regs, "0xea8: 0x0000");
	wmove(regs, STACK_3_Y, STACK_3_X);
	waddstr(regs, "0xea6: 0x0000");
	wmove(regs, STACK_2_Y, STACK_2_X);
	waddstr(regs, "0xea4: 0x0000");
	wmove(regs, STACK_1_Y, STACK_1_X);
	waddstr(regs, "0xea2: 0x0000");
	wmove(regs, STACK_0_Y, STACK_0_X);
	waddstr(regs, "0xea0: 0x0000");

	wmove(regs, I_Y, I_X);
	waddstr(regs, "I:  0x0000");

	wmove(regs, DT_Y, DT_X);
	waddstr(regs, "DT: 0x00");
	wmove(regs, ST_Y, ST_X);
	waddstr(regs, "ST: 0x00");

	wmove(regs, SP_Y, SP_X);
	waddstr(regs, "SP: 0x00");
	wmove(regs, PC_Y, PC_X);
	waddstr(regs, "PC: 0x0000");

	//keys box
	mvwaddch(regs, 25, 2, ACS_ULCORNER);
	mvwaddch(regs, 25, 18, ACS_URCORNER);
	mvwaddch(regs, 30, 2, ACS_LLCORNER);
	mvwaddch(regs, 30, 18, ACS_LRCORNER);
	wmove(regs, 26, 2);
	wvline(regs, ACS_VLINE, 4);
	wmove(regs, 26, 6);
	wvline(regs, ACS_VLINE, 4);
	wmove(regs, 26, 10);
	wvline(regs, ACS_VLINE, 4);
	wmove(regs, 26, 14);
	wvline(regs, ACS_VLINE, 4);
	wmove(regs, 26, 18);
	wvline(regs, ACS_VLINE, 4);
	wmove(regs, 25, 3);
	whline(regs, ACS_HLINE, 3);
	mvwaddch(regs, 25, 6, ACS_TTEE);
	whline(regs, ACS_HLINE, 3);
	mvwaddch(regs, 25, 10, ACS_TTEE);
	whline(regs, ACS_HLINE, 3);
	mvwaddch(regs, 25, 14, ACS_TTEE);
	whline(regs, ACS_HLINE, 3);
	wmove(regs, 30, 3);
	whline(regs, ACS_HLINE, 3);
	mvwaddch(regs, 30, 6, ACS_BTEE);
	whline(regs, ACS_HLINE, 3);
	mvwaddch(regs, 30, 10, ACS_BTEE);
	whline(regs, ACS_HLINE, 3);
	mvwaddch(regs, 30, 14, ACS_BTEE);
	whline(regs, ACS_HLINE, 3);

	//keys
	mvwaddch(regs, KEY_1_Y, KEY_1_X, '1');
	mvwaddch(regs, KEY_2_Y, KEY_2_X, '2');
	mvwaddch(regs, KEY_3_Y, KEY_3_X, '3');
	mvwaddch(regs, KEY_C_Y, KEY_C_X, 'C');
	mvwaddch(regs, KEY_4_Y, KEY_4_X, '4');
	mvwaddch(regs, KEY_5_Y, KEY_5_X, '5');
	mvwaddch(regs, KEY_6_Y, KEY_6_X, '6');
	mvwaddch(regs, KEY_D_Y, KEY_D_X, 'D');
	mvwaddch(regs, KEY_7_Y, KEY_7_X, '7');
	mvwaddch(regs, KEY_8_Y, KEY_8_X, '8');
	mvwaddch(regs, KEY_9_Y, KEY_9_X, '9');
	mvwaddch(regs, KEY_E_Y, KEY_E_X, 'E');
	mvwaddch(regs, KEY_A_Y, KEY_A_X, 'A');
	mvwaddch(regs, KEY_0_Y, KEY_0_X, '0');
	mvwaddch(regs, KEY_B_Y, KEY_B_X, 'B');
	mvwaddch(regs, KEY_F_Y, KEY_F_X, 'F');
}

void printRegs() {
	wmove(regs, 3, 29);
	wvline(regs, ' ', 16);

	wmove(regs, VF_Y, VF_X + 6);
	wprintw(regs, "%02x", VF);
	wmove(regs, VE_Y, VE_X + 6);
	wprintw(regs, "%02x", VE);
	wmove(regs, VD_Y, VD_X + 6);
	wprintw(regs, "%02x", VD);
	wmove(regs, VC_Y, VC_X + 6);
	wprintw(regs, "%02x", VC);
	wmove(regs, VB_Y, VB_X + 6);
	wprintw(regs, "%02x", VB);
	wmove(regs, VA_Y, VA_X + 6);
	wprintw(regs, "%02x", VA);
	wmove(regs, V9_Y, V9_X + 6);
	wprintw(regs, "%02x", V9);
	wmove(regs, V8_Y, V8_X + 6);
	wprintw(regs, "%02x", V8);
	wmove(regs, V7_Y, V7_X + 6);
	wprintw(regs, "%02x", V7);
	wmove(regs, V6_Y, V6_X + 6);
	wprintw(regs, "%02x", V6);
	wmove(regs, V5_Y, V5_X + 6);
	wprintw(regs, "%02x", V5);
	wmove(regs, V4_Y, V4_X + 6);
	wprintw(regs, "%02x", V4);
	wmove(regs, V3_Y, V3_X + 6);
	wprintw(regs, "%02x", V3);
	wmove(regs, V2_Y, V2_X + 6);
	wprintw(regs, "%02x", V2);
	wmove(regs, V1_Y, V1_X + 6);
	wprintw(regs, "%02x", V1);
	wmove(regs, V0_Y, V0_X + 6);
	wprintw(regs, "%02x", V0);

	wmove(regs, STACK_F_Y, STACK_F_X + 9);
	wprintw(regs, "%02x", (STACK_READ(0x1e)));
	wmove(regs, STACK_E_Y, STACK_E_X + 9);
	wprintw(regs, "%02x", (STACK_READ(0x1c)));
	wmove(regs, STACK_D_Y, STACK_D_X + 9);
	wprintw(regs, "%02x", (STACK_READ(0x1a)));
	wmove(regs, STACK_C_Y, STACK_C_X + 9);
	wprintw(regs, "%02x", (STACK_READ(0x18)));
	wmove(regs, STACK_B_Y, STACK_B_X + 9);
	wprintw(regs, "%02x", (STACK_READ(0x16)));
	wmove(regs, STACK_A_Y, STACK_A_X + 9);
	wprintw(regs, "%02x", (STACK_READ(0x14)));
	wmove(regs, STACK_9_Y, STACK_9_X + 9);
	wprintw(regs, "%02x", (STACK_READ(0x12)));
	wmove(regs, STACK_8_Y, STACK_8_X + 9);
	wprintw(regs, "%02x", (STACK_READ(0x10)));
	wmove(regs, STACK_7_Y, STACK_7_X + 9);
	wprintw(regs, "%02x", (STACK_READ(0x0e)));
	wmove(regs, STACK_6_Y, STACK_6_X + 9);
	wprintw(regs, "%02x", (STACK_READ(0x0c)));
	wmove(regs, STACK_5_Y, STACK_5_X + 9);
	wprintw(regs, "%02x", (STACK_READ(0x0a)));
	wmove(regs, STACK_4_Y, STACK_4_X + 9);
	wprintw(regs, "%02x", (STACK_READ(0x08)));
	wmove(regs, STACK_3_Y, STACK_3_X + 9);
	wprintw(regs, "%02x", (STACK_READ(0x06)));
	wmove(regs, STACK_2_Y, STACK_2_X + 9);
	wprintw(regs, "%02x", (STACK_READ(0x04)));
	wmove(regs, STACK_1_Y, STACK_1_X + 9);
	wprintw(regs, "%02x", (STACK_READ(0x02)));
	wmove(regs, STACK_0_Y, STACK_0_X + 9);
	wprintw(regs, "%02x", (STACK_READ(0x00)));

	wmove(regs, I_Y, I_X + 6);
	wprintw(regs, "%04x", I);

	wmove(regs, DT_Y, DT_X + 6);
	wprintw(regs, "%02x", DT);
	wmove(regs, ST_Y, ST_X + 6);
	wprintw(regs, "%02x", ST);

	wmove(regs, SP_Y, SP_X + 6);
	wprintw(regs, "%02x", SP);
	wmove(regs, PC_Y, PC_X + 6);
	wprintw(regs, "%04x", PC);

	if(SP != STACK_START) {
		wmove(regs, 18 - SP, 29);
		waddch(regs, '<');
	}

	//keys
	if(keys[KEYPAD_0]) {
		mvwaddch(regs, KEY_0_Y, KEY_0_X - 1, ACS_CKBOARD);
		mvwaddch(regs, KEY_0_Y, KEY_0_X + 1, ACS_CKBOARD);
	} else {
		mvwaddch(regs, KEY_0_Y, KEY_0_X - 1, ' ');
		mvwaddch(regs, KEY_0_Y, KEY_0_X + 1, ' ');
	}
	if(keys[KEYPAD_1]) {
		mvwaddch(regs, KEY_1_Y, KEY_1_X - 1, ACS_CKBOARD);
		mvwaddch(regs, KEY_1_Y, KEY_1_X + 1, ACS_CKBOARD);
	} else {
		mvwaddch(regs, KEY_1_Y, KEY_1_X - 1, ' ');
		mvwaddch(regs, KEY_1_Y, KEY_1_X + 1, ' ');
	}
	if(keys[KEYPAD_2]) {
		mvwaddch(regs, KEY_2_Y, KEY_2_X - 1, ACS_CKBOARD);
		mvwaddch(regs, KEY_2_Y, KEY_2_X + 1, ACS_CKBOARD);
	} else {
		mvwaddch(regs, KEY_2_Y, KEY_2_X - 1, ' ');
		mvwaddch(regs, KEY_2_Y, KEY_2_X + 1, ' ');
	}
	if(keys[KEYPAD_3]) {
		mvwaddch(regs, KEY_3_Y, KEY_3_X - 1, ACS_CKBOARD);
		mvwaddch(regs, KEY_3_Y, KEY_3_X + 1, ACS_CKBOARD);
	} else {
		mvwaddch(regs, KEY_3_Y, KEY_3_X - 1, ' ');
		mvwaddch(regs, KEY_3_Y, KEY_3_X + 1, ' ');
	}
	if(keys[KEYPAD_4]) {
		mvwaddch(regs, KEY_4_Y, KEY_4_X - 1, ACS_CKBOARD);
		mvwaddch(regs, KEY_4_Y, KEY_4_X + 1, ACS_CKBOARD);
	} else {
		mvwaddch(regs, KEY_4_Y, KEY_4_X - 1, ' ');
		mvwaddch(regs, KEY_4_Y, KEY_4_X + 1, ' ');
	}
	if(keys[KEYPAD_5]) {
		mvwaddch(regs, KEY_5_Y, KEY_5_X - 1, ACS_CKBOARD);
		mvwaddch(regs, KEY_5_Y, KEY_5_X + 1, ACS_CKBOARD);
	} else {
		mvwaddch(regs, KEY_5_Y, KEY_5_X - 1, ' ');
		mvwaddch(regs, KEY_5_Y, KEY_5_X + 1, ' ');
	}
	if(keys[KEYPAD_6]) {
		mvwaddch(regs, KEY_6_Y, KEY_6_X - 1, ACS_CKBOARD);
		mvwaddch(regs, KEY_6_Y, KEY_6_X + 1, ACS_CKBOARD);
	} else {
		mvwaddch(regs, KEY_6_Y, KEY_6_X - 1, ' ');
		mvwaddch(regs, KEY_6_Y, KEY_6_X + 1, ' ');
	}
	if(keys[KEYPAD_7]) {
		mvwaddch(regs, KEY_7_Y, KEY_7_X - 1, ACS_CKBOARD);
		mvwaddch(regs, KEY_7_Y, KEY_7_X + 1, ACS_CKBOARD);
	} else {
		mvwaddch(regs, KEY_7_Y, KEY_7_X - 1, ' ');
		mvwaddch(regs, KEY_7_Y, KEY_7_X + 1, ' ');
	}
	if(keys[KEYPAD_8]) {
		mvwaddch(regs, KEY_8_Y, KEY_8_X - 1, ACS_CKBOARD);
		mvwaddch(regs, KEY_8_Y, KEY_8_X + 1, ACS_CKBOARD);
	} else {
		mvwaddch(regs, KEY_8_Y, KEY_8_X - 1, ' ');
		mvwaddch(regs, KEY_8_Y, KEY_8_X + 1, ' ');
	}
	if(keys[KEYPAD_9]) {
		mvwaddch(regs, KEY_9_Y, KEY_9_X - 1, ACS_CKBOARD);
		mvwaddch(regs, KEY_9_Y, KEY_9_X + 1, ACS_CKBOARD);
	} else {
		mvwaddch(regs, KEY_9_Y, KEY_9_X - 1, ' ');
		mvwaddch(regs, KEY_9_Y, KEY_9_X + 1, ' ');
	}
	if(keys[KEYPAD_A]) {
		mvwaddch(regs, KEY_A_Y, KEY_A_X - 1, ACS_CKBOARD);
		mvwaddch(regs, KEY_A_Y, KEY_A_X + 1, ACS_CKBOARD);
	} else {
		mvwaddch(regs, KEY_A_Y, KEY_A_X - 1, ' ');
		mvwaddch(regs, KEY_A_Y, KEY_A_X + 1, ' ');
	}
	if(keys[KEYPAD_B]) {
		mvwaddch(regs, KEY_B_Y, KEY_B_X - 1, ACS_CKBOARD);
		mvwaddch(regs, KEY_B_Y, KEY_B_X + 1, ACS_CKBOARD);
	} else {
		mvwaddch(regs, KEY_B_Y, KEY_B_X - 1, ' ');
		mvwaddch(regs, KEY_B_Y, KEY_B_X + 1, ' ');
	}
	if(keys[KEYPAD_C]) {
		mvwaddch(regs, KEY_C_Y, KEY_C_X - 1, ACS_CKBOARD);
		mvwaddch(regs, KEY_C_Y, KEY_C_X + 1, ACS_CKBOARD);
	} else {
		mvwaddch(regs, KEY_C_Y, KEY_C_X - 1, ' ');
		mvwaddch(regs, KEY_C_Y, KEY_C_X + 1, ' ');
	}
	if(keys[KEYPAD_D]) {
		mvwaddch(regs, KEY_D_Y, KEY_D_X - 1, ACS_CKBOARD);
		mvwaddch(regs, KEY_D_Y, KEY_D_X + 1, ACS_CKBOARD);
	} else {
		mvwaddch(regs, KEY_D_Y, KEY_D_X - 1, ' ');
		mvwaddch(regs, KEY_D_Y, KEY_D_X + 1, ' ');
	}
	if(keys[KEYPAD_E]) {
		mvwaddch(regs, KEY_E_Y, KEY_E_X - 1, ACS_CKBOARD);
		mvwaddch(regs, KEY_E_Y, KEY_E_X + 1, ACS_CKBOARD);
	} else {
		mvwaddch(regs, KEY_E_Y, KEY_E_X - 1, ' ');
		mvwaddch(regs, KEY_E_Y, KEY_E_X + 1, ' ');
	}
	if(keys[KEYPAD_F]) {
		mvwaddch(regs, KEY_F_Y, KEY_F_X - 1, ACS_CKBOARD);
		mvwaddch(regs, KEY_F_Y, KEY_F_X + 1, ACS_CKBOARD);
	} else {
		mvwaddch(regs, KEY_F_Y, KEY_F_X - 1, ' ');
		mvwaddch(regs, KEY_F_Y, KEY_F_X + 1, ' ');
	}
}
