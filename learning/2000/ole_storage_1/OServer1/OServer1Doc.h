// OServer1Doc.h : interface of the COServer1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OSERVER1DOC_H__5D344BA4_49D8_47C3_9C40_68A07DC1F54C__INCLUDED_)
#define AFX_OSERVER1DOC_H__5D344BA4_49D8_47C3_9C40_68A07DC1F54C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class COServer1SrvrItem;

class COServer1Doc : public COleServerDoc
{
protected: // create from serialization only
	COServer1Doc();
	DECLARE_DYNCREATE(COServer1Doc)

// Attributes
public:
	COServer1SrvrItem* GetEmbeddedItem()
		{ return (COServer1SrvrItem*)COleServerDoc::GetEmbeddedItem(); }

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COServer1Doc)
	protected:
	virtual COleServerItem* OnGetEmbeddedItem();
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COServer1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COServer1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OSERVER1DOC_H__5D344BA4_49D8_47C3_9C40_68A07DC1F54C__INCLUDED_)
