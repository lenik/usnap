; Quick Directory Switching
; DanSei / 1998.12.20

	.Model Small
	.286

	.Code
	Org 100h

Start:
        Jmp     Short Begin
        DB      0Dh, '/TopCroak Software/', 1Ah
Begin:
	Mov	AH, 9
	Lea	DX, Frame
	Int	21h
	Mov	AH, 8		; Direct Console Input -> AX
	Int	21h
	Xor	AH, AH
	Cmp	AL, 0Dh 	; Exit
	Jz	GoExit
	Cmp	AL, 20h 	; Default Choice
	Jnz	Check
	Xor	AL, AL		; Choice 0
Check:
	Cmp	AL, 39h
	Ja	GoExit
	And	AL, 0Fh 	; Get Choice
	Lea	BX, FuncTable
	Add	AL, AL		; AL * 2
	Add	BX, AX
	Call	Word Ptr [BX]
GoExit:
	Int	20h

        Org     140h

Frame:
        DB      9, 'Virus Research Lab', 9, 'Update : 1998.12.26', 9, 'Author : DanSei', 0Dh, 0Ah
        DB      9, 9, '0 - Virus Development', 0Dh, 0Ah
        DB      9, 9, '1 - One_Half', 9, '- 3544', 0Dh, 0Ah
        DB      9, 9, '2 - Lyceum', 9, '- 930', 0Dh, 0Ah
        DB      9, 9, '3 - Tongji', 9, '- 1655', 0Dh, 0Ah
        DB      9, 9, '4 - Grave-1', 9, '- 1550', 0Dh, 0Ah
        DB      9, 9, '5 - CIH', 9, 9, '- nnnn', 0Dh, 0Ah
	DB	24h

	Org	2A0h

FuncTable:
	DW	Func_0
	DW	Func_1
	DW	Func_2
	DW	Func_3
	DW	Func_4
	DW	Func_5
	DW	Func_6
	DW	Func_7
	DW	Func_8
	DW	Func_9
	Jmp	Short ChDir

ChDir	Proc	Near
	Mov	AH, 3Bh
	Int	21h
	Retn
ChDir	Endp

	Org	2C0h

Func_0	Proc	Near
	Lea	DX, Path_0
	Jmp	Short ChDir
Func_0	Endp

Func_1	Proc	Near
	Lea	DX, Path_1
	Jmp	Short ChDir
Func_1	Endp

Func_2	Proc	Near
	Lea	DX, Path_2
	Jmp	Short ChDir
Func_2	Endp

Func_3	Proc	Near
	Lea	DX, Path_3
	Jmp	Short ChDir
Func_3	Endp

Func_4	Proc	Near
	Lea	DX, Path_4
	Jmp	Short ChDir
Func_4	Endp

Func_5	Proc	Near
	Lea	DX, Path_5
	Jmp	Short ChDir
Func_5	Endp

Func_6	Proc	Near
	Lea	DX, Path_6
	Jmp	Short ChDir
Func_6	Endp

Func_7	Proc	Near
	Lea	DX, Path_7
	Jmp	Short ChDir
Func_7	Endp

Func_8	Proc	Near
	Lea	DX, Path_8
	Jmp	Short ChDir
Func_8	Endp

Func_9	Proc	Near
	Lea	DX, Path_9
	Jmp	Short ChDir
Func_9	Endp

	Org	300h

        Path_0  DB 'Develop', 0, '                     [0]'
        Path_1  DB 'OneHalf', 0, '                     [1]'
        Path_2  DB 'Lyceum', 0, '                      [2]'
        Path_3  DB 'Tongji', 0, '                      [3]'
        Path_4  DB 'Grave', 0, '                       [4]'
        Path_5  DB 'CIH', 0, '                         [5]'
        Path_6  DB '.', 0, '                           [6]'
        Path_7  DB '.', 0, '                           [7]'
        Path_8  DB '.', 0, '                           [8]'
        Path_9  DB '.', 0, '                           [9]'

                DB '(C) COPYRIGHT TOPCROAK SOFTWARE '
                DB 'AUTHOR : DANSEI   1998.12. CHINA'
                DB ' - * - ALL RIGHTS RESERVED - * -'

	End	Start
