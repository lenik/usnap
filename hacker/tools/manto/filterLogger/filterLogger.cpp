// filterLogger.cpp : 定义 DLL 应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <httpfilt.h>
#include <EXCPT.H>
#include <WTYPES.H>

#include "filterLogger.h"

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
    return TRUE;
}

BOOL WINAPI __stdcall
GetFilterVersion(HTTP_FILTER_VERSION *pVer) {
	pVer->dwFlags =
		SF_NOTIFY_SECURE_PORT
		| SF_NOTIFY_NONSECURE_PORT
		| SF_NOTIFY_ORDER_LOW
		// | SF_NOTIFY_SEND_RESPONSE
		// | SF_NOTIFY_END_OF_NET_SESSION
		| SF_NOTIFY_LOG
		;
	pVer->dwFilterVersion = HTTP_FILTER_REVISION;
	// strcpy(pVer->dwServerFilterVersion
	return TRUE;
}

DWORD WINAPI __stdcall
HttpFilterProc(HTTP_FILTER_CONTEXT *pfc, DWORD notificationType,
			   VOID *pvNotification)
{
	PHTTP_FILTER_LOG pLogData;
	OutputDebugString("Enter HttpFilterProc\n");

	switch (notificationType) {
		case SF_NOTIFY_LOG:
			{
				OutputDebugString("HttpFilterProc: Logging\n");
				TCHAR sz[256];
				pLogData = (PHTTP_FILTER_LOG)pvNotification;
				sprintf(sz, "Client Machine: %s, Username: %s, Server Machine: %s, Target Path: %s\n",
					pLogData->pszClientHostName,
					pLogData->pszClientUserName,
					pLogData->pszServerName,
					pLogData->pszTarget
					);
				break;
			}
		default:
			OutputDebugString("HttpFilterProc: Default\n");
			break;
	}

	return SF_STATUS_REQ_NEXT_NOTIFICATION;
}
