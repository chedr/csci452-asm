P2DIR =		/usr/local/pub/wrc/courses/csci452/project2
CC =		gcc
AS =		as
CFLAGS =	-ggdb -std=c99
LIBFLAGS =	-L$(P2DIR) -lproject2
CLIBFLAGS =	$(LIBFLAGS)

OBJECTS =	cmp_course.o cmp_student.o find_e_by_course.o find_student.o new_course.o new_enroll.o

.s.o:
	$(AS) --gstabs $< -o $@

infosys:	$(OBJECTS)
	$(CC) $(CFLAGS) -o infosys $(OBJECTS) $(CLIBFLAGS)
