// YaeConf.h : main header file for the YAECONF application
//

#if !defined(AFX_YAECONF_H__2C354E49_5F77_499D_96D4_5C87F4DF8D46__INCLUDED_)
#define AFX_YAECONF_H__2C354E49_5F77_499D_96D4_5C87F4DF8D46__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CYaeConfApp:
// See YaeConf.cpp for the implementation of this class
//

class CYaeConfApp : public CWinApp
{
public:
	CYaeConfApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CYaeConfApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CYaeConfApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_YAECONF_H__2C354E49_5F77_499D_96D4_5C87F4DF8D46__INCLUDED_)
