// CeE3D_Client1Doc.cpp : implementation of the CCeE3D_Client1Doc class
//

#include "stdafx.h"
#include "CeE3D_Client1.h"

#include "CeE3D_Client1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCeE3D_Client1Doc

IMPLEMENT_DYNCREATE(CCeE3D_Client1Doc, CDocument)

BEGIN_MESSAGE_MAP(CCeE3D_Client1Doc, CDocument)
	//{{AFX_MSG_MAP(CCeE3D_Client1Doc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CCeE3D_Client1Doc, CDocument)
	//{{AFX_DISPATCH_MAP(CCeE3D_Client1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//      DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

static const IID IID_ICeE3D_Client1 =
{ 0x7d34fd6a, 0xa651, 0x4005, { 0x81, 0xb0, 0x61, 0x3f, 0xe8, 0xa2, 0x86, 0x9a } };

BEGIN_INTERFACE_MAP(CCeE3D_Client1Doc, CDocument)
	INTERFACE_PART(CCeE3D_Client1Doc, IID_ICeE3D_Client1, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCeE3D_Client1Doc construction/destruction

CCeE3D_Client1Doc::CCeE3D_Client1Doc()
{
	EnableAutomation();

	AfxOleLockApp();
}

CCeE3D_Client1Doc::~CCeE3D_Client1Doc()
{
	AfxOleUnlockApp();
}

BOOL CCeE3D_Client1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCeE3D_Client1Doc serialization

void CCeE3D_Client1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCeE3D_Client1Doc diagnostics

#ifdef _DEBUG
void CCeE3D_Client1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCeE3D_Client1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCeE3D_Client1Doc commands
