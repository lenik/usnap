// TTF2AEF.h : main header file for the TTF2AEF application
//

#if !defined(AFX_TTF2AEF_H__3AB079C4_760E_4428_854A_10771C8493F9__INCLUDED_)
#define AFX_TTF2AEF_H__3AB079C4_760E_4428_854A_10771C8493F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTTF2AEFApp:
// See TTF2AEF.cpp for the implementation of this class
//

class CTTF2AEFApp : public CWinApp
{
public:
	CTTF2AEFApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTTF2AEFApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTTF2AEFApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TTF2AEF_H__3AB079C4_760E_4428_854A_10771C8493F9__INCLUDED_)
