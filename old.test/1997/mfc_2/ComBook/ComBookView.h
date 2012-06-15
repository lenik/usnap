// ComBookView.h : interface of the CComBookView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMBOOKVIEW_H__EB2B978C_C022_11D3_8D4F_E2E9095ED3EF__INCLUDED_)
#define AFX_COMBOOKVIEW_H__EB2B978C_C022_11D3_8D4F_E2E9095ED3EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//CView *pTimerView;

class CComBookView : public CScrollView
{
protected: // create from serialization only
	CComBookView();
	DECLARE_DYNCREATE(CComBookView)
protected:
	int m_nCharHeight;
	int m_nCharWidth;

	int m_nLeftMargin;
	int m_nPageOffset;

	int m_nPageNumber;
	// The index of the "current" CEntry; the current entry is the one that will be deleted or modified if you select those commands(it gets displayed in red)
	POSITION m_posCurrent;

	void Output(CDC *pDC, CEntry *pEntry, int nOffset, int bCurrent);

protected:
	CFont *m_pHeaderFont;
	CFont *m_pColumnHeaderFont;
	CFont *m_pTextFont;

	CFont *SetFont(CDC *, CFont *pNewFont = NULL);

// Attributes
public:
	CComBookDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComBookView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CComBookView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CComBookView)
	afx_msg void OnEditDel();
	afx_msg void OnEditModify();
	afx_msg void OnUpdateEditDel(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditModify(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ComBookView.cpp
inline CComBookDoc* CComBookView::GetDocument()
   { return (CComBookDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOOKVIEW_H__EB2B978C_C022_11D3_8D4F_E2E9095ED3EF__INCLUDED_)
