// test.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

void	mexFunction(int nlhs, mxArray	*plhs[],
		    int nrhs, const mxArray *prhs[]) {
	mexPrintf("nlhs = %d\nnrhs = %d\n\n", nlhs, nrhs);
	mexPrintf("Hello, world!\n");
	MessageBox(NULL, "Hello, world!\n", NULL, MB_OKCANCEL);
}
