
#ifndef ADOC2HTML_PATH
#define ADOC2HTML_PATH

/* Path handling logic */

#include <string.h>

#include "vector.h"
#include "ecode.h"

/* String vector */

struct strvec {
	char* items;
	size_t count;
	size_t capacity;
};

/*
 * Returns a new string with the extension trimmed.
 *
 * Allocates memory for a `strvec` instance.
 * Returns `strvec.items`.
 */
char* trimExtension( char* path );

/*
 * Returns a new allocated string.
 * Combines `str1` and `str2`.
 *
 * Both must be valid, null-terminated strings.
 *
 * Allocates memory for a `strvec` instance.
 * Returns `strvec.items`.
 */
char* concatenate( char* str1, char* str2 );

#endif

