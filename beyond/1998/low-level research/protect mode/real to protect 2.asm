
eds	segment	word public 'code'
	assume cs: eds, ds: edsdat

desc	struc
	limit	dw ?
	base_l	dw ?
	base_m	db ?
	access	db ?
	gran	db ?
	base_h	db ?
desc	ends

sz_desc		equ size desc

pe_on		equ 01h
gdt_kcs_sel	equ 08h
gdt_kds_sel	equ 10h
gdt_kss_sel	equ 18h
vram_sel	equ 20h

inl	proc near
eds_start:
	mov ax, edsdat
        mov ds, ax

        mov ax, stacks
	cli
	mov ss, ax
	mov save_ss, ax
        mov sp, offset stacks_sp
	mov save_sp, sp
	sti

	mov ah, 0dfh
	call gate_a20

.386p
	SGDT fword ptr save_gdt
	SIDT fword ptr save_idt

	mov di, offset gdt_kcs
	mov ax, cs
	mov cx, 10h
	mul cx
        mov [di].base_l, ax
        mov [di].base_m, dl

        mov di, offset gdt_kds
	mov ax, ds
	mov cx, 10h
	mul cx
        mov [di].base_l, ax
        mov [di].base_m, dl

	mov di, offset gdt_kss
	mov ax, ss
	mov cx, 10h
	mul cx
        mov [di].base_l, ax
        mov [di].base_m, dl

	cli
	mov ax, ds
	mov cx, 10h
	mul cx
	add ax, offset gdt_def
	adc dx, 0
	mov dtload, ax
	mov dtload + 2, dx
        mov dtsize, gdt_size - 1

        LGDT fword ptr dtsize

	mov ax, gdt_kds_sel
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	mov eax, 00000001h
	mov cr0, eax
	jmp eds_flush

eds_flush:
	db 0eah
	dw offset vram_disp
	dw gdt_kcs_sel

vram_disp:
	mov ax, vram_sel
	mov es, ax
	mov cx, 02d0h
	mov bx, 0
l1:
        mov word ptr es: [bx], 0720h

	inc bx
	inc bx
	loop l1
	mov bx, 00f0h
        mov word ptr es: [bx], 4141h
	cli
	mov eax, cr0
	AND AX, NOT PE_ON
	mov cr0, eax

	db 0eah
	dw offset real_mode
	dw eds

real_mode:
	mov ah, 0ddh
	call gate_a20

	mov ax, edsdat
	mov ds, ax

        LGDT fword ptr save_gdt
        LIDT fword ptr save_idt
	mov ss, save_ss
	mov sp, save_sp

	mov ah, 4ch
	int 21h

.8086
inl	endp

status_port	equ 64h
port_A		equ 60h

gate_a20	proc
	cli
	call empty_8042
	jnz gate_a20_01
	mov al, 0d1h
	out status_port, al
	call empty_8042
	jnz gate_a20_01
        mov al, ah
	out port_A, al
	call empty_8042
gate_a20_01:
	ret
gate_a20	endp

empty_8042	proc
	push cx
	sub cx, cx
empty_8042_01:
	in al, status_port
	and al, 00000010b
	loopnz empty_8042_01
	pop cx
	ret
empty_8042	endp

eds	ends

edsdat	segment word public 'data'
save_gdt	dw 4 dup (0)
save_idt	dw 4 dup(4)
save_ss         dw 0
save_sp         dw 0

dtsize	dw 0
dtload	dw 0
	dw 0

	gdt_def		equ $
			desc	<>
	gdt_kcs		desc <0fffh, 0, 0, 9ah, 0, 0>
	gdt_kds		desc <0fffh, 0, 0, 92h, 0, 0>
	gdt_kss		desc <0, 0, 0, 96h, 0, 0>
	gdt_vrm		desc <0fffh, 8000, 0bh, 92h, 0, 0>
        gdt_size        equ  $ - gdt_def
edsdat	ends

stacks segment stack para 'stack'
		db 128 dup (0)
stacks_sp       dw 0
stacks ends

        end
