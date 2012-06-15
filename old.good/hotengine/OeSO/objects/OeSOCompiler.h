
#pragma once

// 编译器将SOML编译成其它语言。
// CLSID: 00000000-4F45-0601-0002-486954656368
class OeSOCompiler :
	public CComObjectRoot,
	public CComCoClass<OeSOCompiler, &CLSID_OeSOCompiler>,
	public IDispatchImpl<IOeSOCompiler, &IID_IOeSOCompiler> {
public:
	OeSOCompiler();
	virtual ~OeSOCompiler();

public:
	STDMETHOD(get_parser)(IOeSOParser **ret);
	STDMETHOD(put_parser)(IOeSOParser *parser);
	STDMETHOD(compileSOML)(BSTR *ret);

public:
	BEGIN_COM_MAP(OeSOCompiler)
		COM_INTERFACE_ENTRY(IOeSOCompiler)
		COM_INTERFACE_ENTRY2(IDispatch, IOeSOCompiler)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeSOCompiler)
	DECLARE_NOT_AGGREGATABLE(OeSOCompiler)

public:
};

typedef CComObject<OeSOCompiler>	COeSOCompiler;
