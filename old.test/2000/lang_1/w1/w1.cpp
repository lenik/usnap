// w1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include <GWin.h>

#include <stdlib.h>
typedef DWORD (*pproc)(DWORD dst, DWORD src);

DWORD   copyproc(DWORD dst, DWORD src) {
	return src;
}

DWORD	lightproc(DWORD dst, DWORD src) {
	BYTE r, g, b;
	r = (BYTE)(src >> 16);
	g = (BYTE)(src >> 8);
	b = (BYTE)(src & 0xFF);

	if (r < 155) r += 100;
	else r = 255;
	if (g < 155) g += 100;
	else g = 255;
	if (b < 155) b += 100;
	else b = 255;

	dst = (r << 16) | (g << 8) | b;
	return dst;
}

BOOL	_stdcall BB(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy, pproc tp) {
	HDC		hcDest,		hcSrc;
	HBITMAP		hoDest,		hoSrc;
	HBITMAP		hbmDest,	hbmSrc;
	BITMAPINFO	bmiDest,	bmiSrc;
	DWORD		*bitsDest,	*bitsSrc;
	LONG		sizeDest,	sizeSrc;
	LONG		x, y;

	BOOL		r;

	// 变量初始化
		sizeDest = sizeSrc = width * height;

		memset(&bmiDest, 0, sizeof(BITMAPINFO));
		memset(&bmiSrc, 0, sizeof(BITMAPINFO));
		bmiDest.bmiHeader.biSize =
			bmiSrc.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		bmiDest.bmiHeader.biPlanes =
			bmiSrc.bmiHeader.biPlanes = 1;
		bmiDest.bmiHeader.biBitCount =
			bmiSrc.bmiHeader.biBitCount = 32;
		bmiDest.bmiHeader.biWidth =
			bmiSrc.bmiHeader.biWidth = width;
		bmiDest.bmiHeader.biHeight =
			bmiSrc.bmiHeader.biHeight = height;

		bitsDest = new DWORD[sizeDest];
		bitsSrc  = new DWORD[sizeSrc];

	// 获取源图像数据
		hcDest  = CreateCompatibleDC(hDestDC);
		hcSrc   = CreateCompatibleDC(hSrcDC);
		hbmDest = CreateCompatibleBitmap(hDestDC, width, height);
		hbmSrc  = CreateCompatibleBitmap(hSrcDC, width, height);
		hoDest  = (HBITMAP)SelectObject(hcDest, hbmDest);
		hoSrc   = (HBITMAP)SelectObject(hcSrc,  hbmSrc);

		BitBlt(hcDest, 0, 0, width, height, hDestDC, destx, desty, SRCCOPY);
		BitBlt(hcSrc,  0, 0, width, height, hSrcDC,  srcx,  srcy,  SRCCOPY);
		r = GetDIBits(hDestDC, hbmDest, 0, height, bitsDest, &bmiDest, DIB_RGB_COLORS);
		r = GetDIBits(hSrcDC,  hbmSrc,  0, height, bitsSrc,  &bmiSrc,  DIB_RGB_COLORS);

		SelectObject(hcDest, hoDest);
		DeleteObject(hbmDest);
		DeleteDC(hcDest);
		SelectObject(hcSrc,  hoSrc);
		DeleteObject(hbmSrc);
		DeleteDC(hcSrc);

	// 图像操作
		LONG p = 0;
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				bitsDest[p] = (*tp)(bitsDest[p], bitsSrc[p]);
				p++;
			}
		}

		r = SetDIBitsToDevice(
			hDestDC, destx, desty, width, height,
			0, 0,
			0, height,
			bitsDest, &bmiDest, DIB_RGB_COLORS);

	// 结束返回

		delete[] bitsDest;
		delete[] bitsSrc;

	return r;
}

BOOL	_stdcall BB1(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy) {
	int x, y;
	COLORREF cd, cs;
	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			cd = GetPixel(hDestDC, destx + x, desty + y);
			cs = GetPixel(hSrcDC, srcx + x, srcy + y);
			SetPixel(hDestDC, destx + x, desty + y, cs);
		}
	}
	return TRUE;
}

void CreateBMPFile(LPTSTR pszFile, PBITMAPINFO pbi, HBITMAP hBMP, HDC hDC)
 {
     HANDLE hf;                 // file handle
    BITMAPFILEHEADER hdr;       // bitmap file-header
    PBITMAPINFOHEADER pbih;     // bitmap info-header
    LPBYTE lpBits;              // memory pointer
    DWORD dwTotal;              // total count of bytes
    DWORD cb;                   // incremental count of bytes
    BYTE *hp;                   // byte pointer
    DWORD dwTmp;
    pbih = (PBITMAPINFOHEADER) pbi;
    lpBits = (LPBYTE) GlobalAlloc(GMEM_FIXED, pbih->biSizeImage);
    cb=GetDIBits(hDC, hBMP, 0, (WORD) pbih->biHeight, lpBits, pbi, DIB_RGB_COLORS);
    hf = CreateFile    (pszFile, GENERIC_READ | GENERIC_WRITE, (DWORD) 0, NULL,
	    CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, (HANDLE) NULL);
    hdr.bfType = 0x4d42;        // 0x42 = "B" 0x4d = "M"
    hdr.bfSize = (DWORD) (sizeof(BITMAPFILEHEADER) +
                 pbih->biSize + pbih->biClrUsed
                 * sizeof(RGBQUAD) + pbih->biSizeImage);
    hdr.bfReserved1 = 0;
    hdr.bfReserved2 = 0;
   hdr.bfOffBits = (DWORD) sizeof(BITMAPFILEHEADER) + pbih->biSize + pbih->biClrUsed * sizeof (RGBQUAD);
    WriteFile(hf, (LPVOID) &hdr, sizeof(BITMAPFILEHEADER), (LPDWORD) &dwTmp,  NULL);
    WriteFile(hf, (LPVOID) pbih, sizeof(BITMAPINFOHEADER) + pbih->biClrUsed * sizeof (RGBQUAD),
                  (LPDWORD) &dwTmp, ( NULL));
    dwTotal = cb = pbih->biSizeImage;
    hp = lpBits;
    WriteFile(hf, (LPSTR) hp, (int) cb, (LPDWORD) &dwTmp,NULL) ;
    CloseHandle(hf) ;
    GlobalFree((HGLOBAL)lpBits);
}

