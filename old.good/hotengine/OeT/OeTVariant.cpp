
#include "StdAfx.h"
#include "resource.h"
#include "OeT_types.h"


OeTVariant::OeTVariant() {
	this->m_bAutoTypeConversion	= TRUE;
}

OeTVariant::~OeTVariant() {}

STDMETHODIMP
OeTVariant::get_variant(VARIANT *ret) {
	*ret	= *(new _variant_t(this->m_variant));
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_variant(VARIANT var) {
	this->m_variant	= var;
	return NOERROR;
}


STDMETHODIMP
OeTVariant::get_autoTypeConversion(VARIANT_BOOL *ret) {
	*ret	= this->m_bAutoTypeConversion;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_autoTypeConversion(VARIANT_BOOL bEnabled) {
	this->m_bAutoTypeConversion	= bEnabled;
	return NOERROR;
}


STDMETHODIMP
OeTVariant::get_varType(VARENUM *ret) {
	*ret	= (VARENUM)this->m_variant.vt;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_varType(VARENUM vt) {
	if (this->m_bAutoTypeConversion) {
		this->m_variant.ChangeType((VARTYPE)vt);
	} else {
		this->m_variant.vt	= (VARTYPE)vt;
	}
	return NOERROR;
}


STDMETHODIMP
OeTVariant::get_byteVal(BYTE *ret) {
	*ret	= (BYTE)this->m_variant.bVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_byteVal(BYTE newbyte) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant	= newbyte;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.bVal	= newbyte;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_shortVal(SHORT *ret) {
	*ret	= (SHORT)this->m_variant.iVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_shortVal(SHORT newshort) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant	= newshort;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.iVal	= newshort;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_longVal(LONG *ret) {
	*ret	= (LONG)this->m_variant.lVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_longVal(LONG newlong) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant	= newlong;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.lVal	= newlong;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_floatVal(float *ret) {
	*ret	= (float)this->m_variant.fltVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_floatVal(float newfloat) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant	= newfloat;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.fltVal	= newfloat;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_doubleVal(double *ret) {
	*ret	= (double)this->m_variant.dblVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_doubleVal(double newdouble) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant	= newdouble;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.dblVal	= newdouble;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_boolVal(VARIANT_BOOL *ret) {
	*ret	= (VARIANT_BOOL)this->m_variant.boolVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_boolVal(VARIANT_BOOL newbool) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant	= newbool;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.boolVal	= newbool;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_scodeVal(SCODE *ret) {
	*ret	= (SCODE)this->m_variant.scode;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_scodeVal(SCODE newscode) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant	= newscode;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.scode	= newscode;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_dateVal(DATE *ret) {
	*ret	= (DATE)this->m_variant.date;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_dateVal(DATE newdate) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant	= newdate;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.date	= newdate;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_bstrVal(BSTR *ret) {
	*ret	= (new _bstr_t(this->m_variant.bstrVal))->copy();
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_bstrVal(BSTR newbstr) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant	= newbstr;
		this->m_variant.ChangeType(oldtype);
	} else {
		// >> make a copy
		this->m_variant.bstrVal	= (new _bstr_t(newbstr))->copy();
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_pdecimalVal(VARIANT *ret) {
	*ret	= *(new _variant_t(this->m_variant));
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_pdecimalVal(VARIANT newdecimal) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant	= newdecimal;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.pdecVal	= newdecimal.pdecVal;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_punknownVal(IUnknown **ret) {
	*ret	= (IUnknown *)this->m_variant.punkVal;
	if (!(this->m_variant.vt & VT_BYREF)) {
		(*ret)->AddRef();
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_punknownVal(IUnknown *newunknown) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant	= newunknown;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.punkVal	= newunknown;
		if (!(this->m_variant.vt & VT_BYREF)) {
			this->m_variant.punkVal->AddRef();
		}
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_pdispatchVal(IDispatch **ret) {
	*ret	= (IDispatch *)this->m_variant.pdispVal;
	if (!(this->m_variant.vt & VT_BYREF)) {
		(*ret)->AddRef();
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_pdispatchVal(IDispatch *newdispatch) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant	= newdispatch;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.pdispVal	= newdispatch;
		if (!(this->m_variant.vt & VT_BYREF)) {
			this->m_variant.pdispVal->AddRef();
		}
	}
	return NOERROR;
}


STDMETHODIMP
OeTVariant::get_pbyteVal(BYTE **ret) {
	*ret	= (BYTE *)this->m_variant.pbVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_pbyteVal(BYTE *newpbyte) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant.vt	= VT_UI1 | VT_BYREF;
		this->m_variant.pbVal	= newpbyte;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.pbVal	= newpbyte;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_pshortVal(short **ret) {
	*ret	= (short *)this->m_variant.piVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_pshortVal(short *newpshort) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant.vt	= VT_I2 | VT_BYREF;
		this->m_variant.piVal	= newpshort;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.piVal	= newpshort;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_plongVal(long **ret) {
	*ret	= (long *)this->m_variant.plVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_plongVal(long *newplong) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant.vt	= VT_I4 | VT_BYREF;
		this->m_variant.plVal	= newplong;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.plVal	= newplong;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_pfloatVal(float **ret) {
	*ret	= (float *)this->m_variant.pfltVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_pfloatVal(float *newpfloat) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant.vt	= VT_R4 | VT_BYREF;
		this->m_variant.pfltVal	= newpfloat;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.pfltVal	= newpfloat;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_pdoubleVal(double **ret) {
	*ret	= (double *)this->m_variant.pdblVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_pdoubleVal(double *newpdouble) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant.vt	= VT_R8 | VT_BYREF;
		this->m_variant.pdblVal	= newpdouble;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.pdblVal	= newpdouble;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_pboolVal(VARIANT_BOOL **ret) {
	*ret	= (VARIANT_BOOL *)this->m_variant.pboolVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_pboolVal(VARIANT_BOOL *newpbool) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant.vt		= VT_BOOL | VT_BYREF;
		this->m_variant.pboolVal	= newpbool;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.pboolVal	= newpbool;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_pscodeVal(SCODE **ret) {
	*ret	= (SCODE *)this->m_variant.pscode;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_pscodeVal(SCODE *newpscode) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant.vt	= VT_ERROR | VT_BYREF;
		this->m_variant.pscode	= newpscode;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.pscode	= newpscode;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_pdateVal(DATE **ret) {
	*ret	= (DATE *)this->m_variant.pdate;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_pdateVal(DATE *newpdate) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant.vt	= VT_DATE | VT_BYREF;
		this->m_variant.pdate	= newpdate;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.pdate	= newpdate;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_pbstrVal(BSTR **ret) {
	*ret	= (BSTR *)this->m_variant.pbstrVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_pbstrVal(BSTR *newpbstr) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant.vt		= VT_BSTR | VT_BYREF;
		this->m_variant.pbstrVal	= newpbstr;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.pbstrVal	= newpbstr;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_ppunknownVal(IUnknown ***ret) {
	(*ret)	= (IUnknown **)this->m_variant.ppunkVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_ppunknownVal(IUnknown **newppunknown) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant.vt		= VT_UNKNOWN | VT_BYREF;
		this->m_variant.ppunkVal	= newppunknown;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.ppunkVal	= newppunknown;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_ppdispatchVal(IDispatch ***ret) {
	*ret	= (IDispatch **)this->m_variant.ppdispVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_ppdispatchVal(IDispatch **newppdispatch) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant.vt		= VT_DISPATCH | VT_BYREF;
		this->m_variant.ppdispVal	= newppdispatch;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.ppdispVal	= newppdispatch;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_pvariantVal(VARIANT **ret) {
	*ret	= (VARIANT *)this->m_variant.pvarVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_pvariantVal(VARIANT *newpvariant) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant.vt		= VT_VARIANT | VT_BYREF;
		this->m_variant.pvarVal		= newpvariant;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.pvarVal		= newpvariant;
	}
	return NOERROR;
}


STDMETHODIMP
OeTVariant::get_byrefVal(LONG *ret) {
	// >> generic ByRef
	(*ret)	= (LONG)this->m_variant.byref;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_byrefVal(LONG newbyref_addr) {
	// >> generic ByRef
	this->m_variant.byref	= (LPVOID)newbyref_addr;
	return NOERROR;
}


STDMETHODIMP
OeTVariant::get_charVal(BYTE *ret) {
	*ret	= this->m_variant.cVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_charVal(BYTE newchar) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant.vt		= VT_I1;
		this->m_variant.cVal		= newchar;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.cVal		= newchar;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_ushortVal(short *ret) {
	(*ret)	= (short)this->m_variant.uiVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_ushortVal(short newushort) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant.vt		= VT_UI2;
		this->m_variant.uiVal		= (unsigned short)newushort;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.uiVal		= (unsigned short)newushort;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_ulongVal(long *ret) {
	(*ret)	= (long)this->m_variant.ulVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_ulongVal(long newulong) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant.vt		= VT_UI4;
		this->m_variant.ulVal		= (unsigned long)newulong;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.ulVal		= (unsigned long)newulong;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_intVal(int *ret) {
	*ret	= (int)this->m_variant.intVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_intVal(int newint) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant.vt		= VT_INT;
		this->m_variant.intVal		= (int)newint;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.intVal		= (int)newint;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_uintVal(int *ret) {
	*ret	= (int)this->m_variant.uintVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_uintVal(int newuint) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant.vt		= VT_UINT;
		this->m_variant.uintVal		= (unsigned int)newuint;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.uintVal		= (unsigned int)newuint;
	}
	return NOERROR;
}


STDMETHODIMP
OeTVariant::get_pcharVal(BYTE **ret) {
	(*ret)	= (BYTE *)this->m_variant.pcVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_pcharVal(BYTE *newpchar) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant.vt		= VT_I1 | VT_BYREF;
		this->m_variant.pcVal		= (char *)newpchar;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.pcVal		= (char *)newpchar;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_pushortVal(short **ret) {
	(*ret)	= (short *)this->m_variant.puiVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_pushortVal(short *newpushort) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant.vt		= VT_UI2 | VT_BYREF;
		this->m_variant.puiVal		= (unsigned short *)newpushort;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.puiVal		= (unsigned short *)newpushort;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_pulongVal(long **ret) {
	(*ret)	= (long *)this->m_variant.pulVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_pulongVal(long *newpulong) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant.vt		= VT_UI4 | VT_BYREF;
		this->m_variant.pulVal		= (unsigned long *)newpulong;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.pulVal		= (unsigned long *)newpulong;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_pintVal(int **ret) {
	(*ret)	= (int *)this->m_variant.pintVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_pintVal(int *newpint) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant.vt		= VT_INT | VT_BYREF;
		this->m_variant.pintVal		= (int *)newpint;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.pintVal		= (int *)newpint;
	}
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_puintVal(int **ret) {
	(*ret)	= (int *)this->m_variant.puintVal;
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_puintVal(int *newpuint) {
	if (this->m_bAutoTypeConversion) {
		VARTYPE oldtype = this->m_variant.vt;
		this->m_variant.vt		= VT_UI2 | VT_BYREF;
		this->m_variant.puintVal	= (unsigned int *)newpuint;
		this->m_variant.ChangeType(oldtype);
	} else {
		this->m_variant.puintVal	= (unsigned int *)newpuint;
	}
	return NOERROR;
}


STDMETHODIMP
OeTVariant::get_parrayVal(SAFEARRAY *ret) {
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_parrayVal(SAFEARRAY newarray) {
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_pparrayVal(SAFEARRAY **ret) {
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_pparrayVal(SAFEARRAY *newpparray) {
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_cyVal(CY *ret) {
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_cyVal(CY newcy) {
	return NOERROR;
}

STDMETHODIMP
OeTVariant::get_pcyVal(CY **ret) {
	return NOERROR;
}

STDMETHODIMP
OeTVariant::put_pcyVal(CY *newpcy) {
	return NOERROR;
}
