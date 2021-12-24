# Author:	Eric Walkingshaw
# Date:		Feb 15, 2013
# Description:	Print a riddle and give the answer when the user gives up.

.data

quest:	.asciiz	"Q: Why do programmers get Halloween and Christmas mixed up?\n"
answer:	.asciiz "\n\nA: Because Oct 31 == Dec 25!"
prompt: .asciiz "\nGive up? [y/n]: "

.text

# Pseudocode:
# int main() {
#   printQuestion()
#   waitForGiveUp()
#   printAnswer()
# }
main:
	# NOTE: This does not illustrate proper calling conventions!
	# It just shows how to use jal and jr to call and return
	# from procedures.  Specifically, it will break when any of
	# the called procedures are not leaves (i.e. they also call
	# procedures.
	
	jal printQuestion
	jal waitForGiveUp
	jal printAnswer
	
	li $v0, 10	# exit
	syscall

# Pseudocode:
# void printQuestion() {
#   print(quest)
#   return
# }
printQuestion:
	li $v0, 4	# print(quest)
	la $a0, quest
	syscall
	
	jr $ra		# return

# Pseudocode:
# void printAnswer() {
#   print(answer)
#   return
# }
printAnswer:
	li $v0, 4	# print(answer)
	la $a0, answer
	syscall
	
	jr $ra		# return

# Pseudocode:
# void waitForGiveUp() {
#   do {
#     print(prompt)
#     c = readChar()
#   } while(c != 'y')
#   return
# }
# Registers: c => $v0
waitForGiveUp:

loop:	li  $v0, 4		# print(prompt)
	la  $a0, prompt
	syscall
	
	li  $v0, 12		# c = readChar()
	syscall
	
	bne $v0, 'y', loop 	# while (c != 'y')

	jr  $ra			# return
