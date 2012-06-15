
PAGE  59,132

;ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ
;ÛÛ					                                 ÛÛ
;ÛÛ				AISCAN	                                 ÛÛ
;ÛÛ					                                 ÛÛ
;ÛÛ      Created:   16-Apr-96		                                 ÛÛ
;ÛÛ      Passes:    5          Analysis	Options on: none                 ÛÛ
;ÛÛ					                                 ÛÛ
;ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ

target		EQU   'T3'                      ; Target assembler: TASM-3.2

include  c:\t\sr.inc


; The following equates show data references outside the range of the program.

DATA_1E		EQU	8
DATA_2E		EQU	1CH
DATA_3E		EQU	2CH
DATA_4E		EQU	32H
DATA_5E		EQU	48H
DATA_6E		EQU	55H
DATA_7E		EQU	5AH
DATA_8E		EQU	5BH
DATA_9E		EQU	80H
DATA_10E	EQU	0C6H
DATA_11E	EQU	0C7H
DATA_12E	EQU	0C8H
DATA_13E	EQU	0C9H
DATA_14E	EQU	100H
DATA_15E	EQU	300H
DATA_16E	EQU	302H
DATA_17E	EQU	304H
DATA_18E	EQU	306H
DATA_19E	EQU	30AH
DATA_20E	EQU	30CH
DATA_21E	EQU	30EH
DATA_22E	EQU	312H
DATA_23E	EQU	320H
DATA_24E	EQU	322H
DATA_25E	EQU	326H
DATA_26E	EQU	335H
DATA_27E	EQU	346H
DATA_28E	EQU	355H
DATA_29E	EQU	359H
DATA_30E	EQU	35DH
DATA_31E	EQU	35FH
DATA_32E	EQU	363H
DATA_33E	EQU	365H
DATA_34E	EQU	375H
DATA_35E	EQU	3ECH
DATA_36E	EQU	40FH
DATA_37E	EQU	451H
DATA_38E	EQU	46DH
DATA_39E	EQU	48DH
DATA_40E	EQU	498H
DATA_41E	EQU	100H			;*
DATA_42E	EQU	8
DATA_43E	EQU	5BH
DATA_44E	EQU	302H			;*
DATA_45E	EQU	30EH			;*
DATA_46E	EQU	331H			;*
DATA_47E	EQU	344H			;*
DATA_48E	EQU	35BH			;*
DATA_49E	EQU	373H			;*
DATA_50E	EQU	383H			;*
DATA_51E	EQU	391H			;*
DATA_52E	EQU	3AFH			;*
DATA_53E	EQU	3B1H			;*
DATA_54E	EQU	3C8H			;*
DATA_55E	EQU	3CAH			;*
DATA_56E	EQU	3EAH			;*
DATA_57E	EQU	3ECH			;*
DATA_58E	EQU	40DH			;*
DATA_59E	EQU	428H			;*
DATA_60E	EQU	436H			;*
DATA_61E	EQU	44FH			;*
DATA_62E	EQU	451H			;*
DATA_63E	EQU	46BH			;*
DATA_64E	EQU	47FH			;*
DATA_65E	EQU	48DH			;*
DATA_66E	EQU	498H			;*
DATA_117E	EQU	1AA9H			;*
DATA_118E	EQU	1BF0H			;*

;------------------------------------------------------------  SEG_A   ----

SEG_A		SEGMENT	BYTE PUBLIC
		ASSUME CS:SEG_A  , DS:SEG_B , SS:STACK_SEG_C

DATA_67         DB      0                       ; LINE COUNTER
DATA_68		DB	'Press any key to continue...', 0DH
		DB	0

;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_1		PROC	NEAR
		PUSH	AX
		PUSH	BX
		PUSH	CX
		XOR	BH,BH			; Zero register
LOC_1:
		LODSB				; String [si] to al
		OR	AL,AL			; Zero ?
		JNZ	LOC_2			; Jump if not zero
		POP	CX
		POP	BX
		POP	AX
		RETN
LOC_2:
		MOV	CX,1
		CMP	AL,0AH
		JNE	LOC_3			; Jump if not equal
		MOV	AH,0EH
		INT	10H			; Video display   ah=functn 0Eh
						;  write char al, teletype mode
		MOV	AX,920H
		MOV	CX,50H
		INT	10H			; Video display   ah=functn 09h
						;  set char al & attrib bl @curs
						;   cx=# of chars to replicate
		assume	ds:SEG_A
		CMP	BYTE PTR CS:DATA_84,1
		JNE	LOC_1			; Jump if not equal
		INC	CS:DATA_67
		CMP	CS:DATA_67,18H
		JB	LOC_1			; Jump if below
		PUSH	DS
		PUSH	SI
		PUSH	BX
		PUSH	CS
		POP	DS
		MOV	CS:DATA_67,0
		MOV	SI,OFFSET DATA_68	; ('Press any key to continu')
		MOV	BL,8BH
		CALL	SUB_1
		XOR	AH,AH			; Zero register
		INT	16H			; Keyboard i/o  ah=function 00h
						;  get keybd char in al, ah=scan
		POP	BX
		MOV	AX,920H
		MOV	CX,50H
		INT	10H			; Video display   ah=functn 09h
						;  set char al & attrib bl @curs
						;   cx=# of chars to replicate
		POP	SI
		POP	DS
		JMP	SHORT LOC_1
LOC_3:
		CMP	AL,0DH
		JNE	LOC_4			; Jump if not equal
		MOV	AH,0EH
		INT	10H			; Video display   ah=functn 0Eh
						;  write char al, teletype mode
		JMP	SHORT LOC_1
LOC_4:
		CMP	AL,7
		JNE	LOC_5			; Jump if not equal
		MOV	AH,0EH
		INT	10H			; Video display   ah=functn 0Eh
						;  write char al, teletype mode
		JMP	SHORT LOC_1
LOC_5:
		MOV	AH,9
		INT	10H			; Video display   ah=functn 09h
						;  set char al & attrib bl @curs
						;   cx=# of chars to replicate
		MOV	AH,0EH
		INT	10H			; Video display   ah=functn 0Eh
						;  write char al, teletype mode
		JMP	SHORT LOC_1
SUB_1		ENDP


;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_2		PROC	NEAR
		PUSH	BX
		PUSH	SI
		PUSH	DS
		PUSH	ES
		POP	DS
		MOV	SI,DI
		MOV	BL,4FH			; 'O'
		CALL	SUB_1
		POP	DS
		POP	SI
		POP	BX
		RETN
SUB_2		ENDP

DATA_69		DB	0AH, 'Press any key to reset syst'
		DB	'em ...', 0

;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_3		PROC	NEAR
                ; RESET SYSTEM
		PUSH	CS
		POP	DS
                MOV     SI,OFFSET DATA_69       ; ('Press any key to reset system ...')
		MOV	BL,8BH
		CALL	SUB_1
		XOR	AH,AH			; Zero register
		INT	16H			; Keyboard i/o  ah=function 00h
						;  get keybd char in al, ah=scan
;*		JMP	FAR PTR LOC_216		;*
SUB_3		ENDP

		DB	0EAH
		DW	0, 0FFFFH		;  Fixup - byte match
DATA_70		DB	0

;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_4		PROC	NEAR
		PUSH	AX
		PUSH	BX
		PUSH	DX
		MOV	CS:DATA_70,0
		XOR	DX,DX			; Zero register
		MOV	BX,2710H
		DIV	BX			; ax,dx rem=dx:ax/reg
		MOV	AH,0EH
		OR	AL,AL			; Zero ?
		JNZ	LOC_6			; Jump if not zero
		MOV	AL,20H			; ' '
		JMP	SHORT LOC_7
LOC_6:
		MOV	CS:DATA_70,1
		ADD	AL,30H			; '0'
LOC_7:
		MOV	BX,7
		INT	10H			; Video display   ah=functn 0Eh
						;  write char al, teletype mode
		MOV	AX,DX
		XOR	DX,DX			; Zero register
		MOV	BX,3E8H
		DIV	BX			; ax,dx rem=dx:ax/reg
		MOV	AH,0EH
		CMP	CS:DATA_70,1
		JE	LOC_8			; Jump if equal
		OR	AL,AL			; Zero ?
		JNZ	LOC_8			; Jump if not zero
		MOV	AL,20H			; ' '
		JMP	SHORT LOC_9
LOC_8:
		MOV	CS:DATA_70,1
		ADD	AL,30H			; '0'
LOC_9:
		MOV	BX,7
		INT	10H			; Video display   ah=functn 0Eh
						;  write char al, teletype mode
		MOV	AX,DX
		XOR	DX,DX			; Zero register
		MOV	BX,64H
		DIV	BX			; ax,dx rem=dx:ax/reg
		MOV	AH,0EH
		CMP	CS:DATA_70,1
		JE	LOC_10			; Jump if equal
		OR	AL,AL			; Zero ?
		JNZ	LOC_10			; Jump if not zero
		MOV	AL,20H			; ' '
		JMP	SHORT LOC_11
LOC_10:
		MOV	CS:DATA_70,1
		ADD	AL,30H			; '0'
LOC_11:
		MOV	BX,7
		INT	10H			; Video display   ah=functn 0Eh
						;  write char al, teletype mode
		MOV	AX,DX
		XOR	DX,DX			; Zero register
		MOV	BX,0AH
		DIV	BX			; ax,dx rem=dx:ax/reg
		MOV	AH,0EH
		CMP	CS:DATA_70,1
		JE	LOC_12			; Jump if equal
		OR	AL,AL			; Zero ?
		JNZ	LOC_12			; Jump if not zero
		MOV	AL,20H			; ' '
		JMP	SHORT LOC_13
LOC_12:
		ADD	AL,30H			; '0'
LOC_13:
		MOV	BX,7
		INT	10H			; Video display   ah=functn 0Eh
						;  write char al, teletype mode
		MOV	AL,DL
		MOV	AH,0EH
		ADD	AL,30H			; '0'
		MOV	BX,7
		INT	10H			; Video display   ah=functn 0Eh
						;  write char al, teletype mode
		POP	DX
		POP	BX
		POP	AX
		RETN
SUB_4		ENDP

			                        ;* No entry point to code
		PUSH	BX
		PUSH	CX
		PUSH	AX
		SHR	AL,1			; Shift w/zeros fill
		SHR	AL,1			; Shift w/zeros fill
		SHR	AL,1			; Shift w/zeros fill
		SHR	AL,1			; Shift w/zeros fill
		CMP	AL,0AH
		JB	LOC_14			; Jump if below
		ADD	AL,7
LOC_14:
		ADD	AL,30H			; '0'
		MOV	AH,0EH
		XOR	BX,BX			; Zero register
		MOV	CX,1
		INT	10H			; Video display   ah=functn 0Eh
						;  write char al, teletype mode
		POP	AX
		AND	AL,0FH
		CMP	AL,0AH
		JB	LOC_15			; Jump if below
		ADD	AL,7
LOC_15:
		ADD	AL,30H			; '0'
		MOV	AH,0EH
		INT	10H			; Video display   ah=functn 0Eh
						;  write char al, teletype mode
		POP	CX
		POP	BX
		RETN

;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_5		PROC	NEAR
		PUSH	AX
		PUSH	CX
		PUSH	DX
		MOV	BL,[SI]
		INC	SI
		PUSH	AX
		CALL	SUB_1
		MOV	AX,920H
		MOV	BX,1FH
		MOV	CX,5
		INT	10H			; Video display   ah=functn 09h
						;  set char al & attrib bl @curs
						;   cx=# of chars to replicate
		POP	AX
		CALL	SUB_4
		MOV	SI,DI
		MOV	BL,[SI]
		INC	SI
		CALL	SUB_1
		POP	DX
		POP	CX
		POP	AX
		RETN
SUB_5		ENDP

DATA_71		DB	2
		DB	 88H, 02H, 88H, 02H, 88H, 02H
		DB	 88H, 02H, 00H, 03H, 00H, 01H
		DB	 00H, 01H, 00H, 02H, 88H, 02H
		DB	 88H, 02H, 88H, 02H, 88H, 02H
		DB	 00H, 03H, 00H, 01H, 00H, 01H
		DB	 00H, 02H, 88H, 02H, 88H, 02H
		DB	 88H, 02H, 88H, 02H, 00H, 03H
		DB	 00H, 01H, 00H, 01H, 00H, 02H
		DB	 88H, 02H, 88H, 02H, 88H, 02H
		DB	 88H, 02H, 00H, 03H, 00H, 01H
		DB	 00H, 01H, 00H, 02H, 88H, 02H
		DB	 88H, 02H, 88H, 02H, 88H, 02H
		DB	 00H, 03H, 00H, 01H, 00H, 01H
		DB	 00H, 02H, 88H, 02H, 88H, 02H
		DB	 88H, 02H, 88H, 02H, 00H, 03H
		DB	 00H, 01H, 00H, 01H, 00H, 02H
		DB	 88H, 02H, 88H, 02H, 88H, 02H
		DB	 88H, 02H, 00H, 03H, 00H, 01H
		DB	 00H, 01H, 00H, 02H, 88H, 02H
		DB	 88H, 02H, 88H, 02H, 88H, 02H
		DB	 00H, 03H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 01H
		DB	 00H, 02H, 00H, 02H, 00H, 02H
		DB	 00H, 02H, 00H, 02H, 00H, 02H
		DB	 00H, 02H, 00H, 02H, 00H, 02H
		DB	 00H, 02H, 00H, 02H, 00H, 02H
		DB	 00H, 02H, 00H, 02H, 00H, 02H
		DB	 00H, 02H, 00H, 03H, 88H, 04H
		DB	 88H, 03H, 88H, 03H, 88H, 02H
		DB	 88H, 02H, 88H, 02H, 88H, 02H
		DB	 88H, 02H, 88H, 02H, 88H, 02H
		DB	 88H, 02H, 88H, 02H, 88H, 02H
		DB	 88H, 02H, 88H, 02H, 88H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 01H
		DB	 00H, 05H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 01H
		DB	 00H, 03H, 00H, 03H, 00H, 03H
		DB	 00H, 03H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 02H
		DB	 00H, 03H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 02H, 00H, 02H
		DB	 00H, 02H, 00H, 02H, 00H, 02H
		DB	 00H, 02H, 00H, 02H, 00H, 02H
		DB	 00H, 03H, 00H, 03H, 00H, 03H
		DB	 00H, 03H, 00H, 03H, 00H, 03H
		DB	 00H, 03H, 00H, 03H, 00H, 03H
		DB	 00H, 03H, 00H, 03H, 00H, 01H
		DB	 00H, 02H, 88H, 02H, 88H, 03H
		DB	 88H, 04H, 88H, 01H, 00H, 01H
		DB	 00H, 03H, 00H, 01H, 00H, 01H
		DB	 00H, 02H, 00H, 01H, 00H, 01H
		DB	 00H, 02H, 88H, 02H, 88H, 02H
		DB	 88H, 02H, 88H, 02H, 00H, 02H
		DB	 00H, 01H, 00H, 01H, 00H, 02H
		DB	 88H, 02H, 88H, 02H, 88H, 02H
		DB	 88H, 02H, 88H, 02H, 88H, 02H
		DB	 88H, 02H, 88H, 02H, 00H, 02H
		DB	 00H, 02H, 00H, 02H, 00H, 02H
		DB	 00H, 02H, 00H, 02H, 00H, 02H
		DB	 00H, 03H, 00H, 03H, 00H, 03H
		DB	 00H, 02H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 02H
		DB	 66H, 02H, 66H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 01H, 00H, 01H
		DB	 00H, 01H, 00H, 02H, 88H, 02H
		DB	 88H

