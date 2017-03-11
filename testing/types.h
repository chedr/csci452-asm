/*
** Data type declarations for project 2 test programs
*/

#ifndef _TYPES_H
#define _TYPES_H

#include <sys/types.h>
#include <stdint.h>

typedef
	struct snode {
		struct snode *next;	/* student links */
		struct enode *courses;	/* list of courses */
		char     *name;		/* lname fname mi */
		int      sid;		/* student id */
		uint8_t  current;	/* enrollment info */
	}
		Student;

typedef
	struct cnode {
		struct cnode *next;	/* course links */
		struct enode *students;	/* student list */
		uint16_t num;		/* course id:  ccNNN */
		uint8_t  A;		/* course id:  Ccnnn */
		uint8_t  B;		/* course id:  cCnnn */
		uint8_t  max;		/* max enrollment */
		uint8_t  current;	/* curr enrollment */
	}
		Course;

typedef
	struct enode {
		struct enode *stu_in_course;	/* course enrollment link */
		struct enode *course_for_stu;	/* student enrollment link */
		Student   *student;		/* ptr to student node */
		Course    *course;		/* ptr to course node */
	}
		Enrollment;

#endif
