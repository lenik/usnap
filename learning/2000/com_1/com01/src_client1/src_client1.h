// src_client1.h : main header file for the SRC_CLIENT1 application
//

#if !defined(AFX_SRC_CLIENT1_H__7A2FF8D0_C21E_4341_B28F_B000CA3B4B68__INCLUDED_)
#define AFX_SRC_CLIENT1_H__7A2FF8D0_C21E_4341_B28F_B000CA3B4B68__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

#include "inproc_src.h"

/////////////////////////////////////////////////////////////////////////////
// CSrc_client1App:
// See src_client1.cpp for the implementation of this class
//

class CSrc_client1App : public CWinApp
{
public:
	CSrc_client1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSrc_client1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSrc_client1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SRC_CLIENT1_H__7A2FF8D0_C21E_4341_B28F_B000CA3B4B68__INCLUDED_)