;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_6		PROC	NEAR
		PUSH	AX
		PUSH	BX
		PUSH	BP
		PUSH	DI
		PUSH	DS
		PUSH	SI
		PUSH	ES
		PUSH	CX
		MOV	BX,DI
		MOV	DI,OFFSET DATA_71
LOC_16:
		MOV	ES:[BX],SI
;*		ADD	BX,2
		DB	 83H,0C3H, 02H		;  Fixup - byte match
		DEC	CX
;*		CMP	CX,0
		DB	 83H,0F9H, 00H		;  Fixup - byte match
		JNZ	LOC_17			; Jump if not zero
		JMP	LOC_31
LOC_17:
		MOV	BP,BX
		XOR	BX,BX			; Zero register
		MOV	BL,[SI]
		SHL	BX,1			; Shift w/zeros fill
		PUSH	ES
		MOV	AX,CS
		MOV	ES,AX
		MOV	AX,ES:[BX+DI]
		POP	ES
		CMP	AH,88H
		JE	LOC_18			; Jump if equal
		CMP	AH,66H			; 'f'
		JE	LOC_24			; Jump if equal
		JMP	SHORT LOC_30
LOC_18:
		MOV	BL,[SI+1]
		MOV	BH,BL
		AND	BL,0C0H
		CMP	BL,0
		JE	LOC_19			; Jump if equal
		CMP	BL,0C0H
		JE	LOC_21			; Jump if equal
		CMP	BL,40H			; '@'
		JE	LOC_22			; Jump if equal
		CMP	BL,80H
		JE	LOC_23			; Jump if equal
LOC_19:
		AND	BH,7
		CMP	BH,6
		JNE	LOC_21			; Jump if not equal
LOC_20:
		ADD	AL,2
		JMP	SHORT LOC_30
LOC_21:
		JMP	SHORT LOC_30
LOC_22:
		INC	AL
		JMP	SHORT LOC_30
LOC_23:
		JMP	SHORT LOC_20
LOC_24:
		MOV	BL,[SI+1]
		MOV	BH,BL
		AND	BL,38H			; '8'
		CMP	BL,0
		JE	LOC_27			; Jump if equal
		CMP	BL,8
		JNE	LOC_29			; Jump if not equal
		CMP	BYTE PTR [SI],0F6H
		JE	LOC_25			; Jump if equal
		CMP	BYTE PTR [SI],0F7H
		JE	LOC_26			; Jump if equal
		JMP	SHORT LOC_29
LOC_25:
		INC	AL
		JMP	SHORT LOC_29
LOC_26:
		ADD	AL,2
		JMP	SHORT LOC_29
LOC_27:
		CMP	BYTE PTR [SI],0F6H
		JE	LOC_28			; Jump if equal
		INC	AL
LOC_28:
		INC	AL
		JMP	SHORT LOC_29
LOC_29:
		JMP	SHORT LOC_18
LOC_30:
		XOR	AH,AH			; Zero register
		ADD	SI,AX
		MOV	BX,BP
		JMP	LOC_16
LOC_31:
		POP	CX
		POP	ES
		POP	SI
		POP	DS
		POP	DI
		POP	BP
		POP	BX
		POP	AX
		RETN
SUB_6		ENDP


;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_7		PROC	NEAR
		XOR	BH,BH			; Zero register
		XOR	CL,CL			; Zero register
		MOV	BL,[SI]
		SHL	BX,1			; Shift w/zeros fill
		ADD	BX,DATA_41E
		MOV	DI,[BX]
;*		CMP	DI,0
		DB	 83H,0FFH, 00H		;  Fixup - byte match
		JZ	LOC_38			; Jump if zero
		MOV	AX,SI
		MOV	CH,[DI]
		INC	CH
LOC_32:
		INC	DI
		MOV	BL,[DI]
		XOR	BH,BH			; Zero register
		ADD	SI,BX
LOC_33:
		INC	DI
		CMP	CL,3
		JE	LOC_37			; Jump if equal
		MOV	BH,[DI]
		CMP	BH,66H			; 'f'
		JE	LOC_34			; Jump if equal
		CMP	BH,[SI]
		JNE	LOC_35			; Jump if not equal
LOC_34:
		INC	SI
		INC	CL
		JMP	SHORT LOC_33
LOC_35:
		INC	DI
		INC	CL
		CMP	CL,3
		JNE	LOC_35			; Jump if not equal
;*		ADD	DI,2
		DB	 83H,0C7H, 02H		;  Fixup - byte match
LOC_36:
		INC	DI
		CMP	BYTE PTR [DI],0
		JNE	LOC_36			; Jump if not equal
		INC	DI
		CMP	CH,[DI]
		JE	LOC_38			; Jump if equal
		XOR	CL,CL			; Zero register
		MOV	SI,AX
		JMP	SHORT LOC_32
LOC_37:
		MOV	DX,[DI]
;*		ADD	DI,2
		DB	 83H,0C7H, 02H		;  Fixup - byte match
		STC				; Set carry flag
		RETN
LOC_38:
		CLC				; Clear carry flag
		RETN
SUB_7		ENDP

DATA_72		DB	0

;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_8		PROC	NEAR
		PUSH	BX
		MOV	CS:DATA_72,0
		XOR	DX,DX			; Zero register
		MOV	BX,2710H
		DIV	BX			; ax,dx rem=dx:ax/reg
		OR	AL,AL			; Zero ?
		JNZ	LOC_39			; Jump if not zero
		MOV	AL,20H			; ' '
		JMP	SHORT LOC_40
LOC_39:
		MOV	CS:DATA_72,1
		ADD	AL,30H			; '0'
LOC_40:
		STOSB				; Store al to es:[di]
		MOV	AX,DX
		XOR	DX,DX			; Zero register
		MOV	BX,3E8H
		DIV	BX			; ax,dx rem=dx:ax/reg
		CMP	CS:DATA_72,1
		JE	LOC_41			; Jump if equal
		OR	AL,AL			; Zero ?
		JNZ	LOC_41			; Jump if not zero
		MOV	AL,20H			; ' '
		JMP	SHORT LOC_42
LOC_41:
		MOV	CS:DATA_72,1
		ADD	AL,30H			; '0'
LOC_42:
		STOSB				; Store al to es:[di]
		MOV	AX,DX
		XOR	DX,DX			; Zero register
		MOV	BX,64H
		DIV	BX			; ax,dx rem=dx:ax/reg
		CMP	CS:DATA_72,1
		JE	LOC_43			; Jump if equal
		OR	AL,AL			; Zero ?
		JNZ	LOC_43			; Jump if not zero
		MOV	AL,20H			; ' '
		JMP	SHORT LOC_44
LOC_43:
		MOV	CS:DATA_72,1
		ADD	AL,30H			; '0'
LOC_44:
		STOSB				; Store al to es:[di]
		MOV	AX,DX
		XOR	DX,DX			; Zero register
		MOV	BX,0AH
		DIV	BX			; ax,dx rem=dx:ax/reg
		CMP	CS:DATA_72,1
		JE	LOC_45			; Jump if equal
		OR	AL,AL			; Zero ?
		JNZ	LOC_45			; Jump if not zero
		MOV	AL,20H			; ' '
		JMP	SHORT LOC_46
LOC_45:
		ADD	AL,30H			; '0'
LOC_46:
		STOSB				; Store al to es:[di]
		MOV	AL,DL
		ADD	AL,30H			; '0'
		STOSB				; Store al to es:[di]
		XOR	AL,AL			; Zero register
		STOSB				; Store al to es:[di]
		POP	BX
		RETN
SUB_8		ENDP

DATA_73		DB	7
		DB	0AH, 'AISCAN Change ! Memory has '
		DB	'Virus !', 0DH, 0AH, 0
DATA_75		DB	7
		DB	0AH, 'AISCAN Check Error !', 0DH, 0AH
		DB	0

;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_9		PROC	NEAR
		PUSH	DS
		PUSH	ES
		MOV	DX,SI
		MOV	AX,3D00H
		INT	21H			; DOS Services  ah=function 3Dh
						;  open file, al=mode,name@ds:dx
		MOV	BX,AX
		MOV	AX,1220H
		INT	2FH			; DOS Internal services
						;*  undocumented function
		JC	LOC_47			; Jump if carry Set
		MOV	BL,ES:[DI]
		MOV	AX,1216H
		INT	2FH			; DOS Internal services
						;*  undocumented function
		JC	LOC_47			; Jump if carry Set
                ; FIXED: THAT IS NOT IMPORTANT
                ; CMP     WORD PTR ES:[DI+11H],17B9H      ; FILE LEN = 6073
                ; JNE     LOC_48                  ; Jump if not equal [reset system]
		MOV	AH,3EH
		INT	21H			; DOS Services  ah=function 3Eh
						;  close file, bx=file handle
		POP	ES
		POP	DS
		RETN
LOC_47:
		MOV	AH,3EH
		INT	21H			; DOS Services  ah=function 3Eh
						;  close file, bx=file handle
		PUSH	CS
		POP	DS
		MOV	SI,OFFSET DATA_75
		MOV	BL,0AH
		CALL	SUB_1
		POP	ES
		POP	DS
		RETN
LOC_48:
		PUSH	CS
		POP	DS
		MOV	SI,OFFSET DATA_73
		MOV	BL,0AH
		CALL	SUB_1
		CALL	SUB_3
		DB	0
DATA_77		DB	0
DATA_78		DB	0
DATA_79		DB	0
DATA_80		DB	0
DATA_81		DB	0
DATA_82		DB	0
DATA_83		DB	0
DATA_84		DB	0
DATA_85		DB	0
SUB_9		ENDP


;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_10		PROC	NEAR
		XOR	AH,AH			; Zero register
		MOV	SI,OFFSET DATA_127
LOC_49:
		INC	SI
		MOV	AL,[SI]
		CMP	AL,0DH
		JE	LOC_51			; Jump if equal
		CMP	AL,20H			; ' '
		JE	LOC_50			; Jump if equal
		MOV	AH,1
		CMP	AL,2FH			; '/'
		JE	LOC_52			; Jump if equal
		CMP	AL,7AH			; 'z'
		JA	LOC_49			; Jump if above
		CMP	AL,61H			; 'a'
		JB	LOC_49			; Jump if below
		AND	BYTE PTR [SI],0DFH
		JMP	SHORT LOC_49
LOC_50:
		MOV	BYTE PTR [SI],0
		JMP	SHORT LOC_49
LOC_51:
		MOV	WORD PTR [SI],0FF00H
		RETN
LOC_52:
		PUSH	SI
LOC_53:
		INC	SI
		MOV	AL,[SI]
		CMP	AL,0DH
		JE	LOC_54			; Jump if equal
		CMP	AL,7AH			; 'z'
		JA	LOC_53			; Jump if above
		CMP	AL,61H			; 'a'
		JB	LOC_53			; Jump if below
		AND	AL,0DFH
		MOV	[SI],AL
		JMP	SHORT LOC_53
LOC_54:
		POP	SI
		MOV	BYTE PTR [SI],0
LOC_55:
		INC	SI
		MOV	AL,[SI]
		MOV	BYTE PTR [SI],0FFH
		CMP	AL,0DH
		JE	LOC_51			; Jump if equal
		CMP	AL,3FH			; '?'
		JE	LOC_56			; Jump if equal
		CMP	AL,42H			; 'B'
		JE	LOC_57			; Jump if equal
		CMP	AL,44H			; 'D'
		JE	LOC_59			; Jump if equal
		CMP	AL,46H			; 'F'
		JE	LOC_60			; Jump if equal
		CMP	AL,47H			; 'G'
		JE	LOC_61			; Jump if equal
		CMP	AL,4CH			; 'L'
		JE	LOC_62			; Jump if equal
		JMP	SHORT LOC_65
LOC_56:
		MOV	BYTE PTR CS:[5F5H],1
		JMP	SHORT LOC_55
LOC_57:
		CMP	BYTE PTR [SI+1],43H	; 'C'
		JNE	LOC_58			; Jump if not equal
		MOV	CS:DATA_78,1
		MOV	BYTE PTR [SI+1],0
		JMP	SHORT LOC_55
LOC_58:
		MOV	CS:DATA_77,1
		JMP	SHORT LOC_55
LOC_59:
		MOV	CS:DATA_79,1
		JMP	SHORT LOC_55
LOC_60:
		MOV	CS:DATA_80,1
		JMP	SHORT LOC_55
LOC_61:
		MOV	CS:DATA_81,1
		MOV	BYTE PTR [SI+1],0
		JMP	SHORT LOC_55
LOC_62:
		CMP	BYTE PTR [SI+1],41H	; 'A'
		JNE	LOC_63			; Jump if not equal
		MOV	CS:DATA_83,1
		MOV	CS:DATA_82,1
		MOV	BYTE PTR [SI+1],0
		JMP	SHORT LOC_55
LOC_63:
		CMP	BYTE PTR [SI+1],4FH	; 'O'
		JNE	LOC_64			; Jump if not equal
		MOV	CS:DATA_82,1
		MOV	BYTE PTR [SI+1],0
LOC_64:
		JMP	LOC_55
LOC_65:
		CMP	AL,50H			; 'P'
		JNE	LOC_66			; Jump if not equal
		MOV	CS:DATA_84,1
		JMP	LOC_55
LOC_66:
		CMP	AL,53H			; 'S'
		JNE	LOC_67			; Jump if not equal
		MOV	CS:DATA_85,1
		JMP	LOC_55
LOC_67:
		JMP	LOC_55
SUB_10		ENDP

DATA_86		DW	0
		DB	 50H,0B8H,0D9H, 03H, 2EH,0A3H
		DB	0F0H, 06H, 58H, 2EH,0FFH, 16H
		DB	0F0H, 06H,0CBH
DATA_87		DW	0
		DB	 50H,0B8H, 1FH, 00H, 2EH,0A3H
		DB	 01H, 07H, 58H, 2EH,0FFH, 16H
		DB	 01H, 07H,0CBH
DATA_88		DW	0
		DB	 50H,0B8H, 18H, 09H, 2EH,0A3H
		DB	 12H, 07H, 58H, 2EH,0FFH, 16H
		DB	 12H, 07H,0CBH
DATA_89		DD	00000H
DATA_91		DB	0
DATA_92		DB	0DH, 0AH, 'User break !', 0DH, 0AH
		DB	0

;ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ
;
;                       External Entry Point
;
;ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ

INT_23H_ENTRY	PROC	FAR
		PUSH	AX
		PUSH	BX
		PUSH	CX
		PUSH	DX
		PUSH	BP
		PUSH	DS
		PUSH	SI
		PUSH	ES
		PUSH	DI
		PUSHF				; Push flags
		MOV	AX,3301H
		MOV	DL,CS:DATA_91
		INT	21H			; DOS Services  ah=function 33h
						;  set ctrl-break flag dl=off/on
		PUSH	CS
		POP	DS
		MOV	SI,OFFSET DATA_92	; ('')
		MOV	BL,7
		CALL	SUB_1
		CMP	CS:DATA_82,1
		JNE	LOC_68			; Jump if not equal
		MOV	BX,CS:DATA_112
		MOV	DX,OFFSET DATA_92	; ('')
		MOV	CX,10H
		MOV	AH,40H
		INT	21H			; DOS Services  ah=function 40h
						;  write file  bx=file handle
						;   cx=bytes from ds:dx buffer
		XOR	CX,CX			; Zero register
		MOV	AH,40H
		INT	21H			; DOS Services  ah=function 40h
						;  write file  bx=file handle
						;   cx=bytes from ds:dx buffer
		MOV	AH,3EH
		INT	21H			; DOS Services  ah=function 3Eh
						;  close file, bx=file handle
