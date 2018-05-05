print_int:
  addi $v0, $zero, 1
  syscall
  jr $ra

print_nl:
  addi $v0, $zero, 4
  la $a0, newline_str
  syscall
  jr $ra

.data
newline_str: .asciiz "\n"
