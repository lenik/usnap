// BIGMouthDoc.cpp : implementation of the CBIGMouthDoc class
//

#include "stdafx.h"
#include "BIGMouth.h"

#include "BIGMouthDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBIGMouthDoc

IMPLEMENT_DYNCREATE(CBIGMouthDoc, CDocument)

BEGIN_MESSAGE_MAP(CBIGMouthDoc, CDocument)
	//{{AFX_MSG_MAP(CBIGMouthDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBIGMouthDoc construction/destruction

CBIGMouthDoc::CBIGMouthDoc()
{
	// TODO: add one-time construction code here

}

CBIGMouthDoc::~CBIGMouthDoc()
{
}

BOOL CBIGMouthDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBIGMouthDoc serialization

void CBIGMouthDoc::Serialize(CArchive& ar)
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
// CBIGMouthDoc diagnostics

#ifdef _DEBUG
void CBIGMouthDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBIGMouthDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBIGMouthDoc commands
