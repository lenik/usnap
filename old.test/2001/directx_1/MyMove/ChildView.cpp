// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "MyMove.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildView

LPDIRECTDRAW			lpDD;
LPDIRECTDRAWSURFACE		lpDDSPrimary;
LPDIRECTDRAWCLIPPER		lpDDCPrimary;
LPDIRECTDRAWSURFACE		lpDDSBack;
LPDIRECTDRAWSURFACE		lpDDSSprite;

LPCTSTR	szBack   = MAKEINTRESOURCE(IDB_BACKGROUND);
LPCTSTR szSprite = MAKEINTRESOURCE(IDB_SPRITE);

CRect	rcPrimary;
BOOL	bActive;
int		nsx = 100, nsy = 100;

void releaseAll() {
	if (lpDD != NULL) {
		if (lpDDSPrimary != NULL) {
			lpDDSPrimary->Release();
			lpDDSPrimary = NULL;
		}
		lpDD->Release();
		lpDD = NULL;
	}
	//exit(0);
}

LPDIRECTDRAWPALETTE DDLoadPalette(LPDIRECTDRAW, LPCTSTR);
LPDIRECTDRAWSURFACE DDLoadBitmap(LPDIRECTDRAW, LPCTSTR, int, int);
HRESULT DDCopyBitmap(LPDIRECTDRAWSURFACE, HBITMAP, int, int, int, int);
HRESULT DDReloadBitmap(LPDIRECTDRAWSURFACE, LPCTSTR);
HRESULT DDSetColorKey(LPDIRECTDRAWSURFACE, COLORREF);
DWORD	DDColorMatch(LPDIRECTDRAWSURFACE, COLORREF);

LPDIRECTDRAWPALETTE DDLoadPalette(LPDIRECTDRAW lpDD, LPCTSTR szBitmap) {
	LPDIRECTDRAWPALETTE lpDDPal = NULL;
	HRSRC				h;
	LPBITMAPINFOHEADER	lpbi;
	PALETTEENTRY		ape[256];
	LPRGBQUAD			prgb;

	int	i, nClr;

	if (!szBitmap) return NULL;

	for (i = 0; i < 256; i++) {
		ape[i].peRed   = (BYTE)(((i >> 5) & 0x07) * 255 / 7);
		ape[i].peGreen = (BYTE)(((i >> 3) & 0x07) * 255 / 7);
		ape[i].peBlue  = (BYTE)(((i >> 0) & 0x03) * 255 / 3);
		ape[i].peFlags = 0;
	}

	h = FindResource(NULL, szBitmap, RT_BITMAP);
	if (h != NULL) {
		lpbi = (LPBITMAPINFOHEADER)LockResource(LoadResource(NULL, h));
		if (lpbi != NULL) {
			if (lpbi->biSize >= sizeof(BITMAPINFOHEADER)) {
				prgb = (LPRGBQUAD)((BYTE *)lpbi + lpbi->biSize);
				if (lpbi->biBitCount <= 8) {
					if (lpbi->biClrUsed == 0)
						nClr = 1 << lpbi->biBitCount;
					else
						nClr = lpbi->biClrUsed;
					for (i = 0; i < nClr; i++) {
						ape[i].peRed   = prgb[i].rgbRed;
						ape[i].peGreen = prgb[i].rgbGreen;
						ape[i].peBlue  = prgb[i].rgbBlue;
					}
					lpDD->CreatePalette(DDPCAPS_8BIT, ape, &lpDDPal, NULL);
					return lpDDPal;
				}
			}
		}
	}

	return NULL;
}

LPDIRECTDRAWSURFACE DDLoadBitmap(LPDIRECTDRAW lpDD, LPCTSTR szBitmap, int dx, int dy) {
	HBITMAP			hbm;
	BITMAP			bm;
	DDSURFACEDESC	ddsd;
	LPDIRECTDRAWSURFACE	lpDDS;
	HRESULT			hr;

	hbm = (HBITMAP)LoadImage(GetModuleHandle(NULL), szBitmap, IMAGE_BITMAP, dx, dy, LR_CREATEDIBSECTION);
	if (hbm != NULL) {
		GetObject(hbm, sizeof(bm), &bm);

		ddsd.dwSize   = sizeof(ddsd);
		ddsd.dwFlags  = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT;
		ddsd.dwWidth  = bm.bmWidth;
		ddsd.dwHeight = bm.bmHeight;
		ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN;
		if ((hr = lpDD->CreateSurface(&ddsd, &lpDDS, NULL)) == DD_OK) {
			if ((hr = DDCopyBitmap(lpDDS, hbm, 0, 0, 0, 0)) == DD_OK) {
				DeleteObject(hbm);
				return lpDDS;
			} else
				lpDDS->Release();
		} else
			DeleteObject(hbm);
	}
	return NULL;
}

