// CpTrans.h : main header file for the CPTRANS application
//

#if !defined(AFX_CPTRANS_H__143CDD53_8A2D_4731_ACE3_5612779A1855__INCLUDED_)
#define AFX_CPTRANS_H__143CDD53_8A2D_4731_ACE3_5612779A1855__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if defined(WIN32) || defined(_WINDOWS)

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCpTransApp:
// See CpTrans.cpp for the implementation of this class
//

class CCpTransApp : public CWinApp
{
public:
	CCpTransApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCpTransApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL OnIdle(LONG lCount);
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CCpTransApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CPTRANS_H__143CDD53_8A2D_4731_ACE3_5612779A1855__INCLUDED_)