LRESULT CALLBACK mainproc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_PAINT: {
			HDC	hDC = GetDC(hWnd);
			HDC	hcDC = CreateCompatibleDC(hDC);
			HBITMAP	hbm;
			BITMAPINFO bmi;
			BYTE lpvBits[110000];
			BOOL r;

			memset(&bmi.bmiHeader, 0, sizeof(bmi.bmiHeader));
			bmi.bmiHeader.biSize = sizeof(bmi.bmiHeader);
			bmi.bmiHeader.biBitCount = 32;
			bmi.bmiHeader.biHeight = 300;
			bmi.bmiHeader.biWidth = 300;
			bmi.bmiHeader.biPlanes = 1;

			memset(lpvBits, 0, 100000);
			for (int i = 0; i < 50000; i+=1)
				lpvBits[i] =rand();// i * 256 / 20000;

			SetPixel(hDC, 0, 0, 0x123456);
			SetPixel(hDC, 299, 299, 0x234567);
			SetPixel(hDC, 300, 300, 0x345678);
			Ellipse(hDC, 95,95,100,100);

			r=SetDIBitsToDevice(
				hDC,
				100, 100, 200, 50,
				0, 0,
				0, 50,			// scan lines
				lpvBits, &bmi, DIB_RGB_COLORS);
	/*/
			HBITMAP	hbmDest, ho;
			hbmDest = CreateBitmap(300, 300, 1, 32, lpvBits);
			ho =(HBITMAP)SelectObject(hDC, hbmDest);
			//if (ho == NULL) PrintError(GetLastError(), hDC, 30, 170);
			r = SetDIBits(hDC, hbmDest, 0, 50, lpvBits, &bmi, DIB_RGB_COLORS);
	*/
			PrintError(GetLastError(), hDC, 30, 150);
			//r=DeleteObject(hbm);
			ReleaseDC(hWnd, hDC);
		       }
		break;
	case WM_LBUTTONDOWN:
		PostQuitMessage(0);
		break;
	case WM_RBUTTONDOWN:
		InvalidateRect(hWnd, NULL, FALSE);
		break;
	case WM_KEYDOWN:
		{
			switch ((CHAR)wParam) {
			case 'B': {
				for (int xx = 0; xx < 1; xx++) {
					HDC	hDC = GetDC(hWnd);
					BB(hDC, 10, 10, 200, 50, hDC, 100, 100, lightproc);
					ReleaseDC(hWnd, hDC);
					mainproc(hWnd, WM_PAINT, 0, 0);
				}
				  }
				break;
			case 'V': {
				HDC	hDC = GetDC(hWnd);
				BB1(hDC, 10, 10, 200, 50, hDC, 100, 100);
				ReleaseDC(hWnd, hDC);
				  }
				mainproc(hWnd, WM_PAINT, 0, 0);
				break;
			case 'F': {
				BOOL r;
				HDC hDC = GetDC(hWnd);
				HDC hDC2 = CreateCompatibleDC(hDC);
				HBITMAP hbm, ho;
				hbm = (HBITMAP)LoadImage(
					0, "B:\\bmp01.bmp", IMAGE_BITMAP,
					300, 200, LR_LOADFROMFILE);
				ho = (HBITMAP)SelectObject(hDC2, hbm);
				BitBlt(hDC2, 0, 0, 100, 50, hDC, 100, 100, SRCCOPY);
				BitBlt(hDC, 0, 0, 300, 300, hDC2, 0, 0, SRCCOPY);

				BITMAPINFO bi;
				memset(&bi, 0, sizeof(bi));
				bi.bmiHeader.biSize = sizeof(bi.bmiHeader);
				GetDIBits(hDC2, hbm, 0, 1, NULL, &bi, DIB_RGB_COLORS);
				bi.bmiHeader.biCompression = 0;

				CreateBMPFile("B:\\1k.bmp", &bi, hbm, hDC2);
				SelectObject(hDC2, ho);
				r = DeleteDC(hDC2);
				r = DeleteObject(hbm);
				r = ReleaseDC(hWnd, hDC);
				  }
				break;
			case 'C':
				{
					HDC hDC = GetDC(hWnd);
					RECT r;
					r.left = r.top = 0;
					r.right = r.bottom = 300;
					FillRect(hDC, &r, (HBRUSH)GetStockObject(GRAY_BRUSH));
					ReleaseDC(hWnd, hDC);
				}
				InvalidateRect(hWnd, NULL, TRUE);
				break;
			case 'D':
				InvalidateRect(hWnd, NULL, FALSE);
				break;

			}
		}
		break;
	default:
		;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int APIENTRY WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nS) {
	GWin	w(hI, nS);

	w.wc.lpfnWndProc = (WNDPROC)mainproc;
	w.wc.style = CS_SAVEBITS;
w.param.nWidth = 300;
w.param.nHeight = 300;
	w.Register();
	w.Create();

//	SetPixel(w.hDC, 10, 12, 0x123456);

	w.Go();
	return 0;
}
