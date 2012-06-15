// rcpeDoc.cpp : implementation of the CRcpeDoc class
//

#include "stdafx.h"
#include "rcpeApp.h"

#include "rcpeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRcpeDoc

IMPLEMENT_DYNCREATE(CRcpeDoc, CDocument)

BEGIN_MESSAGE_MAP(CRcpeDoc, CDocument)
	//{{AFX_MSG_MAP(CRcpeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRcpeDoc construction/destruction

CRcpeDoc::CRcpeDoc()
{
	// TODO: add one-time construction code here

}

CRcpeDoc::~CRcpeDoc()
{
}

BOOL CRcpeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRcpeDoc serialization

void CRcpeDoc::Serialize(CArchive& ar)
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
// CRcpeDoc diagnostics

#ifdef _DEBUG
void CRcpeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRcpeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRcpeDoc commands
