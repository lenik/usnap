// LightDemo.h : main header file for the LIGHTDEMO application
//

#if !defined(AFX_LIGHTDEMO_H__4BA31B44_C07A_11D3_8AD1_484C0001E209__INCLUDED_)
#define AFX_LIGHTDEMO_H__4BA31B44_C07A_11D3_8AD1_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLightDemoApp:
// See LightDemo.cpp for the implementation of this class
//

class CLightDemoApp : public CWinApp
{
public:
	CLightDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLightDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CLightDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIGHTDEMO_H__4BA31B44_C07A_11D3_8AD1_484C0001E209__INCLUDED_)
