; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strlen.s                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: mraasvel <mraasvel@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2021/02/18 23:36:12 by mraasvel      #+#    #+#                  ;
;    Updated: 2021/02/19 16:17:41 by mraasvel      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

		global ft_strlen

		section .text
ft_strlen:
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
	ret
