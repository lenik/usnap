// BIGMouthDoc.h : interface of the CBIGMouthDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BIGMOUTHDOC_H__1FBB47EC_C08F_11D3_8DAF_FB36D2B758C6__INCLUDED_)
#define AFX_BIGMOUTHDOC_H__1FBB47EC_C08F_11D3_8DAF_FB36D2B758C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBIGMouthDoc : public CDocument
{
protected: // create from serialization only
	CBIGMouthDoc();
	DECLARE_DYNCREATE(CBIGMouthDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBIGMouthDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBIGMouthDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBIGMouthDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BIGMOUTHDOC_H__1FBB47EC_C08F_11D3_8DAF_FB36D2B758C6__INCLUDED_)
