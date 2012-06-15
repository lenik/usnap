
#include "StdAfx.h"
#include "resource.h"
#include "OeT_types.h"


OeTTable::OeTTable() {}

OeTTable::~OeTTable() {}


STDMETHODIMP
OeTTable::get_cell(VARIANT col, VARIANT row, VARIANT *ret) {
	return S_OK;
}

STDMETHODIMP
OeTTable::put_cell(VARIANT col, VARIANT row, VARIANT newcell) {
	return S_OK;
}

STDMETHODIMP
OeTTable::get_colname(VARIANT col, BSTR *ret) {
	return S_OK;
}

STDMETHODIMP
OeTTable::put_colname(VARIANT col, BSTR newcolname) {
	return S_OK;
}

STDMETHODIMP
OeTTable::get_rowname(VARIANT row, BSTR *ret) {
	return S_OK;
}

STDMETHODIMP
OeTTable::put_rowname(VARIANT row, BSTR newrowname) {
	return S_OK;
}

STDMETHODIMP
OeTTable::get_rows(int *ret) {
	return S_OK;
}

STDMETHODIMP
OeTTable::put_rows(int newrows) {
	return S_OK;
}

STDMETHODIMP
OeTTable::get_cols(int *ret) {
	return S_OK;
}

STDMETHODIMP
OeTTable::put_cols(int newcols) {
	return S_OK;
}

STDMETHODIMP
OeTTable::search(BSTR exp, IOeTTable **ret) {
	return S_OK;
}

STDMETHODIMP
OeTTable::sort(BSTR exp) {
	return S_OK;
}

STDMETHODIMP
OeTTable::combine(IOeTTable *another) {
	return S_OK;
}
