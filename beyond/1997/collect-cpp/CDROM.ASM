
PAGE  59,132

;€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€
;€€					                                 €€
;€€				CDROM	                                 €€
;€€					                                 €€
;€€      Created:   1-Jan-100		                                 €€
;€€      Passes:    5          Analysis	Options on: none                 €€
;€€      Copyright 1991 Borland	Intl.	                                 €€
;€€					                                 €€
;€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€

target		EQU   'M5'                      ; Target assembler: MASM-5.0

include  srmacros.inc


; The following equates show data references outside the range of the program.

data_1e		equ	0
data_2e		equ	4
data_3e		equ	6
data_4e		equ	3Dh
data_5e		equ	70h
data_6e		equ	7Bh
data_7e		equ	87h
data_8e		equ	89h
data_9e		equ	8Bh
data_10e	equ	8Dh
data_11e	equ	8Fh
data_12e	equ	91h
data_13e	equ	0F6h
data_14e	equ	3B6h
data_15e	equ	3CCh
data_16e	equ	3CEh
data_17e	equ	0			;*
data_18e	equ	2			;*
data_19e	equ	8			;*
data_20e	equ	0			;*
data_21e	equ	2			;*
data_22e	equ	0			;*
data_23e	equ	2			;*
data_24e	equ	4			;*
data_25e	equ	0			;*
data_26e	equ	2			;*
data_27e	equ	0			;*
data_28e	equ	6			;*
PSP_free_seg	equ	2
PSP_envirn_seg	equ	2Ch
data_138e	equ	0FF6Ah			;*
data_139e	equ	2			;*
data_140e	equ	2			;*
data_141e	equ	2			;*
data_142e	equ	8			;*
data_143e	equ	4
data_144e	equ	0
data_145e	equ	4
data_146e	equ	0
data_147e	equ	2
data_148e	equ	2
data_149e	equ	8
data_150e	equ	0
data_151e	equ	2
data_152e	equ	8
data_153e	equ	0
data_154e	equ	2

;------------------------------------------------------------  seg_a   ----

seg_a		segment	byte public
		assume cs:seg_a  , ds:seg_a , ss:stack_seg_e


;€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€
;
;                       Program	Entry Point
;
;€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€


cdrom		proc	far

start:
		movseg	dx,seg seg_d
		mov	word ptr cs:[260h],dx
		mov	ah,30h
		int	21h
		mov	bp,ds:PSP_free_seg
		mov	bx,ds:PSP_envirn_seg
		mov	ds,dx
		assume	ds:seg_d
		mov	data_105,ax
		mov	data_104,es
		mov	word ptr data_101+2,bx
		mov	data_112,bp
		call	sub_4
		les	di,data_101
		mov	ax,di
		mov	bx,ax
		mov	cx,7FFFh
		cld
loc_1:
		repne	scasb
		jcxz	loc_3
		inc	bx
		cmp	es:[di],al
		jne	loc_1
		or	ch,80h
		neg	cx
		mov	word ptr data_101,cx
		mov	cx,2
		shl	bx,cl
;*		add	bx,10h
		db	 83h,0C3h, 10h
;*		and	bx,0FFF0h
		db	 83h,0E3h,0F0h
		mov	data_103,bx
		mov	dx,ss
		sub	bp,dx
		movseg	di,seg seg_d
		mov	es,di
		mov	di,es:data_129
		cmp	di,200h
		jae	loc_2
		mov	di,200h
		mov	es:data_129,di
loc_2:
		mov	cl,4
		shr	di,cl
		inc	di
		cmp	bp,di
		jae	loc_4
loc_3:
		jmp	loc_19
loc_4:
		mov	bx,di
		add	bx,dx
		mov	data_110,bx
		mov	data_111,bx
		mov	ax,data_104
		sub	bx,ax
		mov	es,ax
		mov	ah,4Ah			; 'J'
		push	di
		int	21h
		pop	di
		shl	di,cl
		cli
		mov	ss,dx
		mov	sp,di
		sti
		mov	ax,seg_d
		mov	es,ax
		mov	es:data_129,di
		xor	ax,ax
		mov	es,word ptr cs:[260h]
		mov	di,data_15e
		mov	cx,44Eh
		sub	cx,di
		cld
		rep	stosb
		cmp	data_124,14h
		jbe	loc_7
		cmp	byte ptr data_105,3
		jb	loc_7
		ja	loc_5
		cmp	byte ptr data_105+1,1Eh
		jb	loc_7
loc_5:
		mov	ax,5801h
		mov	bx,2
		int	21h
		jc	loc_6
		mov	ah,67h			; 'g'
		mov	bx,data_124
		int	21h
		jc	loc_6
		mov	ah,48h			; 'H'
		mov	bx,1
		int	21h
		jc	loc_6
		inc	ax
		mov	data_112,ax
		dec	ax
		mov	es,ax
		mov	ah,49h
		int	21h
		jc	loc_6
		mov	ax,5801h
		mov	bx,0
		int	21h
		jnc	loc_7
loc_6:
		jmp	loc_19
loc_7:
		mov	ah,0
		int	1Ah
		mov	data_107,dx
		mov	data_108,cx
		or	al,al
		jz	loc_8
		mov	ax,40h
		mov	es,ax
		mov	bx,data_5e
		mov	byte ptr es:[bx],1
loc_8:
		xor	bp,bp
		mov	es,word ptr cs:[260h]
		mov	si,3C6h
		mov	di,3CCh
		call	sub_6
		push	data_100
		push	data_99
		push	data_98
		push	data_97
		push	data_96
		call	far ptr sub_55
		push	ax
		nop
		callf	sub_9

cdrom		endp

;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_1		proc	near
		mov	es,word ptr cs:[260h]
		push	si
		push	di
		mov	si,3CCh
		mov	di,3CCh
		call	sub_6
		pop	di
		pop	si
		retf
sub_1		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_2		proc	near
		retf
sub_2		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_3		proc	near
		mov	bp,sp
		mov	ah,4Ch			; 'L'
		mov	al,[bp+4]
		int	21h
sub_3		endp


;€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€
;
;                       External Entry Point
;
;€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€

int_00h_entry	proc	far
		mov	cx,0Eh
		mov	dx,2Fh
		jmp	loc_20
int_00h_entry	endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_4		proc	near
		push	ds
		mov	ax,3500h
		int	21h
		mov	data_88,bx
		mov	data_89,es
		mov	ax,3504h
		int	21h
		mov	data_90,bx
		mov	data_91,es
		mov	ax,3505h
		int	21h
		mov	data_92,bx
		mov	data_93,es
		mov	ax,3506h
		int	21h
		mov	data_94,bx
		mov	data_95,es
		mov	ax,2500h
		mov	dx,cs
		mov	ds,dx
		mov	dx,offset int_00h_entry
		int	21h
		pop	ds
		retn
sub_4		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_5		proc	near
		push	ds
		mov	ax,2500h
		lds	dx,dword ptr ds:[5Bh]
		int	21h
		pop	ds
		push	ds
		mov	ax,2504h
		lds	dx,dword ptr ds:[5Fh]
		int	21h
		pop	ds
		push	ds
		mov	ax,2505h
		lds	dx,dword ptr ds:[63h]
		int	21h
		pop	ds
		push	ds
		mov	ax,2506h
		lds	dx,dword ptr ds:[67h]
		int	21h
		pop	ds
		retf
sub_5		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_6		proc	near
loc_9:
		cmp	si,3C6h
		je	loc_10
		xor	ah,ah
		jmp	short loc_11
loc_10:
		mov	ah,0FFh
loc_11:
		mov	dx,di
		mov	bx,si
loc_12:
		cmp	bx,di
		je	loc_16
		cmp	byte ptr es:[bx],0FFh
		je	loc_15
		cmp	si,3C6h
		je	loc_13
		cmp	ah,es:[bx+1]
		jmp	short loc_14
loc_13:
		cmp	es:[bx+1],ah
loc_14:
		ja	loc_15
		mov	ah,es:[bx+1]
		mov	dx,bx
loc_15:
;*		add	bx,6
		db	 83h,0C3h, 06h
		jmp	short loc_12
loc_16:
		cmp	dx,di
		je	loc_ret_18
		mov	bx,dx
		cmp	byte ptr es:[bx],0
		mov	byte ptr es:[bx],0FFh
		push	es
		jz	loc_17
		call	dword ptr es:[bx+2]
		pop	es
		jmp	short loc_9
loc_17:
		call	word ptr es:[bx+2]
		pop	es
		jmp	short loc_9

loc_ret_18:
		retn
sub_6		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_7		proc	near
		mov	ah,40h			; '@'
		mov	bx,2
		int	21h
		retn
sub_7		endp

loc_19:
		mov	cx,1Eh
		mov	dx,data_4e
loc_20:
		mov	ds,word ptr cs:[260h]
		call	sub_7
		mov	ax,3
		push	ax
		nop
		callf	sub_10
		add	[bx+si],al
		add	al,0C0h
		push	bp
		mov	bp,sp
		cmp	word ptr ds:data_13e,20h
		jne	loc_21
		mov	ax,1
		jmp	short loc_22
loc_21:
		mov	bx,ds:data_13e
		shl	bx,1
		shl	bx,1
		mov	ax,[bp+8]
		mov	dx,[bp+6]
		mov	ds:data_16e[bx],ax
		mov	ds:data_15e[bx],dx
		inc	word ptr ds:data_13e
		xor	ax,ax
loc_22:
		pop	bp
		retf
		db	0CBh

;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_8		proc	near
		push	bp
		mov	bp,sp
		push	si
		mov	si,[bp+8]
		or	si,si
		jnz	loc_25
		jmp	short loc_24
loc_23:
		dec	data_114
		mov	bx,data_114
		shl	bx,1
		shl	bx,1
		call	dword ptr data_136[bx]	;*
loc_24:
		cmp	data_114,0
		jne	loc_23
		nop
		callf	sub_1
		call	dword ptr data_115
loc_25:
		nop
		callf	sub_5
		nop
		callf	sub_2
		cmp	word ptr [bp+6],0
		jne	loc_27
		or	si,si
		jnz	loc_26
		call	dword ptr data_116
		call	dword ptr data_117
loc_26:
		push	word ptr [bp+4]
		nop
		callf	sub_3
		pop	cx
loc_27:
		pop	si
		pop	bp
		retn	6
sub_8		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_9		proc	near
		push	bp
		mov	bp,sp
		xor	ax,ax
		push	ax
		push	ax
		push	word ptr [bp+6]
		call	sub_8
		pop	bp
		retf
sub_9		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_10		proc	near
		push	bp
		mov	bp,sp
		mov	ax,1
		push	ax
		xor	ax,ax
		push	ax
		push	word ptr [bp+6]
		call	sub_8
		pop	bp
		retf
sub_10		endp

		db	 33h,0C0h, 50h,0B8h, 01h, 00h
		db	 50h, 33h,0C0h, 50h,0E8h, 7Bh
		db	0FFh,0CBh,0B8h, 01h, 00h, 50h
		db	 50h, 33h,0C0h, 50h,0E8h, 6Fh
		db	0FFh
data_51		db	0CBh			; Data table (indexed access)

;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_11		proc	near
		pop	bx
		push	cs
		push	bx
		cmp	cl,10h
		jae	loc_28
		mov	bx,ax
		shl	ax,cl
		shl	dx,cl
		neg	cl
		add	cl,10h
		shr	bx,cl
		or	dx,bx
		retf
loc_28:
		sub	cl,10h
		xchg	dx,ax
		xor	ax,ax
		shl	dx,cl
		retf
sub_11		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_12		proc	near
		pop	es
		push	cs
		push	es
		or	cx,cx
		jge	loc_29
		not	bx
		not	cx
;*		add	bx,1
		db	 83h,0C3h, 01h
;*		adc	cx,0
		db	 83h,0D1h, 00h
		jmp	short loc_31
loc_29:
		add	ax,bx
		jnc	loc_30
		add	dx,1000h
loc_30:
		mov	ch,cl
		mov	cl,4
		shl	ch,cl
		add	dh,ch
		mov	ch,al
		shr	ax,cl
		add	dx,ax
		mov	al,ch
		and	ax,0Fh
		retf
			                        ;* No entry point to code
		pop	es
		push	cs
		push	es
		or	cx,cx
		jge	loc_31
		not	bx
		not	cx
