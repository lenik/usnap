// dv01Doc.h : interface of the CDv01Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DV01DOC_H__2AFBD099_C07C_11D3_8D4E_BBF47FF1F969__INCLUDED_)
#define AFX_DV01DOC_H__2AFBD099_C07C_11D3_8D4E_BBF47FF1F969__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDv01Doc : public CDocument
{
protected: // create from serialization only
	CDv01Doc();
	DECLARE_DYNCREATE(CDv01Doc)

// Attributes
public:
protected:
	CPtrArray m_MousePositions;
	CWordArray m_MouseButtons;

	// The following flag is necesary
	// to correct what appears to be a
	// bug == when an entry in the file Selection
	// box is double-clicked, the view gets a WM_MOUSEMOVE message.
	// This flag is set to TRUE when you are expecting this message and want to ignore it.
	int m_bNoUpdate;

// Operations
public:
	void ClearList();
	void AddList(CPoint, UINT);

	void EnableUpdate();
	UINT GetSize();
	CPoint *GetMPosition(UINT index);
	int GetMButton(UINT index);

public:
	void Save(CArchive& ar);
	void Restore(CArchive& ar);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDv01Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDv01Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDv01Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DV01DOC_H__2AFBD099_C07C_11D3_8D4E_BBF47FF1F969__INCLUDED_)
