// CMineView.h : interface of the CCMineView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CMINEVIEW_H__CBD39B8A_5FE5_4795_87DE_621C574B4E9B__INCLUDED_)
#define AFX_CMINEVIEW_H__CBD39B8A_5FE5_4795_87DE_621C574B4E9B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCMineView : public CView
{
protected: // create from serialization only
	CCMineView();
	DECLARE_DYNCREATE(CCMineView)

// Attributes
public:
	CCMineDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCMineView)
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
	virtual ~CCMineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCMineView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CMineView.cpp
inline CCMineDoc* CCMineView::GetDocument()
   { return (CCMineDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMINEVIEW_H__CBD39B8A_5FE5_4795_87DE_621C574B4E9B__INCLUDED_)
