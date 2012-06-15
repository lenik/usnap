// MyFirst.h : main header file for the MYFIRST DLL
//

#if !defined(AFX_MYFIRST_H__16B894CA_7649_4F71_8978_1F02B6495199__INCLUDED_)
#define AFX_MYFIRST_H__16B894CA_7649_4F71_8978_1F02B6495199__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyFirstApp
// See MyFirst.cpp for the implementation of this class
//

class CMyFirstApp : public CWinApp
{
public:
	CMyFirstApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyFirstApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CMyFirstApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYFIRST_H__16B894CA_7649_4F71_8978_1F02B6495199__INCLUDED_)
