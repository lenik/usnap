// CntrItem.h : interface of the COLEDocumentCntrItem class
//

#if !defined(AFX_CNTRITEM_H__0DBED5D9_9C91_4771_8C3F_5AC046D8087D__INCLUDED_)
#define AFX_CNTRITEM_H__0DBED5D9_9C91_4771_8C3F_5AC046D8087D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class COLEDocumentDoc;
class COLEDocumentView;

class COLEDocumentCntrItem : public COleClientItem
{
	DECLARE_SERIAL(COLEDocumentCntrItem)

// Constructors
public:
	COLEDocumentCntrItem(COLEDocumentDoc* pContainer = NULL);
		// Note: pContainer is allowed to be NULL to enable IMPLEMENT_SERIALIZE.
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-NULL document pointer.

// Attributes
public:
	COLEDocumentDoc* GetDocument()
		{ return (COLEDocumentDoc*)COleClientItem::GetDocument(); }
	COLEDocumentView* GetActiveView()
		{ return (COLEDocumentView*)COleClientItem::GetActiveView(); }

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COLEDocumentCntrItem)
	public:
	virtual void OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam);
	virtual void OnActivate();
	protected:
	virtual void OnGetItemPosition(CRect& rPosition);
	virtual void OnDeactivateUI(BOOL bUndoable);
	virtual BOOL OnChangeItemPosition(const CRect& rectPos);
	//}}AFX_VIRTUAL

// Implementation
public:
	~COLEDocumentCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CNTRITEM_H__0DBED5D9_9C91_4771_8C3F_5AC046D8087D__INCLUDED_)
