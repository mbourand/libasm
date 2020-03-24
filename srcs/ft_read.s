global ft_read		; fonction ssize_t ft_read(int fd, void *buf, size_t count)

ft_read:
	mov rax,0		; 0 est le code du syscall read
	syscall			; lancement du syscall
	cmp rax,0
	jl _ret_err		; si la valeur de read est en dessous de 0, on return -1
	ret				; sinon on retourne la valeur de retour du syscall

_ret_err:			; retourne -1
	mov rax,-1
	ret