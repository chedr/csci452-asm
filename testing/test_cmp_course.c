/*
** test program for cmp_course()
**
*/
#include <stdio.h>

#include "types.h"

/*
** Some test courses
**
** Note that the link fields are irrelevant for cmp_course(),
** as are the counts, so they are all zero.
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
** Prototype for cmp_course() routine
*/

int cmp_course( char A, char B, uint16_t num1,
		char C, char D, uint16_t num2 );

/*
** run cmp_course(i1,i2) and print a result based on its return value
*/

void test( char *expect, Course *i1, char *name1, Course *i2, char *name2 ) {
	int n;

	/* run the test */

	n = cmp_course( i1->A, i1->B, i1->num,
			i2->A, i2->B, i2->num );

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

	test( "=", &cs100, "cs100", &cs100, "cs100" );
	test( "<", &cs100, "cs100", &cs200, "cs200" );
	test( ">", &cs200, "cs200", &cs100, "cs100" );
	test( "<", &cs100, "cs100", &cs300, "cs300" );
	test( ">", &cs300, "cs300", &cs200, "cs200" );

	/*
	** expand here with additional tests
	*/

	return( 0 );

}
