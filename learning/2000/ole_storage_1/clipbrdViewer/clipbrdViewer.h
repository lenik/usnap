// clipbrdViewer.h : main header file for the CLIPBRDVIEWER application
//

#if !defined(AFX_CLIPBRDVIEWER_H__E5F0D87C_2390_402D_9697_47BF9B8B61E7__INCLUDED_)
#define AFX_CLIPBRDVIEWER_H__E5F0D87C_2390_402D_9697_47BF9B8B61E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CClipbrdViewerApp:
// See clipbrdViewer.cpp for the implementation of this class
//

class CClipbrdViewerApp : public CWinApp
{
public:
	CClipbrdViewerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClipbrdViewerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CClipbrdViewerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIPBRDVIEWER_H__E5F0D87C_2390_402D_9697_47BF9B8B61E7__INCLUDED_)
