// LightDemoDoc.cpp : implementation of the CLightDemoDoc class
//

#include "stdafx.h"
#include "LightDemo.h"

#include "LightDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLightDemoDoc

IMPLEMENT_DYNCREATE(CLightDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CLightDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CLightDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLightDemoDoc construction/destruction

CLightDemoDoc::CLightDemoDoc()
{
	// TODO: add one-time construction code here

}

CLightDemoDoc::~CLightDemoDoc()
{
}

BOOL CLightDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLightDemoDoc serialization

void CLightDemoDoc::Serialize(CArchive& ar)
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
// CLightDemoDoc diagnostics

#ifdef _DEBUG
void CLightDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLightDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLightDemoDoc commands
