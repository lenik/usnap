// OServer1Doc.cpp : implementation of the COServer1Doc class
//

#include "stdafx.h"
#include "OServer1.h"

#include "OServer1Doc.h"
#include "SrvrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COServer1Doc

IMPLEMENT_DYNCREATE(COServer1Doc, COleServerDoc)

BEGIN_MESSAGE_MAP(COServer1Doc, COleServerDoc)
	//{{AFX_MSG_MAP(COServer1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COServer1Doc construction/destruction

COServer1Doc::COServer1Doc()
{
	// Use OLE compound files
	EnableCompoundFile();

	// TODO: add one-time construction code here

}

COServer1Doc::~COServer1Doc()
{
}

BOOL COServer1Doc::OnNewDocument()
{
	if (!COleServerDoc::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// COServer1Doc server implementation

COleServerItem* COServer1Doc::OnGetEmbeddedItem()
{
	// OnGetEmbeddedItem is called by the framework to get the COleServerItem
	//  that is associated with the document.  It is only called when necessary.

	COServer1SrvrItem* pItem = new COServer1SrvrItem(this);
	ASSERT_VALID(pItem);
	return pItem;
}



/////////////////////////////////////////////////////////////////////////////
// COServer1Doc serialization

void COServer1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// COServer1Doc diagnostics

#ifdef _DEBUG
void COServer1Doc::AssertValid() const
{
	COleServerDoc::AssertValid();
}

void COServer1Doc::Dump(CDumpContext& dc) const
{
	COleServerDoc::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COServer1Doc commands
