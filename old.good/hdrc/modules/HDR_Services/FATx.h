// FATx.h : Declaration of the CFATx

#ifndef __FATX_H_
#define __FATX_H_

#include "resource.h"       // main symbols
#include "HDR_ServicesCP.h"

/////////////////////////////////////////////////////////////////////////////
// CFATx
class ATL_NO_VTABLE CFATx :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFATx, &CLSID_FATx>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CFATx>,
	public IDispatchImpl<IFSPMapper, &IID_IFSPMapper, &LIBID_HDR_ServicesLib>,
	public IDispatchImpl<IFSPReconstruct, &IID_IFSPReconstruct, &LIBID_HDR_ServicesLib>,
	public IDispatchImpl<IFSPRecstrMonitor, &IID_IFSPRecstrMonitor, &LIBID_HDR_ServicesLib>,
	public IDispatchImpl<IFSPAddInsMgr, &IID_IFSPAddInsMgr, &LIBID_HDR_ServicesLib>,
	public IDispatchImpl<IFSPFATxParser, &IID_IFSPFATxParser, &LIBID_HDR_ServicesLib>,
	public CProxy_IFSPMapperEvents< CFATx >
{
public:
	CFATx()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FATX)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CFATx)
	COM_INTERFACE_ENTRY2(IDispatch, IFSPMapper)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IFSPMapper)
	COM_INTERFACE_ENTRY(IFSPReconstruct)
	COM_INTERFACE_ENTRY(IFSPRecstrMonitor)
	COM_INTERFACE_ENTRY(IFSPAddInsMgr)
	COM_INTERFACE_ENTRY(IFSPFATxParser)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CFATx)
    CONNECTION_POINT_ENTRY(DIID__IFSPMapperEvents)
END_CONNECTION_POINT_MAP()


// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IFSPMapper
public:
	STDMETHOD(get_FiltersCount)(/*[out, retval]*/ long *pVal);
};

#endif //__FATX_H_
