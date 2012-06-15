// CeE3D_Client1Doc.h : interface of the CCeE3D_Client1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CEE3D_CLIENT1DOC_H__D2B26C50_27FE_41A0_95E1_E1F5931F5F50__INCLUDED_)
#define AFX_CEE3D_CLIENT1DOC_H__D2B26C50_27FE_41A0_95E1_E1F5931F5F50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCeE3D_Client1Doc : public CDocument
{
protected: // create from serialization only
	CCeE3D_Client1Doc();
	DECLARE_DYNCREATE(CCeE3D_Client1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCeE3D_Client1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCeE3D_Client1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCeE3D_Client1Doc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CCeE3D_Client1Doc)
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CEE3D_CLIENT1DOC_H__D2B26C50_27FE_41A0_95E1_E1F5931F5F50__INCLUDED_)
