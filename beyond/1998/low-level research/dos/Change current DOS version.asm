; Change Current DOS Version
; DanSei 1998.12.29

        .Model Tiny
        .286
        .Code
        Org 100h

Start:
        Mov     AH, 40h
        Mov     AX, 3521h
        Int     21h
        Cmp     BX, Offset New21
        Jnz     Install
        Mov     AH, 9
        Lea     DX, Installed
        Int     21h
        Int     20h
Installed:
        DB      'CurVer has been installed.$'
Install:
        Mov     AH, 25h
        Lea     DX, New21
        Int     21h
