
#include "StdAfx.h"
#include "resource.h"
#include "OeT_types.h"

OeTString::OeTString() {}

OeTString::~OeTString() {}


STDMETHODIMP
OeTString::get_contents(BSTR *ret) {
	*ret	= m_contents.copy();
	return S_OK;
}

STDMETHODIMP
OeTString::put_contents(BSTR newcontents) {
	m_contents	= newcontents;
	return S_OK;
}


STDMETHODIMP
OeTString::get_c(int index, LONG *ret) {
	*ret	= (LONG)((LPWSTR)this->m_contents)[index];
	return S_OK;
}

STDMETHODIMP
OeTString::put_c(int index, LONG newc) {
	((LPWSTR)this->m_contents)[index]	= (WCHAR)newc;
	return S_OK;
}

STDMETHODIMP
OeTString::get_length(int *ret) {
	*ret	= (int)this->m_contents.length();
	return S_OK;
}
