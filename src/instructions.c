#include "instructions.h"

int zeroes(word instr) {
	switch(instr) {
		case 0x0e0: { return doCLS(instr); }
		case 0x0ee: { return doRET(instr); }
		default: { return doSYS(instr); }
	}
}

int eights(word instr) {
	switch(instr & 0x000f) {
		case 0x0: { return doLD_R(instr); }
		case 0x1: { return doOR(instr); }
		case 0x2: { return doAND(instr); }
		case 0x3: { return doXOR(instr); }
		case 0x4: { return doADD(instr); }
		case 0x5: { return doSUB(instr); }
		case 0x6: { return doSHR(instr); }
		case 0x7: { return doSUBN(instr); }
		case 0xe: { return doSHL(instr); }
		default: return -1;
	}
}

int ees(word instr) {
	switch(instr & 0x00ff) {
		case 0x9e: { return doSKP(instr); }
		case 0xa1: { return doSKNP(instr); }
		default: return -1;
	}
}

int effs(word instr) {
	switch(instr & 0x00ff) {
		case 0x07: { return doLD_DT_I(instr); }
		case 0x0a: { return doLD_K(instr); }
		case 0x15: { return doLD_DT_O(instr); }
		case 0x18: { return doLD_ST(instr); }
		case 0x1e: { return doADD_I_R(instr); }
		case 0x29: { return doLD_S(instr); }
		case 0x33: { return doLD_BCD(instr); }
		case 0x55: { return doLD_A_O(instr); }
		case 0x65: { return doLD_A_I(instr); }
		default: return -1;
	}
}

int doSYS(word instr) {
	//nothing to do
	char buff[32];
	sprintf(buff, "SYS\n");
	setInstr(buff);
	refreshInstr();

	return SYS;
}

int doCLS(word instr) {
	char buff[32];
	sprintf(buff, "CLS\n");
	setInstr(buff);
	refreshInstr();

	clearDisplay();

	return CLS;
}

int doRET(word instr) {
	char buff[32];
	sprintf(buff, "RET\n");
	setInstr(buff);
	refreshInstr();

	if(SP == STACK_START) {
		return -2;
	}

	SET_PC(PC, STACK_READ(SP));
	DEC_SP(SP);

	return RET;
}

int doJP(word instr) {
	char buff[32];
	sprintf(buff, "JP 0x%04x\n", instr);
	setInstr(buff);
	refreshInstr();

	SET_PC(PC, instr);

	return JP;
}

int doCALL(word instr) {
	char buff[32];
	sprintf(buff, "CALL 0x%04x\n", instr);
	setInstr(buff);
	refreshInstr();

	if(SP == 0xff) {
		SP = 0x00;
	} else {
		INC_SP(SP);
	}

	STACK_WRITE(SP, PC);
	SET_PC(PC, instr);
	DEC_PC(PC);

	return CALL;
}

int doSE(word instr) {
	char buff[32];
	sprintf(buff, "SE V%d, 0x%02x\n", (instr & 0x0f00) >> 8, (instr & 0x00ff));
	setInstr(buff);
	refreshInstr();

	if(registers[(instr & 0x0f00) >> 8] == (instr & 0x00ff)) {
		INC_PC(PC);
	}

	return SE;
}

int doSNE(word instr) {
	char buff[32];
	sprintf(buff, "SNE V%d, 0x%02x\n", (instr & 0x0f00) >> 8, (instr & 0x00ff));
	setInstr(buff);
	refreshInstr();

	if(registers[(instr & 0x0f00) >> 8] != (instr & 0x00ff)) {
		INC_PC(PC);
	}

	return SNE;
}

int doSE_R(word instr) {
	char buff[32];
	sprintf(buff, "SE V%d, V%d\n", (instr & 0x0f00) >> 8, (instr & 0x00f0) >> 4);
	setInstr(buff);
	refreshInstr();

	if(registers[(instr & 0x0f00) >> 8] == registers[(instr & 0x00f0) >> 4]) {
		INC_PC(PC);
	}

	return SE_R;
}

int doLD_B(word instr) {
	char buff[32];
	sprintf(buff, "LD V%d, 0x%02x\n", (instr & 0x0f00) >> 8, (instr & 0x00ff));
	setInstr(buff);
	refreshInstr();

	registers[((instr & 0x0f00) >> 8)] = (instr & 0x00ff);

	return LD_B;
}

int doADD_I(word instr) {
	char buff[32];
	sprintf(buff, "ADD V%d, 0x%02x\n", (instr & 0x0f00) >> 8, (instr & 0x00ff));
	setInstr(buff);
	refreshInstr();

	registers[((instr & 0x0f00) >> 8)] = registers[((instr & 0x0f00) >> 8)] + (instr & 0x00ff);

	return ADD_I;
}

