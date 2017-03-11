/*
** test program for new_course()
**
*/
#include <stdio.h>
#include <stdlib.h>

#include "types.h"

/*
** Some test courses
*/

/* CS courses */
Course cs100 = { 0, 0, 100, 'C', 'S',  5, 0 };
Course cs200 = { 0, 0, 200, 'C', 'S', 10, 0 };
Course cs300 = { 0, 0, 300, 'C', 'S', 44, 0 };

/* Math courses */
Course ma110 = { 0, 0, 110, 'M', 'A', 29, 0 };
Course ma120 = { 0, 0, 120, 'M', 'A', 99, 0 };

/* Physics courses */
Course ph201 = { 0, 0, 201, 'P', 'H', 86, 0 };
Course ph301 = { 0, 0, 301, 'P', 'H',  7, 0 };

/*
** Prototype for new_course() routine
*/

Course *new_course( uint8_t cid1, uint8_t cid2, uint16_t cid3, uint8_t size );

/*
** run new_course(cid1,cid2) and print a result based on its return value
*/

void test( uint8_t cid1, uint8_t cid2, uint16_t cid3, uint8_t size ) {
	Course *p;
	int errors;

	/* run the test */

	printf( "Creating ('%c','%c',%d,%d):", cid1, cid2, cid3, size );
	p = new_course( cid1, cid2, cid3, size );

	/* report the results */

	if( p == NULL ) {
		printf( "  Allocation failed!\n" );
	} else {
		errors = 0;
		if( p->next != 0 ) {
			fputs( ", next != 0", stdout );
			++errors;
		}
		if( p->students != 0 ) {
			fputs( ", students != 0", stdout );
			++errors;
		}
		if( p->num != cid3 ) {
			printf( ", num != %d", cid3 );
			++errors;
		}
		if( p->A != cid1 ) {
			printf( ", A != '%c'", cid1 );
			++errors;
		}
		if( p->B != cid2 ) {
			printf( ", B != '%c'", cid2 );
			++errors;
		}
		if( p->max != size ) {
			printf( ", max != %d", size );
			++errors;
		}
		if( p->current != 0 ) {
			fputs( ", current != 0", stdout );
			++errors;
		}
		if( errors == 0 ) {
			fputs( "\tOK\n", stdout );
		} else {
			putchar( '\n' );
		}
		free( p );
	}

}

/*
** The test driver
*/

int main( void ) {
	int n;

	/*
	** test( cid1, cid2, cid3, size );
	*/

	test( cs100.A, cs100.B, cs100.num, cs100.max );
	test( cs200.A, cs200.B, cs200.num, cs200.max );
	test( cs300.A, cs300.B, cs300.num, cs300.max );
	test( ma110.A, ma110.B, ma110.num, ma110.max );
	test( ma120.A, ma120.B, ma120.num, ma120.max );
	test( ph201.A, ph201.B, ph201.num, ph201.max );
	test( ph301.A, ph301.B, ph301.num, ph301.max );

	/*
	** expand here with additional tests
	*/

	return( 0 );

}
