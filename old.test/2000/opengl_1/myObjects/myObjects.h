// myObjects.h : main header file for the MYOBJECTS application
//

#if !defined(AFX_MYOBJECTS_H__B6A71EC4_C087_11D3_8ACC_484C0001E209__INCLUDED_)
#define AFX_MYOBJECTS_H__B6A71EC4_C087_11D3_8ACC_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyObjectsApp:
// See myObjects.cpp for the implementation of this class
//

class CMyObjectsApp : public CWinApp
{
public:
	CMyObjectsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyObjectsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMyObjectsApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYOBJECTS_H__B6A71EC4_C087_11D3_8ACC_484C0001E209__INCLUDED_)
