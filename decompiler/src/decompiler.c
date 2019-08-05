#include "decompiler.h"

int zeroes(word instr) {
	switch(instr & 0x00ff) {
		case 0x0e0: { return printCLS(instr); }
		case 0x0ee: { return printRET(instr); }
		default: { return printSYS(instr); }
	}
}

int eights(word instr) {
	switch(instr & 0x000f) {
		case 0x0: { return printLD_R(instr); }
		case 0x1: { return printOR(instr); }
		case 0x2: { return printAND(instr); }
		case 0x3: { return printXOR(instr); }
		case 0x4: { return printADD(instr); }
		case 0x5: { return printSUB(instr); }
		case 0x6: { return printSHR(instr); }
		case 0x7: { return printSUBN(instr); }
		case 0xe: { return printSHL(instr); }
		default: { return badInstr(instr); }
	}
}

int ees(word instr) {
	switch(instr & 0x00ff) {
		case 0x9e: { return printSKP(instr); }
		case 0xa1: { return printSKNP(instr); }
		default: { return badInstr(instr); }
	}
}

int effs(word instr) {
	switch(instr & 0x00ff) {
		case 0x07: { return printLD_DT_I(instr); }
		case 0x0a: { return printLD_K(instr); }
		case 0x15: { return printLD_DT_O(instr); }
		case 0x18: { return printLD_ST(instr); }
		case 0x1e: { return printADD_I_R(instr); }
		case 0x29: { return printLD_S(instr); }
		case 0x33: { return printLD_BCD(instr); }
		case 0x55: { return printLD_A_O(instr); }
		case 0x65: { return printLD_A_I(instr); }
		default: { return badInstr(instr); }
	}
}

int interpret(byte upper, byte lower) {
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
		word instr = lower;
		instr = instr ^ ((upper << 8) & 0xff00);
	#else
		word instr = lower << 8;
		instr = instr ^ (upper & 0x00ff);
	#endif
	switch(instr & 0xf000) {
		case 0x0000: {
			return zeroes(instr);
		}
		break;
		case 0x1000: {
			return printJP(instr);
		}
		break;
		case 0x2000: {
			return printCALL(instr);
		}
		break;
		case 0x3000: {
			return printSE(instr);
		}
		break;
		case 0x4000: {
			return printSNE(instr);
		}
		break;
		case 0x5000: {
			return printSE_R(instr);
		}
		break;
		case 0x6000: {
			return printLD_B(instr);
		}
		break;
		case 0x7000: {
			return printADD_I(instr);
		}
		break;
		case 0x8000: {
			return eights(instr);
		}
		break;
		case 0x9000: {
			return printSNE_R(instr);
		}
		break;
		case 0xa000: {
			return printLD_I(instr);
		}
		break;
		case 0xb000: {
			return printJP_R(instr);
		}
		break;
		case 0xc000: {
			return printRND(instr);
		}
		break;
		case 0xd000: {
			return printDRW(instr);
		}
		break;
		case 0xe000: {
			return ees(instr);
		}
		break;
		case 0xf000: {
			return effs(instr);
		}
		break;
		default: {
			printf("\n");
			return -1;
		}
	}
}
