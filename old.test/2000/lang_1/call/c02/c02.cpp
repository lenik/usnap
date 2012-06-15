// c02.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdarg.h>
#include <stack>

void _cdecl showargs_cdecl(...) {
	//
	char buf[1000] = { 0, } ;
	int *base;
	_asm mov base, ebp;
	// base指向传递参数(从左至右)
	while (*base) {
		sprintf(buf, "%s%d\n", buf, *base);
		base++;
	}
	MessageBox(NULL, buf, NULL, 0);
}

void _fastcall showargs_fastcall(...) {
	//
	char buf[1000] = { 0, } ;
	int *base;
	_asm mov base, ebp;
	// base指向传递参数(从左至右)
	while (*base) {
		sprintf(buf, "%s%d\n", buf, *base);
		base++;
	}
	MessageBox(NULL, buf, NULL, 0);
}

void _stdcall showargs_stdcall(...) {
	char buf[1000] = { 0, };
	int *base;
	_asm mov base, ebp;
	// base指向传递参数(从右至左)
	while (*base) {
		sprintf(buf, "%s%d\n", buf, *base);
		base++;
	}
	MessageBox(NULL, buf, NULL, 0);
}

typedef LONG (_stdcall *_stdcallback)(...);
typedef LONG (_cdecl *_cdeclcallback)(...);

LONG _stdcall _call_stdcall(_stdcallback proc, int vacount, int extra_release, LPINT pva) {
	LONG retval = -1;
	int i = 0, val;
	extra_release = extra_release * sizeof(int);

	for (i = 0; i < vacount; i++) {
		val = pva[vacount - 1 - i];
		_asm push val;
	}
	_asm call proc;
	//vacount = vacount * 4 - extra_release;
	//_asm add esp, vacount;
	_asm add esp, extra_release;
	_asm mov retval, eax;
	return retval;
}

LONG _stdcall _call_cdecl(_cdeclcallback proc, int vacount, int extra_release, LPINT pva) {
	LONG retval = -1;
	int i = 0, val;
	extra_release = extra_release * sizeof(int);

	for (i = 0; i < vacount; i++) {
		val = pva[vacount - 1 - i];
		_asm push val;
	}
	_asm call proc;
	vacount = vacount * 4 - extra_release;
	_asm add esp, vacount;
	_asm add esp, extra_release;
	_asm mov retval, eax;
	return retval;
}

LONG _stdcall call_stdcall(_stdcallback proc, int vacount, int extra_release, ...) {
	LONG retval = -1;
	int i = 0, val;
	LPINT pva = NULL;

	va_list args;
	va_start(args, extra_release);

	if (vacount < 0) {
		vacount = 0;
		while (val = va_arg(args, int)) vacount++;
		va_end(args);
		va_start(args, extra_release);
	}
	pva = new int[vacount];
	for (i = 0; i < vacount; i++) {
		pva[i] = va_arg(args, int);
	}
	va_end(args);
	retval = _call_stdcall(proc, vacount, extra_release, pva);
	delete[] pva;
	return retval;
}

LONG _stdcall call_cdecl(_cdeclcallback proc, int vacount, int extra_release, ...) {
	LONG retval = -1;
	int i = 0, val;
	LPINT pva = NULL;

	va_list args;
	va_start(args, extra_release);

	if (vacount < 0) {
		vacount = 0;
		while (val = va_arg(args, int)) vacount++;
		va_end(args);
		va_start(args, extra_release);
	}
	pva = new int[vacount];
	for (i = 0; i < vacount; i++) {
		pva[i] = va_arg(args, int);
	}
	va_end(args);
	retval = _call_cdecl(proc, vacount, extra_release, pva);
	delete[] pva;
	return retval;
}

void call_1() {
	MessageBox(NULL, "call_1", NULL, 0);
}

// _cdecl 函数不返回到它的调用者。
// 这是因为 栈变量P位于子函数返回地址 - 8位置
// 通过获取P地址-8地址, 并将它修改成返回地址就可.
// 如果这个函数带有参数, 则函数返回时参数占用栈空间不释放。
void return_into_subroutine() {
	long P;
	P = (long)&P;
	P += 8;
	*(void **)P = call_1;
	return;
}

void pascal pp_std(int, int, int) {
}
void _cdecl pp_cdecl(int, int, int) {
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	pp_std(1,2,3);
	pp_cdecl(1,2,3);

	showargs_cdecl((char)1, (short)2, (long)4, (__int64)8);
	//same as showargs_cdecl
	//showargs_fastcall((char)1, (short)2, (long)4, (__int64)8);
	showargs_stdcall((__int64)0x8888888877777777l, (long)4, (short)2, (char)1, (int)0);

	// call showargs_cdecl((char)1, (short)2, (long)4, (__int64)8) indirectly.
	// call showargs_stdcall((long)4, (short)2, (char)1, (int)0) indirectly
	call_cdecl((_cdeclcallback)&showargs_cdecl, 4, 4, (long)4, (short)2, (char)1, (int)0);
	call_stdcall((_stdcallback)&showargs_stdcall, 4, 4, (long)4, (short)2, (char)1, (int)0);
	return 0;
}