HRESULT DDCopyBitmap(LPDIRECTDRAWSURFACE lpDDS, HBITMAP hbm, int x, int y, int dx, int dy) {
	HDC				hdcImage;
	HDC				hdcDDS;
	BITMAP			bm;
	DDSURFACEDESC	ddsd;
	HRESULT			hr;

	if (lpDDS == NULL || hbm == NULL) return E_FAIL;

	lpDDS->Restore();

	hdcImage = CreateCompatibleDC(NULL);
	if (hdcImage != NULL) {
		SelectObject(hdcImage, hbm);
		GetObject(hbm, sizeof(bm), &bm);
		if (dx == 0) dx = bm.bmWidth;
		if (dy == 0) dy = bm.bmHeight;

		ddsd.dwSize = sizeof(ddsd);
		ddsd.dwFlags = DDSD_WIDTH | DDSD_HEIGHT;
		lpDDS->GetSurfaceDesc(&ddsd);

		if ((hr = lpDDS->GetDC(&hdcDDS)) == DD_OK) {
			StretchBlt(hdcDDS, 0, 0, ddsd.dwWidth, ddsd.dwHeight, hdcImage, x, y, dx, dy, SRCCOPY);
			lpDDS->ReleaseDC(hdcDDS);
		}

		DeleteDC(hdcImage);

		return hr;
	}

	return E_FAIL;
}

HRESULT DDReloadBitmap(LPDIRECTDRAWSURFACE lpDDS, LPCTSTR szBitmap) {
	HBITMAP		hbm;
	HRESULT		hr;

	hbm = (HBITMAP)LoadImage(GetModuleHandle(NULL), szBitmap, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	if (hbm != NULL) {
		hr = DDCopyBitmap(lpDDS, hbm, 0, 0, 0, 0);
		DeleteObject(hbm);
		return hr;
	}

	return E_FAIL;
}

HRESULT DDSetColorKey(LPDIRECTDRAWSURFACE lpDDS, COLORREF c) {
	DDCOLORKEY	ddck;
	ddck.dwColorSpaceLowValue  = DDColorMatch(lpDDS, c);
	ddck.dwColorSpaceHighValue = ddck.dwColorSpaceLowValue;

	return lpDDS->SetColorKey(DDCKEY_SRCBLT, &ddck);
}

DWORD DDColorMatch(LPDIRECTDRAWSURFACE lpDDS, COLORREF c) {
	HDC				hDC;
	COLORREF		tc;
	DWORD			dw = CLR_INVALID;
	DDSURFACEDESC	ddsd;
	HRESULT			hres;

	if (c != CLR_INVALID && lpDDS->GetDC(&hDC) == DD_OK) {
		tc = GetPixel(hDC, 0, 0);
		SetPixel(hDC, 0, 0, c);
		lpDDS->ReleaseDC(hDC);
	}

	ddsd.dwSize = sizeof(ddsd);
	while ((hres = lpDDS->Lock(NULL, &ddsd, 0, NULL)) == DDERR_WASSTILLDRAWING)
		;

	if (hres == DD_OK) {
		dw = *(DWORD *)ddsd.lpSurface;
		if (ddsd.ddpfPixelFormat.dwRGBBitCount < 32)
			dw &= (1 << ddsd.ddpfPixelFormat.dwRGBBitCount) - 1;
		lpDDS->Unlock(NULL);
	}

	if (c != CLR_INVALID && lpDDS->GetDC(&hDC) == DD_OK) {
		SetPixel(hDC, 0, 0, tc);
		lpDDS->ReleaseDC(hDC);
	}

	return dw;
}

CChildView::CChildView()
{
	bActive = FALSE;

}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS,
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);
	return TRUE;
}

