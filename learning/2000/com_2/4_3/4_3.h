
#include "stdafx.h"

#include "IFortune.h"

class ComFortuneTeller : public IFortuneTeller {
public:
	ComFortuneTeller();

	STDMETHOD(QueryInterface)(REFIID, PPVOID);
	STDMETHOD_(ULONG, AddRef)();
	STDMETHOD_(ULONG, Release)();

	STDMETHOD(GetFortune)(/* [out, retval] */BSTR *);
protected:
	m_cRef;
};

typedef ComFortuneTeller	*PComFortuneTeller, *LPComFortuneTeller;
