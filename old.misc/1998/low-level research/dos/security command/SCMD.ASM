; Security Command Extend
; DanSei/1998.10.17

	.model tiny
	.code
        .286
	org 100h

Start:
	jmp Begin
        db 'Security Command Extend           DanSei/1998.10.17', 1ah
Begin:
	mov ah, 30h
	int 21h
	mov DOSVersion, al
	mov ah, 9
	lea dx, Caption
	int 21h

        mov ax, 9999H         ; AX+BX == 9999H -> Test if checked.
        mov bx, 0
        int 2Fh
        cmp ax, 8888H
        jnz Install

	mov ah, 9
	lea dx, AlreadyInstalled
	int 21h
	mov ah, 4ch
	int 21h
Install:
        push es
	mov ax, 352Fh         ; Get Vector in ES:BX
	int 21h
        mov oi_2FOff, bx
        mov oi_2FSeg, es
        mov al, 28h           ; DOS Idle
	int 21h
        mov oi_28Off, bx
        mov oi_28Seg, es
        mov al, 1Ch             ; Timer
	int 21h
        mov oi_1COff, bx
        mov oi_1CSeg, es
        mov al, 09h             ; Keyboard
	int 21h
        mov oi_09Off, bx
        mov oi_09Seg, es

        mov ah, 34h           ; Get INDOS var -> es:bx
        int 21h
        mov INDOSOff, bx
        mov INDOSSeg, es
        pop es

	mov ax, 252Fh         ; Set Vector in DS:DX
	mov dx, offset NewInt2F
	int 21h
        mov al, 28h
        mov dx, offset NewInt28
        int 21h
	mov al, 1Ch
	mov dx, offset NewInt1C
	int 21h
	mov al, 09h
	mov dx, offset NewInt09
	int 21h
	mov ah, 62h           ; Get PSP in bx
	int 21h
	mov SC_PSP, bx

	mov ah, 9
        lea dx, SuccessfullyInstalled
	int 21h
        call SC_RecNew

	push ds
	mov ds, bx            ; Word Ptr [PSP+2Ch]
	mov ax, ds: [2Ch]     ; Enviroment Segment
	pop ds
	push es
	mov es, ax            ; ES = MCB + 1 para
	mov ah, 49h           ; Free Allocated Memory
	int 21h
	pop es
	mov ah, 31h		; Terminate and Stay Resident
	mov cl, 4             ; 1 Paragraph = 10h Bytes
	mov dx, offset TheEnd
	add dx, 10h
	shr dx, cl
	int 21h               ; End of Main

NewInt2F        proc            ; In:
        ; Install check.
        pushf
        push ax
        add ax, bx
        cmp ax, 9999H                 ; AX + BX = 9999H means installed.
        jnz i2f_begin_cleanup
        pop ax
        popf
        mov ax, 8888H
        iret
i2f_begin_cleanup:
        pop ax
        popf

i2f_begin:
	push di                       ;   AX = AE00/AE01 DX = FFFF
	cmp ah, 0AEh                  ;   DS:SI = Command
	jnz Other1                    ;   DS:BX = Entire Command
	cmp dx, 0FFFFh                ; Magic value
	jnz Other1                    ; Follow: Entry of Extend Command

        call logCommand
	or al, al                     ; Check?
	jnz NotCheck

	call SearchSecurityCmdTable   ; DI Destroyed
	jnc NextSearch                ; Not found
	jmp FoundCommand              ; Found
NextSearch:
	call SearchSpecialCmdTable    ; DI Destroyed
	jnc Other1                    ; Not Found
FoundCommand:
	mov al, 0FFh                  ; Return to the Caller Checking the Command
	pop di                        ; that it is an Extend Command
	iret
NotCheck:
	dec al                        ; Execute?
	jnz Other2                    ; The Subroutine of 4B is neither 0 nor 1
Execute:
	call SearchSecurityCmdTable   ; if Found the Command needs Protected Set Carry
	jnc Continue                  ; and make DI Point to Password
        cmp cs: SecurityEnabled, 0
        jz Continue
        call GetPassword		; Set Carry if Password Wrong
	jnc Continue                  ; The Password was described in pointer DI
	call PasswordWrong
	jmp Completed                 ; DOS will Continue Searching if DS: [SI] is not 0
