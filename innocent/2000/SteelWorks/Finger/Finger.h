// Finger.h : main header file for the FINGER application
//

#if !defined(AFX_FINGER_H__1E33142B_1CEA_402E_82D3_DEAFBBB85334__INCLUDED_)
#define AFX_FINGER_H__1E33142B_1CEA_402E_82D3_DEAFBBB85334__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFingerApp:
// See Finger.cpp for the implementation of this class
//

class CFingerApp : public CWinApp
{
public:
	CFingerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFingerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CFingerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINGER_H__1E33142B_1CEA_402E_82D3_DEAFBBB85334__INCLUDED_)
