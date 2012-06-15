
#pragma once

// 类类描述一个类。一个类可以实现多个接口，但只能继承一个类。而且继承类与本类不能有重叠接口。类管理所有实例化的对象。
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
	// 对象名字
	_bstr_t				m_name;
	// 继承类
	IOeSOClass *			m_pInherits;
	// 派生类集
	COeSOClassesCollection *	m_derives;
	// 实现接口
	COeSOInterfacesCollection *	m_interfaces;
	// 类属性集
	COeSOAttributesCollection *	m_attributes;
	// 对象属性模版集
	COeSOAttributesCollection *	m_objectAttributes;
	// 方法集 (连接到类方法集)
	COeSOMethodsCollection *	m_methods;
	// 事件集 (连接到类事件集)
	COeSOEventsCollection *		m_events;
	// 实例集
	COeSOObjectsCollection *	m_instances;
};
