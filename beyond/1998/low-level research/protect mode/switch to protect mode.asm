; Program:      Tutor 10 - 1   [PROTECT MODE PROGRAMMING TUTOR]
; Objective:    Demo switching between real mode and protect mode
; Function:     Dump 110000H for 256 bytes in Hex

Jump    Macro Selector, Offset
        DB 0EAh
        DW Offset
        DW Selector
        Endm

EchoChr Macro Ascii
        Mov AH, 2
        Mov DL, Ascii
        Int 21h
        Endm

Desc    Struc
        LimitL  DW 0
        BaseL   DW 0
        BaseHL  DB 0
        Attr    DW 0
        BaseHH  DB 0
Desc    Ends

PDesc   Struc
        Limit   DW 0
        Base    DD 0
PDesc   Ends

ATDW    = 0F2H   ; PRESENT R/W DATA SEG ATTR            DPL = 3
ATCE    = 0F8H   ; PRESENT EXEC ONLY CODE SEG ATTR      DPL = 3

        .386p

DSeg    Segment Use16

        GDT             Label Byte
        Dummy           Desc <>
        Code            Desc <0FFFFh, , , ATCE, >
        Code_Sel        = Code - GDT Or 3
        DataS           Desc <0FFFFh, 0h, 11h, ATDW, 0>
        DataS_Sel       = DataS - GDT Or 3
        DataD           Desc <0FFFFh, , , ATDW, >
        DataD_Sel       = DataD - GDT Or 3
        GDTLen          = $ - GDT

        VGDTR           PDesc <GDTLen, >

        BufferLen       = 256
        Buffer          DB BufferLen Dup (0)

DSeg    Ends

CSeg    Segment Use16
        Assume CS: CSeg, DS: DSeg
Start:
        Mov     AX, DSeg
        Mov     DS, AX
        ; Prepare for load VGDTR into GDTR
        Mov     BX, 10h
        Mul     BX
        Add     AX, Offset GDT
        Adc     DX, 0
        Mov     Word Ptr VGDTR.Base,            AX
        Mov     Word Ptr VGDTR.Base + 2,        DX
        ; Set Code Segment Descriptor
        Mov     AX, CS
        Mul     BX
        Mov     Code.BaseL,     AX
        Mov     Code.BaseHL,    DL
        Mov     Code.BaseHH,    DH
        ; Set Dest Data Segment Descriptor
        Mov     AX, DS
        Mul     BX
        Add     AX, Offset Buffer
        Adc     DX, 0
        Mov     DataD.BaseL,    AX
        Mov     DataD.BaseHL,   DL
        Mov     DataD.BaseHH,   DH
        ; Load into GDTR
        LGDT    QWord Ptr VGDTR

        ; Switch to Protected Mode
        Cli
        Call    EnableA20
        Mov     EAX, CR0
        Or      EAX, 1
        Mov     CR0, EAX
        Jump    <Code_Sel>, <Offset Virtual>

Virtual:
        ; Now working under protected mode
        Mov     AX, DataS_Sel
        Mov     DS, AX
        Mov     AX, DataD_Sel
        Mov     ES, AX
        Cld
        Xor     SI, SI
        Xor     DI, DI
        Mov     CX, BufferLen / 4
        Repz    Movsd

        ; Switch to Real Mode
        Mov     EAX, CR0
        And     EAX, 0FFFFFFFEh
        Mov     CR0, EAX
        Jump    <Seg Real>, <Offset Real>

Real:
        ; Now returned to real mode
        Call    DisableA20
        Sti
        Mov     AX, DSeg
        Mov     DS, AX
        Mov     SI, Offset Buffer
        Cld
        Mov     BP, BufferLen / 10h
NextLine:
        Mov     CX, 10h
NextChr:
        Lodsb
        Push    AX
        Shr     AL, 1
        Call    ToAscii
        EchoChr AL
        Pop     AX
        Call    ToAscii
        EchoChr AL
        EchoChr ' '
        Loop    NextChr
        EchoChr 0Dh
        EchoChr 0Ah
        Dec     BP
        Jnz     NextLine

        Mov     AX, 4C00h
        Int     21h

ToAscii Proc
        And     AL, 0Fh
        Or      AL, 30h
        Cmp     AL, 39h
        Jbe     $+4
        Add     AL, 7
        Ret
ToAscii Endp

EnableA20       Proc
        Push    AX
        In      AL, 92h
        Or      AL, 2
        Out     92h, AL
        Pop     AX
        RET
EnableA20       Endp

DisableA20      Proc
        Push    AX
        In      AL, 92h
        And     AL, 0FDh
        Out     92h, AL
        Pop     AX
        Ret
DisableA20      Endp

CSeg    Ends

        End     Start
