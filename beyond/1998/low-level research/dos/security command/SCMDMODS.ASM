
include SCmdLogs.asm

; print a string in code segment        cs:dx
displayCodeString       proc
        pusha
        push ds

        push cs
        pop ds
        mov ah, 9
        int 21h

        pop ds
        popa
        ret
displayCodeString       endp

; print a bstr (count+string) in code segment   cs:dx
; Carry bit specified byte(clear) or word(set)
displayCodeBstr         proc
        pusha
        push ds

        push cs
        pop ds

        lahf
        mov al, ah
        mov bx, dx              ; display cs:bx
        xor cx, cx

        mov ah, 2
        mov cl, [bx]
        and al, 1               ; al = 0 byte, 1 word
        jz displayCodeBstr_char ; al == 0
        mov cx, [bx]
        inc bx
displayCodeBstr_char:
        inc bx
        or cx, cx
        jz displayCodeBstr_exit
        mov dl, cs: [bx]
        int 21h
        dec cx
        jmp short displayCodeBstr_char
displayCodeBstr_exit:
        pop ds
        popa
        ret
displayCodeBstr         endp

; append a string in code segment to a file,
;       BX = handle, cs:dx->buffer, cx = length or 0FFFFh means ASCIZ
appendfileCodeString    proc
        pusha
        push ds

        push cs
        pop ds

        call isidle
        jc appendfile_end

        pusha
        mov ah, 42h     ; seek
        mov al, 02h     ; SEEK_END
        mov cx, 0
        mov dx, 0
        int 21h
        popa

        cmp cx, 0FFFFh
        jnz simple_write

        ; count bytes
                push ds
                push si
                mov si, dx
                mov cx, 0
        next_char:
                lodsb
                cmp al, 0
                jz end_count
                inc cx
                jmp next_char
        end_count:
                pop si
                pop ds

simple_write:
        mov ah, 40h     ; write
        int 21h

appendfile_end:
        pop ds
        popa
        ret
appendfileCodeString    endp

; display word value of AX
; or store the ascii word to memory es:di if bool_to_memory == 1
displayWord     proc
        pushf
        pusha
        push ds

        push es
        push di

        mov cx, ax

        mov ax, cs
        mov ds, ax
        mov es, ax

        lea di, wordbuf                 ; es:di -> cs:wordbuf
        mov al, ch
        shr al, 4
        call Hex2Ascii
        stosb
        mov al, ch
        call Hex2Ascii
        stosb
        mov al, cl
        shr al, 4
        call Hex2Ascii
        stosb
        mov al, cl
        call Hex2Ascii
        stosb

        ; display it or store it to es:di
        pop di
        pop es

        cmp byte ptr cs: bool_to_memory, 0
        jnz to_memory
        mov ah, 9
        lea dx, wordbuf
        int 21h
        jmp display_word_exit
to_memory:
        mov cx, 4
        lea si, wordbuf
        rep movsb

display_word_exit:
        pop ds
        popa
        popf
        ret

        bool_to_memory  db 0
        wordbuf         db 0, 0, 0, 0, '$'
DisplayWord             endp

Hex2Ascii               proc    ; al.low half byte -> al
        pushf
        and al, 0fh
        add al, 30h
        cmp al, 3Ah
        jb $+4
        add al, 7
        popf
        ret
Hex2Ascii               endp

SearchSpecialCmdTable   proc    ; Search DS:SI in SecuritySpecialCmdTable
	push cx
	push dx
	push si
	lea dx, SecuritySpecialCmdTable
	push dx                       ; Pass to SearchParameter
	mov ch, 2
	mov cl, ds: [si]
	inc si
	call SearchParameter
	pop si
	pop dx
	pop cx
	ret
SearchSpecialCmdTable   endp

SearchSecurityCmdTable  proc    ; Search DS:SI in SecurityCmdTable
	push cx                       ; Set Carry Flag if Match Found
	push si                       ; And Return DI Point to Entry
	push es
	push cs                       ; ES = CS
	pop es
	lea di, SecurityCmdTable
	mov cx, cs: SecurityCmdCount
