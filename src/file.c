
#include "include/file.h"

#include "include/ecode.h"

#include <stdio.h>

ecode processFile( char* filepath ) {

	FILE* f;
	char c; /* TODO: Why doesn't fgetc return int? */

	f = fopen(filepath, "r");
	if ( f == NULL ) return ECODE_BADARG;

	do {

		c = (char)fgetc(f);

		switch (c) {
			case EOF:  printf("EOF\n");     break;
			case '\n': printf("Newline\n"); break;
			case '\0': printf("Null\n");    break;
			default:   printf("%c\n", c);   break;
		}

	} while ( c != EOF );

	fclose(f);

	return ECODE_SUCCESS;

}

