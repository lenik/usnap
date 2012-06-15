// light.h : main header file for the LIGHT application
//

#if !defined(AFX_LIGHT_H__36C079A4_C040_11D3_8ACD_484C0001E209__INCLUDED_)
#define AFX_LIGHT_H__36C079A4_C040_11D3_8ACD_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLightApp:
// See light.cpp for the implementation of this class
//

class CLightApp : public CWinApp
{
public:
	CLightApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLightApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CLightApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIGHT_H__36C079A4_C040_11D3_8ACD_484C0001E209__INCLUDED_)
