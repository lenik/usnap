// HelloDoc.h : interface of the CHelloDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HELLODOC_H__DF6EA7EE_C089_11D3_8AC9_484C0001E209__INCLUDED_)
#define AFX_HELLODOC_H__DF6EA7EE_C089_11D3_8AC9_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHelloDoc : public CDocument
{
protected: // create from serialization only
	CHelloDoc();
	DECLARE_DYNCREATE(CHelloDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHelloDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHelloDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHelloDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HELLODOC_H__DF6EA7EE_C089_11D3_8AC9_484C0001E209__INCLUDED_)
