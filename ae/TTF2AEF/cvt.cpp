
#include "stdafx.h"


HDC CreateFormatedDC(int w, int h, int bits);
BOOL GetBitsFromHDC(HDC hDC, int x0, int y0, int w, int h, LPVOID pBuf);
BOOL GetBitmapInfoFromHDC(HDC hDC, BITMAPINFO *pBI);

BOOL


BOOL Convert(LPCTSTR pszFontName, LPCTSTR pszFileName, BOOL bVector) {

	//
	if (bVector) return FALSE;

	HDC hDC = CreateDC(_T("SCREEN"), NULL, NULL, NULL);
	HDC hDC2 = CreateCompatibleDC(hDC);
	HBITMAP hbm = ::CreateCompatibleBitmap(hDC2, , h);
	SelectObject(hDC2, hbm);
	SetPixel(hDC2, 100, 100, 0);

	HFONT hFont = CreateFont(
		,,,,,,size,,,,,,,pszFontName);
	SelectObject(hDC2, hFont);

	BYTE *pBuf = new BYTE[10000];

	BITMAPINFO bi;




	return;
}