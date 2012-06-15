// htmlHelloDoc.cpp : implementation of the CHtmlHelloDoc class
//

#include "stdafx.h"
#include "htmlHello.h"

#include "htmlHelloDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHtmlHelloDoc

IMPLEMENT_DYNCREATE(CHtmlHelloDoc, CDocument)

BEGIN_MESSAGE_MAP(CHtmlHelloDoc, CDocument)
	//{{AFX_MSG_MAP(CHtmlHelloDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHtmlHelloDoc construction/destruction

CHtmlHelloDoc::CHtmlHelloDoc()
{
	// TODO: add one-time construction code here

}

CHtmlHelloDoc::~CHtmlHelloDoc()
{
}

BOOL CHtmlHelloDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHtmlHelloDoc serialization

void CHtmlHelloDoc::Serialize(CArchive& ar)
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
// CHtmlHelloDoc diagnostics

#ifdef _DEBUG
void CHtmlHelloDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHtmlHelloDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHtmlHelloDoc commands
