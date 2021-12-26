		global ft_list_remove_if

		extern free

		section .text
delete_element:
	cmp rcx, QWORD 0 ; check if free_fct exists
	je skip_free_data

		; free_fct(tmp->data)
	push rdi ; begin_list

	mov rdi, [rax] ; rdi = rax->data
	push rax ; push tmp for safety
	push rdi
	push rsi
	push rbx
	push rcx

	call rcx ; free_fct(rdi)

	pop rcx
	pop rbx
	pop rsi
	pop rdi
	pop rax ; tmp
	pop rdi ; begin_list

skip_free_data:
	cmp rbx, QWORD 0 ; previous_entry == NULL (means we are deleting *begin_list)
	jne delete_entry
delete_start:

	mov r8, QWORD [rax + 8]
	mov QWORD [rdi], r8 ; *begin_list = (*begin_list)->next

	push rdi
	mov rdi, rax ; rdi = tmp

	push rbx
	push rdx
	push rcx
	push rsi
	push rax

	call free wrt ..plt ; free(tmp)

	pop rax
	pop rsi
	pop rcx
	pop rdx
	pop rbx

	pop rdi ; begin_list
	mov rax, [rdi] ; tmp = *begin_list

	RET
delete_entry:
	mov r8, QWORD [rax + 8]
	mov [rbx + 8], r8 ; prev->next = tmp->next

	push rdi ; begin_list
	mov rdi, rax ; rdi = tmp

	push rbx
	push rdx
	push rcx
	push rsi

	call free wrt ..plt ; free(tmp)

	pop rsi
	pop rcx
	pop rdx
	pop rbx

	mov rax, [rbx + 8] ; tmp = prev->next
	pop rdi ; begin_list
	RET

		; void ft_list_remove_if_c
		; (t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void*))
		; (RDI, RSI, RDX, RCX)
ft_list_remove_if:
	push rbx

	cmp rdi, 0 ; begin_list == NULL
	je return
	cmp rdx, 0 ; cmp() == null
	je return
	mov rax, QWORD [rdi] ; rax = *begin_list
	mov rbx, QWORD 0 ; rbx = NULL (previous pointer)

for_each_element:
	cmp rax, QWORD 0 ; end of list condition
	je return

	push rdi ; push **begin_list, since it's not used yet
	push rcx ; same for free_fct()

	mov rdi, [rax] ; arg1 = tmp->data
	push rax

	push rdx
	push rsi
	push rbx

	call rdx ; cmp(tmp->data, data_ref);

	pop rbx ; prev
	pop rsi ; data_ref
	pop rdx ; cmp()

	cmp rax, 0
	jne no_delete
deleting:
		; Delete the element from the list
	pop rax ; tmp ptr
	pop rcx ; free_fct
	pop rdi ; begin_list

	push rsi ; don't need data_ref so push it
	push rdx ; don't need cmp() so push it

	call delete_element

	pop rdx ; put cmp() back into rdx
	pop rsi ; put data_ref back into rsi
	jmp end_loop

no_delete:
	pop rax ; tmp
	pop rcx ; free_fct
	pop rdi ; begin_list

	mov rbx, rax
	mov rax, [rax + 8] ; rax = rax->next
end_loop:
	jmp for_each_element

return:
	pop rbx
	RET
