		; void ft_list_push_front(t_list **begin_list, void *data);
		global _ft_list_push_front

		extern _malloc

		section .text
		; Data = Second param (rsi)
ft_create_new_elem:
		; Bytes to allocate
	mov rdi, 16
	push rsi
	call _malloc
	pop rsi
		; Check for malloc error
	cmp rax, QWORD 0
	je end_new_elem
		; Set data in structure
		; (first 8 bytes = data pointer, second 8 bytes = next = NULL)
	mov QWORD [rax + 8], QWORD 0
	mov QWORD [rax], rsi
end_new_elem:
	RET


		; RDI contains t_list **begin_list
		; RSI contains void *data
_ft_list_push_front:

		; Null pointer checks
	cmp rdi, QWORD 0
	je return
	cmp QWORD [rdi], QWORD 0
	je new_list

		; Create new element
	push rdi
	call ft_create_new_elem
	pop rdi

		; Malloc error check
	cmp rax, QWORD 0
	je return

		; Put at front of list
	mov rdx, QWORD [rdi]
	mov QWORD [rax + 8], rdx
	mov QWORD [rdi], rax

	jmp return
new_list:
	push rdi
	call ft_create_new_elem
	pop rdi
	mov QWORD [rdi], rax
return:
	RET