LOC_68:
		POPF				; Pop flags
		POP	DI
		POP	ES
		POP	SI
		POP	DS
		POP	BP
		POP	DX
		POP	CX
		POP	BX
		POP	AX
		JMP	CS:DATA_89
DATA_93		DD	00000H
INT_23H_ENTRY	ENDP


;ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ
;
;                       External Entry Point
;
;ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ

INT_24H_ENTry	PROC	FAR
		CMP	AH,18H
		JNE	LOC_69			; Jump if not equal
		MOV	AL,3
		IRET				; Interrupt return
INT_24H_ENTry	ENDP

LOC_69:
		PUSH	AX
		PUSH	BX
		PUSH	CX
		PUSH	DX
		PUSH	BP
		PUSH	DS
		PUSH	SI
		PUSH	ES
		PUSH	DI
		PUSHF				; Push flags
		MOV	AX,920H
		MOV	BX,7
		MOV	CX,50H
		INT	10H			; Video display   ah=functn 09h
						;  set char al & attrib bl @curs
						;   cx=# of chars to replicate
		POPF				; Pop flags
		POP	DI
		POP	ES
		POP	SI
		POP	DS
		POP	BP
		POP	DX
		POP	CX
		POP	BX
		POP	AX
		JMP	CS:DATA_93
			                        ;* No entry point to code
		IRET				; Interrupt return

;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_11		PROC	NEAR
		MOV	SI,OFFSET DATA_126
		MOV	DX,SI
		CMP	WORD PTR [SI+1],3AH
		JNE	LOC_70			; Jump if not equal
;*		ADD	SI,2
		DB	 83H,0C6H, 02H		;  Fixup - byte match
		MOV	CS:DATA_85,1
		JMP	SHORT LOC_71
LOC_70:
		INC	SI
		CMP	BYTE PTR [SI],0
		JNE	LOC_70			; Jump if not equal
		CMP	BYTE PTR [SI-1],5CH	; '\'
		JE	LOC_72			; Jump if equal
		MOV	AH,4EH			; 'N'
		MOV	CX,27H
		INT	21H			; DOS Services  ah=function 4Eh
						;  find 1st filenam match @ds:dx
		JNC	LOC_73			; Jump if carry=0
LOC_71:
		MOV	BYTE PTR [SI],5CH	; '\'
		INC	SI
LOC_72:
		MOV	WORD PTR [SI],2E2AH
		MOV	WORD PTR [SI+2],2AH
		MOV	SI,OFFSET DATA_128
		MOV	WORD PTR [SI],2E2AH
		MOV	WORD PTR [SI+2],2AH
		CLC				; Clear carry flag
		RETN
LOC_73:
		MOV	DI,OFFSET DATA_131
		MOV	SI,OFFSET DATA_126
LOC_74:
		LODSB				; String [si] to al
		OR	AL,AL			; Zero ?
		JZ	LOC_75			; Jump if zero
		STOSB				; Store al to es:[di]
		JMP	SHORT LOC_74
LOC_75:
		STOSB				; Store al to es:[di]
		STC				; Set carry flag
		RETN
SUB_11		ENDP


;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_12		PROC	NEAR
		MOV	DI,5BH
LOC_76:
		CMP	SI,DI
		JE	LOC_78			; Jump if equal
		DEC	SI
		CMP	BYTE PTR [SI],5CH	; '\'
		JNE	LOC_76			; Jump if not equal
		INC	SI
		PUSH	SI
		MOV	DI,OFFSET DATA_128
LOC_77:
		LODSB				; String [si] to al
		STOSB				; Store al to es:[di]
		OR	AL,AL			; Zero ?
		JNZ	LOC_77			; Jump if not zero
		POP	SI
		MOV	WORD PTR [SI],2E2AH
		MOV	WORD PTR [SI+2],2AH
		RETN
LOC_78:
		MOV	DI,OFFSET DATA_128
LOC_79:
		LODSB				; String [si] to al
		STOSB				; Store al to es:[di]
		OR	AL,AL			; Zero ?
		JNZ	LOC_79			; Jump if not zero
		MOV	AH,19H
		INT	21H			; DOS Services  ah=function 19h
						;  get default drive al  (0=a:)
		ADD	AL,41H			; 'A'
		MOV	AH,3AH			; ':'
		MOV	SI,DATA_43E
		MOV	[SI],AX
		MOV	BYTE PTR [SI+2],5CH	; '\'
;*		ADD	SI,3
		DB	 83H,0C6H, 03H		;  Fixup - byte match
		XOR	DL,DL			; Zero register
		MOV	AH,47H
		INT	21H			; DOS Services  ah=function 47h
						;  get present dir,drive dl,1=a:
						;   ds:si=ASCIIZ directory name
LOC_80:
		CMP	BYTE PTR [SI],0
		JE	LOC_81			; Jump if equal
		INC	SI
		JMP	SHORT LOC_80
LOC_81:
		CMP	BYTE PTR [SI-1],5CH	; '\'
		JE	LOC_82			; Jump if equal
		MOV	BYTE PTR [SI],5CH	; '\'
		INC	SI
LOC_82:
		MOV	WORD PTR [SI],2E2AH
		MOV	WORD PTR [SI+2],2AH
		RETN
SUB_12		ENDP


;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_13		PROC	NEAR
		MOV	SI,OFFSET DATA_122
		XOR	AH,AH			; Zero register
		MOV	AL,[SI]
		SUB	AL,30H			; '0'
		MOV	BX,2710H
		MUL	BX			; dx:ax = reg * ax
		MOV	WORD PTR CS:DATA_95+2,AX
		XOR	AH,AH			; Zero register
		MOV	AL,[SI+1]
		SUB	AL,30H			; '0'
		MOV	BX,3E8H
		MUL	BX			; dx:ax = reg * ax
		ADD	WORD PTR CS:DATA_95+2,AX
		XOR	AH,AH			; Zero register
		MOV	AL,[SI+2]
		SUB	AL,30H			; '0'
		MOV	BX,64H
		MUL	BX			; dx:ax = reg * ax
		ADD	WORD PTR CS:DATA_95+2,AX
		XOR	AH,AH			; Zero register
		MOV	AL,[SI+3]
		SUB	AL,30H			; '0'
		MOV	BX,0AH
		MUL	BX			; dx:ax = reg * ax
		ADD	WORD PTR CS:DATA_95+2,AX
		XOR	AH,AH			; Zero register
		MOV	AL,[SI+4]
		SUB	AL,30H			; '0'
		ADD	WORD PTR CS:DATA_95+2,AX
;*		ADD	SI,5
		DB	 83H,0C6H, 05H		;  Fixup - byte match
		XOR	AH,AH			; Zero register
		MOV	AL,[SI]
		SUB	AL,30H			; '0'
		MOV	BX,2710H
		MUL	BX			; dx:ax = reg * ax
		MOV	CS:DATA_95,AX
		XOR	AH,AH			; Zero register
		MOV	AL,[SI+1]
		SUB	AL,30H			; '0'
		MOV	BX,3E8H
		MUL	BX			; dx:ax = reg * ax
		ADD	CS:DATA_95,AX
		XOR	AH,AH			; Zero register
		MOV	AL,[SI+2]
		SUB	AL,30H			; '0'
		MOV	BX,64H
		MUL	BX			; dx:ax = reg * ax
		ADD	CS:DATA_95,AX
		XOR	AH,AH			; Zero register
		MOV	AL,[SI+3]
		SUB	AL,30H			; '0'
		MOV	BX,0AH
		MUL	BX			; dx:ax = reg * ax
		ADD	CS:DATA_95,AX
		XOR	AH,AH			; Zero register
		MOV	AL,[SI+4]
		SUB	AL,30H			; '0'
		ADD	CS:DATA_95,AX
		RETN
SUB_13		ENDP

DATA_95		DW	0, 0

;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_14		PROC	NEAR
		PUSHF				; Push flags
		CALL	DWORD PTR CS:DATA_95
		RETN
SUB_14		ENDP


;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_15		PROC	NEAR
		MOV	SI,0A8H
		MOV	AH,2AH
		INT	21H			; DOS Services  ah=function 2Ah
						;  get date, cx=year, dh=month
						;   dl=day, al=day-of-week 0=SUN
		PUSH	DX
		XOR	DX,DX			; Zero register
		MOV	AX,CX
		MOV	BX,3E8H
		DIV	BX			; ax,dx rem=dx:ax/reg
		MOV	[SI+8],AL
		ADD	BYTE PTR [SI+8],30H	; '0'
		MOV	AX,DX
		MOV	BL,64H			; 'd'
		DIV	BL			; al, ah rem = ax/reg
		MOV	[SI+9],AL
		ADD	BYTE PTR [SI+9],30H	; '0'
		MOV	AL,AH
		XOR	AH,AH			; Zero register
		MOV	BL,0AH
		DIV	BL			; al, ah rem = ax/reg
		MOV	[SI+0AH],AL
		ADD	BYTE PTR [SI+0AH],30H	; '0'
		MOV	[SI+0BH],AH
		ADD	BYTE PTR [SI+0BH],30H	; '0'
		POP	DX
		XOR	AH,AH			; Zero register
		MOV	AL,DH
		MOV	BL,0AH
		DIV	BL			; al, ah rem = ax/reg
		MOV	[SI+2],AL
		ADD	BYTE PTR [SI+2],30H	; '0'
		MOV	[SI+3],AH
		ADD	BYTE PTR [SI+3],30H	; '0'
		XOR	AH,AH			; Zero register
		MOV	AL,DL
		MOV	BL,0AH
		DIV	BL			; al, ah rem = ax/reg
		MOV	[SI+5],AL
		ADD	BYTE PTR [SI+5],30H	; '0'
		MOV	[SI+6],AH
		ADD	BYTE PTR [SI+6],30H	; '0'
		MOV	AH,2CH
		INT	21H			; DOS Services  ah=function 2Ch
						;  get time, cx=hrs/min, dx=sec
		XOR	AH,AH			; Zero register
		MOV	AL,CH
		MOV	BL,0AH
		DIV	BL			; al, ah rem = ax/reg
		MOV	[SI+0EH],AL
		ADD	BYTE PTR [SI+0EH],30H	; '0'
		MOV	[SI+0FH],AH
		ADD	BYTE PTR [SI+0FH],30H	; '0'
		XOR	AH,AH			; Zero register
		MOV	AL,CL
		MOV	BL,0AH
		DIV	BL			; al, ah rem = ax/reg
		MOV	[SI+11H],AL
		ADD	BYTE PTR [SI+11H],30H	; '0'
		MOV	[SI+12H],AH
		ADD	BYTE PTR [SI+12H],30H	; '0'
		MOV	BX,CS:DATA_112
		MOV	DX,SI
		MOV	CX,1EH
		MOV	AH,40H
		INT	21H			; DOS Services  ah=function 40h
						;  write file  bx=file handle
						;   cx=bytes from ds:dx buffer
		RETN
SUB_15		ENDP


;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_16		PROC	NEAR
		PUSH	DS
		PUSH	ES
		MOV	SI,OFFSET DATA_166+0BH	; ('S')
		MOV	BL,0DH
		CALL	SUB_1
		MOV	DI,OFFSET DATA_166+19H	; ('r')
		MOV	DI,ES:[DI]
LOC_83:
		CMP	WORD PTR ES:[DI],0FFFFH
		JE	LOC_85			; Jump if equal
		MOV	DS,ES:[DI]
		MOV	SI,ES:[DI+2]
;*		ADD	DI,8
		DB	 83H,0C7H, 08H		;  Fixup - byte match
		LODSW				; String [si] to ax
		CMP	AX,ES:[DI-4]
		JNE	LOC_84			; Jump if not equal
		LODSW				; String [si] to ax
		CMP	AX,ES:[DI-2]
		JE	LOC_86			; Jump if equal
LOC_84:
		INC	DI
		CMP	BYTE PTR ES:[DI],0
		JNE	LOC_84			; Jump if not equal
		INC	DI
		JMP	SHORT LOC_83
LOC_85:
		POP	ES
		POP	DS
		MOV	SI,OFFSET DATA_166+3	; (' ')
		MOV	BL,0DH
		CALL	SUB_1
		RETN
LOC_86:
		POP	ES
		POP	DS
		MOV	SI,DATA_39E
		MOV	BL,0DH
		CALL	SUB_1
		CALL	SUB_2
		MOV	SI,DATA_40E
		MOV	BL,0DH
		CALL	SUB_1
		RETN
SUB_16		ENDP


;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_17		PROC	NEAR
		MOV	DX,OFFSET DATA_179
		MOV	AH,40H			; '@'
		MOV	CX,0CH
		INT	21H			; DOS Services  ah=function 40h
						;  write file  bx=file handle
						;   cx=bytes from ds:dx buffer
		MOV	DI,OFFSET DATA_129
		PUSH	DI
		assume	ds:SEG_B
		MOV	AX,DATA_137
		CALL	SUB_8
		POP	DX
		MOV	AH,40H			; '@'
		MOV	CX,5
		INT	21H			; DOS Services  ah=function 40h
						;  write file  bx=file handle
						;   cx=bytes from ds:dx buffer
		MOV	DX,OFFSET DATA_180
		MOV	AH,40H			; '@'
		MOV	CX,8
		INT	21H			; DOS Services  ah=function 40h
						;  write file  bx=file handle
						;   cx=bytes from ds:dx buffer
		MOV	DX,OFFSET DATA_182
		MOV	AH,40H			; '@'
		MOV	CX,0AH
		INT	21H			; DOS Services  ah=function 40h
						;  write file  bx=file handle
						;   cx=bytes from ds:dx buffer
		MOV	DI,OFFSET DATA_129
		PUSH	DI
		MOV	AX,DATA_149
		CALL	SUB_8
		POP	DX
		MOV	AH,40H			; '@'
		MOV	CX,5
		INT	21H			; DOS Services  ah=function 40h
						;  write file  bx=file handle
						;   cx=bytes from ds:dx buffer
		MOV	DX,OFFSET DATA_183
		MOV	AH,40H			; '@'
		MOV	CX,0EH
		INT	21H			; DOS Services  ah=function 40h
						;  write file  bx=file handle
						;   cx=bytes from ds:dx buffer
		MOV	DX,OFFSET DATA_185
		MOV	AH,40H			; '@'
		MOV	CX,0AH
		INT	21H			; DOS Services  ah=function 40h
						;  write file  bx=file handle
						;   cx=bytes from ds:dx buffer
		MOV	DI,OFFSET DATA_129
		PUSH	DI
		MOV	AX,DATA_150
		CALL	SUB_8
		POP	DX
		MOV	AH,40H			; '@'
		MOV	CX,5
		INT	21H			; DOS Services  ah=function 40h
						;  write file  bx=file handle
						;   cx=bytes from ds:dx buffer
		MOV	DX,OFFSET DATA_180
		MOV	AH,40H			; '@'
		MOV	CX,8
		INT	21H			; DOS Services  ah=function 40h
						;  write file  bx=file handle
						;   cx=bytes from ds:dx buffer
		RETN
SUB_17		ENDP

DATA_97		DB	0
DATA_98		DW	0
DATA_99		DW	0
DATA_100	DW	0
DATA_101	DW	0
DATA_102	DW	0			; segment storage