SearchLoop2:
	push cx
	xor ch, ch
	mov cl, cs: [di]              ; [DI] = Size of Command
	inc cl                        ; [SI] = Size of Command, too
	push si
	rep cmpsb
	jz Found2
	add di, cx
	mov cl, cs: [di]
	inc cl
	add di, cx
	pop si
	pop cx
	loop SearchLoop2
	jmp short SearchEnd2          ; No Match Found
Found2:
	pop si
	pop cx
	stc
SearchEnd2:
	pop es
	pop si
	pop cx
	ret
SearchSecurityCmdTable  endp

; Search DS:SI->String with CL bytes in CS:BP-2->Strings in the Format of:
; [BP-2]->Counts[Word] + Byte x+x Bytes y+[E] CH Bytes+...
SearchParameter proc
	pop cs: CallPlayIP	;
	pop di			; For get parameter in [BP-2]
	push ax			; -> Flag
	push bx			; -> CX
	push cx			; Set Carry Flag if Match Found
	push si			; and Return DI Point to [E]
	push es
	push cs			; ES = CS
	pop es
	mov bx, cx		; BH = IgnoreWidth BL = SrcLen
	mov cx, cs: [di-2]	; CX = Words count
SearchLoop:
	push cx
	xor ch, ch
	mov cl, cs: [di]	; res. e.g. 's size
	inc di
	cmp cl, bl
	jnz IgnoreCompare
	push si               ; Compare String
	rep cmpsb		; left cx means how many chars doesn't match
	pop si
	jz SearchFound
IgnoreCompare:
	add di, cx            ; Prepare for Next Compare
	mov cl, bh
	add di, cx
	pop cx
	loop SearchLoop
	clc                   ; No Match Found
	jmp short SearchExit

SearchFound:			; DI Point to [E]
	pop cx
	stc

SearchExit:
	pop es
	pop si
	pop cx
	pop bx
	pop ax
	push cs: CallPlayIP   ; Modify Return Address
	ret
	CallPlayIP    dw 0
SearchParameter endp

GetPassword     proc    ; Confirm Password with [DI]
	push ax               ; Set Carry if Password Wrong
	push bx
	push cx               ; Source: CS: [DI]
	push dx               ; Compare: CS: [InputBuffer]
	push si
	push di
	push ds
	push es

	push cs               ; Initializing
	pop ds                ; DS = ES = CS
	push cs
	pop es

	mov ah, 9
	lea dx, InputMessage
	int 21h

	xor bh, bh            ; Page 0
	mov ah, 3             ; Get Cursor Type, Postion
	int 10h               ; DH = Row, DL = Col
	mov OldCursor, cx
	mov ah, 1             ; Set Cursor Type
	mov cx, 040Dh
	int 10h
	mov ax, 0920h         ; Write Char&Attr, Char = ' '
	mov bl, 1Fh           ; Attr: Blue Back, White Fore
	mov cl, [di]          ; [DI] = Password Count
	xor ch, ch
	int 10h

	lea si, InputBuffer
InputLoop:
	mov ah, 7             ; Direct Console Input without Echo
	int 21h
	cmp al, 8             ; BackSpace?
	jnz Normal
	cmp cl, [di]
	jge InputLoop         ; If in begining, Treat as null
	dec dl                ; Do BackSpace
	dec si
	add cl, 2
	jmp InputLoopEnd
Normal:
	inc dl
	mov [si], al          ; Put the INKEY to Buffer
	inc si
InputLoopEnd:
	mov ah, 2             ; Set Cursor Postion
	int 10h
	loop InputLoop        ; Fix: Col > 80 ?

	mov ah, 1             ; Restore
	mov cx, OldCursor
	int 10h
	mov ah, 2             ; Set Cursor Postion at
	xor dl, dl            ; Begin of Line
	int 10h
	mov ax, 0920h         ; Write Char&Attr, Char = ' '
	mov bl, 07h           ; Attr: Blue Back, White Fore
	mov cx, 80            ; One Row
	int 10h

	lea si, InputBuffer   ; Check Password Right
	mov cl, [di]          ; Compare Size, Described in [DI] of in values
	inc di
	rep cmpsb
	jz GetPasswordExit
	stc                   ; Different, Password Wrong.
