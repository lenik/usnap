// Win32DiskLD.cpp : Implementation of CWin32DiskLD

#include "stdafx.h"
#include "HDR_Kernels.h"
#include "Win32DiskLD.h"


#define LBA_TO_64_LOW(lba)          (DWORD)( ((DWORD)(lba)) << 9  )
#define LBA_TO_64_HIGH(lba)         (LONG) ( ((DWORD)(lba)) >> 23 )

#define L64_TO_LBA(low,high)        ((DWORD)((((DWORD)(low)) >> 9) | (((DWORD)(high)) << 23)))

typedef unsigned __int64 U64;


/////////////////////////////////////////////////////////////////////////////
// CWin32DiskLD

CacheBlock *CWin32DiskLD::_alloc_cache(DWORD _lba, DWORD _count_sectors, LPBYTE _data) {
    DWORD cbSize = _count_sectors * 512;
    BOOL bCopyAndRelease = _data != NULL;

    CacheBlock *pBlock = NULL;

    pBlock = m_Cache.PrepareCache(cbSize);
    if (!pBlock) return NULL;

    pBlock->dwExtAddr = _lba;
    if (bCopyAndRelease) {
        memcpy(pBlock->pbMemory, _data, cbSize);
    }

    BOOL b;
    b = m_Cache.SubmitCache(pBlock, bCopyAndRelease);
    ASSERT(b);

    return pBlock;
}


CacheBlock *CWin32DiskLD::_search_cache(DWORD _lba) {
    CacheBlock *pBlock = NULL;

    pBlock = m_Cache.FindCacheBlock(_lba);

    if (!pBlock) return NULL;

    pBlock->AssertValid();
    return pBlock;
}


BOOL CWin32DiskLD::_uncache(DWORD _lba) {
    CacheBlock *pBlock = _search_cache(_lba);
    if (!pBlock) return FALSE;

    return _uncache(pBlock);
}


BOOL CWin32DiskLD::_uncache(CacheBlock *pBlock) {
    pBlock->AssertValid();

    pBlock->DecW();
    ASSERT(pBlock->Weight != -1);

    if (pBlock->Weight == 0 || pBlock->Weight == -1) {
        m_Cache.FreeCache(pBlock);
        return TRUE;
    }
    return FALSE;
}




HRESULT CWin32DiskLD::_read_sector(DWORD _lba, DWORD *pIOErr) {
    BOOL b;
    DWORD cbRead;
    CacheBlock *pSector;
    pSector = _search_cache(_lba);
    if (pSector != NULL) {
        pSector->AssertValid();
        return S_OK;
    }

    DWORD offLow = LBA_TO_64_LOW(_lba);
    LONG offHigh = LBA_TO_64_HIGH(_lba);
    offLow = SetFilePointer(m_hDevice, offLow, &offHigh, FILE_BEGIN);
    if (offLow == (DWORD)-1) {
        ReportError(TEXT("Error seeking"));
        return E_FAIL;
    }

    if (!pSector) {
        pSector = _alloc_cache(_lba, 1/*sectors count*/);
        if (pSector == NULL) {
            return E_OUTOFMEMORY;
        }
    }

    pSector->bLock = 1;
    b = ReadFile(m_hDevice, pSector->pbMemory, 512, &cbRead, NULL);
    if (pIOErr) *pIOErr = GetLastError();
    pSector->IncW();
    pSector->bLock = 0;

    if (!b) {
        ReportError(TEXT("Error reading"));
        _uncache(pSector);
        return E_FAIL;
    } else if (cbRead != 512) {
        ReportError(TEXT("Partial Read"));
        return S_FALSE;
    }
    return S_OK;
}


