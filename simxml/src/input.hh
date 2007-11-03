#ifndef _input_umac_n_xWDeYnqgycNoNk_
#define _input_umac_n_xWDeYnqgycNoNk_ "$Id: input.hh,v 1.1 2007-11-03 12:23:06 lenik Exp $"

#include <cpf/assert.h>
#include <cpf/basetype.h>
#include <cpf/string.h>                 /* sprintf_lim */

#define INPUT_EOF -1                    /* EOF, 0xffff if 16-bit int */
#define INPUT_NA -2                     /* N/A, 0xfffe if 16-bit int */

class input_t {
public:
    virtual int next();
    virtual int next(int *buffer, int cc = INT_MAX);
    virtual int peek();                 /* LA(1) must be virtual for
                                           stack_input_t */
    virtual const char *location(char *buffer, int size = INT_MAX) = 0;
    virtual ~input_t();

protected:
    input_t()
        : eaten(INPUT_NA), row(0), column(0) {}
    virtual int read() = 0;
    virtual int read(int *buffer, int cc = INT_MAX);

private:
    int eaten;
    int row;
    int column;
};

template<typename CT>
class string_input_t : public input_t {
public:
    typedef CT char_type;
    string_input_t(const CT *string, int length)
        : str(string), strp(0), len(length) {}
    string_input_t(const CT *string)
        : str(string), strp(0), len(0) {
        _assert_(string != NULL);
        CT *pc = string;
        while (*pc++) len++;
    }

    virtual const char *location(char *buffer, int size = INT_MAX) {
        sprintf_lim(buffer, size, " ...",
                    "raw string position: %d/%d", strp, len);
        return buffer;
    }

protected:
    virtual int read() {
        if (strp < len)
            return str[strp++];
        return INPUT_EOF;
    }
    virtual int read(int *buffer, int cc = INT_MAX) {
        if (strp >= len) return 0;      /* INPUT_EOF */
        int n = len - strp;             /* available chars */
        if (cc > n) n = cc;             /* min(avail, cc) */
        for (int i = 0; i < n; i++)
            buffer[i] = str[strp++];
        return n;
    }

protected:
    const CT *str;
    int strp;
    int len;
};

class encoded_input_t : public input_t {
protected:
    encoded_input_t(const char *encoding_ = "utf-8")
        : encoding(encoding_), iconvbuf_size(0), iconvbufp(0),
          wcsbuf(NULL), wcsbufp(NULL), iconverr(0) {}
    virtual ~encoded_input_t();

    virtual int bread() = 0;
    virtual int bread(char *buffer, int size = INT_MAX);

    /* input_t */
    virtual int read();
    virtual int read(int *buffer, int cc = INT_MAX);

protected:
    const char *encoding;

private:
    char iconvbuf[1024];                /* iconv from buffer */
    int iconvbuf_size;
    int iconvbufp;
    wchar_t *wcsbuf;                    /* result unicode string */
    wchar_t *wcsbufp;
    int iconverr;                       /* see GConvertError */
};

class binary_input_t : public encoded_input_t {
public:
    binary_input_t(const char *data_, int size_, const char *encoding = NULL)
        : encoded_input_t(encoding), data(data_), datap(0), size(size_) {}

    virtual const char *location(char *buffer, int size = INT_MAX);

protected:
    virtual int bread();
    virtual int bread(char *buffer, int size = INT_MAX);

private:
    const char *data;
    int datap;
    int size;
};

class file_input_t : public encoded_input_t {
public:
    file_input_t *create(const char *path, const char *encoding = NULL);
    virtual ~file_input_t();

    virtual const char *location(char *buffer, int size = INT_MAX);

protected:
    file_input_t(FIEL *fp, const char *encoding);

    virtual int bread();
    virtual int bread(char *buffer, int size = INT_MAX);

private:
    const char *path;
    FILE *fp;
    int fpos;
};

class stack_input_t : public input_t {
public:
    stack_input_t()
        : stack(NULL) {}
    void push_input(input_t *input);
    void pop_input();
    input_t *top_input();

    virtual const char *location(char *buffer, int size = INT_MAX);

    virtual int next();
    virtual int next(int *buffer, int cc = INT_MAX);
    virtual int peek();
    virtual const char *location(char *buffer, int size = INT_MAX);

protected:
    virtual int read();
    virtual int read(char *buffer, int cc = INT_MAX);

protected:
    typedef unknown_t list_t;
    list_t stack;                       /* pointer to the top of stack */
};

#endif
