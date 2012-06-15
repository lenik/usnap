// DDRGenerateDoc.h : interface of the CDDRGenerateDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DDRGENERATEDOC_H__6B2E9FAA_C0A9_11D3_82D4_484C0001E209__INCLUDED_)
#define AFX_DDRGENERATEDOC_H__6B2E9FAA_C0A9_11D3_82D4_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDDRGenerateDoc : public CDocument
{
protected: // create from serialization only
	CDDRGenerateDoc();
	DECLARE_DYNCREATE(CDDRGenerateDoc)

// Attributes
public:

	KeyMaker	keys;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDDRGenerateDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDDRGenerateDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDDRGenerateDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DDRGENERATEDOC_H__6B2E9FAA_C0A9_11D3_82D4_484C0001E209__INCLUDED_)
