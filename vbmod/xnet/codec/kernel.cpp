
#include "stdafx.h"

#include <stdlib.h>
#include <list>
#include "kernel.h"

static int msb(unsigned n) {
    int bits = 0;
    while (n) {
        n >>= 1;
        bits++;
    }
    if (bits-- == 0)
        return 0;
    n = 1;
    while (bits--)
        n <<= 1;
    return n;
}

char *encode(char *p, int cb, int *cb_out) {
    ByteArray buf;
    bool escape = false;
    int i;
    unsigned char c;
    char *out;

    for (i = 0; i < cb; i++) {
        c = p[i];
        switch (c) {
        case ' ':
        case '\t':
        case '\n':
        case '\r':
        case ';':
        case '"':
        case '\\':
            escape = true;
            break;
        }
    }
    if (cb == 0)
        escape = true;

    if (! escape) {
        out = (char *)malloc(cb + 1);
        memcpy(out, p, cb);
        out[cb] = '\0';
        if (cb_out)
            *cb_out = cb;
        return out;
    }

    buf.write('\"');

    while (cb-- > 0) {
        unsigned char c = *p++;
        switch (c) {
        case '\t':  c = 't'; break;
        case '\n':  c = 'n'; break;
        case '\r':  c = 'r'; break;
        case '"':   break;
        case '\\':  break;
        default:
            buf.write(c);
            continue;
        }
        buf.write('\\');
        buf.write(c);
    }

    buf.write('\"');
    buf.write('\0');

    if (cb_out)
        *cb_out = buf.getSize() - 1;

    out = (char *)buf.detach();
    return out;
}

char *decode(char *p, int cb, int *cb_out) {
    _assert_(p);
    _assert_(cb >= 0);

    char *out;

    if (cb == 0) {
        if (cb_out)
            *cb_out = 0;
        return strdup("");
    }

    if (*p != '"') {
        out = (char *)malloc(cb + 1);
        memcpy(out, p, cb);
        out[cb] = '\0';
        if (cb_out)
            *cb_out = cb;
        return out;
    }

    _assert_(p[0] == '"');
    _assert_(p[cb - 1] == '"');
    p++;
    cb -= 2;

    ByteArray buf;
    int escaped = 0;

    while (cb--) {
        char c = *p++;
        if (escaped) {
            switch (c) {
            case 't':  c = '\t'; break;
            case 'n':  c = '\n'; break;
            case 'r':  c = '\r'; break;
            }
            escaped = 0;
        } else {
            if (c == '\\') {
                escaped = 1;
                continue;
            }
        }
        buf.write(c);
    }

    buf.write('\0');

    if (cb_out)
        *cb_out = buf.getSize() - 1;
    out = (char *)buf.detach();
    return out;
}

#define START 0
#define NORMAL 1
#define ESCAPE 2
#define TERM 3

class Decoder {
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

    char *detach() {
        char *detached = buf.detached();
        return detached;
    }

    inline bool term() {
        return state == TERM;
    }

    inline bool input(char c) {
        int sp = isspace(c);
        index++;

        switch (state) {
        case START:
            if (sp)
                return true;
            state = NORMAL;
            index = 0;
        case NORMAL:
            if (sp) {
                state = TERM;
                return true;
            }
            if (quoted) {
                if (c == '\\') {
                    state = ESCAPE;
                    // eat (\).
                    return true;
                }
            }
            if (sp || c == ';') {
                // eat (SP | ;)
                state = TERM;
                return true;
            }

            switch (c) {
            case '"':
                if (index == 0) {
                    quoted = 1;
                    // eat ^(")
                    return true;
                }
                break;
            }
            buf.write(c);
            return true;

        case ESCAPE:
            switch (c) {
            case 't':  c = '\t'; break;
            case 'n':  c = '\n'; break;
            case 'r':  c = '\r'; break;
            }
            buf.write(c);
            state = NORMAL;
            return true;
        }

        // TERM, or else unknown.
        return false;
    }

};