;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_18		PROC	NEAR
		MOV	CS:DATA_99,DI
		MOV	CS:DATA_98,DI
		MOV	CS:DATA_97,CL
		MOV	CS:DATA_100,DX
		MOV	BP,ES
LOC_87:
		LODSB				; String [si] to al
		STOSB				; Store al to es:[di]
		OR	AL,AL			; Zero ?
		JNZ	LOC_87			; Jump if not zero
		MOV	DS,BP
		MOV	SI,CS:DATA_99
		CALL	SUB_28
		CMP	CS:DATA_97,1
		JE	LOC_88			; Jump if equal
		RETN
LOC_88:
		PUSH	ES
		MOV	AH,2FH
		INT	21H			; DOS Services  ah=function 2Fh
						;  get DTA ptr into es:bx
		MOV	CS:DATA_102,ES
		POP	ES
		MOV	CS:DATA_101,BX
LOC_89:
		assume	ds:SEG_A
		MOV	SI,CS:DATA_98
		MOV	DX,SI
;*		ADD	DX,42H
		DB	 83H,0C2H, 42H		;  Fixup - byte match
		MOV	AH,1AH
		INT	21H			; DOS Services  ah=function 1Ah
						;  set DTA(disk xfer area) ds:dx
		MOV	DX,SI
		MOV	BX,SI
;*		ADD	BX,57H
		DB	 83H,0C3H, 57H		;  Fixup - byte match
		MOV	AH,4EH			; 'N'
		MOV	CX,37H
		INT	21H			; DOS Services  ah=function 4Eh
						;  find 1st filenam match @ds:dx
		JC	LOC_92			; Jump if carry Set
LOC_90:
		MOV	AH,[BX]
		AND	AH,10H
		CMP	AH,10H
		JE	LOC_94			; Jump if equal
LOC_91:
		MOV	AH,4FH
		INT	21H			; DOS Services  ah=function 4Fh
						;  find next filename match
		JNC	LOC_90			; Jump if carry=0
LOC_92:
		MOV	AX,CS:DATA_99
		CMP	CS:DATA_98,AX
		JNE	LOC_93			; Jump if not equal
		JMP	LOC_100
LOC_93:
		SUB	CS:DATA_98,0C2H
		MOV	SI,CS:DATA_98
		MOV	DX,SI
		MOV	BX,SI
;*		ADD	BX,57H
		DB	 83H,0C3H, 57H		;  Fixup - byte match
;*		ADD	DX,42H
		DB	 83H,0C2H, 42H		;  Fixup - byte match
		MOV	AH,1AH
		INT	21H			; DOS Services  ah=function 1Ah
						;  set DTA(disk xfer area) ds:dx
		JMP	SHORT LOC_91
LOC_94:
		CMP	BYTE PTR [BX+9],2EH	; '.'
		JE	LOC_91			; Jump if equal
		ADD	CS:DATA_98,0C2H
		MOV	DI,CS:DATA_100
		ADD	DI,CS:DATA_99
		CMP	CS:DATA_98,DI
		JB	LOC_95			; Jump if below
		MOV	DS,CS:DATA_102
		MOV	DX,CS:DATA_101
		MOV	AH,1AH
		INT	21H			; DOS Services  ah=function 1Ah
						;  set DTA(disk xfer area) ds:dx
		STC				; Set carry flag
		RETN
LOC_95:
		MOV	DI,CS:DATA_98
LOC_96:
		LODSB				; String [si] to al
		OR	AL,AL			; Zero ?
		JZ	LOC_97			; Jump if zero
		STOSB				; Store al to es:[di]
		JMP	SHORT LOC_96
LOC_97:
;*		SUB	DI,3
		DB	 83H,0EFH, 03H		;  Fixup - byte match
		MOV	SI,BX
;*		ADD	SI,9
		DB	 83H,0C6H, 09H		;  Fixup - byte match
LOC_98:
		LODSB				; String [si] to al
		OR	AL,AL			; Zero ?
		JZ	LOC_99			; Jump if zero
		STOSB				; Store al to es:[di]
		JMP	SHORT LOC_98
LOC_99:
		MOV	WORD PTR [DI],2A5CH
		MOV	WORD PTR [DI+2],2A2EH
		MOV	BYTE PTR [DI+4],0
		MOV	SI,CS:DATA_98
		CALL	SUB_28
		JMP	LOC_89
LOC_100:
		MOV	DS,CS:DATA_102
		MOV	DX,CS:DATA_101
		MOV	AH,1AH
		INT	21H			; DOS Services  ah=function 1Ah
						;  set DTA(disk xfer area) ds:dx
		CLC				; Clear carry flag
		RETN
SUB_18		ENDP


;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_19		PROC	NEAR
		CMP	AH,3AH			; ':'
		JNE	LOC_103			; Jump if not equal
		MOV	BYTE PTR DS:DATA_12E,1
		CMP	AL,42H			; 'B'
		JA	LOC_101			; Jump if above
		CMP	AL,41H			; 'A'
		JB	LOC_RET_104		; Jump if below
		CALL	SUB_20
		JNC	LOC_RET_104		; Jump if carry=0
		JC	LOC_102			; Jump if carry Set
LOC_101:
		CMP	BYTE PTR DS:DATA_10E,1
		JE	LOC_RET_104		; Jump if equal
		CALL	SUB_23
		MOV	BYTE PTR DS:DATA_10E,1
		JNC	LOC_RET_104		; Jump if carry=0
LOC_102:
		MOV	SI,DATA_44E
		MOV	BL,0FH
		CALL	SUB_1
LOC_103:
		MOV	BYTE PTR DS:DATA_12E,0

LOC_RET_104:
		RETN
SUB_19		ENDP


;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_20		PROC	NEAR
		MOV	BYTE PTR DS:DATA_11E,0
		XOR	DH,DH			; Zero register
		MOV	DL,AL
		SUB	DL,41H			; 'A'
		MOV	SI,DS:DATA_5E
		MOV	WORD PTR [SI-4],4446H
		MOV	[SI-2],AL
		MOV	SI,DATA_47E
		MOV	[SI],AL
		MOV	SI,DATA_48E
		MOV	[SI],AL
		MOV	SI,DATA_49E
		MOV	[SI],AL
		MOV	SI,DATA_50E
		MOV	[SI],AL
		MOV	SI,DATA_46E
		MOV	BL,0DH
		CALL	SUB_1
LOC_105:
		INC	BYTE PTR DS:DATA_11E
		CMP	BYTE PTR DS:DATA_11E,3
		JBE	LOC_106			; Jump if below or =
		STC				; Set carry flag
		RETN
LOC_106:
		XOR	AH,AH			; Zero register
		INT	13H			; Disk  dl=drive ?  ah=func 00h
						;  reset disk, al=return status
		JC	LOC_105			; Jump if carry Set
		MOV	SI,CS:DATA_108
		MOV	BX,SI
		MOV	CX,1
		MOV	AX,201H
		CALL	SUB_14
		JC	LOC_105			; Jump if carry Set
		PUSH	DS
		PUSH	ES
		POP	DS
		CALL	SUB_7
		JC	LOC_107			; Jump if carry Set
		MOV	SI,CS:DATA_108
		CMP	BYTE PTR [SI],0EBH
		JNE	LOC_108			; Jump if not equal
		MOV	AL,[SI+1]
		XOR	AH,AH			; Zero register
		ADD	SI,AX
;*		ADD	SI,2
		DB	 83H,0C6H, 02H		;  Fixup - byte match
		CALL	SUB_7
		JNC	LOC_108			; Jump if carry=0
LOC_107:
		POP	DS
		MOV	SI,DATA_65E
		MOV	BL,0DH
		CALL	SUB_1
		CALL	SUB_2
		MOV	SI,DATA_66E
		MOV	BL,0DH
		CALL	SUB_1
		JMP	SHORT LOC_110
LOC_108:
		POP	DS
		MOV	SI,DATA_21E
		MOV	BL,0DH
		CALL	SUB_1
		CMP	CS:DATA_77,1
		JNE	LOC_109			; Jump if not equal
		MOV	BYTE PTR DS:DATA_12E,0
		CALL	SUB_21
		RETN
LOC_109:
		CMP	CS:DATA_78,1
		JNE	LOC_110			; Jump if not equal
		MOV	BYTE PTR DS:DATA_12E,0
		CALL	SUB_22
		RETN
LOC_110:
		CLC				; Clear carry flag
		RETN
SUB_20		ENDP


;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_21		PROC	NEAR
		MOV	SI,DATA_27E
		MOV	BL,0DH
		CALL	SUB_1
		MOV	DX,DATA_1E
		XOR	CX,CX			; Zero register
		MOV	AH,3CH
		INT	21H			; DOS Services  ah=function 3Ch
						;  create/truncate file @ ds:dx
		JC	LOC_RET_111		; Jump if carry Set
		MOV	BX,AX
		MOV	DX,CS:DATA_108
		PUSH	DS
		PUSH	ES
		POP	DS
		MOV	CX,200H
		MOV	AH,40H
		INT	21H			; DOS Services  ah=function 40h
						;  write file  bx=file handle
						;   cx=bytes from ds:dx buffer
		POP	DS
		JC	LOC_RET_111		; Jump if carry Set
		MOV	AH,3EH
		INT	21H			; DOS Services  ah=function 3Eh
						;  close file, bx=file handle
		JC	LOC_RET_111		; Jump if carry Set
		MOV	SI,DATA_21E
		MOV	BL,0DH
		CALL	SUB_1
		CLC				; Clear carry flag
		RETN

LOC_RET_111:
		RETN
SUB_21		ENDP


;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_22		PROC	NEAR
		PUSH	DS
		MOV	DX,DATA_1E
		MOV	AX,3D00H
		INT	21H			; DOS Services  ah=function 3Dh
						;  open file, al=mode,name@ds:dx
		JC	LOC_115			; Jump if carry Set
		MOV	BX,AX
		MOV	DX,CS:DATA_108
		MOV	SI,DX
		ADD	DX,OFFSET DATA_156+4	; ('C')
		MOV	DI,DX
		PUSH	ES
		POP	DS
		MOV	CX,200H
		MOV	AH,3FH
		INT	21H			; DOS Services  ah=function 3Fh
						;  read file, bx=file handle
						;   cx=bytes to ds:dx buffer
		JC	LOC_115			; Jump if carry Set
		MOV	AH,3EH
		INT	21H			; DOS Services  ah=function 3Eh
						;  close file, bx=file handle
		JC	LOC_115			; Jump if carry Set
		MOV	CX,200H
LOC_112:
		MOV	AH,[SI]
		CMP	AH,[DI]
		JNE	LOC_114			; Jump if not equal
		INC	DI
		INC	SI
		DEC	CX
		OR	CX,CX			; Zero ?
		JZ	LOC_113			; Jump if zero
		JMP	SHORT LOC_112
LOC_113:
		POP	DS
		MOV	SI,DATA_30E
		MOV	BL,0DH
		CALL	SUB_1
		MOV	SI,DATA_21E
		MOV	BL,0DH
		CALL	SUB_1
		CLC				; Clear carry flag
		RETN
LOC_114:
		POP	DS
		MOV	SI,DATA_34E
		MOV	BL,0FH
		CALL	SUB_1
		CLC				; Clear carry flag
		RETN
LOC_115:
		POP	DS
		MOV	SI,DATA_30E
		MOV	BL,0DH
		CALL	SUB_1
		STC				; Set carry flag
		RETN
SUB_22		ENDP


;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_23		PROC	NEAR
		SUB	AL,43H			; 'C'
		MOV	DL,AL
		ADD	DL,80H
		MOV	AH,10H
		PUSHF				; Push flags
		CALL	DWORD PTR CS:DATA_95
		JNC	LOC_116			; Jump if carry=0
		MOV	DL,80H
LOC_116:
		MOV	AL,DL
		MOV	DS:DATA_13E,AL
		SUB	AL,80H
		ADD	AL,43H			; 'C'
		MOV	SI,DS:DATA_5E
		MOV	WORD PTR [SI-4],4448H
		MOV	[SI-2],AL
		MOV	SI,DATA_52E
		MOV	[SI],AL
		MOV	SI,DATA_54E
		MOV	[SI],AL
		MOV	SI,DATA_56E
		MOV	[SI],AL
		MOV	SI,DATA_58E
		MOV	[SI],AL
		MOV	SI,DATA_59E
		MOV	[SI],AL
		MOV	SI,DATA_61E
		MOV	[SI],AL
		MOV	SI,DATA_63E
		MOV	[SI],AL
		MOV	SI,DATA_64E
		MOV	[SI],AL
		MOV	SI,DATA_51E
		MOV	BL,0DH
		CALL	SUB_1
		MOV	SI,CS:DATA_108
		MOV	BX,SI
		XOR	DH,DH			; Zero register
		MOV	DL,DS:DATA_13E
		MOV	AX,201H
		MOV	CX,1
		CALL	SUB_14
		JNC	LOC_117			; Jump if carry=0
		RETN
LOC_117:
		PUSH	DS
		PUSH	ES
		POP	DS
		CALL	SUB_7
		POP	DS
		JNC	LOC_118			; Jump if carry=0
		MOV	SI,DATA_65E
		MOV	BL,0DH
		CALL	SUB_1
		CALL	SUB_2
		MOV	SI,DATA_66E
		MOV	BL,0DH
		CALL	SUB_1
		JMP	SHORT LOC_119
LOC_118:
		MOV	SI,DATA_45E
		MOV	BL,0DH
		CALL	SUB_1
LOC_119:
		CMP	CS:DATA_77,1
		JNE	LOC_120			; Jump if not equal
		MOV	BYTE PTR DS:DATA_12E,0
		CALL	SUB_24
		JNC	LOC_121			; Jump if carry=0
		RETN
LOC_120:
		CMP	CS:DATA_78,1
		JNE	LOC_121			; Jump if not equal
		MOV	BYTE PTR DS:DATA_12E,0
		CALL	SUB_25
		JNC	LOC_121			; Jump if carry=0
		RETN
LOC_121:
		MOV	SI,DATA_53E
		MOV	BL,0DH
		CALL	SUB_1
		MOV	SI,CS:DATA_108
		ADD	SI,OFFSET DATA_151+12H	; (' ')
		MOV	CX,4

LOCLOOP_122:
		CMP	BYTE PTR ES:[SI],80H
		JE	LOC_123			; Jump if equal
		CMP	BYTE PTR ES:[SI+4],6
		JE	LOC_123			; Jump if equal
;*		ADD	SI,10H
		DB	 83H,0C6H, 10H		;  Fixup - byte match
		LOOP	LOCLOOP_122		; Loop if cx > 0

		STC				; Set carry flag
		RETN
LOC_123:
		MOV	DH,ES:[SI+1]
		MOV	CX,ES:[SI+2]
		MOV	SI,CS:DATA_108
		MOV	BX,SI
		MOV	DL,DS:DATA_13E
		MOV	AX,201H
		CALL	SUB_14
		JNC	LOC_124			; Jump if carry=0
		RETN
LOC_124:
		PUSH	DS
		PUSH	ES
		POP	DS
		CALL	SUB_7
		POP	DS
		JNC	LOC_125			; Jump if carry=0
		MOV	SI,DATA_65E
		MOV	BL,0DH
		CALL	SUB_1
		CALL	SUB_2
		MOV	SI,DATA_66E
		MOV	BL,0DH
		CALL	SUB_1
		JMP	SHORT LOC_126
LOC_125:
		MOV	SI,DATA_45E
		MOV	BL,0DH
		CALL	SUB_1
