
#pragma once

// ��������һ������Ķ���
// CLSID: 00000000-4F45-0610-0002-486954656368
class OeSOObject :
	public CComObjectRoot,
	public CComCoClass<OeSOObject, &CLSID_OeSOObject>,
	public IDispatchImpl<IOeSOObject, &IID_IOeSOObject> {
public:
	OeSOObject();
	virtual ~OeSOObject();

public:
	STDMETHOD(get_name)(BSTR *ret);
	STDMETHOD(put_name)(BSTR newname);

	STDMETHOD(get_attributes)(IOeSOAttributesCollection **ret);

	STDMETHOD(get_attributesObject)(IOeSOAttributesCollection **ret);
	STDMETHOD(put_attributesObject)(IOeSOAttributesCollection *newattributes);

	STDMETHOD(get_methods_)(IOeSOMethodsCollection **ret);
	STDMETHOD(put_methods_)(IOeSOMethodsCollection *newmethods);

	STDMETHOD(get_events_)(IOeSOEventsCollection **ret);
	STDMETHOD(put_events_)(IOeSOEventsCollection *newevents);

	STDMETHOD(get_ofclass)(IOeSOClass **ret);
	STDMETHOD(put_ofclass)(IOeSOClass *newclass);

public:
	BEGIN_COM_MAP(OeSOObject)
		COM_INTERFACE_ENTRY(IOeSOObject)
		COM_INTERFACE_ENTRY2(IDispatch, IOeSOObject)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeSOObject)
	DECLARE_NOT_AGGREGATABLE(OeSOObject)

public:
	BOOL				m_inited;
	// ��������
	_bstr_t				m_name;
	// ��������
	IOeSOClass *			m_pOfclass;
	// �������Լ�(�����������Լ�)
	COeSOAttributesCollection *	m_attributes;
	// ������ (���ӵ��෽����)
	COeSOMethodsCollection *	m_methods;
	// �¼��� (���ӵ����¼���)
	COeSOEventsCollection *		m_events;

	//COeSOClass			m;
};
