; switcher real mode & protect mode

.386p

jump    macro selector, offsetv
        db 0eah
        dw offsetv
        dw selector
        endm

echoch  macro ascii
        mov ah,2
        mov dl, ascii
        int 21h
        endm

descriptor      struc
        limitl  dw 0
        basel   dw 0
        basem   db 0
        attributes      dw 0
        baseh   db 0
descriptor      ends

pdesc   struc
        limit   dw 0
        base    dd 0
pdesc   ends

atdw = 92h
atce = 98h

dseg segment use16
        gdt     label byte
        dummy   descriptor <>
        code    descriptor <0ffffh,,,atce,>
        code_sel = code - gdt
        datas descriptor <0ffffh, 0, 11h, atdw, 0>
        datas_sel = datas - gdt
        datad descriptor <0ffffh,,,atdw,>
        datad_sel = datad - gdt
        gdtlen = $-gdt

        vgdtr pdesc <gdtlen-1,>

        bufferlen = 256
        buffer db bufferlen dup (0)
dseg ends

cseg segment use16
        assume cs: cseg, ds: dseg
start:
        mov ax, dseg
        mov ds, ax
        mov bx, 16
        mul bx
        add ax, offset gdt
        adc dx, 0
        mov word ptr vgdtr.base, ax
        mov word ptr vgdtr.base+2, dx
        mov ax, cs
        mul bx
        mov code.basel, ax
        mov code.basem, dl
        mov code.baseh, dh
        mov ax, ds
        mul bx
        add ax, offset buffer
        adc dx, 0
        mov datad.basel, ax
        mov datad.basem, dl
        mov datad.baseh, dh
        lgdt qword ptr vgdtr
        cli
        call enablea20
        mov eax, cr0
        or eax, 1
        mov cr0, eax
        jump <code_seg>, <offset virtual>
virtual:
        mov ax, datas_sel
        mov ds, ax
        mov ax, datad_sel
        mov es, ax
        cld
        xor si,si
        xor di,di
        mov cx, bufferlen / 4
        repz movsd
        mov eax, cr0
        and eax, 0fffffffeh
        mov cr0, eax
        jump <seg real>, <offset real>

real:
        call disablea20
        sti
        mov ax, dseg
        mov ds, ax
        mov si, offset buffer
        cld
        mov bp, bufferlen / 16
nextline:
        mov cx, 16
nextch:
        lodsb
        push ax
        shr al, 4
        call toascii
        echoch al
        pop ax
        call toascii
        echoch al
        echoch ' '
        loop nextch
        echoch 0dh
        echoch 0ah
        dec bp
        jnz nextline
        mov ax, 4c00h
        int 21h

toascii proc


toascii endp

ea20    proc


ea20    endp

da20    proc

da20    endp

cseg    ends
        end start
