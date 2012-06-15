
#pragma once

class OeTTree :
	public CComObjectRoot,
	public CComCoClass<OeTTree, &CLSID_OeTTree>,
	public IDispatchImpl<IOeTTree, &IID_IOeTTree> {
public:
	OeTTree();
	virtual ~OeTTree();

public:

public:
	BEGIN_COM_MAP(OeTTree)
		COM_INTERFACE_ENTRY2(IDispatch, IOeTTree)
		COM_INTERFACE_ENTRY(IOeTTree)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeT1)
	DECLARE_NOT_AGGREGATABLE(OeTTree)
};
