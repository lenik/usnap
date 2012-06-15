// OLEDocumentDoc.h : interface of the COLEDocumentDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEDOCUMENTDOC_H__F7033EF2_4008_4E11_9713_7318448AF93A__INCLUDED_)
#define AFX_OLEDOCUMENTDOC_H__F7033EF2_4008_4E11_9713_7318448AF93A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class COLEDocumentDoc : public COleDocument
{
protected: // create from serialization only
	COLEDocumentDoc();
	DECLARE_DYNCREATE(COLEDocumentDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COLEDocumentDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COLEDocumentDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COLEDocumentDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDOCUMENTDOC_H__F7033EF2_4008_4E11_9713_7318448AF93A__INCLUDED_)
