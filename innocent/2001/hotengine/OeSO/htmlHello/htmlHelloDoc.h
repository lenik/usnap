// htmlHelloDoc.h : interface of the CHtmlHelloDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HTMLHELLODOC_H__F20F89BF_ABB1_4462_AB7A_017FD4BBD050__INCLUDED_)
#define AFX_HTMLHELLODOC_H__F20F89BF_ABB1_4462_AB7A_017FD4BBD050__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHtmlHelloDoc : public CDocument
{
protected: // create from serialization only
	CHtmlHelloDoc();
	DECLARE_DYNCREATE(CHtmlHelloDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHtmlHelloDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHtmlHelloDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHtmlHelloDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTMLHELLODOC_H__F20F89BF_ABB1_4462_AB7A_017FD4BBD050__INCLUDED_)
