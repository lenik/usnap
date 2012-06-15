// XMLViewerDoc.h : interface of the CXMLViewerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_XMLVIEWERDOC_H__74954D8F_199D_405F_B4EF_8F1266E417EA__INCLUDED_)
#define AFX_XMLVIEWERDOC_H__74954D8F_199D_405F_B4EF_8F1266E417EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#import <msxml.dll> named_guids rename_namespace("MSXML")

class CXMLViewerDoc : public CDocument
{
protected: // create from serialization only
	CXMLViewerDoc();
	DECLARE_DYNCREATE(CXMLViewerDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXMLViewerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CXMLViewerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	MSXML::IXMLDOMDocumentPtr m_pXmlDoc;
public:
	BSTR m_view;

// Generated message map functions
protected:
	//{{AFX_MSG(CXMLViewerDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XMLVIEWERDOC_H__74954D8F_199D_405F_B4EF_8F1266E417EA__INCLUDED_)
