# Author:	Eric Walkingshaw
# Date:		Feb 7, 2013
# Description:	Print out a joke, character by character

.data

	# the joke to print
joke:	.ascii	"Q: Why do programmers get Halloween and Christmas mixed up?\n"
	.asciiz "A: Because Oct 31 == Dec 25!"

.text

# Pseudocode:
# 
#   c = joke[0]
#   for (i = 0; c != NULL; c = joke[++i]) {
#     printChar(c);
#   }
# 
# Registers:
#   i: $t0, c: $a0 (since we're just printing each one out)

# Translation to lower-level pseudocode:
#
#   c = joke[0]
#   i = 0
#   while (c != NULL) {
#     printChar(c)
#     i = i+1
#     c = joke[i]
#   }

	lb   $a0, joke($zero)	# c = joke[0]
	li   $t0, 0		# i = 0
	li   $v0, 11		# (loop invariant) for print char syscall

loop:	beq  $a0, 0, end	# while (c != NULL)
	syscall			# printChar(c)
	addi $t0, $t0, 1	# i = i+1
	lb   $a0, joke($t0)	# c = joke[i]
	j    loop		# (end loop)

end:	li   $v0, 10		# exit cleanly
 	syscall