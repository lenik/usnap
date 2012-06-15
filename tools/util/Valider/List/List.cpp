// List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <gmsg.h>

int _stdcall ffproc(HANDLE h, UINT msg, DWORD p1, DWORD p2) {
	static DWORD userparam;
	static int level = 0;
	LPWIN32_FIND_DATA pfd = (LPWIN32_FIND_DATA)p1;
	switch (msg) {
	case FF_INIT:
		userparam = p2;
		level = 0;
		break;
	case FF_FILE: {
		TCHAR prefix[1024];
		for (int i = 0; i < level; i++) {
			printf("  ");
		}
		printf("%s\n", pfd->cFileName);
		      }
		break;
	case FF_ENTER: {
		LPCTSTR dir = (LPCTSTR)pfd->cFileName;
		if (lstrcmp(dir, _T(".")) == 0 ||
			lstrcmp(dir, _T("..")) == 0) {
			return FF_SKIP;
		}
		level++;
		break;
		       }
	case FF_EXIT:
		level--;
		break;
	case FF_END:
		printf("total %d files, processed: %d\n", p1, p2);
		break;
	}
	return 0;
}

int main(int argc, char* argv[])
{
	findfiles(argv[1], 3, ffproc, 0);
	return 0;
}
