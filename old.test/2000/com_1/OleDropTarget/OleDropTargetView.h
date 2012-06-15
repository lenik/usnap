// OleDropTargetView.h : interface of the COleDropTargetView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEDROPTARGETVIEW_H__1120B088_B156_4910_9945_5C0910660899__INCLUDED_)
#define AFX_OLEDROPTARGETVIEW_H__1120B088_B156_4910_9945_5C0910660899__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class COleDropTargetView : public CView
{
protected: // create from serialization only
	COleDropTargetView();
	DECLARE_DYNCREATE(COleDropTargetView)

// Attributes
public:
	COleDropTargetDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COleDropTargetView)
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
	virtual ~COleDropTargetView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COleDropTargetView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OleDropTargetView.cpp
inline COleDropTargetDoc* COleDropTargetView::GetDocument()
   { return (COleDropTargetDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDROPTARGETVIEW_H__1120B088_B156_4910_9945_5C0910660899__INCLUDED_)
