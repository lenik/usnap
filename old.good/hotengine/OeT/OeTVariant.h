
#pragma once

class OeTVariant :
	public CComObjectRoot,
	public CComCoClass<OeTVariant, &CLSID_OeTVariant>,
	public IDispatchImpl<IOeTVariant, &IID_IOeTVariant> {
public:
	OeTVariant();
	virtual ~OeTVariant();

public:
	STDMETHOD(get_variant)(VARIANT *ret);
	STDMETHOD(put_variant)(VARIANT var);

	STDMETHOD(get_autoTypeConversion)(VARIANT_BOOL *ret);
	STDMETHOD(put_autoTypeConversion)(VARIANT_BOOL bEnabled);

	STDMETHOD(get_varType)(VARENUM *ret);
	STDMETHOD(put_varType)(VARENUM vt);

	STDMETHOD(get_byteVal)(BYTE *ret);
	STDMETHOD(put_byteVal)(BYTE newbyte);
	STDMETHOD(get_shortVal)(SHORT *ret);
	STDMETHOD(put_shortVal)(SHORT newshort);
	STDMETHOD(get_longVal)(LONG *ret);
	STDMETHOD(put_longVal)(LONG newlong);
	STDMETHOD(get_floatVal)(float *ret);
	STDMETHOD(put_floatVal)(float newfloat);
	STDMETHOD(get_doubleVal)(double *ret);
	STDMETHOD(put_doubleVal)(double newdouble);
	STDMETHOD(get_boolVal)(VARIANT_BOOL *ret);
	STDMETHOD(put_boolVal)(VARIANT_BOOL newbool);
	STDMETHOD(get_scodeVal)(SCODE *ret);
	STDMETHOD(put_scodeVal)(SCODE newscode);
	STDMETHOD(get_dateVal)(DATE *ret);
	STDMETHOD(put_dateVal)(DATE newdate);
	STDMETHOD(get_bstrVal)(BSTR *ret);
	STDMETHOD(put_bstrVal)(BSTR newbstr);
	STDMETHOD(get_pdecimalVal)(VARIANT *ret);
	STDMETHOD(put_pdecimalVal)(VARIANT newdecimal);
	STDMETHOD(get_punknownVal)(IUnknown **ret);
	STDMETHOD(put_punknownVal)(IUnknown *newunknown);
	STDMETHOD(get_pdispatchVal)(IDispatch **ret);
	STDMETHOD(put_pdispatchVal)(IDispatch *newdispatch);

	STDMETHOD(get_pbyteVal)(BYTE **ret);
	STDMETHOD(put_pbyteVal)(BYTE *newpbyte);
	STDMETHOD(get_pshortVal)(short **ret);
	STDMETHOD(put_pshortVal)(short *newpshort);
	STDMETHOD(get_plongVal)(long **ret);
	STDMETHOD(put_plongVal)(long *newplong);
	STDMETHOD(get_pfloatVal)(float **ret);
	STDMETHOD(put_pfloatVal)(float *newpfloat);
	STDMETHOD(get_pdoubleVal)(double **ret);
	STDMETHOD(put_pdoubleVal)(double *newpdouble);
	STDMETHOD(get_pboolVal)(VARIANT_BOOL **ret);
	STDMETHOD(put_pboolVal)(VARIANT_BOOL *newpbool);
	STDMETHOD(get_pscodeVal)(SCODE **ret);
	STDMETHOD(put_pscodeVal)(SCODE *newpscode);
	STDMETHOD(get_pdateVal)(DATE **ret);
	STDMETHOD(put_pdateVal)(DATE *newpdate);
	STDMETHOD(get_pbstrVal)(BSTR **ret);
	STDMETHOD(put_pbstrVal)(BSTR *newpbstr);
	STDMETHOD(get_ppunknownVal)(IUnknown ***ret);
	STDMETHOD(put_ppunknownVal)(IUnknown **newppunknown);
	STDMETHOD(get_ppdispatchVal)(IDispatch ***ret);
	STDMETHOD(put_ppdispatchVal)(IDispatch **newppdispatch);
	STDMETHOD(get_pvariantVal)(VARIANT **ret);
	STDMETHOD(put_pvariantVal)(VARIANT *newpvariant);

	STDMETHOD(get_byrefVal)(LONG *ret);
	STDMETHOD(put_byrefVal)(LONG newbyref_addr);

	STDMETHOD(get_charVal)(BYTE *ret);
	STDMETHOD(put_charVal)(BYTE newchar);
	STDMETHOD(get_ushortVal)(short *ret);
	STDMETHOD(put_ushortVal)(short newushort);
	STDMETHOD(get_ulongVal)(long *ret);
	STDMETHOD(put_ulongVal)(long newulong);
	STDMETHOD(get_intVal)(int *ret);
	STDMETHOD(put_intVal)(int newint);
	STDMETHOD(get_uintVal)(int *ret);
	STDMETHOD(put_uintVal)(int newuint);

	STDMETHOD(get_pcharVal)(BYTE **ret);
	STDMETHOD(put_pcharVal)(BYTE *newpchar);
	STDMETHOD(get_pushortVal)(short **ret);
	STDMETHOD(put_pushortVal)(short *newpushort);
	STDMETHOD(get_pulongVal)(long **ret);
	STDMETHOD(put_pulongVal)(long *newpulong);
	STDMETHOD(get_pintVal)(int **ret);
	STDMETHOD(put_pintVal)(int *newpint);
	STDMETHOD(get_puintVal)(int **ret);
	STDMETHOD(put_puintVal)(int *newpuint);

	STDMETHOD(get_parrayVal)(SAFEARRAY *ret);
	STDMETHOD(put_parrayVal)(SAFEARRAY newarray);
	STDMETHOD(get_pparrayVal)(SAFEARRAY **ret);
	STDMETHOD(put_pparrayVal)(SAFEARRAY *newpparray);
	STDMETHOD(get_cyVal)(CY *ret);
	STDMETHOD(put_cyVal)(CY newcy);
	STDMETHOD(get_pcyVal)(CY **ret);
	STDMETHOD(put_pcyVal)(CY *newpcy);

	BEGIN_COM_MAP(OeTVariant)
		COM_INTERFACE_ENTRY2(IDispatch, IOeTVariant)
		COM_INTERFACE_ENTRY(IOeTVariant)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeT0)
	DECLARE_NOT_AGGREGATABLE(OeTVariant)

protected:
	_variant_t	m_variant;
	BOOL		m_bAutoTypeConversion;
};
