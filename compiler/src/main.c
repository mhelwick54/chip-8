#include <stdio.h>

#include "instructions.h"
#include "compile.h"

void usage();

int main(int argc, char *argv[]) {
	if(argc != 2) {
		usage();
		return -1;
	}

	FILE *fp = fopen(argv[1], "r");
	if(!fp) {
		printf("couldn't open file\n");
		return -1;
	}

	compile(fp);

	return 0;
}

void usage() {
	printf("usage: ./compile [source file]\n");
}
