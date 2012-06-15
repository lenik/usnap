
buf_maxlen              equ     64

; take log of command user typed
; DS:BX = entire command   (Int 2Fh, AX = AE01h)
;       format: word command_length + byte[command_length]
logCommand             proc
        cmp byte ptr cs: log_enabled, 0
        jnz $+3
        ret

        pusha
        pushf
        push ds
        push es

        push cs
        pop es

        ; store command if INDOS set or not
        ;   ds:bx -> log_buffer + log_buflen
        ;   end when 0Dh occured

        ; count chars
                push ds
                push si
                mov si, bx
                mov cx, 0
        next_commandline_char:
                lodsb
                cmp al, 0
                jz end_of_commandline
                cmp al, 0dh
                jz end_of_commandline
                cmp al, 0ah
                jz end_of_commandline
                inc cx
                jmp next_commandline_char
        end_of_commandline:
                pop si
                pop ds

        ; save the buffer
        mov ax, es: log_buflen        ; test overflow
        add ax, cx
        add ax, 2
        cmp ax, buf_maxlen
        jae buffer_overflow

        lea di, log_buffer
        add di, es: log_buflen        ; di += old_len
        mov es: log_buflen, ax        ; old_len = new_len
        mov word ptr es: [di], cx
        add di, 2
        mov si, bx
        rep movsb

buffer_overflow:
store_end:
        call isIdle
        jc log_end

        mov ax, cs
        mov ds, ax              ; ds is now unimportant
        mov es, ax              ; for the DS:BX has been moved to buffer

        ; open a file
        mov ah, 3dh             ; open file
        mov al, 2               ; read/write access mode
        lea dx, log_filename
        int 21h                 ; ax = file handle if not CF
        jc logfile_end
        mov bx, ax              ; bx = file handle
        lea si, log_buffer   ; write from log_buffer + 0
append_loop:
        mov cx, [si]            ; cx = write size
        or cx, cx
        jz append_end
        add si, 2
        ; write head
                pusha

                mov ax, log_count
                mov di, offset log_head + 1
                push word ptr bool_to_memory
                mov word ptr bool_to_memory, 1
                call displayWord
                pop word ptr bool_to_memory
                inc word ptr log_count

                lea dx, log_head
                mov cx, 0FFFFh
                call appendfileCodeString

                popa
        mov dx, si              ; ds:dx -> write buffer
        add si, cx              ; si -> next write pointer
        ifdef debugversion
                push dx
                lea dx, writeappendmessage
                call DisplayCodeString
                pop dx
        endif
        call appendfileCodeString
        ; write tail
                pusha
                lea dx, log_tail
                mov cx, 0FFFFh
                call appendfileCodeString
                popa
        mov di, si
        sub di, offset log_buffer
        cmp di, log_buflen
        jae append_end
        jmp short append_loop
append_end:
        lea di, log_buffer
        mov cx, buf_maxlen
        mov ax, 0
        rep stosb               ; clear buffer
        mov log_buflen, 0

logfile_end:
        ifdef debugversion
                lea dx, logfile_end_ok
                jnc $+5
                lea dx, logfile_end_err
                call DisplayCodeString
        endif
        mov ah, 3eh             ; close file, BX = handle
        int 21h
        ifdef debugversion
                lea dx, logfile_close_ok
                jnc $+5
                lea dx, logfile_close_err
                call DisplayCodeString
        endif

log_end:
        pop es
        pop ds
        popf
        popa
        ret
logCommand              endp


; take log of command user typed
; DX = Key Code
logKey                  proc
        pushf
        cmp byte ptr cs: rec_enabled, 0
        jnz rec_is_enabled
        popf
        ret
rec_is_enabled:
        popf
        pushf

        pusha
        push ds
        push es

        ; save the buffer
        mov ax, cs: rec_buflen        ; test overflow
        add ax, 2
        cmp ax, buf_maxlen
        jae rec_buffer_overflow
        mov cs: rec_buflen, ax        ; old_len = new_len

        lea di, rec_buffer
        add di, ax
        sub di, 2                     ; now di->write offset
        mov word ptr cs: [di], dx     ; save KEYCODE[AX] to buffer

rec_buffer_overflow:
rec_store_end:
        call isIdle
        jc rec_end              ; DOS busy, exit

        push cs
        pop ds

        ; open a file
        mov ah, 3dh             ; open file
        mov al, 2               ; read/write access mode
        lea dx, rec_filename
        int 21h                 ; ax = file handle if not CF
        jc recfile_end
        mov bx, ax              ; bx = file handle

        mov cx, cs: rec_buflen  ; cx = write size
        mov dx, offset rec_buffer
        call appendfileCodeString

        mov rec_buflen, 0

recfile_end:
        mov ah, 3eh             ; close file, BX = handle
        int 21h

rec_end:
        pop es
        pop ds
        popa
        popf
        ret
logKey                  endp

        log_enabled     db 1
        rec_enabled     db 0

        log_filename    db 'c:\sclog', 0
        rec_filename    db 'c:\screc', 0

        log_count       dw 0
        log_head        db '[0000] ', 0
        log_tail        db 13, 10, 0
        log_buffer      db buf_maxlen dup (0)
        log_buflen      dw 0

        rec_buffer      db buf_maxlen dup (0)
        rec_buflen      dw 0

;include dumpReg.asm
