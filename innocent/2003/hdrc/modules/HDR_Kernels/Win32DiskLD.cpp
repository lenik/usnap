// Win32DiskLD.cpp : Implementation of CWin32DiskLD
#include "stdafx.h"
#include "HDR_Kernels.h"
#include "Win32DiskLD.h"

/////////////////////////////////////////////////////////////////////////////
// CWin32DiskLD

STDMETHODIMP CWin32DiskLD::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] =
	{
		&IID_ILDAccess
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CWin32DiskLD::SetCacheSize(long nSectors)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CWin32DiskLD::InvalidateCache()
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CWin32DiskLD::ReadSector(long nSectors, BYTE *pBuffer, long *nRead)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CWin32DiskLD::WriteSector(long nSectors, BYTE *pBuffer, long *nWritten)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CWin32DiskLD::Seek(long Unit, long Offset, int Direction)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CWin32DiskLD::GetPosition(long *LBA, long *BytesOffset)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CWin32DiskLD::BindToWin32Path(LPCTSTR szDevicePath, VARIANT_BOOL *ret)
{
	// TODO: Add your implementation code here

	return S_OK;
}
