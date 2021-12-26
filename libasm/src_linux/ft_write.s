; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_write.s                                         :+:    :+:             ;
;                                                      +:+                     ;
;    By: mraasvel <mraasvel@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2021/02/18 23:36:14 by mraasvel      #+#    #+#                  ;
;    Updated: 2021/02/18 23:36:15 by mraasvel      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

		global	ft_write
		extern	__errno_location

		section	.text
ft_write:
			; Set write syscall_number and call it
		mov		rax, 1
		syscall
			; Check if return value was negative
		cmp		rax, 0
		jl		error
		ret
error:
			; Set errno to absolute value of return
		neg		rax
		mov		rcx, rax
		call	__errno_location wrt ..plt
		mov		[rax], rcx

			; Return -1
		mov		rax, -1
		ret
