// DriversManager.h : Declaration of the CDriversManager

#ifndef __DRIVERSMANAGER_H_
#define __DRIVERSMANAGER_H_

#include "resource.h"       // main symbols

#include "Win32DiskLD.h"
#include "HDR_KernelsCP.h"

/////////////////////////////////////////////////////////////////////////////
// CDriversManager
class ATL_NO_VTABLE CDriversManager :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDriversManager, &CLSID_DriversManager>,
	public ISupportErrorInfo,
	public IDispatchImpl<IDriverLoader, &IID_IDriverLoader, &LIBID_HDR_KernelsLib>,
	public IDispatchImpl<IDriverEnum, &IID_IDriverEnum, &LIBID_HDR_KernelsLib>,
	public CProxy_IDriverEnumEvents< CDriversManager >,
	public IConnectionPointContainerImpl<CDriversManager>
{
public:
	CDriversManager()
	{
		m_bInited = FALSE;
	}

protected:
	BOOL		m_bInited;
	int			m_nLabeledDisks;
	int			m_nDosDiskDevices;

	typedef std::vector<_bstr_t> bstr_list;
	bstr_list	m_listDisks;

public:
	BOOL		InitDisksInfo();

public:
DECLARE_REGISTRY_RESOURCEID(IDR_DRIVERSMANAGER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CDriversManager)
//	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, IDriverLoader)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IDriverLoader)
	COM_INTERFACE_ENTRY(IDriverEnum)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()


// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IDriverEnum
public:
	STDMETHOD(GetDriverName)(/*[in]*/int Index, /*[out, retval]*/BSTR *Name);
	STDMETHOD(GetDriversCount)(/*[out, retval]*/int *Count);

// IDriverLoader
public:
	STDMETHOD(LoadDriver)(/*[in]*/BSTR Name, /*[out, retval]*/ILDAccess **LinearDevice);

public :

BEGIN_CONNECTION_POINT_MAP(CDriversManager)
	CONNECTION_POINT_ENTRY(DIID__IDriverEnumEvents)
END_CONNECTION_POINT_MAP()

};

#endif //__DRIVERSMANAGER_H_
