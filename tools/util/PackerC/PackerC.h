// PackerC.h : main header file for the PACKERC application
//

#if !defined(AFX_PACKERC_H__69E50388_539A_419F_90BD_864283CB197F__INCLUDED_)
#define AFX_PACKERC_H__69E50388_539A_419F_90BD_864283CB197F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPackerCApp:
// See PackerC.cpp for the implementation of this class
//

class CPackerCApp : public CWinApp
{
public:
	CPackerCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPackerCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPackerCApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PACKERC_H__69E50388_539A_419F_90BD_864283CB197F__INCLUDED_)