HRESULT CWin32DiskLD::_write_sector(DWORD _lba, LPBYTE _data, DWORD *pIOErr) {
    DWORD offLow = LBA_TO_64_LOW(_lba);
    LONG offHigh = LBA_TO_64_HIGH(_lba);
    offLow = SetFilePointer(m_hDevice, offLow, &offHigh, FILE_BEGIN);
    if (offLow == (DWORD)-1) {
        ReportError(TEXT("Error seeking"));
        return E_FAIL;
    }

    BOOL b;
    DWORD cbWritten;
    CacheBlock *pSector;

    pSector = _search_cache(_lba);
    if (pSector == NULL) {
        pSector = _alloc_cache(_lba, 1/*sectors count*/);
        if (pSector == NULL) {
            return E_OUTOFMEMORY;
        }
    } else {
        pSector->AssertValid();
    }

    pSector->bLock = 1;
    memcpy(pSector->pbMemory, _data, 512);
    pSector->bLock = 0;

    pSector->bSync_ = 1;
    b = WriteFile(m_hDevice, pSector, 512, &cbWritten, NULL);
    if (pIOErr) *pIOErr = GetLastError();
    // don't increment the weight for the writing,
    // pSector->IncW();
    pSector->bSync_ = 0;

    if (!b) {
        ReportError(TEXT("Error Writing"));
        // _uncache(pSector);
        return E_FAIL;
    } else if (cbWritten != 512) {
        ReportError(TEXT("Partial Written"));
        return S_FALSE;
    }

    return S_OK;
}

BOOL CWin32DiskLD::_split_range(DWORD startLow, LONG startHigh, DWORD endLow, DWORD endHigh,
                             DWORD& secAt, LONG& sectors,
                             DWORD& bytesPre, DWORD& bytesSuf) {
    __int64 _start;
    __int64 _end;
    __int64 _size;
    long    _sizel;
    ((DWORD *)&_start)[0] = startLow;
    ((LONG  *)&_start)[1] = startHigh;
    ((DWORD *)&_end  )[0] = endLow;
    ((LONG  *)&_end  )[1] = endHigh;

    _size = _end - _start;
    if (_size < 0) return FALSE;

    // [0 1 2 ... 511] -> [ 0 511 510 ... 1 ]
    bytesPre = (512 - startLow % 512) % 512;
    if (bytesPre >= _size) {
        bytesPre = _size;
        _size = 0;
    } else {
        _size -= bytesPre;
        ASSERT(_size >= 0);
    }
    _start += bytesPre;

    secAt = (DWORD)(_start >> 9);

    // [0 1 2 ... 510 511] -> [ 0 0 0 ... 0 1 ]
    sectors = (_size + 1) >> 9;
    bytesSuf = 0;
    _sizel = ((DWORD)_size) & 0x000001FF;

    if (_sizel == 0) return TRUE;

    // [0 1 2 ... 511] -> [ 1 2 3 ... 511 0 ]
    bytesSuf = (endLow % 512 + 1) % 512;
    if (bytesSuf != _sizel) {
        /*
            Assertion (endLow % 512 == _size % 512) won't be true if:

            ___|__________|__________|__________|____
                  S  E
                  <-------> bytesPre
               <-----> bytesSuf

                    ( Here endLow % 512 > _size % 512 )

            According to "bytesPre_ >= _size" will set _size to 0,
            so after the procedure running to here, E must not in the sector
            where S stays:

            ___|__________|__________|__________|____
                  S             E
                  <-------> bytesPre
                          <-----> bytesSuf

            And so Assertion (endLow % 512 == _size % 512) will always be true.
        */
        ASSERT(endLow % 512 == _sizel);
        /*
            And bytesSuf will always be equal to _size.
        */
        ASSERT(FALSE);
    }

    return TRUE;
}



