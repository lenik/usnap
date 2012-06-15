// DSAddIn.h : header file
//

#if !defined(AFX_DSADDIN_H__9B95ACF6_3ACB_4129_A12C_5B4FCA4C4B40__INCLUDED_)
#define AFX_DSADDIN_H__9B95ACF6_3ACB_4129_A12C_5B4FCA4C4B40__INCLUDED_

#include "commands.h"

// {9D4A3BCB-61F5-443E-AEFA-807B27A07A6E}
DEFINE_GUID(CLSID_DSAddIn,
0x9d4a3bcb, 0x61f5, 0x443e, 0xae, 0xfa, 0x80, 0x7b, 0x27, 0xa0, 0x7a, 0x6e);

/////////////////////////////////////////////////////////////////////////////
// CDSAddIn

class CDSAddIn :
	public IDSAddIn,
	public CComObjectRoot,
	public CComCoClass<CDSAddIn, &CLSID_DSAddIn>
{
public:
	DECLARE_REGISTRY(CDSAddIn, "Addin1.DSAddIn.1",
		"ADDIN1 Developer Studio Add-in", IDS_ADDIN1_LONGNAME,
		THREADFLAGS_BOTH)

	CDSAddIn() {}
	BEGIN_COM_MAP(CDSAddIn)
		COM_INTERFACE_ENTRY(IDSAddIn)
	END_COM_MAP()
	DECLARE_NOT_AGGREGATABLE(CDSAddIn)

// IDSAddIns
public:
	STDMETHOD(OnConnection)(THIS_ IApplication* pApp, VARIANT_BOOL bFirstTime,
		long dwCookie, VARIANT_BOOL* OnConnection);
	STDMETHOD(OnDisconnection)(THIS_ VARIANT_BOOL bLastTime);

protected:
	CCommandsObj* m_pCommands;
	DWORD m_dwCookie;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DSADDIN_H__9B95ACF6_3ACB_4129_A12C_5B4FCA4C4B40__INCLUDED)
