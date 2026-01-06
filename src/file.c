
/* file.c */

#include "include/file.h"

#include "include/ecode.h"
#include "include/state.h"

#include <stdio.h>

ecode processFile( char* filepath ) {

	FILE* f;
	int c; /* TODO: Currently only focused on ASCII */

	parserState ps;

	PS_INIT(ps);

	f = fopen(filepath, "r");
	if ( f == NULL ) return ECODE_BADARG;

	do {

		c = (char)fgetc(f);

		switch (c) {

			case EOF:  printf("EOF\n");     break;
			case '\n': printf("Newline\n"); break;
			case '\0': printf("Null\n");    break;

			/* TODO: case '=' */

			default:   printf("%c\n", (unsigned char)c);   break;

		}

	} while ( c != EOF );

	fclose(f);

	return ECODE_SUCCESS;

}

