#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <glib.h>
#include "parser.h"

#define ERROR_BUFFER_SIZE 1024


/* .section. basic extensions */


typedef struct _file_ext_t {
    const char *encoding;       /* NULL to skip */
    const char *path;
    FILE *fp;
    int eaten;                  /* next byte eaten, INPUT_NA if not available.
                                   this is used for decoding. */
    int count;                  /* count of returned characters */
} file_ext_t;


typedef struct _string_ext_t {
    const char *encoding;
    char *string;               /* raw bytes */
    const char *current;
    int eaten;                  /* next byte eaten, INPUT_NA if not available.
                                   this is used for decoding.  */
    int isconst;                /* don't free the string */
    int count;                  /* count of returned characters */
} string_ext_t;


typedef struct _composite_ext_t {
    GSList *stack;              /* pointer to the top of stack */
} composite_ext_t;


static gboolean
composite_remove(composite_ext_t *ext) {
    GSList *top;

    ASSERT(ext);

    if (ext->stack == NULL)
        return FALSE;

    top = ext->stack;
    ext->stack = ext->stack->next;

    ASSERT(top->data);
    input_free((input_source_t *)top->data);

    g_slist_free_1(top);

    return TRUE;
}


static int
file_next_char(void *_ext) {
    file_ext_t *ext = (file_ext_t *)_ext;
    int c;

    ASSERT(ext);
    ASSERT(ext->fp);

    c = fgetc(ext->fp);

    if (c == EOF)
        return INPUT_EOF;

#ifndef NO_ICONV
    /* convert to unicode ... */
    if (ext->count == 0) {
        /* auto-encoding by BOM */
        /* if (c == 0xFEFF) */
    }
#endif

    ext->count++;
    return c;
}


static int
string_next_char(void *_ext) {
    string_ext_t *ext = (string_ext_t *)_ext;
    int c;

    ASSERT(ext);
    ASSERT(ext->current);

    if (*ext->current)
        return *ext->current++;

    return EOF;
}


static int
composite_next_char(void *_ext) {
    composite_ext_t *ext = (composite_ext_t *)_ext;
    GSList *sp;
    input_source_t *top;
    int c = INPUT_NA;

    ASSERT(ext);

    sp = ext->stack;

    while (sp) {
        top = (input_source_t *)ext->stack->data;
        ASSERT(top);

        /* use ::next_char to increase row/column
          ASSERT(top->next_char);
          c = top->next_char(top);
        */
        c = next_char(top);

        ASSERT(c != INPUT_NA);

        if (c >= 0)
            return c;
        if (c == INPUT_EOF) {
            composite_remove(ext); /* remove the top */
            sp = ext->stack;
            continue;
        }

        ASSERT(FALSE);
    }

    /* stack empty */
    return INPUT_EOF;
}


static const char *
file_location(void *_ext, char *buffer, int size) {
    file_ext_t *ext = (file_ext_t *)_ext;
    int cc;

    ASSERT(ext);

    cc = g_snprintf(buffer, size, "file %s", ext->path);
    if (cc > size && size > 5)
        strcpy(buffer + size - 5, " ...");

    return buffer;
}


static const char *
string_location(void *_ext, char *buffer, int size) {
    string_ext_t *ext = (string_ext_t *)_ext;
    int cc;

    ASSERT(ext);

    cc = g_snprintf(buffer, size, "(string)"); /* (raw bytes:) , ext->string); */
    if (cc > size && size > 5)
        strcpy(buffer + size - 5, " ...");

    return buffer;
}


static const char *
composite_location(void *_ext, char *buffer, int size) {
    composite_ext_t *ext = (composite_ext_t *)_ext;
    GSList *it;
    char *pbuf = buffer;
    int cc = 0;

    ASSERT(ext);

    for (it = ext->stack; it != NULL; it = it->next) {
        input_source_t *i = (input_source_t *)it->data;
        i->location(i, pbuf, size - cc);
        cc += strlen(pbuf);
        pbuf += cc;
        ASSERT(cc <= size - 1);
        if (cc >= size - 1)
            break;
    }

    if (cc >= size - 1 && size > 12)
        strcpy(buffer + size - 12, " (... more)");

    return buffer;
}


