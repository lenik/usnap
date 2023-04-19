
#include "StdAfx.h"

#include "resource.h"

#include "OeSO.h"
#include "OeSODeclares.h"

// 方法类用于描述一个方法。描述方法可以通过编写简单代码、引用脚本类或者映射到其它类上。
// CLSID: 00000000-4F45-0621-0002-486954656368

OeSOMethod::OeSOMethod() {}

OeSOMethod::~OeSOMethod() {}


STDMETHODIMP
OeSOMethod::get_name(BSTR *ret) {
	*ret	= m_name.copy();
	return S_OK;
}

STDMETHODIMP
OeSOMethod::put_name(BSTR newname) {
	m_name	= newname;
	return S_OK;
}
