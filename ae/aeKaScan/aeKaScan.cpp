
#include "stdafx.h"

#include "../mltAE/AEplugin.h"


HRESULT _stdcall MainProc(AEImage *pImage, AETextLayout *pTL);
HRESULT _stdcall FixedSelect(AEImage *pImage, double x0, double y0, double x1, double y1,
			     AEFont *pFont, CharAttribute **pCharSelected);
HRESULT _stdcall CharOrder(AEFont *pFont);
HRESULT _stdcall FontOrder(void *pFontsList);
HRESULT _stdcall OptimizeLayout(AETextLayout *pTL);


BOOL g_Initialized = FALSE;

AEKernelPluginHeader g_hdr;
AEConfig *g_pCfg = NULL;


BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	if (!g_Initialized) {
		__zero(g_hdr);
		//
		g_hdr.pszName		= _T("Fixed Scanner");
		g_hdr.major		= 1;
		g_hdr.minor		= 0;
		g_hdr.pszAuthor		= _T("Zauj.G.D.");
		g_hdr.pszCompany	= _T("MLT group");
		g_hdr.pszEmail		= _T("zaujgd@yahoo.com");
		g_hdr.pszWeb		= _T("http://groups.yahoo.com/group/mltae/");
		g_hdr.pszCopyright	= _T("Copyright 2003.4");
		g_hdr.hModule		= hModule;
		g_hdr.bSilenceMode	= TRUE;
		g_hdr.bSupportMode	= FALSE;

		//
		g_hdr.pfMain		= MainProc;
		g_hdr.pfFixedSelect	= FixedSelect;
		g_hdr.pfFontOrder	= FontOrder;
		g_hdr.pfOptimizeLayout	= OptimizeLayout;

		g_Initialized = TRUE;
	}
	return TRUE;
}


HRESULT _stdcall GetKernelPluginHeader(AEConfig *pSvrCfg, AEKernelPluginHeader **ppHdr) {
	g_pCfg = pSvrCfg;
	*ppHdr = &g_hdr;
	return S_OK;
}

HRESULT _stdcall MainProc(AEImage *pImage, AETextLayout *pTL) {

	FontPluginHeader *pFontHdr = (FontPluginHeader *)GetPluginInList(g_pCfg, g_pCfg->pFonts, 0);
	// aeKaScan use the first shape of first font as the default fix-sized image.
	int fw = pFontHdr->pFonts->pShapes->width;
	int fh = pFontHdr->pFonts->pShapes->height;

	int iCode;
	int blockx, blocky;
	HRESULT hr;
	for (blocky = 0; blocky < pImage->height; blocky += fh) {
		for (blockx = 0; blockx < pImage->width; blockx += fw) {
			CharAttribute *pCharSelected = NULL;
			hr = FixedSelect(pImage, blockx, blocky, blockx + fw - 1, blocky + fh - 1,
				pFontHdr->pFonts, // use only one font.
				&pCharSelected);
			if (FAILED(hr)) continue;

			ASSERT(pCharSelected != NULL);

			iCode = pCharSelected->id;

			//pTL->add...
		}
	}
	return S_OK;
}

HRESULT _stdcall FixedSelect(AEImage *pImage, double x0, double y0, double x1, double y1,
			     AEFont *pFont, CharAttribute **ppCharSelected) {
	ASSERT(pImage);
	ASSERT(ppCharSelected);
	ASSERT(x0 > 0 && y0 > 0 && x1 > 0 && y1 > 0 &&
		x0 < x1 && y0 < y1 &&
		x0 < pImage->width && x1 < pImage->width &&
		y0 < pImage->height && y0 < pImage->height);

	int nChars = pFont->chars;
	ASSERT(nChars > 0);
	if (nChars <= 0) return E_INVALIDARG;

	//double *matchval = new double[pFont->nChars];
	// for each char in font
	double *matchVal = new double[nChars];
	for (int iChar = 0; iChar < nChars; iChar++) {
		AEImage& shp = pFont->pShapes[iChar];
		AEFont::charshape *pshpdata = (AEFont::charshape *)shp.pvTypeSpecfic;

		matchVal[iChar] = 0.0;

		pImage->pImage

	}

	return S_OK;
}

