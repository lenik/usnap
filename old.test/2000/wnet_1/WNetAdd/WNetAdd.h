// WNetAdd.h : main header file for the WNETADD application
//

#if !defined(AFX_WNETADD_H__C5E3AA47_18EB_11D4_B811_000021DBCE3F__INCLUDED_)
#define AFX_WNETADD_H__C5E3AA47_18EB_11D4_B811_000021DBCE3F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWNetAddApp:
// See WNetAdd.cpp for the implementation of this class
//

class CWNetAddApp : public CWinApp
{
public:
	CWNetAddApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWNetAddApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWNetAddApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WNETADD_H__C5E3AA47_18EB_11D4_B811_000021DBCE3F__INCLUDED_)
