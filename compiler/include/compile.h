#ifndef COMPILE_H
#define COMPILE_H

#include <stdio.h>
#include <stdint.h>

#include "instructions.h"

typedef uint8_t byte;
typedef uint16_t word;


word make_SYS(FILE *fp);
word make_CLS(FILE *fp);
word make_RET(FILE *fp);
word make_JP(FILE *fp);
word make_CALL(FILE *fp);
word make_SE(FILE *fp);
word make_SNE(FILE *fp);
word make_LD(FILE *fp);
word make_ADD(FILE *fp);
word make_OR(FILE *fp);
word make_AND(FILE *fp);
word make_XOR(FILE *fp);
word make_SUB(FILE *fp);
word make_SHR(FILE *fp);
word make_SUBN(FILE *fp);
word make_SHL(FILE *fp);
word make_RND(FILE *fp);
word make_DRW(FILE *fp);
word make_SKP(FILE *fp);
word make_SKNP(FILE *fp);
void compile(FILE *fp);

#endif //COMPILE_H
