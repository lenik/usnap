
#pragma once

// ��������������һ��������������������ͨ����д�򵥴��롢���ýű������ӳ�䵽�������ϡ�
// CLSID: 00000000-4F45-0621-0002-486954656368
class OeSOMethod :
	public CComObjectRoot,
	public CComCoClass<OeSOMethod, &CLSID_OeSOMethod>,
	public IDispatchImpl<IOeSOMethod, &IID_IOeSOMethod> {
public:
	OeSOMethod();
	virtual ~OeSOMethod();

public:
	STDMETHOD(get_name)(BSTR *ret);
	STDMETHOD(put_name)(BSTR newname);

public:
	BEGIN_COM_MAP(OeSOMethod)
		COM_INTERFACE_ENTRY(IOeSOMethod)
		COM_INTERFACE_ENTRY2(IDispatch, IOeSOMethod)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeSOMethod)
	DECLARE_NOT_AGGREGATABLE(OeSOMethod)

public:
	_bstr_t		m_name;
	//ITypeInfo
};

typedef CComObject<OeSOMethod>	COeSOMethod;
