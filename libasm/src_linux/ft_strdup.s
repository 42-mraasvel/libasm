		global ft_strdup

			; Kind of like function prototypes
		extern ft_strlen
		extern ft_strcpy
		extern malloc

		section .text
ft_strdup:
	push rbx
		; Put src string into rsi
	mov rsi, rdi

		; Get malloc size strlen + 1
		; Set strlen return value to malloc parameter (rdi)
	call ft_strlen
	inc rax
	mov rdi, rax

		; Push rsi to stack, because malloc sets it to NULL for some reason
	push rsi
		; Call malloc and put pointer to memory into rdi
	call malloc wrt ..plt
	mov rdi, rax
		; Get source pointer back from stack
	pop rsi

		; Check for null pointer return
	cmp rdi, QWORD 0
	je malloc_error

		; Return will be pointer to dst put into rax register
	call ft_strcpy
	pop rbx
	ret

malloc_error:
	mov rax, 0
	pop rbx
	ret
