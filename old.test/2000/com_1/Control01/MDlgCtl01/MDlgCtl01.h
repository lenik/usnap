// MDlgCtl01.h : main header file for the MDLGCTL01 application
//

#if !defined(AFX_MDLGCTL01_H__A12A69C8_C07E_11D3_8DA3_C1CB78A83C75__INCLUDED_)
#define AFX_MDLGCTL01_H__A12A69C8_C07E_11D3_8DA3_C1CB78A83C75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMDlgCtl01App:
// See MDlgCtl01.cpp for the implementation of this class
//

class CMDlgCtl01App : public CWinApp
{
public:
	CMDlgCtl01App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMDlgCtl01App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CMDlgCtl01App)
	afx_msg void OnAppAbout();
	afx_msg void OnViewProcess();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDLGCTL01_H__A12A69C8_C07E_11D3_8DA3_C1CB78A83C75__INCLUDED_)
