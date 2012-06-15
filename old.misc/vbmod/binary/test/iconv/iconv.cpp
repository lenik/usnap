// iconv.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iconv.h>

int do_one(unsigned int namescount, const char *const *names, void *data) {
    for (int i = 0; i < namescount; i++) {
        printf("%-20s", names[i]);
    }
    return 0;
}

int main(int argc, char* argv[])
{
    iconvlist(do_one, NULL);
    printf("\n\n");

	iconv_t cd;
    cd = iconv_open("US-ASCII", "UCS-2LE");

    _asm int 3

    wchar_t *unicode = L"Hello, world!\n";
    char *buffer = (char *)malloc(100);

    size_t inbytes = wcslen(unicode) * 2;
    size_t outbytes = 100;
    wchar_t *pin = unicode;
    char *pout = buffer;

    size_t converted = iconv(cd, (const char **)&pin, &inbytes, &pout, &outbytes);

    iconv_close(cd);

    free(buffer);
	return 0;
}
