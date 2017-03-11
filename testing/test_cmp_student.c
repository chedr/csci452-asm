/*
** test program for cmp_student()
**
*/
#include <stdio.h>

#include "types.h"

/*
** Some test students
**
** Note that the link fields are irrelevant for cmp_student(),
** as is the count of checked-out items
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
** Prototype for cmp_student() routine
*/

int cmp_student( Student *p1, Student *p2 );

/*
** run cmp_student(p1,p2) and print a result based on its return value
*/

void test( char *expect, Student *p1, char *name1, Student *p2, char *name2 ) {
	int n;

	/* run the test */

	n = cmp_student( p1, p2 );

	/* report the results */

	printf( "%s :: %s, expected %s, got ", name1, name2, expect );
	if( n < 0 )		puts( "<" );
	else if ( n == 0 ) 	puts( "=" );
	else			puts( ">" );

}

/*
** The test driver
*/

int main( void ) {
	int n;

	/*
	** test( expected_result,
	**	 first_item, first_item_name,
	**	 second_item, second_item_name );
	*/

	test( "=", &js1, "js1", &js1, "js1" );
	test( "<", &js1, "js1", &js2, "js2" );
	test( ">", &js2, "js2", &js1, "js1" );

	test( "=", &fs1, "fs1", &fs1, "fs1" );
	test( "<", &fs1, "fs1", &fs2, "fs2" );
	test( ">", &fs2, "fs2", &fs1, "fs1" );

	test( "=", &tj1, "tj1", &tj1, "tj1" );
	test( "<", &tj1, "tj1", &tj2, "tj2" );
	test( ">", &tj2, "tj2", &tj1, "tj1" );

	/*
	** expand here with additional tests
	*/

	return( 0 );

}
