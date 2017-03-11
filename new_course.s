# File:        new_course.s
# Author:      cer6526
# Description: Allocates a new Course node; fills in the fields of the new node
#              by copying the arguments into the appropriate fields; clears all
#              other fields to 0; returns the pointer to the new node. If the 
#              allocation fails, returns 0. 
.text
.globl new_course

new_course:
#Setup stack frame
  pushl  %ebp
  movl   %esp, %ebp
  pushl  %ebx
  pushl  %eax

#malloc(sizeof(Course))
  movl   $16, (%esp)      #sizeof(Course)
  calll  malloc           #Call malloc
  cmpl   $0, %eax         #Set comparison flags
  je     .exit_new_course #If failed malloc, goto out

#Fill structure
  movl   $0,   (%eax)     #Set next to NULL
  movl   $0,  4(%eax)     #Set students to NULL

  movw   16(%ebp), %dx    #Get course id
  movw   %dx, 8(%eax)     #Set course id

  movb   8(%ebp), %bl     #Get first character
  movb   %bl, 10(%eax)    #Set first character

  movb   12(%ebp), %bl    #Get second character
  movb   %bl, 11(%eax)    #Get second character

  movb   20(%ebp), %bl    #Get max enrollment
  movb   %bl, 12(%eax)    #Set max enrollment

  movb   $0,  13(%eax)    #Set current enrollment to 0

#Tear down stack frame
.exit_new_course:
  addl   $4, %esp
  popl   %ebx
  popl   %ebp
  ret
