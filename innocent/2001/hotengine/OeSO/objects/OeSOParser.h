
#pragma once

// ���������ڷ���SOML�ĵ��������ݿ��е���SOML������SOML��, ������Ӧ�������
// CLSID: 00000000-4F45-0600-0002-486954656368
class OeSOParser :
	public CComObjectRoot,
	public CComCoClass<OeSOParser, &CLSID_OeSOParser>,
	public IDispatchImpl<IOeSOParser, &IID_IOeSOParser>,
	public IDispatchImpl<IOeSOParserEvents, &DIID_IOeSOParserEvents>,
	public IConnectionPointContainerImpl<OeSOParser>,
	public IConnectionPointImpl<OeSOParser, &DIID_IOeSOParserEvents> {
public:
	OeSOParser();
	virtual ~OeSOParser();

public:
	STDMETHOD(load)(VARIANT somlSource, VARIANT_BOOL *ret);
	STDMETHOD(loadSOML)(BSTR soml, VARIANT_BOOL *ret);

	STDMETHOD(createApplication)(IOeSOApplication **ret);

public:
	STDMETHOD_(void, Fire_onLoaded)();

// ����
public:
	STDMETHOD(createLayout)(_xmlnode_t pnode, OeSOApplication *pApp);
	STDMETHOD(createUnits)(_xmlnode_t pnode, OeSOApplication *pApp);
	STDMETHOD(createObjects)(_xmlnode_t pnode, OeSOApplication *pApp);

// ����soml
public:
	// Ԥ����SOML, ĿǰΪ��
	STDMETHOD(xmlp0)();

	// �����Է����׶�
	STDMETHOD(xmlp1_interface)(_xmlnode_t pInterfaceNode, COeSOInterface **ret);
	STDMETHOD(xmlp1_class)(_xmlnode_t pClassNode, COeSOClass **ret);
	// ���Է����׶�
	STDMETHOD(xmlp2_interface)(_xmlnode_t pInterfaceNode, COeSOInterface *pInterface, COeSOApplication *pApp);
	STDMETHOD(xmlp2_class)(_xmlnode_t pClassNode, COeSOClass *pClass, COeSOApplication *pApp);
	STDMETHOD(xmlp2_status)(_xmlnode_t pStatusNode, COeSOStatus *pStatus, COeSOApplication *pApp);
	// ������׶�
	STDMETHOD(xmlp3_class)(_xmlnode_t pClassNode, COeSOClass *pClass, COeSOApplication *pApp);
	STDMETHOD(xmlp3_object)(_xmlnode_t pObjectNode, COeSOObject **ret, COeSOApplication *pApp);
protected:
	// soml��������
	STDMETHOD_(OeSOUnitTypeConstants,
		xmlnode_getUnitType)(_xmlnode_t pNode);
	STDMETHOD_(_bstr_t,
		xmlnode_getUnitName)(_xmlnode_t pNode);
	STDMETHOD_(_bstr_t,
		xmlnode_getUnitClass)(_xmlnode_t pNode);

// ��������
protected:
	STDMETHOD_(BOOL,
		coll_addUnit)(IOeSOCollection *pCollection, IDispatch *pUnit);

public:
	BEGIN_COM_MAP(OeSOParser)
		COM_INTERFACE_ENTRY(IOeSOParser)
		COM_INTERFACE_ENTRY2(IDispatch, IOeSOParser)
		COM_INTERFACE_ENTRY(IOeSOParserEvents)
		COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
	END_COM_MAP()

	BEGIN_CONNECTION_POINT_MAP(OeSOParser)
		CONNECTION_POINT_ENTRY(DIID_IOeSOParserEvents)
	END_CONNECTION_POINT_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeSOParser)
	DECLARE_NOT_AGGREGATABLE(OeSOParser)

public:
	_xmldoc_t	m_pSOML;
};

typedef CComObject<OeSOParser>	COeSOParser;
