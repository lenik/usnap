// OServer1View.h : interface of the COServer1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OSERVER1VIEW_H__C614D44C_5BCA_4905_8032_D046E34B1CA1__INCLUDED_)
#define AFX_OSERVER1VIEW_H__C614D44C_5BCA_4905_8032_D046E34B1CA1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class COServer1View : public CView
{
protected: // create from serialization only
	COServer1View();
	DECLARE_DYNCREATE(COServer1View)

// Attributes
public:
	COServer1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COServer1View)
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
	virtual ~COServer1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COServer1View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	afx_msg void OnCancelEditSrvr();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OServer1View.cpp
inline COServer1Doc* COServer1View::GetDocument()
   { return (COServer1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OSERVER1VIEW_H__C614D44C_5BCA_4905_8032_D046E34B1CA1__INCLUDED_)
