// rcpeView.h : interface of the CRcpeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RCPEVIEW_H__298031DC_75F7_4902_B167_C477C973AB4D__INCLUDED_)
#define AFX_RCPEVIEW_H__298031DC_75F7_4902_B167_C477C973AB4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRcpeView : public CView
{
protected: // create from serialization only
	CRcpeView();
	DECLARE_DYNCREATE(CRcpeView)

// Attributes
public:
	CRcpeDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRcpeView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRcpeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRcpeView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in rcpeView.cpp
inline CRcpeDoc* CRcpeView::GetDocument()
   { return (CRcpeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RCPEVIEW_H__298031DC_75F7_4902_B167_C477C973AB4D__INCLUDED_)
