
#pragma once

class OeTTree2 :
	public CComObjectRoot,
	public CComCoClass<OeTTree2, &CLSID_OeTTree2>,
	public IDispatchImpl<IOeTTree2, &IID_IOeTTree2> {
public:
	OeTTree2();
	virtual ~OeTTree2();

public:

public:
	BEGIN_COM_MAP(OeTTree2)
		COM_INTERFACE_ENTRY2(IDispatch, IOeTTree2)
		COM_INTERFACE_ENTRY(IOeTTree2)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeT1)
	DECLARE_NOT_AGGREGATABLE(OeTTree2)
};
