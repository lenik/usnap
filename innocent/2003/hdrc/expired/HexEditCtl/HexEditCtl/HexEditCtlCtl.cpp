// HexEditCtlCtl.cpp : Implementation of the CHexEditCtlCtrl ActiveX Control class.

#include "stdafx.h"
#include "HexEditCtl.h"
#include "HexEditCtlCtl.h"
#include "HexEditCtlPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CHexEditCtlCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CHexEditCtlCtrl, COleControl)
	//{{AFX_MSG_MAP(CHexEditCtlCtrl)
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEWHEEL()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_KILLFOCUS()
	ON_WM_SETFOCUS()
	ON_WM_CREATE()
	ON_WM_SIZING()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CHexEditCtlCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CHexEditCtlCtrl)
	DISP_STOCKPROP_FONT()
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CHexEditCtlCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CHexEditCtlCtrl, COleControl)
	//{{AFX_EVENT_MAP(CHexEditCtlCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CHexEditCtlCtrl, 2)
	PROPPAGEID(CHexEditCtlPropPage::guid)
    PROPPAGEID(CLSID_CFontPropPage)
END_PROPPAGEIDS(CHexEditCtlCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CHexEditCtlCtrl, "HEXEDITCTL.HexEditCtlCtrl.1",
	0xb9208ed7, 0x2ccf, 0x479a, 0xac, 0xe7, 0x12, 0x7, 0x1f, 0x12, 0xa9, 0xbb)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CHexEditCtlCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DHexEditCtl =
		{ 0x194ffe66, 0xe6ec, 0x47fe, { 0x8a, 0x71, 0x7b, 0x27, 0x4c, 0xc, 0x3a, 0x7f } };
const IID BASED_CODE IID_DHexEditCtlEvents =
		{ 0xf2bfa29b, 0xd63d, 0x471e, { 0xa3, 0xc2, 0x4a, 0x3c, 0x98, 0xaf, 0x57, 0xff } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwHexEditCtlOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CHexEditCtlCtrl, IDS_HEXEDITCTL, _dwHexEditCtlOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CHexEditCtlCtrl::CHexEditCtlCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CHexEditCtlCtrl

BOOL CHexEditCtlCtrl::CHexEditCtlCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_HEXEDITCTL,
			IDB_HEXEDITCTL,
			afxRegApartmentThreading,
			_dwHexEditCtlOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CHexEditCtlCtrl::CHexEditCtlCtrl - Constructor

CHexEditCtlCtrl::CHexEditCtlCtrl()
{
	InitializeIIDs(&IID_DHexEditCtl, &IID_DHexEditCtlEvents);

#ifdef _DEBUG
	m_lpData = (LPBYTE)strdup(
		"ASSOC    显示或修改文件扩展名关联。\n"
		"AT       计划在计算机上运行的命令和程序。\n"
		"ATTRIB   显示或更改文件属性。\n"
		"BREAK    设置或清除扩展式 CTRL+C 检查。\n"
		"CACLS    显示或修改文件的访问控制列表(ACLs)。\n"
		"CALL     从另一个批处理程序调用这一个。\n"
		"CD       显示当前目录的名称或将其更改。\n"
		"CHCP     显示或设置活动代码页数。\n"
		"CHDIR    显示当前目录的名称或将其更改。\n"
		"CHKDSK   检查磁盘并显示状态报告。\n"
		"CHKNTFS  显示或修改启动时间磁盘检查。\n"
		"CLS      清除屏幕。\n"
		);
	m_nDataLength = strlen((char* ) m_lpData);
	m_bRawOutput = TRUE;
#else
	m_lpData = 0;
	m_nDataLength = 0;
#endif
	m_nRow = 0;
	m_nCol = 0;
	m_nViewOffset = 0;
	m_nWidth = 16;
	m_nHeight = 8;
	m_leftMargin = 10;
	m_topMargin = 10;
	m_bDirty = 0;
	m_bHalf = 0;
}


/////////////////////////////////////////////////////////////////////////////
// CHexEditCtlCtrl::~CHexEditCtlCtrl - Destructor

CHexEditCtlCtrl::~CHexEditCtlCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CHexEditCtlCtrl::OnDraw - Drawing function

void CHexEditCtlCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	pdc->FillRect( & rcInvalid,NULL);
	Refresh(pdc);
}


