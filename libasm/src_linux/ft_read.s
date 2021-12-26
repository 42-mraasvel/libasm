; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_read.s                                          :+:    :+:             ;
;                                                      +:+                     ;
;    By: mraasvel <mraasvel@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2021/02/18 11:30:09 by mraasvel      #+#    #+#                  ;
;    Updated: 2021/02/19 16:17:20 by mraasvel      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

		global ft_read
		extern __errno_location

		section .text
ft_read:
	mov rax, 0
	syscall
		; Check if an error was returned
	cmp rax, 0
	jl error
	ret

error:
		; Absolute value of the read return for errno
	NEG rax
		; maybe push rax, pop [rax] ?? try it out
	mov rcx, rax
		; Call errno, returns address to errno and stores in rax
	call __errno_location wrt ..plt
	mov [rax], rcx

		; Set return value
	mov rax, -1
	ret
