
#pragma once

#include "DogCat.h"

#include "resource.h"
#include "DogCatCP.h"

/*
class CaDog :
	public CComObjectRoot,
	public CComCoClass<CaDog, &CLSID_CaDog>,
	public IDispatchImpl<ICaDog, &IID_ICaDog> {
public:
	CaDog() {}
	virtual ~CaDog() {}

public:
	STDMETHOD(shout)() {
		MessageBox(NULL, _T("Dog shout!"), _T("Dog shout!"), MB_OK);
		return NOERROR;
	}

public:
	BEGIN_COM_MAP(CaDog)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(ICaDog)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CaDog)
	DECLARE_NOT_AGGREGATABLE(CaDog)

protected:
};
*/
class CaDog;

class CaDog :
	public CComObjectRoot,
	public CComCoClass<CaDog, &CLSID_CaDog>,
	public IDispatchImpl<ICaDog, &IID_ICaDog>
{
public:
	CaDog() {}
	virtual ~CaDog() {}

public:
	STDMETHOD(shout)();
	STDMETHOD(bornDog)(ICaDog **ret);
	STDMETHOD(bornCat)(ICaCat **ret);

public:
	BEGIN_COM_MAP(CaDog)
		COM_INTERFACE_ENTRY2(IDispatch, ICaDog)
		COM_INTERFACE_ENTRY(ICaDog)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CaDog)
	DECLARE_NOT_AGGREGATABLE(CaDog)

protected:
};


class CaCat :
	public CComObjectRoot,
	public CComCoClass<CaCat, &CLSID_CaCat>,
	public IDispatchImpl<ICaCat, &IID_ICaCat> {
public:
	CaCat() {}
	virtual ~CaCat() {}

public:
	STDMETHOD(shout)();
	STDMETHOD(catshout)();

public:
	BEGIN_COM_MAP(CaCat)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(ICaCat)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CaCat)
	DECLARE_NOT_AGGREGATABLE(CaCat)

protected:
};



// earthquakes
class CaEarthquake :
	public CComObjectRoot,
	public CComCoClass<CaEarthquake, &CLSID_CaEarthquake>,
	public IDispatchImpl<ICaEarthquake, &IID_ICaEarthquake>,
	public IDispatchImpl<ICaEarthquakeEvents, &DIID_ICaEarthquakeEvents>,
	//public IConnectionPointImpl<CaEarthquake, &DIID_ICaEarthquakeEvents>,
	public IConnectionPointContainerImpl<CaEarthquake>,
	public CProxyICaEarthquakeEvents<CaEarthquake>
{
public:
	CaEarthquake() {}
	virtual ~CaEarthquake() {}

public:
	STDMETHOD(quakeNow)();
public:
	STDMETHOD_(void, onQuake)();

public:
	BEGIN_COM_MAP(CaEarthquake)
		COM_INTERFACE_ENTRY2(IDispatch, ICaEarthquake)
		COM_INTERFACE_ENTRY(ICaEarthquake)
		COM_INTERFACE_ENTRY2(IDispatch, ICaEarthquakeEvents)
		COM_INTERFACE_ENTRY(ICaEarthquakeEvents)
		COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
	END_COM_MAP()

	BEGIN_CONNECTION_POINT_MAP(CaEarthquake)
		CONNECTION_POINT_ENTRY(DIID_ICaEarthquakeEvents)
	END_CONNECTION_POINT_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CaEarthquake)
	DECLARE_NOT_AGGREGATABLE(CaEarthquake)
};


// (dispinterface)CaHorse

class CaHorse :
	public CComObjectRoot,
	public CComCoClass<CaHorse, &CLSID_CaHorse>,
	public IDispatchImpl<ICaHorse, &DIID_ICaHorse> {
public:
	CaHorse() {}
	virtual ~CaHorse() {}

public:
	STDMETHOD(run)();
public:

	BEGIN_COM_MAP(CaHorse)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(ICaHorse)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CaHorse)
	DECLARE_NOT_AGGREGATABLE(CaHorse)

protected:
};



class CaPlane :
	public CComObjectRoot,
	public CComCoClass<CaPlane, &CLSID_CaPlane>,
	public IDispatchImpl<ICaPlane, &IID_ICaPlane>,
	public IDispatchImpl<ICaPlaneEvents, &DIID_ICaPlaneEvents>,
	public CProxyICaPlaneEvents< CaPlane >,
	public IConnectionPointContainerImpl<CaPlane>
//	public IConnectionPointImpl<CaPlane, &DIID_ICaPlaneEvents, CComDynamicUnkArray>
	{
public:
	CaPlane() {}
	virtual ~CaPlane() {}
public:
	STDMETHOD(fly)();

public:
	BEGIN_COM_MAP(CaPlane)
		COM_INTERFACE_ENTRY(ICaPlane)
		COM_INTERFACE_ENTRY2(IDispatch, ICaPlane)
		COM_INTERFACE_ENTRY(ICaPlaneEvents)
		COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
	END_COM_MAP()

	BEGIN_CONNECTION_POINT_MAP(CaPlane)
		CONNECTION_POINT_ENTRY(DIID_ICaPlaneEvents)
	END_CONNECTION_POINT_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CaPlane)
	DECLARE_NOT_AGGREGATABLE(CaPlane)

protected:

};

typedef CComObject<CaDog>		CCaDog;
typedef CComObject<CaCat>		CCaCat;
typedef CComObject<CaEarthquake>	CCaEarthquake;
typedef CComObject<CaHorse>		CCaHorse;
typedef CComObject<CaPlane>		CCaPlane;
