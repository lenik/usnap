// DriverManager.h : Declaration of the CDriverManager

#ifndef __DRIVERMANAGER_H_
#define __DRIVERMANAGER_H_

#include "resource.h"       // main symbols

#include "Win32DiskLD.h"
#include "HDR_KernelsCP.h"

/////////////////////////////////////////////////////////////////////////////
// CDriverManager
class ATL_NO_VTABLE CDriverManager :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDriverManager, &CLSID_DriverManager>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CDriverManager>,
	public IDispatchImpl<IDriverLoader, &IID_IDriverLoader, &LIBID_HDR_KernelsLib>,
	public IDispatchImpl<IDriverEnum, &IID_IDriverEnum, &LIBID_HDR_KernelsLib>,
	public CProxy_IDriverEnumEvents< CDriverManager >
{
public:
	CDriverManager()
	{
		m_bInited = FALSE;
	}

protected:
	BOOL			m_bInited;
	int				m_nLabeledDisks;
	int				m_nDosDiskDevices;

	typedef std::vector<_bstr_t> bstr_list;
	bstr_list		m_listDisks;

public:
	BOOL			InitDisksInfo();
	BOOL			ReportError(DWORD number, LPCTSTR sDescription);

DECLARE_REGISTRY_RESOURCEID(IDR_DRIVERMANAGER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CDriverManager)
	COM_INTERFACE_ENTRY(IDriverLoader)
	COM_INTERFACE_ENTRY(IDriverEnum)
	COM_INTERFACE_ENTRY2(IDispatch, IDriverLoader)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CDriverManager)
	CONNECTION_POINT_ENTRY(DIID__IDriverEnumEvents)
END_CONNECTION_POINT_MAP()


// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IDriverEnum
public:
	STDMETHOD(GetDriverName)(/*[in]*/int Index, /*[out, retval]*/BSTR *Name);
	STDMETHOD(GetDriversCount)(/*[out, retval]*/int *Count);

// IDriverLoader
public:
	STDMETHOD(LoadDriver)(/*[in]*/BSTR Name, /*[out, retval]*/ILDAccess **LinearDevice);
};

#endif //__DRIVERMANAGER_H_
