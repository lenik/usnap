// WordAssistant.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#include "GWin.h"

#include "WordAssistant.h"
#include "MultifunxTextFrame.h"

#define WADEBUG

LRESULT CALLBACK waWinProc(
						  HWND hWnd,
						  UINT Msg,
						  WPARAM wParam,
						  LPARAM lParam) {
	switch (Msg) {
	case WM_CREATE:
		break;
//	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, Msg, wParam, lParam);
	}
	return DefWindowProc(hWnd, Msg, wParam, lParam);
}

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		hDllModule = hModule;
		break;
	case DLL_PROCESS_DETACH:
		waUninitialize();
		break;
	}

    return TRUE;
}

long _stdcall setld(int index, long val) {
	if (index < 0 || index >= ARRAY_NUM) return DATA_NONEXIST;
	return laDatas[index] = val;
}
long _stdcall getld(int index) {
	if (index < 0 || index >= ARRAY_NUM) return DATA_NONEXIST;
	return laDatas[index];
}
int _stdcall getarraynum() {
	return ARRAY_NUM;
}

void _stdcall waInitialize() {
#ifdef WADEBUG
	MessageBox(NULL, "welcome", NULL, MB_OK);
#endif
	winMain = new GWin(NULL, SW_NORMAL);
	winMain->wc.lpfnWndProc = (WNDPROC)waWinProc;
}

void _stdcall waUninitialize() {
#ifdef WADEBUG
	MessageBox(NULL, "uninitializing...", NULL, MB_OK);
#endif
}

ATOM _stdcall waRegister() {
	return winMain->Register();
}

HWND _stdcall waCreate() {
	return winMain->Create();
}