;*		add	bx,1
		db	 83h,0C3h, 01h
;*		adc	cx,0
		db	 83h,0D1h, 00h
		jmp	short loc_29
loc_31:
		sub	ax,bx
		jnc	loc_32
		sub	dx,1000h
loc_32:
		mov	bh,cl
		mov	cl,4
		shl	bh,cl
		xor	bl,bl
		sub	dx,bx
		mov	ch,al
		shr	ax,cl
		add	dx,ax
		mov	al,ch
		and	ax,0Fh
		retf
sub_12		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_13		proc	near
		push	bp
		mov	bp,sp
		push	si
		mov	si,[bp+4]
		or	si,si
		jl	loc_35
;*		cmp	si,58h
		db	 83h,0FEh, 58h
		jle	loc_34
loc_33:
		mov	si,57h
loc_34:
		mov	word ptr ds:[2BEh],si
		mov	al,byte ptr ds:[2C0h][si]
		cbw
		mov	si,ax
		jmp	short loc_36
loc_35:
		neg	si
;*		cmp	si,23h
		db	 83h,0FEh, 23h
		jg	loc_33
		mov	word ptr ds:[2BEh],0FFFFh
loc_36:
		mov	word ptr ds:[7Fh],si
		mov	ax,0FFFFh
		pop	si
		pop	bp
		retn	2
sub_13		endp

			                        ;* No entry point to code
		push	bp
		mov	bp,sp
		push	si
		mov	si,[bp+4]
		push	si
		call	sub_13
		mov	ax,si
		pop	si
		pop	bp
		retn	2

;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_14		proc	near
		push	bp
		mov	bp,sp
		mov	ax,4400h
		mov	bx,[bp+6]
		int	21h
		xchg	dx,ax
		and	ax,80h
		pop	bp
		retf
sub_14		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_15		proc	near
		push	bp
		mov	bp,sp
;*		sub	sp,22h
		db	 83h,0ECh, 22h
		push	si
		push	di
		push	es
		les	di,dword ptr [bp+0Ah]
		mov	bx,[bp+8]
;*		cmp	bx,24h
		db	 83h,0FBh, 24h
		ja	loc_44
		cmp	bl,2
		jb	loc_44
		mov	ax,[bp+0Eh]
		mov	cx,[bp+10h]
		or	cx,cx
		jge	loc_37
		cmp	byte ptr [bp+6],0
		je	loc_37
		mov	byte ptr es:[di],2Dh	; '-'
		inc	di
		neg	cx
		neg	ax
;*		sbb	cx,0
		db	 83h,0D9h, 00h
loc_37:
		lea	si,[bp-22h]
		jcxz	loc_39
loc_38:
		xchg	cx,ax
		sub	dx,dx
		div	bx
		xchg	cx,ax
		div	bx
		mov	ss:[si],dl
		inc	si
		jcxz	loc_40
		jmp	short loc_38
loc_39:
		sub	dx,dx
		div	bx
		mov	ss:[si],dl
		inc	si
loc_40:
		or	ax,ax
		jnz	loc_39
		lea	cx,[bp-22h]
		neg	cx
		add	cx,si
		cld

locloop_41:
		dec	si
		mov	al,ss:[si]
		sub	al,0Ah
		jnc	loc_42
		add	al,3Ah			; ':'
		jmp	short loc_43
loc_42:
		add	al,[bp+4]
loc_43:
		stosb
		loop	locloop_41

loc_44:
		mov	al,0
		stosb
		pop	es
		mov	dx,[bp+0Ch]
		mov	ax,[bp+0Ah]
		pop	di
		pop	si
		mov	sp,bp
		pop	bp
		retn	0Eh
sub_15		endp

			                        ;* No entry point to code
		push	bp
		mov	bp,sp
		xor	ax,ax
		push	ax
		push	word ptr [bp+8]
		push	word ptr [bp+6]
		push	word ptr [bp+4]
		mov	ax,0Ah
		push	ax
		mov	al,0
		push	ax
		mov	al,61h			; 'a'
		push	ax
		call	sub_15
		pop	bp
		retn	6

;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_16		proc	near
		push	bp
		mov	bp,sp
		mov	bx,[bp+6]
		shl	bx,1
		and	word ptr ds:[296h][bx],0FDFFh
		mov	ah,42h			; 'B'
		mov	al,[bp+0Ch]
		mov	bx,[bp+6]
		mov	cx,[bp+0Ah]
		mov	dx,[bp+8]
		int	21h
		jc	loc_45
		jmp	short loc_46
loc_45:
		push	ax
		call	sub_13
		cwd
loc_46:
		pop	bp
		retf
sub_16		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_17		proc	near
		push	cx
		mov	ch,al
		mov	cl,4
		shr	ax,cl
		add	dx,ax
		mov	al,ch
		mov	ah,bl
		shr	bx,cl
		pop	cx
		add	cx,bx
		mov	bl,ah
		and	ax,0Fh
;*		and	bx,0Fh
		db	 83h,0E3h, 0Fh
		cmp	dx,cx
		jne	loc_ret_47
		cmp	ax,bx

loc_ret_47:
		retn
sub_17		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_18		proc	near
		push	bp
		mov	bp,sp
		push	si
		mov	bx,es
		les	si,dword ptr [bp+6]
		mov	es:[si],bx
		mov	ax,[bp+4]
		mov	es:[si+2],ax
		mov	es:[si+4],ss
		mov	es:[si+6],ds
		mov	es,bx
		pop	si
		pop	bp
		retf
sub_18		endp

			                        ;* No entry point to code
		mov	cx,5
		cmp	cx,word ptr ds:[294h]
		jae	loc_49
loc_48:
		mov	bx,cx
		shl	bx,1
		mov	word ptr ds:[296h][bx],0
		mov	ax,cx
		mov	dx,14h
		imul	dx
		mov	bx,ax
		mov	byte ptr ds:[108h][bx],0FFh
		mov	ax,cx
		mov	dx,14h
		imul	dx
		add	ax,104h
		push	ax
		mov	ax,cx
		mov	dx,14h
		imul	dx
		mov	bx,ax
		pop	ax
		mov	word ptr ds:[116h][bx],ax
		inc	cx
		cmp	cx,word ptr ds:[294h]
		jb	loc_48
loc_49:
		mov	al,byte ptr ds:[108h]
		cbw
		push	ax
		nop
		callf	sub_14
		pop	cx
		or	ax,ax
		jnz	loc_50
		and	word ptr ds:[106h],0FDFFh
loc_50:
		mov	ax,200h
		push	ax
		test	word ptr ds:[106h],200h
		jz	loc_51
		mov	ax,1
		jmp	short loc_52
loc_51:
		xor	ax,ax
loc_52:
		push	ax
		xor	ax,ax
		push	ax
		push	ax
		push	ds
		mov	ax,104h
		push	ax
		nop
		callf	sub_51
;*		add	sp,0Ch
		db	 83h,0C4h, 0Ch
		mov	al,byte ptr ds:[11Ch]
		cbw
		push	ax
		nop
		callf	sub_14
		pop	cx
		or	ax,ax
		jnz	loc_53
		and	word ptr ds:[11Ah],0FDFFh
loc_53:
		mov	ax,200h
		push	ax
		test	word ptr ds:[11Ah],200h
		jz	loc_54
		mov	ax,2
		jmp	short loc_55
loc_54:
		xor	ax,ax
loc_55:
		push	ax
		xor	ax,ax
		push	ax
		push	ax
		push	ds
		mov	ax,118h
		push	ax
		nop
		callf	sub_51
;*		add	sp,0Ch
		db	 83h,0C4h, 0Ch
		retn

;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_19		proc	near
		push	bp
		mov	bp,sp
		mov	ax,1
		push	ax
		xor	ax,ax
		push	ax
		push	ax
		push	word ptr [bp+6]
		nop
		callf	sub_16
;*		add	sp,8
		db	 83h,0C4h, 08h
		pop	bp
		retf
sub_19		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_20		proc	near
		mov	al,dh
		call	sub_21
		mov	al,dl

;ﬂﬂﬂﬂ External Entry into Subroutine ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ

sub_21:
		db	0D4h, 10h, 86h,0E0h,0E8h, 02h
		db	 00h, 86h,0E0h, 04h, 90h, 27h
		db	 14h, 40h, 27h,0AAh,0C3h

;ﬂﬂﬂﬂ External Entry into Subroutine ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ

sub_22:
		push	bp
		mov	bp,sp
		sub	sp,96h
		push	si
		push	di
		mov	word ptr [bp-12h],0
		mov	word ptr [bp-14h],50h
		mov	word ptr [bp-16h],0
		jmp	short loc_58

;ﬂﬂﬂﬂ External Entry into Subroutine ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ

sub_23:
		push	di
		mov	cx,0FFFFh
		xor	al,al
		repne	scasb
		not	cx
		dec	cx
		pop	di
		retn

;ﬂﬂﬂﬂ External Entry into Subroutine ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ

sub_24:
		mov	ss:[di],al
		inc	di
		dec	byte ptr [bp-14h]
		jnz	loc_ret_57

;ﬂﬂﬂﬂ External Entry into Subroutine ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ

sub_25:
		push	bx
		push	cx
		push	dx
		push	es
		lea	ax,cs:[0FF6Ah][bp]
		sub	di,ax
		push	ss
		lea	ax,cs:[0FF6Ah][bp]
		push	ax
		push	di
		push	word ptr [bp+0Ch]
		push	word ptr [bp+0Ah]
		call	word ptr [bp+0Eh]	;*
		or	ax,ax
		jnz	loc_56
		mov	word ptr [bp-16h],1
loc_56:
		mov	word ptr [bp-14h],50h
		add	[bp-12h],di
		lea	di,ss:data_138e[bp]
		pop	es
		pop	dx
		pop	cx
		pop	bx

loc_ret_57:
		retn
loc_58:
		push	es
		cld
		lea	di,ss:data_138e[bp]
		mov	[bp-4],di
loc_59:
		mov	di,[bp-4]
loc_60:
		les	si,dword ptr [bp+6]
loc_61:
		lods	byte ptr es:[si]
		or	al,al
		jz	loc_63
		cmp	al,25h			; '%'
		je	loc_64
loc_62:
		mov	ss:[di],al
		inc	di
		dec	byte ptr [bp-14h]
		jg	loc_61
		call	sub_25
		jmp	short loc_61
loc_63:
		jmp	loc_143
loc_64:
		mov	[bp-10h],si
		lods	byte ptr es:[si]
		cmp	al,25h			; '%'
		je	loc_62
		mov	[bp-4],di
		xor	cx,cx
		mov	[bp-0Eh],cx
		mov	word ptr [bp-2],20h
		mov	[bp-0Bh],cl
		mov	word ptr [bp-8],0FFFFh
		mov	word ptr [bp-0Ah],0FFFFh
		jmp	short loc_66
loc_65:
		lods	byte ptr es:[si]
loc_66:
		xor	ah,ah
		mov	dx,ax
		mov	bx,ax
		sub	bl,20h			; ' '
		cmp	bl,60h			; '`'
		jae	loc_68
		assume	ds:seg_a
		mov	bl,data_51[bx]
;*		cmp	bx,17h
		db	 83h,0FBh, 17h
		jbe	loc_67
		jmp	loc_141
loc_67:
		shl	bx,1
		jmp	word ptr cs:data_56[bx]	;*24 entries
loc_68:
		jmp	loc_141

;ƒƒƒƒƒ Indexed Entry Point ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ

loc_69:
		cmp	ch,0
		ja	loc_68
		or	word ptr [bp-2],1
		jmp	short loc_65

;ƒƒƒƒƒ Indexed Entry Point ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ

loc_70:
		cmp	ch,0
		ja	loc_68
		or	word ptr [bp-2],2
		jmp	short loc_65

;ƒƒƒƒƒ Indexed Entry Point ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ

loc_71:
		cmp	ch,0
		ja	loc_68
		cmp	byte ptr [bp-0Bh],2Bh	; '+'
		je	loc_72
		mov	[bp-0Bh],dl
