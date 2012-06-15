
#define __MOUSEHOOK_CPP

#include <windows.h>
#include "MouseHook.h"

	#pragma data_seg("GlobalData")

	HMODULE hMouseHookModule = NULL;

	HHOOK hhk = NULL;
	BOOL Enable = TRUE;
	IHOOKPROC IMouseProc = NULL;

	// 记录在DLL中MouseHook的调用次数
	int nCallbackCount = 0;

	#pragma data_seg()


BOOL APIENTRY DllMain(
					  HMODULE hModule,
					  DWORD ul_reason_for_call,
					  LPVOID lpReserved) {
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		hMouseHookModule = hModule;
		break;
	case DLL_PROCESS_DETACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}

HHOOK MOUSEHOOKAPI InstallMouseHook(IHOOKPROC UserMouseProc) {
	IMouseProc = UserMouseProc;
	hhk = SetWindowsHookEx(
		WH_MOUSE,			// int idHook
		(HOOKPROC)GetProcAddress(hMouseHookModule, "MouseProc"),
							// HOOKPROC lpfn
		hMouseHookModule,	// hmod
		0					// dwThreadId
		);
	return hhk;
}

BOOL MOUSEHOOKAPI UninstallMouseHook(HHOOK hhk) {
	DisableMouseHook();
	return UnhookWindowsHookEx(hhk);
}

void MOUSEHOOKAPI EnableMouseHook() { Enable = TRUE; }
void MOUSEHOOKAPI DisableMouseHook() { Enable = FALSE; }

void MOUSEHOOKAPI SetIMouseProc(IHOOKPROC ihp) {
	DisableMouseHook();
	IMouseProc = ihp;
	EnableMouseHook();
}

LRESULT MOUSEHOOKAPI CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
	nCallbackCount++;
	if ((nCode >= 0) && Enable) {
		if (IMouseProc != NULL) {
			(*IMouseProc)(nCode, wParam, lParam);
		}
	}
	// 突破点1. 截取NextHook入口点, 计算NextHook的调用次数
	return CallNextHookEx(hhk, nCode, wParam, lParam);
}

int MOUSEHOOKAPI GetCallbackCount() { return nCallbackCount; }
