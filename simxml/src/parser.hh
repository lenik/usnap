#ifndef _parser_umac_n_xWDeYL_5j0Wb1l_
#define _parser_umac_n_xWDeYL_5j0Wb1l_

class parser_t {
public:
    parser_t(input_t *input_)
        : input(input_);

protected:
    void add_error(const char *fmt, ...);
    const char *last_error();
    void clear_errors();

private:
    typedef unknown_t list_t;
    list_t errors;
};

typedef union _tokenval_t {
    int vint;
    long vlong;
    float vfloat;
    double vdouble;

    int vchar;                  /* maybe ascii or unicode */
    char *vstring;              /* unicode chars will be converted to utf-8 */
    void *vptr;

    struct ptr_add_t {          /* additional information for pointer value */
        void *vptr_or_str;      /* stuff */
        int size;               /* elements count rather than bytes */
    } x;
} tokenval_t;

/* helpers */

typedef char *string_t;

#ifdef NO_ICONV
#define g_string_append_char g_string_append_c
#else
#define g_string_append_char g_string_append_unichar
#endif


/* utility parsers */

/* parse_* function should set_last_error and return NULL on error */

#define PARSE_STR_QT_MASK       0x7F    /* quote-type, auto detect if not 0 */
#define PARSE_STR_ML            0x100   /* multi-line without \ is allowed */
#define PARSE_STR_CR_2_LF       0x300   /* multi-line and convert \r to \n */
#define PARSE_STR_CR_KEEP       0x400   /* don't skip \r */
#define PARSE_STR_NO_ESCAPES    0x800   /* c-style escape is enabled */
#define PARSE_STR_MASK          0xF00   /* for quote-enabled parsers */

/* len returns unicode chars (but not utf-8 bytes) of returned string.  the
 * returned string should be freed. */
string_t
parse_string(input_source_t *input, int options, int *len);


#define PARSE_ARG_QUOTED        1       /* allow quoted arguments */
#define PARSE_ARG_SPLIT_EQU     2       /* split key=value into (key value)
                                           pair */

/* eat leading space and keep trailing space.
 * returns NULL if EOF or parse error.  */
string_t
parse_argument(input_source_t *input, int options);


#define PARSE_ARG_TILL_EOL      4       /* the last arguments */

/* Modes (args, opt):
 *    N      multi-line, fixed args (args > 0)
 *    0      single-line, implicit _EOL, auto args
 *    N,_EOL single-line, fixed args
 *
 * eat trailing space when single-line mode.
 * args returns the actually arguments fetched.
 * returns NULL if EOF or parse error.
 */
string_t *
parse_arguments(input_source_t *input, int options, int *args);

void
free_arguments(string_t *args);


/* common number parse options */
#define PARSE_NUM_NO_SKIP       0x0800  /* don't skip leading space */
#define PARSE_NUM_POSITIVE      0x1000  /* only positive numbers */
#define PARSE_NUM_EXPLICIT      0x2000  /* the number and other stuff must be
                                           separated by space or punctuators */
#define PARSE_NUM_COMMA         0x4000  /* currency-style number */
#define PARSE_NUM_UNDERLINE     0x8000  /* perl-style number */
#define PARSE_NUM_MASK          0xF800  /*  */

#define PARSE_INT_RADIX_MASK    0xFF    /* 0 for auto-detect */
#define PARSE_INT_RADIX_PRE     0x100   /* allow prefix radix specifiers,
                                           includes 0x.. and 0.. */
#define PARSE_INT_RADIX_POST    0x200   /* allow postfix radix specifiers,
                                           includes ..B ..O ..D ..H */

/* return |val| if success, or -1 if failed. */
long
parse_integer(input_source_t *input, int options, long *val);


/* parse decimal integer (using float for large numbers, radix-10 only).
 * return |val| if success, or -DBL_MAX if failed.
 * (fail should test by < -1.0) */
double
parse_decimal_int(input_source_t *input, int options, double *val);


#define PARSE_REAL_EXP          1   /* allow ..e+NN format of decimal */

/* return |val| if success, or -DBL_MAX if failed.
 * (should test by < -1.0) */
double
parse_real(input_source_t *input, int options, double *val);


/* TODO: simple token parser */
#define TOKEN_INTEGER           0x8001
#define TOKEN_DECIMAL           0x8002
#define TOKEN_STRING            0x8003

/* return -1 if failed. */
int
parse_token(input_source_t *input, int options, tokenval_t *val);

#endif
