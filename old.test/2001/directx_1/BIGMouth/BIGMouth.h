// BIGMouth.h : main header file for the BIGMOUTH application
//

#if !defined(AFX_BIGMOUTH_H__1FBB47E6_C08F_11D3_8DAF_FB36D2B758C6__INCLUDED_)
#define AFX_BIGMOUTH_H__1FBB47E6_C08F_11D3_8DAF_FB36D2B758C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBIGMouthApp:
// See BIGMouth.cpp for the implementation of this class
//

class CBIGMouthApp : public CWinApp
{
public:
	CBIGMouthApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBIGMouthApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBIGMouthApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BIGMOUTH_H__1FBB47E6_C08F_11D3_8DAF_FB36D2B758C6__INCLUDED_)
