
#pragma once

// 求值器求解SOML中的属性值、执行SOML中的方法等。
// CLSID: 00000000-4F45-0602-0002-486954656368
class OeSOEvaluator :
	public CComObjectRoot,
	public CComCoClass<OeSOEvaluator, &CLSID_OeSOEvaluator>,
	public IDispatchImpl<IOeSOEvaluator, &IID_IOeSOEvaluator> {
public:
	OeSOEvaluator();
	virtual ~OeSOEvaluator();

public:
	STDMETHOD(get_parser)(IOeSOParser **ret);
	STDMETHOD(put_parser)(IOeSOParser *parser);

	STDMETHOD(evaluator)(BSTR script, VARIANT *ret);

public:
	BEGIN_COM_MAP(OeSOEvaluator)
		COM_INTERFACE_ENTRY(IOeSOEvaluator)
		COM_INTERFACE_ENTRY2(IDispatch, IOeSOEvaluator)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeSOEvaluator)
	DECLARE_NOT_AGGREGATABLE(OeSOEvaluator)

public:
};

typedef CComObject<OeSOEvaluator>	COeSOEvaluator;
