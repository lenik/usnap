
#pragma once

// ��������һ���ࡣһ�������ʵ�ֶ���ӿڣ���ֻ�ܼ̳�һ���ࡣ���Ҽ̳����뱾�಻�����ص��ӿڡ����������ʵ�����Ķ���
// CLSID: 00000000-4F45-0612-0002-486954656368
class OeSOClass :
	public CComObjectRoot,
	public CComCoClass<OeSOClass, &CLSID_OeSOClass>,
	public IDispatchImpl<IOeSOClass, &IID_IOeSOClass> {
public:
	OeSOClass();
	virtual ~OeSOClass();

public:
	STDMETHOD(get_name)(BSTR *ret);
	STDMETHOD(put_name)(BSTR newname);

	STDMETHOD(get_attributes)(IOeSOAttributesCollection **ret);
	STDMETHOD(get_attributesObject)(IOeSOAttributesCollection **ret);
	STDMETHOD(get_methods_)(IOeSOMethodsCollection **ret);
	STDMETHOD(get_events_)(IOeSOEventsCollection **ret);

	STDMETHOD(get_inherits)(IOeSOClass **ret);
	STDMETHOD(put_inherits)(IOeSOClass *newinherits);
	STDMETHOD(get_derives)(IOeSOClassesCollection **ret);
	STDMETHOD(get_interfaces)(IOeSOInterfacesCollection **ret);

	STDMETHOD(get_instances)(IOeSOObjectsCollection **ret);

	STDMETHOD(createObject)(BSTR objectname, IOeSOObject **ret);

	// obsolute
	STDMETHOD(put_attributes)(IOeSOAttributesCollection *newattributes);
	STDMETHOD(put_attributesObject)(IOeSOAttributesCollection *newattributes);
	STDMETHOD(put_methods_)(IOeSOMethodsCollection *newmethods);
	STDMETHOD(put_events_)(IOeSOEventsCollection *newevents);
	STDMETHOD(put_interfaces)(IOeSOInterfacesCollection *newinterfaces);

public:
	BEGIN_COM_MAP(OeSOClass)
		COM_INTERFACE_ENTRY(IOeSOClass)
		COM_INTERFACE_ENTRY2(IDispatch, IOeSOClass)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeSOClass)
	DECLARE_NOT_AGGREGATABLE(OeSOClass)

public:
	// ��������
	_bstr_t				m_name;
	// �̳���
	IOeSOClass *			m_pInherits;
	// �����༯
	COeSOClassesCollection *	m_derives;
	// ʵ�ֽӿ�
	COeSOInterfacesCollection *	m_interfaces;
	// �����Լ�
	COeSOAttributesCollection *	m_attributes;
	// ��������ģ�漯
	COeSOAttributesCollection *	m_objectAttributes;
	// ������ (���ӵ��෽����)
	COeSOMethodsCollection *	m_methods;
	// �¼��� (���ӵ����¼���)
	COeSOEventsCollection *		m_events;
	// ʵ����
	COeSOObjectsCollection *	m_instances;
};
