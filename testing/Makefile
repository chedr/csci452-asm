#
# Test programs for SP project 2 functions
#
CC =		gcc
AS =		as
CFLAGS =	-std=c99
LIBFLAGS =
CLIBFLAGS =	$(LIBFLAGS)

all:	test_cmp_course test_cmp_student \
	test_find_e_by_course test_find_student \
	test_new_course test_new_enroll \

run:	all
	./test_cmp_course
	./test_cmp_student
	./test_find_e_by_course
	./test_find_student
	./test_new_course
	./test_new_enroll

test_cmp_course:	types.h test_cmp_course.o cmp_course.o
	$(CC) $(CFLAGS) -o test_cmp_course \
		test_cmp_course.o cmp_course.o

cmp_course.o:	cmp_course.s
	$(AS) --gstabs $< -o $@

test_cmp_student:	types.h test_cmp_student.o cmp_student.o
	$(CC) $(CFLAGS) -o test_cmp_student \
		test_cmp_student.o cmp_student.o

cmp_student.o:	cmp_student.s
	$(AS) --gstabs $< -o $@

test_find_e_by_course:	types.h test_find_e_by_course.o find_e_by_course.o
	$(CC) $(CFLAGS) -o test_find_e_by_course \
		test_find_e_by_course.o find_e_by_course.o find_student.o cmp_course.o

find_e_by_course.o:	find_e_by_course.s
	$(AS) --gstabs $< -o $@

test_find_student:	types.h test_find_student.o find_student.o
	$(CC) $(CFLAGS) -o test_find_student \
		test_find_student.o find_student.o

find_student.o:	find_student.s
	$(AS) --gstabs $< -o $@

test_new_course:	types.h test_new_course.o new_course.o
	$(CC) $(CFLAGS) -o test_new_course \
		test_new_course.o new_course.o $(CLIBFLAGS)

new_course.o:	new_course.s
	$(AS) --gstabs $< -o $@

test_new_enroll:	types.h test_new_enroll.o new_enroll.o
	$(CC) $(CFLAGS) -o test_new_enroll \
		test_new_enroll.o new_enroll.o $(CLIBFLAGS)

new_enroll.o:	new_enroll.s
	$(AS) --gstabs $< -o $@

clean:
	rm -f *.o test_cmp_course test_cmp_student test_find_e_by_course \
	test_find_student test_new_course test_new_enroll 
