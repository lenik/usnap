; display path

        .Model Small
        .286
        .Code
        Org 100h

Start:
        Mov AX, DS: [16h]           ; parent process seg.
        Mov DS, AX
        Mov AX, DS: [2Ch]           ; Parent's enviroment seg.
        Mov DS, AX
        Xor SI, SI
Loop1:
        Cmp byte ptr [SI], 0
        Jz Nofound
        Call Check
        Jc Loop1
        Mov AH, 2
        Mov DL, 9
        Int 21h
        Add SI, 5
Loop2:
        Mov DL, [SI]
        Or DL, DL
        Jz _End
        Cmp DL, ';'
        Jne DisplayChar
        Mov DL, 0Dh
        Int 21h
        Mov DL, 0Ah
        Int 21h
        Mov DL, 9
DisplayChar:
        Int 21h
        Inc SI
        Jmp Loop2
_End:
        Mov AH, 4Ch
        Int 21h

Check:
        Cmp byte ptr [SI][0], 'P'
        Jne NotThis
        Cmp byte ptr [SI][1], 'A'
        Jne NotThis
        Cmp byte ptr [SI][2], 'T'
        Jne NotThis
        Cmp byte ptr [SI][3], 'H'
        Jne NotThis
        Clc
        Ret
NotThis:
        Inc SI
        Cmp byte ptr [SI], 0
        Jnz NotThis
        Inc SI
        Stc
        Ret

NoFound:
        Mov AH, 9
        Push CS
        Pop DS
        Mov DX, Offset no
        Int 21h
        Jmp _End

no      db 'no found!$'

        End Start
