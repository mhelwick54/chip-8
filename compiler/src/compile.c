#include "compile.h"

int strcmp(char *s1, char *s2) {
	char *ptr1 = s1, *ptr2 = s2;
	while(*ptr1 != '\0' && ptr1 == ptr2) {
		ptr1++;
		ptr2++;
	}

	if(*ptr1 == '\0' && *ptr2 == '\0') {
		return 0;
	} else {
		return 1;
	}
}

word make_SYS(FILE *fp) {
	word instr = SYS;
	word ptr;
	fscanf(fp, "%ld", ptr);
	return instr ^ (ptr & 0x0fff);
}

word make_CLS(FILE *fp) {
	return CLS;
}

word make_RET(FILE *fp) {
	return RET;
}

word make_JP(FILE *fp) {

}

word make_CALL(FILE *fp) {
	word instr = CALL;
	word ptr;
	fscanf(fp, "%ld", ptr);
	return instr ^ (ptr & 0x0fff);
}

word make_SE(FILE *fp) {

}

word make_SNE(FILE *fp) {

}

word make_LD(FILE *fp) {

}

word make_ADD(FILE *fp) {

}

word make_OR(FILE *fp) {
	word instr = OR;
	word ptr;
	fscanf(fp, "%ld", ptr);
	instr = instr ^ (ptr & 0x0f00);
	fscanf(fp, "%ld", ptr);
	return instr ^ (ptr & 0x00f0);
}

word make_AND(FILE *fp) {
	word instr = AND;
	word ptr;
	fscanf(fp, "%ld", ptr);
	instr = instr ^ (ptr & 0x0f00);
	fscanf(fp, "%ld", ptr);
	return instr ^ (ptr & 0x00f0);
}

word make_XOR(FILE *fp) {
	word instr = XOR;
	word ptr;
	fscanf(fp, "%ld", ptr);
	instr = instr ^ (ptr & 0x0f00);
	fscanf(fp, "%ld", ptr);
	return instr ^ (ptr & 0x00f0);
}

word make_SUB(FILE *fp) {
	word instr = SUB;
	word ptr;
	fscanf(fp, "%ld", ptr);
	instr = instr ^ (ptr & 0x0f00);
	fscanf(fp, "%ld", ptr);
	return instr ^ (ptr & 0x00f0);
}

word make_SHR(FILE *fp) {
	word instr = SHR;
	word ptr;
	fscanf(fp, "%ld", ptr);
	instr = instr ^ (ptr & 0x0f00);
	fscanf(fp, "%ld", ptr);
	return instr ^ (ptr & 0x00f0);
}

word make_SUBN(FILE *fp) {
	word instr = SUBN;
	word ptr;
	fscanf(fp, "%ld", ptr);
	instr = instr ^ (ptr & 0x0f00);
	fscanf(fp, "%ld", ptr);
	return instr ^ (ptr & 0x00f0);
}

word make_SHL(FILE *fp) {
	word instr = SHL;
	word ptr;
	fscanf(fp, "%ld", ptr);
	instr = instr ^ (ptr & 0x0f00);
	fscanf(fp, "%ld", ptr);
	return instr ^ (ptr & 0x00f0);
}

word make_RND(FILE *fp) {
	word instr = RND;
	word ptr;
	fscanf(fp, "%ld", ptr);
	instr = instr ^ (ptr & 0x0f00);
	fscanf(fp, "%ld", ptr);
	return instr ^ (ptr & 0x00ff);
}

word make_DRW(FILE *fp) {
	word instr = DRW;
	word ptr;
	fscanf(fp, "%ld", ptr);
	instr = instr ^ (ptr & 0x0f00);
	fscanf(fp, "%ld", ptr);
	instr = instr ^ (ptr & 0x0f00);
	fscanf(fp, "%ld", ptr);
	return instr ^ (ptr & 0x000f);
}

word make_SKP(FILE *fp) {
	word instr = SKP;
	word ptr;
	fscanf(fp, "%ld", ptr);
	return instr ^ (ptr & 0x0f00);
}

word make_SKNP(FILE *fp) {
	word instr = SKNP;
	word ptr;
	fscanf(fp, "%ld", ptr);
	return instr ^ (ptr & 0x0f00);
}


word match(char *buff, FILE *fp) {
	if(!strcmp(buff, "SYS")) {
		return make_SYS(fp);
	} else if(!strcmp(buff, "CLS")) {
		return make_CLS(fp);
	} else if(!strcmp(buff, "RET")) {
		return make_RET(fp);
	} else if(!strcmp(buff, "JP")) {
		return make_JP(fp);
	} else if(!strcmp(buff, "CALL")) {
		return make_CALL(fp);
	} else if(!strcmp(buff, "SE")) {
		return make_SE(fp);
	} else if(!strcmp(buff, "SNE")) {
		return make_SNE(fp);
	} else if(!strcmp(buff, "LD")) {
		return make_LD(fp);
	} else if(!strcmp(buff, "ADD")) {
		return make_ADD(fp);
	} else if(!strcmp(buff, "OR")) {
		return make_OR(fp);
	} else if(!strcmp(buff, "AND")) {
		return make_AND(fp);
	} else if(!strcmp(buff, "XOR")) {
		return make_XOR(fp);
	} else if(!strcmp(buff, "SUB")) {
		return make_SUB(fp);
	} else if(!strcmp(buff, "SHR")) {
		return make_SHR(fp);
	} else if(!strcmp(buff, "SUBN")) {
		return make_SUBN(fp);
	} else if(!strcmp(buff, "SHL")) {
		return make_SHL(fp);
	} else if(!strcmp(buff, "RND")) {
		return make_RND(fp);
	} else if(!strcmp(buff, "DRW")) {
		return make_DRW(fp);
	} else if(!strcmp(buff, "SKP")) {
		return make_SKP(fp);
	} else if(!strcmp(buff, "SKNP")) {
		return make_SKNP(fp);
	} else {
		return 0;
	}
}

void compile(FILE *fp) {
	char buff[8];
	fscanf(fp, "%s", buff);
	switch(match(buff)) {

	}
}
