// ChildView.h : interface of the CChildView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHILDVIEW_H__CC7C9411_C041_11D3_8D4C_9A9DB0902751__INCLUDED_)
#define AFX_CHILDVIEW_H__CC7C9411_C041_11D3_8D4C_9A9DB0902751__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();
protected:
	CPoint m_pntPrevMouseLoc, m_pntMouseLoc;
	UINT m_nMouseFlags;
	BOOL m_bButtonDown;
	UINT m_nPrevIndex;
protected:
	CPtrArray m_MousePositions;
	CWordArray m_MouseButtons;
	void ClearList();
	void AddList(CPoint&, UINT nButtonFlag);
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildView)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	//{{AFX_MSG(CChildView)
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDVIEW_H__CC7C9411_C041_11D3_8D4C_9A9DB0902751__INCLUDED_)