static void
file_free(void *_ext) {
    file_ext_t *ext = (file_ext_t *)_ext;

    ASSERT(ext);
    ASSERT(ext->fp);

    fclose(ext->fp);
    /* ext->fp = NULL; */
}


static void
string_free(void *_ext) {
    string_ext_t *ext = (string_ext_t *)_ext;

    ASSERT(ext);
    ASSERT(ext->string);

    if (! ext->isconst)
        g_free(ext->string);
    /* ext->string = NULL; */
}


static void
composite_free(void *_ext) {
    while (composite_remove(_ext))
        ;
}


input_source_t *
file_source_new(const char *path, const char *encoding) {
    input_source_t *intf;
    file_ext_t *ext;
    FILE *fp;

    ASSERT(path);

    if ((fp = fopen(path, "rb")) == NULL)
        return NULL;

    intf = g_new(input_source_t, 1);
    ext = g_new(file_ext_t, 1);

    intf->ext = ext;
    intf->next_char = file_next_char;
    intf->location = file_location;
    intf->free = file_free;
    intf->row = 0;
    intf->column = 0;
    intf->eaten = INPUT_NA;
    intf->last_error = NULL;

    ext->encoding = encoding;
	ext->path = path;
    ext->fp = fp;
    ext->eaten = INPUT_NA;
    ext->count = 0;

    return intf;
}


input_source_t *
string_source_new(char *string, int isconst, const char *encoding) {
    input_source_t *intf;
    string_ext_t *ext;

    ASSERT(string);

    intf = g_new(input_source_t, 1);
    ext = g_new(string_ext_t, 1);

    intf->ext = ext;
    intf->next_char = string_next_char;
    intf->location = string_location;
    intf->free = string_free;
    intf->row = 0;
    intf->column = 0;
    intf->eaten = INPUT_NA;
    intf->last_error = NULL;

    ext->encoding = encoding;
    ext->string = string;
    ext->current = string;
    ext->eaten = INPUT_NA;
    ext->isconst = isconst;
    ext->count = 0;

    return intf;
}


input_source_t *
composite_source_new() {
    input_source_t *intf;
    composite_ext_t *ext;

    intf = g_new(input_source_t, 1);
    ext = g_new(composite_ext_t, 1);

    intf->ext = ext;
    intf->next_char = composite_next_char;
    intf->location = composite_location;
    intf->free = composite_free;
    intf->row = 0;
    intf->column = 0;
    intf->eaten = INPUT_NA;
    intf->last_error = NULL;

    ext->stack = NULL;

    return intf;
}


void
composite_source_add(input_source_t *comp, input_source_t *top) {
    composite_ext_t *ext;

    ASSERT(comp);
    ASSERT(top);

    ext = (composite_ext_t *)comp->ext;
    ASSERT(ext);

    ext->stack =
        g_slist_prepend(ext->stack, top);
}


gboolean
composite_source_remove(input_source_t *input) {
    ASSERT(input);
    ASSERT(input->ext);

    return composite_remove(input->ext);
}


/* .section. input source api */


void
input_free(input_source_t *input) {
    ASSERT(input);

    input->free(input->ext);

    if (input->last_error)
        g_free(input->last_error);

    g_free(input);
}


int
peek_char(input_source_t *input) {
    ASSERT(input);
    ASSERT(input->next_char);

    if (input->eaten != INPUT_NA)
        return input->eaten;

    input->eaten = input->next_char(input->ext);
    ASSERT(input->eaten != INPUT_NA);

    return input->eaten;
}


int
next_char(input_source_t *input) {
    int c;

    c = peek_char(input);
    input->eaten = INPUT_NA;    /* signal peek_char to forward */

    if (c == '\n') {
        input->row++;
        input->column = 0;
    } else
        input->column++;

    return c;
}


const char *
get_last_error(input_source_t *input) {
    ASSERT(input);

    if (input->last_error == NULL)
        return NULL;

    return (const char *)input->last_error;
}