/////////////////////////////////////////////////////////////////////////////
// CHexEditCtlCtrl::DoPropExchange - Persistence support

void CHexEditCtlCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CHexEditCtlCtrl::OnResetState - Reset control to default state

void CHexEditCtlCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CHexEditCtlCtrl::AboutBox - Display an "About" box to the user

void CHexEditCtlCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_HEXEDITCTL);
	dlgAbout.DoModal();
}

BOOL CHexEditCtlCtrl::Refresh(CDC* pdc)
{

	ASSERT (pdc != NULL) ;
	ASSERT (m_nWidth != 0 );
	ASSERT (m_lpData != NULL ) ;

	HDC hDC = pdc->m_hDC;

	CFont *pOldFont = SelectStockFont(pdc);

	int iRow ,iCol ;
	int HeightMax = effective_height();
	int ColMax;
	BYTE *pViewData = m_lpData + m_nViewOffset;

	for (iRow = 0; iRow < HeightMax; iRow ++)
	{
		// N@ ColMax != m_nWidth  ONLY IF  iRow >= HeightMax - 1
		ColMax = effective_width(iRow);

		char buf[1000],*pbuf;

		sprintf(buf, "%0X", m_nViewOffset + m_nWidth * iRow);

		TextOut( hDC, m_leftMargin ,m_topMargin + iRow * m_tm.tmHeight,
			buf,strlen(buf));

		strcpy(buf,"");

		pbuf = buf ;
		for (iCol = 0 ; iCol < ColMax ;iCol++)
		{
			pbuf += sprintf(pbuf,"%02X ", pViewData[iRow * m_nWidth + iCol]);
		}
		TextOut( hDC, m_leftMargin + 9 * m_tm.tmAveCharWidth ,
						m_topMargin + iRow * m_tm.tmHeight ,buf,strlen(buf) -1 );

		pbuf = buf;
		for (iCol = 0 ; iCol < ColMax ;iCol++)
		{
			int c = '?';
			int c0 = pViewData[iRow * m_nWidth + iCol];

			if (c0 >= 0x20 && c0 <= 0x7F) c = c0;
			if (m_bRawOutput && c0 > 0x7F) c = c0;

			pbuf += sprintf(pbuf,"%c", c);
		}
		TextOut(hDC,m_leftMargin + ( 9 + m_nWidth * 3) * m_tm.tmAveCharWidth,
				m_topMargin + iRow * m_tm.tmHeight ,buf,strlen(buf) );
	}

	SelectObject(hDC, pOldFont);
	return	TRUE;
}

