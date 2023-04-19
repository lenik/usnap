
#include "StdAfx.h"

#include "resource.h"

#include "OeSO.h"
#include "OeSODeclares.h"

// 求值器求解SOML中的属性值、执行SOML中的方法等。
// CLSID: 00000000-4F45-0602-0002-486954656368

OeSOEvaluator::OeSOEvaluator() {}

OeSOEvaluator::~OeSOEvaluator() {}


STDMETHODIMP
OeSOEvaluator::get_parser(IOeSOParser **ret) {
	return NOERROR;
}

STDMETHODIMP
OeSOEvaluator::put_parser(IOeSOParser *parser) {
	return NOERROR;
}

STDMETHODIMP
OeSOEvaluator::evaluator(BSTR script, VARIANT *ret) {
	return NOERROR;
}