loc_72:
		jmp	short loc_65

;ƒƒƒƒƒ Indexed Entry Point ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ

loc_73:
		and	word ptr [bp-2],0FFDFh
		jmp	short loc_75

;ƒƒƒƒƒ Indexed Entry Point ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ

loc_74:
		or	word ptr [bp-2],20h
loc_75:
		mov	ch,5
		jmp	short loc_65

;ƒƒƒƒƒ Indexed Entry Point ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ

loc_76:
		cmp	ch,0
		ja	loc_83
		test	word ptr [bp-2],2
		jnz	loc_80
		or	word ptr [bp-2],8
		mov	ch,1
		jmp	short loc_65
loc_77:
		jmp	loc_141

;ƒƒƒƒƒ Indexed Entry Point ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ

loc_78:
		mov	di,[bp+4]
		mov	ax,ss:[di]
		add	word ptr [bp+4],2
		cmp	ch,2
		jae	loc_81
		or	ax,ax
		jns	loc_79
		neg	ax
		or	word ptr [bp-2],2
loc_79:
		mov	[bp-8],ax
		mov	ch,3
loc_80:
		jmp	loc_65
loc_81:
		cmp	ch,4
		jne	loc_77
		mov	[bp-0Ah],ax
		inc	ch
		jmp	loc_65

;ƒƒƒƒƒ Indexed Entry Point ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ

loc_82:
		cmp	ch,4
		jae	loc_77
		mov	ch,4
		inc	word ptr [bp-0Ah]
		jmp	loc_65

;ƒƒƒƒƒ Indexed Entry Point ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ

loc_83:
		xchg	dx,ax
		sub	al,30h			; '0'
		cbw
		cmp	ch,2
		ja	loc_84
		mov	ch,2
		xchg	[bp-8],ax
		or	ax,ax
		jl	loc_80
		shl	ax,1
		mov	dx,ax
		shl	ax,1
		shl	ax,1
		add	ax,dx
		add	[bp-8],ax
		jmp	loc_65
loc_84:
		cmp	ch,4
		jne	loc_77
		xchg	[bp-0Ah],ax
		or	ax,ax
		jz	loc_80
		shl	ax,1
		mov	dx,ax
		shl	ax,1
		shl	ax,1
		add	ax,dx
		add	[bp-0Ah],ax
		jmp	loc_65

;ƒƒƒƒƒ Indexed Entry Point ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ

loc_85:
		or	word ptr [bp-2],10h
		jmp	loc_75

;ƒƒƒƒƒ Indexed Entry Point ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ

loc_86:
		or	word ptr [bp-2],100h

;ƒƒƒƒƒ Indexed Entry Point ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ

loc_87:
		and	word ptr [bp-2],0FFEFh
		jmp	loc_75

;ƒƒƒƒƒ Indexed Entry Point ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ

loc_88:
		mov	bh,8
		jmp	short loc_91

;ƒƒƒƒƒ Indexed Entry Point ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ

loc_89:
		mov	bh,0Ah
		jmp	short loc_92

;ƒƒƒƒƒ Indexed Entry Point ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ

loc_90:
		mov	bh,10h
		mov	bl,0E9h
		add	bl,dl
loc_91:
		mov	byte ptr [bp-0Bh],0
loc_92:
		mov	[bp-5],dl
		xor	dx,dx
		mov	[bp-6],dl
		mov	di,[bp+4]
		mov	ax,ss:[di]
		jmp	short loc_94

;ƒƒƒƒƒ Indexed Entry Point ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ

loc_93:
		mov	bh,0Ah
		mov	byte ptr [bp-6],1
		mov	[bp-5],dl
		mov	di,[bp+4]
		mov	ax,ss:[di]
		cwd
loc_94:
		inc	di
		inc	di
		mov	[bp+6],si
		test	word ptr [bp-2],10h
		jz	loc_95
		mov	dx,ss:[di]
		inc	di
		inc	di
loc_95:
		mov	[bp+4],di
		lea	di,[bp-45h]
		or	ax,ax
		jnz	loc_96
		or	dx,dx
		jnz	loc_96
		cmp	word ptr [bp-0Ah],0
		jne	loc_97
		jmp	loc_59
loc_96:
		or	word ptr [bp-2],4
loc_97:
		push	dx
		push	ax
		push	ss
		push	di
		mov	al,bh
		cbw
		push	ax
		mov	al,[bp-6]
		push	ax
		push	bx
		call	sub_15
		push	ss
		pop	es
		mov	dx,[bp-0Ah]
		or	dx,dx
		jge	loc_98
		jmp	loc_112
loc_98:
		jmp	loc_113

;ƒƒƒƒƒ Indexed Entry Point ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ

loc_99:
		mov	[bp-5],dl
		mov	[bp+6],si
		lea	di,[bp-46h]
		mov	bx,[bp+4]
		push	word ptr ss:[bx]
		inc	bx
		inc	bx
		mov	[bp+4],bx
		test	word ptr [bp-2],20h
		jz	loc_100
		mov	dx,ss:[bx]
		inc	bx
		inc	bx
		mov	[bp+4],bx
		push	ss
		pop	es
		call	sub_20
		mov	al,3Ah			; ':'
		stosb
loc_100:
		push	ss
		pop	es
		pop	dx
		call	sub_20
		mov	byte ptr ss:[di],0
		mov	byte ptr [bp-6],0
		and	word ptr [bp-2],0FFFBh
		lea	cx,[bp-46h]
		sub	di,cx
		xchg	cx,di
		mov	dx,[bp-0Ah]
		cmp	dx,cx
		jg	loc_101
		mov	dx,cx
loc_101:
		jmp	loc_112

;ƒƒƒƒƒ Indexed Entry Point ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ

loc_102:
		mov	[bp+6],si
		mov	[bp-5],dl
		mov	di,[bp+4]
		mov	ax,ss:[di]
		add	word ptr [bp+4],2
		push	ss
		pop	es
		lea	di,[bp-45h]
		xor	ah,ah
		mov	ss:[di],ax
		mov	cx,1
		jmp	loc_118

;ƒƒƒƒƒ Indexed Entry Point ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ

loc_103:
		mov	[bp+6],si
		mov	[bp-5],dl
		mov	di,[bp+4]
		test	word ptr [bp-2],20h
		jnz	loc_104
		mov	di,ss:[di]
		add	word ptr [bp+4],2
		push	ds
		pop	es
		or	di,di
		jmp	short loc_105
loc_104:
		les	di,dword ptr ss:[di]
		add	word ptr [bp+4],4
		mov	ax,es
		or	ax,di
loc_105:
		jnz	loc_106
		push	ds
		pop	es
		mov	di,31Ch
loc_106:
		call	sub_23
		cmp	cx,[bp-0Ah]
		jbe	loc_107
		mov	cx,[bp-0Ah]
loc_107:
		jmp	loc_118

;ƒƒƒƒƒ Indexed Entry Point ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ

loc_108:
		mov	[bp+6],si
		mov	[bp-5],dl
		mov	di,[bp+4]
		mov	cx,[bp-0Ah]
		or	cx,cx
		jge	loc_109
		mov	cx,6
loc_109:
		push	ss
		push	di
		push	cx
		push	ss
		lea	bx,[bp-45h]
		push	bx
		push	dx
		mov	ax,1
		and	ax,[bp-2]
		push	ax
		mov	ax,[bp-2]
		test	ax,100h
		jz	loc_110
		mov	ax,8
		add	word ptr [bp+4],0Ah
		jmp	short loc_111
loc_110:
		add	word ptr [bp+4],8
		mov	ax,6
loc_111:
		push	ax
		call	sub_42
		push	ss
		pop	es
		lea	di,[bp-45h]
loc_112:
		test	word ptr [bp-2],8
		jz	loc_115
		mov	dx,[bp-8]
		or	dx,dx
		jle	loc_115
loc_113:
		call	sub_23
		cmp	byte ptr es:[di],2Dh	; '-'
		jne	loc_114
		dec	cx
loc_114:
		sub	dx,cx
		jle	loc_115
		mov	[bp-0Eh],dx
loc_115:
		cmp	byte ptr es:[di],2Dh	; '-'
		je	loc_116
		mov	al,[bp-0Bh]
		or	al,al
		jz	loc_117
		dec	di
		mov	es:[di],al
loc_116:
		cmp	word ptr [bp-0Eh],0
		jle	loc_117
		mov	cx,[bp-0Ah]
		or	cx,cx
		jge	loc_117
		dec	word ptr [bp-0Eh]
loc_117:
		call	sub_23
loc_118:
		mov	si,di
		mov	di,[bp-4]
		mov	bx,[bp-8]
		mov	ax,5
		and	ax,[bp-2]
		cmp	ax,5
		jne	loc_119
		mov	ah,[bp-5]
		cmp	ah,6Fh			; 'o'
		jne	loc_120
		cmp	word ptr [bp-0Eh],0
		jg	loc_119
		mov	word ptr [bp-0Eh],1
loc_119:
		jmp	short loc_122
loc_120:
		cmp	ah,78h			; 'x'
		je	loc_121
		cmp	ah,58h			; 'X'
		jne	loc_122
loc_121:
		or	word ptr [bp-2],40h
		dec	bx
		dec	bx
		sub	word ptr [bp-0Eh],2
		jge	loc_122
		mov	word ptr [bp-0Eh],0
loc_122:
		add	cx,[bp-0Eh]
		test	word ptr [bp-2],2
		jnz	loc_125
		jmp	short loc_124
loc_123:
		mov	al,20h			; ' '
		call	sub_24
		dec	bx
loc_124:
		cmp	bx,cx
		jg	loc_123
loc_125:
		test	word ptr [bp-2],40h
		jz	loc_126
		mov	al,30h			; '0'
		call	sub_24
		mov	al,[bp-5]
		call	sub_24
loc_126:
		mov	dx,[bp-0Eh]
		or	dx,dx
		jle	loc_131
		sub	cx,dx
		sub	bx,dx
		mov	al,es:[si]
		cmp	al,2Dh			; '-'
		je	loc_127
		cmp	al,20h			; ' '
		je	loc_127
		cmp	al,2Bh			; '+'
		jne	loc_128
loc_127:
		lods	byte ptr es:[si]
		call	sub_24
		dec	cx
		dec	bx
loc_128:
		xchg	cx,dx
		jcxz	loc_130

locloop_129:
		mov	al,30h			; '0'
		call	sub_24
		loop	locloop_129

loc_130:
		xchg	cx,dx
loc_131:
		jcxz	loc_134
		sub	bx,cx

locloop_132:
		lods	byte ptr es:[si]
		mov	ss:[di],al
		inc	di
		dec	byte ptr [bp-14h]
		jg	loc_133
		call	sub_25
loc_133:
		loop	locloop_132

loc_134:
		or	bx,bx
		jle	loc_136
		mov	cx,bx

locloop_135:
		mov	al,20h			; ' '
		call	sub_24
		loop	locloop_135

loc_136:
		jmp	loc_60
sub_20		endp


;ƒƒƒƒƒ Indexed Entry Point ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ

loc_137:
		mov	[bp+6],si
		mov	di,[bp+4]
		test	word ptr [bp-2],20h
		jnz	loc_138
		mov	di,ss:[di]
		add	word ptr [bp+4],2
		push	ds
		pop	es
		jmp	short loc_139
loc_138:
		les	di,dword ptr ss:[di]
		add	word ptr [bp+4],4
loc_139:
		mov	ax,50h
		sub	al,[bp-14h]
		add	ax,[bp-12h]
		mov	es:[di],ax
		test	word ptr [bp-2],10h
		jz	loc_140
		inc	di
		inc	di
		mov	word ptr es:[di],0
loc_140:
		jmp	loc_59

;ƒƒƒƒƒ Indexed Entry Point ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ

loc_141:
		mov	si,[bp-10h]
		mov	es,[bp+8]
		mov	di,[bp-4]
		mov	al,25h			; '%'
loc_142:
		call	sub_24
		lods	byte ptr es:[si]
		or	al,al
		jnz	loc_142
loc_143:
		cmp	byte ptr [bp-14h],50h	; 'P'
		jge	loc_144
		call	sub_25
loc_144:
		pop	es
		cmp	word ptr [bp-16h],0
		je	loc_145
		mov	ax,0FFFFh
		jmp	short loc_146
