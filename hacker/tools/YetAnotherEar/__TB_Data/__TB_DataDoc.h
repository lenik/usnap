// __TB_DataDoc.h : interface of the C__TB_DataDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX___TB_DATADOC_H__641EF9C9_2F77_45B1_9605_E11BAD5ACDC4__INCLUDED_)
#define AFX___TB_DATADOC_H__641EF9C9_2F77_45B1_9605_E11BAD5ACDC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class C__TB_DataDoc : public CDocument
{
protected: // create from serialization only
	C__TB_DataDoc();
	DECLARE_DYNCREATE(C__TB_DataDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(C__TB_DataDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~C__TB_DataDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(C__TB_DataDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(C__TB_DataDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX___TB_DATADOC_H__641EF9C9_2F77_45B1_9605_E11BAD5ACDC4__INCLUDED_)
