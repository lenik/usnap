SC_Author       proc
	push dx
	lea dx, Author
	call DisplayCodeString
	pop dx
	ret
	Author        db 'TopCroak Software   Author/DanSei', 0dh, 0ah, 'All rights reserved.', 0dh, 0ah, '$'
SC_Author       endp

SC_SCVer        proc
	push dx
	lea dx, Caption
	call DisplayCodeString
	pop dx
	ret
SC_SCVer        endp

SC_Status       proc
        push dx
        lea dx, SecurityHasDisabled
        cmp cs: SecurityEnabled, 0
        jz SCS_Show
        lea dx, SecurityHasEnabled
SCS_Show:
        call DisplayCodeString
        pop dx
        ret
SC_Status       endp

SC_Enable       proc
        mov cs: SecurityEnabled, 1
        push dx
        lea dx, SecurityHasEnabled
        call DisplayCodeString
        pop dx
        ret
SC_Enable       endp

SC_Disable      proc
        mov cs: SecurityEnabled, 0
        push dx
        lea dx, SecurityHasDisabled
        call DisplayCodeString
        pop dx
        ret
SC_Disable      endp

SC_LogNew       proc
        pusha
        push ds
        push cs
        pop ds
        lea dx, log_filename
        mov ah, 3ch             ; create file ds:dx, CX = attrib
        mov al, 0
        mov cx, 20h             ; archive mode
        int 21h                 ; return AX = file handle
        jc log_new_error
        mov bx, ax
        mov ah, 3eh
        int 21h
        lea dx, OpenNewOk
        jmp log_new_end
log_new_error:
        lea dx, OpenNewError
log_new_end:
        call displayCodeString
        pop ds
        popa
        ret
SC_LogNew       endp

SC_Log_On       proc
        mov cs: log_enabled, 1
        push dx
        lea dx, DTurnedOn
        call displayCodeString
        pop dx
        ret
SC_Log_On       endp

SC_Log_Off      proc
        mov cs: log_enabled, 0
        push dx
        lea dx, DTurnedOff
        call displayCodeString
        pop dx
        ret
SC_Log_Off      endp

SC_RecNew       proc
        pusha
        push ds
        push cs
        pop ds
        lea dx, rec_filename
        mov ah, 3ch             ; create file ds:dx, CX = attrib
        mov al, 0
        mov cx, 20h             ; archive mode
        int 21h                 ; return AX = file handle
        jc rec_new_error
        mov bx, ax
        mov ah, 3eh
        int 21h
        lea dx, OpenNewOk
        jmp rec_new_end
rec_new_error:
        lea dx, OpenNewError
rec_new_end:
        call displayCodeString
        pop ds
        popa
        ret
SC_RecNew       endp

SC_Rec_On       proc
        mov cs: rec_enabled, 1
        push dx
        lea dx, DTurnedOn
        call displayCodeString
        pop dx
        ret
SC_Rec_On       endp

SC_Rec_Off      proc
        mov cs: rec_enabled, 0
        push dx
        lea dx, DTurnedOff
        call displayCodeString
        pop dx
        ret
SC_Rec_Off      endp

SC_SCQuit       proc
	push ax
	push dx
	push ds
	push es
	push cs
	pop ds
	mov ah, 9
	lea dx, Removed
	int 21h
	mov ax, 252Fh         ; Set Vector in DS:DX
        mov dx, cs:oi_2FSeg
	mov ds, dx
        mov dx, cs:oi_2FOff
	int 21h
        mov al, 28h
        mov dx, cs:oi_28Seg
        mov ds, dx
        mov dx, cs:oi_28Off
        int 21h
	mov al, 1Ch
        mov dx, cs:oi_1CSeg
	mov ds, dx
        mov dx, cs:oi_1COff
	int 21h
	mov al, 09h
        mov dx, cs:oi_09Seg
	mov ds, dx
        mov dx, cs:oi_09Off
	int 21h
	mov ah, 49h           ; Free Allocated Memory
	mov dx, cs:SC_PSP
	mov es, dx
	int 21h
	pop es
	pop ds
	pop dx
	pop ax
	ret
	Removed       db 'Security Command Extend has been removed. ', 0dh, 0ah, '$'
SC_SCQuit       endp

