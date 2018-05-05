.data

.text
main:
main_0:
  addi $s0, $zero, 42
  sll $s1, $s0, 3
  move $a0, $s1
  jal print_int
  jal print_nl
  addi $s2, $zero, 42
  srl $s3, $s2, 3
  move $a0, $s3
  jal print_int
  jal print_nl
  addi $s4, $zero, -42
  sra $s5, $s4, 3
  move $a0, $s5
  jal print_int
  jal print_nl
  addi $s6, $zero, 3
  addiu $s7, $s6, 1
  addi $t0, $zero, 42
  sllv $t1, $t0, $s7
  move $a0, $t1
  jal print_int
  jal print_nl
  addi $t2, $zero, 42
  srlv $t3, $t2, $s7
  move $a0, $t3
  jal print_int
  jal print_nl
  addi $t4, $zero, -42
  srav $t5, $t4, $s7
  move $a0, $t5
  jal print_int
  jal print_nl
  addi $a0, $zero, 0
  addi $v0, $zero, 17
  syscall

