// Win32DiskLD.h : Declaration of the CWin32DiskLD

#ifndef __WIN32DISKLD_H_
#define __WIN32DISKLD_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CWin32DiskLD
class ATL_NO_VTABLE CWin32DiskLD :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CWin32DiskLD, &CLSID_Win32DiskLD>,
	public ISupportErrorInfo,
	public IDispatchImpl<ILDAccess, &IID_ILDAccess, &LIBID_HDR_KernelsLib>,
	public IDispatchImpl<ILDCache, &IID_ILDAccess, &LIBID_HDR_KernelsLib>,
	public IDispatchImpl<ILDLargeIO, &IID_ILDAccess, &LIBID_HDR_KernelsLib>,
	public IDispatchImpl<IWin32DiskLD, &IID_IWin32DiskLD, &LIBID_HDR_KernelsLib>
{
public:
	CWin32DiskLD()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_WIN32DISKLD)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CWin32DiskLD)
	COM_INTERFACE_ENTRY2(IDispatch, ILDAccess)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(ILDAccess)
	COM_INTERFACE_ENTRY(ILDCache)
	COM_INTERFACE_ENTRY(ILDLargeIO)
	COM_INTERFACE_ENTRY(IWin32DiskLD)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// ILDAccess
public:
	STDMETHOD(BindToWin32Path)(/*[in]*/LPCTSTR szDevicePath, /*[out, retval]*/VARIANT_BOOL *ret);
	STDMETHOD(GetPosition)(/*[out]*/long *LBA, /*[out]*/long *BytesOffset);
	STDMETHOD(Seek)(/*[in]*/long Unit, /*[in]*/long Offset, /*[in]*/int Direction);
	STDMETHOD(WriteSector)(/*[in]*/long nSectors, /*[in]*/BYTE *pBuffer, /*[out, retval]*/long *nWritten);
	STDMETHOD(ReadSector)(/*[in]*/long nSectors, /*[out]*/BYTE *pBuffer, /*[out, retval]*/long *nRead);
	STDMETHOD(InvalidateCache)();
	STDMETHOD(SetCacheSize)(/*[in]*/long nSectors);
};

#endif //__WIN32DISKLD_H_
