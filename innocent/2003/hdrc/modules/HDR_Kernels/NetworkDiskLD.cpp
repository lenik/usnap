// NetworkDiskLD.cpp : Implementation of CNetworkDiskLD
#include "stdafx.h"
#include "HDR_Kernels.h"
#include "NetworkDiskLD.h"

/////////////////////////////////////////////////////////////////////////////
// CNetworkDiskLD

STDMETHODIMP CNetworkDiskLD::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] =
	{
		&IID_ILDAccess,
        &IID_ILDCache,
        &IID_ILDLargeIO
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}



STDMETHODIMP CNetworkDiskLD::SetCacheSize(long nSectors)
{
    return E_NOTIMPL;
}

STDMETHODIMP CNetworkDiskLD::InvalidateCache()
{
    return E_NOTIMPL;
}

STDMETHODIMP CNetworkDiskLD::ReadSector(long LBA, long nSectors, BYTE *pBuffer, long *nRead)
{
    return E_NOTIMPL;
}

STDMETHODIMP CNetworkDiskLD::WriteSector(long LBA, long nSectors, BYTE *pBuffer, long *nWritten)
{
    return E_NOTIMPL;
}

STDMETHODIMP CNetworkDiskLD::Read(long cbSize, BYTE *pbBuffer, long *pcbRead)
{
    return E_NOTIMPL;
}

STDMETHODIMP CNetworkDiskLD::Write(long cbSize, BYTE *pbBuffer, long *pcbWritten)
{
    return E_NOTIMPL;
}

STDMETHODIMP CNetworkDiskLD::Seek(long Low, long High, SeekRelationConstants Rel)
{
    return E_NOTIMPL;
}

STDMETHODIMP CNetworkDiskLD::GetPosition(long *LBA, long *BytesOffset)
{
    return E_NOTIMPL;
}

STDMETHODIMP CNetworkDiskLD::BindToWin32Path(LPCTSTR szDevicePath, VARIANT_BOOL *ret)
{
    return E_NOTIMPL;
}

STDMETHODIMP CNetworkDiskLD::ExportToFile(IDiskAddress *StartAddr, IDiskAddress *EndAddr, BSTR BinaryFile, BSTR LogFile)
{
    return E_NOTIMPL;
}

STDMETHODIMP CNetworkDiskLD::ImportFromFile(IDiskAddress *StartAddr, BSTR BinaryFile, BSTR LogFile)
{
    return E_NOTIMPL;
}
