# adds numbers 1 to 10 backwards and prints the sum to the console
# i.e: 10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1
# output: 10, 19, 27, 34, 40, 45, 49, 52, 54, 55
.global main

format:
	.asciz  "%5ld\n"        # format: %# is number of spaces, ld means long decimal, \n is new line

	.text
	
main:
	push    %rbx			# saves RBX register

	mov     $10, %ecx		# ecx will countdown from 10 to 0
	mov     $0, %rax		# set rax to 0 (sum)
	
printandadd:                # label handle
	add     %rcx, %rax		# add to rcx to rax (sum)
	                        # rcx and ecx are the same register, already moved 10 into rcx
  call printnumbers
	dec     %ecx			# count down
	jnz     printandadd	   	# if ecx is not zero (i.e. if not done counting jump to print)

	pop     %rbx			# restore rbx before returning
	ret


printnumbers:               # label handle
	push    %rax			# caller-save register
	push    %rcx			# caller-save register

	lea format(%rip), %rdi		# set 1st parameter (format)
	mov %rax, %rsi			# set 2nd parameter (current_number)
	xor %eax, %eax			# clear AL

	call    printf		  	# printf(format, current_number)

	pop     %rcx			# restore caller-save register
	pop     %rax			# restore caller-save register
    ret
