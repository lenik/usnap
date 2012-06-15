// olepasteDoc.h : interface of the COlepasteDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEPASTEDOC_H__63676D81_AC4F_4A66_8205_5004F49C52DB__INCLUDED_)
#define AFX_OLEPASTEDOC_H__63676D81_AC4F_4A66_8205_5004F49C52DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class COlepasteDoc : public CDocument
{
protected: // create from serialization only
	COlepasteDoc();
	DECLARE_DYNCREATE(COlepasteDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COlepasteDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COlepasteDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COlepasteDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEPASTEDOC_H__63676D81_AC4F_4A66_8205_5004F49C52DB__INCLUDED_)
