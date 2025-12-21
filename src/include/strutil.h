
#ifndef ADOC2HTML_STRUTIL
#define ADOC2HTML_STRUTIL

#include <stddef.h>
#include <string.h>

#define STREQ( s1, s2 ) ( strcmp(s1, s2) == 0 )

/*
 * Removes the extension from a filename or path.
 * Modifies the string in-place.
 * Returns the modified string, or NULL if no extension was found.
 */
char* stripExtension(char* filepath) {

	/* Decls */
	char *lastDot;
	char *lastSep;

	if (filepath == NULL) return NULL;

	/* Find the last dot and the last directory separator */
	lastDot = strrchr(filepath, '.');
	lastSep = strrchr(filepath, '/');

	/*
	 * Logic check:
	 * 1. We found a dot.
	 * 2. The dot is NOT the first character (handles hidden files like .bashrc)
	 * 3. The dot comes AFTER the last directory separator (handles /my.dir/file)
	 */

	if (
		( lastDot != NULL ) &&
		( lastDot != filepath ) &&
		( (lastSep == NULL) || (lastDot > lastSep) )
	) {
		*lastDot = '\0';
		return filepath;
	}

	return NULL;
}

#endif

