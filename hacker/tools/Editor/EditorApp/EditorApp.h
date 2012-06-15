// EditorApp.h : main header file for the EDITORAPP application
//

#if !defined(AFX_EDITORAPP_H__C7823BB8_41FC_4613_B329_8FBE9858415D__INCLUDED_)
#define AFX_EDITORAPP_H__C7823BB8_41FC_4613_B329_8FBE9858415D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEditorAppApp:
// See EditorApp.cpp for the implementation of this class
//

class CEditorAppApp : public CWinApp
{
public:
	CEditorAppApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditorAppApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	COleTemplateServer m_server;
		// Server object for document creation
	//{{AFX_MSG(CEditorAppApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITORAPP_H__C7823BB8_41FC_4613_B329_8FBE9858415D__INCLUDED_)
