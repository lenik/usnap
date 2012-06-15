// syntest.h : main header file for the SYNTEST application
//

#if !defined(AFX_SYNTEST_H__C7D9E0FE_F417_4152_9E4F_E577FAA19E08__INCLUDED_)
#define AFX_SYNTEST_H__C7D9E0FE_F417_4152_9E4F_E577FAA19E08__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSyntestApp:
// See syntest.cpp for the implementation of this class
//

class CSyntestApp : public CWinApp
{
public:
	CSyntestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSyntestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSyntestApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYNTEST_H__C7D9E0FE_F417_4152_9E4F_E577FAA19E08__INCLUDED_)
