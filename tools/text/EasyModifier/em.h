// em.h : main header file for the EM application
//

#if !defined(AFX_EM_H__ECB9BFE5_C096_11D3_82DA_E142916ADDD3__INCLUDED_)
#define AFX_EM_H__ECB9BFE5_C096_11D3_82DA_E142916ADDD3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEmApp:
// See em.cpp for the implementation of this class
//

class CEmApp : public CWinApp
{
public:
	CEmApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEmApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EM_H__ECB9BFE5_C096_11D3_82DA_E142916ADDD3__INCLUDED_)
