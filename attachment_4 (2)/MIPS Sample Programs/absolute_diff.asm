
# Description:	Find the absolute difference

.data

# string to print before the result
resStr: .asciiz "Result: "

# numbers to add
nums: 	.word 	11, 50	# numbers to add
result: .word	0 		# a place to store the result

.text

	# print the initial string
	li 	$v0, 4		# set up print string syscall
	la 	$a0, resStr
	syscall

	# load three numbers into registers
	la	$t0, nums
	lw 	$t1, 0($t0)	# lw $t1, nums
	lw	$t2, 4($t0)	# lw $t2, nums + 4
	
	#slt $t5, $t1, $t2
	#beq $zero, $t5, B
	
	bgt	$t1,$t2, adc
	
	sub 	$a0, $t2, $t1
	j  over
	adc: sub	$a0, $t1, $t2	# sub the two numbers
	 
	over:
	# save a0 to result location in memory
	sw 	$a0, result

	# now print the result
	li 	$v0, 1		# set up the print int syscall
	syscall
	
	# exit
	li 	$v0, 10		# set up exit syscall
	syscall
