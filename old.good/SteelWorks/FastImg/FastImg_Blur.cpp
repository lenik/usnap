
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
	BYTE	blurDepth	= (BYTE)(blurOption >> 8) & 0x0F;
	double	blurLevel	= (LONG)(blurOption & 0xFF) - 128;

	if (blurFunc != 0) return FALSE;

	blurLevel /= 128;

	double	sampleMatrix[31][31];
	double	sampleCenter = 0;
	LONG	sx, sy;

	for (sy = -blurDepth; sy <= blurDepth; sy++) {
		for (sx = -blurDepth; sx <= blurDepth; sx++) {
			LONG abx = sx < 0 ? -sx : sx;
			LONG aby = sy < 0 ? -sy : sy;
			double factor = 1 / (1 + sqrt(abx * abx + aby * aby)) * blurLevel;
			sampleMatrix[sy + blurDepth][sx + blurDepth] = factor;
			if (sx != 0 && sy != 0) sampleCenter += factor;
		}
	}
	sampleMatrix[blurDepth][blurDepth] = 1 - sampleCenter;

	// copy temparray
	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			srcBits[_I(x, y)] = destBits[_I(x, y)];
		}
	}

	DWORD	blur;
	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			blur = 0;
			for (sy = -blurDepth; sy <= blurDepth; sy++) {
				if (y + sy < 0 || y + sy >= height) continue;
				for (sx = -blurDepth; sx <= blurDepth; sx++) {
					if (x + sx < 0 || x + sx >= width) continue;
					DWORD	ref = srcBits[_I(x + sx, y + sy)];
					double	sample = sampleMatrix[sy + blurDepth][sx + blurDepth];
					if (sample >= 0) {
						blur = _A(blur, _M(ref, sample));
					} else {
						blur = _S(blur, _M(ref, -sample));
					}
				}
			}
			destBits[_I(x, y)] = blur;
		}
	}

	return TRUE;
}
