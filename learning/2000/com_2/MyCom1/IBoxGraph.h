
#pragma once

#include "guid.h"

DECLARE_INTERFACE_(IBoxGraph, IUnknown) {
	STDMETHOD(draw)(HDC hDC) PURE;
	STDMETHOD(setPos)(int x0, int y0, int x1, int y1) PURE;
	STDMETHOD(setColor)(DWORD color) PURE;
};

typedef IBoxGraph	*PBoxGraph, *LPBoxGraph;