loc_145:
		mov	ax,[bp-12h]
loc_146:
		pop	di
		pop	si
		mov	sp,bp
		pop	bp
		retn	0Ch
data_56		dw	offset loc_71		; Data table (indexed access)
data_57		dw	offset loc_69
data_58		dw	offset loc_78
data_59		dw	offset loc_70
data_60		dw	offset loc_82
data_61		dw	offset loc_83
data_62		dw	offset loc_85
data_63		dw	offset loc_86
data_64		dw	offset loc_87
data_65		dw	offset loc_76
data_66		dw	offset loc_93
data_67		dw	offset loc_88
data_68		dw	offset loc_89
data_69		dw	offset loc_90
data_70		dw	offset loc_99
data_71		dw	offset loc_108
data_72		dw	offset loc_102
data_73		dw	offset loc_103
data_74		dw	offset loc_137
data_75		dw	offset loc_141
data_76		dw	offset loc_141
data_77		dw	offset loc_141
data_78		dw	offset loc_73
data_79		dw	offset loc_74
		db	0BAh, 84h, 03h,0EBh, 03h,0BAh
		db	 89h, 03h,0B9h, 05h, 00h,0B4h
		db	 40h,0BBh, 02h, 00h,0CDh, 21h
		db	0B9h, 27h, 00h,0BAh, 8Eh, 03h
		db	0B4h, 40h,0CDh, 21h,0E9h, 79h
		db	0F7h
data_80		db	0, 0
data_81		dw	0			; segment storage
data_82		dw	0			; segment storage
data_83		dw	0			; segment storage
data_84		dw	0
data_85		dw	0

;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_26		proc	near
		cmp	dx,word ptr cs:data_80
		je	loc_149
		mov	ds,dx
		mov	ds,ds:data_18e
		cmp	word ptr ds:data_151e,0
		je	loc_147
		mov	cs:data_81,ds
		jmp	short loc_150
loc_147:
		mov	ax,ds
		cmp	ax,word ptr cs:data_80
		je	loc_148
		mov	ax,ds:data_152e
		mov	cs:data_81,ax
		push	ds
		xor	ax,ax
		push	ax
		call	sub_28
		mov	ds,cs:data_83
		jmp	short loc_151
loc_148:
		mov	dx,word ptr cs:data_80
loc_149:
		mov	word ptr cs:data_80,0
		mov	cs:data_81,0
		mov	cs:data_82,0
loc_150:
		mov	ds,cs:data_83
		push	dx
		xor	ax,ax
		push	ax
loc_151:
		call	sub_39
;*		add	sp,4
		db	 83h,0C4h, 04h
		retn
sub_26		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_27		proc	near
		mov	ds,dx
		push	ds
		mov	es,ds:data_18e
		mov	word ptr ds:data_18e,0
		mov	ds:data_19e,es
		cmp	dx,word ptr cs:data_80
		je	loc_153
		cmp	word ptr es:data_151e,0
		jne	loc_153
		mov	ax,ds:data_17e
		pop	bx
		push	es
		add	es:data_150e,ax
		mov	cx,es
		add	dx,ax
		mov	es,dx
		cmp	word ptr es:data_148e,0
		jne	loc_152
		mov	es:data_149e,cx
		jmp	short loc_154
loc_152:
		mov	es:data_148e,cx
		jmp	short loc_154
loc_153:
		call	sub_29
loc_154:
		pop	es
		mov	ax,es
		add	ax,es:data_150e
		mov	ds,ax
		cmp	word ptr ds:data_154e,0
		je	loc_155
		retn
loc_155:
		mov	ax,ds:data_153e
		add	es:data_150e,ax
		mov	ax,es
		mov	bx,ds
		add	bx,ds:data_153e
		mov	es,bx
		mov	es:data_139e,ax
sub_27		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_28		proc	near
		mov	bx,ds
		cmp	bx,word ptr ds:[6]
		je	loc_156
		mov	es,word ptr ds:[6]
		mov	ds,word ptr ds:[4]
		mov	ds:data_28e,es
		mov	es:data_24e,ds
		mov	cs:data_82,ds
		mov	ds,bx
		retn
loc_156:
		mov	cs:data_82,0
		retn
sub_28		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_29		proc	near
		mov	ax,cs:data_82
		or	ax,ax
		jz	loc_157
		mov	bx,ss
		pushf
		cli
		mov	ss,ax
		mov	es,ss:data_28e
		mov	ss:data_28e,ds
		mov	ds:data_2e,ss
		mov	ss,bx
		popf
		mov	es:data_143e,ds
		mov	ds:data_3e,es
		retn
loc_157:
		mov	cs:data_82,ds
		mov	ds:data_2e,ds
		mov	ds:data_3e,ds
		retn
sub_29		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_30		proc	near
		push	bp
		mov	bp,sp
		push	si
		push	di
		mov	cs:data_83,ds
		mov	dx,[bp+8]
		or	dx,dx
		jz	loc_159
		cmp	dx,cs:data_81
		jne	loc_158
		call	sub_26
		jmp	short loc_159
loc_158:
		call	sub_27
loc_159:
		mov	ds,cs:data_83
		pop	di
		pop	si
		pop	bp
		retf
sub_30		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_31		proc	near
		push	ax
		mov	ds,cs:data_83
		xor	ax,ax
		push	ax
		push	ax
		call	sub_40
;*		add	sp,4
		db	 83h,0C4h, 04h
		and	ax,0Fh
		jz	loc_160
		mov	dx,10h
		sub	dx,ax
		xor	ax,ax
		mov	ds,cs:data_83
		push	ax
		push	dx
		call	sub_40
;*		add	sp,4
		db	 83h,0C4h, 04h
loc_160:
		pop	ax
		push	ax
		xor	bx,bx
		mov	bl,ah
		mov	cl,4
		shr	bx,cl
		shl	ax,cl
		mov	ds,cs:data_83
		push	bx
		push	ax
		call	sub_40
;*		add	sp,4
		db	 83h,0C4h, 04h
		pop	bx
		cmp	ax,0FFFFh
		je	loc_161
		mov	word ptr cs:data_80,dx
		mov	cs:data_81,dx
		mov	ds,dx
		mov	ds:data_20e,bx
		mov	ds:data_21e,dx
		mov	ax,4
		retn
loc_161:
		xor	ax,ax
		cwd
		retn
sub_31		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_32		proc	near
		push	ax
		xor	bx,bx
		mov	bl,ah
		mov	cl,4
		shr	bx,cl
		shl	ax,cl
		mov	ds,cs:data_83
		push	bx
		push	ax
		call	sub_40
;*		add	sp,4
		db	 83h,0C4h, 04h
		pop	bx
		cmp	ax,0FFFFh
		je	loc_164
		and	ax,0Fh
		jnz	loc_163
loc_162:
		mov	cx,cs:data_81
		mov	cs:data_81,dx
		mov	ds,dx
		mov	ds:data_22e,bx
		mov	ds:data_23e,cx
		mov	ax,4
		retn
loc_163:
		push	bx
		push	dx
		neg	ax
		add	ax,10h
		xor	bx,bx
		push	bx
		push	ax
		call	sub_40
;*		add	sp,4
		db	 83h,0C4h, 04h
		pop	dx
		pop	bx
		cmp	ax,0FFFFh
		je	loc_164
		inc	dx
		jmp	short loc_162
loc_164:
		xor	ax,ax
		cwd
		retn
sub_32		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_33		proc	near
		mov	bx,dx
		sub	ds:data_1e,ax
		add	dx,ds:data_1e
		mov	ds,dx
		mov	ds:data_25e,ax
		mov	ds:data_26e,bx
		mov	bx,dx
		add	bx,ds:data_25e
		mov	ds,bx
		mov	ds:data_140e,dx
		mov	ax,4
		retn
sub_33		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_34		proc	near
		push	bp
		mov	bp,sp
		xor	dx,dx
		mov	ax,[bp+6]
		jmp	short loc_165

;ﬂﬂﬂﬂ External Entry into Subroutine ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ

sub_35:
		push	bp
		mov	bp,sp
		mov	dx,[bp+8]
		mov	ax,[bp+6]
loc_165:
		mov	cx,ax
		or	cx,dx
		push	si
		push	di
		mov	cs:data_83,ds
		jz	loc_172
		add	ax,13h
;*		adc	dx,0
		db	 83h,0D2h, 00h
		jc	loc_170
		test	dx,0FFF0h
		jnz	loc_170
		mov	cl,4
		shr	ax,cl
		shl	dx,cl
		or	ah,dl
		mov	dx,word ptr cs:data_80
		or	dx,dx
		jz	loc_168
		mov	dx,cs:data_82
		or	dx,dx
		jz	loc_167
		mov	bx,dx
loc_166:
		mov	ds,dx
		cmp	ds:data_27e,ax
		jae	loc_171
		mov	dx,ds:data_28e
		cmp	dx,bx
		jne	loc_166
loc_167:
		call	sub_32
		jmp	short loc_172
loc_168:
		call	sub_31
		jmp	short loc_172
loc_169:
		call	sub_33
		jmp	short loc_172
loc_170:
		xor	ax,ax
		cwd
		jmp	short loc_172
loc_171:
		ja	loc_169
		call	sub_28
		mov	bx,word ptr ds:[8]
		mov	word ptr ds:[2],bx
		mov	ax,4
loc_172:
		mov	ds,cs:data_83
		pop	di
		pop	si
		pop	bp
		retf
sub_34		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_36		proc	near
		push	bx
		mov	si,cs:data_84
		push	si
		mov	si,cs:data_85
		push	si
		callf	sub_35
;*		add	sp,4
		db	 83h,0C4h, 04h
		or	dx,dx
		jnz	loc_173
		pop	bx
		retn
loc_173:
		pop	ds
		mov	es,dx
		push	es
		push	ds
		push	bx
		mov	dx,ds:data_1e
		cld
		dec	dx
		mov	di,data_145e
		mov	si,di
		mov	cx,6
		rep	movsw
		or	dx,dx
		jz	loc_176
		mov	ax,es
		inc	ax
		mov	es,ax
		mov	ax,ds
		inc	ax
		mov	ds,ax
loc_174:
		xor	di,di
		mov	si,di
		mov	cx,dx
		cmp	cx,1000h
		jbe	loc_175
		mov	cx,1000h
loc_175:
		shl	cx,1
		shl	cx,1
		shl	cx,1
		rep	movsw
		sub	dx,1000h
		jbe	loc_176
		mov	ax,es
		add	ax,1000h
		mov	es,ax
		mov	ax,ds
		add	ax,1000h
		mov	ds,ax
		jmp	short loc_174
loc_176:
		mov	ds,cs:data_83
		callf	sub_30
;*		add	sp,4
		db	 83h,0C4h, 04h
		pop	dx
		mov	ax,4
		retn
sub_36		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_37		proc	near
		cmp	bx,cs:data_81
		je	loc_179
		mov	di,bx
		add	di,ax
		mov	es,di
		mov	si,cx
		sub	si,ax
		mov	es:data_146e,si
		mov	es:data_147e,bx
		push	es
		push	ax
		mov	es,bx
		mov	es:data_144e,ax
		mov	dx,bx
		add	dx,cx
		mov	es,dx
		cmp	word ptr es:data_141e,0
		je	loc_177
		mov	es:data_141e,di
		jmp	short loc_178
loc_177:
		mov	es:data_142e,di
loc_178:
		mov	si,bx
		callf	sub_30
;*		add	sp,4
		db	 83h,0C4h, 04h
		mov	dx,si
		mov	ax,4
		retn
loc_179:
		push	bx
		mov	es,bx
		mov	es:data_144e,ax
		add	bx,ax
		push	bx
		xor	ax,ax
		push	ax
		call	sub_39
;*		add	sp,4
		db	 83h,0C4h, 04h
		pop	dx
		mov	ax,4
		retn
sub_37		endp

			                        ;* No entry point to code
		push	bp
		mov	bp,sp
		xor	dx,dx
		jmp	short loc_180
			                        ;* No entry point to code
		push	bp
		mov	bp,sp
		mov	dx,[bp+0Ch]
