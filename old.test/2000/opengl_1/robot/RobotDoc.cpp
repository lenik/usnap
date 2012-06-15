// RobotDoc.cpp : implementation of the CRobotDoc class
//

#include "stdafx.h"
#include "Robot.h"

#include "RobotDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRobotDoc

IMPLEMENT_DYNCREATE(CRobotDoc, CDocument)

BEGIN_MESSAGE_MAP(CRobotDoc, CDocument)
	//{{AFX_MSG_MAP(CRobotDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRobotDoc construction/destruction

CRobotDoc::CRobotDoc()
{
	// TODO: add one-time construction code here

}

CRobotDoc::~CRobotDoc()
{
}

BOOL CRobotDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRobotDoc serialization

void CRobotDoc::Serialize(CArchive& ar)
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
// CRobotDoc diagnostics

#ifdef _DEBUG
void CRobotDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRobotDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRobotDoc commands
