// OleDropTarget.h : main header file for the OLEDROPTARGET application
//

#if !defined(AFX_OLEDROPTARGET_H__49D8BC25_4B62_446C_8B0D_2BF2ABF1AA34__INCLUDED_)
#define AFX_OLEDROPTARGET_H__49D8BC25_4B62_446C_8B0D_2BF2ABF1AA34__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COleDropTargetApp:
// See OleDropTarget.cpp for the implementation of this class
//

class COleDropTargetApp : public CWinApp
{
public:
	COleDropTargetApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COleDropTargetApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(COleDropTargetApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDROPTARGET_H__49D8BC25_4B62_446C_8B0D_2BF2ABF1AA34__INCLUDED_)
