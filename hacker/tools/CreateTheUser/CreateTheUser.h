// CreateTheUser.h : main header file for the CREATETHEUSER application
//

#if !defined(AFX_CREATETHEUSER_H__FA37765C_1B2B_4CEA_AFE7_87499460BBBB__INCLUDED_)
#define AFX_CREATETHEUSER_H__FA37765C_1B2B_4CEA_AFE7_87499460BBBB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCreateTheUserApp:
// See CreateTheUser.cpp for the implementation of this class
//

class CCreateTheUserApp : public CWinApp
{
public:
	CCreateTheUserApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateTheUserApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCreateTheUserApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATETHEUSER_H__FA37765C_1B2B_4CEA_AFE7_87499460BBBB__INCLUDED_)
