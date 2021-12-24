# Author:	Eric Walkingshaw
# Date:		Feb 13, 2013
# Description:	Print out the properties of a one digit number.
#               Example of a switch block

# Pseudocode: 
#   
#   print(prompt)
#   n = readInt()
#
#   switch (n) {
#     case 0:
#       print("n is zero\n")
#       break
#     case 4:
#       print("n is even\n")
#     case 1:
#     case 9:
#       print("n is square\n")
#       break  
#     case 2:
#       print("n is even\n")
#     case 3:
#     case 5:
#     case 7:
#       print("n is prime\n")
#       break
#     case 6:
#     case 8:
#       print("n is even\n")
#       break
#     default:
#       print("out of range\n")
#   }
#
# Registers: n => $t0

.data

# string constants
prompt: .asciiz "Enter a one digit number: "
zero:   .asciiz "n is zero\n"
even:   .asciiz "n is even\n"
square: .asciiz "n is square\n"
prime:  .asciiz "n is prime\n"
bad:    .asciiz "out of range\n"

# switch block jump table
switch: .word   case0, case1, case2, case3, case4, case5, case6, case7, case8, case9

.text

        li      $v0, 4            # print(prompt)
        la      $a0, prompt
        syscall
        
        li      $v0, 5            # n = readInt()
        syscall
        move    $t0, $v0
        
        li      $v0, 4            # (set up future calls to print)
        
                                  # switch(n)
        blt     $t0, 0, default   #   (if n < 0, goto default)
        bgt     $t0, 9, default   #   (if n > 9, goto default)
        mul     $t1, $t0, 4       #   (tmp = n*4)
        lw      $t1, switch($t1)  #   (tmp = switch[tmp])
        jr      $t1               #   (jump to address in tmp)
        
case0:  la      $a0, zero         # print(zero)
        syscall
        j       end               # break
        
case4:  la      $a0, even         # print(even)
        syscall

case1:
case9:  la      $a0, square       # print(square)
        syscall
        j       end               # break

case2:  la      $a0, even         # print(even)
        syscall

case3:
case5:
case7:  la      $a0, prime        # print(prime)
        syscall
        j       end               # break
        
case6:
case8:  la      $a0, even         # print(even)
        syscall
        j       end               # break
        
default:
        la      $a0, bad          # print(bad)
        syscall

end:    li      $v0, 10           # exit
        syscall
        