// ProcessViewer01View.h : interface of the CProcessViewer01View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROCESSVIEWER01VIEW_H__32350920_C08B_11D3_8D8B_9B78F2ACB14A__INCLUDED_)
#define AFX_PROCESSVIEWER01VIEW_H__32350920_C08B_11D3_8D8B_9B78F2ACB14A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CProcessViewer01View : public CView
{
protected: // create from serialization only
	CProcessViewer01View();
	DECLARE_DYNCREATE(CProcessViewer01View)

// Attributes
public:
	CProcessViewer01Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProcessViewer01View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CProcessViewer01View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CProcessViewer01View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ProcessViewer01View.cpp
inline CProcessViewer01Doc* CProcessViewer01View::GetDocument()
   { return (CProcessViewer01Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROCESSVIEWER01VIEW_H__32350920_C08B_11D3_8D8B_9B78F2ACB14A__INCLUDED_)