loc_180:
		mov	ax,[bp+0Ah]
		mov	bx,[bp+8]
		push	si
		push	di
		mov	cs:data_83,ds
		mov	cs:data_84,dx
		mov	cs:data_85,ax
		or	bx,bx
		jz	loc_183
		mov	cx,ax
		or	cx,dx
		jz	loc_184
		add	ax,13h
;*		adc	dx,0
		db	 83h,0D2h, 00h
		jc	loc_185
		test	dx,0FFF0h
		jnz	loc_185
		mov	cl,4
		shr	ax,cl
		shl	dx,cl
		or	ah,dl
		mov	es,bx
		mov	cx,es:data_144e
		cmp	cx,ax
		jb	loc_182
		ja	loc_181
		mov	dx,bx
		mov	ax,4
		jmp	short loc_186
loc_181:
		call	sub_37
		jmp	short loc_186
loc_182:
		call	sub_36
		jmp	short loc_186
loc_183:
		push	dx
		push	ax
		callf	sub_35
;*		add	sp,4
		db	 83h,0C4h, 04h
		jmp	short loc_186
loc_184:
		push	bx
		push	ax
		callf	sub_30
;*		add	sp,4
		db	 83h,0C4h, 04h
loc_185:
		xor	ax,ax
		cwd
loc_186:
		mov	ds,cs:data_83
		pop	di
		pop	si
		pop	bp
		retf

;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_38		proc	near
		push	bp
		mov	bp,sp
		push	si
		mov	si,[bp+6]
		inc	si
		sub	si,ds:data_6e
;*		add	si,3Fh
		db	 83h,0C6h, 3Fh
		mov	cl,6
		shr	si,cl
		cmp	si,ds:data_14e
		jne	loc_188
loc_187:
		mov	ax,[bp+6]
		mov	dx,[bp+4]
		mov	ds:data_10e,ax
		mov	ds:data_9e,dx
		mov	ax,1
		jmp	short loc_191
loc_188:
		mov	cl,6
		shl	si,cl
		mov	dx,ds:data_12e
		mov	ax,si
		add	ax,ds:data_6e
		cmp	ax,dx
		jbe	loc_189
		mov	si,dx
		sub	si,ds:data_6e
loc_189:
		push	si
		push	word ptr ds:data_6e
		nop
		callf	sub_43
		pop	cx
		pop	cx
		mov	dx,ax
;*		cmp	dx,0FFFFh
		db	 83h,0FAh,0FFh
		jnz	loc_190
		mov	ax,si
		mov	cl,6
		shr	ax,cl
		mov	ds:data_14e,ax
		jmp	short loc_187
loc_190:
		mov	ax,ds:data_6e
		add	ax,dx
		mov	ds:data_12e,ax
		mov	word ptr ds:data_11e,0
		xor	ax,ax
loc_191:
		pop	si
		pop	bp
		retn	4
sub_38		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_39		proc	near
		push	bp
		mov	bp,sp
		mov	cx,ds:data_8e
		mov	bx,ds:data_7e
		mov	dx,[bp+6]
		mov	ax,[bp+4]
		call	sub_17
		jc	loc_192
		mov	cx,ds:data_12e
		mov	bx,ds:data_11e
		mov	dx,[bp+6]
		mov	ax,[bp+4]
		call	sub_17
		ja	loc_192
		push	word ptr [bp+6]
		push	word ptr [bp+4]
		call	sub_38
		or	ax,ax
		jnz	loc_193
loc_192:
		mov	ax,0FFFFh
		jmp	short loc_194
loc_193:
		xor	ax,ax
loc_194:
		pop	bp
		retn
sub_39		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_40		proc	near
		push	bp
		mov	bp,sp
;*		sub	sp,8
		db	 83h,0ECh, 08h
		mov	ax,ds:data_10e
		xor	dx,dx
		mov	cl,4
		call	sub_11
		add	ax,ds:data_9e
;*		adc	dx,0
		db	 83h,0D2h, 00h
		add	ax,[bp+4]
		adc	dx,[bp+6]
;*		cmp	dx,0Fh
		db	 83h,0FAh, 0Fh
		jl	loc_196
		jg	loc_195
		cmp	ax,0FFFFh
		jbe	loc_196
loc_195:
		mov	dx,0FFFFh
		mov	ax,0FFFFh
		jmp	short loc_197
loc_196:
		mov	dx,ds:data_10e
		mov	ax,ds:data_9e
		mov	cx,[bp+6]
		mov	bx,[bp+4]
		call	sub_12
		mov	[bp-2],dx
		mov	[bp-4],ax
		mov	cx,ds:data_8e
		mov	bx,ds:data_7e
		mov	dx,[bp-2]
		call	sub_17
		jc	loc_195
		mov	cx,ds:data_12e
		mov	bx,ds:data_11e
		mov	dx,[bp-2]
		mov	ax,[bp-4]
		call	sub_17
		ja	loc_195
		mov	ax,ds:data_10e
		mov	dx,ds:data_9e
		mov	[bp-6],ax
		mov	[bp-8],dx
		push	word ptr [bp-2]
		push	word ptr [bp-4]
		call	sub_38
		or	ax,ax
		jz	loc_195
		mov	dx,[bp-6]
		mov	ax,[bp-8]
loc_197:
		mov	sp,bp
		pop	bp
		retn
sub_40		endp

			                        ;* No entry point to code
		push	bp
		mov	bp,sp
;*		sub	sp,8
		db	 83h,0ECh, 08h
		push	ss
		lea	ax,[bp-8]
		push	ax
		nop
		callf	sub_18
		pop	cx
		pop	cx
		push	ss
		lea	ax,[bp-8]
		push	ax
		push	word ptr [bp+0Eh]
		push	word ptr [bp+0Ch]
		push	word ptr [bp+0Ah]
		push	word ptr [bp+8]
		push	word ptr [bp+6]
		callf	sub_41
;*		add	sp,0Eh
		db	 83h,0C4h, 0Eh
		mov	sp,bp
		pop	bp
		retf

;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_41		proc	far
		push	bp
		mov	bp,sp
;*		sub	sp,0Eh
		db	 83h,0ECh, 0Eh
		push	si
		push	di
		push	ds
		lea	cx,[bp-0Eh]
		mov	[bp-4],cx
		mov	[bp-2],ss
		mov	byte ptr [bp-0Eh],55h	; 'U'
		mov	byte ptr [bp-0Dh],0CDh
		mov	ax,[bp+6]
		mov	[bp-0Ch],al
		mov	word ptr [bp-0Bh],0CB5Dh
		cmp	al,25h			; '%'
		jb	loc_198
		cmp	al,26h			; '&'
		ja	loc_198
		mov	byte ptr [bp-0Bh],36h	; '6'
		mov	word ptr [bp-0Ah],68Fh
		mov	[bp-8],cx
		mov	word ptr [bp-6],0CB5Dh
loc_198:
		lds	si,dword ptr [bp+10h]
		push	word ptr [si]
		push	word ptr [si+6]
		lds	si,dword ptr [bp+8]
		mov	ax,[si]
		mov	bx,[si+2]
		mov	cx,[si+4]
		mov	dx,[si+6]
		mov	di,[si+0Ah]
		mov	si,[si+8]
		pop	ds
		pop	es
		call	dword ptr [bp-4]	;*
		pushf
		pushf
		push	si
		push	ds
		push	es
		lds	si,dword ptr [bp+10h]
		pop	word ptr [si]
		pop	word ptr [si+6]
		lds	si,dword ptr [bp+0Ch]
		pop	word ptr [si+8]
		pop	word ptr [si+0Eh]
		pop	word ptr [si+0Ch]
		and	word ptr [si+0Ch],1
		mov	[si+0Ah],di
		mov	[si+6],dx
		mov	[si+4],cx
		mov	[si+2],bx
		mov	[si],ax
		pop	ds
		jz	loc_199
		push	ax
		push	ax
		call	sub_13
		pop	ax
loc_199:
		pop	di
		pop	si
		mov	sp,bp
		pop	bp
		retf
sub_41		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_42		proc	near
		jmp	word ptr ds:[3BEh]

;ﬂﬂﬂﬂ External Entry into Subroutine ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ

sub_43:
		push	bp
		mov	bp,sp
		mov	ah,4Ah			; 'J'
		mov	bx,[bp+8]
		mov	es,[bp+6]
		int	21h
		jc	loc_200
		mov	ax,0FFFFh
		jmp	short loc_201
loc_200:
		push	bx
		push	ax
		call	sub_13
		pop	ax
loc_201:
		pop	bp
		retf
sub_42		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_44		proc	near
		push	bp
		mov	bp,sp
		push	si
		mov	ax,[bp+6]
		or	ax,[bp+8]
		jnz	loc_202
		nop
		callf	sub_45
		jmp	loc_208
loc_202:
		les	bx,dword ptr [bp+6]
		mov	ax,es:[bx+12h]
		cmp	ax,[bp+6]
		je	loc_204
loc_203:
		mov	ax,0FFFFh
		jmp	loc_209
loc_204:
		les	bx,dword ptr [bp+6]
		cmp	word ptr es:[bx],0
		jl	loc_207
		test	word ptr es:[bx+2],8
		jnz	loc_206
		mov	ax,es:[bx+0Eh]
		mov	dx,[bp+6]
;*		add	dx,5
		db	 83h,0C2h, 05h
		cmp	ax,[bp+8]
		je	loc_205
		jmp	loc_208
loc_205:
		cmp	es:[bx+0Ch],dx
		jne	loc_208
loc_206:
		les	bx,dword ptr [bp+6]
		mov	word ptr es:[bx],0
		mov	ax,es:[bx+0Eh]
		mov	dx,[bp+6]
;*		add	dx,5
		db	 83h,0C2h, 05h
		cmp	ax,[bp+8]
		jne	loc_208
		cmp	es:[bx+0Ch],dx
		jne	loc_208
		mov	ax,es:[bx+0Ah]
		mov	dx,es:[bx+8]
		mov	es:[bx+0Eh],ax
		mov	es:[bx+0Ch],dx
		jmp	short loc_208
		db	0EBh, 48h
loc_207:
		les	bx,dword ptr [bp+6]
		mov	ax,es:[bx+6]
		add	ax,es:[bx]
		inc	ax
		mov	si,ax
		sub	es:[bx],si
		push	ax
		mov	ax,es:[bx+0Ah]
		mov	dx,es:[bx+8]
		mov	es:[bx+0Eh],ax
		mov	es:[bx+0Ch],dx
		push	ax
		push	dx
		mov	al,es:[bx+4]
		cbw
		push	ax
		nop
		callf	sub_52
;*		add	sp,8
		db	 83h,0C4h, 08h
		cmp	ax,si
		je	loc_208
		les	bx,dword ptr [bp+6]
		test	word ptr es:[bx+2],200h
		jnz	loc_208
		or	word ptr es:[bx+2],10h
		jmp	loc_203
loc_208:
		xor	ax,ax
loc_209:
		pop	si
		pop	bp
		retf
sub_44		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_45		proc	near
		push	bp
		mov	bp,sp
;*		sub	sp,4
		db	 83h,0ECh, 04h
		push	si
		push	di
		xor	di,di
		mov	si,word ptr ds:[294h]
		mov	[bp-2],ds
		mov	word ptr [bp-4],104h
		jmp	short loc_212
loc_210:
		les	bx,dword ptr [bp-4]
		test	word ptr es:[bx+2],3
		jz	loc_211
		push	word ptr [bp-2]
		push	bx
		nop
		callf	sub_44
		pop	cx
		pop	cx
		inc	di
loc_211:
		add	word ptr [bp-4],14h
loc_212:
		mov	ax,si
		dec	si
		or	ax,ax
		jnz	loc_210
		mov	ax,di
		pop	di
		pop	si
		mov	sp,bp
		pop	bp
		retf
sub_45		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_46		proc	near
		push	bp
		mov	bp,sp
;*		sub	sp,4
		db	 83h,0ECh, 04h
		push	si
		les	bx,dword ptr [bp+4]
		cmp	word ptr es:[bx],0
		jge	loc_213
		mov	cx,es:[bx+6]
		add	cx,es:[bx]
		inc	cx
		mov	si,cx
		jmp	short loc_214
