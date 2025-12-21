
#include <stdio.h>
#include <stdlib.h>

#include "./include/ecode.h"
#include "./include/printutil.h"
#include "./include/strutil.h"
#include "./include/bool.h" /* TODO: There's probably gonna be boolean flags */

int main( int argc, char** argv ) {

	/* Decls */

	const char* filepath = NULL;
	const char* outpath  = NULL;
	const char* csspath  = NULL;

	int i;

	/* We need at least the program name and one argument */

	if ( argc < 2 ) {
		printutil("No arguments specified!\n", PRINTUTIL_ERROR);
		return ECODE_NOARG;
	}

	/* Start loop at 1 to skip the program name (argv[0]) */

	for ( i = 1; i < argc; i++ ) {

		/* Handle Output Path Flag */

		if ( STREQ(argv[i], "-o") ) {

			if ( outpath != NULL ) {
				printutil("Duplicate -o flag detected!\n", PRINTUTIL_ERROR);
				return ECODE_BADARG;
			}

			if ( i + 1 >= argc ) {
				printutil("-o requires an output path!\n", PRINTUTIL_ERROR);
				return ECODE_BADARG;
			}

			outpath = argv[++i]; /* Store next arg and skip it in the loop */

		}

		/* Handle CSS Path Flag */
		else if ( STREQ(argv[i], "-c") ) {

			if ( csspath != NULL ) {
				printutil("Duplicate -c flag detected!\n", PRINTUTIL_ERROR);
				return ECODE_BADARG;
			}

			if ( i + 1 >= argc ) {
				printutil("-c requires a CSS path!\n", PRINTUTIL_ERROR);
				return ECODE_BADARG;
			}

			csspath = argv[++i]; /* Store next arg and skip it in the loop */

		}

		/* Handle Positional Argument (The ADOC file) */

		else {

			if ( filepath != NULL ) {
				printutil("Too many positional arguments!\n", PRINTUTIL_ERROR);
				return ECODE_BADARG;
			}

			filepath = argv[i];

		}

	}

	/* Validation: Ensure we actually got an input file */
	if ( filepath == NULL ) {
		printutil("No input file specified!\n", PRINTUTIL_ERROR);
		return ECODE_NOARG;
	}

	/* Print Results */

	printutil("FILEPATH: ", PRINTUTIL_INFO); printf("%s\n", filepath);
	if (outpath) { printutil("OUTPATH:  ", PRINTUTIL_INFO); printf("%s\n", outpath); }
	if (csspath) { printutil("CSSPATH:  ", PRINTUTIL_INFO); printf("%s\n", csspath); }

	return ECODE_SUCCESS;

}

