// MazeView.cpp : implementation of the CMazeView class
//

#include "stdafx.h"
#include "Maze.h"

#include "MazeDoc.h"
#include "MazeView.h"

#include "_Maze.h"

#include <stdarg.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMazeView

IMPLEMENT_DYNCREATE(CMazeView, CView)

BEGIN_MESSAGE_MAP(CMazeView, CView)
	//{{AFX_MSG_MAP(CMazeView)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMazeView construction/destruction

CMazeView::CMazeView()
{
	// TODO: add construction code here

}

CMazeView::~CMazeView()
{
}

BOOL CMazeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMazeView drawing

CString vtos(BoxMaze::vector& v) {
	CString s;
	BoxMaze::vector::iterator i, j;
	for (i = v.begin(); i != v.end(); ++i) {
		CString n;
		n.Format("%d", *i);
		s += n;
		j = i;
		if (++j != v.end()) {
			s += ", ";
		}
	}
	return s;
}

void CMazeView::OnDraw(CDC* pDC)
{
	CMazeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	int line = 0;
	typedef std::list<std::string> strings;
	char buf[100];
	strings showstr;

	BoxMaze::ranges& r = pDoc->maze._r;
	BoxMaze::ranges::iterator ri;
	for (ri = r.begin(); ri != r.end(); ++ri) {
		BoxMaze::vector& rl = ri->first;
		BoxMaze::vector& rr = ri->second;
		sprintf(buf, "%d: (%s)-(%s)", line++, vtos(rl), vtos(rr));
		showstr.push_back(buf);
	}

	strings::iterator si;
	line = 0;
	for (si = showstr.begin(); si != showstr.end(); ++si) {
		pDC->TextOut(10, line * 20, si->c_str());
		line++;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMazeView printing

BOOL CMazeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMazeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMazeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMazeView diagnostics

#ifdef _DEBUG
void CMazeView::AssertValid() const
{
	CView::AssertValid();
}

void CMazeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMazeDoc* CMazeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMazeDoc)));
	return (CMazeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMazeView message handlers

int CMazeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: Add your specialized creation code here

	// 1 try to create listbox
	// 2 try to show the list of ranges

	return 0;
}
