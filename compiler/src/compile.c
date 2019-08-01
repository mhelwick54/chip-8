#include "compile.h"

word make_SYS(FILE *fp) {
	word instr = SYS;
	word ptr;
	fscanf(fp, "%hx", &ptr);
	return instr ^ (ptr & 0x0fff);
}

word make_CLS(FILE *fp) {
	return CLS;
}

word make_RET(FILE *fp) {
	return RET;
}

word make_JP(FILE *fp) {
	//JP addr - 1nnn		JP
	//JP V0, addr - bnnn	JP_R
	word instr = 0;
	word addr = 0;
	char c;
	fseek(fp, 1, SEEK_CUR);
	c = fgetc(fp);
	if(c == 'V' || c == 'v') {	//relative JP, scan addr
		instr = JP_R;
		fseek(fp, 2, SEEK_CUR);
	} else {								//absolute JP, write addr back to
		instr = JP;							//file and scan as word
		ungetc(c, fp);
	}
	fscanf(fp, "%hx", &addr);
	return instr ^ (addr & 0x0fff);
}

word make_CALL(FILE *fp) {
	word instr = CALL;
	word ptr;
	fscanf(fp, "%hx", &ptr);
	return instr ^ (ptr & 0x0fff);
}

word make_SE(FILE *fp) {
	//SE Vx, byte - SE 0x3000
	//SE Vx, Vy - SE_R 0x5000
	word instr = 0;
	byte cmp = 0;
	char c;
	fseek(fp, 2, SEEK_CUR);
	c = fgetc(fp);
	instr = ((c - '0') << 8 & 0x0f00);
	fseek(fp, 2, SEEK_CUR);
	c = fgetc(fp);
	if(c == 'V' || c == 'v') {
		c = fgetc(fp);
		instr = instr ^ (SE_R & 0xf00f);
		return instr ^ (((c - '0') << 4) & 0x00f0);
	} else {
		instr = instr ^ (SE & 0xf000);
		ungetc(c, fp);
		fscanf(fp, "%hhx", &cmp);
		return instr ^ (cmp & 0x00ff);
	}
}

word make_SNE(FILE *fp) {
	//SNE Vx, byte - SNE
	//SNE Vx, Vx - SNE_R
	word instr = 0;
	byte cmp = 0;
	char c;
	fseek(fp, 2, SEEK_CUR);
	c = fgetc(fp);
	instr = ((c - '0') << 8 & 0x0f00);
	fseek(fp, 2, SEEK_CUR);
	c = fgetc(fp);
	if(c == 'V' || c == 'v') {
		instr = instr ^ (SNE_R & 0xf00f);
		c = fgetc(fp);
		return instr ^ (((c - '0') << 4) & 0x00f0);
	} else {
		instr = instr ^ (SNE & 0xf000);
		ungetc(c, fp);
		fscanf(fp, "%hhx", &cmp);
		return instr ^ (cmp & 0x00ff);
	}
}

