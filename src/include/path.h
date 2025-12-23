
#ifndef ADOC2HTML_PATH
#define ADOC2HTML_PATH

/* Path handling logic */

#include "vector.h"

/* String vector */

struct strvec {
	char** items; /* array of char pointers */
	size_t count;
	size_t capacity;
};

#endif

