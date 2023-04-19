// FastImg.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#include "FastImg.h"

BOOL		bRunning = FALSE;

HDC		hcDest,		hcSrc;
HBITMAP		hoDest,		hoSrc;
HBITMAP		hbmDest,	hbmSrc;
BITMAPINFO	bmiDest,	bmiSrc;

DWORD		*bitsDest,	*bitsSrc;
LONG		sizeDest,	sizeSrc;

LONG		x;
LONG		y;
LONG		width;
LONG		height;
LONG		p;		// 注意扫描线的方向与实际存储的方向之间的关系

DWORD		alpha1, alpha2;
DWORD		miniDelay = 0;

BYTE		alphaTable[257];
BYTE		alphaColor[257][256];

#include "FastImg_Helper.h"

BOOL	_stdcall FI_BitBlt_Fn(HDC		hDestDC,
			      LONG		destx,
			      LONG		desty,
			      LONG		_width,
			      LONG		_height,
			      HDC		hSrcDC,
			      LONG		srcx,
			      LONG		srcy,
			      LONG		fntype,
			      LPARAM		lParam,
			      DWORD		dwParam) {

	if (_width < 0 || _height < 0) return FALSE;
	if (_width > FI_MAXWIDTH || _height > FI_MAXHEIGHT) return FALSE;
	if (_width == 0 || _height == 0) return TRUE;

	width	= _width;
	height	= _height;

	LONG		tCount = 0;
	while (bRunning && tCount < FI_MAXDELAY) {
		Sleep(1);
		tCount++;
	} bRunning = TRUE;

	BOOL		r = FALSE;

	// 变量初始化
		sizeDest = sizeSrc = width * height;

		bmiDest.bmiHeader.biWidth =
			bmiSrc.bmiHeader.biWidth = width;
		bmiDest.bmiHeader.biHeight =
			bmiSrc.bmiHeader.biHeight = height;

		if ((bitsDest = new DWORD[sizeDest]) == NULL) goto L_1;
		if ((bitsSrc  = new DWORD[sizeSrc]) == NULL) goto L_2;

	// 获取源图像数据
	if (!(fntype & BITBLT_TESTCALLBACK)) {
		if (fntype & BITBLT_ONLYSRC) {
			for (p = 0; p < sizeDest; p++) bitsDest[p] = alpha2;
		} else {
			if (!(hcDest  = CreateCompatibleDC(hDestDC))) goto L1;
			if (!(hbmDest = CreateCompatibleBitmap(hDestDC, width, height))) goto L2;
			if (!(hoDest  = (HBITMAP)SelectObject(hcDest, hbmDest))) goto L3;
			if (!(r = BitBlt(hcDest, 0, 0, width, height, hDestDC, destx, desty, SRCCOPY))) goto L4;
			if (!(r = GetDIBits(hDestDC, hbmDest, 0, height, bitsDest, &bmiDest, DIB_RGB_COLORS))) goto L5;
		}
		if (fntype & BITBLT_ONLYDEST) {
			for (p = 0; p < sizeSrc; p++) bitsSrc[p] = alpha1;
		} else {
			if (!(hcSrc   = CreateCompatibleDC(hSrcDC))) goto L6;
			if (!(hbmSrc  = CreateCompatibleBitmap(hSrcDC, width, height))) goto L7;
			if (!(hoSrc   = (HBITMAP)SelectObject(hcSrc,  hbmSrc))) goto L8;
			if (!(r = BitBlt(hcSrc,  0, 0, width, height, hSrcDC,  srcx,  srcy,  SRCCOPY))) goto L9;
			if (!(r = GetDIBits(hSrcDC,  hbmSrc,  0, height, bitsSrc,  &bmiSrc,  DIB_RGB_COLORS))) goto L10;
		}
	}

	// 图像操作
	if (!(fntype & BITBLT_TESTBITMAP)) {
		p = 0;
		switch (fntype & 0xFF) {
		case BITBLT_SIMPLE: {
			BITBLTPROC bitblt_callback = (BITBLTPROC)lParam;
			for (y = 0; y < height; y++) {
				for (x = 0; x < width; x++) {
					bitsDest[p] = (*bitblt_callback)(bitsDest[p], bitsSrc[p]);
					p++;
				}
			}
				    }
			break;
		case BITBLT_BIDIRECTION: {
			BITBLTPROC bitblt_bi_callback = (BITBLTPROC)lParam;
			for (y = 0; y < height; y++) {
				for (x = 0; x < width; x++) {
					(*bitblt_bi_callback)((DWORD)&bitsDest[p], (DWORD)&bitsSrc[p]);
					p++;
				}
			}
					 }
			break;
		case BITBLT_ALPHA: {
			BITBLTALPHAPROC bitblt_alpha_callback = (BITBLTALPHAPROC)lParam;
			for (y = 0; y < height; y++) {
				for (x = 0; x < width; x++) {
					bitsDest[p] = (*bitblt_alpha_callback)(bitsDest[p], bitsSrc[p], dwParam);
					p++;
				}
			}
				   }
			break;
		case BITBLT_ALPHA_H: {
			BITBLTALPHAPROC bitblt_alpha_callback = (BITBLTALPHAPROC)lParam;
			DWORD alpha;
			float ratio = ((float)alpha2 - (float)alpha1) / height;
			for (y = 0; y < height; y++) {
				alpha = (DWORD)(y * ratio + alpha1);
				for (x = 0; x < width; x++) {
					bitsDest[p] = (*bitblt_alpha_callback)(bitsDest[p], bitsSrc[p], alpha);
					p++;
				}
			}
				   }
			break;
		case BITBLT_ALPHA_V: {
			BITBLTALPHAPROC bitblt_alpha_callback = (BITBLTALPHAPROC)lParam;
			DWORD alpha;
			float ratio = ((float)alpha2 - (float)alpha1) / width;
			for (y = 0; y < height; y++) {
				for (x = 0; x < width; x++) {
					alpha = (DWORD)(x * ratio + alpha1);
					bitsDest[p] = (*bitblt_alpha_callback)(bitsDest[p], bitsSrc[p], alpha);
					p++;
				}
			}
				   }
			break;
		case BITBLT_EXTEND: {
			BITBLTEXTENDPROC bitblt_extend_callback = (BITBLTEXTENDPROC)lParam;
			r = (*bitblt_extend_callback)(bitsDest, bitsSrc, width, height, dwParam);
				    }
			break;
		default:
			r = FALSE;
		}
		if (!r) goto L11;
	}

		if (!(fntype & BITBLT_ONLYSRC)) {
			r = SetDIBitsToDevice(
				hDestDC, destx, desty, width, height,
				0, 0,
				0, height,
				bitsDest, &bmiDest, DIB_RGB_COLORS);
			if (!(fntype & BITBLT_ONLYDEST)) {
				if (fntype & 0xFF == BITBLT_BIDIRECTION) {
					r &= SetDIBitsToDevice(
						hSrcDC, srcx, srcy, width, height,
						0, 0,
						0, height,
						bitsSrc, &bmiSrc, DIB_RGB_COLORS);
				}
			}
		}

	// 结束返回
	if (!(fntype & BITBLT_TESTCALLBACK)) {
		L11:
		L10:
		L9:
		L8:
		L7:
		L6: r = SelectObject(hcSrc,  hoSrc) != NULL;
		L5: r = DeleteObject(hbmSrc);
		L4: r = DeleteDC(hcSrc);
		L3: r = SelectObject(hcDest, hoDest) != NULL;
		L2: r = DeleteObject(hbmDest);
		L1: r = DeleteDC(hcDest);
	}
		L_2: delete[] bitsDest;
		L_1: delete[] bitsSrc;

	bRunning = FALSE;
	return r;
}

