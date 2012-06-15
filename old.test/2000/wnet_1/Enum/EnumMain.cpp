
/*
 * Network resources enumulation
 *
 * DanSei / TopCroak Software
 * Apr22-2000
 *
 * (C) Copyright
 * All rights reserved.
 */

#include <winnetwk.h>

#ifndef WINDOWS

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	NETRESOURCE nr;
	DWORD result;

	return 0;
}

#else

#include <GWin.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInsatance, LPSTR lpCmdLine, int nCmdShow) {

	HWND mainWnd;

	mainWnd = CreateWindow(
		"EDIT",
		"Netware resource enums",
		WS_OVERLAPPEDWINDOW | ES_MULTILINE,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(mainWnd, nCmdShow);
	UpdateWindow(mainWnd);

	////////////
	NETRESOURCE nr;
	CHAR szUserName[32] = "–ªºÃ¿◊",
		szPassword[32] = "ilovelq",
		szLocalName[32] = "Y:",
		szRemoteName[200] = "\\\\Ã“ø«–≈“µ\\Alt";
	DWORD res;

	nr.dwType = RESOURCETYPE_ANY;
	nr.lpLocalName = szLocalName;
	nr.lpRemoteName = szRemoteName;
	nr.lpProvider = NULL;

	res = WNetAddConnection2(&nr, NULL, NULL, FALSE); //, szUserName, FALSE);

	res = WNetAddConnection3(NULL, &nr, NULL, NULL, WNAC_UPDATE_PROFILE);

	if (res) {
		PrintError(res);
		CHAR strBuf[1024], strName[512];

		WNetGetLastError(&res, strBuf, 1024, strName, 512);
		MessageBox(NULL, strBuf, "Error: ", MB_OK);
	}

	MSG msg;

	while (GetMessage(&msg, mainWnd, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

#endif