word make_LD(FILE *fp) {
	//LD Vx, byte - LD_B
	//LD Vx, Vy - LD_R
	//LD I, addr - LD_I
	//LD Vx, DT - LD_DT_I
	//LD Vx, K - LD_K
	//LD DT, VxLD_DT_O
	//LD ST, Vx - LD_ST
	//LD F, Vx - LD_S
	//LD B, Vx - LD_BCD
	//LD [I], Vx - LD_A_O
	//LD Vx, [I] - LD_A_I
	word instr = 0;
	char c;
	word addr;
	byte b;
	fseek(fp, 1, SEEK_CUR);
	c = fgetc(fp);
	if(c == 'V' || c == 'v') {
		c = fgetc(fp);
		instr = (((c - '0') << 8) & 0x0f00);
		fseek(fp, 2, SEEK_CUR);
		c = fgetc(fp);
		switch(c) {
			case 'V': { //LD Vx, Vy - LD_R
					instr = instr ^ (LD_R & 0xf00f);
					c = fgetc(fp);
					return instr ^ (((c - '0') << 4) & 0x00f0);
				}
				break;
			case 'v': { //LD Vx, Vy - LD_R
					instr = instr ^ (LD_R & 0xf00f);
					c = fgetc(fp);
					return instr ^ (((c - '0') << 4) & 0x00f0);
				}
				break;
			case 'D': { //LD Vx, DT - LD_DT_I
					fseek(fp, 1, SEEK_CUR);
					return instr ^ (LD_DT_I & 0xf0ff);
				}
				break;
			case 'd': { //LD Vx, DT - LD_DT_I
					fseek(fp, 1, SEEK_CUR);
					return instr ^ (LD_DT_I & 0xf0ff);
				}
				break;
			case 'K': { //LD Vx, K - LD_K
					fseek(fp, 1, SEEK_CUR);
					return instr ^ (LD_K & 0xf0ff);
				}
				break;
			case 'k': { //LD Vx, K - LD_K
					fseek(fp, 1, SEEK_CUR);
					return instr ^ (LD_K & 0xf0ff);
				}
				break;
			case '[': { //LD Vx, [I] - LD_A_I
					fseek(fp, 1, SEEK_CUR);
					return instr ^ (LD_A_I & 0xf0ff);
				}
				break;
			default: { //LD Vx, byte - LD_B
				instr = instr ^ (LD_B & 0xf000);
				ungetc(c, fp);
				fscanf(fp, "%hhx", &b);
				return instr ^ (b & 0x00ff);
			}
		}
	} else {
		switch(c) {
			case 'I': { //LD I, addr - LD_I
					fseek(fp, 2, SEEK_CUR);
					instr = LD_I;
					fscanf(fp, "%hx", &addr);
					return instr ^ (addr & 0x0fff);
				}
				break;
			case 'i': { //LD I, addr - LD_I
					fseek(fp, 2, SEEK_CUR);
					instr = LD_I;
					fscanf(fp, "%hx", &addr);
					return instr ^ (addr & 0x0fff);
				}
				break;
			case 'D': { //LD DT, Vx - LD_DT_O
					fseek(fp, 4, SEEK_CUR);
					instr = LD_DT_O;
					c = fgetc(fp);
					return instr ^ (((c - '0') << 8) & 0x0f00);
				}
				break;
			case 'd': { //LD DT, Vx - LD_DT_O
					fseek(fp, 4, SEEK_CUR);
					instr = LD_DT_O;
					c = fgetc(fp);
					return instr ^ (((c - '0') << 8) & 0x0f00);
				}
				break;
			case 'S': { //LD ST, Vx - LD_ST
					fseek(fp, 4, SEEK_CUR);
					instr = LD_ST;
					c = fgetc(fp);
					return instr ^ (((c - '0') << 8) & 0x0f00);
				}
				break;
			case 's': { //LD ST, Vx - LD_ST
					fseek(fp, 4, SEEK_CUR);
					instr = LD_ST;
					c = fgetc(fp);
					return instr ^ (((c - '0') << 8) & 0x0f00);
				}
				break;
			case 'F': { //LD F, Vx - LD_S
					fseek(fp, 3, SEEK_CUR);
					instr = LD_S;
					c = fgetc(fp);
					return instr ^ (((c - '0') << 8) & 0x0f00);
				}
				break;
			case 'f': { //LD F, Vx - LD_S
					fseek(fp, 3, SEEK_CUR);
					instr = LD_S;
					c = fgetc(fp);
					return instr ^ (((c - '0') << 8) & 0x0f00);
				}
				break;
			case 'B': { //LD B, Vx - LD_BCD
					fseek(fp, 3, SEEK_CUR);
					instr = LD_BCD;
					c = fgetc(fp);
					return instr ^ (((c - '0') << 8) & 0x0f00);
				}
				break;
			case 'b': { //LD B, Vx - LD_BCD
					fseek(fp, 3, SEEK_CUR);
					instr = LD_BCD;
					c = fgetc(fp);
					return instr ^ (((c - '0') << 8) & 0x0f00);
				}
				break;
			case '[': { //LD [I], Vx - LD_A_O
					fseek(fp, 5, SEEK_CUR);
					instr = LD_A_O;
					c = fgetc(fp);
					return instr ^ (((c - '0') << 8) & 0x0f00);
				}
				break;
		}
	}
	return 0;
}

word make_ADD(FILE *fp) {
	//ADD Vx, byte - ADD_I
	//ADD Vx, Vy - ADD
	//ADD I, Vx - ADD_I_R
	word instr = 0;
	byte b = 0;
	char c;
	fseek(fp, 1, SEEK_CUR);
	c = fgetc(fp);
	if(c == 'I' || c == 'i') {
		instr = ADD_I_R;
		fseek(fp, 3, SEEK_CUR);
		c = fgetc(fp);
		return instr ^ (((c - '0') << 8) & 0x0f00);
	} else {
		c = fgetc(fp);
		instr = (((c - '0') << 8) & 0x0f00);
		fseek(fp, 2, SEEK_CUR);
		c = fgetc(fp);
		if(c == 'V' || c == 'v') {
			instr = instr ^ (ADD & 0xf00f);
			c = fgetc(fp);
			return instr ^ (((c - '0') << 4) & 0x00f0);
		} else {
			instr = instr ^ (ADD_I & 0xf000);
			ungetc(c, fp);
			fscanf(fp, "%hhx", &b);
			return instr ^ (b & 0x00ff);
		}
	}
}

