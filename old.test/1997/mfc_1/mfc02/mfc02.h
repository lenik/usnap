// mfc02.h : main header file for the MFC02 application
//

#if !defined(AFX_MFC02_H__1887E264_C0D2_11D3_8D62_B2EC4A9FD45A__INCLUDED_)
#define AFX_MFC02_H__1887E264_C0D2_11D3_8D62_B2EC4A9FD45A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMfc02App:
// See mfc02.cpp for the implementation of this class
//

class CMfc02App : public CWinApp
{
public:
	CMfc02App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMfc02App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMfc02App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC02_H__1887E264_C0D2_11D3_8D62_B2EC4A9FD45A__INCLUDED_)
