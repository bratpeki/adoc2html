
/* include/state.h */

#ifndef ADOC2HTML_STATE
#define ADOC2HTML_STATE

/*
 * adoc2html state tracking.
 *
 * Tracks what we're doing currently,
 * like defining a header, bolded text, etc.
 *
 * Basically, a singleton context memory.
 */

#include "bool.h"

/* Enums for mutually exclusive states */

typedef enum _commentType {
	COMMENT_NONE,
	COMMENT_SINGLE,
	COMMENT_MULTI
} commentType;

/* By default, these should all be initialized to 0 */

typedef struct _parserState {

	/*
	 * Headers.
	 * = Example
	 * ==== Another example
	 *
	 * Depth of 0 is not a header.
	 */
	unsigned char depthHeader;

	/*
	 * Basic text modifiers.
	 * *Bold*, _italic_, `monospace`.
	 */
	bool isBold;
	bool isItalic;
	bool isMonospace;

	/*
	 * Comments
	 *
	 * // Single line comment
	 *
	 * ////
	 * Multi-line
	 * comment
	 * ////
	 */
	commentType ct;

	/*
	 * TODO
	 * Lists
	 *
	 * There's ordered, unoredered and checklists
	 */

} parserState;

#define PS_INIT(ps) \
	do { \
		(ps).depthHeader = 0; \
		(ps).isBold = FALSE; \
		(ps).isItalic = FALSE; \
		(ps).isMonospace = FALSE; \
		(ps).ct = COMMENT_NONE; \
	} while(0);

#endif

