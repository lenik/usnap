// basicInput.h : main header file for the BASICINPUT DLL
//

#if !defined(AFX_BASICINPUT_H__B6C5E553_9368_4B13_B704_1B62B678843D__INCLUDED_)
#define AFX_BASICINPUT_H__B6C5E553_9368_4B13_B704_1B62B678843D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

#include "InputDialog.h"

/////////////////////////////////////////////////////////////////////////////
// CBasicInputApp
// See basicInput.cpp for the implementation of this class
//

class CBasicInputApp : public CWinApp
{
public:
	CBasicInputApp();
public:
	CInputDialog m_input;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBasicInputApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CBasicInputApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASICINPUT_H__B6C5E553_9368_4B13_B704_1B62B678843D__INCLUDED_)