LOC_126:
		CMP	CS:DATA_77,1
		JNE	LOC_127			; Jump if not equal
		MOV	BYTE PTR DS:DATA_12E,0
		CALL	SUB_26
		RETN
LOC_127:
		CMP	CS:DATA_78,1
		JNE	LOC_128			; Jump if not equal
		MOV	BYTE PTR DS:DATA_12E,0
		CALL	SUB_27
		RETN
LOC_128:
		CLC				; Clear carry flag
		RETN
SUB_23		ENDP


;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_24		PROC	NEAR
		MOV	SI,DATA_55E
		MOV	BL,0DH
		CALL	SUB_1
		MOV	DX,DATA_42E
		XOR	CX,CX			; Zero register
		MOV	AH,3CH
		INT	21H			; DOS Services  ah=function 3Ch
						;  create/truncate file @ ds:dx
		JC	LOC_RET_129		; Jump if carry Set
		MOV	BX,AX
		MOV	DX,CS:DATA_108
		PUSH	DS
		PUSH	ES
		POP	DS
		MOV	CX,200H
		MOV	AH,40H
		INT	21H			; DOS Services  ah=function 40h
						;  write file  bx=file handle
						;   cx=bytes from ds:dx buffer
		POP	DS
		JC	LOC_RET_129		; Jump if carry Set
		MOV	AH,3EH
		INT	21H			; DOS Services  ah=function 3Eh
						;  close file, bx=file handle
		JC	LOC_RET_129		; Jump if carry Set
		MOV	SI,DATA_45E
		MOV	BL,0DH
		CALL	SUB_1

LOC_RET_129:
		RETN
SUB_24		ENDP


;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_25		PROC	NEAR
		PUSH	DS
		MOV	DX,DATA_42E
		MOV	AX,3D00H
		INT	21H			; DOS Services  ah=function 3Dh
						;  open file, al=mode,name@ds:dx
		JC	LOC_133			; Jump if carry Set
		MOV	BX,AX
		MOV	DX,CS:DATA_108
		MOV	SI,DX
		ADD	DX,OFFSET DATA_156+4	; ('C')
		MOV	DI,DX
		PUSH	ES
		POP	DS
		MOV	CX,200H
		MOV	AH,3FH
		INT	21H			; DOS Services  ah=function 3Fh
						;  read file, bx=file handle
						;   cx=bytes to ds:dx buffer
		JC	LOC_133			; Jump if carry Set
		MOV	AH,3EH
		INT	21H			; DOS Services  ah=function 3Eh
						;  close file, bx=file handle
		JC	LOC_133			; Jump if carry Set
		MOV	CX,200H
LOC_130:
		MOV	AH,[SI]
		CMP	AH,[DI]
		JNE	LOC_132			; Jump if not equal
		INC	DI
		INC	SI
		DEC	CX
		OR	CX,CX			; Zero ?
		JZ	LOC_131			; Jump if zero
		JMP	SHORT LOC_130
LOC_131:
		POP	DS
		MOV	SI,DATA_57E
		MOV	BL,0DH
		CALL	SUB_1
		MOV	SI,DATA_45E
		MOV	BL,0DH
		CALL	SUB_1
		CLC				; Clear carry flag
		RETN
LOC_132:
		POP	DS
		MOV	SI,DATA_36E
		MOV	BL,0FH
		CALL	SUB_1
		CLC				; Clear carry flag
		RETN
LOC_133:
		POP	DS
		MOV	SI,DATA_35E
		MOV	BL,0DH
		CALL	SUB_1
		STC				; Set carry flag
		RETN
SUB_25		ENDP


;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_26		PROC	NEAR
		MOV	SI,DATA_60E
		MOV	BL,0DH
		CALL	SUB_1
		MOV	DX,DATA_42E
		MOV	AX,3D02H
		INT	21H			; DOS Services  ah=function 3Dh
						;  open file, al=mode,name@ds:dx
		JC	LOC_RET_134		; Jump if carry Set
		MOV	BX,AX
		MOV	AX,4200H
		XOR	CX,CX			; Zero register
		MOV	DX,200H
		INT	21H			; DOS Services  ah=function 42h
						;  move file ptr, bx=file handle
						;   al=method, cx,dx=offset
		JC	LOC_RET_134		; Jump if carry Set
		MOV	DX,CS:DATA_108
		PUSH	DS
		PUSH	ES
		POP	DS
		MOV	CX,200H
		MOV	AH,40H
		INT	21H			; DOS Services  ah=function 40h
						;  write file  bx=file handle
						;   cx=bytes from ds:dx buffer
		POP	DS
		JC	LOC_RET_134		; Jump if carry Set
		MOV	AH,3EH
		INT	21H			; DOS Services  ah=function 3Eh
						;  close file, bx=file handle
		JC	LOC_RET_134		; Jump if carry Set
		MOV	SI,DATA_45E
		MOV	BL,0DH
		CALL	SUB_1
		CLC				; Clear carry flag

LOC_RET_134:
		RETN
SUB_26		ENDP


;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_27		PROC	NEAR
		PUSH	DS
		MOV	DX,DATA_42E
		MOV	AX,3D00H
		INT	21H			; DOS Services  ah=function 3Dh
						;  open file, al=mode,name@ds:dx
		JC	LOC_138			; Jump if carry Set
		MOV	BX,AX
		MOV	AX,4200H
		MOV	DX,200H
		XOR	CX,CX			; Zero register
		INT	21H			; DOS Services  ah=function 42h
						;  move file ptr, bx=file handle
						;   al=method, cx,dx=offset
		JC	LOC_138			; Jump if carry Set
		MOV	DX,CS:DATA_108
		MOV	SI,DX
		ADD	DX,OFFSET DATA_156+4	; ('C')
		MOV	DI,DX
		PUSH	ES
		POP	DS
		MOV	CX,200H
		MOV	AH,3FH
		INT	21H			; DOS Services  ah=function 3Fh
						;  read file, bx=file handle
						;   cx=bytes to ds:dx buffer
		JC	LOC_138			; Jump if carry Set
		MOV	AH,3EH
		INT	21H			; DOS Services  ah=function 3Eh
						;  close file, bx=file handle
		JC	LOC_138			; Jump if carry Set
		MOV	CX,200H
LOC_135:
		MOV	AH,[SI]
		CMP	AH,[DI]
		JNE	LOC_137			; Jump if not equal
		INC	DI
		INC	SI
		DEC	CX
		OR	CX,CX			; Zero ?
		JZ	LOC_136			; Jump if zero
		JMP	SHORT LOC_135
LOC_136:
		POP	DS
		MOV	SI,DATA_62E
		MOV	BL,0DH
		CALL	SUB_1
		MOV	SI,DATA_45E
		MOV	BL,0DH
		CALL	SUB_1
		CLC				; Clear carry flag
		RETN
LOC_137:
		POP	DS
		MOV	SI,DATA_38E
		MOV	BL,0FH
		CALL	SUB_1
		CLC				; Clear carry flag
		RETN
LOC_138:
		POP	DS
		MOV	SI,DATA_37E
		MOV	BL,0DH
		CALL	SUB_1
		STC				; Set carry flag
		RETN
SUB_27		ENDP


;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_28		PROC	NEAR
		PUSH	DS
		PUSH	ES
		MOV	AX,SEG_B
		MOV	ES,AX
		MOV	DI,OFFSET DATA_131
LOC_139:
		LODSB				; String [si] to al
		STOSB				; Store al to es:[di]
		OR	AL,AL			; Zero ?
		JNZ	LOC_139			; Jump if not zero
;*		SUB	DI,4
		DB	 83H,0EFH, 04H		;  Fixup - byte match
		MOV	BP,DI
		PUSH	ES
		POP	DS
		MOV	SI,OFFSET DATA_128
LOC_140:
		LODSB				; String [si] to al
		STOSB				; Store al to es:[di]
		OR	AL,AL			; Zero ?
		JNZ	LOC_140			; Jump if not zero
		PUSH	ES
		MOV	AH,2FH
		INT	21H			; DOS Services  ah=function 2Fh
						;  get DTA ptr into es:bx
		assume	ds:SEG_B
		MOV	DATA_136,ES
		MOV	DATA_135,BX
		POP	ES
		MOV	DX,OFFSET DATA_132
		MOV	AH,1AH
		INT	21H			; DOS Services  ah=function 1Ah
						;  set DTA(disk xfer area) ds:dx
		MOV	DX,OFFSET DATA_131
		MOV	CX,27H
		MOV	AH,4EH
		INT	21H			; DOS Services  ah=function 4Eh
						;  find 1st filenam match @ds:dx
		JC	LOC_147			; Jump if carry Set
LOC_141:
		MOV	SI,OFFSET DATA_133
		LODSB				; String [si] to al
		AND	AL,18H
		OR	AL,AL			; Zero ?
		JNZ	LOC_146			; Jump if not zero
		MOV	SI,OFFSET DATA_134
		MOV	DI,BP
LOC_142:
		LODSB				; String [si] to al
		STOSB				; Store al to es:[di]
		OR	AL,AL			; Zero ?
		JNZ	LOC_142			; Jump if not zero
		CMP	CS:DATA_80,1
		JNE	LOC_145			; Jump if not equal
		CMP	WORD PTR ES:[DI-4],5845H
		JNE	LOC_143			; Jump if not equal
		CMP	BYTE PTR ES:[DI-2],45H	; 'E'
		JNE	LOC_146			; Jump if not equal
		JZ	LOC_145			; Jump if zero
LOC_143:
		CMP	WORD PTR ES:[DI-4],4F43H
		JNE	LOC_144			; Jump if not equal
		CMP	BYTE PTR ES:[DI-2],4DH	; 'M'
		JNE	LOC_146			; Jump if not equal
		JZ	LOC_145			; Jump if zero
LOC_144:
		CMP	WORD PTR ES:[DI-4],5953H
		JNE	LOC_146			; Jump if not equal
		CMP	BYTE PTR ES:[DI-2],53H	; 'S'
		JNE	LOC_146			; Jump if not equal
LOC_145:
		CALL	SUB_29
LOC_146:
		MOV	AH,4FH
		INT	21H			; DOS Services  ah=function 4Fh
						;  find next filename match
		JNC	LOC_141			; Jump if carry=0
LOC_147:
		MOV	DX,DATA_135
		MOV	DS,DATA_136
		MOV	AH,1AH
		INT	21H			; DOS Services  ah=function 1Ah
						;  set DTA(disk xfer area) ds:dx
		POP	ES
		POP	DS
		RETN
SUB_28		ENDP


;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_29		PROC	NEAR
		PUSH	DS
		PUSH	ES
		PUSH	BP
		MOV	SI,0CAH
		MOV	AX,920H
		MOV	BX,0AH
		MOV	CX,50H
		INT	10H			; Video display   ah=functn 09h
						;  set char al & attrib bl @curs
						;   cx=# of chars to replicate
		CALL	SUB_1
		MOV	AX,0E0DH
		MOV	CX,1
		INT	10H			; Video display   ah=functn 0Eh
						;  write char al, teletype mode
		INC	DATA_137
		MOV	BYTE PTR CS:DATA_113,0
		MOV	BYTE PTR CS:DATA_114,0
		MOV	WORD PTR CS:DATA_118E,0
		MOV	DX,OFFSET DATA_131
		MOV	AX,3D00H
		INT	21H			; DOS Services  ah=function 3Dh
						;  open file, al=mode,name@ds:dx
		JC	LOC_149			; Jump if carry Set
		MOV	DATA_138,AX
		XCHG	BX,AX
		MOV	DX,CS:DATA_108
		MOV	DI,DX
		PUSH	DS
		MOV	AX,DATA_123
		MOV	ES,AX
		MOV	DS,AX
		MOV	AH,3FH			; '?'
		MOV	CX,CS:DATA_107
		INT	21H			; DOS Services  ah=function 3Fh
						;  read file, bx=file handle
						;   cx=bytes to ds:dx buffer
		POP	DS
		JC	LOC_149			; Jump if carry Set
		MOV	CS:DATA_110,AX
		OR	AX,AX			; Zero ?
		JZ	LOC_149			; Jump if zero
		CMP	WORD PTR ES:[DI],5A4DH
		JE	LOC_150			; Jump if equal
		CMP	WORD PTR ES:[DI],0FFFFH
		JNE	LOC_148			; Jump if not equal
		CMP	WORD PTR ES:[DI+2],0FFFFH
		JNE	LOC_148			; Jump if not equal
		MOV	DX,ES:[DI+6]
		MOV	DATA_140,DX
		XOR	CX,CX			; Zero register
		MOV	AX,4200H
		INT	21H			; DOS Services  ah=function 42h
						;  move file ptr, bx=file handle
						;   al=method, cx,dx=offset
		JC	LOC_149			; Jump if carry Set
		XOR	AX,AX			; Zero register
		MOV	BYTE PTR CS:DATA_114,2
		MOV	DATA_141,AX
		MOV	DATA_142,AX
		MOV	DATA_139,AX
		MOV	DATA_143,AX
		JMP	LOC_160
LOC_148:
		JMP	LOC_163
LOC_149:
		JMP	LOC_173
LOC_150:
		XOR	DX,DX			; Zero register
		MOV	AX,ES:[DI+14H]
		MOV	BX,10H
		DIV	BX			; ax,dx rem=dx:ax/reg
		MOV	CX,DX
		XOR	DX,DX			; Zero register
		ADD	AX,ES:[DI+16H]
		ADD	AX,ES:[DI+8]
		MUL	BX			; dx:ax = reg * ax
		MOV	BX,ES:[DI+8]
		MOV	DATA_143,BX
		MOV	BX,ES:[DI+0EH]
		MOV	DATA_141,BX
		MOV	BX,ES:[DI+10H]
		MOV	DATA_142,BX
		MOV	BX,ES:[DI+14H]
		MOV	DATA_140,BX
		ADD	AX,CX
;*		ADC	DX,0
		DB	 83H,0D2H, 00H		;  Fixup - byte match
		PUSH	AX
		PUSH	DX
		CMP	BYTE PTR ES:[DI+18H],40H	; '@'
		JE	LOC_151			; Jump if equal
		JMP	LOC_158
LOC_151:
		MOV	DX,ES:[DI+3CH]
		MOV	CX,ES:[DI+3EH]
		PUSH	DI
		MOV	DATA_148,DX
		MOV	AX,DX
		MOV	DI,DATA_31E
		STOSW				; Store ax to es:[di]
		MOV	DATA_147,CX
		MOV	AX,CX
		STOSW				; Store ax to es:[di]
		POP	DI
		MOV	AX,4200H
		MOV	BX,DATA_138
		INT	21H			; DOS Services  ah=function 42h
						;  move file ptr, bx=file handle
						;   al=method, cx,dx=offset
		JC	LOC_149			; Jump if carry Set
		PUSH	DS
		PUSH	ES
		POP	DS
		MOV	DX,DI
		MOV	CX,40H
		MOV	AH,3FH
		INT	21H			; DOS Services  ah=function 3Fh
						;  read file, bx=file handle
						;   cx=bytes to ds:dx buffer
		POP	DS
		CMP	WORD PTR ES:[DI],454EH
		JNE	LOC_153			; Jump if not equal
		POP	BX
		POP	BX
		MOV	BX,DATA_2E
		MOV	AX,ES:[BX+DI]
		DEC	AX
		MOV	BX,8
		MUL	BX			; dx:ax = reg * ax
		MOV	BX,DATA_4E
		MOV	CX,ES:[BX+DI]
		MOV	BX,1

