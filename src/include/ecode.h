
/* include/ecode.h */

#ifndef ADOC2HTML_ECODE
#define ADOC2HTML_ECODE

/*
 * Exit codes
 * Enumerated for transparency
 */

typedef enum _ecode {
	ECODE_SUCCESS = 0,
	ECODE_NOARG = 1, /* Insufficient arguments passed */
	ECODE_TESTFAIL = 2, /* Some test in `tests` failed */
	ECODE_BADARG = 3 /* CLI args not passed right */
} ecode;

#endif

