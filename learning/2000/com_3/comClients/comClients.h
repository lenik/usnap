// comClients.h : main header file for the COMCLIENTS application
//

#if !defined(AFX_COMCLIENTS_H__2D4FCC2D_63AA_4EE7_8986_979ECBC0AC59__INCLUDED_)
#define AFX_COMCLIENTS_H__2D4FCC2D_63AA_4EE7_8986_979ECBC0AC59__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CComClientsApp:
// See comClients.cpp for the implementation of this class
//

class CComClientsApp : public CWinApp
{
public:
	CComClientsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComClientsApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CComClientsApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMCLIENTS_H__2D4FCC2D_63AA_4EE7_8986_979ECBC0AC59__INCLUDED_)
