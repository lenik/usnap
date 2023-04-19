// VBTool.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "VBTool.h"

static HMODULE g_hModule			= NULL; 

LONG IDFunc() { return 0xAAAAAAAA; }
LONG _stdcall returnIDFunc() { return (LONG)IDFunc; }
LONG _stdcall returnHandle() { return (LONG)g_hModule; }

LONG _stdcall returnValue(LONG parameter) { return parameter; }

BYTE _stdcall returnByte(LONG base, LONG offset) { return ((LPBYTE)(base + offset))[0]; }
WORD _stdcall returnWord(LONG base, LONG offset) { return ((LPWORD)(base + offset))[0]; }
LONG _stdcall returnLong(LONG base, LONG offset) { return ((LPDWORD)(base + offset))[0]; }

BYTE _stdcall returnNByte(LONG base, LONG offset) { return ((LPBYTE)base)[offset]; }
WORD _stdcall returnNWord(LONG base, LONG offset) { return ((LPWORD)base)[offset]; }
LONG _stdcall returnNLong(LONG base, LONG offset) { return ((LPDWORD)base)[offset]; }

BYTE _stdcall forceByte(LONG base, LONG offforce, BYTE vByte) { return ((LPBYTE)(base + offforce))[0] = vByte; }
WORD _stdcall forceWord(LONG base, LONG offforce, WORD vWord) { return ((LPWORD)(base + offforce))[0] = vWord; }
LONG _stdcall forceLong(LONG base, LONG offforce, LONG vLong) { return ((LPDWORD)(base + offforce))[0] = vLong; }

BYTE _stdcall forceNByte(LONG base, LONG offforce, BYTE vByte) { return ((LPBYTE)base)[offforce] = vByte; }
WORD _stdcall forceNWord(LONG base, LONG offforce, WORD vWord) { return ((LPWORD)base)[offforce] = vWord; }
LONG _stdcall forceNLong(LONG base, LONG offforce, LONG vLong) { return ((LPDWORD)base)[offforce] = vLong; }

LONG _stdcall getStringLengthA(const char *parameter) { return lstrlenA(parameter); }
LONG _stdcall getStringLengthW(const wchar_t *parameter) { return lstrlenW(parameter); }
LONG _stdcall getStringLengthM(const unsigned char *parameter) { return _mbslen(parameter); }

LONG _stdcall copyBytes(LPBYTE pbDest, LPBYTE pbSrc, LONG cBytes) {
	LONG i = 0; 
	try {
		for (i = 0; i < cBytes; i++) {
			pbDest[i] = pbSrc[i]; 
		}
	} catch (int) {
	}
	return i; 
}


LONG _stdcall callFunction0(LONG parameter) {
	_stdcallback0 callbackSpecified = (_stdcallback0)parameter; 
	return (*callbackSpecified)(); 
}
LONG _stdcall callFunction1(LONG parameter, LONG parameter1) {
	_stdcallback1 callbackSpecified = (_stdcallback1)parameter; 
	return (*callbackSpecified)(parameter1); 
}
LONG _stdcall callFunction2(LONG parameter, LONG parameter1, LONG parameter2) {
	_stdcallback2 callbackSpecified = (_stdcallback2)parameter; 
	return (*callbackSpecified)(parameter1, parameter2); 
}
LONG _stdcall callFunction3(LONG parameter, LONG parameter1, LONG parameter2, LONG parameter3) {
	_stdcallback3 callbackSpecified = (_stdcallback3)parameter; 
	return (*callbackSpecified)(parameter1, parameter2, parameter3); 
}
LONG _stdcall callFunction4(LONG parameter, LONG parameter1, LONG parameter2, LONG parameter3, LONG parameter4) {
	_stdcallback4 callbackSpecified = (_stdcallback4)parameter; 
	return (*callbackSpecified)(parameter1, parameter2, parameter3, parameter4); 
}

void _stdcall callProcedure0(LONG parameter) {
	_stdvoidcallback0 callbackSpecified = (_stdvoidcallback0)parameter; 
	(*callbackSpecified)(); 
}
void _stdcall callProcedure1(LONG parameter, LONG parameter1) {
	_stdvoidcallback1 callbackSpecified = (_stdvoidcallback1)parameter; 
	(*callbackSpecified)(parameter1); 
}
void _stdcall callProcedure2(LONG parameter, LONG parameter1, LONG parameter2) {
	_stdvoidcallback2 callbackSpecified = (_stdvoidcallback2)parameter; 
	(*callbackSpecified)(parameter1, parameter2); 
}
void _stdcall callProcedure3(LONG parameter, LONG parameter1, LONG parameter2, LONG parameter3) {
	_stdvoidcallback3 callbackSpecified = (_stdvoidcallback3)parameter; 
	(*callbackSpecified)(parameter1, parameter2, parameter3); 
}
void _stdcall callProcedure4(LONG parameter, LONG parameter1, LONG parameter2, LONG parameter3, LONG parameter4) {
	_stdvoidcallback4 callbackSpecified = (_stdvoidcallback4)parameter; 
	(*callbackSpecified)(parameter1, parameter2, parameter3, parameter4); 
}

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

DWORD _stdcall dword_add(DWORD a, DWORD b) { return a + b; }
DWORD _stdcall dword_sub(DWORD a, DWORD b) { return a - b; }
DWORD _stdcall dword_mul(DWORD a, DWORD b) { return a * b; }
DWORD _stdcall dword_div(DWORD a, DWORD b) { return a / b; }

DWORD _stdcall dword_shift_left(DWORD d, DWORD n) { return d << n; }
DWORD _stdcall dword_shift_right(DWORD d, DWORD n) { return d >> n; }

void _stdcall debugBreak() {
	_asm int 3;
}

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
		g_hModule = (HMODULE)hModule; 
	}
    return TRUE;
}


// For Test
/*
// 对VB自动化字串无效, 也就是说VB传给API的是字串的副本
// 不过对在VB中明确声明过的字串变量却有效 (且必须声明为as string, 不可as any
// 这说明若在VB中明确声明某变量后, 该变量就不再是自动化变量, 而是固定结构的
// 普通内存变量了. (字串对于VB来说是BSTR, 但已经不是自动化中的属于部分的BSTR了)
VOID _stdcall lowerString(char *p) {
	LONG len = getStringLengthA(p); 
	LONG i; 
	for (i = 0; i < len; i++) {
		p[i] |= 0x20; 
	}
}
// VB返回自定义类型时，不时返回这种类型变量的地址，而是整个类型变量的值
// 也就是说，返回的数据一般不止字长（32位）
struct S {
	short	i; 
	long	l1, l2; 
}; 
S	_stdcall vbtType() {
	S	rs; 
	rs.i = 0x1234; 
	rs.l1 = 0x11223344; 
	rs.l2 = 0x55667788; 
	return rs; 
}
*/

DWORD _stdcall catchMessage(HWND hWnd, _stdcallback1 switchprocProc) {
	LONG	oldproc, newproc; 
	oldproc	= GetWindowLong(hWnd, GWL_WNDPROC); 
	newproc	= switchprocProc(oldproc); 
	return SetWindowLong(hWnd, GWL_WNDPROC, newproc); 
}

DWORD _stdcall chainMessage(WNDPROC wndproc, HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	return CallWindowProc(wndproc, hWnd, message, wParam, lParam); 
}
