; OBJASM version 2.0 released on Jan 3, 1991
; (C) Copyright 1988,1989,1990,1991 by Robert F. Day.  All rights reserved

	TITLE	GETPSP
	.386p					; Enable USE32/USE16 usage
	.387					; Enable floating point also
_TEXT	SEGMENT	BYTE PUBLIC USE16 'CODE'
_TEXT	ENDS
_DATA	SEGMENT	WORD PUBLIC USE16 'DATA'
_DATA	ENDS
_BSS	SEGMENT	WORD PUBLIC USE16 'BSS'
_BSS	ENDS
DGROUP	GROUP	_DATA, _BSS


	PUBLIC		_getpsp			; Located at 1:0000h Type = 1

_TEXT	SEGMENT
	assume	cs: _TEXT


_getpsp:
	mov	ah,62h
	int	21h
	mov	ax,bx
	ret

_TEXT	ENDS
	END
