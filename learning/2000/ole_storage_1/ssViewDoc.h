// ssViewDoc.h : interface of the CSsViewDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SSVIEWDOC_H__48088D0D_EB7C_48C5_90DB_C3EBF24FD932__INCLUDED_)
#define AFX_SSVIEWDOC_H__48088D0D_EB7C_48C5_90DB_C3EBF24FD932__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSsViewDoc : public CDocument
{
protected: // create from serialization only
	CSsViewDoc();
	DECLARE_DYNCREATE(CSsViewDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSsViewDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSsViewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSsViewDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SSVIEWDOC_H__48088D0D_EB7C_48C5_90DB_C3EBF24FD932__INCLUDED_)
