// CeE3DAux_Client2.h : main header file for the CEE3DAUX_CLIENT2 application
//

#if !defined(AFX_CEE3DAUX_CLIENT2_H__DD4FF283_2F21_4E47_9358_9F1760635353__INCLUDED_)
#define AFX_CEE3DAUX_CLIENT2_H__DD4FF283_2F21_4E47_9358_9F1760635353__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCeE3DAux_Client2App:
// See CeE3DAux_Client2.cpp for the implementation of this class
//

class CCeE3DAux_Client2App : public CWinApp
{
public:
	CCeE3DAux_Client2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCeE3DAux_Client2App)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
protected:
	HMENU m_hMDIMenu;
	HACCEL m_hMDIAccel;

public:
	//{{AFX_MSG(CCeE3DAux_Client2App)
	afx_msg void OnAppAbout();
	afx_msg void OnFileNew();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CEE3DAUX_CLIENT2_H__DD4FF283_2F21_4E47_9358_9F1760635353__INCLUDED_)
