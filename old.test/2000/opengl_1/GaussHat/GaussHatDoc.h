// GaussHatDoc.h : interface of the CGaussHatDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAUSSHATDOC_H__7E343DCA_C03C_11D3_8ACB_484C0001E209__INCLUDED_)
#define AFX_GAUSSHATDOC_H__7E343DCA_C03C_11D3_8ACB_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGaussHatDoc : public CDocument
{
protected: // create from serialization only
	CGaussHatDoc();
	DECLARE_DYNCREATE(CGaussHatDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGaussHatDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGaussHatDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGaussHatDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAUSSHATDOC_H__7E343DCA_C03C_11D3_8ACB_484C0001E209__INCLUDED_)
