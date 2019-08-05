#include "instructions.h"

int printSYS(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: SYS 0x%04x\n", PC + 0x200, instr, instr & 0x0fff);
	return SYS;
}

int printCLS(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: CLS\n", PC + 200, instr);
	return CLS;
}

int printRET(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: RET\n", PC + 200, instr);
	return RET;
}

int printJP(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: JP 0x%04x\n", PC + 200, instr, instr & 0x0fff);
	return JP;
}

int printCALL(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: CALL 0x%04x\n", PC + 200, instr, instr & 0x0fff);
	return CALL;
}

int printSE(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: SE V%d, 0x%02x\n", PC + 200, instr, (instr & 0x0f00) >> 8, instr & 0x00ff);
	return SE;
}

int printSNE(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: SNE V%d, 0x%02x\n", PC + 200, instr, (instr & 0x0f00) >> 8, instr & 0x00ff);
	return SNE;
}

int printSE_R(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: SE V%d, V%d\n", PC + 200, instr, (instr & 0x0f00) >> 8, (instr & 0x00f0) >> 4);
	return SE_R;
}

int printLD_B(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: LD V%d, 0x%02x\n", PC + 200, instr, (instr & 0x0f00) >> 8, instr & 0x00ff);
	return LD_B;
}

int printADD_I(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: ADD V%d, 0x%02x\n", PC + 200, instr, (instr & 0x0f00) >> 8, instr & 0x00ff);
	return ADD_I;
}

int printLD_R(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: LD V%d, V%d\n", PC + 200, instr, (instr & 0x0f00) >> 8, (instr & 0x00f0) >> 4);
	return LD_R;
}

int printOR(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: OR V%d, V%d\n", PC + 200, instr, (instr & 0x0f00) >> 8, (instr & 0x00f0) >> 4);
	return OR;
}

int printAND(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: AND V%d, V%d\n", PC + 200, instr, (instr & 0x0f00) >> 8, (instr & 0x00f0) >> 4);
	return AND;
}

int printXOR(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: XOR V%d, V%d\n", PC + 200, instr, (instr & 0x0f00) >> 8, (instr & 0x00f0) >> 4);
	return XOR;
}

int printADD(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: ADD V%d, V%d\n", PC + 200, instr, (instr & 0x0f00) >> 8, (instr & 0x00f0) >> 4);
	return ADD;
}

int printSUB(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: SUB V%d, V%d\n", PC + 200, instr, (instr & 0x0f00) >> 8, (instr & 0x00f0) >> 4);
	return SUB;
}

int printSHR(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: SHR V%d\n", PC + 200, instr, (instr & 0x0f00) >> 8);
	return SHR;
}

int printSUBN(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: SUBN V%d, V%d\n", PC + 200, instr, (instr & 0x0f00) >> 8, (instr & 0x00f0) >> 4);
	return SUBN;
}

int printSHL(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: SHL V%d\n", PC + 200, instr, (instr & 0x0f00) >> 8);
	return SHL;
}

int printSNE_R(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: SNE V%d, V%d\n", PC + 200, instr, (instr & 0x0f00) >> 8, (instr & 0x00f0) >> 4);
	return SNE_R;
}

int printLD_I(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: LD I, 0x%04x\n", PC + 200, instr, instr & 0x0fff);
	return LD_I;
}

int printJP_R(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: KP V0, 0x%04x\n", PC + 200, instr, instr & 0x0fff);
	return JP_R;
}

int printRND(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: RND V%d, 0x%02x\n", PC + 200, instr, (instr & 0x0f00) >> 8, instr & 0x00ff);
	return RND;
}

int printDRW(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: DRW V%d, V%d, 0x%02x\n", PC + 200, instr, (instr & 0x0f00) >> 8, (instr & 0x00f0) >> 4, instr & 0x000f);
	return DRW;
}

int printSKP(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: SKP V%d\n", PC + 200, instr, (instr & 0x0f00) >> 8);
	return SKP;
}

int printSKNP(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: SKNP V%d\n", PC + 200, instr, (instr & 0x0f00) >> 8);
	return SKNP;
}

int printLD_DT_I(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: LD V%d, DT\n", PC + 200, instr, (instr & 0x0f00) >> 8);
	return LD_DT_I;
}

int printLD_K(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: LD V%d, K\n", PC + 200, instr, (instr & 0x0f00) >> 8);
	return LD_K;
}

int printLD_DT_O(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: LD DT, V%d\n", PC + 200, instr, (instr & 0x0f00) >> 8);
	return LD_DT_O;
}

int printLD_ST(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: LD ST, V%d\n", PC + 200, instr, (instr & 0x0f00) >> 8);
	return LD_ST;
}

int printADD_I_R(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: ADD I, V%d\n", PC + 200, instr, (instr & 0x0f00) >> 8);
	return ADD_I_R;
}

int printLD_S(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: LD F, V%d\n", PC + 200, instr, (instr & 0x0f00) >> 8);
	return LD_S;
}

int printLD_BCD(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: LD B, V%d\n", PC + 200, instr, (instr & 0x0f00) >> 8);
	return LD_BCD;
}

int printLD_A_O(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: LD [I], V%d\n", PC + 200, instr, (instr & 0x0f00) >> 8);
	return LD_A_O;
}

int printLD_A_I(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: LD V%d, [I]\n", PC + 200, instr, (instr & 0x0f00) >> 8);
	return LD_A_I;
}

int badInstr(word instr) {
	sprintf(prog[PC], "[0x%04x] 0x%04x: bad instr\n", PC + 200, instr);
	return -1;
}