loc_213:
		les	bx,dword ptr [bp+4]
		mov	ax,es:[bx]
		cwd
		xor	ax,dx
		sub	ax,dx
		mov	cx,ax
		mov	si,ax
loc_214:
		les	bx,dword ptr [bp+4]
		test	word ptr es:[bx+2],40h
		jnz	loc_219
		les	bx,dword ptr [bp+4]
		mov	ax,es:[bx+0Eh]
		mov	dx,es:[bx+0Ch]
		mov	[bp-2],ax
		mov	[bp-4],dx
		cmp	word ptr es:[bx],0
		jge	loc_218
		jmp	short loc_216
loc_215:
		dec	word ptr [bp-4]
		les	bx,dword ptr [bp-4]
		cmp	byte ptr es:[bx],0Ah
		jne	loc_216
		inc	si
loc_216:
		mov	ax,cx
		dec	cx
		or	ax,ax
		jnz	loc_215
		jmp	short loc_219
loc_217:
		les	bx,dword ptr [bp-4]
		inc	word ptr [bp-4]
		cmp	byte ptr es:[bx],0Ah
		jne	loc_218
		inc	si
loc_218:
		mov	ax,cx
		dec	cx
		or	ax,ax
		jnz	loc_217
loc_219:
		mov	ax,si
		pop	si
		mov	sp,bp
		pop	bp
		retn	4
sub_46		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_47		proc	near
		push	bp
		mov	bp,sp
		push	si
		mov	si,[bp+0Eh]
		push	word ptr [bp+8]
		push	word ptr [bp+6]
		nop
		callf	sub_44
		pop	cx
		pop	cx
		or	ax,ax
		jz	loc_220
		mov	ax,0FFFFh
		jmp	short loc_223
loc_220:
;*		cmp	si,1
		db	 83h,0FEh, 01h
		jnz	loc_221
		les	bx,dword ptr [bp+6]
		cmp	word ptr es:[bx],0
		jle	loc_221
		push	word ptr [bp+8]
		push	bx
		call	sub_46
		cwd
		sub	[bp+0Ah],ax
		sbb	[bp+0Ch],dx
loc_221:
		les	bx,dword ptr [bp+6]
		and	word ptr es:[bx+2],0FE5Fh
		mov	word ptr es:[bx],0
		mov	ax,es:[bx+0Ah]
		mov	dx,es:[bx+8]
		mov	es:[bx+0Eh],ax
		mov	es:[bx+0Ch],dx
		push	si
		push	word ptr [bp+0Ch]
		push	word ptr [bp+0Ah]
		mov	al,es:[bx+4]
		cbw
		push	ax
		nop
		callf	sub_16
;*		add	sp,8
		db	 83h,0C4h, 08h
;*		cmp	dx,0FFFFh
		db	 83h,0FAh,0FFh
		jnz	loc_222
		cmp	ax,0FFFFh
		jne	loc_222
		mov	ax,0FFFFh
		jmp	short loc_223
loc_222:
		xor	ax,ax
loc_223:
		pop	si
		pop	bp
		retf
sub_47		endp

			                        ;* No entry point to code
		push	bp
		mov	bp,sp
;*		sub	sp,4
		db	 83h,0ECh, 04h
		les	bx,dword ptr [bp+6]
		mov	al,es:[bx+4]
		cbw
		push	ax
		nop
		callf	sub_19
		pop	cx
		mov	[bp-2],dx
		mov	[bp-4],ax
;*		cmp	dx,0FFFFh
		db	 83h,0FAh,0FFh
		jnz	loc_224
		cmp	ax,0FFFFh
		je	loc_226
loc_224:
		les	bx,dword ptr [bp+6]
		cmp	word ptr es:[bx],0
		jge	loc_225
		push	word ptr [bp+8]
		push	bx
		call	sub_46
		cwd
		add	[bp-4],ax
		adc	[bp-2],dx
		jmp	short loc_226
loc_225:
		push	word ptr [bp+8]
		push	word ptr [bp+6]
		call	sub_46
		cwd
		sub	[bp-4],ax
		sbb	[bp-2],dx
loc_226:
		mov	dx,[bp-2]
		mov	ax,[bp-4]
		mov	sp,bp
		pop	bp
		retf

;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_48		proc	near
		push	bp
		mov	bp,sp
		push	si
		push	di
		mov	dx,ds
		les	di,dword ptr [bp+6]
		lds	si,dword ptr [bp+0Ah]
		mov	cx,[bp+0Eh]
		shr	cx,1
		cld
		rep	movsw
		jnc	loc_227
		movsb
loc_227:
		mov	ds,dx
		mov	dx,[bp+8]
		mov	ax,[bp+6]
		pop	di
		pop	si
		pop	bp
		retf
sub_48		endp

			                        ;* No entry point to code
		push	bp
		mov	bp,sp
		mov	ax,159Ah
		push	ax
		push	ds
		mov	ax,118h
		push	ax
		push	word ptr [bp+8]
		push	word ptr [bp+6]
		lea	ax,[bp+0Ah]
		push	ax
		call	sub_22
		pop	bp
		retf

;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_49		proc	near
		push	bp
		mov	bp,sp
		les	bx,dword ptr [bp+8]
		dec	word ptr es:[bx]
		push	word ptr [bp+0Ah]
		push	bx
		mov	al,[bp+6]
		cbw
		push	ax
		nop
		callf	sub_50
;*		add	sp,6
		db	 83h,0C4h, 06h
		pop	bp
		retf
sub_49		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_50		proc	near
		push	bp
		mov	bp,sp
		push	si
		mov	al,[bp+6]
		mov	byte ptr ds:[44Ch],al
		les	bx,dword ptr [bp+8]
		cmp	word ptr es:[bx],0FFFFh
		jge	loc_231
		inc	word ptr es:[bx]
		mov	ax,es:[bx+0Eh]
		mov	si,es:[bx+0Ch]
		inc	word ptr es:[bx+0Ch]
		mov	dl,byte ptr ds:[44Ch]
		mov	es,ax
		mov	es:[si],dl
		mov	es,[bp+0Ah]
		test	word ptr es:[bx+2],8
		jnz	loc_228
		jmp	loc_242
loc_228:
		cmp	byte ptr ds:[44Ch],0Ah
		je	loc_229
		cmp	byte ptr ds:[44Ch],0Dh
		je	loc_229
		jmp	loc_242
loc_229:
		push	word ptr [bp+0Ah]
		push	word ptr [bp+8]
		nop
		callf	sub_44
		pop	cx
		pop	cx
		or	ax,ax
		jnz	loc_230
		jmp	loc_242
loc_230:
		mov	ax,0FFFFh
		jmp	loc_243
		db	0E9h, 24h, 01h
loc_231:
		les	bx,dword ptr [bp+8]
		test	word ptr es:[bx+2],90h
		jnz	loc_232
		test	word ptr es:[bx+2],2
		jnz	loc_233
loc_232:
		les	bx,dword ptr [bp+8]
		or	word ptr es:[bx+2],10h
		jmp	short loc_230
loc_233:
		les	bx,dword ptr [bp+8]
		or	word ptr es:[bx+2],100h
		cmp	word ptr es:[bx+6],0
		je	loc_238
		cmp	word ptr es:[bx],0
		je	loc_234
		push	word ptr [bp+0Ah]
		push	bx
		nop
		callf	sub_44
		pop	cx
		pop	cx
		or	ax,ax
		jnz	loc_230
loc_234:
		les	bx,dword ptr [bp+8]
		mov	ax,es:[bx+6]
		neg	ax
		mov	es:[bx],ax
		mov	ax,es:[bx+0Eh]
		mov	si,es:[bx+0Ch]
		inc	word ptr es:[bx+0Ch]
		mov	dl,byte ptr ds:[44Ch]
		mov	es,ax
		mov	es:[si],dl
		mov	es,[bp+0Ah]
		test	word ptr es:[bx+2],8
		jnz	loc_235
		jmp	loc_242
loc_235:
		cmp	byte ptr ds:[44Ch],0Ah
		je	loc_236
		cmp	byte ptr ds:[44Ch],0Dh
		je	loc_236
		jmp	loc_242
loc_236:
		push	word ptr [bp+0Ah]
		push	word ptr [bp+8]
		nop
		callf	sub_44
		pop	cx
		pop	cx
		or	ax,ax
		jnz	loc_237
		jmp	loc_242
loc_237:
		jmp	loc_230
		db	0E9h, 88h, 00h
loc_238:
		les	bx,dword ptr [bp+8]
		mov	al,es:[bx+4]
		cbw
		shl	ax,1
		mov	bx,ax
		test	word ptr ds:[296h][bx],800h
		jz	loc_239
		mov	ax,2
		push	ax
		xor	ax,ax
		push	ax
		push	ax
		mov	bx,[bp+8]
		mov	al,es:[bx+4]
		cbw
		push	ax
		nop
		callf	sub_16
;*		add	sp,8
		db	 83h,0C4h, 08h
loc_239:
		cmp	byte ptr ds:[44Ch],0Ah
		jne	loc_240
		les	bx,dword ptr [bp+8]
		test	word ptr es:[bx+2],40h
		jnz	loc_240
		mov	ax,1
		push	ax
		push	ds
		mov	ax,3B8h
		push	ax
		mov	al,es:[bx+4]
		cbw
		push	ax
		nop
		callf	sub_53
;*		add	sp,8
		db	 83h,0C4h, 08h
		cmp	ax,1
		jne	loc_241
loc_240:
		mov	ax,1
		push	ax
		push	ds
		mov	ax,44Ch
		push	ax
		les	bx,dword ptr [bp+8]
		mov	al,es:[bx+4]
		cbw
		push	ax
		nop
		callf	sub_53
;*		add	sp,8
		db	 83h,0C4h, 08h
		cmp	ax,1
		je	loc_242
loc_241:
		les	bx,dword ptr [bp+8]
		test	word ptr es:[bx+2],200h
		jnz	loc_242
		jmp	loc_232
loc_242:
		mov	al,byte ptr ds:[44Ch]
		mov	ah,0
loc_243:
		pop	si
		pop	bp
		retf
sub_50		endp

			                        ;* No entry point to code
		push	bp
		mov	bp,sp
		push	ds
		mov	ax,118h
		push	ax
		push	word ptr [bp+6]
		callf	sub_50
;*		add	sp,6
		db	 83h,0C4h, 06h
		pop	bp
		retf
			                        ;* No entry point to code
		push	bp
		mov	bp,sp
;*		sub	sp,2
		db	 83h,0ECh, 02h
		push	si
		push	di
		mov	di,[bp+8]
		mov	[bp-2],di
		les	bx,dword ptr [bp+4]
		test	word ptr es:[bx+2],8
		jz	loc_247
		jmp	short loc_246
loc_244:
		push	word ptr [bp+6]
		push	word ptr [bp+4]
		les	bx,dword ptr [bp+0Ah]
		inc	word ptr [bp+0Ah]
		mov	al,es:[bx]
		cbw
		push	ax
		callf	sub_50
;*		add	sp,6
		db	 83h,0C4h, 06h
		cmp	ax,0FFFFh
		jne	loc_246
loc_245:
		xor	ax,ax
		jmp	loc_266
loc_246:
		mov	ax,di
		dec	di
		or	ax,ax
		jnz	loc_244
		jmp	loc_265
loc_247:
		les	bx,dword ptr [bp+4]
		test	word ptr es:[bx+2],40h
		jnz	loc_248
		jmp	loc_259
loc_248:
		cmp	word ptr es:[bx+6],0
		jne	loc_249
		jmp	loc_256
loc_249:
		cmp	es:[bx+6],di
		jae	loc_253
		cmp	word ptr es:[bx],0
		je	loc_250
		push	word ptr [bp+6]
		push	bx
		nop
		callf	sub_44
		pop	cx
		pop	cx
		or	ax,ax
		jnz	loc_245
loc_250:
		les	bx,dword ptr [bp+4]
		mov	al,es:[bx+4]
		cbw
		shl	ax,1
		mov	bx,ax
		test	word ptr ds:[296h][bx],800h
		jz	loc_251
		mov	ax,2
		push	ax
		xor	ax,ax
		push	ax
		push	ax
		mov	bx,[bp+4]
		mov	al,es:[bx+4]
		cbw
		push	ax
		nop
		callf	sub_16
