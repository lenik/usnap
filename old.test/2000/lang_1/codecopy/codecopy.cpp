// codecopy.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include <stdio.h>

int gf() {
	char *s = "Hello, world!";
	void *pMsgBox = &MessageBox;

	_asm {
		push 0;
		push 0;
		push s;
		push 0;
		call pMsgBox;
		//call        dword ptr [__imp__MessageBoxA@16 (00425294)]
	}
	_asm {
		pop edi;
		pop esi;
		pop ebx;
		mov esp, ebp;
		pop ebp;
		ret;
	}


	return MessageBox(NULL, s, NULL, 0);
}

void copyproc_x86_vc6(void *destmem, void *proc, size_t size) {
	DWORD P_JMP = (DWORD)proc;
	// 开始位置 = P_JMP + 5/*[JMP]*/ + dw ptr[P_JMP + 1]/*relative jmp*/
	DWORD P_PROC = P_JMP + 5 + *(DWORD *)(P_JMP + 1);

	memcpy(destmem, (void *)P_PROC, size);
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.
	BYTE codes[10000];

#ifndef _DEBUG
	_asm int 3
#endif

	copyproc_x86_vc6(codes, &gf, 200);
	DWORD calladdr = (DWORD)codes;

	// 可以将数据区的数据作为代码使用，但由于代码中使用了相对定位，
	// 并且有些子程序和变量是相对于源代码段定位，
	// 因此无法正确执行。
	// 只有调用子程序不含有函数调用（但可以通过手工计算绝对地址来调用）、
	// 还是可以调用的。
	// 主要是 CRT 以及静态连接的库不能调用，API基本上没问题。
	// 函数返回时因为要检测堆栈调用了_chkesp，这个调用使用相对地址，会造成错误。
	// 程序可以在返回时手工弹出栈内容再ret。(参考gf)

	_asm call calladdr;
	return 0;
}
