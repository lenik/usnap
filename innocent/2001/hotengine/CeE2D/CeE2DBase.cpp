
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

// ��ʼ��������, ����Э��ģʽ
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

// ���÷ֱ���, �����Ȼ�߶�Ϊ0������Ϊ����ģʽ
// �������ģʽ���ϴ���ͬ��ִ��, ����ȡ���ϴε�����ģʽ.
// �������ʧ�ܽ���ͼ���óɴ���ģʽ, ���޷��ָ��ϴε�����ģʽ
STDMETHODIMP
CeE2DBase::Resolution(LONG width, LONG height, LONG depth, BOOL *ret) {
	BOOL	inWindow = width == 0 || height == 0;
	HRESULT	hr;

	if (this->m_bInited) {
		// ���������ͬ��ֱ�ӷ���
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
		// �����»���
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
	// ���ٽ�����ҳ��
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
