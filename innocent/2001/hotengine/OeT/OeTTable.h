
#pragma once

class OeTTable :
	public CComObjectRoot,
	public CComCoClass<OeTTable, &CLSID_OeTTable>,
	public IDispatchImpl<IOeTTable, &IID_IOeTTable> {
public:
	OeTTable();
	virtual ~OeTTable();

public:
	STDMETHOD(get_cell)(VARIANT col, VARIANT row, VARIANT *ret);
	STDMETHOD(put_cell)(VARIANT col, VARIANT row, VARIANT newcell);

	STDMETHOD(get_colname)(VARIANT col, BSTR *ret);
	STDMETHOD(put_colname)(VARIANT col, BSTR newcolname);

	STDMETHOD(get_rowname)(VARIANT row, BSTR *ret);
	STDMETHOD(put_rowname)(VARIANT row, BSTR newrowname);

	STDMETHOD(get_cols)(int *ret);
	STDMETHOD(put_cols)(int newcols);

	STDMETHOD(get_rows)(int *ret);
	STDMETHOD(put_rows)(int newrows);

	STDMETHOD(search)(BSTR exp, IOeTTable **ret);
	STDMETHOD(sort)(BSTR exp);
	STDMETHOD(combine)(IOeTTable *another);

public:
	BEGIN_COM_MAP(OeTTable)
		COM_INTERFACE_ENTRY2(IDispatch, IOeTTable)
		COM_INTERFACE_ENTRY(IOeTTable)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeT0)
	DECLARE_NOT_AGGREGATABLE(OeTTable)

protected:
	_bstr_vector_t		m_colnames;
	_bstr_vector_t		m_rownames;
	_variant_table_t	m_members;
};
