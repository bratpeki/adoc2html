
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "./include/ecode.h"
#include "./include/printutil.h"
#include "./include/bool.h"
#include "./include/arg.h"

int main( int argc, char** argv ) {

	/* Decls */

	char* filepath = NULL;
	char* outpath  = NULL;
	char* csspath  = NULL;

	ecode retcode;

	/* If the outpath is not provided, we have to allocate some memory for it */
	bool outpathAllocated = FALSE;

	retcode = processCliArgs(
		argc, argv,
		&filepath, &outpath, &csspath,
		&outpathAllocated
	);

	switch (retcode) {
		case ECODE_BADARG:
		case ECODE_NOARG:
			return retcode;
	}

	/* Print results */

	assert( filepath != NULL );
	assert( outpath != NULL );

	printutil("FILEPATH: ", PRINTUTIL_INFO); printf("%s\n", filepath);
	printutil("OUTPATH:  ", PRINTUTIL_INFO); printf("%s\n", outpath);
	if (csspath) { printutil("CSSPATH:  ", PRINTUTIL_INFO); printf("%s\n", csspath); }

	/* Process the files */

	/* Cleanup */

	if ( outpathAllocated ) free(outpath);

	return ECODE_SUCCESS;

}

