
#include "StdAfx.h"

#include "FastImg.h"

// ...

BOOL	_stdcall FI_BitBlt_E_Call_Brick(LPDWORD destBits, LPDWORD srcBits, LONG width, LONG height, DWORD brickOption) {
	// brickFunc:	砖化功能
	//		00	均匀方砖
	BYTE	brickFunc	= (BYTE)(brickOption >> 24);
	BYTE	brickParam	= (BYTE)(brickOption >> 16);
	BYTE	brickWidth	= (BYTE)(brickOption >> 8);
	BYTE	brickHeight	= (BYTE)(brickOption);

	switch (brickFunc) {
	case 0:
		if (brickWidth == 0 || brickHeight == 0) return TRUE;

		if (brickParam & 0x01 == 0) {
			// 不计算偏移
			alpha1	= 0;
			alpha2	= 0;
		} else {
			alpha1	%= brickWidth;
			alpha2	%= brickHeight;
		}

		for (y = -(LONG)alpha2; y < height; y += brickHeight) {
			LONG	startY	= _MAX(y, 0);
			LONG	edgeY	= _MIN(startY + brickHeight, height);
			for (x = -(LONG)alpha1; x < width; x += brickWidth) {
				DWORD	brickR = 0, brickG = 0, brickB = 0;
				DWORD	brick;
				LONG	startX	= _MAX(x, 0);
				LONG	edgeX	= _MIN(startX + brickWidth, width);
				double	sample = (edgeY - startY) * (edgeX - startX);
				LONG	sx, sy;
				for (sy = startY; sy < edgeY; sy++) {
					for (sx = startX; sx < edgeX; sx++) {
						DWORD	ref = destBits[_I(sx, sy)];
						brickR	+= _R(ref);
						brickG	+= _G(ref);
						brickB	+= _B(ref);
					}
				}
				brickR	= (DWORD)(brickR / sample);
				brickG	= (DWORD)(brickG / sample);
				brickB	= (DWORD)(brickB / sample);
				brick	= _RGB(brickR, brickG, brickB);
				for (sy = startY; sy < edgeY; sy++) {
					for (sx = startX; sx < edgeX; sx++) {
						destBits[_I(sx, sy)] = brick;
					}
				}
			}
		}
		break;
	case 1:
		;
	default:
		return FALSE;
	}
	return TRUE;
}

BOOL	_stdcall FI_BitBlt_E_Brick(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, DWORD brickOption) {
	return FI_BitBlt_Fn(
		hDestDC, destx, desty, width, height,
		0, 0, 0,
		BITBLT_EXTEND | BITBLT_ONLYDEST,
		(LPARAM)FI_BitBlt_E_Call_Brick, brickOption);
}
