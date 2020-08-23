#Rahul Mitra
#caesar cipher code in Assembly
	.file	"cipher.s"

	.globl	cipher
	 .type cipher, @function

cipher:
        #function overhead
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	
	
	movl $26, 24(%esp) #to handle wraparound when shift size is > 26
	movl $122, 20(%esp) #to handle when shifted distance is > 122
	movl $97, %ecx # to handle when shifted distance is < 97 
	
	
	movl 8(%ebp), %ebx #character in %ebx
	movl 12(%ebp), %esi #encrypt or decrypt in  %esi
	movl 16(%ebp), %edi #magnitude of shift in %edi
	
	cmpl $1, %esi
	je   .ENCRYPT #go to encrypt if it is equal to one
	jne  .DECRYPT #go to decrypt if it is not equal to one
	
.ENCRYPT: 
        movl  %edi, %edx
        movl  %edx, %eax
        sarl  $31, %edx
        idivl 24(%esp)
        #now, the remainder is in %edx
        addl  %ebx, %edx #%edx is now stores the new character without handling wrap around
        cmpl $122, %edx # if the value in %edx is greater than 122, need to account for wrap around
        jg   .WRAPAROUND_GREATER
        movl  %edx, %eax
        jmp   .DONE
        
.WRAPAROUND_GREATER:   #accounting for wrap around     
        movl  %edx, %eax
        sarl  $31, %edx
        idivl 20(%esp)
        #%edx should now be wraparoundgreater
	addl  $96, %edx
	movl  %edx, %eax
	jmp   .DONE
	
.DECRYPT:
        movl  %edi, %edx
        movl  %edx, %eax
        sarl  $31, %edx
        idivl 24(%esp)
        subl  %edx,%ebx #%ebx is now stores the new character without handling wrap around
        cmpl  $97, %ebx #if the value in %ebx is less than 97 need to account for wrapping around
        jl    .WRAPAROUND_LESS
        movl  %ebx, %eax
        jmp   .DONE
     
.WRAPAROUND_LESS: #accounting for wrapping around
        movl  %ecx, %edx
        movl  %edx, %eax
        sarl  $31, %edx
        idivl %ebx
        movl  $123, %ecx
        subl  %edx, %ecx
        movl  %ecx, %eax
        jmp   .DONE
        
.DONE: 	leave 
	ret
