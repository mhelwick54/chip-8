#include <stdio.h>

#include "instructions.h"
#include "compile.h"

void usage();

int main(int argc, char *argv[]) {
	if(argc != 3) {
		usage();
		return -1;
	}

	printf("Opening files...");

	FILE *in = fopen(argv[1], "r");
	if(!in) {
		printf("couldn't open file\n");
		return -1;
	}
	FILE *out = fopen(argv[2], "w");
	if(!out) {
		printf("couldn't open file\n");
		return -1;
	}

	printf("success.\nCompiling...");

	compile(in, out);

	printf("success.\n");

	return 0;
}

void usage() {
	printf("usage: ./compile [source file] [output filename]\n");
}
