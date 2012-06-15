// wmfview.h : main header file for the WMFVIEW application
//

#if !defined(AFX_WMFVIEW_H__419F15B1_1476_4C49_8AC0_5EE05FD4ECC7__INCLUDED_)
#define AFX_WMFVIEW_H__419F15B1_1476_4C49_8AC0_5EE05FD4ECC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CWmfviewApp:
// See wmfview.cpp for the implementation of this class
//

class CWmfviewApp : public CWinApp
{
public:
	CWmfviewApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWmfviewApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CWmfviewApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WMFVIEW_H__419F15B1_1476_4C49_8AC0_5EE05FD4ECC7__INCLUDED_)
