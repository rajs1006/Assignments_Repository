.data

.text
main:
main_0:
  addi $s0, $zero, 119
  andi $s1, $s0, 248
  move $a0, $s1
  jal print_int
  jal print_nl
  addi $s2, $zero, 119
  ori $s3, $s2, 248
  move $a0, $s3
  jal print_int
  jal print_nl
  addi $s4, $zero, 119
  xori $s5, $s4, 248
  move $a0, $s5
  jal print_int
  jal print_nl
  li $s6, 4278255360
  li $t0, 2004318071
  and $s7, $s6, $t0
  move $a0, $s7
  jal print_int
  jal print_nl
  li $t1, 4278255360
  li $t3, 2004318071
  or $t2, $t1, $t3
  move $a0, $t2
  jal print_int
  jal print_nl
  li $t4, 4278255360
  li $t6, 2004318071
  xor $t5, $t4, $t6
  move $a0, $t5
  jal print_int
  jal print_nl
  addi $a0, $zero, 0
  addi $v0, $zero, 17
  syscall

