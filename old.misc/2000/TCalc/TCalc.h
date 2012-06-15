// TCalc.h : main header file for the TCALC application
//

#if !defined(AFX_TCALC_H__FE2965B7_C032_11D3_8D55_D0657801DC47__INCLUDED_)
#define AFX_TCALC_H__FE2965B7_C032_11D3_8D55_D0657801DC47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTCalcApp:
// See TCalc.cpp for the implementation of this class
//

class CTCalcApp : public CWinApp
{
public:
	CTCalcApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTCalcApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTCalcApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCALC_H__FE2965B7_C032_11D3_8D55_D0657801DC47__INCLUDED_)
