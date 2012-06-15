// Shapes.cpp : Implementation of CShapes
#include "stdafx.h"
#include "Glyphs.h"
#include "Shapes.h"
#include "Lines.h"

/////////////////////////////////////////////////////////////////////////////
// CShapes


CShapes::CShapes() {
    m_pLines = new CLinesObject();
    m_pLines->AddRef();
}

CShapes::~CShapes() {
    m_pLines->Release();
}

STDMETHODIMP CShapes::get_Lines(ILines **pVal)
{
	if (pVal == NULL)
        return E_POINTER;
    m_pLines->QueryInterface(IID_ILines, (void **)pVal);
	return S_OK;
}
