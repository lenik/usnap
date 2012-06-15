// syntestDoc.h : interface of the CSyntestDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SYNTESTDOC_H__EC4945AC_3206_4B31_BAA8_763569F2039D__INCLUDED_)
#define AFX_SYNTESTDOC_H__EC4945AC_3206_4B31_BAA8_763569F2039D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSyntestDoc : public CDocument
{
protected: // create from serialization only
	CSyntestDoc();
	DECLARE_DYNCREATE(CSyntestDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSyntestDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSyntestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSyntestDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYNTESTDOC_H__EC4945AC_3206_4B31_BAA8_763569F2039D__INCLUDED_)
