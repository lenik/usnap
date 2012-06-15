#include "input.hh"

#define CHARSET_WCS "utf16-le"

int input_t::next() {
    if (eaten == INPUT_EOF)
        return INPUT_EOF;

    int c;
    if (eaten == INPUT_NA) {
        c = read();
        _assert_(c != INPUT_NA);
        if (c == INPUT_EOF)             /* EOF-safe */
            eaten = INPUT_EOF;
    } else {
        c = eaten;
        eaten = INPUT_NA;
    }

    if (c == '\n') {
        row++;
        column = 0;
    } else {
        column++;
    }

    return c;
}

int input_t::next(int *buffer, int cc) {
    _assert_(buffer);
    _assert_(cc >= 0);

    int n = 0;
    if (eaten == INPUT_EOF)             /* EOF-safe */
        return 0;
    if (eaten != INPUT_NA && cc >= 1) {
        n++;
        *buffer++ = eaten;
        eaten = INPUT_NA;
    }

    int c;
    while (n < cc) {
        c = next();
        _assert_(c != INPUT_NA);
        if (c == INPUT_EOF) {           /* EOF-safe */
            eaten = INPUT_EOF;
            break;
        }
        n++;
        *buffer++ = c;
    }
    return n;
}

int input_t::peek() {
    if (eaten == INPUT_NA)
        eaten = read();
    return eaten;
}

encoded_input_t::~encoded_input_t() {
    if (wcsbuf != NULL)
        g_free(wcsbuf);
}

int encoded_input_t::bread(char *buffer, int size = INT_MAX) {
    _assert_(buffer);
    _assert_(size >= 0);
    int n = 0;
    int b;
    while (n < size) {
        b = bread();
        if (b == INPUT_EOF)
            break;
        n++;
        *buffer++ = b;
    }
    return n;
}

int encoded_input_t::read() {
    _assert_(iconvbufp <= iconvbuf_size);

    if (wcsbufp != NULL)
        if (*wcsbufp)
            return *wcsbufp++;
        else {
            g_free(wcsbuf);
            wcsbuf = wcsbufp = NULL;
        }

    /* iconvbuf underflow? */
    if (iconvbufp >= iconvbuf_size) {
        int cb = bread(iconvbuf, sizeof(iconvbuf));
        iconvbufp = 0;
        if ((iconvbuf_size = cb) == 0)
            return INPUT_EOF;
    }

    GError *err;
    int tries = 0;
    for (;;) {
        size_t cbread;
        err = NULL;
        wcsbufp = wcsbuf = (wchar_t *)
            g_convert(iconvbuf + iconvbufp, iconvbuf_size - iconvbufp,
                      CHARSET_WCS, encoding, &cbread, NULL /*cbwritten*/,
                      &err);
        iconvbufp += cbread;
        if (err) {
            iconverr = err->code;
            g_error_free(err);
        }
        if (wcsbuf != NULL && *wcsbuf == 0) {
            g_free(wcsbuf);
            wcsbufp = wcsbuf = NULL;
        }
        if (wcsbuf != NULL)
            return *wcsbufp++;

        /* Retrying... */
        if (tries++ == 2) /* Don't try more than twice */
            break;

        /* Buffer may be underflow for iconv */
        /* 1. Move the rest data to the beginning */
        for (int i = iconvbufp; i < iconvbuf_size; i++)
            iconvbuf[i - iconvbufp] = iconvbuf[i];
        iconvbuf_size -= iconvbufp;
        iconvbufp = 0;

        /* 2. Read more data */
        int cbmax = sizeof(iconvbuf) - iconvbuf_size;
        if (cbmax == 0) {
            /* -- No space room left.
             *    (Last iconv didn't converted any chars?)
             *  - some char at the beginning can't be converted
             *  - iconvbuf is not large enough
             */
            return INPUT_EOF;
        }
        int cb = bread(iconvbuf + iconvbuf_size, cbmax);
        if (cb == 0) {
            /* -- No more data, some bytes at the ending will be ignored. */
            return INPUT_EOF;
        }
        iconvbuf_size += cb;
    }

    /* -- Tried too much, some bytes at the ending will be ignored. */
    return INPUT_EOF;
};

