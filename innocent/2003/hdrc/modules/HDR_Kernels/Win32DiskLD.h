// Win32DiskLD.h : Declaration of the CWin32DiskLD

#ifndef __WIN32DISKLD_H_
#define __WIN32DISKLD_H_

#include "resource.h"       // main symbols

#include "ExtCache.h"
#include "HDR_KernelsCP.h"


enum LogControlCode {
    lccNull = 0,
    lccRecordMagic,             // the Magic is 'LCC '
    lccBadSector,
    lccIgnore,
    lccAll_00,
    lccAll_FF,
    lccPatch,
    lccRepeatLast,
};

struct LccRecord {
    LogControlCode lcc;
    struct _Magic {
        DWORD   Value;
    };
    struct _Range {
        DWORD   LBA;
        DWORD   Count;
    };
    struct _Patch {
        DWORD   LBA;
        short   Offset;
        short   PatchSize;
        LPBYTE  PatchData;
    };
    union {
        _Magic  Magic;
        _Range  Range;
        _Patch  Patch;
    };
};


/////////////////////////////////////////////////////////////////////////////
// CWin32DiskLD
class ATL_NO_VTABLE CWin32DiskLD :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CWin32DiskLD, &CLSID_Win32DiskLD>,
    public ISupportErrorInfo,
    public IConnectionPointContainerImpl<CWin32DiskLD>,
    public IDispatchImpl<ILDAccess, &IID_ILDAccess, &LIBID_HDR_KernelsLib>,
    public IDispatchImpl<ILDCache, &IID_ILDAccess, &LIBID_HDR_KernelsLib>,
    public IDispatchImpl<ILDLargeIO, &IID_ILDAccess, &LIBID_HDR_KernelsLib>,
    public IDispatchImpl<IWin32DiskLD, &IID_IWin32DiskLD, &LIBID_HDR_KernelsLib>,
    public CProxy_ILDLargeIOEvents< CWin32DiskLD >
{
public:
    CWin32DiskLD()
    {
        //m_bInited = FALSE;
        m_hDevice = NULL;
        m_szPath = NULL;
        m_offLow = 0;
        m_offHigh = 0;
	}
    ~CWin32DiskLD() {
        HRESULT hr;
        hr = Unbind();
        ASSERT(SUCCEEDED(hr));
    }

protected:
    //BOOL            m_bInited;

    // The Handle is NULL when not binded.
    HANDLE          m_hDevice;

    // The Win32 Device File Full-Path.
    LPCTSTR         m_szPath;

    /*
        BOOL            m_bCacheEnabled;

        DWORD           _m_pages_in_cache;

        // Each page-block's status stored as a byte in the cache.
        // So new blocks may substitute the useless ones.
        // The byte is allocated as:
        //      7 6 5 4 3 2 1 0
        //      | | | | |-----|
        //      | | | |  Count
        //      | | | +- Heavy I/O:     I/O takes much time.
        //      | | +- Lock:            Locked, and don't substitute it until unlocked.
        //      | +- Sync:              Synchronized, so the content is reliable. (Sync=0 when updating)
        //      +- Reserved.0
        LPBYTE          _m_pages_status;

        // The primary cache. Size is _m_pages_in_cache * 4K bytes.(8 sectors a page)
        LPBYTE          _m_cache;
    */

    ExternalCacheMgr m_Cache;

    DWORD           m_offLow;
    LONG            m_offHigh;

    CacheBlock *    _alloc_cache(DWORD _lba, DWORD _count_sectors, LPBYTE _data = NULL);
    CacheBlock *    _search_cache(DWORD _lba);
    BOOL            _uncache(DWORD _lba);
    BOOL            _uncache(CacheBlock *pBlock);

    HRESULT         _read_sector(DWORD _lba, DWORD *pIOErr = NULL);
    HRESULT         _write_sector(DWORD _lba, LPBYTE _data, DWORD *pIOErr = NULL);

    BOOL            _split_range(DWORD startLow, LONG startHigh, DWORD endLow, DWORD endHigh,
                                 DWORD& secAt, LONG& sectors,
                                 DWORD& bytesPre, DWORD& bytesSuf);

    LogControlCode  _lcc_input  (HANDLE hfLog, LccRecord *pRecord);
    LogControlCode  _lcc_input1 (HANDLE hfLog, DWORD *pLBA);
    BOOL            _lcc_output (HANDLE hfLog, LccRecord *pRecord);
    BOOL            _lcc_output1(HANDLE hfLog, LogControlCode lcc, DWORD LBA);

    HRESULT         _import_from_file(HANDLE hfBinary, HANDLE hfLog, BOOL bLog,
                                      DWORD secAt, LONG sectors, DWORD bytesPre, DWORD bytesSuf);
    HRESULT         _export_to_file(HANDLE hfBinary, HANDLE hfLog, BOOL bLog,
                                    DWORD secAt, LONG sectors, DWORD bytesPre, DWORD bytesSuf);

    BOOL            _process_errlog(DWORD dwError, HANDLE hfLog, DWORD LBA, DWORD Count);
    BOOL            _pad_bytes(HANDLE hf, DWORD cbBytes);

public:
DECLARE_REGISTRY_RESOURCEID(IDR_WIN32DISKLD)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CWin32DiskLD)
    COM_INTERFACE_ENTRY2(IDispatch, ILDAccess)
    COM_INTERFACE_ENTRY(ISupportErrorInfo)
    COM_INTERFACE_ENTRY(ILDAccess)
    COM_INTERFACE_ENTRY(ILDCache)
    COM_INTERFACE_ENTRY(ILDLargeIO)
    COM_INTERFACE_ENTRY(IWin32DiskLD)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
    COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CWin32DiskLD)
	CONNECTION_POINT_ENTRY(DIID__ILDLargeIOEvents)
