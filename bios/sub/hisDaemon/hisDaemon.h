// hisDaemon.h : main header file for the HISDAEMON DLL
//

#if !defined(AFX_HISDAEMON_H__209ED979_0623_40DC_9321_03A2042B98A0__INCLUDED_)
#define AFX_HISDAEMON_H__209ED979_0623_40DC_9321_03A2042B98A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

#include "MainDialog.h"

/////////////////////////////////////////////////////////////////////////////
// CHisDaemonApp
// See hisDaemon.cpp for the implementation of this class
//

class CHisDaemonApp : public CWinApp
{
public:
	CHisDaemonApp();
public:
	CMainDialog m_main;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHisDaemonApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL InitApplication();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CHisDaemonApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISDAEMON_H__209ED979_0623_40DC_9321_03A2042B98A0__INCLUDED_)
