// wmfviewView.cpp : implementation of the CWmfviewView class
//

#include "stdafx.h"
#include "wmfview.h"

#include "wmfviewDoc.h"
#include "wmfviewView.h"

#include "wmfDecode.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWmfviewView

IMPLEMENT_DYNCREATE(CWmfviewView, CScrollView)

BEGIN_MESSAGE_MAP(CWmfviewView, CScrollView)
	//{{AFX_MSG_MAP(CWmfviewView)
	ON_COMMAND(ID_VIEW_INFO, OnViewInfo)
	ON_COMMAND(ID_VIEW_INFO2, OnViewInfo2)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWmfviewView construction/destruction

CWmfviewView::CWmfviewView()
{
}

CWmfviewView::~CWmfviewView()
{
}

BOOL CWmfviewView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CWmfviewView drawing

void CWmfviewView::OnDraw(CDC* pDC)
{
	CWmfviewDoc* pDoc = GetDocument();
	if (pDoc->m_file.m_hFile != CFile::hFileNull) {
		try {
			DWORD oldPos = pDoc->m_file.GetPosition();
			pDoc->m_file.Seek(sizeof(wmfHeader) + sizeof(wmfHeader2), CFile::begin);

			wmfRecord rec;

			int i;
			SIZE fsize;
			GetTextExtentPoint(pDC->m_hDC, "X", 1, &fsize);
			fsize.cy = (int)((float)fsize.cy * 1.2);

			TRY {
				DWORD fLen = pDoc->m_file.GetLength();
				for (i = 0; pDoc->m_file.GetPosition() < fLen; i++) {	// N@
					pDoc->m_file.Read(&rec, sizeof(wmfRecord));
					pDC->MoveTo(10, i * fsize.cy);
					wmfDecode(pDC, rec.fn, NULL, rec.cb);
					LONG lOff = (rec.cb - 3) * sizeof(WORD);
					pDoc->m_file.Seek(lOff > 0 ? lOff : 0, CFile::current);
				}
			} CATCH(CFileException, fe) {
				fe->ReportError();
			} END_CATCH;

			SIZE sizeTotal;
			sizeTotal.cx = 200;
			sizeTotal.cy = i * fsize.cy;
			SetScrollSizes(MM_TEXT, sizeTotal);

			pDoc->m_file.Seek(oldPos, CFile::begin);
		} catch (CFileException *fe) {
			fe->ReportError();
		}
	}
	ASSERT_VALID(pDoc);
}

/////////////////////////////////////////////////////////////////////////////
// CWmfviewView printing

BOOL CWmfviewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CWmfviewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CWmfviewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

/////////////////////////////////////////////////////////////////////////////
// CWmfviewView diagnostics

#ifdef _DEBUG
void CWmfviewView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CWmfviewView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CWmfviewDoc* CWmfviewView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWmfviewDoc)));
	return (CWmfviewDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWmfviewView message handlers

void CWmfviewView::OnViewInfo()
{
	// TODO: Add your command handler code here
	CWmfviewDoc *pDoc = this->GetDocument();
	if (pDoc->m_file.m_hFile != CFile::hFileNull) {
		DWORD pos = pDoc->m_file.GetPosition();
		wmfHeader hdr;

		pDoc->m_file.SeekToBegin();
		pDoc->m_file.Read((LPVOID)&hdr, sizeof(wmfHeader));
		pDoc->m_file.Seek(pos, CFile::begin);

		m_infoDlg.SetWindowText("WMF文件信息" + pDoc->m_file.GetFileName());
		m_infoDlg.m_strKEY.Format(PRN_IDS_FIXNUM, hdr.key, hdr.key);
		m_infoDlg.m_strHMF.Format(PRN_IDS_NUM, hdr.hmf, hdr.hmf);
		m_infoDlg.m_strINCH.Format(PRN_IDS_NUM, hdr.inch, hdr.inch);
		m_infoDlg.m_strCHECKSUM.Format(PRN_IDS_NUM, hdr.checksum, hdr.checksum);
		m_infoDlg.m_strRESERVED.Format(PRN_IDS_NUM, hdr.reserved, hdr.reserved);
		m_infoDlg.m_strBBOX.Format(PRN_IDS_RECT, hdr.bboxP1x, hdr.bboxP1y, hdr.bboxP2x, hdr.bboxP2y);
		m_infoDlg.UpdateData(FALSE);
		m_infoDlg.ShowWindow(SW_NORMAL);
		m_infoDlg.UpdateWindow();
	}
}

void CWmfviewView::OnViewInfo2()
{
	// TODO: Add your command handler code here
	CWmfviewDoc *pDoc = this->GetDocument();
	if (pDoc->m_file.m_hFile != CFile::hFileNull) {
		DWORD pos = pDoc->m_file.GetPosition();
		wmfHeader2 hdr2;

		pDoc->m_file.Seek(sizeof(wmfHeader), CFile::begin);
		pDoc->m_file.Read((LPVOID)&hdr2, sizeof(wmfHeader2));
		pDoc->m_file.Seek(pos, CFile::begin);

		m_info2Dlg.SetWindowText("WMF头部信息:" + pDoc->m_file.GetFileName());
		switch (hdr2.mtType) {
		case 0:
			m_info2Dlg.m_strTYPE = "0/在内存中";
			break;
		case 1:
			m_info2Dlg.m_strTYPE = "1/在文件中";
			break;
		default:
			m_info2Dlg.m_strTYPE.Format("%d'%x/未知类型", hdr2.mtType, hdr2.mtType);
		}
		m_info2Dlg.m_strHDRSIZE.Format(PRN_IDS_NUM, hdr2.mtHeaderSize, hdr2.mtHeaderSize);
		m_info2Dlg.m_strMAXREC.Format(PRN_IDS_NUM, hdr2.mtMaxRecords, hdr2.mtMaxRecords);
		m_info2Dlg.m_strNOOBJ.Format(PRN_IDS_NUM, hdr2.mtNoObject, hdr2.mtNoObject);
		m_info2Dlg.m_strNOPARAM.Format(PRN_IDS_NUM, hdr2.mtNoParameters, hdr2.mtNoParameters);
		m_info2Dlg.m_strSIZE.Format(PRN_IDS_NUM, hdr2.mtSize, hdr2.mtSize);
		m_info2Dlg.m_strVERSION.Format(PRN_IDS_NUM, hdr2.mtVersion, hdr2.mtVersion);
		m_info2Dlg.UpdateData(FALSE);
		m_info2Dlg.ShowWindow(SW_NORMAL);
		m_info2Dlg.UpdateWindow();
	}
}

int CWmfviewView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CScrollView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: Add your specialized creation code here
	SIZE s;
	s.cx = 80;
	s.cy = 20;
	SetScrollSizes(MM_TEXT, s);
	return 0;
}
