
#include "StdAfx.h"
#include "resource.h"
#include "OeT_types.h"


OeTSet::OeTSet() {
	this->m_elements	= new COeTArray;
	this->m_universals	= new COeTArray;
}

OeTSet::~OeTSet() {}


STDMETHODIMP
OeTSet::get_elements(IOeTArray **ret) {
	*ret	= (IOeTArray *)this->m_elements;
	return S_OK;
}

STDMETHODIMP
OeTSet::put_elements(IOeTArray *newelements) {
	if (this->m_elements != NULL) {
		delete this->m_elements;
	}
	this->m_elements	= (COeTArray *)newelements;
	return S_OK;
}

STDMETHODIMP
OeTSet::get_unis(IOeTArray **ret) {
	*ret	= (IOeTArray *)this->m_elements;
	return S_OK;
}

STDMETHODIMP
OeTSet::put_unis(IOeTArray *newunis) {
	return S_OK;
}

STDMETHODIMP
OeTSet::get_contain(VARIANT element, VARIANT_BOOL *ret) {
	return S_OK;
}

STDMETHODIMP
OeTSet::get_contains(IOeTSet *another, VARIANT_BOOL *ret) {
	return S_OK;
}

STDMETHODIMP
OeTSet::comps(IOeTSet **ret) {
	return S_OK;
}

STDMETHODIMP
OeTSet::add(VARIANT element, VARIANT_BOOL *ret) {
	return S_OK;
}

STDMETHODIMP
OeTSet::remove(VARIANT element, VARIANT_BOOL *ret) {
	return S_OK;
}

STDMETHODIMP
OeTSet::ints(IOeTSet *another, IOeTSet **ret) {
	return S_OK;
}

STDMETHODIMP
OeTSet::unions(IOeTSet *another, IOeTSet **ret) {
	return S_OK;
}

STDMETHODIMP
OeTSet::xors(IOeTSet *another, IOeTSet **ret) {
	return S_OK;
}

STDMETHODIMP
OeTSet::subs(IOeTSet *another, IOeTSet **ret) {
	return S_OK;
}
