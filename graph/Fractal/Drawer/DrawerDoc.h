// DrawerDoc.h : interface of the CDrawerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWERDOC_H__8FAD6FA2_0846_4BCE_819A_868309277D40__INCLUDED_)
#define AFX_DRAWERDOC_H__8FAD6FA2_0846_4BCE_819A_868309277D40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDrawerDoc;
#include "IterDialog.h"

class CDrawerDoc : public CDocument
{
protected: // create from serialization only
	CDrawerDoc();
	DECLARE_DYNCREATE(CDrawerDoc)

// Attributes
public:
	CIterDialog		*m_pDlgIter;
	CStringArray	m_igA;
	CStringArray	m_igB;
	UINT			m_igCount;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDrawerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawerDoc)
	afx_msg void OnShowIterDlg();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWERDOC_H__8FAD6FA2_0846_4BCE_819A_868309277D40__INCLUDED_)
