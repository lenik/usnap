// material.h : main header file for the MATERIAL application
//

#if !defined(AFX_MATERIAL_H__FA95CAE4_C06F_11D3_8ACD_484C0001E209__INCLUDED_)
#define AFX_MATERIAL_H__FA95CAE4_C06F_11D3_8ACD_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMaterialApp:
// See material.cpp for the implementation of this class
//

class CMaterialApp : public CWinApp
{
public:
	CMaterialApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMaterialApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMaterialApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MATERIAL_H__FA95CAE4_C06F_11D3_8ACD_484C0001E209__INCLUDED_)
