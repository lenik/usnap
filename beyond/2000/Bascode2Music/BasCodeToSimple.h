// BasCodeToSimple.h : main header file for the BASCODETOSIMPLE application
//

#if !defined(AFX_BASCODETOSIMPLE_H__0E618646_C052_11D3_8DBB_FE025B14AD4C__INCLUDED_)
#define AFX_BASCODETOSIMPLE_H__0E618646_C052_11D3_8DBB_FE025B14AD4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBasCodeToSimpleApp:
// See BasCodeToSimple.cpp for the implementation of this class
//

class CBasCodeToSimpleApp : public CWinApp
{
public:
	CBasCodeToSimpleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBasCodeToSimpleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CBasCodeToSimpleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASCODETOSIMPLE_H__0E618646_C052_11D3_8DBB_FE025B14AD4C__INCLUDED_)
