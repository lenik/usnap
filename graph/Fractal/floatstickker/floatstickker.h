// floatstickker.h : main header file for the FLOATSTICKKER application
//

#if !defined(AFX_FLOATSTICKKER_H__5C81A498_9F79_4803_BA30_E3DAD7429C0E__INCLUDED_)
#define AFX_FLOATSTICKKER_H__5C81A498_9F79_4803_BA30_E3DAD7429C0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFloatstickkerApp:
// See floatstickker.cpp for the implementation of this class
//

class CFloatstickkerApp : public CWinApp
{
public:
	CFloatstickkerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFloatstickkerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CFloatstickkerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLOATSTICKKER_H__5C81A498_9F79_4803_BA30_E3DAD7429C0E__INCLUDED_)
