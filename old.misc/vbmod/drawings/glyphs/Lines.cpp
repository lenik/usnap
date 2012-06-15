// Lines.cpp : Implementation of CLines
#include "stdafx.h"
#include "Glyphs.h"
#include "Lines.h"
#include "kernel.h"

/////////////////////////////////////////////////////////////////////////////
// CLines


STDMETHODIMP CLines::Arrow(long hDC, ArrowTypeConstants type, long x0, long y0, long x1, long y1)
{
    vector_t s = { x0, y0, 1 };
    vector_t e = { x1, y1, 1 };
	DrawArrow((HDC)hDC, (DWORD)type, s, e);
	return S_OK;
}
