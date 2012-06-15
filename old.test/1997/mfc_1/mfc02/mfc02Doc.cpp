// mfc02Doc.cpp : implementation of the CMfc02Doc class
//

#include "stdafx.h"
#include "mfc02.h"

#include "mfc02Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMfc02Doc

IMPLEMENT_DYNCREATE(CMfc02Doc, CDocument)

BEGIN_MESSAGE_MAP(CMfc02Doc, CDocument)
	//{{AFX_MSG_MAP(CMfc02Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMfc02Doc construction/destruction

CMfc02Doc::CMfc02Doc()
{
	// TODO: add one-time construction code here

}

CMfc02Doc::~CMfc02Doc()
{
}

BOOL CMfc02Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMfc02Doc serialization

void CMfc02Doc::Serialize(CArchive& ar)
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
// CMfc02Doc diagnostics

#ifdef _DEBUG
void CMfc02Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMfc02Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMfc02Doc commands