void
set_last_error(input_source_t *input, const char *fmt, ...) {
    va_list args;
    string_t buffer;
    int cc;

    ASSERT(input);

    if (fmt == NULL) {
        if (input->last_error)
            g_free(input->last_error);
        input->last_error = NULL;
        return;
    }

    buffer = (string_t)input->last_error;
    if (buffer == NULL) {
        buffer = (string_t)malloc(ERROR_BUFFER_SIZE);
        input->last_error = buffer;
    }

    /* error format: <message> \n <location> */
    /* cc = g_strlcpy(buffer, msg, ERROR_BUFFER_SIZE); */
    va_start(args, fmt);
    cc = g_vsnprintf(buffer, ERROR_BUFFER_SIZE, fmt, args);
    va_end(args);
    if (ERROR_BUFFER_SIZE - cc < 256)
        strcpy(buffer + ERROR_BUFFER_SIZE - 256, "...");
    cc += sprintf(buffer + cc, "\nline %d, offset %d\n",
            input->row + 1, input->column + 1);

    input->location(input->ext, buffer + cc, ERROR_BUFFER_SIZE - cc);
}


/* .section. helpers */


/* .section. utility parsers */


string_t
parse_string(input_source_t *input, int options, int *len) {
    GString *strbuf;
    int qt, c;                  /* quote type, maybe ' or " */
    int f_esc, i, num, esc;     /* used in escape decode */
    int cc = 0;

    strbuf = g_string_new(NULL);

    if (options & PARSE_STR_QT_MASK)
        qt = options & PARSE_STR_QT_MASK;
    else {
        qt = next_char(input);
        ASSERT(qt == '\"' || qt == '\'');
    }

    f_esc = !(options & PARSE_STR_NO_ESCAPES);

    while ((c = next_char(input)) != qt) {
        if (c == '\r')
            if (options & PARSE_STR_CR_2_LF)
                c = '\n';       /* \r\n will become \n\n */
            else if (! (options & PARSE_STR_CR_KEEP))
                continue;       /* ignore */

        if (c == INPUT_EOF
                || (c == '\n' && !(options & PARSE_STR_ML))) {
            set_last_error(input, "non-terminated string");
            g_string_free(strbuf, TRUE);
            return NULL;
        }

        if (c == '\\' && f_esc) {
            c = next_char(input);
            switch (c) {
            case 'n':
                c = '\n';
                break;
            case 'r':
                c = '\r';
                break;
            case '0':
                c = '\0';
                break;
            case 't':
                c = '\t';
                break;
            case 'x':
            case 'X':
            case 'u':
            case 'U':
                esc = (c == 'x' || c == 'X') ? 2 : 4;
                i = 0;          /* hex digits */
                num = 0;        /* hex value */
                do {
                    c = peek_char(input);
                    if (c >= '0' && c <= '9')
                        num = (num << 4) | (c - '0');
                    else if (c >= 'a' && c <= 'f')
                        num = (num << 4) | (c - 'a' + 10);
                    else if (c >= 'A' && c <= 'F')
                        num = (num << 4) | (c - 'A' + 10);
                    else
                        break;
                    next_char(input); /* eat */
                    i++;
                } while (i <= esc); /* max 2 or 4 digits */

                if (i == 0) {
                    set_last_error(input, "invalid hex-escape format (char %d, '%c')", c, c);
                    g_string_free(strbuf, TRUE);
                    return NULL;
                }
                break;
            }
        }
        g_string_append_char(strbuf, c);
        cc++;
    }

    if (len) *len = cc;

    return (string_t)g_string_free(strbuf, FALSE);
}


