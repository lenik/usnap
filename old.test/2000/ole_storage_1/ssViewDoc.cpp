// ssViewDoc.cpp : implementation of the CSsViewDoc class
//

#include "stdafx.h"
#include "ssView.h"

#include "ssViewDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSsViewDoc

IMPLEMENT_DYNCREATE(CSsViewDoc, CDocument)

BEGIN_MESSAGE_MAP(CSsViewDoc, CDocument)
	//{{AFX_MSG_MAP(CSsViewDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSsViewDoc construction/destruction

CSsViewDoc::CSsViewDoc()
{
	// TODO: add one-time construction code here

}

CSsViewDoc::~CSsViewDoc()
{
}

BOOL CSsViewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSsViewDoc serialization

void CSsViewDoc::Serialize(CArchive& ar)
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
// CSsViewDoc diagnostics

#ifdef _DEBUG
void CSsViewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSsViewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSsViewDoc commands
