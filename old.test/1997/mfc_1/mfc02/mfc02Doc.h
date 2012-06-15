// mfc02Doc.h : interface of the CMfc02Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFC02DOC_H__1887E26A_C0D2_11D3_8D62_B2EC4A9FD45A__INCLUDED_)
#define AFX_MFC02DOC_H__1887E26A_C0D2_11D3_8D62_B2EC4A9FD45A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMfc02Doc : public CDocument
{
protected: // create from serialization only
	CMfc02Doc();
	DECLARE_DYNCREATE(CMfc02Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMfc02Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMfc02Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMfc02Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC02DOC_H__1887E26A_C0D2_11D3_8D62_B2EC4A9FD45A__INCLUDED_)
