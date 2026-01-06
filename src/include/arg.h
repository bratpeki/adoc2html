
/* include/arg.h */

#ifndef ADOC2HTML_ARG
#define ADOC2HTML_ARG

/* CLI arg parsing */

#include "bool.h"
#include "ecode.h"

ecode processCliArgs(

	/* Args */
	int argc, char** argv,

	/* Store args here */
	char** filepath,
	char** outpath,
	char** csspath,

	/* So we know if we have to free `outpath` */
	bool* outpathAllocated

);

#endif