END_CONNECTION_POINT_MAP()

// ISupportsErrorInfo
    STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);
	BOOL ReportError(LPCTSTR sDescription);
    DWORD ReportLastError();

public:
	STDMETHOD(Unbind)();
    STDMETHOD(BindToWin32Path)(/*[in]*/LPCTSTR szDevicePath, /*[out, retval]*/VARIANT_BOOL *ret);
	STDMETHOD(ImportFromFile)(/*[in]*/IDiskAddress *StartAddr, /*[in]*/BSTR BinaryFile, /*[in]*/BSTR LogFile);
	STDMETHOD(ExportToFile)(/*[in]*/IDiskAddress *StartAddr, /*[in]*/IDiskAddress *EndAddr, /*[in]*/BSTR BinaryFile, /*[in]*/BSTR LogFile);
    STDMETHOD(InvalidateCache)();
    STDMETHOD(SetCacheSize)(/*[in]*/long nSectors);
    STDMETHOD(GetPosition)(/*[out]*/long *LBA, /*[out]*/long *BytesOffset);
    STDMETHOD(Seek)(/*[in]*/long offLow, /*[in]*/long offHigh, /*[in]*/SeekRelationConstants Rel);
	STDMETHOD(Write)(/*[in]*/long cbSize, /*[in,size_is(cbSize)]*/BYTE *pbBuffer, /*[out,retval]*/long *pcbWritten);
	STDMETHOD(Read)(/*[in]*/long cbSize, /*[out,size_is(cbSize)]*/BYTE *pbBuffer, /*[out,retval]*/long *pcbRead);
    STDMETHOD(WriteSector)(/*[in]*/long LBA, /*[in]*/long nSectors, /*[in]*/BYTE *pBuffer, /*[out, retval]*/long *nWritten);
    STDMETHOD(ReadSector)(/*[in]*/long LBA, /*[in]*/long nSectors, /*[out]*/BYTE *pBuffer, /*[out, retval]*/long *nRead);

};

#endif //__WIN32DISKLD_H_
