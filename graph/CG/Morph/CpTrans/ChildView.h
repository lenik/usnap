// ChildView.h : interface of the CChildView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHILDVIEW_H__CFE9EC95_B5CF_4FC9_82A6_A8CEF249DB4C__INCLUDED_)
#define AFX_CHILDVIEW_H__CFE9EC95_B5CF_4FC9_82A6_A8CEF249DB4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CpTransI.h"

#define DEFAULT_SAMPLE		0.01

/////////////////////////////////////////////////////////////////////////////
// CChildView window

struct CPPACK {
	LPPOINT		cpSrc;
	INT		nSrc;
	LPPOINT		cpDst;
	INT		nDst;
	CDC		*pDC;
};
typedef struct CPPACK	*PCPPACK, *LPCPPACK;

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
protected:
	POINT	cpLine[2];
	POINT	cpRect[4];
	POINT	cpCircle[128];
	INT	lastOp;
public:
	static REAL _sleep_val;
	static BOOL IsChkWait;
public:
	static BOOL MouseDownChecker;

public:
	void	STDCALL initData();
	void	STDCALL switchTo(INT);

	static	BOOL STDCALL waitunit();
	static	BOOL STDCALL draw(REAL, LPPOINT, INT, DWORD);
	static	BOOL STDCALL chkrel(LPPOINTR, INT, LPPOINTR, INT, DWORD);

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
	afx_msg void OnButtonLine();
	afx_msg void OnButtonRect();
	afx_msg void OnButtonCircle();
	afx_msg void OnSpeedFast();
	afx_msg void OnSpeedSlow();
	afx_msg void OnButtonChkRes();
	afx_msg void OnButtonChkWait();
	afx_msg void OnButtonCls();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

BOOL	STDCALL drawPixel(CDC *, int, int, REAL, COLORREF);
BOOL	STDCALL arrowLine(CDC *, int, int, int, int, COLORREF);
BOOL	STDCALL setColor(CDC *, COLORREF);
BOOL	STDCALL setBackColor(CDC *, COLORREF);
BOOL	STDCALL textOut(CDC *, int, int, LPCTSTR, COLORREF);

BOOL	STDCALL waitcycle();

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDVIEW_H__CFE9EC95_B5CF_4FC9_82A6_A8CEF249DB4C__INCLUDED_)
