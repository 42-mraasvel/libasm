		global _ft_strlen

		section .text
_ft_strlen:
	push rbx
	; rdi register contains our string pointer on linux
	; Set our incrementor to 0
	mov rcx, 0
while:
	; Compare for a null terminator, jump to return if equal
	cmp BYTE [rdi + rcx], 0
	je return
	inc rcx
	jmp while

return:
	mov rax, rcx
	pop rbx
	ret
