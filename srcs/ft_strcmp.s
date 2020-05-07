global ft_strcmp		; fonction int ft_strcmp(const char *s1, const char *s2)

ft_strcmp:
	xor rbx,rbx		; initialisation de la variable d'itération à 0
	xor rax,rax		; initialisation de la valeur de retour à 0
	xor cx,cx
	xor dx,dx

_loop:
	mov cl,[rdi + rbx]	; on récupère le caractère dans s1
	mov dl,[rsi + rbx]	; on récupère le caractère dans s2
	or cl,cl
	jz _ret
	or dl,dl
	jz _ret			; si dl ou dh vaut 0, on return
	cmp cl,dl		; on compare les deux caractères
	jne _ret		; si les caractères ne sont pas les mêmes, on termine le programme	
	inc rbx			; on passe au caractère suivant
	jmp _loop

_ret:				; retourne la différence entre les premiers caractères différents
	sub cx,dx
	jl _neg
	ja _pos
	jmp _eq

_neg:
	mov rax,-1
	ret

_pos:
	mov rax,1
	ret

_eq:
	mov rax,0
	ret
