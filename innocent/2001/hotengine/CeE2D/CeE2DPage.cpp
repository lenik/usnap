
#include "StdAfx.h"

#include "resource.h"

#include "CeE2D.h"
#include "CeE2DPage.h"


CeE2DPage::CeE2DPage() {
	this->m_bInited		= FALSE;
	this->m_lpDDS		= NULL;
	this->m_lpCurrentDDS	= NULL;
	this->m_nPages		= 0;
	this->m_bDrawing	= FALSE;
	this->m_hDC		= NULL;
	this->m_bLocked		= FALSE;
	this->m_lpMemoryBase	= NULL;
}

CeE2DPage::~CeE2DPage() {
	if (this->m_bLocked) {
		this->ProcessEnd();
	}
	if (this->m_bDrawing) {
		this->DrawEnd();
	}
	if (this->m_lpCurrentDDS != NULL) {
		m_lpCurrentDDS->Release();
	}
	if (this->m_lpDDS != NULL) {
		m_lpDDS->Release();
	}
}

STDMETHODIMP
CeE2DPage::init(LPDIRECTDRAWSURFACE lpDDS, DWORD nPages) {
	//HRESULT			hr;
	LPDIRECTDRAWSURFACE	lpdds = NULL;
	// 初始化页面, 设置切换页面
	if (lpDDS == NULL || nPages < 0) return E_FAIL;

	//hr = lpDDS->GetAttachedSurface(&ddscaps, &lpdds);
	//if (FAILED(hr)) return hr;

	this->m_lpDDS	= lpDDS;
	this->m_nPages	= nPages;
	this->m_bInited	= TRUE;
	return NOERROR;
}

STDMETHODIMP
CeE2DPage::get_lpdds(LPDIRECTDRAWSURFACE *ret) {
	*ret = this->m_lpDDS;
	return NOERROR;
}

STDMETHODIMP
CeE2DPage::NextPage(ICeE2DPage **ret) {
	HRESULT			hr;
	LPDIRECTDRAWSURFACE	lpdds = NULL;
	DDSCAPS			ddscaps;
	ICeE2DPage		*ppage;

	if (!this->m_bInited) return E_FAIL;

	ppage	 = new CCeE2DPage;
	ppage->AddRef();

	ddscaps.dwCaps = DDSCAPS_BACKBUFFER;
	hr = this->m_lpDDS->GetAttachedSurface(&ddscaps, &lpdds);
	if (FAILED(hr)) return hr;

	hr = ((CeE2DPage *)ppage)->init(lpdds, this->m_nPages);
	if (FAILED(hr)) {
		lpdds->Release();
		return hr;
	}

	*ret	= ppage;
	return NOERROR;
}

STDMETHODIMP
CeE2DPage::SwapPage() {
	HRESULT hr;

	if (!this->m_bInited) return E_FAIL;

	hr = this->m_lpDDS->Flip(NULL, DDFLIP_WAIT);
	if (FAILED(hr)) {
		return hr;
	}

	return NOERROR;
}

STDMETHODIMP
CeE2DPage::DrawBegin(HDC *ret) {
	HRESULT hr;
	HDC hdc;

	if (!this->m_bInited) return E_FAIL;
	if (this->m_bDrawing) return E_FAIL;
	if (this->m_bLocked) return E_FAIL;

	hr = this->m_lpDDS->GetDC(&hdc);
	if (FAILED(hr)) {
		return hr;
	}

	this->m_hDC		= hdc;
	this->m_bDrawing	= TRUE;

	*ret = hdc;
	return NOERROR;
}

STDMETHODIMP
CeE2DPage::DrawEnd() {
	HRESULT hr;

	if (!this->m_bInited) return E_FAIL;
	if (!this->m_bDrawing) return E_FAIL;

	hr = this->m_lpDDS->ReleaseDC(this->m_hDC);
	if (FAILED(hr)) {
		return hr;
	}

	this->m_hDC		= NULL;
	this->m_bDrawing	= FALSE;
	return NOERROR;
}

STDMETHODIMP
CeE2DPage::ProcessBegin(LONG *ret) {
	HRESULT hr;
	DDSURFACEDESC ddsd;

	if (!this->m_bInited) return E_FAIL;
	if (this->m_bDrawing) return E_FAIL;
	if (this->m_bLocked) return E_FAIL;

	hr = this->m_lpDDS->Lock(NULL, &ddsd, DDLOCK_WAIT, NULL);
	if (FAILED(hr)) {
		return E_FAIL;
	}

	this->m_bLocked		= TRUE;
	this->m_lpMemoryBase	= ddsd.lpSurface;

	*ret	= (LONG)this->m_lpMemoryBase;

	return NOERROR;
}

STDMETHODIMP
CeE2DPage::ProcessEnd() {
	HRESULT hr;

	if (!this->m_bInited) return E_FAIL;
	if (!this->m_bLocked) return E_FAIL;

	hr = this->m_lpDDS->Unlock(this->m_lpMemoryBase);
	if (FAILED(hr)) {
		return hr;
	}

	this->m_lpMemoryBase	= NULL;
	this->m_bLocked		= FALSE;

	return NOERROR;
}

STDMETHODIMP
CeE2DPage::BitBlt(ICeE2DPage *pdest, LONG destx, LONG desty, LONG width, LONG height, LONG srcx, LONG srcy, LONG rop) {
	HRESULT			hr;
	LPDIRECTDRAWSURFACE	lpddsDest	= NULL;
	DWORD			bltFlags	= 0;
	DDBLTFX			ddbltfx;
	RECT			rectdest;
	RECT			rectsrc;

	if (pdest == NULL) return E_FAIL;

	hr = ((CeE2DPage *)pdest)->get_lpdds(&lpddsDest);
	if (FAILED(hr)) return hr;

	bltFlags = DDBLT_ROP;
	ddbltfx.dwSize	= sizeof(DDBLTFX);
	ddbltfx.dwROP	= rop;
	rectdest.left	= destx;
	rectdest.top	= desty;
	rectdest.right	= destx + width - 1;
	rectdest.bottom	= desty + height - 1;
	rectsrc.left	= srcx;
	rectsrc.top	= srcy;
	rectsrc.right	= rectdest.right;
	rectsrc.bottom	= rectdest.bottom;
	hr = lpddsDest->Blt(&rectdest, this->m_lpDDS, &rectsrc, bltFlags, &ddbltfx);
	if (FAILED(hr)) {
		return hr;
	}

	return NOERROR;
}
