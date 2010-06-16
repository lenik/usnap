// WM.h : main header file for the WM application
//

#if !defined(AFX_WM_H__87EF5F23_31D6_461B_80EE_9686CB6647E4__INCLUDED_)
#define AFX_WM_H__87EF5F23_31D6_461B_80EE_9686CB6647E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWMApp:
// See WM.cpp for the implementation of this class
//

class CWMApp : public CWinApp
{
public:
	CWMApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWMApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWMApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WM_H__87EF5F23_31D6_461B_80EE_9686CB6647E4__INCLUDED_)