GetPasswordExit:
	pop es
	pop ds
	pop di
	pop si
	pop dx
	pop cx
	pop bx
	pop ax
	ret

	OldCursor     dw 0
	InputMessage  db 'Please Enter Password: $'
	InputBuffer   db 32 dup (0)
GetPassword     endp

PasswordWrong   proc
	push dx
	lea dx, ErrorPassword
	call DisplayCodeString
	pop dx
	ret
        ErrorPassword db 'Your Password is Wrong! Request refused by DanSei/TopCroak, Sorry!', 0dh, 0ah, '$'
PasswordWrong   endp

GetParam        proc    ; Ret: CX = Size of Parameter(include space), DS:BX -> Parameters
	xor ch, ch
	cmp CS: DOSVersion, 6
	jg DOS7
	mov cl, [bx+1]        ; Size of Command Line
	sub cl, [si]          ; Size of Command
	add bx, 2             ; Begin of Command Line
	jmp GetParamExit
DOS7:
	mov cx, [bx-2]        ; Size of Command Line
	sub cl, [si]          ; Size of Command
GetParamExit:
	push dx               ; Pass the Command of Command Line
	mov dx, [si]
	xor dh, dh
	add bx, dx
	pop dx
	inc bx                ; Begin without Space
	ret
GetParam        endp

AsciiToBinary   proc    ; DLDH -> DL
	push ax               ; DH: Bit 0: DHerror, Bit 1: DLerror
	xor al, al            ; AL: as DH
	cmp dh, 30h
	jl DHerror
	sub dh, 30h
	cmp dh, 0ah
	jl DHok       ; 0 - 9
	sub dh, 7
	cmp dh, 10h
	jl DHok       ; A - F
	sub dh, 20h
	cmp dh, 10h
	jl DHok       ; a - f
DHerror:
	xor dh, dh
	or al, 1
DHok:
	cmp dl, 30h
	jl DLerror
	sub dl, 30h
	cmp dl, 0ah
	jl DLok       ; 0 - 9
	sub dl, 7
	cmp dl, 10h
	jl DLok       ; A - F
	sub dl, 20h
	cmp dl, 10h
	jl DLok       ; a - f
DLerror:
	xor dl, dl
	or al, 2
DLok:
	push cx
	mov cl, 4
	shl dl, cl
	pop cx
	add dl, dh
	mov dh, al
	pop ax
	ret
AsciiToBinary   endp

ToUpper         proc    ; Translate CX Bytes' String in DS:SI
	or cx, cx
	jz TU_Done
	push ax
	push cx
	push si
	push di
	push es
	push ds               ; ES:DI = DS:SI
	pop es
	mov di, si
ToUpperLoop:
	lodsb
	cmp al, 'a'
	jl TU_Continue
	cmp al, 'z'
	jg TU_Continue
	xor al, 20h
TU_Continue:
	stosb
	loop ToUpperLoop
	pop es
	pop di
	pop si
	pop cx
	pop ax
TU_Done:
	ret
ToUpper         endp

Rand    Proc    ; Return Random in AL and 0 or 1 in ZF
        push cx
        push dx
        xor ax, ax
        int 1ah
        mov cl, al
        rol ax, cl
        add CS: RandWord, DX
        mov ax, CS: RandWord
        pop dx
        pop cx
        test ax, 1
        ret
        RandWord dw 0
Rand    Endp

Delay   Proc    ; Delay DX * 4 ms
        pusha
        mov cx, dx
        shr cx, 14
        shl dx, 2
        mov ah, 86h
        int 15h
        popa
        ret
Delay   Endp

IsIdle  Proc
        or byte ptr cs: dosidle, 0
        jz notidle
        push es
        push bx
        les bx, dword ptr cs: INDOSOff
        or byte ptr es: [bx], 0
        pop bx
        pop es
        jnz notidle
        clc
        ret
notidle:
        stc
        ret
IsIdle  Endp

SetBusy Proc
        push es
        push bx
        les bx, dword ptr cs: INDOSOff
        or byte ptr es: [bx], 1
        pop bx
        pop es
        ret
SetBusy Endp

ClrBusy Proc
        push es
        push bx
        les bx, dword ptr cs: INDOSOff
        mov byte ptr es: [bx], 0
        pop bx
        pop es
        ret
ClrBusy Endp