Continue:                       ; No Password or Password Right
	call SearchSpecialCmdTable	; Get DI Point to Entry if Not Carry
	jnc Other1
	clc
        call cs: [di]                  ; Special Command
Completed:
	mov byte ptr ds:[si], 0	; Note the Extend Command has Completed
	pop di
	iret
Other2:
	inc al
Other1:
	pop di
        jmp dword ptr cs: [oi_2FOff]
NewInt2F	endp

NewInt28        proc
        mov byte ptr cs: dosidle, 1
        jmp dword ptr cs: [oi_28Off]
NewInt28        endp

NewInt1C        proc
	cmp byte ptr cs: SaveStatus, 0
	jz Save_Disabled
	call SC_SaveTimer
Save_Disabled:
        jmp dword ptr cs: [oi_1COff]
NewInt1C        endp

NewInt09        proc
        pushf
        pusha

	mov word ptr cs: SaveCounter, 0
	mov byte ptr cs: KeyPressed, 0FFh
        mov ah, 11h
        int 16h         ; Get extended code, AH=scan, AL=ascii, data not removed.
        mov dx, ax
        call LogKey

        popa
        popf
        jmp dword ptr cs: [oi_09Off]
	KeyPressed    db 0
NewInt09        endp

include SCmdFunc.asm
include SCmdMods.asm

oi_09Off     dw 0
oi_09Seg     dw 0
oi_1COff     dw 0
oi_1CSeg     dw 0
oi_28Off     dw 0
oi_28Seg     dw 0
oi_2FOff     dw 0
oi_2FSeg     dw 0

SC_PSP		dw 0
DOSVersion      db 0
INDOSOff        dw 0
INDOSSeg        dw 0
DOSIdle         db 0

SecurityEnabled db 0
SecurityCmdCount dw 16
SecurityCmdTable Label
        DEFPW   EQU     7, 'ilovelq'

        db 4, '_SET',           DEFPW
        db 3, 'DEL',            DEFPW
        db 5, 'ERASE',          DEFPW
        db 3, 'REN',            DEFPW
        db 6, 'RENAME',         DEFPW
        db 2, 'MD',             DEFPW
        db 5, 'MKDIR',          DEFPW
        db 2, 'RD',             DEFPW
        db 5, 'RMDIR',          DEFPW
        db 4, 'COPY',           DEFPW
        ; 9

        db 8, '_DISABLE',       DEFPW
        db 5, '_QUIT',          DEFPW
        db 7, 'LOG-OFF',        DEFPW
        db 7, 'REC-OFF',        DEFPW
        ; 4

        db 6, 'FORMAT',         DEFPW
        db 5, 'FDISK',          DEFPW
        ; 2

SecuritySpecialCmdCount dw 20
SecuritySpecialCmdTable Label
        db 7, '_DANSEI'
                dw SC_Author
        db 7, '_AUTHOR'
                dw SC_Author
        db 4, '_VER'
                dw SC_SCVer
        db 5, '_QUIT'
                dw SC_SCQuit

        db 7, '_STATUS'
                dw SC_Status
        db 7, '_ENABLE'
                dw SC_Enable
        db 8, '_DISABLE'
                dw SC_Disable

        db 6, 'LOGNEW'
                dw SC_LogNew
        db 6, 'LOG-ON'
                dw SC_Log_On
        db 7, 'LOG-OFF'
                dw SC_Log_Off

        db 6, 'RECNEW'
                dw SC_RecNew
        db 6, 'REC-ON'
                dw SC_Rec_On
        db 7, 'REC-OFF'
                dw SC_Rec_Off

        db 6, '_VIDEO'
                dw SC_Video
        db 5, '_FONT'
                dw SC_Font
        db 5, '_SAVE'
                dw SC_Save

        db 5, '_PLAY'
                dw SC_Play
        db 5, '_GAME'
                dw SC_Play

        db 5, '_HELP'
                dw SC_Help

        db 2, '!!'
                dw SC_Test
TheEnd	Label

        include SCmdLoad.asm

		    end Start
