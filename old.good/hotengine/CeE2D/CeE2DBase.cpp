
#include "StdAfx.h"

#include "resource.h"

#include "CeE2D.h"
#include "CeE2DBase.h"
#include "CeE2DPage.h"

#import "CeE2D.tlb"

CeE2DBase::CeE2DBase() {
	this->m_hWnd		= NULL;
	this->m_bInited		= FALSE;
	this->m_bInWindowMode	= TRUE;
	this->m_nResWidth	= 0;
	this->m_nResHeight	= 0;
	this->m_nResDepth	= 0;
	this->m_lpDD		= NULL;
}

CeE2DBase::~CeE2DBase() {
	if (this->m_lpDD != NULL) {
		m_lpDD->Release();
	}
}

// 初始化基本库, 设置协作模式
STDMETHODIMP
CeE2DBase::init(HWND hWnd) {
	LPDIRECTDRAW	lpDD = NULL;
	HRESULT hr;
	hr = DirectDrawCreate(NULL, &lpDD, NULL);
	if (FAILED(hr)) return hr;
	hr = lpDD->SetCooperativeLevel(hWnd, DDSCL_NORMAL);
	if (FAILED(hr)) {
		lpDD->Release();
		return hr;
	}
	if (this->m_lpDD != NULL) {
		this->m_lpDD->Release();
		this->m_lpDD	= lpDD;
	}
	this->m_hWnd		= hWnd;
	this->m_bInited		= TRUE;
	this->m_bInWindowMode	= TRUE;

	return NOERROR;
}

// 设置分辨率, 如果宽度或高度为0则设置为窗口模式
// 如果设置模式与上次相同则不执行, 否则取消上次的设置模式.
// 如果设置失败将试图设置成窗口模式, 但无法恢复上次的设置模式
STDMETHODIMP
CeE2DBase::Resolution(LONG width, LONG height, LONG depth, BOOL *ret) {
	BOOL	inWindow = width == 0 || height == 0;
	HRESULT	hr;

	if (this->m_bInited) {
		// 如果设置相同则直接返回
		if (this->m_bInWindowMode == TRUE) {
			if (inWindow == TRUE) {
				return NOERROR;
			}
		} else {
			if (!inWindow) {
				if (width == this->m_nResWidth &&
					height == this->m_nResHeight &&
					depth == this->m_nResDepth) {
					return NOERROR;
				}
			}
		}

		this->m_bInited = FALSE;
		// 建立新环境
		LPDIRECTDRAW	lpDD;
		hr = DirectDrawCreate(NULL, &lpDD, NULL);
		if (FAILED(hr)) return hr;
		if (this->m_lpDD != NULL) {
			this->m_lpDD->Release();
		}
		this->m_lpDD = lpDD;

		if (inWindow) {
			hr = this->m_lpDD->SetCooperativeLevel(this->m_hWnd, DDSCL_NORMAL);
			if (FAILED(hr)) return hr;

			this->m_bInWindowMode	= TRUE;
			this->m_nResWidth	= width;
			this->m_nResHeight	= height;
		} else {
			hr = this->m_lpDD->SetCooperativeLevel(this->m_hWnd,
				DDSCL_FULLSCREEN | DDSCL_EXCLUSIVE);
			if (FAILED(hr)) return hr;

			hr = this->m_lpDD->SetDisplayMode(width, height, depth);
			if (FAILED(hr)) return hr;

			this->m_bInWindowMode	= TRUE;
			this->m_nResWidth	= width;
			this->m_nResHeight	= height;
			this->m_nResDepth	= depth;
		}
		this->m_bInited	= TRUE;
	} else {
		return this->Resolution(0, 0, depth, ret);
	}
	return NOERROR;
}

STDMETHODIMP
CeE2DBase::CreatePage(LONG width, LONG height, LONG nAdditionPages, BOOL bOffScreen, ICeE2DPage **ret) {
	// 至少建立主页面
	HRESULT		hr;
	DDSURFACEDESC	ddsd;
	LPDIRECTDRAWSURFACE lpdds;
	ICeE2DPage	*ppage;

	*ret		= NULL;

	ddsd.dwSize	= sizeof(DDSURFACEDESC);
	ddsd.dwFlags	= DDSD_CAPS;
	ddsd.ddsCaps.dwCaps	= bOffScreen ? DDSCAPS_OFFSCREENPLAIN : DDSCAPS_PRIMARYSURFACE;
	if (nAdditionPages > 0) {
		ddsd.dwFlags		 |= DDSD_BACKBUFFERCOUNT;
		ddsd.dwBackBufferCount	 = nAdditionPages;
		ddsd.ddsCaps.dwCaps	 |= DDSCAPS_COMPLEX | DDSCAPS_FLIP;
	}
	hr = this->m_lpDD->CreateSurface(&ddsd, &lpdds, NULL);
	if (FAILED(hr)) {
		return hr;
	}

	ppage	= new CCeE2DPage;
	ppage->AddRef();

	hr = ((CeE2DPage *)ppage)->init(lpdds, nAdditionPages);
	if (FAILED(hr)) {
		ppage->Release();
		return hr;
	}

	*ret		= ppage;
	return NOERROR;
}
