// materialDoc.h : interface of the CMaterialDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MATERIALDOC_H__FA95CAEA_C06F_11D3_8ACD_484C0001E209__INCLUDED_)
#define AFX_MATERIALDOC_H__FA95CAEA_C06F_11D3_8ACD_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMaterialDoc : public CDocument
{
protected: // create from serialization only
	CMaterialDoc();
	DECLARE_DYNCREATE(CMaterialDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMaterialDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMaterialDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMaterialDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MATERIALDOC_H__FA95CAEA_C06F_11D3_8ACD_484C0001E209__INCLUDED_)
