
#ifndef ADOC2HTML_PRINTUTIL
#define ADOC2HTML_PRINTUTIL

/*
 * Print utility
 * Calls prints but adds some additional context
 */

#include <stdio.h>

typedef enum {
	PRINTUTIL_INFO = 0,
	PRINTUTIL_ERROR = 1
} printType;

void printutil( const char* text, printType type ) {
	const char* prefixlist[] = { "INFO", "ERROR" };
	printf("[%s] %s", prefixlist[type], text);
}

#endif

