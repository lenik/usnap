// dv01.h : main header file for the DV01 application
//

#if !defined(AFX_DV01_H__2AFBD093_C07C_11D3_8D4E_BBF47FF1F969__INCLUDED_)
#define AFX_DV01_H__2AFBD093_C07C_11D3_8D4E_BBF47FF1F969__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDv01App:
// See dv01.cpp for the implementation of this class
//

class CDv01App : public CWinApp
{
public:
	CDv01App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDv01App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDv01App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DV01_H__2AFBD093_C07C_11D3_8D4E_BBF47FF1F969__INCLUDED_)
