// CeE3D_Client1View.h : interface of the CCeE3D_Client1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CEE3D_CLIENT1VIEW_H__16A62773_9D85_4234_A260_CCB3DD9478EA__INCLUDED_)
#define AFX_CEE3D_CLIENT1VIEW_H__16A62773_9D85_4234_A260_CCB3DD9478EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCeE3D_Client1View : public CView
{
protected: // create from serialization only
	CCeE3D_Client1View();
	DECLARE_DYNCREATE(CCeE3D_Client1View)

// Attributes
public:
	CCeE3D_Client1Doc* GetDocument();

	ICeE3DBase	*pCeBase;
	ICeE3DAux	*pCeAux;
	ICeE3DModel	*pCeModel;
	ICeE3DEnv	*pCeEnv;
	ICeE3DRender	*pCeRender;
	ICeE3DUtil	*pCeUtil;

	virtual void InitObjects();
	virtual void CleanUpObjects();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCeE3D_Client1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCeE3D_Client1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCeE3D_Client1View)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CeE3D_Client1View.cpp
inline CCeE3D_Client1Doc* CCeE3D_Client1View::GetDocument()
   { return (CCeE3D_Client1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CEE3D_CLIENT1VIEW_H__16A62773_9D85_4234_A260_CCB3DD9478EA__INCLUDED_)
