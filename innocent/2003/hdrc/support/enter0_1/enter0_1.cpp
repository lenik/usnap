//

#include "stdafx.h"


BYTE _gdtr[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
BYTE _callptr[] = { 0, 0, 0, 0, 0x0F, 0 };
WORD _ourgate[] = { 0, 0x28, 0xec00, 0 };

BYTE param[] = {
	0, 1, 0, 0, 0,
	0xe0,
	0xc4,
};

char *_ascii = "0123456789ABCDEF";
char *_caption = "enter the ring 0 level";
DWORD _byte = 0x200;
BYTE _buffer[512];
BYTE _show_text[2000];	// 512*3

void __declspec(naked) ring0_proc() {
	__asm {
		pushad
		mov al, [param + 5]	; 0xe0
		mov dx, 0x1f6
		out dx, al		; e0 -> 1f6, enable LBA mode.
		call delay
		mov ecx, 6
		lea esi, param
		mov dx, 1f1h
outp:
		lodsb
		out dx, al		; 1f1->1f6: 0 1 0 0 0 E0  ==> "cylinder pre =0, blocks = 1, LBA address=0, LBA enabled."
		inc dx
		loop outp
		nop
		call delay
		lodsb
		out dx, al		; c4->1f7: command: "read multiple"
test_:
		in al, dx		; 1f7 == 58h " drive ready, seek complete, sector buffer waiting"
		cmp al, 58h
		jnz test_
		xor eax, eax
		mov ecx, 80h		; 512(sector size) / sizeof(dword) = 80h
		mov al, [param + 1]	; 1 = blocks
		mul cx			; cx = 1*80h, == 80h
		mov ecx, eax
		lea edi, _buffer
		mov dx, 1f0h
		rep insd		; read data (sector contents)
		nop
		popad
		xor eax, eax
		retf
delay:
		mov ecx, 1000h
		mov dx, 1f7h
n1:
		in al, dx
		cmp al, 50h		; "drive ready, seek complete"
		jz n2
		loop n1
		mov eax, 1
n2:
		ret
	} // __asm
}

void _declspec(naked) _show_buffer() {
	__asm {
		cld
		lea esi, _buffer
		lea edi, _show_text
		mov ebx, offset _ascii
		xor edx, edx
		xor ecx, ecx
compute:
		xor eax, eax
		cmp edx, _byte
		jnc end_
		lodsb
		push eax
		shr eax, 4
		mov al, [ebx + eax]
		stosb
		pop eax
		and eax, 0fh
		mov al, [ebx + eax]
		mov ah, ' '
		stosw
		inc ecx
		cmp ecx, 16
		jnz compute
		add edx, ecx
		xor ecx, ecx
		mov byte ptr [edi - 1], 0dh
		jmp compute
end_:
		ret
	} // _asm
}

void main(int argc, char* argv[])
{

	__asm {
		mov eax, offset ring0_proc
		mov [_ourgate], ax
		shr eax, 16
		mov [_ourgate + 6], ax

		xor eax, eax
		sgdt fword ptr _gdtr
		mov ebx, dword ptr [_gdtr + 2]
		sldt ax
		add ebx, eax
		mov al, [ebx + 4]
		mov ah, [ebx + 7]
		shl eax, 16
		mov ax, [ebx + 2]
		add eax, 8
		mov edi, eax
		mov esi, offset _ourgate
		movsd
		movsd
		call fword ptr [_callptr]
		xor eax, eax
		sub edi, 8
		stosd
		stosd

		nop
		call _show_buffer

		push MB_OK
		push offset _caption
		push offset _show_text
		push 0
		call MessageBoxA

		push 0
		call ExitProcess

		mov eax, 0
	} // __asm
}
