// NetEnum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdlib.h>
#include "..\NetEnum.h"

//N@ add VB callback support, then make DLL
DWORD _stdcall WNet_enum(LPNETRESOURCE nr_contain, WNETENUMPROC lpfnEnum) {
	BYTE buf[1024];
	LPNETRESOURCE nr;
	DWORD bufsize = sizeof(buf);
	HANDLE hEnum;
	DWORD count = 1;
	DWORD r;

	r = WNetOpenEnum(
		RESOURCE_GLOBALNET,	// dwScope
		RESOURCETYPE_ANY,	// dwType
		RESOURCEUSAGE_ALL,	// dwUsage
		nr_contain,		// LPNETRESOURCE of the container
		&hEnum);
	if (r != NO_ERROR) return r;

	do {
		count = 1;
		bufsize = 256;
		r = WNetEnumResource(hEnum, &count, buf, &bufsize);
		if (r != NO_ERROR) {
			if (r != WN_NO_MORE_ENTRIES) return r;
			return NO_ERROR;
		}
		nr = (LPNETRESOURCE)buf;
		(*lpfnEnum)(nr);

		if (nr->dwUsage & RESOURCEUSAGE_CONTAINER) {
			WNet_enum(nr, lpfnEnum);
		}
	} while (r == NO_ERROR);

	r = WNetCloseEnum(hEnum);
	if (r != NO_ERROR) return r;

	return NO_ERROR;
}

LPTSTR _stdcall WNet_status(DWORD status) {
	static TCHAR _buf[1024], *buf, *p;
	TCHAR provider[512];
	buf = _buf + 4;
	ltoa(status, buf, 10);
	p = buf + strlen(buf);

	switch (status) {
	case WN_SUCCESS:		strcpy(p, "WN_SUCCESS"); break;
	case WN_NOT_SUPPORTED:		strcpy(p, "WN_NOT_SUPPORTED"); break;
	case WN_CANCEL:			strcpy(p, "WN_CANCEL"); break;
	case WN_RETRY:			strcpy(p, "WN_RETRY"); break;
	case WN_NET_ERROR:		strcpy(p, "WN_NET_ERROR"); break;
	case WN_MORE_DATA:		strcpy(p, "WN_MORE_DATA"); break;
	case WN_BAD_POINTER:		strcpy(p, "WN_BAD_POINTER"); break;
	case WN_BAD_VALUE:		strcpy(p, "WN_BAD_VALUE"); break;
	case WN_BAD_USER:		strcpy(p, "WN_BAD_USER"); break;
	case WN_BAD_PASSWORD:		strcpy(p, "WN_BAD_PASSWORD"); break;
	case WN_ACCESS_DENIED:		strcpy(p, "WN_ACCESS_DENIED"); break;
	case WN_FUNCTION_BUSY:		strcpy(p, "WN_FUNCTION_BUSY"); break;
	//case WN_WINDOWS_ERROR:	strcpy(p, "WN_WINDOWS_ERROR"); break;
	case WN_OUT_OF_MEMORY:		strcpy(p, "WN_OUT_OF_MEMORY"); break;
	case WN_NO_NETWORK:		strcpy(p, "WN_NO_NETWORK"); break;
	case WN_EXTENDED_ERROR:		strcpy(p, "WN_EXTENDED_ERROR"); break;
	case WN_BAD_LEVEL:		strcpy(p, "WN_BAD_LEVEL"); break;
	case WN_BAD_HANDLE:		strcpy(p, "WN_BAD_HANDLE"); break;
	case WN_NOT_INITIALIZING:	strcpy(p, "WN_NOT_INITIALIZING"); break;
	case WN_NO_MORE_DEVICES:	strcpy(p, "WN_NO_MORE_DEVICES"); break;
	case WN_NOT_CONNECTED:		strcpy(p, "WN_NOT_CONNECTED"); break;
	case WN_OPEN_FILES:		strcpy(p, "WN_OPEN_FILES"); break;
	case WN_DEVICE_IN_USE:		strcpy(p, "WN_DEVICE_IN_USE"); break;
	case WN_BAD_NETNAME:		strcpy(p, "WN_BAD_NETNAME"); break;
	case WN_BAD_LOCALNAME:		strcpy(p, "WN_BAD_LOCALNAME"); break;
	case WN_ALREADY_CONNECTED:	strcpy(p, "WN_ALREADY_CONNECTED"); break;
	case WN_DEVICE_ERROR:		strcpy(p, "WN_DEVICE_ERROR"); break;
	case WN_CONNECTION_CLOSED:	strcpy(p, "WN_CONNECTION_CLOSED"); break;
	case WN_NO_NET_OR_BAD_PATH:	strcpy(p, "WN_NO_NET_OR_BAD_PATH"); break;
	case WN_BAD_PROVIDER:		strcpy(p, "WN_BAD_PROVIDER"); break;
	case WN_CANNOT_OPEN_PROFILE:	strcpy(p, "WN_CANNOT_OPEN_PROFILE"); break;
	case WN_BAD_PROFILE:		strcpy(p, "WN_BAD_PROFILE"); break;
	case WN_BAD_DEV_TYPE:		strcpy(p, "WN_BAD_DEV_TYPE"); break;
	case WN_DEVICE_ALREADY_REMEMBERED:
					strcpy(p, "WN_DEVICE_ALREADY_REMEMBERED"); break;
	case WN_CONNECTED_OTHER_PASSWORD:
					strcpy(p, "WN_CONNECTED_OTHER_PASSWORD"); break;

	case WN_NO_MORE_ENTRIES:	strcpy(p, "WN_NO_MORE_ENTRIES"); break;
	case WN_NOT_CONTAINER:		strcpy(p, "WN_NOT_CONTAINER"); break;

	case WN_NOT_AUTHENTICATED:	strcpy(p, "WN_NOT_AUTHENTICATED"); break;
	case WN_NOT_LOGGED_ON:		strcpy(p, "WN_NOT_LOGGED_ON"); break;
	case WN_NOT_VALIDATED:		strcpy(p, "WN_NOT_VALIDATED"); break;
	default: ;
	}

	p = buf + strlen(buf);
	WNetGetLastError(&status, p, sizeof(buf) + p - buf, provider, sizeof(provider));

	((LPLONG)_buf)[0] = strlen(buf);
	return buf;
}
