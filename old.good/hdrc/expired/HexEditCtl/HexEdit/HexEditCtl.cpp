// HexEditCtl.cpp : Implementation of CHexEditCtl

#include "stdafx.h"
#include "HexEdit.h"
#include "HexEditCtl.h"

/////////////////////////////////////////////////////////////////////////////
// CHexEditCtl

HRESULT CHexEditCtl::OnDraw(ATL_DRAWINFO& di)
{
    RECT& rc = *(RECT*)di.prcBounds;
    Rectangle(di.hdcDraw, rc.left, rc.top, rc.right, rc.bottom);

    SetTextAlign(di.hdcDraw, TA_CENTER|TA_BASELINE);
    LPCTSTR pszText = _T("ATL 3.0 : HexEditCtl");
    TextOut(di.hdcDraw,
        (rc.left + rc.right) / 2,
        (rc.top + rc.bottom) / 2,
        pszText,
        lstrlen(pszText));

    return S_OK;
}

LRESULT CHexEditCtl::OnChar(UINT uMsg ,WPARAM wParam,LPARAM lParam, BOOL& bHandled)
{
    int nChar = int (wParam);

    ASSERT(m_lpData && m_nDataLength > 0);
	BYTE delayedChar = nChar >> 8;


	long offset = m_nViewOffset + m_nRow * m_nWidth + m_nCol;
	ASSERT(offset < m_nDataLength);

	BYTE& by = m_lpData[offset];

	__try {
		if (m_bEditOnChars) {
			if (nChar < 0x20) return 0;

			by = (BYTE)(char)nChar;
		} else {
			if (nChar >= 'a' && nChar <= 'z') nChar = nChar - 0x20;
			if (!strchr("0123456789ABCDEF", nChar)) {
				return 0;
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

		OnKeyDown(uMsg,VK_RIGHT, 1, bHandled);

        InvalidateRect(NULL, TRUE);

        return 0;

	} __finally {
		//if (delayedChar != 0) {
		//	OnChar(delayedChar, 1, 0);
		//}
		m_bDirty = TRUE;
	}

    return 0 ;
}

LRESULT CHexEditCtl::OnLeftMouse(UINT uMsg ,WPARAM wParam,LPARAM lParam, BOOL& bHandled)
{
    HDC hDC = ::GetDC(m_hWnd);

    int x = lParam & 0xffffu;
    int y = lParam >> 16;

	int x1 ,y1;

	x1 = (x - m_leftMargin - 9 * m_tm.tmAveCharWidth) / m_tm.tmAveCharWidth;

	y1 = (y - m_topMargin ) / m_tm.tmHeight ;

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

    return 0;
}

LRESULT CHexEditCtl::OnKeyDown(UINT uMsg ,WPARAM wParam,LPARAM lParam, BOOL& bHandled)
{
    BOOL bRefresh = FALSE;
	BOOL bUpdateCaret = FALSE;

    int nChar = (int)wParam;

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
    return 0;
}


BOOL CHexEditCtl::Refresh()
{

	ASSERT (m_nWidth != 0 );
	ASSERT (m_lpData != NULL ) ;

    HDC hDC = ::GetDC(m_hWnd);

//	CFont *pOldFont = SelectStockFont(hDC);

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

//	SelectObject(hDC, pOldFont);
	return	TRUE;
}


BOOL CHexEditCtl::UpdateCaret()
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

int CHexEditCtl::effective_height() {
	ASSERT(m_nViewOffset >= 0 && m_nViewOffset < m_nDataLength);
	int nRestLen = m_nDataLength - m_nViewOffset;
	int HeightMax = (nRestLen + m_nWidth - 1 ) / m_nWidth ;
	if (HeightMax > m_nHeight ) HeightMax = m_nHeight ;
	return HeightMax;
}

int CHexEditCtl::effective_width(int row) {
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

void CHexEditCtl::OnFontChanged()
{
/*	if (!m_hWnd) return;
	CDC *pDC = GetDC();

	CFont *pOldFont = SelectStockFont(pDC);
	pDC->GetTextMetrics(&m_tm);
	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);

	InvalidateRect(NULL, TRUE); */
}

LRESULT CHexEditCtl::OnSizing(UINT uMsg ,WPARAM wParam,LPARAM lParam, BOOL& bHandled)
{/*
	int cx, cy;
	cx = m_leftMargin * 2 + m_tm.tmAveCharWidth * (9 + m_nWidth * 4);
	cy = m_topMargin * 2 + m_tm.tmHeight * m_nHeight;

	pRect->right = pRect->left + cx;
	pRect->bottom = pRect->top + cy; */
    return 0;
}

LRESULT CHexEditCtl::OnKillFocus(UINT uMsg ,WPARAM wParam,LPARAM lParam, BOOL& bHandled)
{
	::HideCaret(m_hWnd);
	ASSERT(DestroyCaret());
    return 0 ;
}

LRESULT CHexEditCtl::OnSetFocus(UINT uMsg ,WPARAM wParam,LPARAM lParam, BOOL& bHandled)
{

	BOOL b;
	HDC hDC = ::GetDC(m_hWnd);


	int cxBorder = ::GetSystemMetrics(SM_CXBORDER);
	b = ::CreateCaret(m_hWnd, m_hbmpCaret, cxBorder, m_tm.tmHeight);
	ASSERT(b);

	b = ::ShowCaret(m_hWnd);
	ASSERT(b);
    return 0 ;
}
