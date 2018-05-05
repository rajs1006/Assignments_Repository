.data
.str: .asciiz "foo"

.text
main:
main_0:
  la $s0, .str
  addi $s1, $s0, 0
  move $a0, $s1
  jal my_strlen
  move $s2, $v0
  move $a0, $s2
  jal print_int
  addi $a0, $zero, 0
  addi $v0, $zero, 17
  syscall

my_strlen:
my_strlen_0:
  move $s0, $a0
  addi $s1, $zero, 0
  j my_strlen_1
my_strlen_1:
  lb $s3, 0($s0)
  addi $s4, $zero, 0
  bne $s3, $s4, my_strlen_2
  j my_strlen_3
my_strlen_2:
  addi $s5, $s0, 1
  addiu $s6, $s1, 1
  move $s0, $s5
  move $s1, $s6
  j my_strlen_1
my_strlen_3:
  move $v0, $s1
  jr $ra

