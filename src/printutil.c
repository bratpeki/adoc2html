
/* printutil.c */

#include "include/printutil.h"

#include <stdio.h>

void printutil( char* text, printType type ) {
	const char* prefixlist[] = { "INFO", "ERROR" };
	printf("[%s] %s", prefixlist[type], text);
}

