
#pragma once

// 分析器用于分析SOML文档、从数据库中导入SOML、保存SOML等, 并创建应用体对象。
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

// 分析
public:
	STDMETHOD(createLayout)(_xmlnode_t pnode, OeSOApplication *pApp);
	STDMETHOD(createUnits)(_xmlnode_t pnode, OeSOApplication *pApp);
	STDMETHOD(createObjects)(_xmlnode_t pnode, OeSOApplication *pApp);

// 解析soml
public:
	// 预处理SOML, 目前为空
	STDMETHOD(xmlp0)();

	// 无属性分析阶段
	STDMETHOD(xmlp1_interface)(_xmlnode_t pInterfaceNode, COeSOInterface **ret);
	STDMETHOD(xmlp1_class)(_xmlnode_t pClassNode, COeSOClass **ret);
	// 属性分析阶段
	STDMETHOD(xmlp2_interface)(_xmlnode_t pInterfaceNode, COeSOInterface *pInterface, COeSOApplication *pApp);
	STDMETHOD(xmlp2_class)(_xmlnode_t pClassNode, COeSOClass *pClass, COeSOApplication *pApp);
	STDMETHOD(xmlp2_status)(_xmlnode_t pStatusNode, COeSOStatus *pStatus, COeSOApplication *pApp);
	// 对象构造阶段
	STDMETHOD(xmlp3_class)(_xmlnode_t pClassNode, COeSOClass *pClass, COeSOApplication *pApp);
	STDMETHOD(xmlp3_object)(_xmlnode_t pObjectNode, COeSOObject **ret, COeSOApplication *pApp);
protected:
	// soml分析工具
	STDMETHOD_(OeSOUnitTypeConstants,
		xmlnode_getUnitType)(_xmlnode_t pNode);
	STDMETHOD_(_bstr_t,
		xmlnode_getUnitName)(_xmlnode_t pNode);
	STDMETHOD_(_bstr_t,
		xmlnode_getUnitClass)(_xmlnode_t pNode);

// 分析工具
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
