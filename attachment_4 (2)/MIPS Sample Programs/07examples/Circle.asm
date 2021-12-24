# Author:	Eric Walkingshaw
# Date:		Jan 28, 2013
# Description:	Given a radius, approximates the area of a circle.

.data

	# string constants
prompt:	.asciiz "\nEnter a radius or 0 to quit: "
result:	.asciiz "Approximate area = "
bye:    .asciiz "\nBye."

.text

# Pseudocode:
#   while(true) {
#     print(prompt)
#     r = readInt()
#     if (r == 0) break
#     area = 3 * r * r
#     print(result)
#     print(area)
#   }
#   print(bye)
#
# Register mappings:
#   t0: r
#   t1: area

	# begin while loop
loop:	li   $v0, 4		# print(prompt)
	la   $a0, prompt
	syscall
	
	li   $v0, 5		# r = readInt()
	syscall
	move $t0, $v0
	
	beqz $t0, end		# if (r==0) break
	
	li $t1, 3		# area = 3 * r * r
	mul $t1, $t1, $t0
	mul $t1, $t1, $t0
	
	li   $v0, 4		# print(result)
	la   $a0, result
	syscall
	
	li   $v0, 1		# print(area)
	move $a0, $t1
	syscall

	j loop
	# end while loop

end: 	li   $v0, 4		# print(bye)
	la   $a0, bye
	syscall
	
	li   $v0, 10		# exit
	syscall
