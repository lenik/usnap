
        PUBLIC          _hello

_TEXT	SEGMENT
	assume	cs: _TEXT

_hello:
        push ax
        push ds
        push dx
        mov ax, 900h
        push cs
        pop ds
        mov dx, offset hellostring
        int 21h
        pop dx
        pop ds
        pop ax
	ret
        hellostring db 'hello, world!', 13, 10, '$'

_TEXT	ENDS
	END
