
dumpRegisters   proc
        ; save registers to buffer
        mov cs: reg_ax, ax
        mov cs: reg_bx, bx
        mov cs: reg_cx, cx
        mov cs: reg_dx, dx
        mov cs: reg_sp, sp
        mov cs: reg_bp, bp
        mov cs: reg_si, si
        mov cs: reg_di, di
        mov ax, ds
        mov cs: reg_ds, ax
        mov ax, es
        mov cs: reg_es, ax
        mov ax, ss
        mov cs: reg_ss, ax
        mov ax, cs
        mov cs: reg_cs, ax
        pushf
        pop ax
        mov cs: reg_fl, ax
        pop ax                  ; return addr
        push ax
        mov cs: reg_ip, ax

        ; check if INDOS
        push es
        pusha
        mov ah, 34h             ; get INDOS in es:bx, exit if set
        int 21h
        or byte ptr es: [bx], 0
        popa
        pop es
        jnz dump_registers_end

        call tran_reg_table
        lea dx, regdump
        call displayCodeString

dump_registers_end:
        mov bx, cs: reg_bx
        mov cx, cs: reg_cx
        mov dx, cs: reg_dx
        mov sp, cs: reg_sp
        mov bp, cs: reg_bp
        mov si, cs: reg_si
        mov di, cs: reg_di
        mov ax, cs: reg_ds
        mov ds, ax
        mov ax, cs: reg_es
        mov es, ax
        mov ax, cs: reg_fl
        push ax
        popf
        mov ax, cs: reg_ax
        ret

dumpRegisters   endp

tran_reg_table  proc
        pusha
        push ds
        push es

        mov ax, cs
        mov ds, ax
        mov es, ax

        push word ptr cs: bool_to_memory
        mov byte ptr cs: bool_to_memory, 1

        mov ax, cs: reg_ax
        lea di, ri_ax
        call displayWord
        mov ax, cs: reg_bx
        lea di, ri_bx
        call displayWord
        mov ax, cs: reg_cx
        lea di, ri_cx
        call displayWord
        mov ax, cs: reg_dx
        lea di, ri_dx
        call displayWord

        mov ax, cs: reg_sp
        lea di, ri_sp
        call displayWord
        mov ax, cs: reg_bp
        lea di, ri_bp
        call displayWord
        mov ax, cs: reg_si
        lea di, ri_si
        call displayWord
        mov ax, cs: reg_di
        lea di, ri_di
        call displayWord

        mov ax, cs: reg_ds
        lea di, ri_ds
        call displayWord
        mov ax, cs: reg_es
        lea di, ri_es
        call displayWord
        mov ax, cs: reg_ss
        lea di, ri_ss
        call displayWord
        mov ax, cs: reg_cs
        lea di, ri_cs
        call displayWord

        mov ax, cs: reg_ip
        lea di, ri_ip
        call displayWord
        mov ax, cs: reg_fl
        lea di, ri_fl
        call displayWord

        pop word ptr cs: bool_to_memory

        pop es
        pop ds
        popa
        ret

tran_reg_table  endp

        reg_ax  dw 0
        reg_bx  dw 0
        reg_cx  dw 0
        reg_dx  dw 0
        reg_sp  dw 0
        reg_bp  dw 0
        reg_si  dw 0
        reg_di  dw 0
        reg_ds  dw 0
        reg_es  dw 0
        reg_ss  dw 0
        reg_cs  dw 0
        reg_ip  dw 0
        reg_fl  dw 0

        regdump db 'AX='
        ri_ax   db '0000  BX='
        ri_bx   db '0000  CX='
        ri_cx   db '0000  DX='
        ri_dx   db '0000  SP='
        ri_sp   db '0000  BP='
        ri_bp   db '0000  SI='
        ri_si   db '0000  DI='
        ri_di   db '0000', 13, 10
                db 'DS='
        ri_ds   db '0000  ES='
        ri_es   db '0000  SS='
        ri_ss   db '0000  CS='
        ri_cs   db '0000  IP='
        ri_ip   db '0000  FL='
        ri_fl   db '0000', 13, 10
                db '$'
