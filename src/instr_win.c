#include "instr_win.h"

void setInstr(char *msg) {
	waddstr(instructions, msg);
}
