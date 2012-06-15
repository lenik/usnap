// Drawer.h : main header file for the DRAWER application
//

#if !defined(AFX_DRAWER_H__168DAB23_5662_48CA_932B_234C3C385117__INCLUDED_)
#define AFX_DRAWER_H__168DAB23_5662_48CA_932B_234C3C385117__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDrawerApp:
// See Drawer.cpp for the implementation of this class
//

class CDrawerApp : public CWinApp
{
public:
	CDrawerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDrawerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWER_H__168DAB23_5662_48CA_932B_234C3C385117__INCLUDED_)
