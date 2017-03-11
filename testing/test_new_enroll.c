/*
** test program for new_enroll()
**
*/
#include <stdio.h>
#include <stdlib.h>

#include "types.h"

/*
** Course declarations
*/

/* CS courses */
Course cs100 = { 0, 0, 100, 'C', 'S', 0, 0 };
Course cs200 = { 0, 0, 200, 'C', 'S', 0, 0 };
Course cs300 = { 0, 0, 300, 'C', 'S', 0, 0 };

/* Math courses */
Course ma110 = { 0, 0, 110, 'M', 'A', 0, 0 };
Course ma120 = { 0, 0, 120, 'M', 'A', 0, 0 };

/* Physics courses */
Course ph201 = { 0, 0, 201, 'P', 'H', 0, 0 };
Course ph301 = { 0, 0, 301, 'P', 'H', 0, 0 };

/*
** Student declarations
*/

/* John Smith I */
Student js1 = { 0, 0, "Smith John", 11230, 0 };

/* John Smith II */
Student js2 = { 0, 0, "Smith John", 11245, 0 };

/* Fred Smith I */
Student fs1 = { 0, 0, "Smith Fred", 90116, 0 };

/* Fred Smith II */
Student fs2 = { 0, 0, "Smith Fred", 91116, 0 };

/* Tom Jones I */
Student tj1 = { 0, 0, "Jones Tom", 120, 0 };

/* Tom Jones II */
Student tj2 = { 0, 0, "Jones Tom", 121, 0 };

/*
** Prototype for new_enroll() routine
*/

Enrollment *new_enroll( Student *sp, Course *cp );

/*
** run new_enroll(sp,cp) and print a result based on its return value
*/

void test( Student *sp, Course *cp ) {
	Enrollment *p;
	int errors;

	/* run the test */

	printf( "Create (%8p, %8p):", sp, cp );
	p = new_enroll( sp, cp );

	/* report the results */

	if( p == NULL ) {
		printf( "  Allocation failed!\n" );
	} else {
		errors = 0;
		if( p->stu_in_course != NULL ) {
			fputs( ", stu_in_course != NULL", stdout );
			++errors;
		}
		if( p->course_for_stu != NULL ) {
			fputs( ", course_for_stu != NULL", stdout );
			++errors;
		}
		if( p->student == NULL ) {
			printf( ", student is NULL" );
			++errors;
		} else if( p->student != sp ) {
			printf( ", student is %8p, not %8p", p->student, sp );
			++errors;
		}
		if( p->course == NULL ) {
			printf( ", course is NULL" );
			++errors;
		} else if( p->course != cp ) {
			printf( ", course is %8p, not %8p", p->course, cp );
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

	/*
	** test( sp, cp );
	*/

	test( &js1, &cs100 );
	test( &js2, &ma110 );
	test( &fs1, &ph301 );
	test( &fs2, &ph201 );
	test( &tj1, &cs300 );
	test( &tj2, &ma120 );

	/*
	** expand here with additional tests
	*/

	return( 0 );

}
