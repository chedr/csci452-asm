/*
** test program for find_e_by_course()
**
*/
#include <stdio.h>

#include "types.h"

/*
** Course declarations
*/

/* Physics courses */
Course ph301 = { 0, 0, 301, 'P', 'H', 0, 0 };
Course ph201 = { &ph301, 0, 201, 'P', 'H', 0, 0 };

/* Math courses */
Course ma120 = { &ph201, 0, 120, 'M', 'A', 0, 0 };
Course ma110 = { &ma120, 0, 110, 'M', 'A', 0, 0 };

/* CS courses */
Course cs300 = { &ma110, 0, 300, 'C', 'S', 0, 0 };
Course cs200 = { &cs300, 0, 200, 'C', 'S', 0, 0 };
Course cs100 = { &cs200, 0, 100, 'C', 'S', 0, 0 };

/* Pointer to first course in list */
Course *courses = &cs100;

/*
** Student declarations
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
** Enrollment nodes
**
** Matrix ("*" indicates an enrollment):
**
** Student        CS100 CS200 CS300 MA110 MA120 PH201 PH301
** =============  ===== ===== ===== ===== ===== ===== =====
** Tom Jones I            *           *           *
** Tom Jones II	    *                 *
** Fred Smith I                 *                       *
** Fred Smith II          *           *
** John Smith I
** John Smith II                      *
**
** Naming convention:  e_STUDENT_COURSE
*/

                         /*    S-in-C       C-for-S      Stu  Course */
Enrollment e_tj1_ph201 = {            0,            0, &tj1, &ph201 };
Enrollment e_fs1_ph301 = {            0,            0, &fs1, &ph301 };
Enrollment e_fs1_cs300 = {            0, &e_fs1_ph301, &fs1, &cs300 };
Enrollment e_js2_ma110 = {            0,            0, &js2, &ma110 };
Enrollment e_fs2_ma110 = { &e_js2_ma110,            0, &fs2, &ma110 };
Enrollment e_fs2_cs200 = {            0, &e_fs2_ma110, &fs2, &cs200 };
Enrollment e_tj2_ma110 = { &e_fs2_ma110,           0, &tj2, &ma110 };
Enrollment e_tj2_cs100 = {            0, &e_tj2_ma110, &tj2, &cs100 };
Enrollment e_tj1_ma110 = { &e_tj2_ma110, &e_tj1_ph201, &tj1, &ma110 };
Enrollment e_tj1_cs200 = { &e_fs2_cs200, &e_tj1_ma110, &tj1, &cs200 };

/*
** Prototype for find_e_by_course() routine
*/

Enrollment *find_e_by_course( int sid, uint8_t cid1, uint8_t cid2,
				uint16_t cid3 );

/*
** run find_e_by_course(sid,cid) and print a result based on its return value
*/

void test( Enrollment *expect, int sid, uint8_t cid1,
	   uint8_t cid2, uint16_t cid3 ) {
	Enrollment *i;

	/* run the test */

	i = find_e_by_course( sid, cid1, cid2, cid3 );

	/* report the results */

	printf( "Looking for %05d in %c%c%03d", sid, cid1, cid2, cid3 );
	if( i == expect ) {
		puts( ", OK" );
	} else {
		printf( ", expected %#08x, got %#08x\n",
			(uint32_t) expect, (uint32_t) i );
	}

}

/*
** The test driver
*/

int main( void ) {
	int n;

	/*
	** Make the final connections between students and courses
	*/

	/* first student in each course */
	cs100.students = &e_tj2_cs100;
	cs200.students = &e_tj1_cs200;
	cs300.students = &e_fs1_cs300;
	ma110.students = &e_tj1_ma110;
	ph201.students = &e_tj1_ph201;
	ph301.students = &e_fs1_ph301;

	/* first course for each student */
	tj1.courses = &e_tj1_cs200;
	tj2.courses = &e_tj2_cs100;
	fs1.courses = &e_fs1_cs300;
	fs2.courses = &e_fs2_cs200;
	js2.courses = &e_js2_ma110;

	/*
	** test( expected_result, sid, cid1, cid2, cid3 );
	*/

	/* first students in courses */
	test( &e_tj2_cs100,   121, 'C', 'S', 100 );
	test( &e_tj1_cs200,   120, 'C', 'S', 200 );
	test( &e_fs1_cs300, 90116, 'C', 'S', 300 );
	test( &e_tj1_ma110,   120, 'M', 'A', 110 );
	test( &e_tj1_ph201,   120, 'P', 'H', 201 );
	test( &e_fs1_ph301, 90116, 'P', 'H', 301 );

	/* last students in courses */
	test( &e_fs2_cs200, 91116, 'C', 'S', 200 );
	test( &e_js2_ma110, 11245, 'M', 'A', 110 );

	/* middle students in courses */
	test( &e_fs2_ma110, 91116, 'M', 'A', 110 );
	test( &e_tj2_ma110,   121, 'M', 'A', 110 );

	/* students not in each course */
	test(            0,   120, 'C', 'S', 100 );
	test(            0,   121, 'C', 'S', 200 );
	test(            0, 11230, 'C', 'S', 300 );
	test(            0, 90116, 'M', 'A', 110 );
	test(            0,   120, 'M', 'A', 120 );
	test(            0, 91116, 'P', 'H', 201 );
	test(            0, 11245, 'P', 'H', 301 );

	/*
	** expand here with additional tests
	*/

	return( 0 );

}
