
#pragma once

class OeTGraph :
	public CComObjectRoot,
	public CComCoClass<OeTGraph, &CLSID_OeTGraph>,
	public IDispatchImpl<IOeTGraph, &IID_IOeTGraph> {
public:
	OeTGraph();
	virtual ~OeTGraph();

public:

public:
	BEGIN_COM_MAP(OeTGraph)
		COM_INTERFACE_ENTRY2(IDispatch, IOeTGraph)
		COM_INTERFACE_ENTRY(IOeTGraph)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeT1)
	DECLARE_NOT_AGGREGATABLE(OeTGraph)
};