int doLD_R(word instr) {
	char buff[32];
	sprintf(buff, "LD V%d, V%d\n", (instr & 0x0f00) >> 8, (instr & 0x00f0) >> 4);
	setInstr(buff);
	refreshInstr();

	return LD_R;
}

int doOR(word instr) {
	char buff[32];
	sprintf(buff, "OR V%d, V%d\n", (instr & 0x0f00) >> 8, (instr & 0x00f0) >> 4);
	setInstr(buff);
	refreshInstr();

	return OR;
}

int doAND(word instr) {
	char buff[32];
	sprintf(buff, "AND V%d, V%d\n", (instr & 0x0f00) >> 8, (instr & 0x00f0) >> 4);
	setInstr(buff);
	refreshInstr();

	return AND;
}

int doXOR(word instr) {
	char buff[32];
	sprintf(buff, "XOR V%d, V%d\n", (instr & 0x0f00) >> 8, (instr & 0x00f0) >> 4);
	setInstr(buff);
	refreshInstr();

	return XOR;
}

int doADD(word instr) {
	char buff[32];
	sprintf(buff, "ADD V%d, V%d\n", (instr & 0x0f00) >> 8, (instr & 0x00f0) >> 4);
	setInstr(buff);
	refreshInstr();

	word temp = registers[((instr & 0x0f00) >> 8)] + registers[((instr & 0x00f0) >> 4)];
	if(temp > 255) {
		VF = 0x1;
	} else {
		VF = 0x0;
	}
	registers[((instr & 0x0f00) >> 8)] = (temp & 0xff);

	return ADD;
}

int doSUB(word instr) {
	char buff[32];
	sprintf(buff, "SUB V%d, V%d\n", (instr & 0x0f00) >> 8, (instr & 0x00f0) >> 4);
	setInstr(buff);
	refreshInstr();

	if(registers[((instr & 0x0f00) >> 8)] > registers[((instr & 0x00f0) >> 4)]) {
		VF = 0x1;
	} else {
		VF = 0x0;
	}
	registers[((instr & 0x0f00) >> 8)] = registers[((instr & 0x0f00) >> 8)] - registers[((instr & 0x00f0) >> 4)];

	return SUB;
}

int doSHR(word instr) {
	char buff[32];
	sprintf(buff, "SHR V%d\n", (instr & 0x0f00) >> 8);
	setInstr(buff);
	refreshInstr();

	return SHR;
}

int doSUBN(word instr) {
	char buff[32];
	sprintf(buff, "SUBN V%d, V%d\n", (instr & 0x0f00) >> 8, (instr & 0x00f0) >> 4);
	setInstr(buff);
	refreshInstr();

	return SUBN;
}

int doSHL(word instr) {
	char buff[32];
	sprintf(buff, "SHL V%d\n", (instr & 0x0f00) >> 8);
	setInstr(buff);
	refreshInstr();

	return SHL;
}

int doSNE_R(word instr) {
	char buff[32];
	sprintf(buff, "SNE V%d, V%d\n", (instr & 0x0f00) >> 8, (instr & 0x00f0) >> 4);
	setInstr(buff);
	refreshInstr();

	return SNE_R;
}

int doLD_I(word instr) {
	char buff[32];
	sprintf(buff, "LD I, 0x%04x\n", (instr & 0x0fff));
	setInstr(buff);
	refreshInstr();

	I = (instr & 0x0fff);

	return LD_I;
}

int doJP_R(word instr) {
	char buff[32];
	sprintf(buff, "JP V0, 0x%04x\n", (instr & 0x0fff));
	setInstr(buff);
	refreshInstr();

	return JP_R;
}

int doRND(word instr) {
	char buff[32];
	sprintf(buff, "RND V%d, 0x%02x\n", (instr & 0x0f00) >> 8, (instr & 0x00ff));
	setInstr(buff);
	refreshInstr();

	return RND;
}

int doDRW(word instr) {
	char buff[32];
	sprintf(buff, "DRW V%d, V%d, 0x%01x\n", (instr & 0x0f00) >> 8, (instr & 0x00f0) >> 4, (instr & 0x000f));
	setInstr(buff);
	refreshInstr();

	setPixels(registers[((instr & 0x0f00) >> 8)], registers[((instr & 0x00f0) >> 4)], (instr & 0x000f), I);
	setDisplay();

	return DRW;
}

