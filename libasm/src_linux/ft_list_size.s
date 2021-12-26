		global ft_list_size


		section .text
		; RDI contains pointer to start of linked list
ft_list_size:

	mov rax, 0
	; while (rdi) != NULL; rdi = rdi->next
	; because 'next' pointer is located 8 bytes into the struct
while:
	cmp rdi, 0
	je return

	mov rdi, [rdi + 8]
	inc rax

	jmp while
return:
	RET
