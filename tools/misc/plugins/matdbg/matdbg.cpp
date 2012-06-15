// matdbg.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#define ARRAY_ACCESS_INLINING
#include <mex.h>

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{

	return TRUE;
}


void DumpArrayBytes(mxArray *pA) {
	char buf[1024];
	char *pb = buf;
	BYTE *p0 = (BYTE *)pA;

	pb += sprintf(pb, "mxArray %s (%08x)\n", pA->name, pA);

	for (int i = 0; i < sizeof(mxArray); i++) {
		pb += sprintf(pb, "%02x ", *p0++);
		if (i % 16 == 15) pb += sprintf(pb, "\n");
	}

	pb += sprintf(pb, "\nmxArray::pdata->... (header 128 bytes)\n");
	p0 = (BYTE *)pA->data.number_array.pdata;

	for (i = 0; i < 128; i++) {
		pb += sprintf(pb, "%02x ", *p0++);
		if (i % 16 == 15) pb += sprintf(pb, "\n");
	}
	pb += sprintf(pb, "\n");

	mexPrintf(buf);
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]) {
	if (nrhs < 1) {
		mexErrMsgTxt("One input required.");
		return;
	}

	while (nrhs > 0) {
		DumpArrayBytes(*prhs);
		prhs++;
		nrhs--;
	}
}
