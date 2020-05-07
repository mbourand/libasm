extern __errno_location
global ft_read		; fonction ssize_t ft_read(int fd, void *buf, size_t count)

ft_read:
	mov rax,0		; 0 est le code du syscall read
	syscall			; lancement du syscall
	cmp rax,0
	jl _ret_err		; si la valeur de read est en dessous de 0, on set errno et on return -1
	ret				; sinon on retourne la valeur de retour du syscall

_ret_err:			; set errno et retourne -1
	neg rax			; on met rax à la future valeur d'errno
	mov rdx,rax		; on fait une copie de rax
	call __errno_location ; rax contient maintenant un pointeur sur errno
	mov [rax],rdx	; on set la valeur d'errno
	mov rax,-1		; on met la valeur de retour à -1
	ret
