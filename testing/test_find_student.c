/*
** test program for find_student()
**
*/
#include <stdio.h>

#include "types.h"

/*
** Some test students
**
** Note the ordering - this keeps the compiler happy
*/

/* John Smith II */
Student js2 = { 0, 0, "Smith John", 11245, 0 };

/* John Smith I */
Student js1 = { &js2, 0, "Smith John", 11230, 0 };

/* Fred Smith II */
Student fs2 = { &js1, 0, "Smith Fred", 91116, 0 };

/* Fred Smith I */
Student fs1 = { &fs2, 0, "Smith Fred", 90116, 0 };

/* Tom Jones II */
Student tj2 = { &fs1, 0, "Jones Tom", 121, 0 };

/* Tom Jones I */
Student tj1 = { &tj2, 0, "Jones Tom", 120, 0 };

/* Pointer to first student in list */
Student *students = &tj1;	/* Tom Jones I is first */

/*
** Prototype for find_student() routine
*/

Student *find_student( int sid );

/*
** run find_student(sid) and print a result based on its return value
*/

void test( Student *expect, int sid ) {
	Student *p;

	/* run the test */

	p = find_student( sid );

	/* report the results */


	printf( "Looking for %05d", sid );
	if( p == expect ) {
		puts( ", OK" );
	} else {
		printf( ", expected 0x%08x, got 0x%08x\n",
			(uint32_t) expect, (uint32_t) p );
	}

}

/*
** The test driver
*/

int main( void ) {

	/*
	** test( expected_address, pid1, pid2 );
	*/

	test( &js1, 11230 );
	test( &js2, 11245 );
	test( &fs1, 90116 );
	test( &fs2, 91116 );
	test( &tj1, 120 );
	test( &tj2, 121 );

	test( 0, 234 );
	test( 0, 567 );
	test( 0, 9999 );

	/*
	** expand here with additional tests
	*/

	return( 0 );

}
