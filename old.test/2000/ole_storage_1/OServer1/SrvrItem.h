// SrvrItem.h : interface of the COServer1SrvrItem class
//

#if !defined(AFX_SRVRITEM_H__1331CC97_2E7C_4FC7_9D3F_1E31854032E4__INCLUDED_)
#define AFX_SRVRITEM_H__1331CC97_2E7C_4FC7_9D3F_1E31854032E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class COServer1SrvrItem : public COleServerItem
{
	DECLARE_DYNAMIC(COServer1SrvrItem)

// Constructors
public:
	COServer1SrvrItem(COServer1Doc* pContainerDoc);

// Attributes
	COServer1Doc* GetDocument() const
		{ return (COServer1Doc*)COleServerItem::GetDocument(); }

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COServer1SrvrItem)
	public:
	virtual BOOL OnDraw(CDC* pDC, CSize& rSize);
	virtual BOOL OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize);
	//}}AFX_VIRTUAL

// Implementation
public:
	~COServer1SrvrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SRVRITEM_H__1331CC97_2E7C_4FC7_9D3F_1E31854032E4__INCLUDED_)
