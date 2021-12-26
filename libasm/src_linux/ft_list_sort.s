		global ft_list_sort

		extern ft_list_size

; void ft_list_sort(t_list **begin_list, int (*cmp)())

		; r15 = begin_list
		; r14 = cmp
		; r13 = size(list) - 1
		; rcx = itr_outer
		; rbx = itr_inner
		section .text
ft_list_sort:
		; prologue
		; saving callee registers
	push rbx
	push rbp
	push rdi
	push rsi
	push rsp
	push r12
	push r13
	push r14
	push r15

	cmp rdi, QWORD 0
	je end_sort
	cmp QWORD [rdi], QWORD 0
	je end_sort

	mov r15, rdi
	mov r14, rsi
	mov rdi, [r15]
	call ft_list_size
	mov r13, rax
	dec r13

		; r12 = list_iterator
	mov rcx, 0
outer_loop:
	cmp rcx, r13
	je end_outer

	mov r12, r15
	mov rbx, 0
	inner_loop:
		mov rax, r13
		sub rax, rcx
		cmp rbx, rax
		je end_inner

	preparing_cmp_call:
		mov rdi, [r12]
		mov rsi, [rdi + 8]

		push rdi
		push rsi

		mov rdi, [rdi]
		mov rsi, [rsi]
	calling_cmp:

		push rcx
		call r14 ; cmp(rdi->data, rsi->data)
		pop rcx

		pop rsi ; next entry
		pop rdi ; current entry
	after_cmp:
		cmp eax, 0
		jle dont_swap
	swap_entries:
			; 1->next = 2->next
			; 2->next = 1
			; iterator = 2 (pointer to previous next)
		mov rax, [rsi + 8]
		mov [rdi + 8], rax
		mov [rsi + 8], rdi
		mov [r12], rsi

	dont_swap:
			; r12 = &(*r12)->next
		mov r12, [r12]
		add r12, 8
		inc rbx
		jmp inner_loop

	end_inner:
		inc rcx
		jmp outer_loop
end_outer:



end_sort:
		; epilogue
		; retrieve original values of these registers
	pop r15
	pop r14
	pop r13
	pop r12
	pop rsp
	pop rsi
	pop rdi
	pop rbp
	pop rbx
	RET
