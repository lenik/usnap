; FILE LINKER
; DANSEI / 1998.12.12

;       MAKE THE SAME LINKER OF A SPECIFIED FILE
;       THIS PROGRAM IS DANGEROUS TO USE
;       PLEASE USING CAREFULLY !

        .MODEL TINY
        .286
        .CODE
        ORG 100H

; PROGRAMMING:
;     ∫ CHECK PARAMETERS                                     ø
;     ∫ FIND SOURCE FILE, GET ITS STRUCTURE                ø ≥
;     ∫ FIND DESTINE FILE                                  ≥ ≥
;     ∫       ≥ DELETED WITH CONFUMING IF EXISTED          √ø≥
;     ∫       ¿ CREATE THEN                                ≥√Ÿ
;     ∫ FIND DESTINE FILE AGAIN FOR ITS STRUCTURE ADDRESS  Ÿ≥
;     ” WRITE STRUCTURE TO DESTINE                          Ÿ

START:
        CALL    CHECK_PARAMETER
        JC      PARAMETER_ERROR
        MOV     AH, 1AH                 ; SET DTA ADDRESS
        LEA     DX, LOCAL_DTA
        INT     21H
        MOV     SI, 81H
        CALL    FIND_FIRST
        JZ      SOURCE_ERROR
        LEA     DI, SOURCE_STRUCTURE
        CALL    READ_STRUCTURE
        JC      SOURCE_ERROR
LOOP_1:
        INC     SI
        CMP     BYTE PTR [SI], 0
        JNZ     LOOP_1
        INC     SI
        CALL    FIND_FIRST
        JZ      CREATE_DUMMY
        CALL    DELETE_FILE
        JNZ     FLINK_EXIT
CREATE_DUMMY:
        CALL    CREATE_FILE
        JC      DESTINE_ERROR
        CALL    FIND_FIRST
        JZ      DESTINE_ERROR
        LEA     SI, SOURCE_STRUCTURE
        CALL    WRITE_STRUCTURE
        JC      DESTINE_ERROR
FLINK_DONE:
        ; SUCCESS
FLINK_EXIT:
        INT     20H

PARAMETER_ERROR:
        JMP     FLINK_EXIT
SOURCE_ERROR:
        JMP     FLINK_EXIT
DESTINE_ERROR:
        JMP     FLINK_EXIT

FIND_FIRST      PROC NEAR
        ;       FIND FIRST FILE WITH FILENAME IN SI
        ;       RETURN ZF = 0 IF FOUND OR = 1 IF NOT FOUND
        PUSH    AX
        PUSH    CX
        PUSH    DX
        PUSH    SI
        MOV     AH, 4EH         ; FIND FIRST FILE, DS:DX, CX = ATTR
        MOV     CX, 3FH         ; ALL FILES
        MOV     DX, SI
        INT     21H
        PUSHF                   ; ASSIGN CF TO ZF
        POP     AX
        MOV     DX, AX
        SHL     DL, 6
        OR      DL, 0BFH
        AND     AL, DL
        PUSH    AX
        POPF
        POP     SI
        POP     DX
        POP     CX
        POP     AX
        RET
FIND_FIRST      ENDP

DELETE_FILE     PROC NEAR
DELETE_FILE     ENDP

CREATE_FILE     PROC NEAR
CREATE_FILE     ENDP

READ_STRUCTURE  PROC NEAR
READ_STRUCTURE  ENDP

WRITE_STRUCTURE PROC NEAR
WRITE_STRUCTURE ENDP

CHECK_PARAMETER PROC NEAR
CHECK_PARAMETER ENDP

        END     START
