// NetEnum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "..\NetEnum.h"

void _stdcall enumproc(LPNETRESOURCE element) {
	printf("%s\n", element->lpRemoteName);
}

int main(int argc, char* argv[])
{
	DWORD r = WNet_enum(NULL, enumproc);	// the NULL container --> root container
	if (r != NO_ERROR) {
		printf("err: %s\n", WNet_status(r));
	}
	return 0;
}
