
#include "StdAfx.h"

#include "FastImg.h"

BOOL	_stdcall FI_Init_Alpha(DWORD amode) {
	int	mode	= amode >> 24;
	int	a1	= (amode & 0xFF00) >> 8;
	int	a2	= amode & 0xFF;
	int	rev	= a1 > a2;
		if (rev) { a1 += a2; a2 = a1 - a2; a1 = a1 - a2; }
	int	aw	= a2 - a1 + 1;
	int	alpha;

	switch (mode) {
	case 0:
		// ÏßÐÔ¹ý¶É
		for (alpha = 0; alpha < a1; alpha++) alphaTable[alpha] = 0;
		for (alpha = a1; alpha <= a2; alpha++)
			alphaTable[alpha] = (BYTE)((alpha - a1) * 256 / aw);
		for (alpha = a2 + 1; alpha <= 256; alpha++) alphaTable[alpha] = 255;
		break;
	case 1:
		//
		for (alpha = 0; alpha < a1; alpha++) alphaTable[alpha] = 0;
		for (alpha = a1; alpha <= a2; alpha++) {
			float a	= (float)(alpha - a1) / aw;
			a	= a * a * 256;
			alphaTable[alpha] = (BYTE)a;
		}
		for (alpha = a2 + 1; alpha <= 256; alpha++) alphaTable[alpha] = 255;
		break;
	case 0xFF:
		{
			FILE *f=fopen("C:\\alphacolor","w");
			if (f != NULL) {
				DWORD ai,ci;
				for(ai=0;ai<257;ai++) {
					fprintf(f,"\nalpha:%d",ai);
					for(ci=0;ci<256;ci++) {
						if (ci%16==0)fprintf(f,"\t\n");
						fprintf(f,"%2x ",alphaColor[ai][ci]);
					}
				}
				fclose(f);
			}
		}
	default: ;
	}

	if (rev) {
		int t;
		for (alpha = 0; alpha < 128; alpha++) {
			t = alphaTable[alpha];
			alphaTable[alpha] = alphaTable[256 - alpha];
			alphaTable[256 - alpha] = t;
		}
	}
	return TRUE;
}
