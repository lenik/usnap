// TextPainter.h : main header file for the TEXTPAINTER application
//

#if !defined(AFX_TEXTPAINTER_H__086AA0C3_C087_11D3_82CE_F690E07058CA__INCLUDED_)
#define AFX_TEXTPAINTER_H__086AA0C3_C087_11D3_82CE_F690E07058CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTextPainterApp:
// See TextPainter.cpp for the implementation of this class
//

class CTextPainterApp : public CWinApp
{
public:
	CTextPainterApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextPainterApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTextPainterApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTPAINTER_H__086AA0C3_C087_11D3_82CE_F690E07058CA__INCLUDED_)