/* TODO unicode */
string_t
parse_argument(input_source_t *input, int options) {
    int c = INPUT_NA;

    ASSERT(input);

    /* skip leading spaces */
    do {
        c = next_char(input);
    } while (g_unichar_isspace(c));

    if (c == INPUT_EOF) {
        set_last_error(input, "unexpected end of file");
        return NULL;
    }

    /* word boundary */
    if ((c == '\"' || c == '\'') && options & PARSE_ARG_QUOTED) {
        return parse_string(input, c | (options & PARSE_STR_MASK),
                            NULL);
    } else {
        GString *strbuf;
        strbuf = g_string_new(NULL);

        do {
            g_string_append_char(strbuf, c);

            /* don't eat trailing space, but eat '=' if mode _EQU */
            c = peek_char(input);
            if (g_unichar_isspace(c))
                break;
            c = next_char(input);
            if (c == '=' && options & PARSE_ARG_SPLIT_EQU)
                break;
        } while (c != INPUT_EOF);

        return g_string_free(strbuf, FALSE);
    }
}

string_t *
parse_arguments(input_source_t *input, int options, int *args) {
    GPtrArray *arglist;
    string_t arg;
    int n = 0, i;
    int c;

    ASSERT(input);

    if (args) n = *args;
    ASSERT(n != INT_MAX);       /* INT_MAX is internal used only */

    if (n == 0) {               /* All arguments on the same line */
        n = INT_MAX;
        options |= PARSE_ARG_TILL_EOL;
    }

    arglist = g_ptr_array_new();

    for (i = 0; i < n; i++) {
        if (options & PARSE_ARG_TILL_EOL)
            while (1) {
                c = peek_char(input);
                if (! g_unichar_isspace(c))
                    break;
                next_char(input); /* eat the space */
                if (c == '\n')
                    goto break_2;
            }

        arg = parse_argument(input, options);
        if (arg == NULL) {
            g_ptr_array_add(arglist, NULL);
            free_arguments((string_t *)g_ptr_array_free(arglist, FALSE));
            return NULL;
        }

        if (i == n - 1) {       /* last argument */
            if (options & PARSE_ARG_TILL_EOL) {
                GString *remaining = g_string_new(arg);
                g_free(arg);

                /* keep everything until '\n', eat '\n' */
                while ((c = next_char(input)) != '\n')
                    g_string_append_char(remaining, c);

                arg = g_string_free(remaining, FALSE);
            }
        }
        g_ptr_array_add(arglist, arg);
    }

 break_2:
    g_ptr_array_add(arglist, NULL);
    return (string_t *)g_ptr_array_free(arglist, FALSE);
}


void
free_arguments(string_t *args) {
    string_t *p;

    ASSERT(args);

    for (p = args; *p; p++)
        g_free(*p);

    g_free(args);
}


static int _char_int[] = {
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
      0,  1,  2,  3,  4,  5,  6,  7,  8,  9, -1, -1, -1, -1, -1, -1,
     -1, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
     25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, -1, -1, -1, -1, -1,
     -1, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
     25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, -1, -1, -1, -1, -1,
};

static int _int_char[] = {
    '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f',
    'g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v',
    'w','x','y','z',
};


