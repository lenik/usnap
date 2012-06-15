// NetworkDiskLD.h : Declaration of the CNetworkDiskLD

#ifndef __NETWORKDISKLD_H_
#define __NETWORKDISKLD_H_

#include "resource.h"       // main symbols
#include "HDR_KernelsCP.h"

/////////////////////////////////////////////////////////////////////////////
// CNetworkDiskLD
class ATL_NO_VTABLE CNetworkDiskLD :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CNetworkDiskLD, &CLSID_NetworkDiskLD>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CNetworkDiskLD>,
    public IDispatchImpl<ILDAccess, &IID_ILDAccess, &LIBID_HDR_KernelsLib>,
    public IDispatchImpl<ILDCache, &IID_ILDAccess, &LIBID_HDR_KernelsLib>,
    public IDispatchImpl<ILDLargeIO, &IID_ILDAccess, &LIBID_HDR_KernelsLib>,
    public CProxy_ILDLargeIOEvents< CNetworkDiskLD >
{
public:
	CNetworkDiskLD()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_NETWORKDISKLD)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CNetworkDiskLD)
    COM_INTERFACE_ENTRY2(IDispatch, ILDAccess)
    COM_INTERFACE_ENTRY(ISupportErrorInfo)
    COM_INTERFACE_ENTRY(ILDAccess)
    COM_INTERFACE_ENTRY(ILDCache)
    COM_INTERFACE_ENTRY(ILDLargeIO)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
    COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CNetworkDiskLD)
    CONNECTION_POINT_ENTRY(DIID__ILDLargeIOEvents)
END_CONNECTION_POINT_MAP()


// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// ILDAccess
public:
	STDMETHOD(ImportFromFile)(/*[in]*/IDiskAddress *StartAddr, /*[in]*/BSTR BinaryFile, /*[in]*/BSTR LogFile);
	STDMETHOD(ExportToFile)(/*[in]*/IDiskAddress *StartAddr, /*[in]*/IDiskAddress *EndAddr, /*[in]*/BSTR BinaryFile, /*[in]*/BSTR LogFile);
    STDMETHOD(BindToWin32Path)(/*[in]*/LPCTSTR szDevicePath, /*[out, retval]*/VARIANT_BOOL *ret);
    STDMETHOD(GetPosition)(/*[out]*/long *LBA, /*[out]*/long *BytesOffset);
    STDMETHOD(Seek)(/*[in]*/long offLow, /*[in]*/long offHigh, /*[in]*/SeekRelationConstants Rel);
	STDMETHOD(Write)(/*[in]*/long cbSize, /*[in,size_is(cbSize)]*/BYTE *pbBuffer, /*[out,retval]*/long *pcbWritten);
	STDMETHOD(Read)(/*[in]*/long cbSize, /*[out,size_is(cbSize)]*/BYTE *pbBuffer, /*[out,retval]*/long *pcbRead);
    STDMETHOD(WriteSector)(/*[in]*/long LBA, /*[in]*/long nSectors, /*[in]*/BYTE *pBuffer, /*[out, retval]*/long *nWritten);
    STDMETHOD(ReadSector)(/*[in]*/long LBA, /*[in]*/long nSectors, /*[out]*/BYTE *pBuffer, /*[out, retval]*/long *nRead);
    STDMETHOD(InvalidateCache)();
    STDMETHOD(SetCacheSize)(/*[in]*/long nSectors);
};

#endif //__NETWORKDISKLD_H_
