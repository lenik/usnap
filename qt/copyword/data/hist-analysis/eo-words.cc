#include <stdio.h>

int main(int argc, char **argv) {
    FILE *fin = stdin;

    if (argc >= 2) {
        char *path = argv[1];
        fin = fopen(path, "rt");
        if (fin == NULL) {
            perror("failed to open");
            return 1;
        }
    }

    char buf[100];
    int cc = 0;

    int ch;
    // Escaped: ĈĜĤĴŜŬ ĉĝĥĵŝŭ => ~zC ~zG .. ~zu
    while ((ch = fgetc(fin)) != EOF) {
        if (   (ch >= 'a' && ch <= 'z')
            || (ch >= 'A' && ch <= 'Z')
            || (ch == '-') || (ch == '~')
            ) {
            buf[cc++] = (char) ch;
        } else {
            if (cc != 0) {
                buf[cc] = '\0';
                printf("%s\n", buf);
                cc = 0;
            }
        }
    }
    return 0;
}
