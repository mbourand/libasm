global ft_strcpy			; fonction char *ft_strlen(char *dest, const char *src)

ft_strcpy:
	xor rax,rax				; initialisation de la variable d'itération à 0

_loop:
	mov dl,[rsi + rax]		; on récupère le caractère
	or dl,dl
	jz _ret					; si il vaut 0, on termine le programme
	mov byte[rdi + rax],dl	; on remplace le caractère de dest (rdi) par celui de src (rsi)
	inc rax					; on passe au caractère suivant
	jmp _loop

_ret:
	mov byte[rdi + rax],0			; on met l'\0 en fin de chaîne
	mov rax,rdi				; on retourne un pointeur sur dest
	ret