LOCLOOP_152:
		SHL	BX,1			; Shift w/zeros fill
		LOOP	LOCLOOP_152		; Loop if cx > 0

		MOV	BP,BX
		MOV	CX,DX
		MOV	DX,AX
		MOV	AX,4201H
		MOV	BX,DATA_138
		INT	21H			; DOS Services  ah=function 42h
						;  move file ptr, bx=file handle
						;   al=method, cx,dx=offset
		PUSH	DS
		PUSH	ES
		POP	DS
		MOV	DX,DI
		MOV	CX,2
		MOV	AH,3FH
		INT	21H			; DOS Services  ah=function 3Fh
						;  read file, bx=file handle
						;   cx=bytes to ds:dx buffer
		POP	DS
		MOV	AX,ES:[DI]
		MUL	BP			; dx:ax = reg * ax
		MOV	CX,DX
		MOV	DX,AX
		JMP	SHORT LOC_159
LOC_153:
		CMP	WORD PTR ES:[DI],4550H
		JE	LOC_154			; Jump if equal
		JMP	SHORT LOC_158
LOC_154:
		POP	DX
		POP	DX
		MOV	DX,DATA_148
		MOV	CX,DATA_147
		ADD	DX,ES:[DI+14H]
;*		ADC	CX,0
		DB	 83H,0D1H, 00H		;  Fixup - byte match
;*		ADD	DX,18H
		DB	 83H,0C2H, 18H		;  Fixup - byte match
;*		ADC	CX,0
		DB	 83H,0D1H, 00H		;  Fixup - byte match
		PUSH	DI
		MOV	DI,DATA_33E
		MOV	AX,DX
		STOSW				; Store ax to es:[di]
		POP	DI
		MOV	BX,DATA_138
		MOV	AX,4200H
		INT	21H			; DOS Services  ah=function 42h
						;  move file ptr, bx=file handle
						;   al=method, cx,dx=offset
		MOV	AX,ES:[DI+6]
		PUSH	AX
		MOV	CL,28H			; '('
		MUL	CL			; ax = reg * al
		PUSH	DI
		MOV	DI,DATA_33E
		ADD	ES:[DI],AX
		POP	DI
		XCHG	CX,AX
		PUSH	DS
		PUSH	ES
		POP	DS
		MOV	DX,DI
		MOV	AH,3FH
		INT	21H			; DOS Services  ah=function 3Fh
						;  read file, bx=file handle
						;   cx=bytes to ds:dx buffer
		POP	DS
		POP	CX
		JC	LOC_161			; Jump if carry Set
		PUSH	DI
		PUSH	CX

LOCLOOP_155:
		CMP	WORD PTR ES:[DI],6C76H
		JNE	LOC_156			; Jump if not equal
		CMP	WORD PTR ES:[DI+2],6461H
		JE	LOC_157			; Jump if equal
LOC_156:
;*		ADD	DI,28H
		DB	 83H,0C7H, 28H		;  Fixup - byte match
		LOOP	LOCLOOP_155		; Loop if cx > 0

;*		SUB	DI,28H
		DB	 83H,0EFH, 28H		;  Fixup - byte match
LOC_157:
		POP	AX
		SUB	AX,CX
		MOV	DX,ES:[DI+14H]
		MOV	CX,ES:[DI+16H]
		MOV	DI,DATA_32E
		STOSW				; Store ax to es:[di]
		POP	DI
		JMP	SHORT LOC_159
LOC_158:
		POP	CX
		POP	DX
LOC_159:
		MOV	DATA_144,CX
		MOV	DATA_145,DX
		MOV	BX,DATA_138
		MOV	AX,4200H
		INT	21H			; DOS Services  ah=function 42h
						;  move file ptr, bx=file handle
						;   al=method, cx,dx=offset
		JNC	LOC_160			; Jump if carry=0
		JMP	LOC_173
LOC_160:
		PUSH	DS
		PUSH	ES
		POP	DS
		MOV	DX,DI
		MOV	AH,3FH			; '?'
		MOV	CX,CS:DATA_107
		INT	21H			; DOS Services  ah=function 3Fh
						;  read file, bx=file handle
						;   cx=bytes to ds:dx buffer
		POP	DS
		JC	LOC_161			; Jump if carry Set
		MOV	CS:DATA_110,AX
		OR	AX,AX			; Zero ?
		JNZ	LOC_162			; Jump if not zero
LOC_161:
		JMP	LOC_173
LOC_162:
		JMP	LOC_169
LOC_163:
		XOR	AX,AX			; Zero register
		MOV	DATA_144,AX
		MOV	DATA_145,AX
		MOV	DATA_143,AX
		MOV	BYTE PTR CS:DATA_114,1
		MOV	DATA_140,100H
		MOV	DATA_146,100H
		CMP	WORD PTR ES:[DI+20H],2044H
		JNE	LOC_164			; Jump if not equal
		CMP	WORD PTR ES:[DI+1],2C79H
		JNE	LOC_164			; Jump if not equal
		JMP	LOC_174
LOC_164:
		CMP	WORD PTR ES:[DI],8C0EH
		JNE	LOC_165			; Jump if not equal
		CMP	WORD PTR ES:[DI+2],5C8H
		JNE	LOC_165			; Jump if not equal
		CMP	WORD PTR ES:[DI+6],0B850H
		JNE	LOC_165			; Jump if not equal
		CMP	WORD PTR ES:[DI+8],100H
		JNE	LOC_165			; Jump if not equal
		CMP	WORD PTR ES:[DI+0AH],0CB50H
		JNE	LOC_165			; Jump if not equal
		MOV	AX,ES:[DI+4]
		MOV	CL,4
		SHL	AX,CL			; Shift w/zeros fill
		MOV	DATA_145,AX
		JMP	LOC_172
LOC_165:
		CMP	WORD PTR ES:[DI],0C08CH
		JNE	LOC_166			; Jump if not equal
		CMP	WORD PTR ES:[DI+2],12EH
		JNE	LOC_166			; Jump if not equal
		CMP	WORD PTR ES:[DI+4],0E06H
		JNE	LOC_166			; Jump if not equal
		CMP	WORD PTR ES:[DI+6],2E01H
		JNE	LOC_166			; Jump if not equal
		CMP	WORD PTR ES:[DI+8],2EFFH
		JNE	LOC_166			; Jump if not equal
		CMP	WORD PTR ES:[DI+0AH],10CH
		JNE	LOC_166			; Jump if not equal
		MOV	AX,ES:[DI+0EH]
		SUB	AX,10H
		MOV	CL,4
		SHL	AX,CL			; Shift w/zeros fill
		MOV	DATA_145,AX
		JMP	LOC_172
LOC_166:
		CMP	WORD PTR ES:[DI],0FF2EH
		JNE	LOC_167			; Jump if not equal
		CMP	BYTE PTR ES:[DI+2],36H	; '6'
		JNE	LOC_167			; Jump if not equal
		CMP	BYTE PTR ES:[DI+5],0C3H
		JNE	LOC_167			; Jump if not equal
		XOR	CX,CX			; Zero register
		MOV	DX,ES:[DI+3]
		SUB	DX,100H
		MOV	AX,4200H
		INT	21H			; DOS Services  ah=function 42h
						;  move file ptr, bx=file handle
						;   al=method, cx,dx=offset
		MOV	DX,OFFSET DATA_145
		MOV	AH,3FH			; '?'
		MOV	CX,2
		INT	21H			; DOS Services  ah=function 3Fh
						;  read file, bx=file handle
						;   cx=bytes to ds:dx buffer
		SUB	DATA_145,100H
		JMP	SHORT LOC_172
LOC_167:
		MOV	BX,DATA_20E
		MOV	SI,ES:[BX]
LOC_168:
		MOV	AX,ES:[SI]
		CMP	AX,0FFFFH
		JE	LOC_169			; Jump if equal
		MOV	BX,ES:[SI+2]
;*		ADD	SI,4
		DB	 83H,0C6H, 04H		;  Fixup - byte match
		CMP	ES:[DI],AL
		JNE	LOC_168			; Jump if not equal
		MOV	AL,BH
		XOR	BH,BH			; Zero register
		CMP	ES:[BX+DI],AH
		JNE	LOC_168			; Jump if not equal
		MOV	CS:DATA_113,AL
		ADD	DATA_145,BX
		ADD	CS:DATA_118E,BX
		JMP	SHORT LOC_172
LOC_169:
		MOV	AL,ES:[DI]
		CMP	AL,0E8H
		JE	LOC_170			; Jump if equal
		CMP	AL,0E9H
		JE	LOC_170			; Jump if equal
		CMP	AL,0EBH
		JE	LOC_171			; Jump if equal
		JMP	SHORT LOC_174
LOC_170:
		MOV	AX,DATA_145
		ADD	AX,ES:[DI+1]
		ADD	AX,3
		MOV	DX,AX
		SUB	DX,DATA_145
		ADD	CS:DATA_118E,DX
		MOV	DATA_145,AX
		JMP	SHORT LOC_172
LOC_171:
		XOR	AH,AH			; Zero register
		MOV	AL,ES:[DI+1]
		CBW				; Convrt byte to word
		ADD	AX,DATA_145
		ADD	AX,2
		MOV	DX,AX
		SUB	DX,DATA_145
		ADD	CS:DATA_118E,DX
		MOV	DATA_145,AX
LOC_172:
		MOV	BX,DATA_138
		MOV	CX,DATA_144
		MOV	DX,DATA_145
		MOV	AX,4200H
		INT	21H			; DOS Services  ah=function 42h
						;  move file ptr, bx=file handle
						;   al=method, cx,dx=offset
		JC	LOC_173			; Jump if carry Set
		PUSH	DS
		PUSH	ES
		POP	DS
		MOV	DX,DI
		MOV	AH,3FH			; '?'
		MOV	CX,CS:DATA_107
		INT	21H			; DOS Services  ah=function 3Fh
						;  read file, bx=file handle
						;   cx=bytes to ds:dx buffer
		POP	DS
		JC	LOC_173			; Jump if carry Set
		MOV	CS:DATA_110,AX
		OR	AX,AX			; Zero ?
		JZ	LOC_173			; Jump if zero
		JMP	SHORT LOC_169
LOC_173:
		MOV	BX,DATA_138
		MOV	AH,3EH
		INT	21H			; DOS Services  ah=function 3Eh
						;  close file, bx=file handle
		JMP	SHORT LOC_177
LOC_174:
		MOV	AX,CS:DATA_110
		CMP	AX,CS:DATA_107
		JE	LOC_176			; Jump if equal
		ADD	DI,AX
LOC_175:
		MOV	BYTE PTR ES:[DI],0
		INC	AX
		INC	DI
		CMP	AX,CS:DATA_107
		JNE	LOC_175			; Jump if not equal
LOC_176:
		MOV	DI,DATA_26E
		MOV	AX,DATA_141
		STOSW				; Store ax to es:[di]
		MOV	AX,DATA_139
		STOSW				; Store ax to es:[di]
		MOV	AX,DATA_140
		STOSW				; Store ax to es:[di]
		MOV	AX,DATA_143
		STOSW				; Store ax to es:[di]
		MOV	AX,CS:DATA_118E
		STOSW				; Store ax to es:[di]
		MOV	AX,DATA_138
		STOSW				; Store ax to es:[di]
		MOV	SI,CS:DATA_108
		PUSH	DS
		CALL	SUB_30
		POP	DS
		MOV	BX,DATA_138
		MOV	AH,3EH
		INT	21H			; DOS Services  ah=function 3Eh
						;  close file, bx=file handle
LOC_177:
		POP	BP
		POP	ES
		POP	DS
		RETN
SUB_29		ENDP


;ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß
;                              SUBROUTINE
;ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ

SUB_30		PROC	NEAR
		PUSH	ES
		POP	DS
LOC_178:
		PUSH	SI
		CALL	SUB_7
		POP	SI
		JC	LOC_181			; Jump if carry Set
		MOV	BX,OFFSET DATA_166+3	; (' ')
		MOV	CX,[BX]
		MOV	DI,CS:DATA_106
		CALL	SUB_6
		MOV	DI,OFFSET DATA_166+40H	; ('p')
		MOV	CX,[DI]
		MOV	DI,OFFSET DATA_165
		MOV	BX,[DI]
		MOV	WORD PTR CS:DATA_115+2,DS

LOCLOOP_179:
		MOV	AX,[BX]
		MOV	CS:DATA_115,AX
		PUSH	BX
		PUSH	CX
		PUSH	DS
		PUSH	ES
		MOV	BX,CS:DATA_106
		MOV	AH,CS:DATA_114
		MOV	AL,AH
		SHR	AL,1			; Shift w/zeros fill
		MOV	AL,CS:DATA_113
		CALL	DWORD PTR CS:DATA_115
		POP	ES
		POP	DS
		POP	CX
		POP	BX
		JC	LOC_181			; Jump if carry Set
;*		ADD	BX,2
		DB	 83H,0C3H, 02H		;  Fixup - byte match
		LOOP	LOCLOOP_179		; Loop if cx > 0

LOC_180:
		JMP	LOC_188
LOC_181:
		MOV	AX,SEG_B
		MOV	DS,AX
;*		CMP	DX,1
		DB	 83H,0FAH, 01H		;  Fixup - byte match
		JNZ	LOC_182			; Jump if not zero
		XOR	CX,CX			; Zero register
		MOV	DX,25F0H
		MOV	BX,DATA_138
		MOV	AX,4200H
		INT	21H			; DOS Services  ah=function 42h
						;  move file ptr, bx=file handle
						;   al=method, cx,dx=offset
		MOV	DX,CS:DATA_108
		MOV	SI,DX
		PUSH	ES
		POP	DS
		MOV	AH,3FH			; '?'
		MOV	CX,CS:DATA_107
		INT	21H			; DOS Services  ah=function 3Fh
						;  read file, bx=file handle
						;   cx=bytes to ds:dx buffer
		OR	AX,AX			; Zero ?
		JZ	LOC_180			; Jump if zero
		JMP	LOC_178
LOC_182:
		INC	DATA_149
		MOV	SI,OFFSET DATA_173+3	; ('')
		MOV	BL,0FH
		CALL	SUB_1
		CALL	SUB_2
		MOV	SI,OFFSET DATA_173+0EH	; (' ')
		MOV	BL,0FH
		CALL	SUB_1
		CMP	CS:DATA_82,1
		JNE	LOC_185			; Jump if not equal
		XOR	CX,CX			; Zero register
		MOV	SI,OFFSET DATA_131
LOC_183:
		LODSB				; String [si] to al
		INC	CX
		OR	AL,AL			; Zero ?
		JNZ	LOC_183			; Jump if not zero
		DEC	CX
		MOV	DX,OFFSET DATA_131
		MOV	BX,CS:DATA_112
		MOV	AH,40H
		INT	21H			; DOS Services  ah=function 40h
						;  write file  bx=file handle
						;   cx=bytes from ds:dx buffer
		MOV	DX,OFFSET DATA_173+5	; (' ')
		MOV	CX,8
		MOV	AH,40H
		INT	21H			; DOS Services  ah=function 40h
						;  write file  bx=file handle
						;   cx=bytes from ds:dx buffer
		PUSH	DS
		PUSH	ES
		POP	DS
		MOV	SI,DI
		XOR	CX,CX			; Zero register
