// myObjectsDoc.h : interface of the CMyObjectsDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYOBJECTSDOC_H__B6A71ECA_C087_11D3_8ACC_484C0001E209__INCLUDED_)
#define AFX_MYOBJECTSDOC_H__B6A71ECA_C087_11D3_8ACC_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyObjectsDoc : public CDocument
{
protected: // create from serialization only
	CMyObjectsDoc();
	DECLARE_DYNCREATE(CMyObjectsDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyObjectsDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyObjectsDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyObjectsDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYOBJECTSDOC_H__B6A71ECA_C087_11D3_8ACC_484C0001E209__INCLUDED_)
