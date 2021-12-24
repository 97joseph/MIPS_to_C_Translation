# Author: Eric Walkingshaw
# Date:   Mar 13, 2013
#
# Description:
# An illustration of absolute vs. relative addressing.
# Assemble this file and compare in MARS.  You should observe that
# the two jump instructions assemble to the exact same machine code
# instructions, while the two branch instructions assemble to
# different machine code instructions.  This is because jump addresses
# are absolute (within a 256Mb region) and branch addresses are
# relative from the location of the instruction.

.text
	j   jlabel
	nop
jlabel: nop
        nop
        j   jlabel
        
        nop
        
        beq $0, $0, blabel
	nop
blabel: nop
        nop
        beq $0, $0, blabel
        