global ft_strdup		; fonction char *ft_strdup(char *str)
extern ft_strlen		; ft_strlen(char *str)
extern ft_strcpy		; ft_strcpy(char *dest, const char *src)
extern malloc			; malloc(size_t size)

ft_strdup:
	call ft_strlen		; on récupère dans rax la longueur de str
	inc rax				; on ajoute 1 pour mettre l'\0
	push rdi			; on fait une sauvegarde de str
	mov rdi,rax			; on met la longueur de str en paramètre pour malloc
	call malloc			; appel de malloc
	pop rdi				; on récupère le pointeur sur str
	or rax,rax
	jz _ret_err			; si malloc à échoué on retourne 0
	mov rsi,rdi			; on met str en tant que src pour strcpy
	mov rdi,rax			; on met le pointeur de malloc en tant que dest pour strcpy
	call ft_strcpy
	ret

_ret_err:			; retourne 0
	xor rax,rax
	ret
