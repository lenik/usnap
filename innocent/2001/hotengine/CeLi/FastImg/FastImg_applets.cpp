
#include "StdAfx.h"

#include "FastImg.h"

BYTE	_stdcall FI_BitBlt_GetAlpha(DWORD alpha, DWORD color) {
	return alphaColor[alpha][color];
}

DWORD	_stdcall FI_BitBlt_Vars(DWORD op, LONG index, DWORD dwParam) {
	DWORD	*vp, lv;
	switch (op) {
	case FI_GETADDRESS:
		switch (index) {
		case FI_VAR_RUNNING:	return (DWORD)&bRunning;
		case FI_VAR_ALPHA1:	return (DWORD)&alpha1;
		case FI_VAR_ALPHA2:	return (DWORD)&alpha2;
		case FI_VAR_X:		return (DWORD)&x;
		case FI_VAR_Y:		return (DWORD)&y;
		case FI_VAR_WIDTH:	return (DWORD)&width;
		case FI_VAR_HEIGHT:	return (DWORD)&height;
		case FI_VAR_P:		return (DWORD)&p;
		case FI_VAR_ALPHAT:	return (DWORD)alphaTable;
		case FI_VAR_ALPHAC:	return (DWORD)alphaColor;
		case FI_VAR_BITSDEST:	return (DWORD)bitsDest;
		case FI_VAR_BITSSRC:	return (DWORD)bitsSrc;
		case FI_VAR_SIZEDEST:	return (DWORD)sizeDest;
		case FI_VAR_SIZESRC:	return (DWORD)sizeSrc;
		}
		break;
	case FI_GETVAL:
		vp = (DWORD *)FI_BitBlt_Vars(FI_GETADDRESS, index);
		if (vp != NULL) return *vp;
		break;
	case FI_SETVAL:
		vp = (DWORD *)FI_BitBlt_Vars(FI_GETADDRESS, index);
		if (vp != NULL) {
			lv = *vp;
			*vp = dwParam;
			return lv;
		}
		break;
	}
	return 0;
}

// callbacks
DWORD	_stdcall FI_BitBlt_Call_Copy(DWORD cDest, DWORD cSrc) { return cSrc; }
DWORD	_stdcall FI_BitBlt_Call_Order(DWORD cDest, DWORD cSrc) {
	_DRGB(o, DWORD, cDest);
	return (_RGB(oB, oG, oR)) << 8;
}

DWORD	_stdcall FI_BitBlt_Call_Add(DWORD cDest, DWORD cSrc) {
	DWORD	outR, outG, outB;

	outR	= _R(cDest) + _R(cSrc);
	outG	= _G(cDest) + _G(cSrc);
	outB	= _B(cDest) + _B(cSrc);

	outR	= _NOMORE(outR, 0xFF);
	outG	= _NOMORE(outG, 0xFF);
	outB	= _NOMORE(outB, 0xFF);

	return _RGB(outR, outG, outB);
}

DWORD	_stdcall FI_BitBlt_Call_Sub(DWORD cDest, DWORD cSrc) {
	DWORD	outR, outG, outB;

	outR	= _R(cDest) - _R(cSrc);
	outG	= _G(cDest) - _G(cSrc);
	outB	= _B(cDest) - _B(cSrc);

	outR	= _NOLESS0B(outR);
	outG	= _NOLESS0B(outG);
	outB	= _NOLESS0B(outB);

	return _RGB(outR, outG, outB);
}

DWORD	_stdcall FI_BitBlt_Call_Mul(DWORD cDest, DWORD cSrc) { return _M(cDest, (double)alpha1 / 0x10000); }
DWORD	_stdcall FI_BitBlt_Call_Mul_(DWORD cDest, double factor) {
	DWORD	outR, outG, outB;

	outR	= (DWORD)(_R(cDest) * factor);
	outG	= (DWORD)(_G(cDest) * factor);
	outB	= (DWORD)(_B(cDest) * factor);

	outR	= _NOMORE(outR, 0xFF);
	outG	= _NOMORE(outG, 0xFF);
	outB	= _NOMORE(outB, 0xFF);

	return _RGB(outR, outG, outB);
}

