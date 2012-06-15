// CMineDoc.cpp : implementation of the CCMineDoc class
//

#include "stdafx.h"
#include "CMine.h"

#include "CMineDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCMineDoc

IMPLEMENT_DYNCREATE(CCMineDoc, CDocument)

BEGIN_MESSAGE_MAP(CCMineDoc, CDocument)
	//{{AFX_MSG_MAP(CCMineDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCMineDoc construction/destruction

CCMineDoc::CCMineDoc()
{
	// TODO: add one-time construction code here

}

CCMineDoc::~CCMineDoc()
{
}

BOOL CCMineDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCMineDoc serialization

void CCMineDoc::Serialize(CArchive& ar)
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
// CCMineDoc diagnostics

#ifdef _DEBUG
void CCMineDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCMineDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCMineDoc commands