BOOL CChildView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: Add your specialized code here and/or call the base class

	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd ::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: Add your specialized creation code here
	HRESULT			ddrval;
	DDSURFACEDESC	ddsd;
	char			buf[1024];

	if ((ddrval = DirectDrawCreate(NULL, &lpDD, NULL)) != DD_OK) goto ddinit_error;

#ifdef fullscreen
	ddrval = lpDD->SetCooperativeLevel(this->m_hWnd, DDSCL_FULLSCREEN | DDSCL_EXCLUSIVE);
	lpDD->SetDisplayMode(640, 480, 8);
#else
	ddrval = lpDD->SetCooperativeLevel(this->m_hWnd, DDSCL_NORMAL);
#endif
	if (ddrval != DD_OK) goto ddinit_error;

	ddsd.dwSize = sizeof(ddsd);
	ddsd.dwFlags = DDSD_CAPS;
	ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
	ddrval = lpDD->CreateSurface( &ddsd, &lpDDSPrimary, NULL );
	if (ddrval != DD_OK) goto ddinit_error;

	if (lpDD->CreateClipper(0, &lpDDCPrimary, NULL) != DD_OK) goto ddinit_error;
	if (lpDDCPrimary->SetHWnd(0, this->m_hWnd) != DD_OK) goto ddinit_error;
	if (lpDDSPrimary->SetClipper(lpDDCPrimary) != DD_OK) goto ddinit_error;

	lpDDSBack = DDLoadBitmap(lpDD, szBack, 0, 0);
	if (ddrval != DD_OK) goto ddinit_error;

	lpDDSPrimary->Blt(NULL, lpDDSBack, NULL, 0, NULL);

	lpDDSSprite = DDLoadBitmap(lpDD, szSprite, 0, 0);
	if (lpDDSSprite == NULL) goto ddinit_error;

	if (DDSetColorKey(lpDDSSprite, CLR_INVALID) != DD_OK) goto ddinit_error;

	return 0;

ddinit_error:
	wsprintf(buf, "Failed to init DirectDraw: %ld (%lx) ", ddrval, ddrval);

	MessageBox(buf);

	releaseAll();

	return -1;
}

void ShowOn(LPDIRECTDRAWSURFACE dest, int x, int y) {
	CRect rectSrc(0, 0, 0, 0), rectDest(0, 0, 0, 0);
	DDSURFACEDESC ddsd;

	ddsd.dwSize  = sizeof(ddsd);
	ddsd.dwFlags = DDSD_WIDTH | DDSD_HEIGHT;
	dest->GetSurfaceDesc(&ddsd);
	rectDest.SetRect(0, 0, ddsd.dwWidth, ddsd.dwHeight);

	lpDDSPrimary->BltFast(x, y, dest, rectDest, DDBLTFAST_SRCCOLORKEY);
}

CRect GetRect(HWND hWnd) {
	CRect	rect;
	POINT	point;
	point.x = point.y = 0;
	GetClientRect(hWnd, rect);
	ClientToScreen(hWnd, &point);
	rect += point;
	return rect;
}

void CChildView::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	// TODO: Add your message handler code here
	rcPrimary = GetRect(this->m_hWnd);
	//DDReloadBitmap(lpDDSBack, szBack);
	ShowOn(lpDDSSprite, nsx, nsy);
	//lpDDSPrimary->Blt(rcPrimary, lpDDSBack, NULL, 0, NULL);
	CString str;
	str.Format("snx=%d  sny=%d", nsx, nsy);
	//dc.TextOut(20, 20, str);
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	switch (nChar) {
	case VK_LEFT:
		nsx -= nRepCnt;
		break;
	case VK_RIGHT:
		nsx += nRepCnt;
		break;
	case VK_UP:
		nsy -= nRepCnt;
		break;
	case VK_DOWN:
		nsy += nRepCnt;
		break;
	default: ;
	}
	Invalidate(FALSE);
	CWnd ::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	DDSURFACEDESC	ddsd;
	ddsd.dwSize = sizeof(ddsd);
	ddsd.dwFlags = DDSD_WIDTH | DDSD_HEIGHT;
	lpDDSBack->GetSurfaceDesc(&ddsd);
	nsx = point.x * ddsd.dwWidth / rcPrimary.Width();
	nsy = point.y * ddsd.dwHeight / rcPrimary.Height();
	Invalidate(FALSE);
	CWnd ::OnMouseMove(nFlags, point);
}