LogControlCode  CWin32DiskLD::_lcc_input  (HANDLE hfLog, LccRecord *pRecord) {
    ASSERT(hfLog && pRecord);
    LogControlCode lcc;
    BOOL b;
    DWORD cbRead;
    b = ReadFile(hfLog, &lcc, sizeof(DWORD), &cbRead, NULL);
    if (!b || cbRead != sizeof(DWORD)) {
        ASSERT(FALSE);
        return lccNull;
    }
    pRecord->lcc = lcc;
    switch (lcc) {
    case lccNull:
        break;
    case lccRecordMagic:
        b = ReadFile(hfLog, &pRecord->Magic, sizeof(LccRecord::_Magic), &cbRead, NULL);
        ASSERT(b && cbRead == sizeof(LccRecord::_Magic));
        if (pRecord->Magic.Value != 'LCC ') {
            ReportError(TEXT("Not an valid log file."));
            return lcc;
        }
        break;
    case lccBadSector:
    case lccIgnore:
    case lccAll_00:
    case lccAll_FF:
        b = ReadFile(hfLog, &pRecord->Range, sizeof(LccRecord::_Range), &cbRead, NULL);
        ASSERT(b && cbRead == sizeof(LccRecord::_Range));
        break;
    case lccPatch:
        b = ReadFile(hfLog, &pRecord->Patch, sizeof(LccRecord::_Patch), &cbRead, NULL);
        ASSERT(b && cbRead == sizeof(LccRecord::_Patch));
        break;
    case lccRepeatLast:
    default:
        ReportError(TEXT("Invalid Log Record!"));
        return lcc;
    }

    return lcc;
}

LogControlCode  CWin32DiskLD::_lcc_input1 (HANDLE hfLog, DWORD *pLBA) {
    LccRecord rec;
    switch (_lcc_input(hfLog, &rec)) {
    case lccNull:
        return lccNull;
    case lccBadSector:
    case lccIgnore:
    case lccAll_00:
    case lccAll_FF:
        ASSERT(rec.Range.Count == 1);
        if (pLBA) *pLBA = rec.Range.LBA;
        break;
    case lccPatch:
    case lccRepeatLast:
    default:
        return rec.lcc;
    }
    return rec.lcc;
}

BOOL            CWin32DiskLD::_lcc_output (HANDLE hfLog, LccRecord *pRecord) {
    ASSERT(hfLog && pRecord);
    DWORD lcc = pRecord->lcc;
    BOOL b;
    DWORD cbWritten;

    b = WriteFile(hfLog, &lcc, sizeof(DWORD), &cbWritten, NULL);
    if (!b || cbWritten != sizeof(DWORD)) return FALSE;

    switch (lcc) {
    case lccNull:
        break;
    case lccBadSector:
    case lccIgnore:
    case lccAll_00:
    case lccAll_FF:
        b = WriteFile(hfLog, &pRecord->Range, sizeof(LccRecord::_Range), &cbWritten, NULL);
        ASSERT(b && cbWritten == sizeof(LccRecord::_Range));
        break;
    case lccPatch:
        b = WriteFile(hfLog, &pRecord->Patch, sizeof(LccRecord::_Patch), &cbWritten, NULL);
        ASSERT(b && cbWritten == sizeof(LccRecord::_Patch));
        break;
    case lccRepeatLast:
    default:
        ASSERT(FALSE);
        return FALSE;
    }

    return TRUE;
}

BOOL            CWin32DiskLD::_lcc_output1(HANDLE hfLog, LogControlCode lcc, DWORD LBA) {
    LccRecord rec;
    rec.lcc = lcc;
    rec.Range.LBA = LBA;
    rec.Range.Count = 1;
    return _lcc_output(hfLog, &rec);
}

HRESULT CWin32DiskLD::_import_from_file(HANDLE hfBinary, HANDLE hfLog, BOOL bLog,
                                        DWORD secAt, LONG sectors, DWORD bytesPre, DWORD bytesSuf) {
    return E_NOTIMPL;
}


