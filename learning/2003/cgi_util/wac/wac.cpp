// wac.cpp : Defines the entry poinhttp://tc-info/cgi-bin/c1c.htmt for the application.
//

#include "stdafx.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.
	if (strcmp(lpCmdLine, "test") == 0) {
		printf("Content-Type: text/html\n\n\n");
		printf("Hello, world! this is a Windows-Application, not console. \n\n");
		return 0;
	} else if (strncmp(lpCmdLine, "read", 4) == 0) {
		FILE *f;
		if ((f = fopen(lpCmdLine + 4, "r")) == NULL) {
			printf("Content-Type: text/html\n\n\n");
			printf("Couldn't open the file %s ", lpCmdLine + 4);
			FILE *t = new FILE;
			memcpy(t, stderr, sizeof(FILE));
			memcpy(stderr, stdout, sizeof(FILE));
			perror("");
			memcpy(stderr, t, sizeof(FILE));
			delete t;
		} else {
			int c;
			while ((c = fgetc(f)) != EOF) {
				fputc(c, stdout);
			}
			fclose(f);
			return -1;
		}
		return 0;
	} else if (strncmp(lpCmdLine, "view", 4) == 0) {
		FILE *f;
		if ((f = fopen(lpCmdLine + 4, "rb")) == NULL) {
			printf("Content-Type: text/html\n\n\n");
			printf("Couldn't open the file %s ", lpCmdLine + 4);
			FILE *t = new FILE;
			memcpy(t, stderr, sizeof(FILE));
			memcpy(stderr, stdout, sizeof(FILE));
			perror("");
			memcpy(stderr, t, sizeof(FILE));
			delete t;
		} else {
			int c;
			while ((c = fgetc(f)) != EOF) {
				fputc(c, stdout);
			}
			fclose(f);
			return -1;
		}
		return 0;
	} else if (strncmp(lpCmdLine, "exec", 4) == 0) {
		int r = WinExec(lpCmdLine + 4, nCmdShow);
		//CreateProcess("WAC", lpCmdLine, NULL, NULL, FALSE, 0, NULL, NULL, NULL, NULL);
		printf("Content-Type: text/html\n\n\n");
		printf("<p>process exit with %d. (%s)</p>", r, lpCmdLine);
		return r;
	} else if (strncmp(lpCmdLine, "call", 4) == 0) {
		BOOL b;
		b = CreateProcess(
			"WAC", lpCmdLine + 4, NULL, NULL,
			TRUE, 0, NULL, NULL, NULL, NULL);
		DWORD dwErr = GetLastError();
		if (!b) {
			printf("Content-Type: text/html\n\n\n");
			printf("<p>can't create process \"%s\"! (error = 0x%08x)</p>\n",
				lpCmdLine + 4,
				dwErr);
		}
		return 0;
	} else if (strncmp(lpCmdLine, "echo", 4) == 0) {
		printf("Content-Type: text/html\n\n\n");
		printf("%s", lpCmdLine + 4);
		return 0;
	} else {
		printf("Content-Type: text/html\n\n\n");
		for (int i = 0; environ[i] != NULL; i++) {
			printf("%s <BR>\n", environ[i]);
		}

		char *clen = getenv("CONTENT_LENGTH");
		if (clen != NULL) {
			printf("\n<p>Content: <HR>\n");
			int cl = (int)atol(clen);
			for (i = 0; i < cl; i++) {
				int c = fgetc(stdin);
				if (c == EOF) break;
				if (c == '\n') {
					cl--;
					printf("<BR>");
				}
				fputc(c, stdout);
			}
		}
	}
	return 0;
}
