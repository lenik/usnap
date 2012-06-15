
#pragma once

// ״̬������һ��״̬��һ��״̬�ж��״ֵ̬��״ֵ̬����Ӧ��һ��״̬��ʾ�ࡣ
// CLSID: 00000000-4F45-0613-0002-486954656368
class OeSOStatus :
	public CComObjectRoot,
	public CComCoClass<OeSOStatus, &CLSID_OeSOStatus>,
	public IDispatchImpl<IOeSOStatus, &IID_IOeSOStatus> {
public:
	OeSOStatus();
	virtual ~OeSOStatus();

public:
	STDMETHOD(get_name)(BSTR *ret);
	STDMETHOD(put_name)(BSTR newname);

public:
	BEGIN_COM_MAP(OeSOStatus)
		COM_INTERFACE_ENTRY(IOeSOStatus)
		COM_INTERFACE_ENTRY2(IDispatch, IOeSOStatus)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeSOStatus)
	DECLARE_NOT_AGGREGATABLE(OeSOStatus)

public:
	_bstr_t			m_name;
};

typedef CComObject<OeSOStatus>	COeSOStatus;
