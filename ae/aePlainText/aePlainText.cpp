
#include "stdafx.h"

#include "../mltAE/AEplugin.h"


HRESULT _stdcall MainProc(AETextLayout *pTextLayout, AEFont *pFontUsing);

BOOL g_Initialized = FALSE;

OutputPluginHeader g_hdr;
AEConfig *g_pCfg = NULL;


BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	if (!g_Initialized) {
		__zero(g_hdr);
		g_hdr.pszName		= _T("Plain Text");
		g_hdr.major		= 1;
		g_hdr.minor		= 0;
		g_hdr.pszAuthor		= _T("Zauj.G.D.");
		g_hdr.pszCompany	= _T("MLT group");
		g_hdr.pszEmail		= _T("zaujgd@yahoo.com");
		g_hdr.pszWeb		= _T("http://groups.yahoo.com/group/mltae/");
		g_hdr.pszCopyright	= _T("Copyright 2003.4");
		g_hdr.hModule		= hModule;
		g_hdr.bSilenceMode	= TRUE;
		g_hdr.bSupportMode	= TRUE;
		lstrcpy(g_hdr.szSupportCode, _T(".txt"));
		g_hdr.pfMain		= MainProc;

		g_Initialized = TRUE;
	}
	return TRUE;
}


HRESULT _stdcall GetOutputPluginHeader(AEConfig *pSvrCfg, OutputPluginHeader **ppHdr) {
	g_pCfg = pSvrCfg;
	*ppHdr = &g_hdr;
	return S_OK;
}

HRESULT _stdcall MainProc(AETextLayout *pTextLayout, AEFont *pFontUsing) {
	ASSERT(pTextLayout && pFontUsing);
	if (!g_pCfg->cfg.pszOutputFile) return E_UNEXPECTED;

	//
	//
	// N@ PlainText's re-transform:
	//	this is designed for large-font, or font-split -> recombination.
	//	e.g., if char-'O' is in somewhere of text layout, then it may split into '('')'
	//	      after spliting, '()' can contain in more precise position.
	//
	//	not implemented yet.
	//
	//

	// sum sub-layouts into -> single array. after sumed, sort them.
	long calc_chars(AETextLayout *);
	long chars_sum = calc_chars(pTextLayout);

	CharAttribute **sorted = new CharAttribute*[chars_sum];
	if (!sorted) return E_OUTOFMEMORY;

	long dump_to_array(AETextLayout *, CharAttribute **);
	long ndumped = dump_to_array(pTextLayout, sorted);
	ASSERT(ndumped == chars_sum);

	int _cdecl _layout_xy_cmp(CharAttribute *pCA1, CharAttribute *pCA2);
	int (_cdecl *layout_xy_cmp)(const void *a, const void *b) =
		(int (_cdecl *)(const void *, const void *))_layout_xy_cmp;
	qsort((void *)sorted, chars_sum, sizeof(CharAttribute *), layout_xy_cmp);

	// make the stuff-filled text paragraph correspond to the layout.
	BOOL bExtraSpace = g_pCfg->cfg.bSpaceFilled;
	// current text position. (column,row)
	int tx = 0, ty = 0;
	std::string text;
	std::string line;

	// use the font size as default fixed char size
	// note that the char-shape->pImage is the defined image's area, not the font's.
	int fixc_w = pTextLayout->pChars->pFont->default_shape.logfont.lfWidth;
	int fixc_h = pTextLayout->pChars->pFont->default_shape.logfont.lfHeight;

	for (long ic = 0; ic < ndumped; ic++) { // ic: i_Char
		double cx = sorted[ic]->x;
		double cy = sorted[ic]->y;
		int cxt = (int)cx;
		int cyt = (int)cy;

		cxt = (cxt - cxt % fixc_w) / fixc_w;
		cyt = (cyt - cyt % fixc_h) / fixc_h;

		if (cyt < ty) continue;
		if (cyt > ty) {
			// break the line, and make pre-spaces.
			text += line;
			text += _T("\n");
			line = "";
			tx = 0;
			ty++;

			while (cyt > ty) {
				text += _T("\n");
				ty++;
			}
		}
		// now cyt == ty
		while (tx < cxt - 1) {
			line += _T(" ");
			tx++;
		}
		// append the char after the line
		line += (TCHAR)(sorted[ic]->pCharShape->id);
		tx++;
	}

	text += line;
	SAFE_DELETE_ARRAY(sorted);

	FILE *pOut = _tfopen(g_pCfg->cfg.pszOutputFile, _T("wt"));
	if (pOut == NULL) return E_UNEXPECTED;

	// N@: Unicode version
	_ftprintf(pOut, _T("%s"), text.c_str());

	fclose(pOut);

	return S_OK;
}



long calc_chars(AETextLayout *pTL) {
	if (pTL->bIgnored) return 0;

	long sum = pTL->nElements;
	if (pTL->nSubGroups > 0) {
		for (long i = 0; i < pTL->nSubGroups; i++) {
			sum += calc_chars(pTL->pSubGroups + i);
		}
	}
	return sum;
}

long dump_to_array(AETextLayout *pTL, CharAttribute **ppCA) {
	if (pTL->bIgnored) return 0;

	// ASSERT_VALID(ppCA[0..pTL->nElem]);
	long linear_index;
	for (linear_index = 0; linear_index < pTL->nElements; linear_index++) {
		ppCA[linear_index] = pTL->pChars + linear_index;
	}
	if (pTL->nSubGroups > 0) {
		long i;
		for (i = 0; i < pTL->nSubGroups; i++) {
			linear_index += dump_to_array(pTL->pSubGroups + i, ppCA + linear_index);
		}
	}
	// return the next linear_index after all of this pTL group.
	// when nSubGroup == 0, the linear_index will be same as nElem.
	return linear_index;
}

int _cdecl _layout_xy_cmp(CharAttribute *pCA1, CharAttribute *pCA2) {
	// N@ this seems not efficiency. but not serious at all.
	int align_w = pCA1->pFont->default_shape.logfont.lfWidth;
	int align_h = pCA1->pFont->default_shape.logfont.lfHeight;

	// y is always aligned, this is because we must include as much in a single line,
	// compared to y, x's aligning isn't so important. why?
	//	because the textlayout is assumed no overlapped between chars.
	// it is still a good idea to ignore the overlapped chars, to make a truer text image.

	// N@ negative Y position doesn't take mind, here.
	int x1 = pCA1->x;
	int y1 = pCA1->y;
	int x2 = pCA2->x;
	int y2 = pCA2->y;

	y1 -= y1 % align_h;
	y2 -= y2 % align_h;

	if (y1 < y2) return -1;
	if (y1 > y2) return 1;
	if (x1 < x2) return -1;
	if (x1 > x2) return 1;

	// it is never happened if chars do not overlap, but may be when the kernel adjuster
	// use some special algorithm.
	// whatever, overlap will be detected at the later compositing, before the text generating.
	return 0;
}
