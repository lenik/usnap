// SComp_Client.h : main header file for the SCOMP_CLIENT application
//

#if !defined(AFX_SCOMP_CLIENT_H__10AE33E6_221C_4B68_9667_97255E1E1C8D__INCLUDED_)
#define AFX_SCOMP_CLIENT_H__10AE33E6_221C_4B68_9667_97255E1E1C8D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSComp_ClientApp:
// See SComp_Client.cpp for the implementation of this class
//

class CSComp_ClientApp : public CWinApp
{
public:
	CSComp_ClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSComp_ClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSComp_ClientApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCOMP_CLIENT_H__10AE33E6_221C_4B68_9667_97255E1E1C8D__INCLUDED_)
