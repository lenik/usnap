// FRG.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#include "resource.h"

HANDLE	ghModule;

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	ghModule = hModule;
	return TRUE;
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
	TCHAR syntaxerror[32];
	TCHAR systemerror[32];
	int r;

	LoadString((HINSTANCE)ghModule, IDS_SYNTAX, syntaxerror, sizeof(syntaxerror) / sizeof(TCHAR));
	LoadString((HINSTANCE)ghModule, IDS_SYSTEMERROR, systemerror, sizeof(systemerror) / sizeof(TCHAR));

	if (nrhs != 3) {
		mexPrintf("%s\n", syntaxerror);
		return;
	}

	double forward_step = *mxGetPr(prhs[0]);
	double rotate_step = *mxGetPr(prhs[1]);
	LONG steps = (LONG)*mxGetPr(prhs[2]);
	LONG ps;

	double anglesum = 0;
	double xsum = 0;
	double ysum = 0;

	r = 0;
	if (nlhs == 1) {
		mxArray *res1;
		res1 = mxCreateDoubleMatrix(2, steps, mxREAL);
		if (res1 == NULL) {
			mexPrintf("%s\n", systemerror);
			return;
		}
		double *datas = mxGetPr(res1);
		steps *= 2;
		for (ps = 0; ps < steps; ps += 2) {
			datas[ps] = xsum;
			datas[ps + 1] = ysum;
			anglesum += (ps / 2) * rotate_step;
			xsum += forward_step * cos(anglesum);
			ysum += forward_step * sin(anglesum);
		}
		mxDestroyArray(plhs[0]);
		plhs[0] = res1;
	} else if (nlhs == 2) {
		mxArray *res2_x, *res2_y;
		res2_x = mxCreateDoubleMatrix(1, steps, mxREAL);
		if (res2_x == NULL) {
			mexPrintf("%s\n", systemerror);
			return;
		}
		res2_y = mxCreateDoubleMatrix(1, steps, mxREAL);
		if (res2_y == NULL) {
			mexPrintf("%s\n", systemerror);
			mxDestroyArray(res2_x);
			return;
		}
		double *xdatas = mxGetPr(res2_x);
		double *ydatas = mxGetPr(res2_y);
		for (ps = 0; ps < steps; ps++) {
			xdatas[ps] = xsum;
			ydatas[ps] = ysum;
			anglesum += ps * rotate_step;
			xsum += forward_step * cos(anglesum);
			ysum += forward_step * sin(anglesum);
		}
		mxDestroyArray(plhs[0]);
		mxDestroyArray(plhs[1]);
		plhs[0] = res2_x;
		plhs[1] = res2_y;
	} else {
		mexPrintf("%s\n", syntaxerror);
		return;
	}
}
