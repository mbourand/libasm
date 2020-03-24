global ft_write		; fonction ssize_t ft_write(int fd, char *str, size_t count)

ft_write:
	mov rax,1		; 0 est le code du syscall write
	syscall			; lancement du syscall
	cmp rax,0
	jl _ret_err		; si la valeur de read est en dessous de 0, on return -1
	ret				; sinon on retourne la valeur de retour du syscall

_ret_err:			; retourne -1
	mov rax,-1
	ret