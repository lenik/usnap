// olepasteDoc.cpp : implementation of the COlepasteDoc class
//

#include "stdafx.h"
#include "olepaste.h"

#include "olepasteDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COlepasteDoc

IMPLEMENT_DYNCREATE(COlepasteDoc, CDocument)

BEGIN_MESSAGE_MAP(COlepasteDoc, CDocument)
	//{{AFX_MSG_MAP(COlepasteDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COlepasteDoc construction/destruction

COlepasteDoc::COlepasteDoc()
{
	// TODO: add one-time construction code here

}

COlepasteDoc::~COlepasteDoc()
{
}

BOOL COlepasteDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// COlepasteDoc serialization

void COlepasteDoc::Serialize(CArchive& ar)
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
// COlepasteDoc diagnostics

#ifdef _DEBUG
void COlepasteDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COlepasteDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COlepasteDoc commands
