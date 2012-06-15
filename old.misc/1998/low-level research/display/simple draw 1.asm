; Draw machine ver 0.01

code    segment
D0_01   proc far
        assume cs:code,ds:code
start:  jmp short begin
curx    dw 0
cury    dw 0
curc    db 0
begin:
        push cs
        pop ds

        mov ax,12h
        int 10h

        mov [curx],320
        mov [cury],240
        mov [curc],15
        mov ah,8

dbegin:
        mov ah,0ch
        mov al,[curc]
        mov cx,[curx]
        mov dx,[cury]
        int 10h

        mov ah,8
        int 21h
        cmp al,'8'
        je short d_up
        cmp al,'4'
        je short d_left
        cmp al,'2'
        je short d_down
        cmp al,'6'
        je short d_right
        cmp al,'+'
        je short d_cinc
        cmp al,'-'
        je short d_cdec
;        cmp al,27h
;        je short d_esc

        jmp short dbegin

d_up:   dec [cury]
        jmp short d_oy
d_down: inc [cury]
d_oy:   cmp [cury],0
        jle short d_down
        cmp [cury],479
        jge short d_up
        jmp short dend

d_left: dec [curx]
        jmp short d_ox
d_right:inc [curx]
d_ox:   cmp [curx],0
        jle short d_right
        cmp [curx],639
        jge short d_left
        jmp short dend

d_cdec: dec [curc]
        jmp short d_oc
d_cinc: inc [curc]
d_oc:   cmp [curc],0
        jl short d_cinc
        cmp [curc],15
        jg short d_cdec

dend:   jmp short dbegin
desc:
        mov ax,3
        int 10h
        mov ax,4c00h
        int 21h
D0_01   endp
code    ends
        end start