void CHexEditCtlCtrl::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	BOOL bRefresh = FALSE;
	BOOL bUpdateCaret = FALSE;

	int maxHeight = effective_height();
	int maxWidth = effective_width(m_nRow);
	switch (nChar)
	{
	case VK_UP:
		if (m_nRow > 0) {
			m_nRow--;
		} else {
			if (m_nViewOffset - m_nWidth >= 0) {
				m_nViewOffset -= m_nWidth;
				bRefresh = TRUE;
			}
		}
		bUpdateCaret = TRUE;
		break;
	case VK_DOWN:
		if (m_nRow < maxHeight - 1) {
			m_nRow++;

			int newMaxWidth = effective_width(m_nRow);
			if (m_nCol >= newMaxWidth) m_nCol = newMaxWidth - 1;
		} else {
			if (m_nViewOffset + m_nHeight * m_nWidth < m_nDataLength) {
				m_nViewOffset += m_nWidth;
				int newMaxWidth = effective_width(m_nRow);
				if (m_nCol >= newMaxWidth) m_nCol = newMaxWidth - 1;
				bRefresh = TRUE;
			}
		}
		bUpdateCaret = TRUE;
		break;
	case VK_LEFT:
		if (!m_bEditOnChars && m_bHalf == TRUE) {
			m_bHalf = FALSE;
		} else {
			if (m_nCol > 0) {
				m_nCol--;
			} else {
				if (m_nViewOffset + m_nRow * m_nWidth + m_nCol - 1 >= 0) {
					m_nCol = m_nWidth - 1;

					// scroll down, if needed
					if (m_nRow - 1 >= 0) {
						m_nRow--;
					} else {
						if (m_nViewOffset >= m_nWidth) {
							m_nViewOffset -= m_nWidth;
							bRefresh = TRUE;
						}
					}
				}
			}
			if (!m_bEditOnChars) m_bHalf = TRUE;
		}
		bUpdateCaret = TRUE;
		break;
	case VK_RIGHT:
		if (!m_bEditOnChars && m_bHalf == FALSE) {
			m_bHalf = TRUE;
		} else {
			if (m_nCol < maxWidth - 1) {
				m_nCol++;
			} else {
				if (m_nViewOffset + m_nRow * m_nWidth + m_nCol + 1 < m_nDataLength) {
					m_nCol = 0;

					// scroll up, if needed.
					if (m_nRow + 1 < maxHeight) {
						m_nRow++;
					} else {
						if (m_nViewOffset + m_nHeight * m_nWidth < m_nDataLength) {
							m_nViewOffset += m_nWidth;
							bRefresh = TRUE;
						}
					}
				}
			}
			if (!m_bEditOnChars) m_bHalf = FALSE;
		}
		bUpdateCaret = TRUE;
		break;
	case VK_F2:
		m_bEditOnChars = !m_bEditOnChars;
		bUpdateCaret = TRUE;
		break;
	default:
		break;
	}

	if (bRefresh) InvalidateRect(NULL, TRUE);
	if (bUpdateCaret) UpdateCaret();
	COleControl::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CHexEditCtlCtrl::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	ASSERT(m_lpData && m_nDataLength > 0);
	BYTE delayedChar = nChar >> 8;

	long offset = m_nViewOffset + m_nRow * m_nWidth + m_nCol;
	ASSERT(offset < m_nDataLength);

	BYTE& by = m_lpData[offset];

	__try {
		if (m_bEditOnChars) {
			if (nChar < 0x20) return;

			by = (BYTE)(char)nChar;
		} else {
			if (nChar >= 'a' && nChar <= 'z') nChar = nChar - 0x20;
			if (!strchr("0123456789ABCDEF", nChar)) {
				return;
			}

			static int transtbl_30h[] = {
				0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -1, -1, -1, -1, -1,
				-1, 10, 11, 12, 13, 14, 15
			};
			BYTE val = (BYTE)transtbl_30h[nChar - 0x30];
			ASSERT(val != (BYTE)-1);
			if (m_bHalf) {
				// low half byte
				by = (by & 0xF0) | val;
			} else {
				// high half byte
				by = (by & 0x0F) | (val << 4);
			}
		}

		OnKeyDown(VK_RIGHT, 1, 0);
		InvalidateRect(NULL, TRUE);

		COleControl::OnChar(nChar, nRepCnt, nFlags);
		return;
	} __finally {
		//if (delayedChar != 0) {
		//	OnChar(delayedChar, 1, 0);
		//}
		m_bDirty = TRUE;
	}
}

void CHexEditCtlCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	HDC hDC = ::GetDC(m_hWnd);

	int x1,y1;

	x1 = (point.x - m_leftMargin - 9 * m_tm.tmAveCharWidth) / m_tm.tmAveCharWidth;

	y1 = (point.y - m_topMargin ) / m_tm.tmHeight ;

	if ( y1 < 0 ) y1 =0 ;
	else {
		int maxheight = effective_height();
		if (y1 >= maxheight) {
			y1 = maxheight - 1;
			if (y1 < 0) y1 = 0;
		}
	}

	if (x1 >= m_nWidth * 3 ) {
		m_bEditOnChars = TRUE;
		x1 -= m_nWidth * 3;
		if (x1 >= m_nWidth )
		{
			x1 = m_nWidth - 1;
		}
	}else{
		m_bEditOnChars = FALSE ;
		m_bHalf = x1 % 3;
		x1 = x1 / 3;
		if (x1 < 0 ) {
			x1 = 0;
			m_bHalf = FALSE;
		}
		else if (x1 >= m_nWidth )
		{
			x1 = m_nWidth - 1;
			m_bHalf = TRUE;
		}
	}

	int maxwidth = effective_width(y1);
	if (x1 >= maxwidth) {
		x1 = maxwidth - 1;
		ASSERT(x1 != 0);	// because the row (y1) never empty.
		if (x1 < 0) x1 = 0;
	}

	m_nCol = x1 ;
	m_nRow = y1 ;

	UpdateCaret();

	::ReleaseDC(m_hWnd, hDC);
	COleControl::OnLButtonDown(nFlags, point);
}

