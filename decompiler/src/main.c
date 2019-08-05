#include <stdio.h>
#include <stdint.h>

#include "decompiler.h"

typedef uint8_t byte;
typedef uint16_t word;

byte program[0x1000];
char prog[0x1000][48];
word PC;

int endian;

int load_program(char *file);

int main(int argc, char *argv[]) {
	PC = 0;
	if(argc < 3) {
		printf("usage: ./bin/decompile [filename] -e=[b/l]\n");
		return -1;
	}

	if(argv[2][3] == 'l') {
		endian = 0;
	} else {
		endian = 1;
	}

	int i = 0, lim = 0;
	lim = load_program(argv[1]);
	while(i < lim) {
		interpret(program[i + 1], program[i]);
		i += 2;
		PC++;
	}

	i = 0;
	for(i = 0; i < PC; ++i) {
		printf("%s", prog[i]);
	}

	return 0;
}

int load_program(char *file) {
	FILE *fp = fopen(file, "rb");
	if(!fp) {
		return 0;
	}

	byte half_instr = 0;
	word offset = 0;
	while(fread(&half_instr, sizeof(half_instr), 1, fp)) {
		//#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
		if(endian == 0) {
			program[offset] = half_instr;
			fread(&half_instr, sizeof(half_instr), 1, fp);
			program[offset + 1] = half_instr;
		//#else
		} else {
			program[offset + 1] = half_instr;
			fread(&half_instr, sizeof(half_instr), 1, fp);
			program[offset] = half_instr;
		//#endif
		}
		offset += 2;
	}
	return offset;
}