HRESULT CWin32DiskLD::_export_to_file(HANDLE hfBinary, HANDLE hfLog, BOOL bLog,
                                      DWORD secAt, LONG sectors, DWORD bytesPre, DWORD bytesSuf) {
    ASSERT(hfBinary && (!bLog || bLog && hfLog));

    HRESULT hr;
    CacheBlock *pSector;
    BOOL b;
    DWORD cb;
    DWORD IOErr;

    if (bytesPre) {
        ASSERT(secAt - 1 >= 1);

        hr = _read_sector(secAt - 1, &IOErr);
        if (FAILED(hr)) {
            if (!_process_errlog(IOErr, hfLog, secAt - 1, 1)) {
                return hr;
            }
            b = _pad_bytes(hfBinary, 512);
            if (!b) return E_FAIL;
        } else {
            pSector = _search_cache(secAt - 1);
            ASSERT(pSector);

            b = WriteFile(hfBinary, pSector->pbMemory + 512 - bytesPre, bytesPre, &cb, NULL);
            if (!b || cb != bytesPre) {
                ReportLastError();
                return E_FAIL;
            }
        }
    }

    while (sectors > 0) {
        hr = _read_sector(secAt, &IOErr);
        if (FAILED(hr)) {
            if (!_process_errlog(IOErr, hfLog, secAt, 1)) {
                return hr;
            }
            b = _pad_bytes(hfBinary, 512);
            if (!b) return E_FAIL;
        } else {
            pSector = _search_cache(secAt);
            ASSERT(pSector);

            b = WriteFile(hfBinary, pSector->pbMemory, 512, &cb, NULL);
            if (!b || cb != 512) {
                ReportLastError();
                return E_FAIL;
            }
        }
        secAt++;
        sectors--;
    }

    if (bytesSuf) {
        hr = _read_sector(secAt, &IOErr);
        if (FAILED(hr)) {
            if (!_process_errlog(IOErr, hfLog, secAt - 1, 1)) {
                return hr;
            }
            b = _pad_bytes(hfBinary, 512);
            if (!b) return E_FAIL;
        } else {
            pSector = _search_cache(secAt);
            ASSERT(pSector);

            b = WriteFile(hfBinary, pSector->pbMemory, bytesSuf, &cb, NULL);
            if (!b || cb != bytesSuf) {
                ReportLastError();
                return E_FAIL;
            }
        }
    }

    return S_OK;
}


BOOL CWin32DiskLD::_process_errlog(DWORD dwError, HANDLE hfLog, DWORD LBA, DWORD Count) {
    switch (dwError) {
    case ERROR_CRC:
        // bad sector.
        _lcc_output1(hfLog, lccBadSector, LBA);
        break;
    default:
        return FALSE;
    }
    return TRUE;
}


BOOL CWin32DiskLD::_pad_bytes(HANDLE hf, DWORD cbBytes) {
    LPBYTE pBuf = new BYTE[cbBytes];
    ASSERT(pBuf);

    BOOL b;
    DWORD cbWritten;
    b = WriteFile(hf, pBuf, cbBytes, &cbWritten, NULL);
    delete[] pBuf;

    return b && cbWritten == cbBytes;
}


BOOL CWin32DiskLD::ReportError(LPCTSTR sDescription) {
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
			hr = pCEI->SetGUID(CLSID_Win32DiskLD);
			hr = pCEI->SetSource(L"CWin32DiskLD");
			hr = SetErrorInfo(0, pEI);
			pEI->Release();
		}
		pCEI->Release();
	}
	return TRUE;
}


DWORD CWin32DiskLD::ReportLastError() {
    DWORD dwErr = GetLastError();
    TCHAR buf[256];

    FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwErr, 0, buf, 255, NULL);

    ReportError(buf);

    return dwErr;
}


STDMETHODIMP CWin32DiskLD::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] =
	{
		&IID_ILDAccess,
        &IID_ILDCache,
        &IID_ILDLargeIO,
        &IID_IWin32DiskLD,
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
    DWORD nNewSize = nSectors * 512;

    if (nNewSize < 1) {
        ReportError(TEXT("Cache have to contain 1 more sectors."));
        return E_INVALIDARG;
    }

    BOOL b = m_Cache.SetCacheSize(nNewSize);

    if (!b) {
        ReportError(TEXT("Can't set size, some blocks may be using."));
        return E_FAIL;
    }

    return S_OK;
}


STDMETHODIMP CWin32DiskLD::InvalidateCache()
{
	BOOL b = m_Cache.InvalidateCache();

    if (!b) {
        ReportError(TEXT("Can't invalidate cache, some blocks may be using."));
        return E_FAIL;
    }

	return S_OK;
}