LOC_184:
		LODSB				; String [si] to al
		INC	CX
		OR	AL,AL			; Zero ?
		JNZ	LOC_184			; Jump if not zero
		DEC	CX
		MOV	DX,DI
		MOV	AH,40H
		INT	21H			; DOS Services  ah=function 40h
						;  write file  bx=file handle
						;   cx=bytes from ds:dx buffer
		POP	DS
		MOV	DX,OFFSET DATA_173+0EH	; (' ')
		MOV	CX,6
		MOV	AH,40H
		INT	21H			; DOS Services  ah=function 40h
						;  write file  bx=file handle
						;   cx=bytes from ds:dx buffer
LOC_185:
		CMP	CS:DATA_79,1
		JNE	LOC_187			; Jump if not equal
		CMP	CS:DATA_82,1
		JNE	LOC_186			; Jump if not equal
		MOV	DX,OFFSET DATA_186+2CH	; (' ')
		MOV	CX,0BH
		MOV	AH,40H
		INT	21H			; DOS Services  ah=function 40h
						;  write file  bx=file handle
						;   cx=bytes from ds:dx buffer
LOC_186:
		MOV	DX,OFFSET DATA_131
		MOV	AX,4301H
		XOR	CX,CX			; Zero register
		INT	21H			; DOS Services  ah=function 43h
						;  set attrb cx, filename @ds:dx
		MOV	DX,OFFSET DATA_131
		MOV	AH,41H
		INT	21H			; DOS Services  ah=function 41h
						;  delete file, name @ ds:dx
		MOV	SI,OFFSET DATA_173+17H	; (' ')
		MOV	BL,0FH
		CALL	SUB_1
		INC	DATA_150
LOC_187:
		CMP	CS:DATA_82,1
		JNE	LOC_188			; Jump if not equal
		MOV	DX,OFFSET DATA_173+3	; ('')
		MOV	CX,2
		MOV	BX,CS:DATA_112
		MOV	AH,40H
		INT	21H			; DOS Services  ah=function 40h
						;  write file  bx=file handle
						;   cx=bytes from ds:dx buffer
LOC_188:
		MOV	BX,SEG SEG_B
		MOV	DS,BX
		MOV	BX,DATA_138
		MOV	AH,3EH
		INT	21H			; DOS Services  ah=function 3Eh
						;  close file, bx=file handle
		RETN
SUB_30		ENDP

DATA_103	DB	0, 0
DATA_104	DW	0
DATA_105	DW	0
DATA_106	DW	0
DATA_107	DW	0
DATA_108	DW	0
DATA_109	DW	0
DATA_110	DW	0
DATA_111	DW	0			; segment storage
DATA_112	DW	0
DATA_113	DB	0
DATA_114	DB	0
DATA_115	DW	0, 0
		DB	0, 0

;ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ
;
;                       PROGRAM	ENTRY POINT
;
;ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ


AISCAN		PROC	FAR

START:
		PUSH	DS
		MOV	AX,SEG_B
		MOV	DS,AX
		MOV	DX,OFFSET DATA_132
		MOV	AH,1AH
		INT	21H			; DOS Services  ah=function 1Ah
						;  set DTA(disk xfer area) ds:dx
		POP	DS
		MOV	CS:DATA_111,DS
		MOV	SI,DATA_3E
		MOV	DS,[SI]
		XOR	SI,SI			; Zero register
LOC_189:
		INC	SI
		MOV	AX,[SI]
		OR	AX,AX			; Zero ?
		JNZ	LOC_189			; Jump if not zero
;*		ADD	SI,4
		DB	 83H,0C6H, 04H		;  Fixup - byte match
		PUSH	SI
		MOV	AX,8041H
		INT	10H			; ??INT NON-STANDARD INTERRUPT
		MOV	AX,SEG_B
		MOV	ES,AX
		MOV	DI,OFFSET DATA_120
LOC_190:
		LODSB				; String [si] to al
		STOSB				; Store al to es:[di]
		OR	AL,AL			; Zero ?
		JNZ	LOC_190			; Jump if not zero
		POP	SI
		CALL	SUB_9
		MOV	DS,CS:DATA_111
		CALL	SUB_10
		PUSH	ES
		POP	DS
		OR	AH,AH			; Zero ?
		JZ	LOC_191			; Jump if zero
		CMP	BYTE PTR CS:[5F5H],1
		JNE	LOC_192			; Jump if not equal
LOC_191:
		MOV	CS:DATA_84,1
		MOV	SI,OFFSET DATA_186+37H	; ('+')
		MOV	BL,0AH
		CALL	SUB_1
		MOV	SI,OFFSET DATA_186+1A6H	; (' ')
		MOV	BL,7
		CALL	SUB_1
		MOV	AX,4C00H
		INT	21H			; DOS Services  ah=function 4Ch
						;  terminate with al=return code
LOC_192:
		MOV	SI,OFFSET DATA_186+37H	; ('+')
		MOV	BL,0AH
		CALL	SUB_1
		PUSH	DS
		PUSH	ES
		MOV	AX,SEG_A
		MOV	DS,AX
		MOV	AX,3523H
		INT	21H			; DOS Services  ah=function 35h
						;  get intrpt vector al in es:bx
		assume	ds:SEG_A
		MOV	WORD PTR CS:DATA_89+2,ES
		MOV	WORD PTR CS:DATA_89,BX
		MOV	AX,3524H
		INT	21H			; DOS Services  ah=function 35h
						;  get intrpt vector al in es:bx
		MOV	WORD PTR CS:DATA_93+2,ES
		MOV	WORD PTR CS:DATA_93,BX
		MOV	DX,OFFSET INT_23H_ENTRY
		MOV	AX,2523H
		INT	21H			; DOS Services  ah=function 25h
						;  set intrpt vector al to ds:dx
		MOV	DX,OFFSET INT_24H_ENTry
		MOV	AX,2524H
		INT	21H			; DOS Services  ah=function 25h
						;  set intrpt vector al to ds:dx
		MOV	AX,3300H
		INT	21H			; DOS Services  ah=function 33h
						;  get ctrl-break flag in dl
		MOV	CS:DATA_91,DL
		MOV	AX,3301H
		MOV	DL,1
		INT	21H			; DOS Services  ah=function 33h
						;  set ctrl-break flag dl=off/on
		POP	ES
		POP	DS
		MOV	ES,CS:DATA_111
		MOV	AX,ES
		MOV	BX,9247H
		SUB	BX,AX
		MOV	AH,4AH
		INT	21H			; DOS Services  ah=function 4Ah
						;  change memory allocation
						;   bx=bytes/16, es=mem segment
		MOV	AH,48H			; 'H'
		MOV	BX,0FFFFH
		INT	21H			; DOS Services  ah=function 48h
						;  allocate memory, bx=bytes/16
		assume	ds:SEG_B
		MOV	DATA_124,BX
		MOV	AH,48H
		INT	21H			; DOS Services  ah=function 48h
						;  allocate memory, bx=bytes/16
		MOV	DATA_123,AX
		MOV	SI,OFFSET DATA_120
		MOV	DX,SI
LOC_193:
		LODSB				; String [si] to al
		OR	AL,AL			; Zero ?
		JNZ	LOC_193			; Jump if not zero
		MOV	DATA_121,SI
		MOV	BYTE PTR [SI-7],4CH	; 'L'
		MOV	BYTE PTR [SI-4],43H	; 'C'
		MOV	WORD PTR [SI-3],444FH
		MOV	AX,3D00H
		INT	21H			; DOS Services  ah=function 3Dh
						;  open file, al=mode,name@ds:dx
		JNC	LOC_194			; Jump if carry=0
		MOV	SI,OFFSET DATA_155
		MOV	BL,0AH
		CALL	SUB_1
		JMP	LOC_214
LOC_194:
		MOV	BX,AX
		PUSH	DS
		MOV	DS,DATA_123
		MOV	DX,DATA_14E
		MOV	AH,3FH			; '?'
		MOV	CX,0FFFEH
		INT	21H			; DOS Services  ah=function 3Fh
						;  read file, bx=file handle
						;   cx=bytes to ds:dx buffer
		PUSH	AX
		MOV	CX,AX
		MOV	SI,DATA_15E

LOCLOOP_195:
		SUB	BYTE PTR [SI],42H	; 'B'
		INC	SI
		LOOP	LOCLOOP_195		; Loop if cx > 0

		MOV	SI,DATA_22E
		MOV	AX,6F2H
		MOV	[SI],AX
		MOV	AX,SEG_A
		MOV	[SI+2],AX
		MOV	AX,703H
		MOV	[SI+35H],AX
		MOV	AX,SEG_A
		MOV	[SI+37H],AX
		MOV	AX,714H
		MOV	[SI+3FH],AX
		MOV	AX,SEG_A
		MOV	[SI+41H],AX
		MOV	AX,[SI-12H]
		MOV	CS:DATA_115,AX
		MOV	WORD PTR CS:DATA_115+2,DS
		CLC				; Clear carry flag
		CALL	DWORD PTR CS:DATA_115
		MOV	AX,[SI-2]
		MOV	WORD PTR CS:DATA_103,AX
		MOV	AX,[SI+4]
		MOV	CS:DATA_105,AX
		MOV	AX,[SI+6]
		MOV	CS:DATA_107,AX
		MOV	AH,3EH
		INT	21H			; DOS Services  ah=function 3Eh
						;  close file, bx=file handle
		POP	AX
		POP	DS
		MOV	CL,4
		SHR	AX,CL			; Shift w/zeros fill
		INC	AX
		SHL	AX,CL			; Shift w/zeros fill
		ADD	AX,100H
		MOV	CS:DATA_104,AX
		ADD	AX,WORD PTR CS:DATA_103
		MOV	CS:DATA_106,AX
		ADD	AX,CS:DATA_105
		MOV	CS:DATA_108,AX
		ADD	AX,CS:DATA_107
		MOV	CS:DATA_109,AX
		MOV	CL,4
		SHR	AX,CL			; Shift w/zeros fill
		INC	AX
		ADD	AX,DATA_123
		MOV	DATA_125,AX
		MOV	SI,OFFSET DATA_156+53H	; ('')
		MOV	DI,260H
		MOV	AX,DATA_124
		MOV	CL,6
		SHR	AX,CL			; Shift w/zeros fill
		CALL	SUB_5
		MOV	ES,DATA_123
		MOV	SI,DATA_19E
		MOV	DX,CS:DATA_108
		MOV	ES:[SI],DX
		MOV	SI,DATA_24E
		MOV	DX,CS:DATA_109
		MOV	ES:[SI],DX
		MOV	SI,DATA_23E
		MOV	DX,CS:DATA_117E
		MOV	ES:[SI],DX
		MOV	SI,OFFSET DATA_156+6DH	; ('[')
		MOV	BL,0AH
		CALL	SUB_1
		PUSH	DS
		PUSH	ES
		POP	DS
		MOV	SI,DATA_25E
		MOV	BL,0AH
		CALL	SUB_1
		POP	DS
		MOV	SI,OFFSET DATA_156+82H	; (' ')
		MOV	BL,0AH
		CALL	SUB_1
		MOV	SI,OFFSET DATA_162
		MOV	DI,28CH
		MOV	BX,DATA_16E
		MOV	AX,ES:[BX]
		MOV	CX,AX
		CALL	SUB_5
		MOV	SI,OFFSET DATA_162
		MOV	DI,29BH
		MOV	BX,DATA_17E
		MOV	AX,ES:[BX]
		ADD	CX,AX
		CALL	SUB_5
		MOV	SI,OFFSET DATA_162
		MOV	DI,2AAH
		MOV	BX,DATA_18E
		MOV	AX,ES:[BX]
		ADD	CX,AX
		CALL	SUB_5
		MOV	SI,OFFSET DATA_163
		MOV	DI,2F4H
		MOV	AX,CX
		CALL	SUB_5
		MOV	SI,OFFSET DATA_162
		MOV	DI,2C0H
		MOV	BX,DATA_28E
		MOV	AX,ES:[BX]
		MOV	CX,AX
		CALL	SUB_5
		MOV	SI,OFFSET DATA_162
		MOV	DI,2D6H
		MOV	BX,DATA_29E
		MOV	AX,ES:[BX]
		ADD	CX,AX
		CALL	SUB_5
		MOV	SI,OFFSET DATA_163
		MOV	DI,2FEH
		MOV	AX,CX
		CALL	SUB_5
		CMP	CS:DATA_82,1
		JNE	LOC_198			; Jump if not equal
		MOV	SI,DATA_121
		MOV	BYTE PTR [SI-4],4CH	; 'L'
		MOV	WORD PTR [SI-3],474FH
		MOV	DX,OFFSET DATA_120
		MOV	AH,5BH			; '['
		XOR	CX,CX			; Zero register
		INT	21H			; DOS Services  ah=function 5Bh
						;  create new file, name @ ds:dx
						;   cx=file attribute bits
		JNC	LOC_196			; Jump if carry=0
		CMP	AX,50H
		JNE	LOC_196			; Jump if not equal
		MOV	AX,3D01H
		INT	21H			; DOS Services  ah=function 3Dh
						;  open file, al=mode,name@ds:dx
LOC_196:
		MOV	CS:DATA_112,AX
		MOV	BX,AX
		CMP	CS:DATA_83,1
		JNE	LOC_197			; Jump if not equal
		MOV	AX,4202H
		XOR	CX,CX			; Zero register
		XOR	DX,DX			; Zero register
		INT	21H			; DOS Services  ah=function 42h
						;  move file ptr, bx=file handle
						;   al=method, cx,dx=offset
LOC_197:
		CALL	SUB_15
LOC_198:
		XOR	BX,BX			; Zero register
		XOR	CX,CX			; Zero register
		MOV	AX,160AH
		INT	2FH			; ??INT NON-STANDARD INTERRUPT
		OR	AX,AX			; Zero ?
		JNZ	LOC_199			; Jump if not zero
		CMP	BX,400H
		JNE	LOC_199			; Jump if not equal
;*		CMP	CX,3
		DB	 83H,0F9H, 03H		;  Fixup - byte match
		JZ	LOC_200			; Jump if zero
LOC_199:
		MOV	SI,DATA_121
		MOV	WORD PTR [SI-4],4643H
		MOV	BYTE PTR [SI-2],47H	; 'G'
		MOV	DX,OFFSET DATA_120
		MOV	AX,3D00H
		INT	21H			; DOS Services  ah=function 3Dh
						;  open file, al=mode,name@ds:dx
		JC	LOC_200			; Jump if carry Set
		MOV	BX,AX
		MOV	DX,OFFSET DATA_122
		MOV	AH,3FH			; '?'
		MOV	CX,0BH
		INT	21H			; DOS Services  ah=function 3Fh
						;  read file, bx=file handle
						;   cx=bytes to ds:dx buffer
		MOV	AH,3EH
		INT	21H			; DOS Services  ah=function 3Eh
						;  close file, bx=file handle
		CALL	SUB_13
		MOV	SI,OFFSET DATA_151	; ('')
		MOV	BL,0FH
		CALL	SUB_1
		MOV	AX,WORD PTR CS:DATA_95+2
		CALL	SUB_4
		MOV	AH,2
		MOV	DL,3AH			; ':'
		INT	21H			; DOS Services  ah=function 02h
						;  display char dl
		MOV	AX,CS:DATA_95
		CALL	SUB_4
		MOV	SI,OFFSET DATA_151+4AH	; ('')
		MOV	BL,0FH
		CALL	SUB_1
		JMP	SHORT LOC_201
LOC_200:
		PUSH	ES
		MOV	AX,3513H
		INT	21H			; DOS Services  ah=function 35h
						;  get intrpt vector al in es:bx
		MOV	WORD PTR CS:DATA_95+2,ES
		POP	ES
		MOV	CS:DATA_95,BX
		MOV	SI,OFFSET DATA_151+2AH	; ('')
		MOV	BL,0FH
		CALL	SUB_1
