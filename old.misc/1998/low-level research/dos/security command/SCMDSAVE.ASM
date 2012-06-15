SC_Save         proc
	push ax
	push bx
	push cx
	push si
	push di               ; This DI was modified to SC_Play by INT2F Main Proc
	lea ax, SC_SaveCommandsTable
	push ax               ; This AX has no using other than Passing Address
	call GetParam         ; So This Proc will Make Nested Calls without DI Reassigned.
	mov si, bx            ; GetParam Return Parameter in DS:BX
	and cx, 7Fh           ;       make CX in score of 1 to 127
	cmp cl, 2             ; and a Length of Parameter in CX
	jge CheckParameter
	pop ax                ; No busy for had seen that push ax is no using,
	jmp SaveLackParameter ; We'll no SearchParameter done as parameter wrong!
CheckParameter:
	mov ax, cx            ; Save the length of parameter
	call ToUpper
	dec cx                ; Decrease Space
	mov ch, 2             ; Every Saver has 2 bytes Entry Address
	call SearchParameter
	jc RunSave
	sub al, 2             ; Decrease Space, '!' or '#'
	mov cx, ax            ; Restore the length of parameter in CX
	mov al, [bx]
	cmp al, '!'
	jnz Save_NotCommand
	jcxz SaveLackParameter
	push es               ; Save the "Command" in Save(r)Command
	push cs
	pop es
	inc si                ; SI is equal to BX
	lea di, SaveCommand
	rep movsb
	mov byte ptr es: [di], 0
			      ; ASCIZ
	pop es
	mov byte ptr cs: SaveType, 0FFh
			      ; Sign the Save Server is a Command
	jmp SaveExit
Save_NotCommand:
	cmp al, '#'
	jnz Save_NotChange
	jcxz SaveLackParameter
	inc bx
	call SC_Save_Change
	jmp SaveExit
Save_NotChange:
	cmp al, '0'
	jl SaveLackParameter
	cmp al, '9'
	jg SaveLackParameter
	and al, 0Fh
	mov byte ptr cs: SaveType, al
	jmp SaveExit
SaveLackParameter:
	push dx
	lea dx, SaveParameterError
	call DisplayCodeString
	pop dx
	jmp short SaveExit
RunSave:
	call cs: [di]         ; ->sc_play
SaveExit:
	pop di
	pop si
	pop cx
	pop bx
	pop ax
	ret
SC_Save_Off:
        mov Byte ptr cs: SaveStatus, 0
        ret
SC_Save_On:
        mov Byte ptr cs: SaveStatus, 1
        ret
SC_Save         endp

SC_SaveTimer    proc    ; This procedure will be called if SaveStatus != 0
        call SC_Save_Off
	push dx
	mov dx, word ptr cs: SaveCounter
	inc dx
	mov word ptr cs: SaveCounter, dx
	cmp dx, cs: SaveInterval
        pop dx
	jl Waiting

        ; Saver activated
        mov word ptr cs: SaveCounter, 0
	push ax
        mov al, cs: SaveType
        ; here can write a char at cur. cursor
        cmp al, 0FFh
        jz SC_Check1
	call SC_Save_Sim
ST_Break:
	pop ax
Waiting:
        call SC_Save_On
	ret
SC_Check1:
        call SC_Save_Command
        jmp short ST_Break
SC_SaveTimer    endp

SC_Save_Change  proc    ; DS:BX point to a number with CX bytes
	cmp cx, 2
	jle TimeInScore
TimeError:
	push dx
	lea dx, TimeLong
	call DisplayCodeString
	pop dx
	jmp SSC_Exit
TimeInScore:
	mov dx, [bx]
	call AsciiToBinary
	or dh, dh            ; !=0 may invalid char
	jz SSC_Allright
	mov cl, 4
	shr dl, cl
	xor dh, dh
SSC_Allright:
	or dl, dl             ; =0 minute
	jz TimeError
	mov word ptr cs: SaveInterval, dx
SSC_Exit:
	ret
	TimeLong      db 'Bad Interval Time Specified! [01~FF ¬ minutes]$'
SC_Save_Change  endp

SC_Save_Command proc    ; Do command in SaveCommand
	     push ax
	     push bx
	     push cx
	     mov ah, 0ah
	     mov al, '!'
	     xor bh, bh
	     mov bl, 0Fh
	     mov cx, 1
	     int 10h
	     pop cx
	     pop bx
	     pop ax
	ret

SC_Save_Command endp

SC_Save_Sim     proc    ; AL contains index of Simple Saver
	push bx
	xor ah, ah
	add ax, ax
        mov bx, offset SimIndex
	add bx, ax
	call cs: [bx]
	pop bx
	ret

	Sim0:
                call movingcross
                ret
	Sim1:
	  ret
	Sim2:
	  ret
	Sim3:
	  ret
	Sim4:
	  ret
	Sim5:
	  ret
	Sim6:
	  ret
	Sim7:
	  ret
	Sim8:
	  ret
	Sim9:
	  ret

	SimIndex      dw Sim0, Sim1, Sim2, Sim3, Sim4, Sim5, Sim6, Sim7, Sim8, Sim9

SC_Save_Sim     endp

SaveCounter     dw 0
SaveInterval    dw 20H
SaveType        db 0    ; 0 - 9 Internal Saver, 0FFH - Command
SaveStatus      db 0    ; 0 Disable      1 Enable
SaveCommand		db 128 dup (0)  ; Command Line
				db 0    ; ASCIZ

SaveParameterError      db 'SAVE ON | OFF | #<Interval-¬minutes> | !<Command> | n$'

SC_SaveCommandsCount    dw 4
SC_SaveCommandsTable    Label
	db 2, 'ON'
	  dw SC_Save_On
	db 3, 'OFF'
	  dw SC_Save_Off

include moving.asm
