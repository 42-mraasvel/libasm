		global _ft_strcmp

		section .text
_ft_strcmp:
	push rbx
		; Set iterator
	mov rcx, 0
	mov rax, 0
while:
		; rdi contains s1, rsi contains s2
	mov al, BYTE [rdi + rcx]
	cmp al, BYTE [rsi + rcx]

	jb negative ; jump if below = unsigned jmp
	ja positive ; jump if above = unsigned jmp

		; Both are null terminators, and thus equal strings
	cmp BYTE [rdi + rcx], 0
	je positive

	inc rcx
	jmp while

		; Setting return values
negative:
	not rax ; sign-extend rax by setting all bits to 1 using the NOT instruction
	jmp return
positive:
	mov rax, 0 ; zero-extend rax
return:
	mov al, BYTE [rdi + rcx]
	sub al, BYTE [rsi + rcx]
	pop rbx
	ret
