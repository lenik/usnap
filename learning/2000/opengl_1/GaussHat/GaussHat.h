// GaussHat.h : main header file for the GAUSSHAT application
//

#if !defined(AFX_GAUSSHAT_H__7E343DC4_C03C_11D3_8ACB_484C0001E209__INCLUDED_)
#define AFX_GAUSSHAT_H__7E343DC4_C03C_11D3_8ACB_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGaussHatApp:
// See GaussHat.cpp for the implementation of this class
//

class CGaussHatApp : public CWinApp
{
public:
	CGaussHatApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGaussHatApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGaussHatApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAUSSHAT_H__7E343DC4_C03C_11D3_8ACB_484C0001E209__INCLUDED_)
