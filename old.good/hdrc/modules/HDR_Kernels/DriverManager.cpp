// DriverManager.cpp : Implementation of CDriverManager
#include "stdafx.h"
#include "HDR_Kernels.h"
#include "DriverManager.h"


// _getdrives
#include <direct.h>
// DRIVE_LAYOUT_INFORMATION
#include <winioctl.h>


/////////////////////////////////////////////////////////////////////////////
// CDriverManager
BOOL CDriverManager::InitDisksInfo() {
	m_nDosDiskDevices = 0;
	m_nLabeledDisks = 0;	// From A: - Z:

	m_listDisks.clear();

	// Search labeled disks
	// This is included in DOS Devices.
	/*
	DWORD dwDisksMask = _getdrives();
	for (DWORD iMask = 0; iMask < 26; iMask++) {
		TCHAR szLabeled[] = TEXT("X:");
		if (dwDisksMask & (1 << iMask)) {
			szLabeled[0] = 'A' + iMask;
			m_listDisks.push_back(_bstr_t(szLabeled));
			m_nLabeledDisks++;
		}
	}
	*/

	// Search DOS Devices
	// ...
	TCHAR NamesBuf[32768], *pItem = NamesBuf;
	//		In my computer, the result occupies 6K chars.
	//		"> 100" seems enough small for check the result.
	if (QueryDosDevice(NULL, NamesBuf, 32767) > 100) {
		//		the last item is "\0\0".
		while (lstrlen(pItem) > 0) {
			// retrieve information and feature about the device.
			// GetDeviceInfo(pItem)?
			//

			// \\.\PHYSICALDRIVEx

			TCHAR szDosPath[1024];
			_stprintf(szDosPath, TEXT("\\\\.\\%s"), pItem);
			bstr_t bsDosPath = szDosPath;
			// Move to next item
			pItem += lstrlen(pItem) + 1;

			// Raise the event
			HRESULT hr;
			VARIANT_BOOL bIgnore = VARIANT_FALSE;
			hr = Fire_ScanDriver(bsDosPath, &bIgnore);

			if (bIgnore) {
				// ignored by caller.
				continue;
			}

			// For test only.
			HANDLE hDev = CreateFile(szDosPath, GENERIC_READ, FILE_SHARE_READ/*exclusive*/,
				NULL, OPEN_EXISTING, 0, NULL);
			if (hDev != INVALID_HANDLE_VALUE) {
				BOOL bRet;
				DWORD cb = 0;
				DRIVE_LAYOUT_INFORMATION dli;
				BOOL bAddThis = FALSE;

				if (!bAddThis) {
					DWORD cbLow, cbHigh = 0;
					cbLow = ::GetFileSize(hDev, &cbHigh);

					if ( (cbLow != (DWORD)-1) &&
						 (cbLow > 0 || (cbLow == 0 && cbHigh != 0))
						) bAddThis = TRUE;
				}

				if (!bAddThis) {
					bRet = DeviceIoControl(hDev, IOCTL_DISK_GET_DRIVE_LAYOUT, NULL, 0,
						&dli, sizeof(dli), &cb, NULL);

					if (!bRet || cb <= 0) {
						// seems not a valid disk drive.
					} else {
						// check more ...
						bAddThis = TRUE;
					}
				}

				if (bAddThis) {
					m_listDisks.push_back(_bstr_t(szDosPath));
					m_nDosDiskDevices++;
				}

				CloseHandle(hDev);
			}
		}
	}

	m_bInited = TRUE;
	return TRUE;
}


BOOL CDriverManager::ReportError(DWORD number, LPCTSTR sDescription) {
	HRESULT hr;
	ICreateErrorInfo *pCEI = NULL;
	IErrorInfo *pEI = NULL;

	hr = CreateErrorInfo(&pCEI);
	ASSERT(SUCCEEDED(hr));

	if (SUCCEEDED(hr)) {
		hr = pCEI->QueryInterface(IID_IErrorInfo, (void **)&pEI);
		ASSERT(SUCCEEDED(hr));

		if (SUCCEEDED(hr)) {
			hr = pCEI->SetDescription(_bstr_t(sDescription));
			// "the interface that defined the error", IID_DriverEnum?
			hr = pCEI->SetGUID(CLSID_DriverManager);
			hr = pCEI->SetSource(L"CDriverManager");
			hr = SetErrorInfo(0, pEI);
			pEI->Release();
		}
		pCEI->Release();
	}
	return TRUE;
}


STDMETHODIMP CDriverManager::GetDriversCount(int *Count)
{
	if (!m_bInited) InitDisksInfo();

	*Count = m_nLabeledDisks + m_nDosDiskDevices;
	return S_OK;
}


STDMETHODIMP CDriverManager::GetDriverName(int Index, BSTR *Name)
{
	if (!m_bInited) InitDisksInfo();

	*Name = NULL;

	if (Index < 0 || Index >= (int)m_listDisks.size()) {
		ReportError(0, TEXT("Index out of range!"));
		return E_INVALIDARG;
	}

	*Name = m_listDisks[Index].copy();
	return S_OK;
}


STDMETHODIMP CDriverManager::LoadDriver(BSTR Name, ILDAccess **LinearDevice)
{
	typedef CComObject<CWin32DiskLD> CWin32DiskLDImpl;

	*LinearDevice = NULL;

	CWin32DiskLDImpl *pDevice = new CWin32DiskLDImpl;
	if (pDevice == NULL) return E_OUTOFMEMORY;

	_bstr_t bstrname = Name;

	HRESULT hr;
	VARIANT_BOOL ret;
	hr = pDevice->BindToWin32Path((LPCTSTR)bstrname, &ret);

	if (FAILED(hr) || !ret) {
		delete pDevice;
		if (FAILED(hr)) return hr;
		else return E_FAIL;
	}

	hr = pDevice->QueryInterface(IID_ILDAccess, (void **)LinearDevice);
	if (FAILED(hr)) {
		delete pDevice;
		return hr;
	}

	return S_OK;
}


STDMETHODIMP CDriverManager::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] =
	{
		&IID_IDriverLoader,
		&IID_IDriverEnum,
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}
