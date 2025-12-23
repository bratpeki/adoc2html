
#ifndef ADOC2HTML_ECODE
#define ADOC2HTML_ECODE

/*
 * Exit codes
 * Enumerated for transparency
 */

enum {
	ECODE_SUCCESS = 0,
	ECODE_NOARG = 1, /* Insufficient arguments passed */
	ECODE_TESTFAIL = 2, /* Some test in `tests` failed */
	ECODE_BADARG = 3 /* CLI args not passed right */
};

typedef int ecode;

#endif