BOOL	_stdcall FI_BitBlt_Simple_Fn(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy, BITBLTPROC bitblt_callback) {
	return FI_BitBlt_Fn(
		hDestDC, destx, desty, width, height,
		hSrcDC, srcx, srcy,
		BITBLT_SIMPLE, (LPARAM)bitblt_callback, 0
		);
}

BOOL	_stdcall FI_BitBlt_Simple_Add(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy) {
	return FI_BitBlt_Fn(
		hDestDC, destx, desty, width, height,
		hSrcDC, srcx, srcy,
		BITBLT_SIMPLE, (LPARAM)FI_BitBlt_Call_Add, 0
		);
}

BOOL	_stdcall FI_BitBlt_Simple_Sub(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy) {
	return FI_BitBlt_Fn(
		hDestDC, destx, desty, width, height,
		hSrcDC, srcx, srcy,
		BITBLT_SIMPLE, (LPARAM)FI_BitBlt_Call_Sub, 0
		);
}

BOOL	_stdcall FI_BitBlt_Simple_Mul(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, DWORD factor) {
	alpha1 = factor;
	return FI_BitBlt_Fn(
		hDestDC, destx, desty, width, height,
		0, 0, 0,
		BITBLT_SIMPLE | BITBLT_ONLYDEST, (LPARAM)FI_BitBlt_Call_Mul, 0
		);
}

