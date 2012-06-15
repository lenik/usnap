// TextEditorDoc.h : interface of the CTextEditorDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEXTEDITORDOC_H__4D81D94C_C06D_11D3_8D51_D78E1C71984A__INCLUDED_)
#define AFX_TEXTEDITORDOC_H__4D81D94C_C06D_11D3_8D51_D78E1C71984A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTextEditorDoc : public CDocument
{
protected:
	CStringArray m_saText;
	void AddSimpleChar(int &nLine, int &nCharOff, char cChar);
	void DeleteCharLeft(int &nLine, int &nCharOff);
	void DeleteCharRight(int &nLine, int &nCharOff, int &nLineHint);
	void AddNL(int &nLine, int &nCharOff);
	void DeleteAll();
public:
	void AddChar(int &nLine, int &nCharOff, char cChar);
	CString String(int nLine);
	int GetLength();

protected: // create from serialization only
	CTextEditorDoc();
	DECLARE_DYNCREATE(CTextEditorDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextEditorDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTextEditorDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTextEditorDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTEDITORDOC_H__4D81D94C_C06D_11D3_8D51_D78E1C71984A__INCLUDED_)