DWORD	_stdcall FI_BitBlt_Call_Div(DWORD cDest, DWORD cSrc) { return _D(cDest, (double)alpha1 / 0x10000); }
DWORD	_stdcall FI_BitBlt_Call_Div_(DWORD cDest, double factor) {
	DWORD	outR, outG, outB;

	outR	= (DWORD)(_R(cDest) / factor);
	outG	= (DWORD)(_G(cDest) / factor);
	outB	= (DWORD)(_B(cDest) / factor);

	outR	= _NOMORE(outR, 0xFF);
	outG	= _NOMORE(outG, 0xFF);
	outB	= _NOMORE(outB, 0xFF);

	return _RGB(outR, outG, outB);
}

DWORD	_stdcall FI_BitBlt_Call_Light(DWORD cDest, DWORD cSrc) {
	DWORD	outR, outG, outB;

	outR	= _MAX(_R(cDest), _R(cSrc));
	outG	= _MAX(_G(cDest), _G(cSrc));
	outB	= _MAX(_B(cDest), _B(cSrc));

	outR	= _NOMORE(outR, 0xFF);
	outG	= _NOMORE(outG, 0xFF);
	outB	= _NOMORE(outB, 0xFF);

	return _RGB(outR, outG, outB);
}

DWORD	_stdcall FI_BitBlt_Call_Dark(DWORD cDest, DWORD cSrc) {
	DWORD	outR, outG, outB;

	outR	= _MIN(_R(cDest), _R(cSrc));
	outG	= _MIN(_G(cDest), _G(cSrc));
	outB	= _MIN(_B(cDest), _B(cSrc));

	outR	= _NOLESS0B(outR);
	outG	= _NOLESS0B(outG);
	outB	= _NOLESS0B(outB);

	return _RGB(outR, outG, outB);
}

DWORD	_stdcall FI_BitBlt_Call_Merge(DWORD cDest, DWORD cSrc, DWORD key) {
	BYTE control = (BYTE)(key >> 24);
	BOOL object = control & 0x1;
	BOOL fuzzyMerge = control & 0x10;

	key	&= 0xFFFFFF;
	switch (object) {
	case FI_DESTKEY:
//		if (fuzzyMerge) {
//			if fuzzyEqual(cDest, cSrc, alpha1)
		return cDest == key ? cSrc : cDest;
	case FI_SRCKEY:
		return cSrc == key ? cDest : cSrc;
	}
	return cSrc;
}

DWORD	_stdcall FI_BitBlt_Call_Alpha(DWORD cDest, DWORD cSrc, DWORD alpha) {
	_DRGB(dest, DWORD, cDest);
	_DRGB(src,  DWORD, cSrc);
	DWORD	outR, outG, outB;
	DWORD	a	= alpha < 256 ? alphaTable[alpha] : alphaTable[256];
	DWORD	_a	= 256 - a;

	outR	= alphaColor[a][destR] + alphaColor[_a][srcR];
	outG	= alphaColor[a][destG] + alphaColor[_a][srcG];
	outB	= alphaColor[a][destB] + alphaColor[_a][srcB];

	outR	= _NOMORE(outR, 0xFF);
	outG	= _NOMORE(outG, 0xFF);
	outB	= _NOMORE(outB, 0xFF);

	return _RGB(outR, outG, outB);
}

DWORD	_stdcall FI_BitBlt_Call_Alpha_Merge(DWORD cDest, DWORD cSrc, DWORD alpha) {
	DWORD	r;
	if (alpha == 0) {
		r = FI_BitBlt_Call_Merge(cDest, cSrc, alpha1);
	} else {
		r = FI_BitBlt_Call_Alpha(
			cDest,
			FI_BitBlt_Call_Merge(cDest, cSrc, alpha1),
			alpha);
	}
	return r;
}
