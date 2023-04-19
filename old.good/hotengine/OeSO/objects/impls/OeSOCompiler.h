
#include "StdAfx.h"

#include "resource.h"

#include "OeSO.h"
#include "objects/OeSOCompiler.h"

// 编译器将SOML编译成其它语言。
// CLSID: 00000000-4F45-0601-0002-486954656368

OeSOCompiler::OeSOCompiler() {}

OeSOCompiler::~OeSOCompiler() {}


STDMETHODIMP
OeSOCompiler::get_parser(IOeSOParser **ret) {
	return NOERROR;
}

STDMETHODIMP
OeSOCompiler::put_parser(IOeSOParser *parser) {
	return NOERROR;
}

STDMETHODIMP
OeSOCompiler::compileSOML(BSTR *ret) {
	return NOERROR;
}
