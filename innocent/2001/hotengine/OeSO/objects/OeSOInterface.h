
#pragma once

// �ӿ�������һ���ӿڡ��ӿڵ�ʵ���������С�
// CLSID: 00000000-4F45-0611-0002-486954656368
class OeSOInterface :
	public CComObjectRoot,
	public CComCoClass<OeSOInterface, &CLSID_OeSOInterface>,
	public IDispatchImpl<IOeSOInterface, &IID_IOeSOInterface> {
public:
	OeSOInterface();
	virtual ~OeSOInterface();

public:
	STDMETHOD(get_name)(BSTR *ret);
	STDMETHOD(put_name)(BSTR newname);

	STDMETHOD(get_methods_)(IOeSOMethodsCollection **ret);

	STDMETHOD(get_events_)(IOeSOEventsCollection **ret);

	STDMETHOD(get_inherits)(IOeSOInterface **ret);
	STDMETHOD(put_inherits)(IOeSOInterface *newinherits);

	STDMETHOD(get_interfaces)(IOeSOInterfacesCollection **ret);

	STDMETHOD(get_derives)(IOeSOInterfacesCollection **ret);

	// obsolute
	STDMETHOD(put_methods_)(IOeSOMethodsCollection *newmethods);
	STDMETHOD(put_events_)(IOeSOEventsCollection *newevents);
	STDMETHOD(put_interfaces)(IOeSOInterfacesCollection *newinterfaces);

public:
	BEGIN_COM_MAP(OeSOInterface)
		COM_INTERFACE_ENTRY(IOeSOInterface)
		COM_INTERFACE_ENTRY2(IDispatch, IOeSOInterface)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeSOInterface)
	DECLARE_NOT_AGGREGATABLE(OeSOInterface)

public:
	_bstr_t				m_name;
	// ��ʽ�̳нӿ�
	IOeSOInterface *		m_pInherits;
	// ����̳нӿڼ�
	COeSOInterfacesCollection *	m_interfaces;
	// �����ӿڼ�
	COeSOInterfacesCollection *	m_derives;
	// �ӿڷ�����
	COeSOMethodsCollection *	m_methods;
	// �ӿ��¼���
	COeSOEventsCollection *		m_events;
};
