// visplug.h : main header file for the VISPLUG DLL
//

#if !defined(AFX_VISPLUG_H__AFE2E288_A0D0_11D3_85AA_5254AB163CA9__INCLUDED_)
#define AFX_VISPLUG_H__AFE2E288_A0D0_11D3_85AA_5254AB163CA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CVisplugApp
// See visplug.cpp for the implementation of this class
//

class CVisplugApp : public CWinApp
{
public:
	CVisplugApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVisplugApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CVisplugApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VISPLUG_H__AFE2E288_A0D0_11D3_85AA_5254AB163CA9__INCLUDED_)