STDMETHODIMP CWin32DiskLD::ReadSector(long LBA, long nSectors, BYTE *pBuffer, long *nRead)
{
    if (m_hDevice == NULL) {
        ReportError(TEXT("Device not ready"));
        return E_FAIL;
    }
    if (LBA == 0 || LBA > 0x7FFFFFFF) {
        ReportError(TEXT("Index out of range. (This program don't support disk larger than 1T bytes.) "));
        return E_INVALIDARG;
    }

    HRESULT hr;
    long sectorsRead = 0;

    if (nRead) *nRead = 0;

    for (; nSectors > 0; LBA++, nSectors--) {
        hr = _read_sector(LBA);

        if (FAILED(hr)) {
            TCHAR buf[40];
            _stprintf(buf, TEXT("Can't read sector: LBA=%08x"), LBA);
            ReportError(buf);
            return E_FAIL;
        }

        CacheBlock *pSector = _search_cache(LBA);
        pSector->AssertValid();
        if (pSector == NULL) return E_UNEXPECTED;

        memcpy(pBuffer, pSector->pbMemory, 512);
        pBuffer += 512;
        sectorsRead++;

        // n@ repeat writing.
        m_offLow  = LBA_TO_64_LOW(LBA);
        m_offHigh = LBA_TO_64_HIGH(LBA);

        if (nRead) *nRead = sectorsRead;
    }

	return S_OK;
}


STDMETHODIMP CWin32DiskLD::WriteSector(long LBA, long nSectors, BYTE *pBuffer, long *nWritten)
{
    if (m_hDevice == NULL) {
        ReportError(TEXT("Device not ready"));
        return E_FAIL;
    }
    if (LBA == 0 || LBA > 0x7FFFFFFF) {
        ReportError(TEXT("Index out of range. (This program don't support disk larger than 1T bytes.) "));
        return E_INVALIDARG;
    }

    HRESULT hr;
    long sectorsWritten = 0;

    if (nWritten) *nWritten = 0;

    for (; nSectors > 0; LBA++, nSectors--) {
        hr = _write_sector(LBA, pBuffer);

        if (FAILED(hr)) {
            TCHAR buf[40];
            _stprintf(buf, TEXT("Can't write sector: LBA=%08x"), LBA);
            ReportError(buf);
            return E_FAIL;
        }

        /*
            CacheBlock *pSector = _search_cache(LBA);
            pSector->AssertValid();
            if (pSector == NULL) return E_UNEXPECTED;
        */

        pBuffer += 512;
        sectorsWritten++;

        // n@ repeat writing.
        m_offLow  = LBA_TO_64_LOW(LBA);
        m_offHigh = LBA_TO_64_HIGH(LBA);

        if (nWritten) *nWritten = sectorsWritten;
    }

	return S_OK;
}


STDMETHODIMP CWin32DiskLD::Read(long cbSize, BYTE *pbBuffer, long *pcbRead)
{
    if (m_hDevice == NULL) {
        ReportError(TEXT("Device not ready"));
        return E_FAIL;
    }

    DWORD endLow, endHigh;
    endLow = m_offLow + cbSize - 1;
    endHigh = m_offHigh;
    if (endLow < cbSize - 1) endHigh++;

    DWORD secAt, bytesPre, bytesSuf;
    LONG sectors;
    DWORD cbRead;
    BOOL b;

    b = _split_range(m_offLow, m_offHigh, endLow, endHigh, secAt, sectors, bytesPre, bytesSuf);
    if (!b) {
        ReportError(TEXT("Range error!"));
        return E_INVALIDARG;
    }

	return E_NOTIMPL;
}


STDMETHODIMP CWin32DiskLD::Write(long cbSize, BYTE *pbBuffer, long *pcbWritten)
{
    if (m_hDevice == NULL) {
        ReportError(TEXT("Device not ready"));
        return E_FAIL;
    }

    // TODO: Add your implementation code here

	return E_NOTIMPL;
}


STDMETHODIMP CWin32DiskLD::Seek(long Low, long High, SeekRelationConstants Rel)
{
    if (m_hDevice == NULL) {
        ReportError(TEXT("Device not ready"));
        return E_FAIL;
    }

    DWORD dwMoveMethod;
    switch (Rel) {
    case srBegin:
        dwMoveMethod    = FILE_BEGIN;
        break;
    case srEnd:
        dwMoveMethod    = FILE_END;
        break;
    case srCurrent:
        dwMoveMethod    = FILE_CURRENT;
        break;
    default:
        ReportError(TEXT("Relation error: \n\t 0 - Begin, \n\t 1 - End, \n\t 2 - Current"));
        return E_INVALIDARG;
    }

    DWORD dwLow = (DWORD)Low, dwHigh = (DWORD)High;
    dwLow = SetFilePointer(m_hDevice, Low, &High, dwMoveMethod);

    if (dwLow == (DWORD)-1) {
        ReportError(TEXT("Cannot do seek. "));
        return E_FAIL;
    }

	return S_OK;
}


