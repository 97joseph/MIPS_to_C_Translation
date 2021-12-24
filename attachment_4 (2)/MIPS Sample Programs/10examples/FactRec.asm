# Author:	Eric Walkingshaw
# Date:		Mar 4, 2013
# Description:	Computes n! using a recursive function.

.data

prompt:	.asciiz	"Enter an integer in the range [0..12]: "

.text

# Pseudocode:
#   void main() {
#     print(prompt)
#     n = readInt()
#     m = fact(n)
#     printInt(m)
#   }
main:	addiu $sp, $sp, -16 	# push stack frame

	li    $v0, 4		# print(prompt)
	la    $a0, prompt
	syscall
	
	li    $v0, 5		# n = readInt()
	syscall
	
	move  $a0, $v0		# m = fact(n)
	jal   fact
	
	move  $a0, $v0		# printInt(m)
	li    $v0, 1
	syscall
	
	addiu $sp, $sp, 16 	# pop stack frame

	li    $v0, 10		# system exit
	syscall

# Pseudocode:
#   int fact(int n) {
#     if (n < 2) return 1
#     m = fact(n-1)
#     m = m * n
#     return m
#   }
# Registers:
#   n => $a0, m => $v0
fact:	addiu $sp, $sp, -24 	# procedure prologue
	sw    $ra, 16($sp)
	
	li    $v0, 1		# m = 1
	blt   $a0, 2, end	# if (n < 2) goto end
	
	sw    $a0, 20($sp)	# (startup) save n
	subi  $a0, $a0, 1	# tmp = n-1
	jal   fact		# fact(tmp)
	lw    $a0, 20($sp)	# (cleanup) restore n
	
	mul   $v0, $v0, $a0	# m = m*n
	
end:	lw    $ra, 16($sp)	# procedure epilogue
	addiu $sp, $sp, 24
	jr    $ra		# return
	
