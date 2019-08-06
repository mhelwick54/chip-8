#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#ifdef __APPLE__
	#include <ncurses.h>
#else
	#include <curses.h>
#endif

#include "c8_endian.h"
#include "memory_layout.h"
#include "window.h"
#include "instr_win.h"
#include "debug.h"
#include "display.h"
#include "keys.h"

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

int zeroes(word instr);
int eights(word instr);
int ees(word instr);
int effs(word instr);

int doSYS(word instr);
int doCLS(word instr);
int doRET(word instr);
int doJP(word instr);
int doCALL(word instr);
int doSE(word instr);
int doSNE(word instr);
int doSE_R(word instr);
int doLD_B(word instr);
int doADD_I(word instr);
int doLD_R(word instr);
int doOR(word instr);
int doAND(word instr);
int doXOR(word instr);
int doADD(word instr);
int doSUB(word instr);
int doSHR(word instr);
int doSUBN(word instr);
int doSHL(word instr);
int doSNE_R(word instr);
int doLD_I(word instr);
int doJP_R(word instr);
int doRND(word instr);
int doDRW(word instr);
int doSKP(word instr);
int doSKNP(word instr);
int doLD_DT_I(word instr);
int doLD_K(word instr);
int doLD_DT_O(word instr);
int doLD_ST(word instr);
int doADD_I_R(word instr);
int doLD_S(word instr);
int doLD_BCD(word instr);
int doLD_A_O(word instr);
int doLD_A_I(word instr);

int interpret(byte upper, byte lower);

#endif //INSTRUCTIONS_H
