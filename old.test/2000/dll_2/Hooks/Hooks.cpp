// Hooks.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"


#pragma data_seg("GlobalData")

	HOOKMODULE g_HookModule;
	HOOKINFO g_Infos[16];
#pragma data_seg()


BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	return TRUE;
}



LRESULT _stdcall _HookProc(int nCode, WPARAM wParam, LPARAM lParam) {

	nCallbackCount++;
	if ((nCode >= 0) && Enable) {
		if (IMouseProc != NULL) {
			(*IMouseProc)(nCode, wParam, lParam);
		}
	}
	// ͻ�Ƶ�1. ��ȡNextHook��ڵ�, ����NextHook�ĵ��ô���
	return CallNextHookEx(hhk, nCode, wParam, lParam);
}