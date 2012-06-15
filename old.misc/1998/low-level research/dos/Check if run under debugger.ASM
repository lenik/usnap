; Identifies if I was executed by COMMAND or by DEBUG

; Technology:
;       1. Judge if CX = FF
;       2. Judge if Program in Env. Seg. is Abr. Filename (Including Path.)

        .Model Tiny
        .Code
        Org 100h

Start:
        Mov     AH, 9

        Lea     DX, ByCommand1
        Cmp     CX, 0FFh
        Jz      OutPut1
        Lea     DX, ByDebug1
OutPut1:
        Int     21h

        Mov     ES, DS: [2Ch]   ; Enviroment Segment
        Xor     BX, BX
SeekNameA:
        Inc     BX
        Cmp     Word Ptr ES: [BX], 0
        Jnz     SeekNameA
        Add     BX, 3

        Lea     DX, ByDebug2
SeekNameB:
        Inc     BX
        Cmp     Byte Ptr ES: [BX], 0
        Jz      NoFound
        Cmp     Byte Ptr ES: [BX], 20h
        Jnz     SeekNameB
        Lea     DX, ByCommand2
NoFound:
        Int     21h

        Xor     AX, AX
        Push    AX
        Ret

ByDebug1        DB      'CX is not FF, BY DEBUG, NOT '
ByCommand1      DB      'BY COMMAND (CX = FF)!', 0Ah, 0Dh, '$'

ByDebug2        DB      'Abr. Filename, BY DEBUG, NOT '
ByCommand2      DB      'BY COMMAND (Full Filename)!', 0Ah, 0Dh, '$'

        End     Start
