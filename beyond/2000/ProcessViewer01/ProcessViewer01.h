// ProcessViewer01.h : main header file for the PROCESSVIEWER01 application
//

#if !defined(AFX_PROCESSVIEWER01_H__32350918_C08B_11D3_8D8B_9B78F2ACB14A__INCLUDED_)
#define AFX_PROCESSVIEWER01_H__32350918_C08B_11D3_8D8B_9B78F2ACB14A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

int GetProcessList(CListBox *lb);
int GetProcessList(CComboBox *lb);
int GetModuleList(CListBox *lb, DWORD idProcess);

/////////////////////////////////////////////////////////////////////////////
// CProcessViewer01App:
// See ProcessViewer01.cpp for the implementation of this class
//

class CProcessViewer01App : public CWinApp
{
public:
	CProcessViewer01App();
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProcessViewer01App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CProcessViewer01App)
	afx_msg void OnAppAbout();
	afx_msg void OnVmodule();
	afx_msg void OnVprocess();
	afx_msg void OnVthread();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROCESSVIEWER01_H__32350918_C08B_11D3_8D8B_9B78F2ACB14A__INCLUDED_)
