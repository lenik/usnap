// CMine.h : main header file for the CMINE application
//

#if !defined(AFX_CMINE_H__0D74FD1E_4B67_45CA_ADF8_D084C8B8F37F__INCLUDED_)
#define AFX_CMINE_H__0D74FD1E_4B67_45CA_ADF8_D084C8B8F37F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCMineApp:
// See CMine.cpp for the implementation of this class
//

class CCMineApp : public CWinApp
{
public:
	CCMineApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCMineApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCMineApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMINE_H__0D74FD1E_4B67_45CA_ADF8_D084C8B8F37F__INCLUDED_)