;*		add	sp,8
		db	 83h,0C4h, 08h
loc_251:
		push	di
		push	word ptr [bp+0Ch]
		push	word ptr [bp+0Ah]
		les	bx,dword ptr [bp+4]
		mov	al,es:[bx+4]
		cbw
		push	ax
		nop
		callf	sub_53
;*		add	sp,8
		db	 83h,0C4h, 08h
		cmp	ax,di
		jb	loc_252
		jmp	loc_265
loc_252:
		jmp	loc_245
		db	0E9h, 28h, 01h
loc_253:
		les	bx,dword ptr [bp+4]
		mov	ax,es:[bx]
		add	ax,di
		jl	loc_255
		cmp	word ptr es:[bx],0
		jne	loc_254
		mov	ax,0FFFFh
		sub	ax,es:[bx+6]
		mov	es:[bx],ax
		jmp	short loc_255
loc_254:
		push	word ptr [bp+6]
		push	word ptr [bp+4]
		nop
		callf	sub_44
		pop	cx
		pop	cx
		or	ax,ax
		jz	loc_255
		jmp	loc_245
loc_255:
		push	di
		push	word ptr [bp+0Ch]
		push	word ptr [bp+0Ah]
		les	bx,dword ptr [bp+4]
		push	word ptr es:[bx+0Eh]
		push	word ptr es:[bx+0Ch]
		nop
		callf	sub_48
;*		add	sp,0Ah
		db	 83h,0C4h, 0Ah
		les	bx,dword ptr [bp+4]
		mov	ax,es:[bx]
		add	ax,di
		mov	es:[bx],ax
		add	es:[bx+0Ch],di
		jmp	loc_265
loc_256:
		les	bx,dword ptr [bp+4]
		mov	al,es:[bx+4]
		cbw
		shl	ax,1
		mov	bx,ax
		test	word ptr ds:[296h][bx],800h
		jz	loc_257
		mov	ax,2
		push	ax
		xor	ax,ax
		push	ax
		push	ax
		mov	bx,[bp+4]
		mov	al,es:[bx+4]
		cbw
		push	ax
		nop
		callf	sub_16
;*		add	sp,8
		db	 83h,0C4h, 08h
loc_257:
		push	di
		push	word ptr [bp+0Ch]
		push	word ptr [bp+0Ah]
		les	bx,dword ptr [bp+4]
		mov	al,es:[bx+4]
		cbw
		push	ax
		nop
		callf	sub_53
;*		add	sp,8
		db	 83h,0C4h, 08h
		cmp	ax,di
		jb	loc_258
		jmp	loc_265
loc_258:
		jmp	loc_245
		db	0EBh, 7Bh
loc_259:
		les	bx,dword ptr [bp+4]
		cmp	word ptr es:[bx+6],0
		je	loc_264
		jmp	short loc_263
loc_260:
		les	bx,dword ptr [bp+4]
		inc	word ptr es:[bx]
		jge	loc_261
		mov	ax,es:[bx+0Eh]
		mov	si,es:[bx+0Ch]
		inc	word ptr es:[bx+0Ch]
		les	bx,dword ptr [bp+0Ah]
		inc	word ptr [bp+0Ah]
		mov	dl,es:[bx]
		mov	es,ax
		mov	es:[si],dl
		mov	al,dl
		mov	ah,0
		jmp	short loc_262
loc_261:
		push	word ptr [bp+6]
		push	word ptr [bp+4]
		les	bx,dword ptr [bp+0Ah]
		inc	word ptr [bp+0Ah]
		mov	al,es:[bx]
		push	ax
		callf	sub_49
;*		add	sp,6
		db	 83h,0C4h, 06h
loc_262:
		cmp	ax,0FFFFh
		jne	loc_263
		jmp	loc_245
loc_263:
		mov	ax,di
		dec	di
		or	ax,ax
		jnz	loc_260
		jmp	short loc_265
loc_264:
		push	di
		push	word ptr [bp+0Ch]
		push	word ptr [bp+0Ah]
		les	bx,dword ptr [bp+4]
		mov	al,es:[bx+4]
		cbw
		push	ax
		nop
		callf	sub_52
;*		add	sp,8
		db	 83h,0C4h, 08h
		cmp	ax,di
		jae	loc_265
		jmp	loc_245
loc_265:
		mov	ax,[bp-2]
loc_266:
		pop	di
		pop	si
		mov	sp,bp
		pop	bp
		retn	0Ah

;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_51		proc	near
		push	bp
		mov	bp,sp
		push	si
		push	di
		mov	di,[bp+0Eh]
		mov	si,[bp+10h]
		les	bx,dword ptr [bp+6]
		mov	ax,es:[bx+12h]
		cmp	ax,[bp+6]
		jne	loc_267
;*		cmp	di,2
		db	 83h,0FFh, 02h
		jg	loc_267
		cmp	si,7FFFh
		jbe	loc_268
loc_267:
		mov	ax,0FFFFh
		jmp	loc_276
loc_268:
		cmp	word ptr ds:[3BCh],0
		jne	loc_269
		cmp	word ptr [bp+6],118h
		jne	loc_269
		mov	word ptr ds:[3BCh],1
		jmp	short loc_270
loc_269:
		cmp	word ptr ds:[3BAh],0
		jne	loc_270
		cmp	word ptr [bp+6],104h
		jne	loc_270
		mov	word ptr ds:[3BAh],1
loc_270:
		les	bx,dword ptr [bp+6]
		cmp	word ptr es:[bx],0
		je	loc_271
		mov	ax,1
		push	ax
		xor	ax,ax
		push	ax
		push	ax
		push	word ptr [bp+8]
		push	bx
		nop
		callf	sub_47
;*		add	sp,0Ah
		db	 83h,0C4h, 0Ah
loc_271:
		les	bx,dword ptr [bp+6]
		test	word ptr es:[bx+2],4
		jz	loc_272
		push	word ptr es:[bx+0Ah]
		push	word ptr es:[bx+8]
		nop
		callf	sub_30
		pop	cx
		pop	cx
loc_272:
		les	bx,dword ptr [bp+6]
		and	word ptr es:[bx+2],0FFF3h
		mov	word ptr es:[bx+6],0
		mov	ax,[bp+8]
		mov	dx,[bp+6]
;*		add	dx,5
		db	 83h,0C2h, 05h
		mov	es:[bx+0Ah],ax
		mov	es:[bx+8],dx
		mov	es:[bx+0Eh],ax
		mov	es:[bx+0Ch],dx
;*		cmp	di,2
		db	 83h,0FFh, 02h
		jz	loc_275
		or	si,si
		jbe	loc_275
		mov	word ptr ds:[0FAh],seg_a
		mov	word ptr ds:[0F8h],1A3Fh
		mov	ax,[bp+0Ah]
		or	ax,[bp+0Ch]
		jnz	loc_274
		push	si
		nop
		callf	sub_34
		pop	cx
		mov	[bp+0Ch],dx
		mov	[bp+0Ah],ax
		or	ax,dx
		jnz	loc_273
		jmp	loc_267
loc_273:
		les	bx,dword ptr [bp+6]
		or	word ptr es:[bx+2],4
		jmp	short loc_274
		db	0E9h, 34h,0FFh
loc_274:
		les	bx,dword ptr [bp+6]
		mov	ax,[bp+0Ch]
		mov	dx,[bp+0Ah]
		mov	es:[bx+0Eh],ax
		mov	es:[bx+0Ch],dx
		mov	es:[bx+0Ah],ax
		mov	es:[bx+8],dx
		mov	es:[bx+6],si
;*		cmp	di,1
		db	 83h,0FFh, 01h
		jnz	loc_275
		or	word ptr es:[bx+2],8
loc_275:
		xor	ax,ax
loc_276:
		pop	di
		pop	si
		pop	bp
		retf
sub_51		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_52		proc	near
		push	bp
		mov	bp,sp
		sub	sp,8Eh
		push	si
		push	di
		mov	di,[bp+6]
		cmp	di,word ptr ds:[294h]
		jb	loc_277
		mov	ax,6
		push	ax
		call	sub_13
		jmp	loc_292
loc_277:
		mov	ax,[bp+0Ch]
		inc	ax
		cmp	ax,2
		jae	loc_278
		xor	ax,ax
		jmp	loc_292
loc_278:
		mov	bx,di
		shl	bx,1
		test	word ptr ds:[296h][bx],800h
		jz	loc_279
		mov	ax,2
		push	ax
		xor	ax,ax
		push	ax
		push	ax
		push	di
		nop
		callf	sub_16
;*		add	sp,8
		db	 83h,0C4h, 08h
loc_279:
		mov	bx,di
		shl	bx,1
		test	word ptr ds:[296h][bx],4000h
		jnz	loc_280
		push	word ptr [bp+0Ch]
		push	word ptr [bp+0Ah]
		push	word ptr [bp+8]
		push	di
		nop
		callf	sub_53
;*		add	sp,8
		db	 83h,0C4h, 08h
		jmp	loc_292
loc_280:
		mov	bx,di
		shl	bx,1
		and	word ptr ds:[296h][bx],0FDFFh
		mov	ax,[bp+0Ah]
		mov	dx,[bp+8]
		mov	[bp-0Ah],ax
		mov	[bp-0Ch],dx
		mov	ax,[bp+0Ch]
		mov	[bp-6],ax
		jmp	short loc_286
loc_281:
		dec	word ptr [bp-6]
		les	bx,dword ptr [bp-0Ch]
		inc	word ptr [bp-0Ch]
		mov	al,es:[bx]
		mov	[bp-7],al
		cmp	al,0Ah
		jne	loc_282
		les	bx,dword ptr [bp-4]
		mov	byte ptr es:[bx],0Dh
		inc	word ptr [bp-4]
loc_282:
		les	bx,dword ptr [bp-4]
		mov	al,[bp-7]
		mov	es:[bx],al
		inc	word ptr [bp-4]
		lea	ax,cs:[0FF72h][bp]
		mov	dx,[bp-4]
		xor	bx,bx
		sub	dx,ax
;*		sbb	bx,0
		db	 83h,0DBh, 00h
		or	bx,bx
		jl	loc_287
		jnz	loc_283
		cmp	dx,80h
		jb	loc_287
loc_283:
		lea	ax,cs:[0FF72h][bp]
		mov	si,[bp-4]
		xor	dx,dx
		sub	si,ax
;*		sbb	dx,0
		db	 83h,0DAh, 00h
		push	si
		push	ss
		push	ax
		push	di
		nop
		callf	sub_53
;*		add	sp,8
		db	 83h,0C4h, 08h
		mov	dx,ax
		cmp	ax,si
		je	loc_286
;*		cmp	dx,0FFFFh
		db	 83h,0FAh,0FFh
		jnz	loc_285
loc_284:
		mov	ax,0FFFFh
		jmp	short loc_290
loc_285:
		mov	ax,[bp+0Ch]
		sub	ax,[bp-6]
		jmp	short loc_289
loc_286:
		lea	ax,cs:[0FF72h][bp]
		mov	[bp-2],ss
		mov	[bp-4],ax
loc_287:
		cmp	word ptr [bp-6],0
		je	loc_288
		jmp	loc_281
loc_288:
		lea	ax,cs:[0FF72h][bp]
		mov	si,[bp-4]
		xor	dx,dx
		sub	si,ax
;*		sbb	dx,0
		db	 83h,0DAh, 00h
		mov	ax,si
		or	ax,ax
		jbe	loc_291
		push	si
		push	ss
		lea	ax,cs:[0FF72h][bp]
		push	ax
		push	di
		nop
		callf	sub_53
;*		add	sp,8
		db	 83h,0C4h, 08h
		mov	dx,ax
		cmp	ax,si
		je	loc_291
;*		cmp	dx,0FFFFh
		db	 83h,0FAh,0FFh
		jz	loc_284
		mov	ax,[bp+0Ch]
loc_289:
		add	ax,dx
		sub	ax,si
loc_290:
		jmp	short loc_292
loc_291:
		mov	ax,[bp+0Ch]
