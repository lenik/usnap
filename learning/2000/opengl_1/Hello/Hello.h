// Hello.h : main header file for the HELLO application
//

#if !defined(AFX_HELLO_H__DF6EA7E6_C089_11D3_8AC9_484C0001E209__INCLUDED_)
#define AFX_HELLO_H__DF6EA7E6_C089_11D3_8AC9_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CHelloApp:
// See Hello.cpp for the implementation of this class
//

class CHelloApp : public CWinApp
{
public:
	CHelloApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHelloApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CHelloApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HELLO_H__DF6EA7E6_C089_11D3_8AC9_484C0001E209__INCLUDED_)
