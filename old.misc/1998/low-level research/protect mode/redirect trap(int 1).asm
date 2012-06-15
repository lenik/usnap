
.Model  Tiny
.286

.Data
        LoopS   Db '0123456789ABCDEFGHIJKLMNOQPRSTUVWXYZabcdefghijklmnopqrstuvwxyz'
.Code

Start:
        Mov     AX, 3501h
        Int     21h
        Mov     AX, 2501h
        Lea     DX, NewTrap
        Int     21h

        Cli
        Pushf
        Pop     AX
        Or      AX, 100h
        Push    AX
        Popf
        Sti

        Xor     DI, DI
        Mov     DX, DI
;        Call    OutW

        Cli
        Pushf
        Pop     AX
        And     AX, 0FEFFh
        Push    AX
        Popf
        Sti

        Mov     AX, 2501h
        Push    ES
        Pop     DS
        Mov     DX, BX
        Int     21h

        Mov     AH, 4Ch
        Int     21h

NewTrap Proc
;        Inc     DI
        IRet
NewTrap Endp

OutW    Proc
        ; Out DX Value
        ; Needed to be called out of indos
        Push    BX
        Push    CX
        Push    DX
        Mov     BX, DX
        Mov     DL, BH
        Mov     CL, 4
        Shr     DL, CL
        Call    Disp16
        Mov     DL, BH
        And     DL, 0Fh
        Call    Disp16
        Mov     DL, BL
        Shr     DL, CL
        Call    Disp16
        Mov     DL, BL
        And     DL, 0Fh
        Call    Disp16
        Pop     DX
        Pop     CX
        Pop     BX
        Ret
Outw    Endp

Disp16  Proc
        Push    AX
        Push    DX
        Mov     AL, DL
        Add     AL, 30h
        Daa
        Cmp     AL, 40h
        Jl      SkipA
        Inc     AL
SkipA:
        Mov     AH, 2
        Mov     DL, AL
        Int     21h
        Pop     DX
        Pop     AX
        Ret
Disp16  Endp

        End     Start