long
parse_integer(input_source_t *input, int options, long *val) {
    long num = 0;
    int radix, radix_spec = 0;
    int neg = 0;
    int c, n;
    char buf[100];
    char *pbuf = buf, *pbuf_max = buf + 100;

    ASSERT(input);
    ASSERT(val);

    radix = options & PARSE_INT_RADIX_MASK;

    ASSERT(radix == 0 || (radix >= 2 && radix <= 16));
    ASSERT(radix != 0 ||
           (options & (PARSE_INT_RADIX_PRE | PARSE_INT_RADIX_POST)));

    if (radix == 0) radix = 10;

    /* skip leading space */
    if (! (options & PARSE_NUM_NO_SKIP))
        while (g_unichar_isspace(peek_char(input)))
            next_char(input);

    /* possible prefixes */
    c = peek_char(input);
    if (c == '-')
        if (options & PARSE_NUM_POSITIVE) {
            set_last_error(input, "only positive number expected");
            return -1;
        } else {
            neg = -1;         /* no space should be occured in -... */
            next_char(input);
            c = peek_char(input);
        }
    if (c < '0' || c > '9') {
        set_last_error(input, "invalid number start (char %d, '%c')", c, c);
        return -1;
    }
    if (c == '0') {
        next_char(input);       /* eat 0 always */
        if (options & PARSE_INT_RADIX_PRE) {
            c = peek_char(input);
            if (c == 'x' || c == 'X') {
                radix = 16;
                radix_spec = 1;
                next_char(input); /* eat 'x' 'X' */
            } else if (c >= '0' && c <= '7') {
                radix = 8;
                /* post specifier 0..H may need this preceding 0.. */
                if (! (options & PARSE_INT_RADIX_POST))
                    radix_spec = 1;
            } else
                *pbuf++ = 0;    /* just digit 0 */
        } else
            *pbuf++ = 0;
    }

    /* integer digits */
    while ((c = peek_char(input)) != INPUT_EOF) {
        if (g_unichar_isspace(c))
            break;
        if (c >= 0x7f)
            break;
        if (c == ',')
            if (! (options & PARSE_NUM_COMMA))
                break;
        if (c == '_')
            if (! (options & PARSE_NUM_UNDERLINE))
                break;
        if (! radix_spec && options & PARSE_INT_RADIX_POST) {
            if (c == 'h' || c == 'H')
                radix = 16;
            else if (c == 'd' || c == 'D')
                radix = 10;
            else if (c == 'o' || c == 'O')
                radix = 8;
            else if (c == 'b' || c == 'B')
                radix = 2;
            else
                break;
            next_char(input);   /* eat h d o b */
            break;
        }
        n = _char_int[c];
        if (n == -1 || n >= radix)
            break;
        *pbuf++ = n;
        if (pbuf == pbuf_max) {
            set_last_error(input, "buffer overflow: too many digits");
            return -1;
        }
        next_char(input);       /* eat a digit */
    }

    /* explicit mode */
    if (options & PARSE_NUM_EXPLICIT) {
        c = peek_char(input);
        if (! (g_unichar_isspace(c) ||
               g_unichar_ispunct(c) ||
               c == INPUT_EOF)) {
            set_last_error(input, "invalid number boundary (char %d, '%c')", c, c);
            return -1;
        }
    }

    /* radix convert */
    pbuf_max = pbuf;
    for (pbuf = buf; pbuf < pbuf_max; pbuf++)
        num = num * radix + (int)*pbuf;

    *val = neg ? -num : num;
    return num;
}


double
parse_decimal_int(input_source_t *input, int options, double *val) {
    double num = 0.0;
    int neg = 0;
    int c;

    ASSERT(input);
    ASSERT(val);

    /* skip leading space */
    if (! (options & PARSE_NUM_NO_SKIP))
        while (g_unichar_isspace(peek_char(input)))
            next_char(input);

    /* possible prefixes */
    c = peek_char(input);
    if (c == '-')
        if (options & PARSE_NUM_POSITIVE) {
            set_last_error(input, "only positive number expected");
            return -DBL_MAX;
        } else {
            neg = -1;         /* no space should be occured in -... */
            next_char(input);
            c = peek_char(input);
        }
    if (c < '0' || c > '9') {
        set_last_error(input, "invalid number start (char %d, '%c')", c, c);
        return -DBL_MAX;
    }

    /* decimal digits */
    while ((c = peek_char(input)) != INPUT_EOF) {
        if (c == '_') {
            if (! (options & PARSE_NUM_UNDERLINE))
                break;
        }
        else if (c == ',') {
            if (! (options & PARSE_NUM_COMMA))
                break;
        }
        else if (c >= '0' && c <= '9')
            num = num * 10.0 + (double)(c - '0'); /* overflow? */
        else
            break;

        next_char(input);
    }

    /* explicit mode */
    if (options & PARSE_NUM_EXPLICIT) {
        c = peek_char(input);
        if (! (g_unichar_isspace(c) ||
               g_unichar_ispunct(c) ||
               c == INPUT_EOF)) {
            set_last_error(input, "invalid number boundary (char %d, '%c')", c, c);
            return -1;
        }
    }

    *val = neg ? -num : num;
    return num;
}


