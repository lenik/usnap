// sockTalk.h : main header file for the SOCKTALK application
//

#if !defined(AFX_SOCKTALK_H__DDE6D8A8_4B05_4B33_80E7_51FDA3EBD9FA__INCLUDED_)
#define AFX_SOCKTALK_H__DDE6D8A8_4B05_4B33_80E7_51FDA3EBD9FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSockTalkApp:
// See sockTalk.cpp for the implementation of this class
//

class CSockTalkApp : public CWinApp
{
public:
	CSockTalkApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSockTalkApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSockTalkApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOCKTALK_H__DDE6D8A8_4B05_4B33_80E7_51FDA3EBD9FA__INCLUDED_)
