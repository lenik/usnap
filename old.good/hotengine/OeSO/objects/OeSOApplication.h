
#pragma once

// 应用体类, 管理类和接口集合
// CLSID: 00000000-4F45-0660-0002-486954656368
class OeSOApplication :
	public CComObjectRoot,
	public CComCoClass<OeSOApplication, &CLSID_OeSOApplication>,
	public IDispatchImpl<IOeSOApplication, &IID_IOeSOApplication> {
public:
	OeSOApplication();
	virtual ~OeSOApplication();

public:
	STDMETHOD(get_name)(BSTR *ret);
	STDMETHOD(put_name)(BSTR newname);

	STDMETHOD(get_objects)(VARIANT whichclass, IOeSOObjectsCollection **ret);

	STDMETHOD(get_interfaces)(IOeSOInterfacesCollection **ret);

	STDMETHOD(get_classes)(IOeSOClassesCollection **ret);

	STDMETHOD(get_statuses)(IOeSOStatusesCollection **ret);

public:
	BEGIN_COM_MAP(OeSOApplication)
		COM_INTERFACE_ENTRY(IOeSOApplication)
		COM_INTERFACE_ENTRY2(IDispatch, IOeSOApplication)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeSOApplication)
	DECLARE_NOT_AGGREGATABLE(OeSOApplication)

public:
	_bstr_t				m_name;
	COeSOObjectsCollection *	m_objects;
	COeSOInterfacesCollection *	m_interfaces;
	COeSOClassesCollection *	m_classes;
	COeSOStatusesCollection * 	m_statuses;
};

typedef CComObject<OeSOApplication>	COeSOApplication;
