// docviewView.h : interface of the CDocviewView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DOCVIEWVIEW_H__2AFBD06C_C07C_11D3_8D4E_BBF47FF1F969__INCLUDED_)
#define AFX_DOCVIEWVIEW_H__2AFBD06C_C07C_11D3_8D4E_BBF47FF1F969__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDocviewView : public CView
{
protected: // create from serialization only
	CDocviewView();
	DECLARE_DYNCREATE(CDocviewView)

// Attributes
public:
	CDocviewDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDocviewView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDocviewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDocviewView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in docviewView.cpp
inline CDocviewDoc* CDocviewView::GetDocument()
   { return (CDocviewDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOCVIEWVIEW_H__2AFBD06C_C07C_11D3_8D4E_BBF47FF1F969__INCLUDED_)
