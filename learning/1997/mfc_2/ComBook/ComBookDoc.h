// ComBookDoc.h : interface of the CComBookDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMBOOKDOC_H__EB2B978A_C022_11D3_8D4F_E2E9095ED3EF__INCLUDED_)
#define AFX_COMBOOKDOC_H__EB2B978A_C022_11D3_8D4F_E2E9095ED3EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ComEntry.h"

class CComBookDoc : public CDocument
{
protected: // create from serialization only
	CComBookDoc();
	DECLARE_DYNCREATE(CComBookDoc)
protected:
	CPtrList m_lEntry;
public:
	CEntry *GetNext(POSITION &Index);
	CEntry *GetFirst(POSITION &Index);
	POSITION Add(CEntry& eNewEntry);
	void Modify(POSITION Index);
	void Delete(POSITION Index);
	void DeleteAll();
	int GetCount();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComBookDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CComBookDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CComBookDoc)
	afx_msg void OnEditAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOOKDOC_H__EB2B978A_C022_11D3_8D4F_E2E9095ED3EF__INCLUDED_)
