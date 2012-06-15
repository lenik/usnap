
#ifdef XXXX

class ComFortuneTeller : public CCmdTarget {
public:
	ComFortuneTeller();
	virtual ~ComFortuneTeller();

protected:

	BEGIN_INTERFACE_PART(CInnerFortune, IUnknown)
		STDMETHOD(GetFortune)(PBSTR);
	END_INTERFACE_PART(CInnerFortune)

	BEGIN_INTERFACE_PART(CInnerFortune, IUnknown)
		STDMETHOD(GetQuotation)(PBSTR, PBSTR);
	END_INTERFACE_PART(CInnerFortune);

	DECLARE_INTERFACE_MAP()
	DECLARE_OLECREATE(ComFortuneTeller)
	DECLARE_DYNCREATE(ComFortuneTeller)
};

typedef ComFortuneTeller	*PCOMFORTUNETELLER, *LPCOMFORTUNETELLER;

#endif
