#include "debug.h"

void setDebug(char *msg) {
	waddstr(debug, msg);
}