static double _exp_10[] = {
    1e+0,  1e+1,  1e+2,  1e+3,  1e+4,  1e+5,  1e+6,  1e+7,  1e+8,  1e+9,
    1e+10, 1e+11, 1e+12, 1e+13, 1e+14, 1e+15, 1e+16, 1e+17, 1e+18, 1e+19,
    1e+20, 1e+21, 1e+22, 1e+23, 1e+24, 1e+25, 1e+26, 1e+27, 1e+28, 1e+29,
    1e+30, 1e+31, 1e+32, 1e+33, 1e+34, 1e+35, 1e+36, 1e+37, 1e+38, 1e+39,
};


double
parse_real(input_source_t *input, int options, double *val) {
    int int_options;
    double num = 0.0;
    int neg = 0, mantissa_specified = 0;
    int c;

    ASSERT(input);
    ASSERT(val);

    /* skip leading space */
    if (! (options & PARSE_NUM_NO_SKIP))
        while (g_unichar_isspace(peek_char(input)))
            next_char(input);

    /* component: mantissa int. */
    int_options = 10
          | (options & PARSE_NUM_MASK)
          | PARSE_NUM_NO_SKIP;
    c = peek_char(input);
    if (c == '-')
        if (options & PARSE_NUM_POSITIVE) {
            set_last_error(input, "only positive number expected");
            return -DBL_MAX;
        } else {
            neg = -1;         /* no space should be occured in -... */
            next_char(input);   /* eat - */
            c = peek_char(input);
        }
    if (c != '.') {
        if (parse_decimal_int(input, int_options, &num) < -1.0)
            return -DBL_MAX;
        if (num < 0) {
            num = -num;
            neg = -1;
        }
        mantissa_specified = 1;
        c = peek_char(input);
    }

    /* component: mantissa .dec */
    int_options |= PARSE_NUM_POSITIVE;
    if (c == '.') {
        int m_dec_z = 0;
        next_char(input);       /* eat . */
        while ((c = peek_char(input)) == '0') {
            next_char(input);
            m_dec_z++;       /* .00..00 will be ignored by _decimal */
        }
        if (c >= '1' && c <= '9') {
            double m_dec = 0.0;
            if (parse_decimal_int(input, int_options, &m_dec) < -1.0)
                return -DBL_MAX;
            if (m_dec != 0.0)
                m_dec_z += 1 + (int)(floor(log10(m_dec)));
            m_dec /= _exp_10[m_dec_z];
            num += m_dec;
            c = peek_char(input);
        }
        if (m_dec_z) mantissa_specified = 1;
    }

    if (! mantissa_specified) {
        /* may be .e+.. */
        set_last_error(input, "mantissa cannot be '.'");
        return -DBL_MAX;
    }

    /* component: exponent */
    if (c == 'e' || c == 'E') {
        if (options & PARSE_REAL_EXP) {
            double e_int = 0.0;
            int e_neg = 0;
            next_char(input);   /* eat e E */
            c = peek_char(input);
            if (c == '+')
                ;
            else if (c == '-')
                e_neg = -1;
            else {
                set_last_error(input, "invalid exponent format, expected +/-");
                return -DBL_MAX;
            }
            next_char(input);   /* eat + - */
            if (parse_decimal_int(input, int_options, &e_int) < -1.0)
                return -DBL_MAX;
            if (e_int)
                /* not use pow10 for compat. */
                num = num * pow(10.0, e_neg ? -e_int : e_int);
            c = peek_char(input);
        }
    }

    if (options & PARSE_NUM_EXPLICIT)
        if (! (g_unichar_isspace(c) ||
               g_unichar_ispunct(c) ||
               c == INPUT_EOF)) {
            set_last_error(input, "invalid number boundary (char %d, '%c')", c, c);
            return -DBL_MAX;
        }

    *val = neg ? -num : num;
    return num;
}


int
parse_token(input_source_t *input, int options, tokenval_t *val) {
    ASSERT(input);
    ASSERT(val);

    set_last_error(input, "not impl.");

    return -1;
}
