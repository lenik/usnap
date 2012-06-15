// mfc03.h : main header file for the MFC03 application
//

#if !defined(AFX_MFC03_H__EF599184_C069_11D3_8D4D_DAABAC64C44E__INCLUDED_)
#define AFX_MFC03_H__EF599184_C069_11D3_8D4D_DAABAC64C44E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMfc03App:
// See mfc03.cpp for the implementation of this class
//

class CMfc03App : public CWinApp
{
public:
	CMfc03App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMfc03App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CMfc03App)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC03_H__EF599184_C069_11D3_8D4D_DAABAC64C44E__INCLUDED_)
