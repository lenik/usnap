class GWin {
	static LONG cc;
public:
	HINSTANCE hInstance;
	int nCmdShow;
public:
	HWND hWnd;
	HDC hDC;
public:
	WNDCLASSEX wc;
	struct CreateWindowExParam {
		DWORD dwExStyle;  /* extended window style */
		LPCTSTR lpClassName;  /* pointer to registered class name */
		LPCTSTR lpWindowName;  /* pointer to window name */
		DWORD dwStyle;  /* window style */
		int x;  /* horizontal position of window */
		int y;  /* vertical position of window */
		int nWidth;  /* window width */
		int nHeight;  /* window height */
		HWND hWndParent;  /* handle to parent or owner window */
		HMENU hMenu;  /* handle to menu, or child-window identifier */
		HINSTANCE hInstance;  /* handle to application instance */
		LPVOID lpParam;  /* pointer to window-creation data */
	} param;
public:
	ATOM Init();
	HWND Create();
	int Destroy();
public:
	GWin(HINSTANCE, int);
};

LONG GWin::cc = 0;

LRESULT CALLBACK GWinProc(
						  HWND hWnd,
						  UINT Msg,
						  WPARAM wParam,
						  LPARAM lParam) {
	switch (Msg) {
	case WM_CREATE:
		break;
	case WM_QUIT:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, Msg, wParam, lParam);
	}
	return 0;
}

GWin::GWin(HINSTANCE hInstance, int nCmdShow) {
	this->hInstance = hInstance;
	this->nCmdShow = nCmdShow;
	WORD lpszClassName[256];
	wsprintf((LPSTR)lpszClassName, "GWin 1.00 [%08l]", cc++);
	wc.lpszClassName = (LPSTR)lpszClassName;
	wc.lpszMenuName = NULL;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpfnWndProc = GWinProc;
	wc.cbClsExtra = wc.cbWndExtra = 0;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;

	param.dwExStyle = WS_EX_OVERLAPPEDWINDOW;
	param.dwStyle = WS_OVERLAPPEDWINDOW;
	param.hInstance = hInstance;
	param.hMenu = NULL;
	param.hWndParent = NULL;
	param.lpClassName = wc.lpszClassName;
	param.lpParam = NULL;
	param.lpWindowName = "General Window 1.00";
	param.nWidth = param.nHeight = param.x = param.y = CW_USEDEFAULT;
}

ATOM GWin::Init() {
	return (RegisterClassEx(&wc));
}

HWND GWin::Create() {
	hWnd = CreateWindowEx(
		param.dwExStyle, param.lpClassName, param.lpWindowName, param.dwStyle,
		param.x, param.y, param.nWidth, param.nHeight,
		param.hWndParent, param.hMenu, param.hInstance, param.lpParam);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	hDC = GetDC(hWnd);
	return hWnd;
}

int GWin::Destroy() {
	return (UnregisterClass(wc.lpszClassName, wc.hInstance));
}
