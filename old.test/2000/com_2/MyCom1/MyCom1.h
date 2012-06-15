
#include "stdafx.h"

#include "Ellipse.h"

class BoxGraphFactory : public IClassFactory {
public:
	BoxGraphFactory();

	STDMETHOD(QueryInterface)(REFIID, LPVOID *);
	STDMETHOD_(ULONG, AddRef)();
	STDMETHOD_(ULONG, Release)();
public:
	STDMETHOD(CreateInstance)(LPUNKNOWN, REFIID, LPVOID *);
	STDMETHOD_(ULONG, LockServer)();
};
