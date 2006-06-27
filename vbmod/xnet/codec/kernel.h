#ifndef __KERNEL_H
#define __KERNEL_H

#include "array.h"

char *encode(char *p, int cb, int *cb_out);
char *decode(char *p, int cb, int *cb_out);

char *decode_segment(char *p, int cb, int *cb_out, int *cb_read);

#define START 0
#define NORMAL 1
#define ESCAPE 2
#define TERM 3
#define TERM_LINE 4

struct Decoder {
    ByteArray buf;
    int state;
    int index;
    int quoted;

public:
    Decoder() {
        state = START;
        index = -1;
        quoted = 0;
    }

    inline bool term() {
        return state == TERM || state == TERM_LINE;
    }

    inline bool termLine() {
        return state == TERM_LINE;
    }

    bool input(BYTE c);

    inline const BYTE *process(const BYTE *str, int size) {
        _assert_(str);
        _assert_(size >= 0);

        while (size--) {
            if (! input(*str))
                break;
            str++;
        }

        return str;
    }
};

#endif
