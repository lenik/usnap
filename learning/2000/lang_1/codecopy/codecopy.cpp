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
	// ��ʼλ�� = P_JMP + 5/*[JMP]*/ + dw ptr[P_JMP + 1]/*relative jmp*/
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

	// ���Խ���������������Ϊ����ʹ�ã������ڴ�����ʹ������Զ�λ��
	// ������Щ�ӳ���ͱ����������Դ����ζ�λ��
	// ����޷���ȷִ�С�
	// ֻ�е����ӳ��򲻺��к������ã�������ͨ���ֹ�������Ե�ַ�����ã���
	// ���ǿ��Ե��õġ�
	// ��Ҫ�� CRT �Լ���̬���ӵĿⲻ�ܵ��ã�API������û���⡣
	// ��������ʱ��ΪҪ����ջ������_chkesp���������ʹ����Ե�ַ������ɴ���
	// ��������ڷ���ʱ�ֹ�����ջ������ret��(�ο�gf)

	_asm call calladdr;
	return 0;
}