LOC_201:
		XOR	AH,AH			; Zero register
		MOV	DL,80H
		CALL	SUB_14
		CMP	CS:DATA_81,1
		JNE	LOC_204			; Jump if not equal
		PUSH	DS
		POP	ES
		MOV	SI,OFFSET DATA_156+20H	; ('')
		MOV	BL,0DH
		CALL	SUB_1
		MOV	BYTE PTR DATA_130,0
LOC_202:
		INC	DATA_130
		CMP	BYTE PTR DATA_130,3
		JE	LOC_203			; Jump if equal
		XOR	AH,AH			; Zero register
		XOR	DH,DH			; Zero register
		INT	13H			; Disk  dl=drive 0  ah=func 00h
						;  reset disk, al=return status
		JC	LOC_202			; Jump if carry Set
		MOV	BX,8A2H
		MOV	AX,301H
		MOV	CX,1
		XOR	DX,DX			; Zero register
		CALL	SUB_14
		JC	LOC_202			; Jump if carry Set
		MOV	SI,OFFSET DATA_166+3	; (' ')
		MOV	BL,0DH
		CALL	SUB_1
		CALL	SUB_3
LOC_203:
		MOV	SI,OFFSET DATA_164
		MOV	BL,0FH
		CALL	SUB_1
		JMP	LOC_214
LOC_204:
		CALL	SUB_16
		MOV	DS,CS:DATA_111
		MOV	SI,DATA_9E
		MOV	BX,SEG SEG_B
		MOV	ES,BX
		MOV	DI,DATA_8E
LOC_205:
		INC	SI
LOC_206:
		CMP	BYTE PTR [SI],0
		JE	LOC_205			; Jump if equal
		CMP	BYTE PTR [SI],0FFH
		JNE	LOC_207			; Jump if not equal
		JMP	SHORT LOC_213
LOC_207:
		PUSH	ES
		PUSH	DI
LOC_208:
		LODSB				; String [si] to al
		STOSB				; Store al to es:[di]
		OR	AL,AL			; Zero ?
		JNZ	LOC_208			; Jump if not zero
		PUSH	DS
		PUSH	SI
		PUSH	ES
		POP	DS
		MOV	SI,DATA_7E
LOC_209:
		INC	SI
		MOV	AL,[SI]
		CMP	AL,2AH			; '*'
		JE	LOC_210			; Jump if equal
		CMP	AL,3FH			; '?'
		JE	LOC_210			; Jump if equal
		OR	AL,AL			; Zero ?
		JNZ	LOC_209			; Jump if not zero
		CALL	SUB_11
		JNC	LOC_211			; Jump if carry=0
		MOV	SI,5BH
		CALL	SUB_29
		POP	SI
		POP	DS
		POP	DI
		POP	ES
		JMP	SHORT LOC_206
LOC_210:
		CALL	SUB_12
LOC_211:
		MOV	ES,DS:DATA_6E
		MOV	SI,DATA_8E
		MOV	AX,[SI]
		CALL	SUB_19
		CMP	BYTE PTR DS:DATA_12E,0
		JE	LOC_212			; Jump if equal
		MOV	DX,DATA_8E
		MOV	AH,4EH			; 'N'
		MOV	CX,37H
		INT	21H			; DOS Services  ah=function 4Eh
						;  find 1st filenam match @ds:dx
		JC	LOC_212			; Jump if carry Set
		MOV	SI,DATA_8E
		MOV	CL,CS:DATA_85
		MOV	DI,CS:DATA_104
		MOV	DX,WORD PTR CS:DATA_103
		CALL	SUB_18
LOC_212:
		POP	SI
		POP	DS
		POP	DI
		POP	ES
		JMP	SHORT LOC_206
LOC_213:
		MOV	AX,SEG_B
		MOV	DS,AX
		MOV	AX,920H
		MOV	BX,7
		MOV	CX,50H
		INT	10H			; Video display   ah=functn 09h
						;  set char al & attrib bl @curs
						;   cx=# of chars to replicate
		MOV	SI,OFFSET DATA_178
		MOV	DI,4CCH
		MOV	AX,DATA_137
		CALL	SUB_5
		MOV	SI,OFFSET DATA_181
		MOV	DI,4E2H
		MOV	AX,DATA_149
		CALL	SUB_5
		MOV	SI,OFFSET DATA_184
		MOV	DI,4E2H
		MOV	AX,DATA_150
		CALL	SUB_5
		CMP	CS:DATA_82,1
		JNE	LOC_214			; Jump if not equal
		MOV	BX,CS:DATA_112
		CALL	SUB_17
		XOR	CX,CX			; Zero register
		MOV	AH,40H
		INT	21H			; DOS Services  ah=function 40h
						;  write file  bx=file handle
						;   cx=bytes from ds:dx buffer
		MOV	AH,3EH
		INT	21H			; DOS Services  ah=function 3Eh
						;  close file, bx=file handle
LOC_214:
		MOV	AX,920H
		MOV	BX,7
		MOV	CX,50H
		INT	10H			; Video display   ah=functn 09h
						;  set char al & attrib bl @curs
						;   cx=# of chars to replicate
		MOV	ES,DATA_123
		MOV	AH,49H
		INT	21H			; DOS Services  ah=function 49h
						;  release memory block, es=seg
		XOR	AL,AL			; Zero register
		CMP	DATA_149,0
;*		JE	LOC_215			;*Jump if equal
		DB	 74H, 05H		;  Fixup - byte match
		MOV	AL,1

AISCAN		ENDP

SEG_A		ENDS



;------------------------------------------------------------  SEG_B   ----

SEG_B		SEGMENT	PARA PUBLIC
		ASSUME CS:SEG_B  , DS:SEG_B , SS:STACK_SEG_C

                ; MOV     AX, [1A8H]
                ; MOV     AH, 4CH
                ; INT     21H
		DB	0A1H,0A8H, 01H,0B4H, 4CH,0CDH
		DB	 21H
		DB	0
DATA_120	DB	0
		DB	63 DUP (0)
DATA_121	DW	0
DATA_122	DB	0
		DB	10 DUP (0)
DATA_123	DW	0
DATA_124	DW	0
DATA_125	DW	0
DATA_126	DB	0
		DB	36 DUP (0)
DATA_127	DB	0
		DB	26 DUP (0)
DATA_128	DB	0
		DB	12 DUP (0)
DATA_129	DB	'[   -  -        :   ] AISCAN', 0DH
		DB	0AH, 0
DATA_130	DB	0
		DB	0, 0
DATA_131	DW	32 DUP (0)
; DTA
DATA_132	DB	0
		DB	20 DUP (0)

DATA_133	DB	0
		DB	8 DUP (0)
DATA_134	DB	0
		DB	97 DUP (0)
DATA_135	DW	0
DATA_136	DW	0			; segment storage
DATA_137	DW	0
DATA_138	DW	0
DATA_139	DW	0
DATA_140	DW	0
DATA_141	DW	0
DATA_142	DW	0
DATA_143	DW	0
DATA_144	DW	0
DATA_145	DW	0
		DB	0, 0
DATA_146	DW	0
DATA_147	DW	0
DATA_148	DW	0
DATA_149	DW	0
DATA_150	DW	0
DATA_151	DB	0AH, 'Call int 13h in [ Super ] m'
		DB	'ode, Address=', 0
		DB	0AH, 'Call int 13h in [ Normal ] '
		DB	'mode', 0DH, 0AH, 0DH, 0AH, 0
DATA_155	DB	7
DATA_156	DB	0AH, 'AISCAN Can', 27H, 't Find A'
		DB	'ISCLN.COD', 0DH, 0AH, 0
		DB	0AH, 'Generate BIOS int 13h addre'
		DB	'ss detector at drive A', 0
		DB	0AH, '[ Work Space : ', 0
		DB	0AH, 'K ]', 0
		DB	'K ]', 0
		DB	'[ AISCLN.COD ver 3.0', 0
		DB	' ]', 0AH, 0DH, 0AH, 0
DATA_162	DB	0EH
		DB	 53H, 63H, 61H, 6EH, 20H, 20H
		DB	 00H, 0EH
		DB	' Boot Virus', 0DH, 0AH
		DB	 00H, 0EH
		DB	' File Virus', 0DH, 0AH
		DB	 00H, 0EH
		DB	' Polymorphic Virus', 0DH, 0AH
		DB	 00H, 0EH
		DB	' [Mutation Engine]', 0DH, 0AH
		DB	 00H, 0EH
		DB	' (Virus Generator)', 0DH, 0AH
		DB	0
DATA_163	DB	3
		DB	 54H, 6FH, 74H, 61H, 6CH, 20H
		DB	 00H, 03H
		DB	' Virus', 0DH, 0AH
		DB	 00H, 03H, 0DH, 0AH, 00H
DATA_164	DB	20H
		DB	 45H, 72H, 72H, 6FH, 72H
DATA_165	DB	20H
		DB	 21H, 07H
DATA_166	DB	0DH, 0AH, 0
		DB	' OK !', 0DH, 0AH, 0
		DB	'Scan memory for Boot Virus', 0
		DB	'Scan Boot of Drive  ', 0
		DB	'Backup Boot of Drive  ', 0
		DB	'Compare Boot of Dr'
		DB	 69H, 76H, 65H, 20H, 20H, 00H
		DB	'Boot of Drive   Change !'
		DB	7
		DB	0DH, 0AH, 0
		DB	'Scan Master Boot of Hard Disk C', 0
		DB	'Scan Boot of Hard Disk C', 0
		DB	'Backup Master Boot of Hard Disk '
		DB	'C', 0
		DB	'Compare Master Boot of Hard Disk'
		DB	' C', 0
		DB	'Master Boot of Hard Disk C Chang'
		DB	'e !'
		DB	7
		DB	0DH, 0AH, 0
		DB	'Backup Boot of Hard Disk C', 0
		DB	'Compare Boot of Hard Disk C', 0
		DB	'Boot of Hard Disk C Change !'
		DB	7
DATA_173	DB	0DH, 0AH, 0
		DB	0DH, 0AH, '  Found ', 0
		DB	' Virus', 0DH, 0AH, 0
		DB	'  Deleted this Virus file', 0DH, 0AH
		DB	0
DATA_178	DB	0BH
		DB	0AH
DATA_179	DB	0DH, 0AH, '  Scanned ', 0
		DB	0BH
DATA_180	DB	' files', 0DH, 0AH, 0
DATA_181	DB	0BH
DATA_182	DB	'  Found   ', 0
		DB	0BH
DATA_183	DB	' Virus files', 0DH, 0AH, 0
DATA_184	DB	0BH
DATA_185	DB	20H
DATA_186	DB	' Deleted ', 0
		DB	0DH, 0AH, '  This is a ', 0
		DB	' compressed file', 0DH, 0AH, 0
		DB	' -> Deleted+--------- This is a '
		DB	'Public Domain (PD) Software ----'
		DB	'-----+', 0DH, 0AH, '|  AISCAN 3.'
		DB	'0 - An Artifical Intelligence Vi'
		DB	'rus Scanner   |', 0DH, 0AH, '|  '
		DB	'                                '
		DB	'                       |', 0DH, 0AH
		DB	'|  Written by Shichen Young     '
		DB	'                          |', 0DH
		DB	0AH, '|  04-16-1996             e'
		DB	'mail : shichen@hope.hinet.net  |'
		DB	0DH, 0AH, '+---------------------'
		DB	'--------------------------------'
		DB	'----+', 0DH, 0AH, 0
		DB	' Usage :', 0DH, 0AH, '       AIS'
		DB	'CAN [drive1] [drive2]... [/?][/B'
		DB	'|/BC]...', 0DH, 0AH, ' Option :', 0DH
		DB	0AH, '      /? - Display help scr'
		DB	'een', 0DH, 0AH, '      /B - Back'
		DB	'up disk system area to file', 0DH
		DB	0AH, '     /BC - Compare disk sys'
		DB	'tem area with file', 0DH, 0AH, ' '
		DB	'     /D - Delete virus file', 0DH
		DB	0AH, '      /F - Fast scan mode, '
		DB	'scan EXE, COM, SYS only', 0DH, 0AH
		DB	'      /G - Generate BIOS int 13h'
		DB	' address detector at drive A', 0DH
		DB	0AH, '     /LA - Append old Log f'
		DB	'ile', 0DH, 0AH, '     /LO - Over'
		DB	'write old Log file', 0DH, 0AH, ' '
		DB	'     /P - Pause at each page', 0DH
		DB	0AH, '      /S - Scan subdirector'
		DB	'y', 0DH, 0AH, 0AH, ' Please refe'
		DB	'r to AISCLN.DOC for more informa'
		DB	'tion', 0DH, 0AH, 0
		DB	 33H,0C0H, 8EH,0D8H,0BBH, 4CH
		DB	 00H, 8BH, 07H, 50H, 8BH, 47H
		DB	 02H, 50H, 58H,0E8H, 19H, 00H
		DB	12 DUP (90H)
		DB	 58H,0E8H, 09H, 00H, 32H,0E4H
		DB	0CDH, 16H,0EAH, 00H, 00H,0FFH
		DB	0FFH, 50H, 53H, 52H, 33H,0D2H
		DB	0BBH, 10H, 27H,0F7H,0F3H, 8BH
		DB	0DAH, 32H,0F6H, 8AH,0D0H, 80H
		DB	0C2H, 30H, 53H, 8AH,0C2H,0B4H
		DB	 0EH,0BBH, 07H, 00H,0B9H, 01H
		DB	 00H,0CDH, 10H, 5BH, 33H,0D2H
		DB	 8BH,0C3H,0BBH,0E8H, 03H,0F7H
		DB	0F3H, 8BH,0DAH, 32H,0F6H, 8AH
		DB	0D0H, 80H,0C2H, 30H, 53H, 8AH
		DB	0C2H,0B4H, 0EH,0BBH, 07H, 00H
		DB	0B9H, 01H, 00H,0CDH, 10H, 5BH
		DB	 33H,0D2H, 8BH,0C3H,0BBH, 64H
		DB	 00H,0F7H,0F3H, 8BH,0DAH, 32H
		DB	0F6H, 8AH,0D0H, 80H,0C2H, 30H
		DB	 53H, 8AH,0C2H,0B4H, 0EH,0BBH
		DB	 07H, 00H,0B9H, 01H, 00H,0CDH
		DB	 10H, 5BH, 33H,0D2H, 8BH,0C3H
		DB	0BBH, 0AH, 00H,0F7H,0F3H, 8BH
		DB	0DAH, 32H,0F6H, 8AH,0D0H, 80H
		DB	0C2H, 30H, 53H, 8AH,0C2H,0B4H
		DB	 0EH,0BBH, 07H, 00H,0B9H, 01H
		DB	 00H,0CDH, 10H, 5BH, 8AH,0D3H
		DB	 80H,0C2H, 30H, 53H, 8AH,0C2H
		DB	0B4H, 0EH,0BBH, 07H, 00H,0B9H
		DB	 01H, 00H,0CDH, 10H, 5BH, 5AH
		DB	 5BH, 58H,0C3H
		DB	11 DUP (0)

SEG_B		ENDS



;------------------------------------------------------  STACK_SEG_C   ----

STACK_SEG_C	SEGMENT	WORD STACK 'STACK'

		DB	1024 DUP (0)

STACK_SEG_C	ENDS



		END	START
