#ifndef WINDOW_H
#define WINDOW_H

extern WINDOW *win;

extern WINDOW *display;
extern WINDOW *debug;
extern WINDOW *instructions;

/*								66 + 34 = 100
 /				(64 + 2 = 66)				(32 + 2 = 34)
 /	   +----------------------------------------------------+
 /	   |+--------------------------------++----------------+|
 /	   ||								 ||				   ||
 /	   ||								 ||				   ||
 /	   ||								 ||		instr	   ||
 /	   ||								 ||				   || (32 + 2 = 34)
 /	   ||		display					 ||				   ||
 /	   ||								 ||				   ||
 /	   ||								 ||				   ||
 /	   ||								 ||				   ||
 /	   |+--------------------------------++----------------+|					34 + 34 = 72
 /	   |+--------------------------------++----------------+|
 /	   ||												   ||
 /	   ||												   ||
 /	   ||												   ||
 /	   ||												   || (32 + 2 = 34)
 /	   ||			debug								   ||
 /	   ||												   ||
 /	   ||												   ||
 /	   ||												   ||
 /	   |+--------------------------------------------------+|
 /	   +----------------------------------------------------+
 /								(96 + 2 = 98)
 /							100
 */

#define BORDER_OFFSET 2

#define DISP_W (64 + BORDER_OFFSET)
#define DISP_H (32 + BORDER_OFFSET)
#define DISP_X 1
#define DISP_Y 1

#define INSTR_W (32 + BORDER_OFFSET)
#define INSTR_H (32 + BORDER_OFFSET)

#define DEBUG_W (96 + BORDER_OFFSET)
#define DEBUG_H (32 + BORDER_OFFSET)

#define WIN_W (DISP_W + INSTR_W)
#define WIN_H (DISP_H + DEBUG_H)

#endif //WINDOW_H
