// mfc02.h : main header file for the MFC02 application
//

#if !defined(AFX_MFC02_H__CC7C940B_C041_11D3_8D4C_9A9DB0902751__INCLUDED_)
#define AFX_MFC02_H__CC7C940B_C041_11D3_8D4C_9A9DB0902751__INCLUDED_

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
	virtual BOOL OnIdle(LONG lCount);
	//}}AFX_VIRTUAL

// Implementation

public:
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

#endif // !defined(AFX_MFC02_H__CC7C940B_C041_11D3_8D4C_9A9DB0902751__INCLUDED_)
