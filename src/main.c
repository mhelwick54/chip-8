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

#include "memory_layout.h"
#include "registers.h"
#include "sprites.h"
#include "display.h"
#include "info_wins.h"

const float CLOCK_SPEED = 500.0;
const float CLOCK_PERIOD = ((1.0 * 1000.0)/ CLOCK_SPEED);
const int TIMER_PERIOD = (int)CLOCK_SPEED;

//extern defs
byte 	*memory;
byte 	*stack;
byte 	registers[18];
byte 	stack_pointer;
word 	program_counter;
byte 	sprites[DISPLAY_HEIGHT][DISPLAY_WIDTH];
byte 	framebuffer[DISPLAY_HEIGHT * DISPLAY_WIDTH];

void startup();
void shutdown();

void execute();

void test_sprites();

int main() {
	startup();

	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	uint64_t cycle = 0;
	int timer_tick = 0;
	char c;
	test_sprites();

	while(1) {
		clock_gettime(CLOCK_MONOTONIC_RAW, &end);
		float delta = (float)(end.tv_sec - start.tv_sec) * 1000.0 + (float)(end.tv_nsec - start.tv_nsec) / 1000000.0;
		if(cycle % TIMER_PERIOD == 0 && !timer_tick) {
			if(DELAY_TIMER != 0) {
				DELAY_TIMER--;
				printf("%d\n", DELAY_TIMER);
			}
			if(SOUND_TIMER != 0) {
				SOUND_TIMER--;
			}
			timer_tick = 1;
		}
		if(delta >= CLOCK_PERIOD) {
			clock_gettime(CLOCK_MONOTONIC_RAW, &start);
			timer_tick = 0;
			cycle++;

			execute();
			scanf("%c", &c);
			break;
		}
	}

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
	stack = malloc(STACK_SIZE * BYTE_SIZE);
	printf("initializing registers...\n");
	PC = (word)DATA_OFFSET;
	SP = STACK_TOP;
	DELAY_TIMER = 0;
	SOUND_TIMER = 0;
	printf("setting sprites...\n");
	setSprites();
	printf("ready\n");
}

void shutdown() {
	endwin();
	printf("cleaning ram...\n");
	free(memory);
	printf("shutting down...\n");
}

void execute() {

	INC_PC(PC);
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
	printDisplay();
}
