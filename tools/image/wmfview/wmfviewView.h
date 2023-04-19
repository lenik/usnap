// wmfviewView.h : interface of the CWmfviewView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WMFVIEWVIEW_H__A9B6E390_F0C9_4FCF_BD76_CE23446E94BD__INCLUDED_)
#define AFX_WMFVIEWVIEW_H__A9B6E390_F0C9_4FCF_BD76_CE23446E94BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "infoDialog.h"
#include "info2Dialog.h"

#pragma pack(push, hdrsetting, 1)

struct wmfHeader {
	DWORD	key;
	WORD	hmf;
	WORD	bboxP1x, bboxP1y;
	WORD	bboxP2x, bboxP2y;
	WORD	inch;
	DWORD	reserved;
	WORD	checksum;
};

struct wmfHeader2 {
	WORD	mtType;
	WORD	mtHeaderSize;
	WORD	mtVersion;
	DWORD	mtSize;
	WORD	mtNoObject;
	DWORD	mtMaxRecords;
	WORD	mtNoParameters;
};

struct wmfRecord {
	DWORD	cb;			// 记录长度, 以WORD计算
	WORD	fn;			// WMF 功能代号
};

#pragma pack(pop, hdrsetting)

class CWmfviewView : public CScrollView
{
protected: // create from serialization only
	CWmfviewView();
	DECLARE_DYNCREATE(CWmfviewView)

// Attributes
public:
	CWmfviewDoc* GetDocument();
	CInfoDialog m_infoDlg;
	CInfo2Dialog m_info2Dlg;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWmfviewView)
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
	virtual ~CWmfviewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWmfviewView)
	afx_msg void OnViewInfo();
	afx_msg void OnViewInfo2();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in wmfviewView.cpp
inline CWmfviewDoc* CWmfviewView::GetDocument()
   { return (CWmfviewDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WMFVIEWVIEW_H__A9B6E390_F0C9_4FCF_BD76_CE23446E94BD__INCLUDED_)
