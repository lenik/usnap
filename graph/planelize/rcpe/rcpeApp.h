// rcpe.h : main header file for the RCPE application
//

#if !defined(AFX_RCPE_H__15D4469A_6D30_43A7_8146_E81CE4F96551__INCLUDED_)
#define AFX_RCPE_H__15D4469A_6D30_43A7_8146_E81CE4F96551__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRcpeApp:
// See rcpe.cpp for the implementation of this class
//

class CRcpeApp : public CWinApp
{
public:
	CRcpeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRcpeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CRcpeApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RCPE_H__15D4469A_6D30_43A7_8146_E81CE4F96551__INCLUDED_)
