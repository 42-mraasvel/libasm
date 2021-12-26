			global _ft_write

			extern ___error ; errno

			; ssize_t	ft_write(int fd, const void *buf, size_t nbyte);
			section .text
_ft_write:
	mov rax, 0x2000004
	syscall
	jc error
	RET

error:
	push rax
	call ___error
	pop rcx
	mov [rax], rcx
	mov rax, -1
	RET
