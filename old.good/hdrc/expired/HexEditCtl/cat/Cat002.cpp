// Cat002.cpp : Implementation of CCat002

#include "stdafx.h"
#include "Cat.h"
#include "Cat002.h"

/////////////////////////////////////////////////////////////////////////////
// CCat002

LRESULT CCat002::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
    m_cmdShow = ::CreateWindow("BUTTON", "Show my name",
        WS_CHILD, 10, 10, 100, 30,
        this->m_hWnd, NULL, _Module.m_hInst, 0);
    ::ShowWindow(m_cmdShow, SW_NORMAL);
    return 0;
}


STDMETHODIMP CCat002::GetRawObject(long *pRawAddr)
{
	if (!pRawAddr) return E_POINTER;

    *pRawAddr = (long)this;
	return S_OK;
}
