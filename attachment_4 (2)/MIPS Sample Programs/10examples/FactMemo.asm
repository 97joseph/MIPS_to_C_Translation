# Author:	Eric Walkingshaw
# Date:		Mar 4, 2013
# Description:	Computes n! using a recursive function and memoization table.

.data

prompt:	.asciiz	"Enter an integer in the range [0..12]: "

# memoization table -- enough space for 16 results (more than we need)
memo:	.word	  1	# fact(0) = 1
	.word	  1	# fact(1) = 1
	.space	 56

.text

# Pseudocode:
#   void main() {
#     print(prompt)
#     n = readInt()
#     m = factM(n)
#     printInt(m)
#   }
main:	addiu $sp, $sp, -16 	# push stack frame

	li    $v0, 4		# print(prompt)
	la    $a0, prompt
	syscall
	
	li    $v0, 5		# n = readInt()
	syscall
	
	move  $a0, $v0		# m = factM(n)
	jal   factM
	
	move  $a0, $v0		# printInt(m)
	li    $v0, 1
	syscall
	
	addiu $sp, $sp, 16 	# pop stack frame

	li    $v0, 10		# system exit
	syscall

# Pseudocode:
#   int factM(int n) {
#     m = memo[n]
#     if (m == 0) {
#       m = factM(n-1)
#       m = m * n
#       memo[n] = m
#     }
#     return m
#   }
# Registers:
#   n => $a0, m => $v0, i => $t0
factM:	addiu $sp, $sp, -32 	# procedure prologue
	sw    $ra, 16($sp)
	
	mul   $t0, $a0, 4	# i = n * 4
	lw    $v0, memo($t0)	# m = memo[i]
	bnez  $v0, end		# if (m == 0) {
	
	sw    $a0, 24($sp)	#   (startup) save n
	sw    $t0, 28($sp)	#   (startup) save i
	subi  $a0, $a0, 1	#   tmp = n-1
	jal   factM		#   factM(tmp)
	lw    $a0, 24($sp)	#   (cleanup) restore n
	lw    $t0, 28($sp)	#   (cleanup) restore i
	
	mul   $v0, $v0, $a0	#   m = m*n
	
	sw    $v0, memo($t0)    #   memo[i] = m
				# } (end if)

end:	lw    $ra, 16($sp)	# procedure epilogue
	addiu $sp, $sp, 32
	jr    $ra		# return
	
