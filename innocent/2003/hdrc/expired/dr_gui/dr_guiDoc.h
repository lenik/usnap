// dr_guiDoc.h : interface of the CDr_guiDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DR_GUIDOC_H__959E8EC6_ABBA_4731_B15E_D4E3E5F57365__INCLUDED_)
#define AFX_DR_GUIDOC_H__959E8EC6_ABBA_4731_B15E_D4E3E5F57365__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDr_guiDoc : public CDocument
{
protected: // create from serialization only
	CDr_guiDoc();
	DECLARE_DYNCREATE(CDr_guiDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDr_guiDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDr_guiDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDr_guiDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DR_GUIDOC_H__959E8EC6_ABBA_4731_B15E_D4E3E5F57365__INCLUDED_)
