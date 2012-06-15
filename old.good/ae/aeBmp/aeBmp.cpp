// aeBmp.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#include "../mltAE/AEplugin.h"


BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

GraphPluginHeader hdr  = {
	"BMP plugin",
		1,
		0,
		"s",
		..

		,
		TRUE,
		TRUE,
		,. ..
		'BMP'


		&main
}


AEConfig *g_pCfg;

HRESULT _stdcall GetPluginHeaderProc(AEConfig *pSvrCfg, PluginHeader **ppHdr) {
	g_pCfg = pSvrCfg;

	*ppHdr = &hdr;

}


HRESULT main(AEImage *pImg) {
	pSvrCfg->filename


}
