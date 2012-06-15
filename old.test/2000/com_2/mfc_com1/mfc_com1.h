// mfc_com1.h : main header file for the MFC_COM1 application
//

#if !defined(AFX_MFC_COM1_H__D260AFAE_4F05_4DF2_AC05_AA6EA3DA7CA6__INCLUDED_)
#define AFX_MFC_COM1_H__D260AFAE_4F05_4DF2_AC05_AA6EA3DA7CA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMfc_com1App:
// See mfc_com1.cpp for the implementation of this class
//

class CMfc_com1App : public CWinApp
{
public:
	CMfc_com1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMfc_com1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CMfc_com1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_COM1_H__D260AFAE_4F05_4DF2_AC05_AA6EA3DA7CA6__INCLUDED_)
