# writes "Hello World" to the console
.global main

message:
	.asciz "Hello world\n"		# asciz puts a 0x00 byte at the end, to end the string

	.text
main:							# this is called by the C library's startup code
	push %rbx					# saves the value in the RBX register on the stack

	lea message(%rip), %rdi		# put message in the rdi register
	xor %eax, %eax				# clear the EAX register
	call printf					# call the C printf(message) function

	pop %rbx					# restore the value to the RBX register
	ret							# return to C library code
