// ComBook.h : main header file for the COMBOOK application
//

#if !defined(AFX_COMBOOK_H__EB2B9784_C022_11D3_8D4F_E2E9095ED3EF__INCLUDED_)
#define AFX_COMBOOK_H__EB2B9784_C022_11D3_8D4F_E2E9095ED3EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CComBookApp:
// See ComBook.cpp for the implementation of this class
//

class CComBookApp : public CWinApp
{
public:
	CComBookApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComBookApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL OnIdle(LONG lCount);
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CComBookApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOOK_H__EB2B9784_C022_11D3_8D4F_E2E9095ED3EF__INCLUDED_)
