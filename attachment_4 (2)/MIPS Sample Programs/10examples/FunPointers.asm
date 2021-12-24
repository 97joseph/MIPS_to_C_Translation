# Author:	Eric Walkingshaw
# Date:		Mar 4, 2013
# Description:	A small example that shows how to pass and use function pointers.

# Passes various combinations of input and function pointers to
# the test procedure.
# Pseudocode:
#   void main() {
#     test(add2, 3)
#     test(add3, 10)
#     test(negate, 7)
#   }
main:	addiu $sp, $sp, -16	# procedure prologue

	la    $a0, add2		# test(add2, 3)
	li    $a1, 3
	jal   test
	
	la    $a0, add3		# test(add3, 10)
	li    $a1, 10
	jal   test
	
	la    $a0, negate	# test(negate, 7)
	li    $a1, 7
	jal   test

	addiu $sp, $sp, 16	# procedure epilogue
	li    $v0, 10		# exit
	syscall

# Applies a function foo (from int to int), to an argument n
# and prints the result.
# Pseudocode:
#   void test(foo, int n) {
#     tmp = foo(n)
#     printInt(tmp)
#     printChar('\n')
#   }
test:	addiu $sp, $sp, -24	# procedure prologue
	sw    $ra, 16($sp)
	
	move  $t0, $a0		# t0 contains pointer to foo
	move  $a0, $a1 		# a1 contains n, which foo be passed to foo
	jalr  $t0 		# call foo(n)
	
	move  $a0, $v0		# put result of foo(n) in a0 for printInt
	li    $v0, 1
	syscall			# call printInt
	
	li    $a0, '\n'		# printChar('\n')
	li    $v0, 11
	syscall
	
	lw    $ra, 16($sp)	# procedure epilogue
	addiu $sp, $sp, 24
	jr    $ra		# return

# Adds two to its argument. (Simple leaf) 
# Pseudocode:
#   add2(int n) {
#     return n+2
#   }
add2:	addi  $v0, $a0, 2
        jr    $ra

# Adds three to its argument. (Simple leaf) 
# Pseudocode:
#   add3(int n) {
#     return n+3
#   }
add3:	addi  $v0, $a0, 3
        jr    $ra

# Negates its argument. (Simple leaf) 
# Pseudocode:
#   neg(int n) {
#     return 0-n
#   }
negate:	sub   $v0, $zero, $a0
        jr    $ra
