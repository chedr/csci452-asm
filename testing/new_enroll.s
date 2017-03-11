# File:        new_enroll.s
# Author:      cer6526
# Description: Allocates a new Enrollment node; copies the Student and Course
#              pointers into the corresponding fields in the new node; copies
#              NULL into the other pointer fields; and returns the pointer to
#              the new node. If the allocation fails, returns 0.
.text
.globl new_enroll

new_enroll:
#Setup stack frame
  pushl  %ebp
  movl   %esp, %ebp
  subl   $8, %esp

#malloc(sizeof(Enrollment))
  movl   $16, (%esp)      #sizeof(Enrollment)
  calll  malloc           #Call malloc
  cmpl   $0, %eax         #Set comparison flags
  je     .exit_new_enroll #If failed malloc, goto out
  
#Fill structure  
  movl   $0,  (%eax)      #Set stu_in_course to NULL
  movl   $0, 4(%eax)      #Set course_for_stu to NULL

  movl   8(%ebp), %edx    #Get student pointer
  movl   %edx, 8(%eax)    #Set student pointer

  movl   12(%ebp), %ecx   #Get course pointer
  movl   %ecx, 12(%eax)   #Set course pointer

#Tear down stack frame
.exit_new_enroll:
  addl  $8, %esp
  popl  %ebp
  ret
