// syntestView.h : interface of the CSyntestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SYNTESTVIEW_H__498AB142_0FCB_4F5C_BB49_58BEE53D6A15__INCLUDED_)
#define AFX_SYNTESTVIEW_H__498AB142_0FCB_4F5C_BB49_58BEE53D6A15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSyntestView : public CView
{
protected: // create from serialization only
	CSyntestView();
	DECLARE_DYNCREATE(CSyntestView)

// Attributes
public:
	CSyntestDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSyntestView)
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
	virtual ~CSyntestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSyntestView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in syntestView.cpp
inline CSyntestDoc* CSyntestView::GetDocument()
   { return (CSyntestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYNTESTVIEW_H__498AB142_0FCB_4F5C_BB49_58BEE53D6A15__INCLUDED_)