int doSKP(word instr) {
	char buff[32];
	sprintf(buff, "SKP V%d\n", (instr & 0x0f00) >> 8);
	setInstr(buff);
	refreshInstr();

	return SKP;
}

int doSKNP(word instr) {
	char buff[32];
	sprintf(buff, "SKNP V%d\n", (instr & 0x0f00) >> 8);
	setInstr(buff);
	refreshInstr();

	return SKNP;
}

int doLD_DT_I(word instr) {
	char buff[32];
	sprintf(buff, "LD V%d, DT\n", (instr & 0x0f00) >> 8);
	setInstr(buff);
	refreshInstr();

	return LD_DT_I;
}

int doLD_K(word instr) {
	char buff[32];
	sprintf(buff, "LD V%d, K\n", (instr & 0x0f00) >> 8);
	setInstr(buff);
	refreshInstr();

	return LD_K;
}

int doLD_DT_O(word instr) {
	char buff[32];
	sprintf(buff, "LD DT, V%d\n", (instr & 0x0f00) >> 8);
	setInstr(buff);
	refreshInstr();

	return LD_DT_O;
}

int doLD_ST(word instr) {
	char buff[32];
	sprintf(buff, "LD ST, V%d\n", (instr & 0x0f00) >> 8);
	setInstr(buff);
	refreshInstr();

	return LD_ST;
}

int doADD_I_R(word instr) {
	char buff[32];
	sprintf(buff, "ADD I, V%d\n", (instr & 0x0f00) >> 8);
	setInstr(buff);
	refreshInstr();

	I = I + registers[((instr & 0x0f00) >> 8)];

	return ADD_I_R;
}

int doLD_S(word instr) {
	char buff[32];
	sprintf(buff, "LD F, V%d\n", (instr & 0x0f00) >> 8);
	setInstr(buff);
	refreshInstr();

	return LD_S;
}

int doLD_BCD(word instr) {
	char buff[32];
	sprintf(buff, "LD B, V%d\n", (instr & 0x0f00) >> 8);
	setInstr(buff);
	refreshInstr();

	return LD_BCD;
}

int doLD_A_O(word instr) {
	char buff[32];
	sprintf(buff, "LD [I], V%d\n", (instr & 0x0f00) >> 8);
	setInstr(buff);
	refreshInstr();

	return LD_A_O;
}

int doLD_A_I(word instr) {
	char buff[32];
	sprintf(buff, "LD V%d, [I]\n", (instr & 0x0f00) >> 8);
	setInstr(buff);
	refreshInstr();

	return LD_A_I;
}

int interpret(byte upper, byte lower) {
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
		word instr = lower;
		instr = instr ^ ((upper << 8) & 0xff00);
	#else
		word instr = lower << 8;
		instr = instr ^ (upper & 0x00ff);
	#endif
	char buff[24];
	sprintf(buff, "0x%02x 0x%02x\n", lower, upper);
	setDebug(buff);
	sprintf(buff, "0x%04x\n", instr);
	setDebug(buff);
	refreshDebug();
	switch(instr & 0xf000) {
		case 0x0000: {
			return zeroes(instr & 0x0fff);
		}
		break;
		case 0x1000: {
			return doJP(instr & 0x0fff);
		}
		break;
		case 0x2000: {
			return doCALL(instr & 0x0fff);
		}
		break;
		case 0x3000: {
			return doSE(instr & 0x0fff);
		}
		break;
		case 0x4000: {
			return doSNE(instr & 0x0fff);
		}
		break;
		case 0x5000: {
			return doSE_R(instr & 0x0fff);
		}
		break;
		case 0x6000: {
			return doLD_B(instr & 0x0fff);
		}
		break;
		case 0x7000: {
			return doADD_I(instr & 0x0fff);
		}
		break;
		case 0x8000: {
			return eights(instr & 0x0fff);
		}
		break;
		case 0x9000: {
			return doSNE_R(instr & 0x0fff);
		}
		break;
		case 0xa000: {
			return doLD_I(instr & 0x0fff);
		}
		break;
		case 0xb000: {
			return doJP_R(instr & 0x0fff);
		}
		break;
		case 0xc000: {
			return doRND(instr & 0x0fff);
		}
		break;
		case 0xd000: {
			return doDRW(instr & 0x0fff);
		}
		break;
		case 0xe000: {
			return ees(instr & 0x0fff);
		}
		break;
		case 0xf000: {
			return effs(instr & 0x0fff);
		}
		break;
		default: {
			sprintf(buff, "Unkown command: 0x%04x\n", instr);
			setDebug(buff);
			refreshDebug();
			return -1;
		}
	}
}