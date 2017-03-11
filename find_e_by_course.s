# File:        find_e_by_course.s
# Author:      cer6526
# Description: Locates the enrollment node for the student with the specified
#              sid in the list of students enrolled in the course with cid ABnum
#              and returns a pointer to it; returns 0 if the course does not 
#              exist or if the student is not enrolled in that course. 
# Notes:       This does not work properly.
.text
.globl find_e_by_course

find_e_by_course:
#Setup stack frame
  pushl  %ebp
  movl   %esp, %ebp
  pushl  %ebx
  pushl  %edi
  pushl  %esi
  subl   $28, %esp

  movl   8(%ebp), %eax           #Get sid
  movl   %eax, (%esp)            #Set sid as argument
  calll  find_student            #Call find_student
  movl   %eax, %esi              #Save result
  addl   $4, %esi                #Add 4 to get student->courses

.loop_find_e_by_course:
  movl   (%esi), %esi            #Get address
  cmpl   $0, %esi                #Set comparison flags; current == NULL
  je     .exit_find_e_by_course  #Exit if true
  #Compare courses here
  addl   $4, %esi                #Increment


# TODO:
#   Student *stu  = find_student(sid)
#   Enrollment *e = student->courses
#   while (e != NULL)
#     if (cmp_course) return e
#     e = e->next
#   return NULL

  movl   $0, %eax                 #Set return to NULL
  
#Tear down stack frame
.exit_find_e_by_course:
  addl   $28, %esp
  popl   %esi
  popl   %edi
  popl   %ebx
  popl   %ebp
  ret
