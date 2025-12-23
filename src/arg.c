
#include "include/arg.h"
#include "include/printutil.h"
#include "include/strutil.h"
#include "include/ecode.h"

ecode processCliArgs(

	/* Args */
	int argc, char** argv,

	/* Store args here */
	char** filepath,
	char** outpath,
	char** csspath,

	/* So we know if we have to free `outpath` */
	bool* outpathAllocated

) {

	int i;

	/* We need at least the program name and the ADOC file */

	if ( argc < 2 ) {
		printutil("Usage: adoc2html <input.adoc> [-c style.css] [-o out.html]\n", PRINTUTIL_INFO);
		return ECODE_NOARG;
	}

	/* Start loop at 1 to skip the program name */

	for ( i = 1; i < argc; i++ ) {

		/* Handle `-o outfile` */

		if ( STREQ(argv[i], "-o") ) {

			if ( *outpath != NULL ) {
				printutil("Duplicate -o flag detected!\n", PRINTUTIL_ERROR);
				return ECODE_BADARG;
			}

			/*
			 * Inspects if the `outfile` is even provided!
			 *
			 *                     v
			 * ./adoc2html in.adoc -o out.html
			 * 0           1       2  3
			 *
			 * `argc` is 4.
			 * `argv[i]` is the `-o` flag
			 * `argv[i+1]` is the `outfile`
			 *
			 * Therefore, i+1 has to be a valid index, meaning `i+1 < argc`.
			 * Here, we need the error condition, so we flip the logic.
			 *
			 * Simple as!
			 */
			if ( i + 1 >= argc ) {
				printutil("-o requires an output path!\n", PRINTUTIL_ERROR);
				return ECODE_BADARG;
			}

			*outpath = argv[++i]; /* Store next arg and skip it in the loop */

		}

		/* Handle `-c cssfile`, pretty much the same logic as before */

		else if ( STREQ(argv[i], "-c") ) {

			if ( *csspath != NULL ) {
				printutil("Duplicate -c flag detected!\n", PRINTUTIL_ERROR);
				return ECODE_BADARG;
			}

			if ( i + 1 >= argc ) {
				printutil("-c requires a CSS path!\n", PRINTUTIL_ERROR);
				return ECODE_BADARG;
			}

			*csspath = argv[++i];

		}

		/* Handle `filepath` */

		else {

			if ( *filepath != NULL ) {
				printutil("Too many positional arguments!\n", PRINTUTIL_ERROR);
				return ECODE_BADARG;
			}

			*filepath = argv[i];

		}

	}

	/* No point in progressing if we don't have an input file */

	if ( *filepath == NULL ) {
		printutil("No input file specified!\n", PRINTUTIL_ERROR);
		return ECODE_NOARG;
	}

	/* TODO: ./adoc2html -o -o a.adoc ---> `-o` is the `outpath` */

	/* If there's no outpath specified, let's make it */
	if (*outpath == NULL) {

		/* TODO: *outpathAllocated = TRUE; */

	}

	return ECODE_SUCCESS;

}

