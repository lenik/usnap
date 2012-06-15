// ProcessViewer01Doc.cpp : implementation of the CProcessViewer01Doc class
//

#include "stdafx.h"
#include "ProcessViewer01.h"

#include "ProcessViewer01Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProcessViewer01Doc

IMPLEMENT_DYNCREATE(CProcessViewer01Doc, CDocument)

BEGIN_MESSAGE_MAP(CProcessViewer01Doc, CDocument)
	//{{AFX_MSG_MAP(CProcessViewer01Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProcessViewer01Doc construction/destruction

CProcessViewer01Doc::CProcessViewer01Doc()
{
	// TODO: add one-time construction code here

}

CProcessViewer01Doc::~CProcessViewer01Doc()
{
}

BOOL CProcessViewer01Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CProcessViewer01Doc serialization

void CProcessViewer01Doc::Serialize(CArchive& ar)
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
// CProcessViewer01Doc diagnostics

#ifdef _DEBUG
void CProcessViewer01Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CProcessViewer01Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CProcessViewer01Doc commands
