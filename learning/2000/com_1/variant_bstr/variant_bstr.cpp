// variant_bstr.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

typedef std::vector<_variant_t> _variant_vector_t;

int APIENTRY WinMain2(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	_bstr_t *		pstr;
	_variant_vector_t	vv;

	int	i;

	vv.resize(10);

	for (i = 0; i < 10; i++) {
		_variant_t v;
		v.vt	= VT_I4;
		v.lVal	= i;
		v.ChangeType(VT_BSTR);
		pstr	= new _bstr_t(v.bstrVal);
		vv[i] = *pstr;
	}

	_bstr_t b;
	for (i = 0; i < 10; i++) {
		_bstr_t b1;
		b1	= vv[i];
		b	+= b1;
		b	+= _T("\n");
	}

	MessageBox(NULL, b, b, 0);
	return 0;
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	_variant_t	*v1 = new _variant_t;
	_variant_t	*v2 = new _variant_t;
	_variant_t	*v3 = new _variant_t;
	_variant_t	*v4 = new _variant_t;
	_variant_t	*v5 = new _variant_t;

	_bstr_t		*b1 = new _bstr_t(_T("b1"));
	_bstr_t		*b2 = new _bstr_t(_T("b2"));
	_bstr_t		*b3 = new _bstr_t(_T("b3"));
	_bstr_t		*b4 = new _bstr_t(_T("b4"));
	_bstr_t		*b5 = new _bstr_t(_T("b5"));

	*v1	= *b1;	//
	*v2	= *v1;	// *ret = v[n];
			// a = obj.get()
	VARIANT vv =	(*v2).Detach();
	VARIANT vv2 =	(*v1).Detach();
	VARIANT vv3 =	(*v1).Detach();
	return 0;

}