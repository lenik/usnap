
#include "StdAfx.h"

#include "FastImg.h"

// ...

BOOL	_stdcall FI_BitBlt_E_Blur(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, DWORD blurOption) {
	return FI_BitBlt_Fn(
		hDestDC, destx, desty, width, height,
		0, 0, 0,
		BITBLT_EXTEND | BITBLT_ONLYDEST,
		(DWORD)FI_BitBlt_E_Call_Blur, blurOption);
}
BOOL	_stdcall FI_BitBlt_E_Call_Blur(LPDWORD destBits, LPDWORD srcBits, LONG width, LONG height, DWORD blurOption) {
	// blurFunc:	模糊功能	00-FF 对应于 锐化-模糊化
	// blurDepth:　	模糊深度	00-FF 对应于 越附近-越广阔
	// blurLevel:	模糊等级	00-FF 对应于 越原始-越模糊
	WORD	blurFunc	= (WORD)(blurOption >> 16);
	BYTE	blurDepth	= (BYTE)(blurOption >> 8) & 0xF;
	float	blurLevel	= (((LONG)(blurOption & 0xFF)) - 128) / 128;

	if (blurFunc != 0) return FALSE;

	float	sampleMatrix[33][33];
	LONG	sx, sy;

	for (sy = -blurDepth; sy <= blurDepth; sy++) {
		for (sx = -blurDepth; sx <= blurDepth; sx++) {

			float factor =
			sampleMatrix[sy + blurDepth][sx + blurDepth] =
				sx
	for (y = 0; y < height && height > 1; y += height - 1) {
		for (x = 0; x < width && width > 1; x += width - 1) {
			srcBits[_I(x, y)] = srcBits[_I(x, y)];
		}
	}

	for (y = 1; y < height - 1; y++) {
		for (x = 1; x < width - 1; x++) {
			srcBits[_I(x, y)] =
				_A(_D(destBits[_I(x - 1, y - 1)], blurDepth << 15),
				_A(_D(destBits[_I(x    , y - 1)], blurDepth << 15),
				_A(_D(destBits[_I(x + 1, y - 1)], blurDepth << 15),
				_A(_D(destBits[_I(x - 1, y    )], blurDepth << 15),
				_A(_D(destBits[_I(x    , y    )], blurDepth << 15),
				_A(_D(destBits[_I(x + 1, y    )], blurDepth << 15),
				_A(_D(destBits[_I(x + 1, y + 1)], blurDepth << 15),
				_A(_D(destBits[_I(x    , y + 1)], blurDepth << 15),
				   _D(destBits[_I(x + 1, y + 1)], (blurDepth * (blurDepth - 8)) << 15)))))))));
		}
	}

	p = 0;
	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			destBits[p] = srcBits[p];
			p++;
		}
	}

	return TRUE;
}
