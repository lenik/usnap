// OServer1.h : main header file for the OSERVER1 application
//

#if !defined(AFX_OSERVER1_H__46CE726C_033C_4647_8D9B_E829A49F9AAB__INCLUDED_)
#define AFX_OSERVER1_H__46CE726C_033C_4647_8D9B_E829A49F9AAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COServer1App:
// See OServer1.cpp for the implementation of this class
//

class COServer1App : public CWinApp
{
public:
	COServer1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COServer1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	COleTemplateServer m_server;
		// Server object for document creation
	//{{AFX_MSG(COServer1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OSERVER1_H__46CE726C_033C_4647_8D9B_E829A49F9AAB__INCLUDED_)
