		global _ft_read
		extern ___error

		section .text
_ft_read:
	mov rax, 0x2000003 ; read syscall for mac
	syscall
		; Check if an error was returned
	jc error
	ret

error:
		; Call errno, returns address to errno and stores in rax
	push rax
	call ___error
	pop rcx
	mov [rax], rcx

		; Set return value
	mov rax, -1
	ret