word make_OR(FILE *fp) {
	word instr = OR;
	char c;
	fseek(fp, 2, SEEK_CUR);
	c = fgetc(fp);
	instr = instr ^ (((c - '0') << 8) & 0x0f00);
	fseek(fp, 3, SEEK_CUR);
	c = fgetc(fp);
	return instr ^ (((c - '0') << 4) & 0x00f0);
}

word make_AND(FILE *fp) {
	word instr = AND;
	char c;
	fseek(fp, 2, SEEK_CUR);
	c = fgetc(fp);
	instr = instr ^ (((c - '0') << 8) & 0x0f00);
	fseek(fp, 3, SEEK_CUR);
	c = fgetc(fp);
	return instr ^ (((c - '0') << 4) & 0x00f0);
}

word make_XOR(FILE *fp) {
	word instr = XOR;
	char c;
	fseek(fp, 2, SEEK_CUR);
	c = fgetc(fp);
	instr = instr ^ (((c - '0') << 8) & 0x0f00);
	fseek(fp, 3, SEEK_CUR);
	c = fgetc(fp);
	return instr ^ (((c - '0') << 4) & 0x00f0);
}

word make_SUB(FILE *fp) {
	word instr = SUB;
	char c;
	fseek(fp, 2, SEEK_CUR);
	c = fgetc(fp);
	instr = instr ^ (((c - '0') << 8) & 0x0f00);
	fseek(fp, 3, SEEK_CUR);
	c = fgetc(fp);
	return instr ^ (((c - '0') << 4) & 0x00f0);
}

word make_SHR(FILE *fp) {
	word instr = SHR;
	char c;
	fseek(fp, 2, SEEK_CUR);
	c = fgetc(fp);
	return instr ^ (((c - '0') << 8) & 0x0f00);
}

word make_SUBN(FILE *fp) {
	word instr = SUBN;
	char c;
	fseek(fp, 2, SEEK_CUR);
	c = fgetc(fp);
	instr = instr ^ (((c - '0') << 8) & 0x0f00);
	fseek(fp, 3, SEEK_CUR);
	c = fgetc(fp);
	return instr ^ (((c - '0') << 4) & 0x00f0);
}

word make_SHL(FILE *fp) {
	word instr = SHL;
	char c;
	fseek(fp, 2, SEEK_CUR);
	c = fgetc(fp);
	return instr ^ (((c - '0') << 8) & 0x0f00);
}

word make_RND(FILE *fp) {
	word instr = RND;
	byte b;
	char c;
	fseek(fp, 2, SEEK_CUR);
	c = fgetc(fp);
	instr = instr ^ (((c - '0') << 8) & 0x0f00);
	fseek(fp, 2, SEEK_CUR);
	fscanf(fp, "%hhx", &b);
	return instr ^ (b & 0x00ff);
}

word make_DRW(FILE *fp) {
	word instr = DRW;
	char c;
	byte b;
	fseek(fp, 2, SEEK_CUR);
	c = fgetc(fp);
	instr = instr ^ (((c - '0') << 8) & 0x0f00);
	fseek(fp, 3, SEEK_CUR);
	c = fgetc(fp);
	instr = instr ^ (((c - '0') << 4) & 0x00f0);
	fseek(fp, 2, SEEK_CUR);
	fscanf(fp, "%hhx", &b);
	return instr ^ (b & 0x000f);
}

word make_SKP(FILE *fp) {
	word instr = SKP;
	char c;
	fseek(fp, 2, SEEK_CUR);
	c = fgetc(fp);
	return instr ^ (((c - '0') << 8) & 0x0f00);
}

word make_SKNP(FILE *fp) {
	word instr = SKNP;
	char c;
	fseek(fp, 2, SEEK_CUR);
	c = fgetc(fp);
	return instr ^ (((c - '0') << 8) & 0x0f00);
}

void stripSpaceAndComma(char **buff) {
	char *ptr = *buff;
	while(*ptr != '\0') {
		if(*ptr == ' ' || *ptr == ',') {
			*ptr = '\0';
			return;
		}
		++ptr;
	}
}

word match(char *buff, FILE *fp) {
	stripSpaceAndComma(&buff);
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

void compile(FILE *in, FILE *out) {
	char buff[8];
	while(fscanf(in, "%s", buff) >= 0) {
		word instr = match(buff, in);
		if(instr) {
			printf("0x%04x\n", instr);
			fwrite(&instr, sizeof(instr), 1, out);
		}
	}
}
