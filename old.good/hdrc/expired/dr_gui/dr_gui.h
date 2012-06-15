// dr_gui.h : main header file for the DR_GUI application
//

#if !defined(AFX_DR_GUI_H__FC12D925_17A4_42F7_9E29_378560F0BFD3__INCLUDED_)
#define AFX_DR_GUI_H__FC12D925_17A4_42F7_9E29_378560F0BFD3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDr_guiApp:
// See dr_gui.cpp for the implementation of this class
//

class CDr_guiApp : public CWinApp
{
public:
	CDr_guiApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDr_guiApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDr_guiApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DR_GUI_H__FC12D925_17A4_42F7_9E29_378560F0BFD3__INCLUDED_)
