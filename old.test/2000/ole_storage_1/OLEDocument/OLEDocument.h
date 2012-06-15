// OLEDocument.h : main header file for the OLEDOCUMENT application
//

#if !defined(AFX_OLEDOCUMENT_H__BF3399B2_7882_4D9A_8368_68E806F060D1__INCLUDED_)
#define AFX_OLEDOCUMENT_H__BF3399B2_7882_4D9A_8368_68E806F060D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COLEDocumentApp:
// See OLEDocument.cpp for the implementation of this class
//

class COLEDocumentApp : public CWinApp
{
public:
	COLEDocumentApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COLEDocumentApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(COLEDocumentApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDOCUMENT_H__BF3399B2_7882_4D9A_8368_68E806F060D1__INCLUDED_)
