global ft_strcmp		; fonction int ft_strcmp(const char *s1, const char *s2)

ft_strcmp:
	xor rbx,rbx				; initialisation de la variable d'itération à 0
	xor rax,rax				; initialisation de la valeur de retour à 0

_loop:
	mov dl,[rdi + rbx]		; on récupère le caractère dans s1
	mov dh,[rsi + rbx]		; on récupère le caractère dans s2
	or dl,dl
	jz _ret
	or dh,dh
	jz _ret					; si dl ou dh vaut 0, on return
	cmp dl,dh				; on compare les deux caractères
	jne _ret				; si les caractères ne sont pas les mêmes, on termine le programme	
	inc rbx					; on passe au caractère suivant
	jmp _loop

_ret:						; retourne la différence entre les premiers caractères différents
	sub dl,dh
	or dl,dl
	jl _neg
	ja _pos
	mov al,dl
	ret

_neg:
	mov rax,-1
	ret

_pos:
	mov rax,1
	ret