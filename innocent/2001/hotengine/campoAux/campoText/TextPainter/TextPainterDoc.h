// TextPainterDoc.h : interface of the CTextPainterDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEXTPAINTERDOC_H__086AA0CB_C087_11D3_82CE_F690E07058CA__INCLUDED_)
#define AFX_TEXTPAINTERDOC_H__086AA0CB_C087_11D3_82CE_F690E07058CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "campoText.h"

class CTextPainterDoc : public CDocument
{
protected: // create from serialization only
	CTextPainterDoc();
	DECLARE_DYNCREATE(CTextPainterDoc)

// Attributes
public:
	cText text;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextPainterDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTextPainterDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTextPainterDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTPAINTERDOC_H__086AA0CB_C087_11D3_82CE_F690E07058CA__INCLUDED_)
