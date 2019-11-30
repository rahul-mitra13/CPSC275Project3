#Rahul Mitra
#CPSC 275, Project 2
	.file	"cipher.s"
.LC0:
	.string	"This is the remainder %d\n"

	.globl	cipher
	 .type cipher, @function

cipher:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	
	
	movl $26, 24(%esp)
	movl $122, 20(%esp)
	
	
	movl 8(%ebp), %ebx #character in %ebx
	movl 12(%ebp), %esi #encrypt or decrypt in  %esi
	movl 16(%ebp), %edi #magnitude of shift in %edi
	
	cmpl $1, %esi
	je   .ENCRYPT #go to encrypt if it is equal to one
	#jne  .DECRYPT #go to decrypt if it is not equal to one
	
.ENCRYPT: 
        movl  %edi, %edx
        movl  %edx, %eax
        sarl  $31, %edx
        idivl 24(%esp)
        #now, the remainder is in %edx
        addl  %ebx, %edx #%edx is now initialshiftforward
        cmpl $122, %edx
        jg   .WRAPAROUND_GREATER
        movl  %edx, %eax
        jmp   .DONE
        
.WRAPAROUND_GREATER:        
        movl  %edx, %eax
        sarl  $31, %edx
        idivl 20(%esp)
        #%edx should now be wraparoundgreater
	addl  $96, %edx
	movl  %edx, %eax
	
	
.DONE: 	leave 
	ret
