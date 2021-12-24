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
#   for (addr = text; *addr != NUL; addr++) { }
#
#   // now print it backward
#   while (--addr >= text) {
#     printChar(*addr)
#   }
#
# Registers:
#   addr => $t0, tmp => $t1, orig => $t2
	
        li      $v0, 4          # print(intro)
        la      $a0, intro
        syscall
        
        li      $v0, 8          # text = readString()
        la      $a0, text
        li      $a1, 256        # (size of input buffer)
        syscall
        
        la      $t0, text       # addr = text
        move    $t2, $t0        # orig = addr (backup of original address)
find:   lb      $t1, 0($t0)     # tmp = *addr
        beq     $t1, 0, print   # while(tmp != NUL)
        addi    $t0, $t0, 1     # addr++
        j       find            # (end loop)

print:  subi    $t0, $t0, 1     # --addr
        blt     $t0, $t2, end   # while (addr >= orig)
        li      $v0, 11         # printChar(
        lb      $a0, 0($t0)     #   *addr
        syscall                 # )
        j       print           # (end loop)

end:    li      $v0, 10         # exit cleanly
        syscall
