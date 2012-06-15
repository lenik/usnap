; Clear Virus in Memory

        .Model Tiny
        .Code
        Org 100h

Start:
        Mov AX, 0F078h          ; Check Grave Virus
        Int 21h
        Or AX, AX
        Jnz NoVirus
        Push DS
        Mov AX, 3521h
        Int 21h
        Mov AX, 2521h
        LDS DX, ES: [0A7h]
        Int 21h
        Pop DS
        Lea DX, Cleared
Print:
        Mov AH, 9
        Int 21h
        Int 20h
NoVirus:
        Lea DX, NoVirusFound
        Jmp Short Print

        NoVirusFound    DB 'No Grave Found in Memory !$'
        Cleared         DB 'Grave Virus Has Been Cleared in Memory !$'

        End Start
