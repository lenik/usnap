	.model tiny
	.code
        .286
	org 100h

start:
        mov ah, 4ah
        mov bx, 100h
        int 21h
        call movingcross
        int 20h

include moving.asm

AsciiToBinary   proc    ; DLDH -> DL
	push ax               ; DH: Bit 0: DHerror, Bit 1: DLerror
	xor al, al            ; AL: as DH
	cmp dh, 30h
	jl DHerror
	sub dh, 30h
	cmp dh, 0ah
	jl DHok       ; 0 - 9
	sub dh, 7
	cmp dh, 10h
	jl DHok       ; A - F
	sub dh, 20h
	cmp dh, 10h
	jl DHok       ; a - f
DHerror:
	xor dh, dh
	or al, 1
DHok:
	cmp dl, 30h
	jl DLerror
	sub dl, 30h
	cmp dl, 0ah
	jl DLok       ; 0 - 9
	sub dl, 7
	cmp dl, 10h
	jl DLok       ; A - F
	sub dl, 20h
	cmp dl, 10h
	jl DLok       ; a - f
DLerror:
	xor dl, dl
	or al, 2
DLok:
	push cx
	mov cl, 4
	shl dl, cl
	pop cx
	add dl, dh
	mov dh, al
	pop ax
	ret
AsciiToBinary   endp

ToUpper         proc    ; Translate CX Bytes' String in DS:SI
	or cx, cx
	jz TU_Done
	push ax
	push cx
	push si
	push di
	push es
	push ds               ; ES:DI = DS:SI
	pop es
	mov di, si
ToUpperLoop:
	lodsb
	cmp al, 'a'
	jl TU_Continue
	cmp al, 'z'
	jg TU_Continue
	xor al, 20h
TU_Continue:
	stosb
	loop ToUpperLoop
	pop es
	pop di
	pop si
	pop cx
	pop ax
TU_Done:
	ret
ToUpper         endp

Rand    Proc    ; Return Random in AL and 0 or 1 in ZF
        push cx
        push dx
        xor ax, ax
        int 1ah
        mov cl, al
        rol ax, cl
        add CS: RandWord, DX
        mov ax, CS: RandWord
        pop dx
        pop cx
        test ax, 1
        ret
        RandWord dw 0
Rand    Endp

Delay   Proc    ; Delay DX * 4 ms
        pop cs: dv1
        pop cs: dv2
        push cs: dv1
        pusha
        mov dx, cs: dv2
        mov cx, dx
        shr cx, 14
        shl dx, 2
        mov ah, 86h
        int 15h
        popa
        ret
        dv1     dw 0
        dv2     dw 0
Delay   Endp

end start
