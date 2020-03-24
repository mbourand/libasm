global ft_strlen		; fonction size_t ft_strlen(const char *str)

ft_strlen:
	xor rax,rax		; initialisation de rax à 0

_loop:
	mov dl,[rdi + rax]	; dl contient le caractère quon vérifie
	or dl,dl		; comparaison de dl avec 0
	jz _ret			; si dl = 0, on arrête
	inc rax			; on ajoute un à la longueur de la chaîne
	jmp _loop		; on recommence pour le caractère suivant

_ret:
	ret
