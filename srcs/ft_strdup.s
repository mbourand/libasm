global ft_strdup		; fonction char *ft_strdup(char *str)
extern ft_strlen		; ft_strlen(char *str)
extern ft_strcpy		; ft_strcpy(char *dest, const char *src)
extern _malloc			; malloc(size_t size)

ft_strdup:
	call ft_strlen		; on récupère dans rax la longueur de str
	mov rdx,rdi			; on garde un registre sur str
	mov rdi,rax			; on place en paramètre pour malloc la taille de str
	inc rdi				; incrémentation de rdi pour permettre de mettre l'\0
	call _malloc		; appel de malloc
	or rax,rax			; comparaison de rax avec 0
	jz _ret_err			; si malloc a échoué, on retourne 0
	mov rsi,rdx			; on met str en tant que src pour ft_strcpy
	mov rdi,rax			; on met le pointeur retourné par malloc en tant que dest pour ft_strcpy
	call ft_strcpy		; appel de ft_strcpy
	ret					; on retourne la valeur de retour de ft_strcpy (dest)
	
_ret_err:				; retourne 0
	mov rax,0
	ret