// mltAE.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include "mltAE.h"
#include "resource.h"


AEEnvironment g_Env;
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

	ShowWindow(g_Env.hMainWindow, nCmdShow);
	UpdateWindow(g_Env.hMainWindow);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}


void InitializeModules() {
	//
}

void Play() {
	InitializeModules();
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
		wc.lpszClassName = g_Env.pClassName = _T("MLT.AE Main");
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
		g_Env.dwMainStyle = WS_OVERLAPPEDWINDOW;
		hWnd = CreateWindow(
			g_Env.pClassName, g_Config.pAppName,
			g_Env.dwMainStyle,
			CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
			NULL, NULL, g_Config.hApp, NULL);
		long l = GetLastError();
		if (hWnd == NULL) return FALSE;
		g_Env.hMainWindow = hWnd;

	// init procs
		_sp_init();

	return TRUE;
}

LRESULT _stdcall MainWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	BOOL bProcessed = TRUE;
	int ID = wParam & 0xFFFFul;
	int Event = wParam >> 16;
	HWND hCtl = (HWND)lParam;
	int Button = wParam;
	int x = lParam & 0xFFFFul;
	int y = lParam >> 16;


	switch (message) {
	case WM_CREATE:
		{
			::ShowCursor(FALSE);
			RECT r;
			::GetClientRect(hWnd, &r);
		}
		break;
	case WM_CLOSE:
		::ShowCursor(TRUE);
		bProcessed = FALSE;
		break;
	case WM_PAINT:
		break;
	case WM_MOUSEMOVE:
		{
			HDC hDC = GetDC(hWnd);
			SetROP2(hDC, R2_XORPEN);
			static int lx,ly;
			Ellipse(hDC, lx - 10, ly - 10, lx + 10, ly + 10);
			Ellipse(hDC, x - 10, y - 10, x + 10, y + 10);
			lx = x;
			ly = y;
			ReleaseDC(hWnd, hDC);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		bProcessed = FALSE;
	}

	if (!bProcessed) {
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}
