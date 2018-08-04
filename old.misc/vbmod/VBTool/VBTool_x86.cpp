// VBTool.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "VBTool.h"

void __declspec(naked) _x86_returnValue() {
	__asm {
		mov eax, [esp + 8]	// DWORD v
		ret 4
	}
}
