// docview.h : main header file for the DOCVIEW application
//

#if !defined(AFX_DOCVIEW_H__2AFBD064_C07C_11D3_8D4E_BBF47FF1F969__INCLUDED_)
#define AFX_DOCVIEW_H__2AFBD064_C07C_11D3_8D4E_BBF47FF1F969__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDocviewApp:
// See docview.cpp for the implementation of this class
//

class CDocviewApp : public CWinApp
{
public:
	CDocviewApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDocviewApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDocviewApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOCVIEW_H__2AFBD064_C07C_11D3_8D4E_BBF47FF1F969__INCLUDED_)
