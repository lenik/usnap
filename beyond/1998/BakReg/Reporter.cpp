class Reporter {
protected:
	HLOCAL hMsg;
	LPSTR lpMsg;
	HWND hWnd;
public:
	void Clear() { LocalFree(hMsg); }
	HLOCAL Append(LPSTR);	// Append text strings.
	HLOCAL Append(int);		// Append blank spaces to express indent (different levels)
public:
	Reporter(HWND, LPSTR);
	~Reporter();
} *r;

HLOCAL Reporter::Append(LPSTR lpStr) {
	const int len = lstrlen(lpMsg);
	HLOCAL hx = LocalReAlloc(hMsg, len + lstrlen(lpStr) + 1, 0);
	if (hx != NULL) {
		hMsg = hx;
		lpMsg = (LPSTR)LocalLock(hMsg);
		lstrcpy(lpMsg + len, lpStr);
		LocalUnlock(hMsg);
		SetWindowText(hWnd, lpMsg);
	}
	return hx;
}

HLOCAL Reporter::Append(int iWidth) {
	HLOCAL hx = NULL;
	LPSTR lpBlank = new CHAR[iWidth + 1];
	if (lpBlank != NULL) {
		for (int i = 0; i < iWidth; i++) {
			lpBlank[i] = ' ';
		}
		lpBlank[iWidth] = '\0';
		hx = this->Append(lpBlank);
		delete lpBlank;
	}
	return hx;
}

Reporter::Reporter(HWND _hWnd, LPSTR _lpStr) {
	const int len = lstrlen(_lpStr) + 1;
	HLOCAL hx = LocalAlloc(LMEM_MOVEABLE, len);
	hWnd = _hWnd;
	hMsg = hx;
	if (hx != NULL) {
		lpMsg = (LPSTR)LocalLock(hMsg);
		lstrcpy(lpMsg, _lpStr);
		LocalUnlock(hMsg);
		SetWindowText(hWnd, lpMsg);
	} else {
		lpMsg = NULL;
	}
}

Reporter::~Reporter() {
	if (hMsg != NULL) {
		LocalFree(hMsg);
	}
}
