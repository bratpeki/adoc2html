
#include <stdio.h>
#include <stdlib.h>

#include "./include/ecode.h"
#include "./include/printutil.h"
#include "./include/bool.h" /* TODO: There's probably gonna be boolean flags */

int main( int argc, char** argv ) {

	/* Decls */

	int i;

	const char* filename; /* CLI arg: ADOC file to be converted */

	/* Code */

	/*
	 * The first argument is always the program itself,
	 * the rest are flags and the file
	 *
	 * We want at least two args, those being the program and ADOC file
	 */

	if ( argc < 2 ) {
		printutil("No arguments specified!\n", PRINTUTIL_ERROR);
		return ECODE_NOARG;
	}

	for ( i = 0; i < argc; i++ ) {
		puts(argv[i]);
	}

	return ECODE_SUCCESS;

}

