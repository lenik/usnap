// FragmentsColumn.h : Declaration of the CFragmentsColumn

#pragma once
#include "resource.h"       // main symbols

#include <shlobj.h>

#include "winexmagicinfo.h"

#include <map>
#include <list>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

#define MAX_MAGICS 256
#define MAXBLOCK	32

// CFragmentsColumn

class ATL_NO_VTABLE CFragmentsColumn :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFragmentsColumn, &CLSID_FragmentsColumn>,
	public IDispatchImpl<IFragmentsColumn, &IID_IFragmentsColumn, &LIBID_WinexMagicInfo, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IDispatchImpl<IColumnProvider, &IID_IColumnProvider, &LIBID_Shell32, /* wMajor = */ 1>
	//public IDispatchImpl<IShellLinkDual, &__uuidof(IShellLinkDual), &LIBID_Shell32, /* wMajor = */ 1>
{
public:
	CFragmentsColumn()
	{
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_FRAGMENTSCOLUMN)

	BEGIN_COM_MAP(CFragmentsColumn)
		COM_INTERFACE_ENTRY(IFragmentsColumn)
		COM_INTERFACE_ENTRY_IID(IID_IColumnProvider, IColumnProvider)
		COM_INTERFACE_ENTRY(IDispatch)
	END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		memset(m_bAlwaysShow, 0, sizeof(m_bAlwaysShow));
		lstrcpy(m_titles[0], TEXT("Header Frag"));
		lstrcpy(m_titles[1], TEXT("Footer Frag"));
		lstrcpy(m_titles[2], TEXT("Magic"));
		m_headerSize = 4;
		m_footerSize = 4;
		m_magics = 0;
		memset(headerMaskLen, 0, sizeof(headerMaskLen));
		memset(footerMaskLen, 0, sizeof(footerMaskLen));
		return S_OK;
	}

	void FinalRelease()
	{
		for (int i = 0; i < m_magics; i++)
			free(flagChars[i]);
	}

private:
	TCHAR m_titles[10][100]; // MAXTITLESIZE
	int m_bAlwaysShow[10];

	int m_headerSize;
	int m_footerSize;
	int m_magics;

	TCHAR *flagChars[MAX_MAGICS];
	int headerMaskLen[MAX_MAGICS];
	int footerMaskLen[MAX_MAGICS];
	BYTE headerMask[MAX_MAGICS][MAXBLOCK];
	BYTE footerMask[MAX_MAGICS][MAXBLOCK];

public:
    STDMETHOD (Initialize)(LPCSHCOLUMNINIT psci);
    STDMETHOD (GetColumnInfo)(DWORD dwIndex, SHCOLUMNINFO *psci);
    STDMETHOD (GetItemData)(LPCSHCOLUMNID pscid, LPCSHCOLUMNDATA pscd, VARIANT *pvarData);

public:
	STDMETHOD(init)(void);
};

OBJECT_ENTRY_AUTO(__uuidof(FragmentsColumn), CFragmentsColumn)
