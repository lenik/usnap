; Draw machine ver 1.00

stacks  segment stack
        db 256 dup (0)
stacks  ends

data    segment
        maxx    dw 0
        maxy    dw 0
        maxc    dw 0
        curx    dw 0
        cury    dw 0
        curc    db 0
        key     db 0
        disptype        dw 0

        msg0    db 'Max:',0dh,0ah,'X='
        msg1    dw 0,0a0dh
                db 'Y='
        msg2    dw 0,0a0dh
                db '$'
data    ends

code    segment
D1_00   proc far
        assume cs:code,ds:data,es:data,ss:stacks
start:
        push ds
        xor ax,ax
        push ax
        mov ax,data
        mov ds,ax
        mov es,ax
        mov ax,stack
        mov ss,ax

        mov ax,12h
        int 10h

        push es

        mov ah,15h
        int 10h ; Return Physical Display Parms (convertible)
        mov disptype,ax

        mov ax,es:[di+4]
        mov ds:[msg1],ax
        mov ax,es:[di+5]
        mov ds:[msg2],ax

        pop es

        mov ds:[curx],320
        mov ds:[cury],200
        mov ds:[curc],15
        mov ah,8

dbegin:
        mov ah,0ch
        mov al,ds:[curc]
        mov cx,ds:[curx]
        mov dx,ds:[cury]
        int 10h

        mov ah,8
        int 21h
        cmp al,'8'
        je d_up
        cmp al,'4'
        je d_left
        cmp al,'2'
        je d_down
        cmp al,'6'
        je d_right
        cmp al,'+'
        je d_cinc
        cmp al,'-'
        je d_cdec
        cmp al,27h

        jmp short dbegin

d_up:   dec ds:[cury]
        jmp short d_oy
d_down: inc ds:[cury]
d_oy:   cmp ds:[cury],10
        jle short d_down
        cmp ds:[cury],200
        jge short d_up
        jmp dend

d_left: dec ds:[curx]
        jmp short d_ox
d_right:inc ds:[curx]
d_ox:   cmp ds:[curx],10
        jle short d_right
        cmp ds:[curx],500
        jge short d_left
        jmp dend

d_cdec: dec ds:[curc]
        jmp short d_oc
d_cinc: inc ds:[curc]
d_oc:   cmp ds:[curc],0
        jl short d_cinc
        cmp ds:[curc],15
        jg short d_cdec
        jmp dend

dend:   jmp dbegin
desc:
        mov ax,3
        int 10h
        mov ax,4c00h
        int 21h
D0_01   endp
code    ends
        end start
