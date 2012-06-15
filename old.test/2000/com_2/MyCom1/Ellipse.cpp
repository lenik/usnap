// MyCom1.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#include "Ellipse.h"

CEllipse::CEllipse() {
	m_x0 = m_y0 = 0;
	m_x1 = m_y1 = 100;
	m_color = RGB(128, 128, 128);
}

STDMETHODIMP CEllipse::QueryInterface(REFIID riid, LPVOID *ppv) {
	return NOERROR;
}

STDMETHODIMP_(ULONG) CEllipse::AddRef() {
	m_cRef++;
	return m_cRef;
}

STDMETHODIMP_(ULONG) CEllipse::Release() {
	m_cRef--;
	if (m_cRef > 0) return m_cRef;
	delete this;
	return 0;
}

STDMETHODIMP CEllipse::draw(HDC hDC) {
	HPEN newPen, oldPen;
	newPen	= CreatePen(PS_SOLID, 1, m_color);
	if (newPen != NULL) {
		oldPen	= (HPEN)SelectObject(hDC, newPen);

		Ellipse(hDC, m_x0, m_y0, m_x1, m_y1);
		SelectObject(hDC, oldPen);
		DeleteObject(newPen);

		return S_OK;
	}
	return E_FAIL;
}

STDMETHODIMP CEllipse::setPos(int x0, int y0, int x1, int y1) {
	m_x0	= x0;
	m_y0	= y0;
	m_x1	= x1;
	m_y1	= y1;
	return S_OK;
}

STDMETHODIMP CEllipse::setColor(DWORD color) {
	this->m_color	= color;
	return S_OK;
}