// compare 2 images, (stretch algorithm may be considered on different size)
// out: pQRef: reference value for similar level, the value is defined by caller,
//		but larger value > 0 for different, and <= 0 for the similar.
HRESULT _stdcall CompareImage(AEImage *pA, double Ax0, double Ay0, double Ax1, double Ay1,
			      AEImage *pB, double Bx0, double By0, double Bx1, double By1,
			      double *pQRef) {
	ASSERT(pA && pB && pQRef &&
		pA->pImage && pB->pImage &&
		Ax0 < Ay0 && Ax1 < Ay1 &&
		Bx0 < By0 && Bx1 < By1);

	int Aw = (int)(Ax1 - Ax0);
	int Ah = (int)(Ay1 - Ay0);
	int Bw = (int)(Bx1 - Bx0);
	int Bh = (int)(By1 - By0);

	// aeKaScan only support compare between 2 same type/size image.
	if (Aw != Bw || Ah != Bh) return E_INVALIDARG;
	if (pA->type != pB->type || pA->bits != pB->bits) return E_INVALIDARG;

	// aeKaScan return the count of different points as the similar level.
	long cDiffs = 0;
	DWORD *pSrc = (DWORD *)pA->pImage + Ay0 * Aw;
	DWORD *pDst = (DWORD *)pB->pImage + By0 * Bw;
	for (long y = 0; y < h; y++) {
		pSrc += (int)Ax0;
		pDst += (int)Bx0;
		for (long x = 0; x < w; x++) {
			if (*pSrc != *pDst) cDiffs++;
		}
		pSrc += Aw - Ax1;
		pDst += Bw - Bx1;
	}

	*pQRef = (double)cDiffs;

	return S_OK;
}

// compare image with one font shape
// out: pQRef: see CompareImage/pQRef.
HRESULT _stdcall CompareImageWithFontShape(AEImage *pImg, double x0, double y0, double x1, double y1,
					   AEImage *pFontShape, AEFont::charshape *pDefShape,
					   double *pQRef) {
	ASSERT(pImg && pFontShape && pDefShape && pQRef &&
		pImg->pImage && pFontShape->pImage &&
		x0 < x1 && y0 < y1);

	// aeKaScan didn't support vector font.
	if (pDefShape->vector_image) return E_NOTIMPL;
	// aeKaScan didn't support colorized font.
	if (pDefShape->colorized) return E_NOTIMPL;

	long w = (int)(x1 - x0);
	long h = (int)(y1 - y0);
	long fw = pFontShape->width;
	long fh = pFontShape->height;

	if (pImg->type != pFontShape->type || pImg->bits != pFontShape->bits) {
		return E_NOTIMPL;
	}

	HRESULT hr;
	hr = CompareImage(pImg, x0, y0, x1, y1,
		pFontShape, 0, 0, (double)w, (double)h,
		pQRef);
	return hr;
}

// define chars order ( e.g. ASCII '\x20' is more important than '\xFF', though they were all spaces.)
HRESULT _stdcall CharOrder(AEFont *pFont) {
	ASSERT(pFont);

	return S_OK;
}

struct _fontord_power {
	DWORD dwCharSet;
	FontHeader::_t_purpose purpose;
	int major;
	int minor;
	void *pListEntry;
};

HRESULT _stdcall FontOrder(void *pFontsList) {
	ASSERT(pFontsList);
	int nFonts = GetPluginsCount(pFontsList);
	// offset bytes of pluginheader from listentry.
	long cbListHdr = (long)GetPluginInList(g_pCfg, pFontsList, 0) - (long)pFontsList;

	ASSERT(nFonts);
	_fontord_power *pPowers = new _fontord_power[nFonts];
	if (!pPowers) return E_OUTOFMEMORY;

	int iFont;
	for (iFont = 0; iFont < nFonts; iFont++) {
		FontPluginHeader *pHdr = (FontPluginHeader *)GetPluginInList(g_pCfg, pFontsList, iFont);
		FontHeader *pRawHdr = pHdr->font.pFontHdr;

		pPowers[iFont].dwCharSet = pRawHdr->dwCharSet;
		pPowers[iFont].purpose = pRawHdr->purpose;
		pPowers[iFont].major = pRawHdr->major;
		pPowers[iFont].minor = pRawHdr->minor;
		pPowers[iFont].pListEntry = (void *)((long)pHdr - cbListHdr);
	}

	qsort(pPowers, sizeof(_fontord_power), nFonts, _fontord_cmp);

	void *pEntry = pFontsList;
	((void **)pEntry)[0] = pPowers[1].pListEntry;	// list[0]->next = sorted[1]
	((void **)pEntry)[1] = NULL;	// list[0]->prev = NULL;
	for (iFont = 1; iFont < nFonts - 1; iFont++) {
		((void **)pEntry)[0] = pPowers[iFont].pListEntry;
		((void **)pEntry)[1] = pPowers[iFont - 1].pListEntry;
		pEntry = *(void **)pEntry;	// next entry
	}
	((void **)pEntry)[0] = NULL;	// list[nFonts - 1]->next = NULL;



	return S_OK;
}

HRESULT _stdcall OptimizeLayout(AETextLayout *pTL) {
	return S_OK;
}
