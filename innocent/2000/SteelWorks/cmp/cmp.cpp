// cmp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "..\scomp\scomp.h"

#ifdef x1
int main(int argc, char* argv[])
{
	BYTE a[4096], b[4096];
	size_t cr[1000];
	size_t size_cr = 1000;

	printf("input a: ");
	gets((char *)a);
	printf("input b: ");
	gets((char *)b);

	stream_comp_byte(a, b, strlen((char *)a), strlen((char *)b), 20, 3, cr, &size_cr);

	char rbuf[2048], obuf[2048];
	size_t size_rbuf = 2048, size_obuf = 2048;

	stream_comp_pretty_result(cr, size_cr, rbuf, &size_rbuf, obuf, &size_obuf);

	printf("%s\n%s\n%s\n%s\n", a, rbuf, b, obuf);

	return 0;
}
#endif

int main(int argc, char *argv[]) {
	TCHAR a[4096], b[4096];

	size_t cr[1000];
	size_t size_cr = 1000;

	printf("input a: ");
	gets((char *)a);
	printf("input b: ");
	gets((char *)b);

	stream_comp_mbcs((LPBYTE)a, (LPBYTE)b, _mbslen((const BYTE*)a), _mbslen((const BYTE*)b), 20, 3, cr, &size_cr);

	char rbuf[2048], obuf[2048];
	size_t size_rbuf = 2048, size_obuf = 2048;

	stream_comp_pretty_result(cr, size_cr, rbuf, &size_rbuf, obuf, &size_obuf);

	printf("%s\n%s\n%s\n%s\n", a, rbuf, b, obuf);

	return 0;
}