// dhtml_client1.h : main header file for the DHTML_CLIENT1 application
//

#if !defined(AFX_DHTML_CLIENT1_H__3E5D4CD2_EE3B_4FFE_A1EA_87313A77AE4F__INCLUDED_)
#define AFX_DHTML_CLIENT1_H__3E5D4CD2_EE3B_4FFE_A1EA_87313A77AE4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDhtml_client1App:
// See dhtml_client1.cpp for the implementation of this class
//

class CDhtml_client1App : public CWinApp
{
public:
	CDhtml_client1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDhtml_client1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDhtml_client1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DHTML_CLIENT1_H__3E5D4CD2_EE3B_4FFE_A1EA_87313A77AE4F__INCLUDED_)
