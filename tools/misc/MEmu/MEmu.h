// MEmu.h : main header file for the MEMU application
//

#if !defined(AFX_MEMU_H__A3E699A3_C028_11D3_82DD_A0694CF2D1D4__INCLUDED_)
#define AFX_MEMU_H__A3E699A3_C028_11D3_82DD_A0694CF2D1D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMEmuApp:
// See MEmu.cpp for the implementation of this class
//

class CMEmuApp : public CWinApp
{
public:
	CMEmuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMEmuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMEmuApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEMU_H__A3E699A3_C028_11D3_82DD_A0694CF2D1D4__INCLUDED_)
