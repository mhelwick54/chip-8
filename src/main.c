#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <unistd.h>
#ifdef __APPLE__
	#include <ncurses.h>
#else
	#include <curses.h>
#endif

#include "c8_endian.h"
#include "memory_layout.h"
#include "registers.h"
#include "sprites.h"
#include "window.h"
#include "display.h"
#include "debug.h"
#include "instr_win.h"
#include "reg_win.h"
#include "instructions.h"
#include "keys.h"

//extern defs
int		endian;
byte 	*memory;
byte 	registers[18];
word	address_reg;
byte 	stack_pointer;
word 	program_counter;
byte 	sprites[DISPLAY_HEIGHT][DISPLAY_WIDTH];
WINDOW	*win;
WINDOW	*display;
WINDOW	*debug;
WINDOW	*instructions;
WINDOW	*regs;
int		keys[16];
struct 	termios tty;

void startup();
void shutdown();

int 	load_program(char *file);
int 	execute();
void 	getKeys();

void test_sprites();
void test_collision();

int main(int argc, char *argv[]) {
	float CLOCK_SPEED = 500.0;
	float CLOCK_PERIOD = ((1.0 * 1000.0)/ CLOCK_SPEED);

	startup();

	if(argv[2][3] == 'l') {
		endian = BIN_LITTLE_ENDIAN;
	} else {
		endian = BIN_BIG_ENDIAN;
	}

	if(!load_program(argv[1])) {
		return -1;
	}

	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	uint64_t cycle = 0;
	int timer_tick = 0;
	char c;
	int executing = 1;

	resetKeys();
	printRegs();
	refreshReg();
	scanf("%c", &c);

	while(executing != -2) {
		clock_gettime(CLOCK_MONOTONIC_RAW, &end);
		float delta = (float)(end.tv_sec - start.tv_sec) * 1000.0 + (float)(end.tv_nsec - start.tv_nsec) / 1000000.0;
		if(cycle > (CLOCK_SPEED / 60) && !timer_tick) {
			if(DT != 0) {
				DT--;
			}
			if(ST != 0) {
				ST--;
			}
			timer_tick = 1;
			cycle = 0;
			refreshDisplay();
		}
		if(delta >= CLOCK_PERIOD) {
			getKeys();
			clock_gettime(CLOCK_MONOTONIC_RAW, &start);
			timer_tick = 0;
			cycle++;

			executing = execute();
			if(DT > 0) {
				DT--;
			}
			if(ST > 0) {
				ST--;
			}
			//scanf("%c", &c);
		}
	}
	refreshWins();

	scanf("%c", &c);
	shutdown();
	return 0;
}

void startup() {
	printf("booting up...\n");
	printf("initializing ram...");
	memory = malloc(MEM_BYTES * sizeof(byte));
	if(memory == NULL) {
		printf("failure. exiting...\n");
		exit(-1);
	} else {
		printf("success.\n");
	}
	printf("initializing registers...\n");
	initRegisters();
	printf("setting sprites...\n");
	setSprites();
	printf("ready\n");
	tty_set();
	initWins();
	displaySplash();
	sleep(3);
	clearDisplay();
	printRegs();
	refreshWins();
}

void shutdown() {
	delwin(debug);
	delwin(instructions);
	delwin(display);
	endwin();
	printf("cleaning ram...\n");
	free(memory);
	printf("shutting down...\n");
	tty_reset();
}

int load_program(char *file) {
	FILE *fp = fopen(file, "rb");
	if(!fp) {
		return 0;
	}

	byte half_instr = 0;
	word mem_offset = DATA_OFFSET;
	char buff[24];
	while(fread(&half_instr, sizeof(half_instr), 1, fp)) {
		if(endian == BIN_LITTLE_ENDIAN) {
			MEM_WRITE(mem_offset, half_instr);
			sprintf(buff, "0x%02x\n", half_instr);
			//setDebug(buff);
			fread(&half_instr, sizeof(half_instr), 1, fp);
			MEM_WRITE(mem_offset + 1, half_instr);
		} else {
			MEM_WRITE(mem_offset + 1, half_instr);
			sprintf(buff, "0x%02x\n", half_instr);
			//setDebug(buff);
			fread(&half_instr, sizeof(half_instr), 1, fp);
			MEM_WRITE(mem_offset, half_instr);
		}
		sprintf(buff, "0x%02x\n", half_instr);
		//setDebug(buff);
		//refreshDebug();
		mem_offset += 2;
	}
	return 1;
}

int execute() {
	int ret = 1;
	ret = interpret(MEM_READ(PC), MEM_READ(PC + 1));
	INC_PC(PC);
	printRegs();
	refreshReg();
	return ret;
}

void getKeys() {
	resetKeys();
	while(kbhit()) {
		int c;
		c = kb_getch();
		char buff[32];
		sprintf(buff, "key pressed %d\n", c);
		setDebug(buff);
		refreshDebug();
		if(c == 27) {	//esc
			tty_reset();
			exit(1);
		}
		pressKey(c);
	}
}

void test_sprites() {
	setPixels(0, 0, 5, SPRITE_HEX_0);
	setPixels(8, 0, 5, SPRITE_HEX_1);
	setPixels(16, 0, 5, SPRITE_HEX_2);
	setPixels(24, 0, 5, SPRITE_HEX_3);
	setPixels(32, 0, 5, SPRITE_HEX_4);
	setPixels(40, 0, 5, SPRITE_HEX_5);
	setPixels(48, 0, 5, SPRITE_HEX_6);
	setPixels(56, 0, 5, SPRITE_HEX_7);
	setPixels(0, 8, 5, SPRITE_HEX_8);
	setPixels(8, 8, 5, SPRITE_HEX_9);
	setPixels(16, 8, 5, SPRITE_HEX_A);
	setPixels(24, 8, 5, SPRITE_HEX_B);
	setPixels(32, 8, 5, SPRITE_HEX_C);
	setPixels(40, 8, 5, SPRITE_HEX_D);
	setPixels(48, 8, 5, SPRITE_HEX_E);
	setPixels(56, 8, 5, SPRITE_HEX_F);
	setDisplay();
	refreshWins();
}

void test_collision() {
	setPixels(0, 0, 5, SPRITE_HEX_8);
	setPixels(3, 3, 5, SPRITE_HEX_8);
	setDisplay();
	if(VF == 1) {
		setDebug("collide\n");
	} else{
		setDebug("no collide\n");
	}
	refreshWins();
	sleep(2);
	clearDisplay();

	setPixels(0, 0, 5, SPRITE_HEX_8);
	setPixels(12, 12, 5, SPRITE_HEX_8);
	setDisplay();
	if(VF == 1) {
		setDebug("collide\n");
	} else{
		setDebug("no collide\n");
	}
	refreshWins();
}
