// MazeDoc.cpp : implementation of the CMazeDoc class
//

#include "stdafx.h"
#include "Maze.h"

#include "MazeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMazeDoc

IMPLEMENT_DYNCREATE(CMazeDoc, CDocument)

BEGIN_MESSAGE_MAP(CMazeDoc, CDocument)
	//{{AFX_MSG_MAP(CMazeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMazeDoc construction/destruction

CMazeDoc::CMazeDoc()
{
	// TODO: add one-time construction code here

}

CMazeDoc::~CMazeDoc()
{
}

void setvector(BoxMaze::vector& v, int dims, ...) {
	va_list args;
	va_start(args, dims);
	//va_arg(args, int);
	v.resize(dims);
	for (int i = 0; i < dims; i++) {
		v[i] = va_arg(args, BoxMaze::vector::size_type);
	}
	va_end(args);
}

BOOL CMazeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	BoxMaze::range rg;	// top range
	BoxMaze::connection conn;

	maze.map.dimensions = 4;

	setvector(rg.first, maze.map.dimensions,
		10, 10, 10, 10);
	setvector(rg.second, maze.map.dimensions,
		12, 12, 12, 12);

	maze.CreateWay(rg, conn);

	this->UpdateAllViews(NULL);

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMazeDoc serialization

void CMazeDoc::Serialize(CArchive& ar)
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
// CMazeDoc diagnostics

#ifdef _DEBUG
void CMazeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMazeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// Maze Core
