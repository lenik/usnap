// BIGMouthView.h : interface of the CBIGMouthView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BIGMOUTHVIEW_H__1FBB47EE_C08F_11D3_8DAF_FB36D2B758C6__INCLUDED_)
#define AFX_BIGMOUTHVIEW_H__1FBB47EE_C08F_11D3_8DAF_FB36D2B758C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBIGMouthView : public CView
{
protected: // create from serialization only
	CBIGMouthView();
	DECLARE_DYNCREATE(CBIGMouthView)

// Attributes
public:
	CBIGMouthDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBIGMouthView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBIGMouthView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBIGMouthView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BIGMouthView.cpp
inline CBIGMouthDoc* CBIGMouthView::GetDocument()
   { return (CBIGMouthDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BIGMOUTHVIEW_H__1FBB47EE_C08F_11D3_8DAF_FB36D2B758C6__INCLUDED_)
