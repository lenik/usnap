
#pragma once

#include "IBoxGraph.h"

class CEllipse : public IBoxGraph {
public:
	CEllipse();

	STDMETHOD(QueryInterface)(REFIID, LPVOID *);
	STDMETHOD_(ULONG, AddRef)();
	STDMETHOD_(ULONG, Release)();

	STDMETHOD(draw)(HDC);
	STDMETHOD(setPos)(int, int, int, int);
	STDMETHOD(setColor)(DWORD);

protected:
	int	m_x0, m_y0, m_x1, m_y1;
	DWORD	m_color;
private:
	ULONG	m_cRef;
};

typedef CEllipse	*PEllipse, *LPEllipse;