SC_Video        proc    ; Fixup: Parameter Error
	push ax
	push bx
	push cx
	push dx
	call GetParam ; DS:BX -> Param, CX: Length of Param
	mov dx, [bx]
	call AsciiToBinary
	xor ah, ah    ; Change Video Mode
	mov al, dl
	cmp cx, 2     ; Have Parameters [Contain Pre-Space] ?
	jz Video1     ; One Char Parameter
	jg ChangeVideo
	mov al, 3     ; Default
	jmp ChangeVideo
Video1:
	mov cl, 4
	shr al, cl
ChangeVideo:
	int 10h
	pop dx
	pop cx
	pop bx
	pop ax
	ret
SC_Video        endp

SC_Font         proc
	push ax
	push bx
	push cx
	push dx
	call GetParam ; DS:BX -> Param, CX: Length of Param
	cmp cx, 22h   ; 1+16 Bytes Data, 2+32 (22H) Chars Input
	jg ParameterOK
	cmp cx, 2     ; 'r'->Restore?
	jz ParameterOK
ParameterError:
	lea dx, LackParameter
	call DisplayCodeString
	jmp SCF_Exit
ParameterOK:
	mov dx, [bx]
	or dl, 20h    ; Lower Case
	cmp dl, 'r'
	jz RestoreFont
	cmp cx, 2
	jz ParameterError
	call AsciiToBinary
	mov AsciiCode, dl
	add bx, 2     ;
	mov cx, 10h
	push es
	push di
	push bp
	push cs
	pop es
	lea di, FontShape
	mov bp, di
TranslateLoop:
	mov dx, [bx]
	call AsciiToBinary
	mov al, dl
	add bx, 2
	stosb
	loop TranslateLoop
	mov ax, 1100h ; User character load
	mov bx, 1000h ; BH=number of bytes per character BL=table in character generator RAM
	mov cx, 1
	xor dh, dh
	mov dl, AsciiCode
	int 10h
	pop bp
	pop di
	pop es        ;
	jmp short SCF_Exit
RestoreFont:
	mov ax, 1104h
	xor bx, bx
	int 10h
SCF_Exit:
	pop dx
	pop cx
	pop bx
	pop ax
	ret
	AsciiCode     db 0
	FontShape     db 10h dup (0)
	LackParameter db 'FONT <2chars', 27h, 'Ascii+32chars', 27h, 'FontShape>|r$'
SC_Font         endp

include SCmdSave.asm    ; SC_Save
include SCmdGame.asm    ; SC_Play

SC_Help         proc
	push dx
	lea dx, HelpText
	call DisplayCodeString
	pop dx
	ret
SC_Help         endp

SC_Test         proc
        push dx
        lea dx, TestText
        call DisplayCodeString
        lea dx, t2
        stc
        call DisplayCodeBstr
        pop dx
        ret
        TestText        db 'T E S T', 0dh, 0ah, '$'
        t2 db 9, 0, '0123456789abc'
SC_Test         endp

Caption                 db 'Security Command Extend     Version 2.52', 0dh, 0ah
			db 'DanSei/98.10.17', 0dh, 0ah, '$'
SecurityHasEnabled      db 'Security Enabled.', 0dh, 0ah, '$'
SecurityHasDisabled     db 'Security Disabled.', 0dh, 0ah, '$'

OpenNewError            db 'Cannot open new file. ', 0dh, 0ah, '$'
OpenNewOk               db 'A new file has been opened. ', 0dh, 0ah, '$'
DTurnedOn               db 'Daemon has been turned on. ', 0dh, 0ah, '$'
DTurnedOff              db 'Daemon has been turned off. ', 0dh, 0ah, '$'

HelpText                db 'Security Command Extend  -  DanSei/1998.10.17', 0dh, 0ah
                        db '_Help', 9,  '_Ver', 9,      '_Author', 9,   '_Quit', 9
                        db              '_Enable', 9,   '_Disable', 9,  '_Status',      0dh, 0ah
                        db '_Video', 9, '_Font', 9,     '_Save',                        0dh, 0ah
                        db '_Note', 9,  'LogNew', 9,    'Log-On', 9,    'Log-Off', 9
                        db              'RecNew', 9,    'Rec-On', 9,    'Rec-Off',      0dh, 0ah
                        db '_Play', 9,  '_Game', 9,                                     0dh, 0ah
                        db '$'

NewLine                 db 0dh, 0ah, '$'
TabChar                 db 9, '$'
