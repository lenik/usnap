// myFontDoc.h : interface of the CMyFontDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYFONTDOC_H__F2818E1B_C080_11D3_8ACD_484C0001E209__INCLUDED_)
#define AFX_MYFONTDOC_H__F2818E1B_C080_11D3_8ACD_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyFontDoc : public CDocument
{
protected: // create from serialization only
	CMyFontDoc();
	DECLARE_DYNCREATE(CMyFontDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyFontDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyFontDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyFontDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYFONTDOC_H__F2818E1B_C080_11D3_8ACD_484C0001E209__INCLUDED_)
