
#include "StdAfx.h"

#include "FastImg.h"

// ...

BOOL	_stdcall FI_BitBlt_E_Call_Scan(LPDWORD bitsDest, LPDWORD bitsSrc, LONG width, LONG height, DWORD dwParam) {
	return TRUE;
}

BOOL	_stdcall FI_BitBlt_E_Scan(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy, DWORD scanOption) {
	return FI_BitBlt_Extend_Fn(
		hDestDC, destx, desty, width, height,
		hSrcDC, srcx, srcy,
		FI_BitBlt_E_Call_Scan, scanOption);
}

// Gradient
BOOL	_stdcall FI_BitBlt_E_Call_Gradient(LPDWORD bitsDest, LPDWORD bitsSrc, LONG width, LONG height, DWORD gradientOption) {
	BOOL	vertical	= gradientOption & 0x00008000;

	DWORD	lineColor;
	if (vertical) {
		for (x = 0; x < width; x++) {
			lineColor = FI_BitBlt_Call_Alpha(alpha2, alpha1, (x << 8) / width);
			for (y = 0; y < height; y++) {
				bitsDest[_I(x, y)] = lineColor;
			}
		}
	} else {
		for (y = 0; y < height; y++) {
			lineColor = FI_BitBlt_Call_Alpha(alpha2, alpha1, (y << 8) / height);
			for (x = 0; x < width; x++) {
				bitsDest[_I(x, y)] = lineColor;
			}
		}
	}
	return TRUE;
}

BOOL	_stdcall FI_BitBlt_E_Gradient(HDC hDescDC, LONG destx, LONG desty, LONG width, LONG height, DWORD color1, DWORD color2, BOOL bVertical) {
	DWORD	dwParam = 0;

	alpha1 = color1;
	alpha2 = color2;
	if (bVertical)	dwParam |= 0x00008000;

	return FI_BitBlt_Fn(
		hDescDC, destx, desty, width, height,
		0, 0, 0,
		BITBLT_EXTEND | BITBLT_ONLYDEST,
		(LPARAM)FI_BitBlt_E_Call_Gradient, dwParam);
}