STDMETHODIMP CWin32DiskLD::GetPosition(long *LBA, long *BytesOffset)
{
    if (m_hDevice == NULL) {
        ReportError(TEXT("Device not ready"));
        return E_FAIL;
    }

    if (!LBA || !BytesOffset) return E_INVALIDARG;

    long Low, High;
    Low = ::SetFilePointer(m_hDevice, 0, &High, FILE_CURRENT);
    if (Low == (DWORD)-1) {
        ReportError(TEXT("Cannot get position: Seek error."));
        return E_UNEXPECTED;
    }

    unsigned __int64 Pos64 = (High << 32) | Low;

    DWORD theLBA;
    if (Pos64 >= 0x20000000000) {
        ReportError(TEXT("Currently Position at more than 2T bytes, the program can't return the value."));
        return E_FAIL;
    }

    theLBA = (DWORD)(Pos64 / 512);
    *LBA = theLBA;
    *BytesOffset = (long)(Pos64 % 512);

	return S_OK;
}


STDMETHODIMP CWin32DiskLD::BindToWin32Path(LPCTSTR szDevicePath, VARIANT_BOOL *ret)
{
    if (m_hDevice != NULL) {
        ReportError(TEXT("Already binded."));
        return E_FAIL;
    }

    m_szPath = strdup(szDevicePath);
	return S_OK;
}

STDMETHODIMP CWin32DiskLD::Unbind()
{
    if (m_hDevice) {
        BOOL b;
        b = CloseHandle(m_hDevice);
        if (!b) {
            ReportError(TEXT("Can't close device, the device may be using."));
            return E_FAIL;
        }
        m_hDevice = NULL;
    }

    if (m_szPath) {
        free((void *)m_szPath);
        m_szPath = NULL;
    }
	return S_OK;
}


STDMETHODIMP CWin32DiskLD::ExportToFile(IDiskAddress *StartAddr, IDiskAddress *EndAddr, BSTR BinaryFile, BSTR LogFile)
{
    BOOL bLog = FALSE;
    _bstr_t bsFileBinary(BinaryFile);
    HANDLE hfBinary;
    HANDLE hfLog = NULL;
    HRESULT hr;
    VARIANT_BOOL vb;
    BOOL b;

    if (!StartAddr || !EndAddr || !BinaryFile) return E_INVALIDARG;

    if (m_hDevice == NULL) {
        ReportError(TEXT("Device not ready"));
        return E_FAIL;
    }

    hr = StartAddr->IsValid(&vb);
    ASSERT(SUCCEEDED(hr));
    if (!vb) return E_INVALIDARG;

    hr = EndAddr->IsValid(&vb);
    ASSERT(SUCCEEDED(hr));
    if (!vb) return E_INVALIDARG;

    DWORD startLow, endLow;
    LONG startHigh, endHigh;
    DWORD secAt, bytesPre, bytesSuf;
    LONG sectors;
    AddressModeConstants startMode, endMode;

    hr = StartAddr->get_LinearLow((long *)&startLow);
    hr = StartAddr->get_LinearHigh((long *)&startHigh);
    hr = EndAddr->get_LinearLow((long *)&endLow);
    hr = EndAddr->get_LinearHigh((long *)&endHigh);
    hr = EndAddr->get_Mode(&startMode);
    hr = EndAddr->get_Mode(&endMode);
    if (startMode == endMode && startMode != amLinear) {
        // using CHS or LBA mode, so align at sector:
        ASSERT((startLow % 512 == 0) && (endLow % 512 == 0));
        // align to a sector of 512 bytes..
        endLow += 511;
    }

    b = _split_range(startLow, startHigh, endLow, endHigh,
                     secAt, sectors, bytesPre, bytesSuf);
    if (!b) {
        ReportError(TEXT("Invalid range specified!"));
        return E_INVALIDARG;
    }

    /*
        !! IMPORTANT !!
            Writing the file may destroy data on disk, when the file is stored
            on the specified disk. (overlapped)

            FILE_FLAG_WRITE_THROUGH instructs system to write to disk directly,
            or not to lazily flush the cache.
    */
    hfBinary = CreateFile((LPCTSTR)bsFileBinary, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL, NULL);
    if (hfBinary == INVALID_HANDLE_VALUE) {
        ReportError(TEXT("Can't open binary file for writing."));
        return E_FAIL;
    }

    if (LogFile) {
        _bstr_t bsFileLog(LogFile);
        hfLog = CreateFile((LPCTSTR)bsFileLog, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
            FILE_ATTRIBUTE_NORMAL, NULL);
        if (hfLog != INVALID_HANDLE_VALUE) {
            bLog = TRUE;
        } else {
            hfLog = NULL;
        }
    }

    hr = _export_to_file(hfBinary, hfLog, bLog, secAt, sectors, bytesPre, bytesSuf);

    if (bLog) {
        CloseHandle(hfLog);
    }
    CloseHandle(hfBinary);

	return hr;
}

