// ssViewView.cpp : implementation of the CSsViewView class
//

#include "stdafx.h"
#include "ssView.h"

#include "ssViewDoc.h"
#include "ssViewView.h"

#include "ssEleCon.h"
#include "makeSS\makeSS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSsViewView

IMPLEMENT_DYNCREATE(CSsViewView, CView)

BEGIN_MESSAGE_MAP(CSsViewView, CView)
	//{{AFX_MSG_MAP(CSsViewView)
	ON_COMMAND(ID_VIEW_SS, OnViewSs)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSsViewView construction/destruction

CSsViewView::CSsViewView() : m_ssDialog(NULL)
{
	// TODO: add construction code here
	m_ssDialog.Create(IDD_SS, NULL);
}

CSsViewView::~CSsViewView()
{
}

BOOL CSsViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSsViewView drawing

void CSsViewView::OnDraw(CDC* pDC)
{
	CSsViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSsViewView printing

BOOL CSsViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSsViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSsViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSsViewView diagnostics

#ifdef _DEBUG
void CSsViewView::AssertValid() const
{
	CView::AssertValid();
}

void CSsViewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSsViewDoc* CSsViewView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSsViewDoc)));
	return (CSsViewDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSsViewView message handlers

void CSsViewView::OnViewSs()
{
	// TODO: Add your command handler code here
	m_ssDialog.ShowWindow(SW_NORMAL);

}

void CSsViewView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	m_ssDialog.m_pviewOwner	= this;
	CString windowText;
	windowText	= this->GetDocument()->GetTitle();
	windowText.Insert(0, _T("Structure Storage View: "));
	m_ssDialog.SetWindowText(windowText);

	// Init controls
	HRESULT	hr = StgIsStorageFile(towcs(GetDocument()->GetPathName()));

	CTreeCtrl	&tStg	= m_ssDialog.m_treeStorage;
	CTreeCtrl	&tCnt	= m_ssDialog.m_treeContent;
	HTREEITEM	hI;

	#define OPITEM(treectrl, item)	treectrl.SetItemData(item, (treectrl.GetItemData(item)

	if (hr != S_OK) {
		hI	= tStg.InsertItem(_T("\\"), 0, 0);
		OPITEM(tStg, hI), ELE_PLAIN));
	} else {
		HTREEITEM	hI;
		hI	= tStg.InsertItem(_T("\\"), 0, 0);
		tStg.SetItemData(hI, ELE_STORAGE | ELE_ROOT);
		hr	= StgOpenStorage(
			towcs(GetDocument()->GetPathName()),
			NULL,
			STGM_TRANSACTED | STGM_READWRITE | STGM_SHARE_DENY_NONE,
			NULL, 0, &m_ssDialog.m_pStg);
		if (FAILED(hr)) {
			OPITEM(tStg, hI) | ELE_ERROR));
		}
	}
}
