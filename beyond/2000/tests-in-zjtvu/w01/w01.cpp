#include "GWin.h"

INT WINAPI WinMain(
				   HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
				   LPSTR lpCmdLine,
				   INT nCmdShow) {
	GWin w(hInstance, nCmdShow), w2(hInstance, nCmdShow);
	w.Register(); w2.Register();
	w.Create(); w2.Create();
	GWin w3(hInstance, nCmdShow);
	w3.param.lpszClassName = "BUTTON";
	w3.param.dwStyle = WS_CHILD | WS_SIZEBOX | BS_PUSHBUTTON;
	w3.param.hWndParent = w2.hWnd;
	w3.param.x = w3.param.y = 20;
	w3.param.nHeight = w3.param.nWidth = 300;
	w3.Create();
	MessageBox(w.hWnd, "PAUSE", "PAUSE", MB_OK);
	w.Destroy(); w2.Destroy(); w3.Destroy();
	return 0;
}
