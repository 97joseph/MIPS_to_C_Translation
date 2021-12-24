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
#   for (addr = joke; *addr != NULL; addr++) {
#     printChar(*addr)
#   }
# 
# Registers:
#   addr = $t0, c = $a0 (since we're just printing each one out)

# Translation to lower-level pseudocode:
#
#   addr = joke
#   c = *addr
#   while (c != NULL) {
#     printChar(c)
#     addr = addr + 1
#     c = *addr
#   }

	la   $t0, joke		# addr = joke
	li   $v0, 11		# (loop invariant) for print char syscall

loop:	lb   $a0, 0($t0)	# c = *addr
	beq  $a0, 0, end	# while (c != NULL)
	syscall			# printChar(c)
	addi $t0, $t0, 1	# addr = addr+1
	j    loop		# (end loop)

end:	li   $v0, 10		# exit cleanly
 	syscall