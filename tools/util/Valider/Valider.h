// Valider.h : main header file for the VALIDER application
//

#if !defined(AFX_VALIDER_H__CCC6E037_9C07_49B7_8FCA_694AB0C5EB4A__INCLUDED_)
#define AFX_VALIDER_H__CCC6E037_9C07_49B7_8FCA_694AB0C5EB4A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CValiderApp:
// See Valider.cpp for the implementation of this class
//

class CValiderApp : public CWinApp
{
public:
	CValiderApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CValiderApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CValiderApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VALIDER_H__CCC6E037_9C07_49B7_8FCA_694AB0C5EB4A__INCLUDED_)
