// ole.h : main header file for the OLE application
//

#if !defined(AFX_OLE_H__8CE20FD1_0720_4944_8349_3C293877AD43__INCLUDED_)
#define AFX_OLE_H__8CE20FD1_0720_4944_8349_3C293877AD43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COleApp:
// See ole.cpp for the implementation of this class
//

class COleApp : public CWinApp
{
public:
	COleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLE_H__8CE20FD1_0720_4944_8349_3C293877AD43__INCLUDED_)
