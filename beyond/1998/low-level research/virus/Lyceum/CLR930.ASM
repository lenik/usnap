;               Dynamical Lyenum / 930 Virus' Cleaning
;               Author / DanSei   1998.11.1

        .Model Tiny

.Code

        Org 100H

Start:

        Mov AX, 0ABCDh          ; Test if there's 930 in memory
        Int 21h
        Cmp AX, 0FFFFh
        Jnz No930

        Push DS

        Mov ES, DS: [2]         ; Virus Address

        Mov AH, 25h

        Mov AL, 09h
        Mov DX, ES: [3A2h]      ; Origin Int 09h Address
        Mov DS, ES: [3A4h]
        Int 21h

        Mov AL, 21h             ; Origin Int 21h Address
        Mov DX, ES: [3A6h]
        Mov DS, ES: [3A8h]
        Int 21h

        Pop DS

        Lea DX, SucClear

        Jmp Exit

No930:
        Lea DX, NoLyenumVirus

Exit:
        Mov AH, 9
        Int 21h

        Int 20h

SucClear        DB 'Lyenum / 930 Virus Had Successful Cleaned!', 0Ah, 0Dh, '$'

NoLyenumVirus   DB 'No Lyenum / 930 Virus in Memory!', 0Ah, 0Dh, '$'

        End Start
