// mfc_com3.h : main header file for the MFC_COM3 DLL
//

#if !defined(AFX_MFC_COM3_H__415A8D0A_268A_43D3_AE51_64F082932FDF__INCLUDED_)
#define AFX_MFC_COM3_H__415A8D0A_268A_43D3_AE51_64F082932FDF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMfc_com3App
// See mfc_com3.cpp for the implementation of this class
//

class CMfc_com3App : public CWinApp
{
public:
	CMfc_com3App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMfc_com3App)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CMfc_com3App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_COM3_H__415A8D0A_268A_43D3_AE51_64F082932FDF__INCLUDED_)
