// XMLViewer.h : main header file for the XMLVIEWER application
//

#if !defined(AFX_XMLVIEWER_H__6E4B927C_F9FB_48FF_BBEB_FE7BB444DE01__INCLUDED_)
#define AFX_XMLVIEWER_H__6E4B927C_F9FB_48FF_BBEB_FE7BB444DE01__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CXMLViewerApp:
// See XMLViewer.cpp for the implementation of this class
//

class CXMLViewerApp : public CWinApp
{
public:
	CXMLViewerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXMLViewerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CXMLViewerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XMLVIEWER_H__6E4B927C_F9FB_48FF_BBEB_FE7BB444DE01__INCLUDED_)
