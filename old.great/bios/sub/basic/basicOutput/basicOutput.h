// basicOutput.h : main header file for the BASICOUTPUT DLL
//

#if !defined(AFX_BASICOUTPUT_H__2E9A7090_5D3A_4886_BA4B_C38055C29E9E__INCLUDED_)
#define AFX_BASICOUTPUT_H__2E9A7090_5D3A_4886_BA4B_C38055C29E9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

#include "OutputDialog.h"

/////////////////////////////////////////////////////////////////////////////
// CBasicOutputApp
// See basicOutput.cpp for the implementation of this class
//

class CBasicOutputApp : public CWinApp
{
public:
	CBasicOutputApp();
public:
	COutputDialog m_output;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBasicOutputApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CBasicOutputApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASICOUTPUT_H__2E9A7090_5D3A_4886_BA4B_C38055C29E9E__INCLUDED_)
