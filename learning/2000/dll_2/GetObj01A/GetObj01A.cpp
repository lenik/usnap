
#include <stdio.h>
#include <GWin.h>

typedef LRESULT (CALLBACK* IHOOKPROC)(int &code, WPARAM &wParam, LPARAM &lParam);

typedef HHOOK (*INSTALLHOOKPROC)(IHOOKPROC UserProc);
typedef BOOL (*UNINSTALLHOOKPROC)(HHOOK hhk);
typedef void (*SETMOUSEHOOK)();
typedef int (*GETINT)();

INSTALLHOOKPROC InstallMouseHook, SetIMouseProc;
UNINSTALLHOOKPROC UninstallMouseHook;
SETMOUSEHOOK EnableMouseHook, DisableMouseHook;
GETINT GetCallbackCount;
HOOKPROC MouseProc;
LRESULT CALLBACK MyMouseHook(int &code, WPARAM &wParam, LPARAM &lParam);

HWND hWnd;
long count = 0;
long msgcount = 0;

int WINAPI WinMain(
				   HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
				   LPSTR lpCmdLine,
				   int nCmdShow) {
	GWin w(hInstance, nCmdShow), ed(hInstance, SW_SHOWNORMAL);
	HHOOK hhk;
	MSG msg;

	w.Register();
	w.Create();		// Main window

	ed.param.lpszClassName = "EDIT";
	ed.param.dwStyle = WS_CHILD;
	ed.param.dwStyle |= WS_BORDER | WS_SIZEBOX;
	ed.param.dwStyle |= WS_HSCROLL | WS_VSCROLL;
	ed.param.dwStyle |= ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL;
	ed.param.x = ed.param.y = 10;
	ed.param.nWidth = 300; ed.param.nHeight = 250;
	ed.param.hWndParent = w.hWnd;

	ed.Create();

	hWnd = ed.hWnd;

	#ifdef _DEBUG
		HINSTANCE hinstDLL = (HINSTANCE)LoadLibrary("J:\\DLLs\\MouseHook\\Debug\\MouseHook.dll");
	#else
		HINSTANCE hinstDLL = (HINSTANCE)LoadLibrary("J:\\DLLs\\MouseHook\\Release\\MouseHook.dll");
	#endif

	InstallMouseHook = (INSTALLHOOKPROC)GetProcAddress(hinstDLL, "InstallMouseHook");
	UninstallMouseHook = (UNINSTALLHOOKPROC)GetProcAddress(hinstDLL, "UninstallMouseHook");
	EnableMouseHook = (SETMOUSEHOOK)GetProcAddress(hinstDLL, "EnableMouseHook");
	DisableMouseHook = (SETMOUSEHOOK)GetProcAddress(hinstDLL, "DisableMouseHook");
	SetIMouseProc = (INSTALLHOOKPROC)GetProcAddress(hinstDLL, "SetIMouseProc");
	MouseProc = (HOOKPROC)GetProcAddress(hinstDLL, "MouseProc");
	GetCallbackCount = (GETINT)GetProcAddress(hinstDLL, "GetCallbackCount");

	SetIMouseProc(MyMouseHook);
	//hhk = SetWindowsHookEx(WH_MOUSE, MouseProc, hinstDLL, 0);

	if ((hhk = InstallMouseHook(MyMouseHook)) == NULL) {
		PrintError(GetLastError());
		return 0;
	}

	while (GetMessage(&msg, 0, 0, 0)) {
		msgcount++;
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	UninstallMouseHook(hhk);

	FreeLibrary(hinstDLL);

	MessageBox(NULL, "OK!", "OKey", MB_OK);
	return msg.wParam;
}

LRESULT CALLBACK MyMouseHook(int &code, WPARAM &wParam, LPARAM &lParam) {
	char lpBuf[1024];
	int HookType = WH_MOUSE;
	MOUSEHOOKSTRUCT *mhs = (LPMOUSEHOOKSTRUCT)lParam;
	CWPSTRUCT *cs = (LPCWPSTRUCT)lParam;

	switch (HookType) {
	case WH_MOUSE:
		wsprintf(lpBuf, "\
CALLBACK: %d\r\n\
MessageCount = [%d]\r\n\
HookCount = [%d]\r\n\
My hWnd = %x\r\n\
\r\n\
Mouse.hwnd = %x\r\n\
Mouse.X = %d\r\n\
Mouse.Y = %d\r\n\
Mouse.dwExtraInfo = %x\r\n\
Mouse.wHitTestcode = %x",
			GetCallbackCount(),
			msgcount, count++, hWnd,
			//cs->hwnd, cs->message, cs->wParam, cs->lParam, hWnd
			mhs->hwnd, mhs->pt.x, mhs->pt.y, mhs->dwExtraInfo, mhs->wHitTestCode
		);
		break;
	default:
		;
	}

	DisableMouseHook();
	SetWindowText(hWnd, lpBuf);
		//TextOut(GetDC(hWnd), 2, 15, lpBuf, lstrlen(lpBuf));
	EnableMouseHook();
	return 0;
}