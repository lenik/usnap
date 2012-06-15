// __TB_Data.h : main header file for the __TB_DATA application
//

#if !defined(AFX___TB_DATA_H__5DDEEDEB_F823_497F_BC98_D66B931282E4__INCLUDED_)
#define AFX___TB_DATA_H__5DDEEDEB_F823_497F_BC98_D66B931282E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// C__TB_DataApp:
// See __TB_Data.cpp for the implementation of this class
//

class C__TB_DataApp : public CWinApp
{
public:
	C__TB_DataApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(C__TB_DataApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	COleTemplateServer m_server;
		// Server object for document creation
	//{{AFX_MSG(C__TB_DataApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX___TB_DATA_H__5DDEEDEB_F823_497F_BC98_D66B931282E4__INCLUDED_)
