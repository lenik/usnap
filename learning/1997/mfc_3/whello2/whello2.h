// whello2.h : main header file for the WHELLO2 application
//

#if !defined(AFX_WHELLO2_H__196D92B3_C07E_11D3_8D63_A9A308238194__INCLUDED_)
#define AFX_WHELLO2_H__196D92B3_C07E_11D3_8D63_A9A308238194__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CWhello2App:
// See whello2.cpp for the implementation of this class
//

class CWhello2App : public CWinApp
{
public:
	CWhello2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWhello2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CWhello2App)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WHELLO2_H__196D92B3_C07E_11D3_8D63_A9A308238194__INCLUDED_)
