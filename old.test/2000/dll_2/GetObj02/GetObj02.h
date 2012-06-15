// GetObj02.h : main header file for the GETOBJ02 application
//

#if !defined(AFX_GETOBJ02_H__8D28F5A3_C01E_11D3_8D85_8FD4D4D70349__INCLUDED_)
#define AFX_GETOBJ02_H__8D28F5A3_C01E_11D3_8D85_8FD4D4D70349__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "MouseHook.h"	// Added by ClassView

/////////////////////////////////////////////////////////////////////////////
// CGetObj02App:
// See GetObj02.cpp for the implementation of this class
//

class CGetObj02App : public CWinApp
{
public:
	CGetObj02App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetObj02App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CGetObj02App)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETOBJ02_H__8D28F5A3_C01E_11D3_8D85_8FD4D4D70349__INCLUDED_)
