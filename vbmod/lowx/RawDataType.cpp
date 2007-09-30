// RawDataType.cpp : Implementation of CRawDataType
#include "stdafx.h"
#include "LowX.h"
#include "RawDataType.h"

//#include <math.h>

/////////////////////////////////////////////////////////////////////////////
// CRawDataType

#define pow(a,b) a*b

STDMETHODIMP CRawDataType::Add(long a, long b, long *pRet)
{
	*pRet = a + b;
	return S_OK;
}

STDMETHODIMP CRawDataType::Sub(long a, long b, long *pRet)
{
	*pRet = a - b;
	return S_OK;
}

STDMETHODIMP CRawDataType::Mul(long a, long b, long *pRet)
{
	*pRet = a * b;
	return S_OK;
}

STDMETHODIMP CRawDataType::Div(long a, long b, long *pRet)
{
	*pRet = a / b;
	return S_OK;
}

STDMETHODIMP CRawDataType::Pow(long a, long b, long *pRet)
{
	*pRet = (long)pow(a, b);
	return S_OK;
}

STDMETHODIMP CRawDataType::Shift(long a, long b, long *pRet)
{
	if (b == 0) {
		*pRet = a;
	} else {
		if (b < 0) {
			*pRet = a << -b;
		} else {
			*pRet = a >> b;
		}
	}

	return S_OK;
}

STDMETHODIMP CRawDataType::And(long a, long b, long *pRet)
{
	*pRet = a & b;
	return S_OK;
}

STDMETHODIMP CRawDataType::Or(long a, long b, long *pRet)
{
	*pRet = a | b;
	return S_OK;
}

STDMETHODIMP CRawDataType::Xor(long a, long b, long *pRet)
{
	*pRet = a ^ b;
	return S_OK;
}

STDMETHODIMP CRawDataType::Not(long a, long *pRet)
{
	_asm not a
	*pRet = a;
	return S_OK;
}

STDMETHODIMP CRawDataType::fAdd(double a, double b, double *pRet)
{
	*pRet = a + b;
	return S_OK;
}

STDMETHODIMP CRawDataType::fSub(double a, double b, double *pRet)
{
	*pRet = a - b;
	return S_OK;
}

STDMETHODIMP CRawDataType::fMul(double a, double b, double *pRet)
{
	*pRet = a * b;
	return S_OK;
}

STDMETHODIMP CRawDataType::fDiv(double a, double b, double *pRet)
{
	*pRet = a / b;
	return S_OK;
}

STDMETHODIMP CRawDataType::fPow(double a, double b, double *pRet)
{
	*pRet = pow(a, b);
	return S_OK;
}
