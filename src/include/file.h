
/* include/file.h */

#ifndef ADOC2HTML_FILE
#define ADOC2HTML_FILE

/* File handling logic */

#include "ecode.h"

/*
 * Processes the input files.
 * Effectively, this is the compilation function.
 *
 * TODO: Add the other files to processing
 */
ecode processFile( char* filename );

#endif

