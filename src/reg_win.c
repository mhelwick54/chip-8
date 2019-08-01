#include "reg_win.h"

void initRegs() {
	wmove(regs, 1, 2);
	waddstr(regs, "Registers");
	wmove(regs, 1, 15);
	waddstr(regs, "Stack");

	wmove(regs, 3, 2);
	waddstr(regs, "VF: 0x00");
	wmove(regs, 4, 2);
	waddstr(regs, "VE: 0x00");
	wmove(regs, 5, 2);
	waddstr(regs, "VD: 0x00");
	wmove(regs, 6, 2);
	waddstr(regs, "VC: 0x00");
	wmove(regs, 7, 2);
	waddstr(regs, "VB: 0x00");
	wmove(regs, 8, 2);
	waddstr(regs, "VA: 0x00");
	wmove(regs, 9, 2);
	waddstr(regs, "V9: 0x00");
	wmove(regs, 10, 2);
	waddstr(regs, "V8: 0x00");
	wmove(regs, 11, 2);
	waddstr(regs, "V7: 0x00");
	wmove(regs, 12, 2);
	waddstr(regs, "V6: 0x00");
	wmove(regs, 13, 2);
	waddstr(regs, "V5: 0x00");
	wmove(regs, 14, 2);
	waddstr(regs, "V4: 0x00");
	wmove(regs, 15, 2);
	waddstr(regs, "V3: 0x00");
	wmove(regs, 16, 2);
	waddstr(regs, "V2: 0x00");
	wmove(regs, 17, 2);
	waddstr(regs, "V1: 0x00");
	wmove(regs, 18, 2);
	waddstr(regs, "V0: 0x00");

	wmove(regs, 3, 15);
	waddstr(regs, "0xebc: 0x0000");
	wmove(regs, 4, 15);
	waddstr(regs, "0xeba: 0x0000");
	wmove(regs, 5, 15);
	waddstr(regs, "0xeb8: 0x0000");
	wmove(regs, 6, 15);
	waddstr(regs, "0xeb6: 0x0000");
	wmove(regs, 7, 15);
	waddstr(regs, "0xeb4: 0x0000");
	wmove(regs, 8, 15);
	waddstr(regs, "0xeb2: 0x0000");
	wmove(regs, 9, 15);
	waddstr(regs, "0xeb0: 0x0000");
	wmove(regs, 10, 15);
	waddstr(regs, "0xeae: 0x0000");
	wmove(regs, 11, 15);
	waddstr(regs, "0xeac: 0x0000");
	wmove(regs, 12, 15);
	waddstr(regs, "0xeac: 0x0000");
	wmove(regs, 13, 15);
	waddstr(regs, "0xeaa: 0x0000");
	wmove(regs, 14, 15);
	waddstr(regs, "0xea8: 0x0000");
	wmove(regs, 15, 15);
	waddstr(regs, "0xea6: 0x0000");
	wmove(regs, 16, 15);
	waddstr(regs, "0xea4: 0x0000");
	wmove(regs, 17, 15);
	waddstr(regs, "0xea2: 0x0000");
	wmove(regs, 18, 15);
	waddstr(regs, "0xea0: 0x0000");

	wmove(regs, 20, 2);
	waddstr(regs, "I:  0x0000");

	wmove(regs, 22, 2);
	waddstr(regs, "DT: 0x00");
	wmove(regs, 23, 2);
	waddstr(regs, "ST: 0x00");

	wmove(regs, 25, 2);
	waddstr(regs, "SP: 0x00");
	wmove(regs, 26, 2);
	waddstr(regs, "PC: 0x0000");
}

void printRegs() {
	wmove(regs, 3, 29);
	wvline(regs, ' ', 16);

	wmove(regs, 3, 8);
	wprintw(regs, "%02x", VF);
	wmove(regs, 4, 8);
	wprintw(regs, "%02x", VE);
	wmove(regs, 5, 8);
	wprintw(regs, "%02x", VD);
	wmove(regs, 6, 8);
	wprintw(regs, "%02x", VC);
	wmove(regs, 7, 8);
	wprintw(regs, "%02x", VB);
	wmove(regs, 8, 8);
	wprintw(regs, "%02x", VA);
	wmove(regs, 9, 8);
	wprintw(regs, "%02x", V9);
	wmove(regs, 10, 8);
	wprintw(regs, "%02x", V8);
	wmove(regs, 11, 8);
	wprintw(regs, "%02x", V7);
	wmove(regs, 12, 8);
	wprintw(regs, "%02x", V6);
	wmove(regs, 13, 8);
	wprintw(regs, "%02x", V5);
	wmove(regs, 14, 8);
	wprintw(regs, "%02x", V4);
	wmove(regs, 15, 8);
	wprintw(regs, "%02x", V3);
	wmove(regs, 16, 8);
	wprintw(regs, "%02x", V2);
	wmove(regs, 17, 8);
	wprintw(regs, "%02x", V1);
	wmove(regs, 18, 8);
	wprintw(regs, "%02x", V0);

	wmove(regs, 3, 24);
	wprintw(regs, "%02x", (STACK_READ(0x1e)));
	wmove(regs, 4, 24);
	wprintw(regs, "%02x", (STACK_READ(0x1c)));
	wmove(regs, 5, 24);
	wprintw(regs, "%02x", (STACK_READ(0x1a)));
	wmove(regs, 6, 24);
	wprintw(regs, "%02x", (STACK_READ(0x18)));
	wmove(regs, 7, 24);
	wprintw(regs, "%02x", (STACK_READ(0x16)));
	wmove(regs, 8, 24);
	wprintw(regs, "%02x", (STACK_READ(0x14)));
	wmove(regs, 9, 24);
	wprintw(regs, "%02x", (STACK_READ(0x12)));
	wmove(regs, 10, 24);
	wprintw(regs, "%02x", (STACK_READ(0x10)));
	wmove(regs, 11, 24);
	wprintw(regs, "%02x", (STACK_READ(0x0e)));
	wmove(regs, 12, 24);
	wprintw(regs, "%02x", (STACK_READ(0x0c)));
	wmove(regs, 13, 24);
	wprintw(regs, "%02x", (STACK_READ(0x0a)));
	wmove(regs, 14, 24);
	wprintw(regs, "%02x", (STACK_READ(0x08)));
	wmove(regs, 15, 24);
	wprintw(regs, "%02x", (STACK_READ(0x06)));
	wmove(regs, 16, 24);
	wprintw(regs, "%02x", (STACK_READ(0x04)));
	wmove(regs, 17, 24);
	wprintw(regs, "%02x", (STACK_READ(0x02)));
	wmove(regs, 18, 24);
	wprintw(regs, "%02x", (STACK_READ(0x00)));

	wmove(regs, 20, 8);
	wprintw(regs, "%04x", I);

	wmove(regs, 22, 8);
	wprintw(regs, "%02x", DT);
	wmove(regs, 23, 8);
	wprintw(regs, "%02x", ST);

	wmove(regs, 25, 8);
	wprintw(regs, "%02x", SP);
	wmove(regs, 26, 8);
	wprintw(regs, "%04x", PC);

	if(SP != STACK_START) {
		wmove(regs, 18 - SP, 29);
		waddch(regs, '<');
	}
}
