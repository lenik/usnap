// docviewDoc.h : interface of the CDocviewDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DOCVIEWDOC_H__2AFBD06A_C07C_11D3_8D4E_BBF47FF1F969__INCLUDED_)
#define AFX_DOCVIEWDOC_H__2AFBD06A_C07C_11D3_8D4E_BBF47FF1F969__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDocviewDoc : public CDocument
{
protected: // create from serialization only
	CDocviewDoc();
	DECLARE_DYNCREATE(CDocviewDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDocviewDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDocviewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDocviewDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOCVIEWDOC_H__2AFBD06A_C07C_11D3_8D4E_BBF47FF1F969__INCLUDED_)
