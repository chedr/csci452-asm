# File:        find_student.s
# Author:      cer6526
# Description: Locates the student record which has the specified sid and
#              returns a pointer to it; if the sid is not found, returns 0. 
.text
.globl find_student

find_student:
#Setup stack frame
#Nothing to do

  movl  $students, %ecx     #address of students
  movl  4(%esp), %edx       #sid

  movl  $0, %eax            #Set default return code (NULL)

#The loop
.loop_find_student:
  movl  (%ecx), %ecx        #Move current address into register
  cmpl  $0, %ecx            #Set comparison flags; current == NULL
  je    .exit_find_student  #Exit if true

  cmpl  %edx, 12(%ecx)      #Set comparison flags; current->sid == sid
  jne   .loop_find_student  #Loop if false
  movl  %ecx, %eax          #Found record, set return

#Tear down stack frame
.exit_find_student:
  ret
