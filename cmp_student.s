# File:        cmp_student.s
# Author:      cer6526
# Description: Compares the two students s1 and s2
.text
.globl cmp_student

cmp_student:
#Setup stack frame
  pushl  %ebp
  movl   %esp, %ebp
  pushl  %edi
  pushl  %esi
  subl   $16, %esp

  movl    8(%ebp), %esi
  movl    8(%esi), %eax     #s1
  movl   12(%ebp), %edi
  movl    8(%edi), %ecx     #s2

#strcmp(s1->name, s2->name)
  movl   %eax,  (%esp)      #Set s1 as arugment 1
  movl   %ecx, 4(%esp)      #Set s2 as arugment 2
  calll  strcmp             #Call strcmp
  movl   $0, %ecx           #Set return value to 0
  cmpl   $0, %eax           #Set comparison flags
  jne    .exit_cmp_student  #If the result was non-0 goto exit

#s1->id == s2->id
  movl   12(%edi), %edx
  movl   12(%esi), %esi
  movl   $0, %ecx           #Set return value to 0
  cmpl   %edx, %esi         #Set comparison flags
  je     .exit_cmp_student  #Goto out if equal

#s1->id < s2->id
  movl   $-1, %ecx          #Set return value to -1
  cmpl   %edx, %esi         #Set comparison flags
  jl     .exit_cmp_student  #Goto out if less than

#s1->id > s2->id
  movl   $1, %ecx           #Set return value to 1
  cmpl   %edx, %esi         #Set comparison flags
  jg     .exit_cmp_student  #Goto out if greater than

#Tear down stack frame
.exit_cmp_student:
  movl   %ecx, %eax         #Set result
  addl   $16, %esp
  popl   %esi
  popl   %edi
  popl   %ebp
  ret
