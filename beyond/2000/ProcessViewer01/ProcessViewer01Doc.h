// ProcessViewer01Doc.h : interface of the CProcessViewer01Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROCESSVIEWER01DOC_H__3235091E_C08B_11D3_8D8B_9B78F2ACB14A__INCLUDED_)
#define AFX_PROCESSVIEWER01DOC_H__3235091E_C08B_11D3_8D8B_9B78F2ACB14A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CProcessViewer01Doc : public CDocument
{
protected: // create from serialization only
	CProcessViewer01Doc();
	DECLARE_DYNCREATE(CProcessViewer01Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProcessViewer01Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CProcessViewer01Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CProcessViewer01Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROCESSVIEWER01DOC_H__3235091E_C08B_11D3_8D8B_9B78F2ACB14A__INCLUDED_)
