// CMineDoc.h : interface of the CCMineDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CMINEDOC_H__134B3F18_EB5D_423C_911A_53BF842ACF34__INCLUDED_)
#define AFX_CMINEDOC_H__134B3F18_EB5D_423C_911A_53BF842ACF34__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCMineDoc : public CDocument
{
protected: // create from serialization only
	CCMineDoc();
	DECLARE_DYNCREATE(CCMineDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCMineDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCMineDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCMineDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMINEDOC_H__134B3F18_EB5D_423C_911A_53BF842ACF34__INCLUDED_)
