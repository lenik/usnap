// DrawerDoc.cpp : implementation of the CDrawerDoc class
//

#include "stdafx.h"
#include "Drawer.h"

#include "DrawerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawerDoc

IMPLEMENT_DYNCREATE(CDrawerDoc, CDocument)

BEGIN_MESSAGE_MAP(CDrawerDoc, CDocument)
	//{{AFX_MSG_MAP(CDrawerDoc)
	ON_COMMAND(ID_SHOW_ITER_DLG, OnShowIterDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawerDoc construction/destruction

CDrawerDoc::CDrawerDoc()
{
	// TODO: add one-time construction code here
	m_pDlgIter = new CIterDialog(this);
	m_igCount = 0;
}

CDrawerDoc::~CDrawerDoc()
{
	if (m_pDlgIter != NULL) delete m_pDlgIter;
}

BOOL CDrawerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CDrawerDoc serialization

void CDrawerDoc::Serialize(CArchive& ar)
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
// CDrawerDoc diagnostics

#ifdef _DEBUG
void CDrawerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrawerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawerDoc commands

void CDrawerDoc::OnShowIterDlg()
{
	// TODO: Add your command handler code here
	m_pDlgIter->ShowWindow(SW_NORMAL);
}