BOOL CHexEditCtlCtrl::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	int nv = m_nViewOffset - zDelta * m_nWidth ;
	if (nv < 0 ) {
		nv %= m_nWidth;
		nv = (nv + m_nWidth ) % m_nWidth ;
	} else if ( nv > m_nDataLength ){
		nv %= m_nWidth;
		if (nv >= (m_nDataLength % m_nWidth ))
		{
			nv = nv - m_nWidth ;
		}
	}

	return COleControl::OnMouseWheel(nFlags, zDelta, pt);
}

void CHexEditCtlCtrl::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default

	COleControl::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CHexEditCtlCtrl::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default

	COleControl::OnVScroll(nSBCode, nPos, pScrollBar);
}


BOOL CHexEditCtlCtrl::UpdateCaret()
{
	OnFontChanged();
	if (m_bEditOnChars)
	{
		::SetCaretPos (m_leftMargin +( 9 + m_nWidth * 3 + m_nCol ) * m_tm.tmAveCharWidth ,
			m_topMargin + m_nRow * m_tm.tmHeight);
	} else {
		::SetCaretPos (m_leftMargin +( 9 + m_nCol * 3 + (m_bHalf ? 1 : 0)) * m_tm.tmAveCharWidth ,
			m_topMargin + m_nRow * m_tm.tmHeight);
	}
	return TRUE;
}

void CHexEditCtlCtrl::OnKillFocus(CWnd* pNewWnd)
{
	COleControl::OnKillFocus(pNewWnd);
	::HideCaret(m_hWnd);
	ASSERT(DestroyCaret());
}

void CHexEditCtlCtrl::OnSetFocus(CWnd* pOldWnd)
{
	COleControl::OnSetFocus(pOldWnd);

	BOOL b;
	HDC hDC = ::GetDC(m_hWnd);


	int cxBorder = ::GetSystemMetrics(SM_CXBORDER);
	b = ::CreateCaret(m_hWnd, m_hbmpCaret, cxBorder, m_tm.tmHeight);
	ASSERT(b);

	b = ::ShowCaret(m_hWnd);
	ASSERT(b);
}

int CHexEditCtlCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_hbmpCaret = ::LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_CARET));
	ASSERT(m_hbmpCaret != NULL);

	return 0;
}

int CHexEditCtlCtrl::effective_height() {
	ASSERT(m_nViewOffset >= 0 && m_nViewOffset < m_nDataLength);
	int nRestLen = m_nDataLength - m_nViewOffset;
	int HeightMax = (nRestLen + m_nWidth - 1 ) / m_nWidth ;
	if (HeightMax > m_nHeight ) HeightMax = m_nHeight ;
	return HeightMax;
}

int CHexEditCtlCtrl::effective_width(int row) {
	ASSERT(m_nViewOffset >= 0 && m_nViewOffset < m_nDataLength);
	int nRestLen = m_nDataLength - m_nViewOffset;

	ASSERT(row >= 0 && row < effective_height());
	if (row < 0 || row >= effective_height()) return 0;

	int ColMax = m_nWidth;
	if ( (row + 1)* m_nWidth > nRestLen) {
		ColMax = nRestLen % m_nWidth;
		// this assertion is because of row < effective_height().
		ASSERT(ColMax != 0);
	}
	return ColMax;
}

void CHexEditCtlCtrl::OnFontChanged()
{
	if (!m_hWnd) return;
	CDC *pDC = GetDC();

	CFont *pOldFont = SelectStockFont(pDC);
	pDC->GetTextMetrics(&m_tm);
	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);

	InvalidateRect(NULL, TRUE);
}

BOOL CHexEditCtlCtrl::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Add your specialized code here and/or call the base class
	cs.style |= WS_VSCROLL;
	return COleControl::PreCreateWindow(cs);
}

void CHexEditCtlCtrl::OnSizing(UINT fwSide, LPRECT pRect)
{
	COleControl::OnSizing(fwSide, pRect);

	// TODO: Add your message handler code here
	int cx, cy;
	cx = m_leftMargin * 2 + m_tm.tmAveCharWidth * (9 + m_nWidth * 4);
	cy = m_topMargin * 2 + m_tm.tmHeight * m_nHeight;

	pRect->right = pRect->left + cx;
	pRect->bottom = pRect->top + cy;
}
