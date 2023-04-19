// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "../kernel.h"
#include "array.h"

void test_encode(char *msg, int size = -1) {
    if (size == -1)
        size = strlen(msg);

    int cbenc;
    char *enc = encode(msg, size, &cbenc);

    int trunc = strlen(enc) != cbenc;

    printf("<%s>", enc);
    if (trunc) printf("...");
    printf("\n");

    free(enc);
}

void test_decode(char *msg, int size = -1) {
    if (size == -1)
        size = strlen(msg);

    int cbdec;
    char *dec = decode(msg, size, &cbdec);

    int trunc = strlen(dec) != cbdec;

    printf("<%s>", dec);
    if (trunc) printf("...");
    printf("\n");

    free(dec);
}

int main(int argc, char* argv[])
{
    printf("--------- encode -----------\n");

    test_encode("hello, world");
    test_encode("simpleword");
    test_encode("你好，中国");
    test_encode("for example ' a str(@#$!&*(\\\t\r\ning with \" inside '. ");
    test_encode("");
    test_encode("segment\0separated", 17);

    printf("--------- decode -----------\n");

    test_decode("\"hello, world\"");
    test_decode("simpleword");
    test_decode("你好，中国");
    test_decode("\"for example ' a str(@#$!&*(\\\\\\t\\r\\ning with \\\" inside '. \"");
    test_decode("\"\"");
    test_decode("segment\0separated", 17);

    return 0;
}
