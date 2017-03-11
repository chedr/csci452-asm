# File:        cmp_course.s
# Author:      cer6526
# Description: Compares the two cids ABnum1 and CDnum2
.text
.globl cmp_course

cmp_course:
#Setup stack frame
  pushl  %ebp
  movl   %esp, %ebp
  pushl  %esi
  subl   $20, %esp

#Put character arguments into stack allocated arrays
  movb   8(%ebp), %al
  movb   %al, -6(%ebp)
  movb   12(%ebp), %al
  movb   %al, -5(%ebp)

  movb   20(%ebp), %al
  movb   %al, -8(%ebp)
  movb   24(%ebp), %al
  movb   %al, -7(%ebp)

#strncmp(AB, CD, 2)
  leal   -6(%ebp), %eax     #Get address of array 1
  movl   %eax, (%esp)       #Set address of array 1 as argument 1

  leal   -8(%ebp), %eax     #Get address of array 2
  movl   %eax, 4(%esp)      #Set address of array 2 as argument 2
  
  movl   $2, 8(%esp)        #Set last arugment to 2
  calll  strncmp            #Call strncmp
  movl   $0, %ecx           #Set return value to 0
  cmpl   $0, %eax           #Set comparison flags
  jne    .exit_cmp_course   #If the result was non-0 goto exit

#num1 == num2
  movl   28(%ebp), %edx
  movl   16(%ebp), %esi
  movl   $0, %ecx           #Set return value to 0
  cmpw   %dx, %si           #Set comparison flags
  je     .exit_cmp_course   #Goto out if equal (sign doesn't matter!)

#num1 < num2
  movl   $-1, %ecx          #Set return value to -1
  cmpw   %dx, %si           #Set comparison flags
  jb     .exit_cmp_course   #Goto out if less than (unsigned)

#num1 > num2
  movl   $1, %ecx           #Set return value to 1
  cmpw   %dx, %si           #Set comparison flags
  ja     .exit_cmp_course   #Goto out if greater than (unsigned)

#Tear down stack frame
.exit_cmp_course:
  movl  %ecx, %eax          #Set result
  addl  $20, %esp
  popl  %esi
  popl  %ebp
  ret
