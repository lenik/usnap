
#include <stdio.h>
#include <GWin.h>

#include "..\MouseHook\MouseHook.h"

LRESULT CALLBACK MyMouseHook(int &code, WPARAM &wParam, LPARAM &lParam);

HWND hWnd;
long count = 0;
long msgcount = 0;

HINSTANCE	ghInstance;
LPSTR		glpCmdLine;
int			gnCmdShow;
HANDLE		gmonThread;

DWORD monMain(LPVOID);


LRESULT CALLBACK mainproc(
						  HWND hWnd,
						  UINT Msg,
						  WPARAM wParam,
						  LPARAM lParam) {
	switch (Msg) {
	case WM_CREATE:
		break;
	case WM_CLOSE:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 1;
	default:
		return DefWindowProc(hWnd, Msg, wParam, lParam);
	}
	return DefWindowProc(hWnd, Msg, wParam, lParam);
}

int WINAPI WinMain(
				   HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
				   LPSTR lpCmdLine,
				   int nCmdShow) {
	DWORD Id;
	ghInstance = hInstance;
	glpCmdLine = lpCmdLine;
	gnCmdShow = nCmdShow;

	gmonThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)monMain, 0L,
							  STANDARD_RIGHTS_REQUIRED, &Id);
	if (!gmonThread) {
		MessageBox(NULL, "Couldn't create monitor thread. ", NULL, MB_OK);
		return 0;
	}
	WaitForSingleObject(gmonThread, INFINITE);
	return 0;
}

DWORD monMain(LPVOID lpv) {
	UNREFERENCED_PARAMETER(lpv);
	GWin w(ghInstance, gnCmdShow);
	HHOOK hhk;
	MSG msg;

	if ((hhk = InstallMouseHook(MyMouseHook)) == NULL) {
		PrintError(GetLastError());
		return 0;
	}
	EnableMouseHook();

	w.param.lpszClassName = "EDIT";
	w.param.dwStyle |= WS_HSCROLL | WS_VSCROLL;
	w.param.dwStyle |= ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL;
	w.wc.lpfnWndProc = (WNDPROC)mainproc;

	w.Create();
	hWnd = w.hWnd;

	w.hWnd = NULL;
	while (GetMessage(&msg, w.hWnd, 0, 0)) {
		msgcount++;
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	DisableMouseHook();
	UninstallMouseHook(hhk);

	MessageBox(NULL, "OK!", "OKey", MB_OK);
	ExitThread(0);
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