/* TODO: optimize */
int encoded_input_t::read(int *buffer, int cc) {
    return input_t::read(buffer, cc);
}

const char *
binary_input_t::location(char *buffer, int size) {
    sprintf_lim(buffer, size, "...",
                "raw binary position: %d/%d", datap, size);
    return buffer;
}

int binary_input_t::bread() {
    if (datap < size)
        return ((unsigned char *)data)[datap++];
    return INPUT_EOF;
}

int binary_input_t::bread(char *buffer, int size) {
    if (datap >= size) return 0;        /* INPUT_EOF */
    int n = size - datap;               /* available bytes */
    if (size > n) n = size;             /* min(avail, size) */
    for (int i = 0; i < n; i++)
        buffer[i] = data[datap++];
    return n;
}

file_input_t::file_input_t(FILE *fp_, const char *encoding)
    : encoded_input_t(encoding), fp(fp_) {
    _assert_(fp_ != NULL);
}

file_input_t::~file_input_t() {
    if (fp != NULL)
        fclose(fp);
}

file_input_t *
file_input_t::create(const char *path, const char *encoding) {
    FILE *fp = fopen(path, "rb");
    if (fp == NULL)
        return NULL;
    return new file_input_t(fp, encoding);
}

const char *
file_input_t::location(char *buffer, int size) {
    int fpos = 0;
    if (fp)
        fpos = ftell(fpos);
    sprintf_lim(buffer, size, "...",
                "file %s offset %d", path, fpos);
    return buffer;
}

int file_input_t::bread() {
    _assert_(fp != NULL);
    return fgetc(fp);
}

int file_input_t::bread(char *buffer, int size = INT_MAX) {
    _assert_(fp != NULL);
    _assert_(size >= 0);
    int cbread = (int)fread(buffer, 1, (size_t)size, fp);
    return cbread;
}

void stack_input_t::push_input(input_t *input) {
    _assert_(input);
    stack = (list_t)g_slist_push((GSList *)stack, input);
}

void stack_input_t::pop_input() {
    g_slist_remove((GSList *)stack);
}

input_t *stack_input_t::top_input() {
    if (stack) {
        return (input_t *)g_slist_get((GSList *)stack, 0);
    }
    return NULL;
}

int stack_input_t::next() {
    input_t *top = top_input();
    if (top == NULL)
        return INPUT_EOF;
    int c = top->next();
    while (c == INPUT_EOF) {
        pop_input();
        top = top_input();
        if (top == NULL)
            return INPUT_EOF;
        c = top->next();
    }
    return c;
}

int stack_input_t::peek() {
    for (GSList *top = (GSList *)stack;
         top != NULL;
         top = g_slist_next(top)) {
        input_t *in = (input_t *)top->data;
        int c = in->peek();
        if (c != INPUT_EOF)
            return c;
    }
    return INPUT_EOF;
}

int stack_input_t::read() {
    input_t *top = top_input();
    if (top == NULL)
        return INPUT_EOF;
    int c = top->read();
    while (c == INPUT_EOF) {
        pop_input();
        top = top_input();
        if (top == NULL)
            return INPUT_EOF;
        c = top->read();
    }
    return c;
}

int stack_input_t::read(char *buffer, int cc = INT_MAX) {
    int n = 0;
    while (cc > 0) {
        input_t *top = top_input();
        if (top == NULL)
            break;
        int m = top->read(buffer, cc);
        if (m == 0) {
            pop_input();
            continue;
        }
        n += m;
        cc -= m;
        buffer += m;
    }
    return n;
}

const char *
stack_input_t::location(char *buffer, int size) {
    _assert_(size > 5);                 /* don't be too small */
    char *bufp = buffer;
    for (GSList *top = (GSList *)stack;
         top != NULL;
         top = g_slist_next(top)) {
        input_t *in = (input_t *)top->data;
        in->location(bufp, size - 5);
        strcat(bufp, "\n");
        int len = strlen(bufp);
        bufp += len;
        size -= len;
        if (size < 5) {
            strcat(bufp, "...");
            break;
        }
    }
    return buffer;
}
