// oletrace_cfg.h : main header file for the OLETRACE_CFG application
//

#if !defined(AFX_OLETRACE_CFG_H__C9BD69E4_D11E_435C_B1EB_82C8AFB931C9__INCLUDED_)
#define AFX_OLETRACE_CFG_H__C9BD69E4_D11E_435C_B1EB_82C8AFB931C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COletrace_cfgApp:
// See oletrace_cfg.cpp for the implementation of this class
//

class COletrace_cfgApp : public CWinApp
{
public:
	COletrace_cfgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COletrace_cfgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COletrace_cfgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLETRACE_CFG_H__C9BD69E4_D11E_435C_B1EB_82C8AFB931C9__INCLUDED_)
