// LightDemoDoc.h : interface of the CLightDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIGHTDEMODOC_H__4BA31B4A_C07A_11D3_8AD1_484C0001E209__INCLUDED_)
#define AFX_LIGHTDEMODOC_H__4BA31B4A_C07A_11D3_8AD1_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLightDemoDoc : public CDocument
{
protected: // create from serialization only
	CLightDemoDoc();
	DECLARE_DYNCREATE(CLightDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLightDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLightDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLightDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIGHTDEMODOC_H__4BA31B4A_C07A_11D3_8AD1_484C0001E209__INCLUDED_)
