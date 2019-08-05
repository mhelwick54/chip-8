#ifndef DECOMP_H
#define DECOMP_H

#include <stdio.h>

#include "instructions.h"

typedef uint8_t byte;
typedef uint16_t word;

extern byte program[0x1000];
extern char prog[0x1000][48];
extern word PC;

int zeroes(word instr);
int eights(word instr);
int ees(word instr);
int effs(word instr);

int interpret(byte upper, byte lower);

#endif //DECOMP_H
