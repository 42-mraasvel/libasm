		global _ft_strcpy

		section .text
_ft_strcpy:
	push rbx
		; Initialize iterator and return value
	mov rbx, 0
	mov rax, rdi

		; Check if the address is the same (dst == src)
	cmp rdi, rsi
	je return

		; while (src[i] != '\0')
while:
	cmp BYTE [rsi + rbx], 0
	je terminate
		; We cannot do 'mov mem, mem', so we use a register in between (8 bit register for bytes)
		; this is apparently also faster anyway
	mov cl, BYTE [rsi + rbx]
	mov BYTE [rdi + rbx], cl

	inc rbx
	jmp while

terminate:
	mov BYTE [rdi + rbx], 0
return:
	pop rbx
	RET
