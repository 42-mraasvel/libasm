		; Subroutine that returns 0 if base is invalid
		; Otherwise returns length of base (0 or 1 is invalid)
		global _ft_atoi_base

		section .text
		; Return 1 if space, else return 0
		; Checks value in rcx register
ft_isspace:
	mov rax, 1
		; Whitespace ascii checks
	cmp rcx, BYTE 9
	je end
	cmp rcx, BYTE 10
	je end
	cmp rcx, BYTE 11
	je end
	cmp rcx, BYTE 12
	je end
	cmp rcx, BYTE 13
	je end
	cmp rcx, BYTE 32
	je end
	mov rax, 0
end:
	RET


check_char:
		; check '+' and '-'
	cmp [rsi + rbx], BYTE '+'
	je invalid_char
	cmp [rsi + rbx], BYTE '-'
	je invalid_char

	mov rcx, 0
	mov cl, BYTE [rsi + rbx]
	call ft_isspace
	cmp rax, 1
	je invalid_char

		; Check if char appeared already in string
	mov rcx, 0
	mov cl, BYTE [rsi + rbx]
	lea rax, [rel ascii]
	cmp [rax + rcx], BYTE 0
	jne invalid_char
	inc BYTE [rax + rcx]
valid_char:
	mov rax, 0
	RET
invalid_char:
	mov rax, -1
	RET


check_base:
	mov rax, 0
	mov rbx, -1
		; Iterate through each character, check '+' '-' or duplicates
check_loop:
	inc rbx

	call check_char
	cmp rax, -1
	je invalid_base

	cmp [rsi + rbx], BYTE 0
	jne check_loop
valid_base:
	mov rax, rbx
	RET
invalid_base:
	mov rax, 0
	RET


		; Skips all spaces in string RDI, sets negative variable to 1 if '-' is encountered
find_number:
		; while (isspace(rdi) == 1)
		; 	rdi++
	dec rdi
	lea rax, [rel sign]
	mov [rax], BYTE 0
while_space:
	inc rdi
	mov rcx, 0
	mov cl, BYTE [rdi]
	call ft_isspace
	cmp rax, 1
	je while_space
check_sign:
	mov rcx, 0
	mov cl, BYTE [rdi]
	cmp cl, BYTE '+'
	je inc_sign
	cmp cl, BYTE '-'
	jne end_find_number
set_negative:
	lea rax, [rel sign]
	mov BYTE [rax], BYTE 1
inc_sign:
	inc rdi
end_find_number:
	RET


		; Returns base index, otherwise -1 (in RAX)
		; RCX contains char that is compared
ft_isbase:
	mov rax, 0
while_base:
		; Get value of char in base string
	mov rbx, 0
	mov bl, BYTE [rsi + rax]
		; Check for null terminator
	cmp bl, 0
	je not_in_base
		; Compare to char we're checking of the number string
	cmp bl, cl
	je in_base
	inc rax
	jmp while_base
in_base:
	RET
not_in_base:
	mov rax, -1
	RET

zero_ascii: ; apparently the .data variables are not zero'd on each call
	mov rcx, 256
	lea rax, [rel sign]
	mov [rax], BYTE 0
loop_ascii:
	sub rcx, 8 ; bzero per 8 bytes
	lea rax, [rel ascii]
	mov QWORD [rax + rcx], QWORD 0
	jnz loop_ascii
	RET



		; Radix value is stored in R9
_ft_atoi_base:
	push rbx

	call zero_ascii
	call check_base
	cmp rax, 2
	jl error

	mov r9, rax
	call find_number

	mov rdx, 0
	mov rax, 0
convert:
		; Check if char is in our base
		; And which index
	push rax
	mov rcx, 0
	mov cl, BYTE [rdi]
	call ft_isbase
	cmp rax, -1
	je end_atoi_base

	mov rbx, rax
	pop rax

		; num = (num * radix) + new_digit
	mul r9
	add rax, rbx
	inc rdi
	jmp convert

end_atoi_base:
	pop rax
	lea rcx, [rel sign]
	cmp [rcx], BYTE 0
	je positive
		; All returns
negative:
	NEG RAX
positive:
	pop rbx
	RET
error:
	mov rax, 0
	pop rbx
	RET

		section .data
	ascii	TIMES 255 DB 0
	sign	DB 0
