// PackerCDoc.h : interface of the CPackerCDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PACKERCDOC_H__D65C1A6E_75E7_4BF5_9032_78110E518BB6__INCLUDED_)
#define AFX_PACKERCDOC_H__D65C1A6E_75E7_4BF5_9032_78110E518BB6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPackerCDoc : public CDocument
{
protected: // create from serialization only
	CPackerCDoc();
	DECLARE_DYNCREATE(CPackerCDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPackerCDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPackerCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPackerCDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PACKERCDOC_H__D65C1A6E_75E7_4BF5_9032_78110E518BB6__INCLUDED_)
