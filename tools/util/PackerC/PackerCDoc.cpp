// PackerCDoc.cpp : implementation of the CPackerCDoc class
//

#include "stdafx.h"
#include "PackerC.h"

#include "PackerCDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPackerCDoc

IMPLEMENT_DYNCREATE(CPackerCDoc, CDocument)

BEGIN_MESSAGE_MAP(CPackerCDoc, CDocument)
	//{{AFX_MSG_MAP(CPackerCDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPackerCDoc construction/destruction

CPackerCDoc::CPackerCDoc()
{
	// TODO: add one-time construction code here

}

CPackerCDoc::~CPackerCDoc()
{
}

BOOL CPackerCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPackerCDoc serialization

void CPackerCDoc::Serialize(CArchive& ar)
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
// CPackerCDoc diagnostics

#ifdef _DEBUG
void CPackerCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPackerCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPackerCDoc commands
