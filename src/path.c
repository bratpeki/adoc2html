
/* path.c */

#include "include/path.h"
#include "include/vector.h"

char* trimExtension( char* path ) {

	strvec out = { 0, 0, 0 };

	char* dotPos = strrchr(path, '.');

	int i;

	/*
	 * Two cases in which we copy the whole string over:
	 *
	 * 1. There's no dot (for example, `mydoc`)
	 * 2. There's a dot, but the file is hidden (dot is the first item; for example, `.mydoc`)
	 */
	if ( (dotPos == NULL) || (dotPos == path) )
		for ( i = 0; path[i] != '\0'; i++ )
			VEC_APPEND(out, path[i]);

	/* In any other case, we go until we hit the dot position */

	else
		for ( i = 0; &path[i] != dotPos; i++ )
			VEC_APPEND(out, path[i]);

	return out.items;

}

char* concatenate( char* str1, char* str2 ) {

	strvec out = { 0, 0, 0 };

	int i;

	for ( i = 0; str1[i] != '\0'; i++ )
		VEC_APPEND(out, str1[i]);

	for ( i = 0; str2[i] != '\0'; i++ )
		VEC_APPEND(out, str2[i]);

	return out.items;

}

