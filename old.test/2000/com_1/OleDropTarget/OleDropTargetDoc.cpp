// OleDropTargetDoc.cpp : implementation of the COleDropTargetDoc class
//

#include "stdafx.h"
#include "OleDropTarget.h"

#include "OleDropTargetDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COleDropTargetDoc

IMPLEMENT_DYNCREATE(COleDropTargetDoc, CDocument)

BEGIN_MESSAGE_MAP(COleDropTargetDoc, CDocument)
	//{{AFX_MSG_MAP(COleDropTargetDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COleDropTargetDoc construction/destruction

COleDropTargetDoc::COleDropTargetDoc()
{
	// TODO: add one-time construction code here

}

COleDropTargetDoc::~COleDropTargetDoc()
{
}

BOOL COleDropTargetDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// COleDropTargetDoc serialization

void COleDropTargetDoc::Serialize(CArchive& ar)
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
// COleDropTargetDoc diagnostics

#ifdef _DEBUG
void COleDropTargetDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COleDropTargetDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COleDropTargetDoc commands
