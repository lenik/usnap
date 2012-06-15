// mfc02View.h : interface of the CMfc02View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFC02VIEW_H__1887E26C_C0D2_11D3_8D62_B2EC4A9FD45A__INCLUDED_)
#define AFX_MFC02VIEW_H__1887E26C_C0D2_11D3_8D62_B2EC4A9FD45A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMfc02View : public CView
{
protected: // create from serialization only
	CMfc02View();
	DECLARE_DYNCREATE(CMfc02View)

// Attributes
public:
	CMfc02Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMfc02View)
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
	virtual ~CMfc02View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMfc02View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in mfc02View.cpp
inline CMfc02Doc* CMfc02View::GetDocument()
   { return (CMfc02Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC02VIEW_H__1887E26C_C0D2_11D3_8D62_B2EC4A9FD45A__INCLUDED_)
