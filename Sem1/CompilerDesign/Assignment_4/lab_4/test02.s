.data

.text
main:
main_0:
  addi $s0, $zero, 1
  addiu $s1, $s0, 2
  move $a0, $s1
  jal print_int
  jal print_nl
  addi $s2, $zero, 1
  subu $s3, $s2, 2
  move $a0, $s3
  jal print_int
  addi $a0, $zero, 0
  addi $v0, $zero, 17
  syscall

