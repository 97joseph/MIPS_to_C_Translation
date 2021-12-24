# Author:	Eric Walkingshaw
# Date:		Feb 11, 2013
# Description:	Read in a string and print it in reverse

.data

	# string constants
intro:	.ascii  "Enter a string and I'll say it in reverse!\n\n"
	.asciiz "String: "

	# save space for 255 character input, plus the null character
text:	.space	256

.text

# Pseudocode:
#
#   print(intro)
#   text = readString()
#
#   // find the end of the string
#   for (i = 0; text[i] != NUL; i++) { }
#
#   // now print it backward
#   while (i > 0) {
#     printChar(text[--i])
#   }
#
# Registers:
#   i => $t0, tmp => $t1

	
	li	$v0, 4		# print the intro
	la	$a0, intro
	syscall
	
	li	$v0, 8		# text = readString()
	la	$a0, text
	li 	$a1, 256	# (size of input buffer)
	syscall
	
	li 	$t0, 0		# i = 0
find:   lb	$t1, text($t0)	# tmp = text[i]
	beq 	$t1, 0, print   # while(tmp != NUL)
	addi    $t0, $t0, 1     # i++
	j 	find		# (end loop)

print:  ble	$t0, 0, end	# while (i > 0)
	addi 	$t0, $t0, -1    # --i
	li 	$v0, 11		# printChar(
	lb	$a0, text($t0) 	#   text[i]
	syscall			# )
	j 	print		# (end loop)

end:	li   $v0, 10		# exit cleanly
 	syscall
