// mltAE.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include "mltAE.h"
#include "resource.h"


AESettings g_Settings;
AEConfig g_Config;


BOOL InitApp();
LRESULT _stdcall MainWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	BOOL b;
	HRESULT hr;
	int i;
	long l;

	__zero(g_Config);
	g_Config.hApp = hInstance;
	b = InitApp();

	if (!b) {
		MessageBox(NULL, _T("Can't initialize application!"), _T("Initializing Error"),
			MB_OK | MB_ICONEXCLAMATION);
		return -1;
	}

	ShowWindow(g_Config.hMainWindow, nCmdShow);
	UpdateWindow(g_Config.hMainWindow);

	MSG msg;
	while (GetMessage(&msg, g_Config.hMainWindow, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}


BOOL InitApp() {
	// loading version information
		HRSRC hSrc;
		DWORD deflang;
		TCHAR name[50];
		void *pv;

		hSrc = FindResource(g_Config.hApp, MAKEINTRESOURCE(VS_VERSION_INFO),
			RT_VERSION);
		if (hSrc == NULL) return FALSE;
		HGLOBAL hmemSrc = LoadResource(g_Config.hApp, hSrc);
		LPVOID pVersion = LockResource(hmemSrc);
		DWORD *pdwTranslations;	// hi-word=wCodePage lo-word=wLanguage
		UINT cb = 0;
		VerQueryValue(pVersion, _T("\\VarFileInfo\\Translation"),
			(void **)&pdwTranslations, &cb);
		int nVerLangs = cb / sizeof(DWORD);
		if (nVerLangs < 1) return FALSE;
		deflang = pdwTranslations[0];
		deflang = (deflang >> 16) | (deflang << 16);

		// app name
			_stprintf(name, _T("\\StringFileInfo\\%08x\\FileDescription"), deflang);
			VerQueryValue(pVersion, name, &pv, &cb);
			g_Config.pAppName = (LPTSTR)pv;
		// version
			_stprintf(name, _T("\\StringFileInfo\\%08x\\FileVersion"), deflang);
			VerQueryValue(pVersion, name, &pv, &cb);
			LPTSTR pspart = (LPTSTR)pv;
			g_Config.major = _tcstol(pspart, &pspart, 0);
			if (pspart != NULL) {
				pspart++;
				g_Config.minor = _tcstol(pspart, &pspart, 0);
			}
	// register wnd class
		WNDCLASS wc;
		wc.hInstance = g_Config.hApp;
		wc.lpszClassName = g_Config.pClassName = _T("MLT.AE Main");
		wc.lpszMenuName = NULL;
		wc.hbrBackground = NULL;
		wc.hCursor = NULL;
		wc.hIcon = LoadIcon(g_Config.hApp, MAKEINTRESOURCE(IDI_MLTAE));
		wc.lpfnWndProc = MainWndProc;
		wc.style = CS_HREDRAW | CS_VREDRAW | CS_SAVEBITS;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;

		ATOM cid = RegisterClass(&wc);
		if (cid == NULL) return FALSE;

	// create main window
		HWND hWnd;
		hWnd = CreateWindow(
			g_Config.pClassName, g_Config.pAppName,
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
			NULL, NULL, g_Config.hApp, NULL);
		long l = GetLastError();
		if (hWnd == NULL) return FALSE;
		g_Config.hMainWindow = hWnd;

	return TRUE;
}

LRESULT _stdcall MainWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_CREATE:
		::ShowCursor(FALSE);
		break;
	case WM_CLOSE:
		::ShowCursor(TRUE);
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
