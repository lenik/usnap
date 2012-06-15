movingcross     proc
        cli
        pusha
        push ds
        push es

        call initscr
        jc movingerr

        mov dx, 0c28h   ; pos (12, 40)
movingmainloop:
        mov cx, 7       ; make it dark
        call movingrestore      ; draw background
        call RandXY
        call drawcrossing
        mov ah, 0bh     ; check keybrd
        int 21h         ; al = ff if key
        or al, al
        jnz movingend
        push 01000h
        call Delay
        jmp movingmainloop

movingend:
        mov ah, 49h     ; (es -> allocated memory)
        int 21h
        mov cx, 0FFh
        call movingrestore

movingret:
        pop es
        pop ds
        popa
        sti
        ret
movingerr:
        push ax
        push bx
        push cx
        mov ax, 0A45h
        mov bx, 0
        mov cx, 1
        int 10h
        pop cx
        pop bx
        pop ax
        jmp movingret

initscr:                ; initialize screen, ds:si -> scr buf, es:di -> bak
                mov ah, 48h     ; ax, bx destroyed
                mov bx, 80h
                int 21h         ; allocate memory (bx) <-> ax: (bx)
                jc initend      ; error
                push ax
                pop es
                push 0b800h
                pop ds
                xor si, si
                xor di, di
                mov cx, 2000    ; 80 * 25
        scrbak:
                lodsw
                mov al, ah
                stosb
                loop scrbak
        initend:
                ret

RandXY:
                pusha
                xor ah, ah
                call Rand
                jz incy
                dec dh
                jmp short modye
        incy:
                inc dh
        modye:
                cmp dh, 25
                jb modye1
                xor dh, dh
        modye1:
                call Rand
                jz incx
                dec dl
                jmp short modxe
        incx:
                inc dl
        modxe:
                cmp dl, 80
                jb modxe1
                xor dl, dl
        modxe1:
                popa
                ret

drawcrossing:           ; draw highlight crossing at dh row, dl col
                pusha
                xor ah, ah
                mov al, dh
                mov cl, 160
                mul cl
                inc ax
                mov bx, ax      ; bx -> head attr. byte of row dh
                mov cx, 80      ; row[dh][0..79]
        drawx:
                or byte ptr [bx], 78h    ; lighten it
                inc bx
                inc bx
                loop drawx
                xor bx, bx      ; row[0..24][dl]
                mov bl, dl
                add bx, bx
                inc bx
                mov cx, 25
        drawy:
                or byte ptr [bx], 78h
                or byte ptr [bx + 2], 78h
                add bx, 160
                loop drawy

                popa
                ret

movingrestore:          ; cl contain and bits
                pusha
                push ds
                push es
                pop ds
                pop es
                xor si, si
                mov di, 1
                mov bx, cx
                mov cx, 2000
        restloop:
                lodsb
                and al, bl
                stosb
                inc di
                loop restloop
                push ds
                push es
                pop ds
                pop es
                popa
                ret

movingcross     endp
