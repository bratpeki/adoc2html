
#ifndef ADOC2HTML_VECTOR
#define ADOC2HTML_VECTOR

/* Vector, an implementation of the dynamic array */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * This is an example of an integer vector.
 * typedef struct ivec {
 *   int *items;
 *   size_t count;
 *   size_t capacity;
 * } ivec_t;
 */

/*
 * Appends `item` to vector `vec`.
 *
 * As long as the structure includes
 * - `ANYTYPE* items`
 * - `size_t count`
 * - `size_t capacity`
 * this macro should work for it.
 *
 * Set the initial `capacity` to taste, I put `16`.
 *
 * This also force-exits the program with an exit code of 1 if it can't reallocate memory.
 * You will probably want it to handle it differently.
 */
#define VEC_APPEND( vec, item ) \
	do { \
		if ( (vec).count >= (vec).capacity ) { \
			if ( (vec).capacity == 0 ) (vec).capacity = 16; \
			else (vec).capacity *= 2; \
			(vec).items = realloc((vec).items, (vec).capacity * sizeof(*(vec).items)); \
			if ( (vec).items == NULL ) exit(1); \
		} \
		(vec).items[(vec).count++] = (item); \
	} while (0)

/*
 * Removes an item from `vec` at the given `index`.
 *
 * Checks the upper bound (always the index of the last added item).
 *
 * Make sure `index` is an unsigned type, since this macro doesn't check the lower bound.
 * Preferably, `index` is a `size_t`.
 *
 * Some implementations call for shrinking the allocated memory
 * if the count goes below a certain threshold, usually capacity/2 or capacity/4.
 * That's not implemented here.
 */
#define VEC_REMOVE( vec, index ) \
	do { \
		if ( (index) < (vec).count ) { \
			memmove( \
				&(vec).items[(index)], \
				&(vec).items[(index) + 1], \
				sizeof(*(vec).items) * ((vec).count - 1 - (index)) \
			); \
			(vec).count--; \
		} \
	} while (0)

#endif

