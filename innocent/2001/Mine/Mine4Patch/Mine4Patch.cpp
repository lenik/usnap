// Mine4Patch.cpp : Defines the entry point for the application.
//

#include "stdafx.h"


// �����1����Ϊ 4 ��������� ��ԭΪ 8 ������

void __declspec(naked) Seg1_4Count(int, int) {
	__asm {
		push ebx

		mov ebx,dword ptr [esp+12]
		mov edx,dword ptr [esp+8]

		xor eax, eax
		xor ecx, ecx

		dec ebx
		shl ebx, 5
		add ebx, 1005700h

		add ebx, edx		// edx=X(1Ϊ��), X(0Ϊ��+1)
		mov al, [ebx]
		shr al, 7
		add ecx, eax

		add ebx, 1Fh
		mov al, [ebx]
		shr al, 7
		add ecx, eax

		inc ebx
		inc ebx
		mov al, [ebx]
		shr al, 7
		add ecx, eax

		add ebx, 1Fh
		mov al, [ebx]
		shr al, 7
		add ecx, eax

		pop ebx

		mov eax, ecx

		ret //8	// C2 08 00
	}
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.
	Seg1_4Count(0, 0);

	return 0;
}