BOOL	_stdcall FI_BitBlt_Simple_Div(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, DWORD factor) {
	alpha1 = factor;
	return FI_BitBlt_Fn(
		hDestDC, destx, desty, width, height,
		0, 0, 0,
		BITBLT_SIMPLE | BITBLT_ONLYDEST, (LPARAM)FI_BitBlt_Call_Div, 0
		);
}

BOOL	_stdcall FI_BitBlt_Merge(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy, DWORD key) {
	return FI_BitBlt_Fn(
		hDestDC, destx, desty, width, height,
		hSrcDC, srcx, srcy,
		BITBLT_ALPHA, (LPARAM)FI_BitBlt_Call_Merge, key
		);
}

BOOL	_stdcall FI_BitBlt_Alpha_Fn(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy, BITBLTALPHAPROC bitblt_alpha_callback, DWORD dwParam) {
	return FI_BitBlt_Fn(
		hDestDC, destx, desty, width, height,
		hSrcDC, srcx, srcy,
		BITBLT_ALPHA, (LPARAM)bitblt_alpha_callback, dwParam
		);
}

BOOL	_stdcall FI_BitBlt_Alpha_Simple(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy, DWORD alpha) {
	return FI_BitBlt_Fn(
		hDestDC, destx, desty, width, height,
		hSrcDC, srcx, srcy,
		BITBLT_ALPHA, (LPARAM)FI_BitBlt_Call_Alpha, alpha
		);
}

BOOL	_stdcall FI_BitBlt_Alpha_Merge(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy, DWORD alpha, DWORD key) {
	alpha1 = key;
	return FI_BitBlt_Fn(
		hDestDC, destx, desty, width, height,
		hSrcDC, srcx, srcy,
		BITBLT_ALPHA, (LPARAM)FI_BitBlt_Call_Alpha_Merge, alpha
		);
}

BOOL	_stdcall FI_BitBlt_LinearAlpha_H(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy, DWORD alphaTop, DWORD alphaBottom) {
	alpha1 = alphaBottom;
	alpha2 = alphaTop;
	return FI_BitBlt_Fn(
		hDestDC, destx, desty, width, height,
		hSrcDC, srcx, srcy,
		BITBLT_ALPHA_H, (LPARAM)FI_BitBlt_Call_Alpha, 0
		);
}

BOOL	_stdcall FI_BitBlt_LinearAlpha_V(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy, DWORD alphaLeft, DWORD alphaRight) {
	alpha1 = alphaLeft;
	alpha2 = alphaRight;
	return FI_BitBlt_Fn(
		hDestDC, destx, desty, width, height,
		hSrcDC, srcx, srcy,
		BITBLT_ALPHA_V, (LPARAM)FI_BitBlt_Call_Alpha, 0
		);
}

BOOL	_stdcall FI_BitBlt_LinearAlpha_Ex(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy, DWORD alphaAngleFromCenter) {
	return FALSE;
}

BOOL	_stdcall FI_BitBlt_Extend_Fn(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy, BITBLTEXTENDPROC bitblt_extend_callback, DWORD dwParam) {
	return FI_BitBlt_Fn(
		hDestDC, destx, desty, width, height,
		hSrcDC, srcx, srcy,
		BITBLT_EXTEND, (LPARAM)bitblt_extend_callback, dwParam
		);
}

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		initvar();
		break;
	case DLL_PROCESS_DETACH:
		cleanup();
		break;
	}
	return TRUE;
}