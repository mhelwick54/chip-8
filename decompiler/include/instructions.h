#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <stdio.h>
#include <stdint.h>

#include "decompiler.h"

typedef uint8_t byte;
typedef uint16_t word;

#define SYS		0x0000
#define CLS		0x00e0
#define RET		0x00ee
#define JP		0x1000
#define CALL	0x2000
#define SE		0x3000
#define SNE		0x4000
#define SE_R	0x5000
#define LD_B	0x6000
#define ADD_I	0x7000
#define LD_R	0x8000
#define OR		0x8001
#define AND		0x8002
#define XOR		0x8003
#define ADD		0x8004
#define SUB		0x8005
#define SHR		0x8006
#define SUBN	0x8007
#define SHL		0x800e
#define SNE_R	0x9000
#define LD_I	0xa000
#define JP_R	0xb000
#define RND		0xc000
#define DRW		0xd000
#define SKP		0xe09e
#define SKNP	0xe0a1
#define LD_DT_I	0xf007
#define LD_K	0xf00a
#define LD_DT_O	0xf015
#define LD_ST	0xf018
#define ADD_I_R	0xf01e
#define LD_S	0xf029
#define LD_BCD	0xf033
#define LD_A_O	0xf055
#define LD_A_I	0xf065

int printSYS(word instr);
int printCLS(word instr);
int printRET(word instr);
int printJP(word instr);
int printCALL(word instr);
int printSE(word instr);
int printSNE(word instr);
int printSE_R(word instr);
int printLD_B(word instr);
int printADD_I(word instr);
int printLD_R(word instr);
int printOR(word instr);
int printAND(word instr);
int printXOR(word instr);
int printADD(word instr);
int printSUB(word instr);
int printSHR(word instr);
int printSUBN(word instr);
int printSHL(word instr);
int printSNE_R(word instr);
int printLD_I(word instr);
int printJP_R(word instr);
int printRND(word instr);
int printDRW(word instr);
int printSKP(word instr);
int printSKNP(word instr);
int printLD_DT_I(word instr);
int printLD_K(word instr);
int printLD_DT_O(word instr);
int printLD_ST(word instr);
int printADD_I_R(word instr);
int printLD_S(word instr);
int printLD_BCD(word instr);
int printLD_A_O(word instr);
int printLD_A_I(word instr);

int badInstr(word instr);

#endif //INSTRUCTIONS_H
