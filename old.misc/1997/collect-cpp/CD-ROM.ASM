
.286c

Data    Segment Byte
Buffer          DB 8000h Dup (0)

ReqHeader       Label
                DB 24
                DB 0
                DB 80h          ; Read long
        Status  DW ?            ; Status
                DB 4 Dup (0)    ; Reserved
                DD 0
                DB 0            ; HSG
        trOff   DW Offset Buffer
        trSeg   DW Data
                DW 1            ; number of sectors
                DD 1000         ; start sector
                DB 0
                DB 0
                DB 0
Data    Ends

Stacks  Segment Stack 'Stack'
        DB 1000h Dup (0)
Stacks  Ends

Code    Segment
        Assume CS: Code, DS: Data, ES: Data, SS: Stacks
Start:
        Push DS
        Push 0
        Mov AX, Data
        Mov DS, AX
        Mov ES, AX
        Mov AX, 0802h
        Mov BX, Offset ReqHeader
        Int 2Fh
        Pop AX
        Mov AX, Status
        Retf
Code    Ends

        End Start
