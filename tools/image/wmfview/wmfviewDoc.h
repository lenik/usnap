// wmfviewDoc.h : interface of the CWmfviewDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WMFVIEWDOC_H__DCE399BE_929A_4B24_9046_77C4D466119F__INCLUDED_)
#define AFX_WMFVIEWDOC_H__DCE399BE_929A_4B24_9046_77C4D466119F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CWmfviewDoc : public CDocument
{
protected: // create from serialization only
	CWmfviewDoc();
	DECLARE_DYNCREATE(CWmfviewDoc)

// Attributes
public:
	CFile	m_file;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWmfviewDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void OnCloseDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWmfviewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWmfviewDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WMFVIEWDOC_H__DCE399BE_929A_4B24_9046_77C4D466119F__INCLUDED_)
