// PackerCView.h : interface of the CPackerCView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PACKERCVIEW_H__A1AAAA3A_4C1D_4C1F_9846_552A7B068824__INCLUDED_)
#define AFX_PACKERCVIEW_H__A1AAAA3A_4C1D_4C1F_9846_552A7B068824__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPackerCView : public CHtmlView
{
protected: // create from serialization only
	CPackerCView();
	DECLARE_DYNCREATE(CPackerCView)

// Attributes
public:
	CPackerCDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPackerCView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPackerCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPackerCView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PackerCView.cpp
inline CPackerCDoc* CPackerCView::GetDocument()
   { return (CPackerCDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PACKERCVIEW_H__A1AAAA3A_4C1D_4C1F_9846_552A7B068824__INCLUDED_)
