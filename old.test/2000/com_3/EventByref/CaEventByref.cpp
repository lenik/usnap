
#include "StdAfx.h"

#include "resource.h"

#include "EventByref.h"
#include "CaEventByref.h"

CaEventByref::CaEventByref() {}

CaEventByref::~CaEventByref() {}


STDMETHODIMP
CaEventByref::get_prop1(long *ret) {
	*ret	= this->m_prop1;
	return S_OK;
}

STDMETHODIMP
CaEventByref::put_prop1(long newval) {
	this->m_prop1	= newval;
	return S_OK;
}

STDMETHODIMP
CaEventByref::makeEventTest() {
	this->Fire_onEventTest();
	return S_OK;
}

STDMETHODIMP
CaEventByref::makeEvent1() {
	this->Fire_onEvent1();
	return S_OK;
}

STDMETHODIMP
CaEventByref::makeEvent2() {
	this->Fire_onEvent2();
	return S_OK;
}
