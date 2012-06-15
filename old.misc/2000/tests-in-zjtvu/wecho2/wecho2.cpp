// wecho2.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include "stdio.h"

#define LIST_FILENAME			"X:\\Temp\\L"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	FILE *f;

	if (lpCmdLine[0] == '\0') {
		int r = MessageBox(NULL, "加入空行么?", NULL, MB_YESNO);
		if (r != IDYES) return 0;
	}
	f = fopen(LIST_FILENAME, "a");
	if (f == NULL) {
		MessageBox(NULL, "打开列表文件错误", NULL, MB_OK);
		return -1;
	}

	fprintf(f, "%s\n", lpCmdLine);
	fclose(f);

	return 0;
}
