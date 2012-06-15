// wmh.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

typedef VOID (CALLBACK *SHOWINGPROC)(LPARAM);

SHOWINGPROC	_spKey = NULL;
SHOWINGPROC	_spMouse = NULL;
SHOWINGPROC	_spGetMsg = NULL;

HANDLE		hModule;

HHOOK		hhkMouseHook;
HHOOK		hhkKeyHook;
HHOOK		hhkGetMsgHook;

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		::hModule	= hModule;

		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
	LPMOUSEHOOKSTRUCT pmhs;
	char buf[100];
	pmhs = (LPMOUSEHOOKSTRUCT)lParam;
	static int counter = 0;
	sprintf(buf, "POS: [%4d] %d, %d", counter++, pmhs->pt.x, pmhs->pt.y);
	if (_spMouse) _spMouse((LPARAM)buf);

	if (nCode == HC_ACTION) {		// 0
		//
	} else if (nCode == HC_NOREMOVE) {	// 3
		// only means message hasn't been removed yet,
		// and caller should also remain the message in queue.
		// don't worried about that.
	} else if (nCode < 0) {			// < 0
	}

	return ::CallNextHookEx(hhkMouseHook, nCode, wParam, lParam);
}

LRESULT CALLBACK KeyProc(int nCode, WPARAM wParam, LPARAM lParam) {
	// wParam: virtualkey code
	// lParam: repeat count

	char buf[100];
	static int counter = 0;
	sprintf(buf, "%4d:%c(%4x),%x", counter++, wParam, wParam, lParam);
	if (_spKey) _spKey((LPARAM)buf);

	return ::CallNextHookEx(hhkKeyHook, nCode, wParam, lParam);
}

LRESULT CALLBACK GetMsgProc(int nCode, WPARAM wParam, LPARAM lParam) {
	char buf[100];
	static int counter = 0;
	sprintf(buf, "GetMsgProc called:%4d", counter++);
	if (_spGetMsg) _spGetMsg((LPARAM)buf);

	return ::CallNextHookEx(hhkGetMsgHook, nCode, wParam, lParam);
}

BOOL CALLBACK SetShowingProc(SHOWINGPROC spKey, SHOWINGPROC spMouse, SHOWINGPROC spGetMsg) {
	_spKey		= spKey;
	_spMouse	= spMouse;
	_spGetMsg	= spGetMsg;

	return TRUE;
}

BOOL CALLBACK Start() {
	hhkMouseHook = ::SetWindowsHookEx(
		WH_MOUSE, MouseProc, (HINSTANCE)hModule, 0);
	hhkKeyHook = ::SetWindowsHookEx(
		WH_KEYBOARD, KeyProc, (HINSTANCE)hModule, 0);
	hhkGetMsgHook = ::SetWindowsHookEx(
		WH_GETMESSAGE, GetMsgProc, (HINSTANCE)hModule, 0);
	return TRUE;
}

BOOL CALLBACK Stop() {
	return UnhookWindowsHookEx(hhkMouseHook) &&
		UnhookWindowsHookEx(hhkKeyHook) &&
		UnhookWindowsHookEx(hhkGetMsgHook);
}

VOID CALLBACK SetH(DWORD h) {
	::hModule = (HANDLE)h;
}
