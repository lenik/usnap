// rcpeDoc.h : interface of the CRcpeDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RCPEDOC_H__594A8B03_8B08_43D0_88A8_340468086E4F__INCLUDED_)
#define AFX_RCPEDOC_H__594A8B03_8B08_43D0_88A8_340468086E4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRcpeDoc : public CDocument
{
protected: // create from serialization only
	CRcpeDoc();
	DECLARE_DYNCREATE(CRcpeDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRcpeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRcpeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRcpeDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RCPEDOC_H__594A8B03_8B08_43D0_88A8_340468086E4F__INCLUDED_)
