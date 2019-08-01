#include "registers.h"

void initRegisters() {
	PC = (word)DATA_OFFSET;
	SP = (byte)STACK_START;
	DT = 0;
	ST = 0;
	V0 = 0;
	V1 = 0;
	V2 = 0;
	V3 = 0;
	V4 = 0;
	V5 = 0;
	V6 = 0;
	V7 = 0;
	V8 = 0;
	V9 = 0;
	VA = 0;
	VB = 0;
	VC = 0;
	VD = 0;
	VE = 0;
	VF = 0;
}
