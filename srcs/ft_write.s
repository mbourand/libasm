extern __errno_location
global ft_write		; fonction ssize_t ft_write(int fd, char *str, size_t count)

ft_write:
	mov rax,1		; 0 est le code du syscall write
	syscall			; lancement du syscall
	cmp rax,0
	jl _ret_err		; si la valeur de read est en dessous de 0, on return -1
	ret				; sinon on retourne la valeur de retour du syscall

_ret_err:			; set errno et retourne -1
	neg rax			; on met rax à la future valeur d'errno
	mov rdx,rax		; on fait une copie de rax
	call __errno_location ; rax contient maintenant un pointeur sur errno
	mov [rax],rdx	; on set la valeur d'errno
	mov rax,-1		; on met la valeur de retour à -1
	ret
