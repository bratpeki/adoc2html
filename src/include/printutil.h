
#ifndef ADOC2HTML_PRINTUTIL
#define ADOC2HTML_PRINTUTIL

/*
 * Print utility
 * Calls prints but adds some additional context
 */

#include <stdio.h>

enum {
	PRINTUTIL_INFO = 0,
	PRINTUTIL_ERROR = 1
};

typedef int printType;

void printutil( char* text, printType type );

#endif