STDMETHODIMP CWin32DiskLD::ImportFromFile(IDiskAddress *StartAddr, BSTR BinaryFile, BSTR LogFile)
{
    BOOL bLog = FALSE;
    _bstr_t bsFileBinary(BinaryFile);
    HANDLE hfBinary;
    HANDLE hfLog = NULL;
    HRESULT hr;
    VARIANT_BOOL vb;
    BOOL b;

    if (!StartAddr || !BinaryFile) return E_INVALIDARG;

    if (m_hDevice == NULL) {
        ReportError(TEXT("Device not ready"));
        return E_FAIL;
    }

    hr = StartAddr->IsValid(&vb);
    ASSERT(SUCCEEDED(hr));
    if (!vb) return E_INVALIDARG;

    /*
        !! IMPORTANT !!
            Writing to the disk may destroy the opened file, and this may writing
            duplicated data to the specified disk. (overlapped)

            It's recommend to read all of the file into memory, and then do the
            writing work. (It may also too large to loaded into memory.)
    */
    hfBinary = CreateFile((LPCTSTR)bsFileBinary, GENERIC_READ, 0, NULL, OPEN_EXISTING,
        0, NULL);
    if (hfBinary == INVALID_HANDLE_VALUE) {
        ReportError(TEXT("Can't open binary file for reading."));
        return E_FAIL;
    }

    DWORD sizeBinary[2];
    sizeBinary[0] = ::GetFileSize(hfBinary, sizeBinary + 1);

    DWORD startAddr[2];
    DWORD endAddr[2];
    DWORD secAt, bytesPre, bytesSuf;
    LONG sectors;

    hr = StartAddr->get_LinearLow((long *)startAddr + 0);
    hr = StartAddr->get_LinearHigh((long *)startAddr + 1);
    *(U64 *)endAddr = (*(U64 *)startAddr) + (*(U64 *)sizeBinary);

    b = _split_range(startAddr[0], startAddr[1], endAddr[0], endAddr[1],
                     secAt, sectors, bytesPre, bytesSuf);
    if (!b) {
        ReportError(TEXT("Invalid range specified!"));
        return E_INVALIDARG;
    }


    if (LogFile) {
        _bstr_t bsFileLog(LogFile);
        hfLog = CreateFile((LPCTSTR)bsFileLog, GENERIC_READ, 0, NULL, OPEN_EXISTING,
            0, NULL);
        if (hfLog != INVALID_HANDLE_VALUE) {
            bLog = TRUE;
        } else {
            hfLog = NULL;
        }
    }

    hr = _import_from_file(hfBinary, hfLog, bLog, secAt, sectors, bytesPre, bytesSuf);

    if (bLog) {
        CloseHandle(hfLog);
    }
    CloseHandle(hfBinary);

    return hr;
}
