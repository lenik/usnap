// MyMove.h : main header file for the MYMOVE application
//

#if !defined(AFX_MYMOVE_H__9F94AAD9_06DA_4E19_B086_B703ACDC5682__INCLUDED_)
#define AFX_MYMOVE_H__9F94AAD9_06DA_4E19_B086_B703ACDC5682__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyMoveApp:
// See MyMove.cpp for the implementation of this class
//

class CMyMoveApp : public CWinApp
{
public:
	CMyMoveApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyMoveApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CMyMoveApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMOVE_H__9F94AAD9_06DA_4E19_B086_B703ACDC5682__INCLUDED_)