loc_292:
		pop	di
		pop	si
		mov	sp,bp
		pop	bp
		retf
sub_52		endp


;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_53		proc	near
		push	bp
		mov	bp,sp
		mov	bx,[bp+6]
		shl	bx,1
		test	word ptr ds:[296h][bx],1
		jz	loc_293
		mov	ax,5
		push	ax
		jmp	short loc_295
loc_293:
		push	ds
		mov	ah,40h			; '@'
		mov	bx,[bp+6]
		mov	cx,[bp+0Ch]
		lds	dx,dword ptr [bp+8]
		int	21h
		pop	ds
		jc	loc_294
		push	ax
		mov	bx,[bp+6]
		shl	bx,1
		or	word ptr ds:[296h][bx],1000h
		pop	ax
		jmp	short loc_296
loc_294:
		push	ax
loc_295:
		call	sub_13
loc_296:
		pop	bp
		retf
sub_53		endp

			                        ;* No entry point to code
		push	bp
		mov	bp,sp
;*		sub	sp,4
		db	 83h,0ECh, 04h
		push	si
		mov	si,4
		mov	[bp-2],ds
		mov	word ptr [bp-4],104h
		jmp	short loc_299
loc_297:
		les	bx,dword ptr [bp-4]
		test	word ptr es:[bx+2],3
		jz	loc_298
		push	word ptr [bp-2]
		push	bx
		nop
		callf	sub_44
		pop	cx
		pop	cx
loc_298:
		dec	si
		add	word ptr [bp-4],14h
loc_299:
		or	si,si
		jnz	loc_297
		pop	si
		mov	sp,bp
		pop	bp
		retf

seg_a		ends



;------------------------------------------------------------  seg_b   ----

seg_b		segment	byte public
		assume cs:seg_b  , ds:seg_b , ss:stack_seg_e


		org	7

		db	0C8h, 18h, 00h, 00h,0C7h, 46h
		db	0E8h, 08h, 15h, 8Bh, 46h, 08h
		db	 89h, 46h,0F0h, 8Bh, 46h, 06h
		db	 89h, 46h,0F2h, 8Bh, 46h, 0Ch
		db	 89h, 46h,0F8h, 8Bh, 46h, 0Ah
		db	 89h, 46h,0EAh,0C7h, 46h,0ECh
		db	 04h, 00h,0C7h, 46h,0EEh, 01h
		db	 00h, 16h, 8Dh, 46h,0F8h, 50h
		db	 16h, 8Dh, 46h,0E8h, 50h, 16h
		db	 8Dh, 46h,0E8h, 50h, 6Ah, 2Fh
		db	 9Ah, 76h, 10h
		dw	seg_a
		db	 83h,0C4h, 0Eh, 83h, 7Eh,0F4h
		db	 00h, 74h, 2Eh, 8Bh, 46h,0E8h
		db	 3Dh, 0Fh, 00h, 74h, 07h, 3Dh
		db	 15h, 00h, 74h, 08h,0EBh, 0Ch
		db	 1Eh, 68h, 94h, 00h,0EBh, 0Ah
		db	 1Eh, 68h,0A4h, 00h,0EBh, 04h
		db	 1Eh, 68h,0B6h, 00h, 9Ah,0BCh
		db	 13h
		dw	seg_a
		db	 83h,0C4h, 04h, 8Bh, 46h,0E8h
loc_300:
		jmp	short $+14h
		db	0EBh, 0Ch, 1Eh, 68h,0C6h, 00h
		db	 9Ah,0BCh, 13h
		dw	seg_a
		db	 83h,0C4h, 04h, 33h,0C0h,0EBh
		db	0ECh,0C9h,0CBh,0C8h, 18h, 00h
		db	 00h,0C7h, 46h,0E8h, 0Fh, 15h
		db	0C6h, 46h,0ECh, 04h, 83h, 7Eh
		db	 0Eh, 00h, 74h, 04h,0B0h, 01h
		db	0EBh, 02h,0B0h, 00h, 88h, 46h
		db	0EDh, 8Bh, 46h, 08h, 89h, 46h
		db	0F8h, 8Bh, 46h, 06h, 89h, 46h
		db	0EAh, 8Bh, 46h, 0Ch, 89h, 46h
		db	0F0h, 8Bh, 46h, 0Ah, 89h, 46h
		db	0F2h, 16h, 8Dh, 46h,0F8h, 50h
		db	 16h, 8Dh, 46h,0E8h, 50h, 16h
		db	 8Dh, 46h,0E8h, 50h, 6Ah, 2Fh
		db	 9Ah, 76h, 10h
		dw	seg_a
		db	 83h,0C4h, 0Eh, 83h, 7Eh,0F4h
		db	 00h, 74h, 05h, 8Bh, 46h,0E8h
		db	0EBh, 05h, 8Bh, 46h,0E8h,0F7h
		db	0D8h,0EBh, 00h,0C9h,0CBh

;ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
;                              SUBROUTINE
;‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹

sub_54		proc	near
		db	0C8h, 18h, 00h, 00h,0C7h, 46h
		db	0E8h, 02h, 08h, 8Bh, 46h, 08h
		db	 89h, 46h,0F8h, 8Bh, 46h, 06h
		db	 89h, 46h,0EAh, 16h, 8Dh, 46h
		db	0F8h, 50h, 16h, 8Dh, 46h,0E8h
		db	 50h, 16h, 8Dh, 46h,0E8h, 50h
		db	 6Ah, 2Fh, 9Ah, 76h, 10h
		dw	seg_a
		db	 83h,0C4h, 0Eh,0C9h,0CBh

;ﬂﬂﬂﬂ External Entry into Subroutine ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ

sub_55:
		db	0C8h, 1Eh, 00h, 00h, 50h,0B8h
		db	 00h, 11h, 68h,0DAh,0DAh,0CDh
		db	 2Fh, 88h, 46h,0FFh, 58h, 58h
		db	 80h, 7Eh,0FFh,0FFh, 74h, 0Eh
		db	 1Eh, 68h,0D5h, 00h, 9Ah,0BCh
		db	 13h
		dw	seg_a
loc_301:
;*		add	sp,4
		db	 83h,0C4h, 04h
		jmp	short $+56h
sub_54		endp

		db	0C6h, 46h,0E2h, 1Bh,0C6h, 46h
		db	0E3h, 00h,0C6h, 46h,0E4h, 80h
		db	0C7h, 46h,0E9h, 00h, 00h,0C7h
		db	 46h,0E7h, 00h, 00h,0C7h, 46h
		db	0EDh, 00h, 00h,0C7h, 46h,0EBh
		db	 00h, 00h,0C6h, 46h,0EFh, 00h
		db	0C7h, 46h,0F2h
		dw	seg_c
		db	0C7h, 46h,0F0h, 00h, 00h,0C7h
		db	 46h,0F4h, 01h, 00h,0C7h, 46h
		db	0F8h, 00h, 00h,0C7h, 46h,0F6h
		db	 48h, 00h,0C6h, 46h,0FAh, 00h
		db	0C6h, 46h,0FBh, 00h,0C6h, 46h
		db	0FCh, 00h, 16h, 8Dh, 46h,0E2h
		db	 50h, 0Eh,0E8h, 58h,0FFh,0EBh
		db	0A7h,0C9h,0CBh, 00h, 00h

seg_b		ends



;------------------------------------------------------------  seg_c   ----

seg_c		segment	para public
		assume cs:seg_c  , ds:seg_c , ss:stack_seg_e

		db	16384 dup (0)

seg_c		ends



;------------------------------------------------------------  seg_d   ----

seg_d		segment	para public
		assume cs:seg_d  , ds:seg_d , ss:stack_seg_e

		db	 00h, 00h, 00h, 00h, 42h, 6Fh
		db	'rland C++ - '
copyright	db	'Copyright 1991 Borland Intl.'
		db	0
		db	'Divide error', 0Dh, 0Ah, 'Abnorm'
		db	'al program termination', 0Dh, 0Ah
data_88		dw	0
data_89		dw	0			; segment storage
data_90		dw	0
data_91		dw	0			; segment storage
data_92		dw	0
data_93		dw	0			; segment storage
data_94		dw	0
data_95		dw	0			; segment storage
data_96		dw	0
data_97		dw	0
data_98		dw	0
data_99		dw	0
data_100	dw	0
data_101	dd	00000h
data_103	dw	0
data_104	dw	0			; segment storage
data_105	dw	0
		db	0, 0
data_107	dw	0
data_108	dw	0
		db	 4Eh, 04h, 00h
		db	0
data_110	dw	0
		db	0, 0
data_111	dw	0
		db	0, 0
data_112	dw	0
		db	0
		db	'Invalid drive!', 0Ah, 0
		db	'Drive not ready!', 0Ah, 0
		db	'Unknown error!', 0Ah, 0
		db	'Success Read!', 0Ah, 0
		db	'CD-ROM Driver hasn', 27h, 't ins'
		db	'talled!', 0Ah
		db	0
data_114	dw	0
data_115	dw	291h, seg_a
data_116	dw	291h, seg_a
data_117	dw	291h, seg_a
		db	0, 0, 9, 2
		db	14 dup (0)
		db	 04h, 01h, 00h, 00h, 0Ah, 02h
		db	 01h, 00h
		db	12 dup (0)
		db	 18h, 01h, 00h, 00h, 02h, 02h
		db	 02h, 00h
		db	12 dup (0)
		db	 2Ch, 01h, 00h, 00h, 43h, 02h
		db	 03h
		db	13 dup (0)
		db	 40h, 01h, 00h, 00h, 42h, 02h
		db	 04h, 00h
		db	12 dup (0)
		db	 54h, 01h, 00h
		db	299 dup (0)
data_124	dw	14h
		db	 01h, 60h, 02h, 60h, 02h, 60h
		db	 04h,0A0h, 02h,0A0h
		db	33 dup (0)
		db	 13h, 02h, 02h, 04h, 05h, 06h
		db	 08h, 08h, 08h, 14h, 15h, 05h
		db	 13h,0FFh, 16h, 05h, 11h, 02h
		db	13 dup (0FFh)
		db	 05h, 05h,0FFh
		db	15 dup (0FFh)
		db	 0Fh,0FFh, 23h, 02h,0FFh, 0Fh
		db	0FFh,0FFh,0FFh,0FFh, 13h,0FFh
		db	0FFh, 02h, 02h, 05h, 0Fh, 02h
		db	0FFh,0FFh,0FFh, 13h
		db	8 dup (0FFh)
		db	 23h,0FFh,0FFh,0FFh,0FFh, 23h
		db	0FFh, 13h,0FFh, 00h
data_129	dw	1000h
		db	 28h, 6Eh, 75h, 6Ch, 6Ch, 29h
		db	 00h, 00h, 14h, 14h, 01h, 14h
		db	 15h, 14h, 14h, 14h, 14h, 02h
		db	 00h, 14h, 03h, 04h, 14h, 09h
		db	 05h
		db	8 dup (5)
		db	11 dup (14h)
		db	 0Fh, 17h, 0Fh, 08h, 14h, 14h
		db	 14h, 07h, 14h, 16h
		db	9 dup (14h)
		db	 0Dh, 14h, 14h
		db	8 dup (14h)
		db	 10h, 0Ah, 0Fh, 0Fh, 0Fh, 08h
		db	 0Ah, 14h, 14h, 06h, 14h, 12h
		db	 0Bh, 0Eh, 14h, 14h, 11h, 14h
		db	 0Ch, 14h, 14h
		db	0Dh
		db	7 dup (14h)
		db	 00h, 70h, 72h
		db	'int scanf : floating point forma'
		db	'ts not linked', 0Dh, 0Ah
		db	 00h, 00h, 00h, 0Dh, 00h, 00h
		db	 00h, 00h, 00h,0B1h, 0Ah,0B6h
		db	 0Ah,0B6h, 0Ah,0B6h, 0Ah, 00h
		db	 02h, 0Dh, 05h, 00h, 00h
data_136	db	132 dup (0)		; Data table (indexed access)

seg_d		ends



;------------------------------------------------------  stack_seg_e   ----

stack_seg_e	segment	word stack 'STACK'

		db	128 dup (0)

stack_seg_e	ends



		end	start
