// bmfc02.h : main header file for the BMFC02 application
//

#if !defined(AFX_BMFC02_H__C825B0B8_C07B_11D3_8D67_9218F7A2469C__INCLUDED_)
#define AFX_BMFC02_H__C825B0B8_C07B_11D3_8D67_9218F7A2469C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBmfc02App:
// See bmfc02.cpp for the implementation of this class
//

class CBmfc02App : public CWinApp
{
public:
	CBmfc02App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmfc02App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CBmfc02App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMFC02_H__C825B0B8_C07B_11D3_8D67_9218F7A2469C__INCLUDED_)
