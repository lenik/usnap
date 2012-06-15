// OleDropTargetDoc.h : interface of the COleDropTargetDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEDROPTARGETDOC_H__4FE6E808_5693_4F55_99E0_EEAD5E0A7573__INCLUDED_)
#define AFX_OLEDROPTARGETDOC_H__4FE6E808_5693_4F55_99E0_EEAD5E0A7573__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class COleDropTargetDoc : public CDocument
{
protected: // create from serialization only
	COleDropTargetDoc();
	DECLARE_DYNCREATE(COleDropTargetDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COleDropTargetDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COleDropTargetDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COleDropTargetDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDROPTARGETDOC_H__4FE6E808_5693_4F55_99E0_EEAD5E0A7573__INCLUDED_)
