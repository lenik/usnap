// callproto.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <stdio.h>

void s() {
	MessageBeep(0);
}

int _cdecl cf1(int a, int b, int c) {
	int d;
	d = a + b + c;
	return d;
}

int pascal pf1(int a, int b, int c) {
	int d;
	d = a + b + c;
	return d;
}

int _cdecl cf2(int a, ...) {
	return 0;
}

int pascal pf2(int a, ...) {
	return 0;
}

#include <stdarg.h>

int pascal pf3(int count) {
	int sum = 0;
	va_list ap;
	va_start(ap, count);
	for (int i = 0; i < count; i++) {
		sum += va_arg(ap, int);
	}
	va_end(ap);
	return sum;
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	s();

	cf1(1, 2, 3);
	pf1(4, 5, 6);
	cf2(7, 8, 9, 10);
	pf2(11, 12);

	int c;
	_asm {
		push 4
		push 3
		push 2
		push 1
	}
#ifdef DEBUG
	_asm {
		push 4
		call pf3
	}
#else
	pf3(4);
#endif
	_asm {
		mov c, eax
		add esp, 10h
	}
	char ss[100];
	sprintf(ss, "%d", c);
	MessageBox(NULL, ss, ss, 0);

	return 0;
}
	_asm push 4
	_asm push 3
	_asm push 2
	_asm push 1
	int c = pf3(4);
	_asm add esp, 10h
