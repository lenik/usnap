// scomp2_client2.h : main header file for the SCOMP2_CLIENT2 application
//

#if !defined(AFX_SCOMP2_CLIENT2_H__59EF081B_4AFC_425C_B939_75585147382A__INCLUDED_)
#define AFX_SCOMP2_CLIENT2_H__59EF081B_4AFC_425C_B939_75585147382A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CScomp2_client2App:
// See scomp2_client2.cpp for the implementation of this class
//

class CScomp2_client2App : public CWinApp
{
public:
	CScomp2_client2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScomp2_client2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CScomp2_client2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCOMP2_CLIENT2_H__59EF081B_4AFC_425C_B939_75585147382A__INCLUDED_)
