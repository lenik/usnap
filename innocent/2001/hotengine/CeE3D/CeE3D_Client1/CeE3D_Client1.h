// CeE3D_Client1.h : main header file for the CEE3D_CLIENT1 application
//

#if !defined(AFX_CEE3D_CLIENT1_H__AE9023CE_25D4_4E53_A233_8E387DA1A726__INCLUDED_)
#define AFX_CEE3D_CLIENT1_H__AE9023CE_25D4_4E53_A233_8E387DA1A726__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCeE3D_Client1App:
// See CeE3D_Client1.cpp for the implementation of this class
//

class CCeE3D_Client1App : public CWinApp
{
public:
	CCeE3D_Client1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCeE3D_Client1App)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	COleTemplateServer m_server;
	//{{AFX_MSG(CCeE3D_Client1App)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CEE3D_CLIENT1_H__AE9023CE_25D4_4E53_A233_8E387DA1A726__INCLUDED_)
