// Mine4Patch.cpp : Defines the entry point for the application.
//

#include "stdafx.h"


// 程序段1：改为 4 个方向计数 （原为 8 个方向）

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

		add ebx, edx		// edx=X(1为底), X(0为底+1)
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
