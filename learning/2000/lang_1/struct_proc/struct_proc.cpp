// struct_proc.cpp : Defines the entry point for the application.
//

#include "stdafx.h"


void __declspec(naked) copyStruct(void *_pRet, size_t ssize) {
	//
	// naked:
	//	naked F(int P0, int P1, ..., int Pn) {
	//		auto int v0, v1, ...
	//		auto int v...
	//		auto int vn;
	//
	//	编译器会将 形参P(i) 的地址解释成 EBP + 8 + i*4，
	//		将 栈变量 v(i) 的地址解释成 EBP - 4 - i*4
	//		这是常规的做法。不过这里 EBP --> [旧ESP]，在不使用EBP框架时，形参开始于EBP+4
	//
	//	因此不要在 naked 中书写自动变量。即使放在 { } 中。

	//memcpy(_pRet, ((int *)&ssize) + 1, ssize);
	__asm {
		mov eax, [esp+8]
		push eax
		lea eax, [esp+16]
		push eax
		mov eax, [esp+12]
		push eax
		call memcpy
		add esp, 12
	}

	__asm {
		mov eax, [esp+4]
		mov ecx, [esp+8]
		pop edx		; ret address
		add esp, ecx
		push edx
		// sizeof(_pRet) + sizeof(size)
		ret 8
	}
}


double _stdcall f1() {
	return exp(3.3 / 2.4);
}


typedef long PROCA;

PROCA internal_f1;
PROCA internal_f2;
void f1_frame();
void _stdcall Proc_stdcall(PROCA *p);
void _stdcall Call_stdcall(PROCA p);
void _stdcall Ret_stdcall(PROCA reserved = 0);

bool _declspec(naked) Frame_start(long *p) {
	__asm {
		xor eax, eax
		setnc al	; eax = CF
		mov ebx, [esp + 4]
		pop ecx
		sub ecx, 5
		mov [ebx], ecx
		ret
	}
}

void MAIN() {
	f1_frame();
	Call_stdcall(internal_f1);
	((void (_stdcall *)())internal_f1)();
}

void f1_frame() {
	long Pstart;
	if (Frame_start(&Pstart)) {
		Proc_stdcall(&internal_f1);
		MessageBox(NULL, "Hello", NULL, 0);
		Ret_stdcall();

		Proc_stdcall(&internal_f2);
		MessageBox(NULL, "How do u do?", NULL, 0);
		Ret_stdcall();
	}
}

void __declspec(naked) __stdcall Proc_stdcall(PROCA *p) {
	__asm {
		mov ebx, [esp + 4]	; p
		pop eax			; eax = caller's next statement
		mov [ebx], eax		; [p]
		add esp, 4		; release (p) stack
		ret			; jump to main's next
	}
}

void __declspec(naked) __stdcall Call_stdcall(PROCA p) {
	__asm {
		mov eax, [esp + 4]	; p
		call eax
	}
}

void __declspec(naked) __stdcall Ret_stdcall(PROCA reserved) {
	__asm {
		add esp, 4		; eax = caller's next statement
		ret			; jump to main's next
	}
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	MAIN();

	double l = f1();

	struct S {
		int a;
		int b;
		int c;
		int d;
	};

	S x;
	x.a = 100;
	x.b = 101;
	S y;

	typedef S (_stdcall *RETURN_S)(size_t size, S in_s);
	RETURN_S procS1;
	procS1 = (RETURN_S)&copyStruct;
	y = procS1(sizeof(S), x);

	bool succeed = x.a == y.a && x.b == y.b;

	return 0;
}
