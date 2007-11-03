#ifndef _tv_umac_n_xWDeY3jH9rp9s2_
#define _tv_umac_n_xWDeY3jH9rp9s2_ "$Id: tv.h,v 1.1 2007-11-03 12:23:06 lenik Exp $"

#include <glib/gtypes.h>
#include "util.h"

#define TYPED_VALUE_GENERIC(g) \
    g(int, int) \
    g(short, short) \
    g(long, gint64) \
    g(float, float) \
    g(double, double) \
    g(char, char) \
    g(string, char *) \
    g(shared_string, char *)    /* though shared-string should not be
                                   freed, but its content is still
                                   writable. */ \
    g(buffer, buffer_t *) \
    g(ptr, void *)

#define TYPED_VALUE_INT             (&typed_value_int_type)
#define TYPED_VALUE_SHORT           (&typed_value_short_type)
#define TYPED_VALUE_LONG            (&typed_value_long_type)
#define TYPED_VALUE_FLOAT           (&typed_value_float_type)
#define TYPED_VALUE_DOUBLE          (&typed_value_double_type)
#define TYPED_VALUE_CHAR            (&typed_value_char_type)
#define TYPED_VALUE_STRING          (&typed_value_string_type)
#define TYPED_VALUE_SHARED_STRING   (&typed_value_shared_string_type)
#define TYPED_VALUE_BUFFER          (&typed_value_buffer_type)
#define TYPED_VALUE_PTR             (&typed_value_ptr_type)

typedef struct _typed_value_t typed_value_t;
typedef struct _typed_value_type_t typed_value_type_t;
typedef union _typed_value_union_t typed_value_union_t;

struct _typed_value_type_t {
    const char *typename;
    void (*ctor)(typed_value_union_t *data, typed_value_union_t *init);
    void (*dtor)(typed_value_union_t *data);
    void (*get)(typed_value_union_t *data, typed_value_union_t *dest, typed_value_type_t *type);
    void (*convert)(typed_value_union_t *data, typed_value_type_t *type);
    int (*get_int)(typed_value_union_t *data);
    short (*get_short)(typed_value_union_t *data);
    gint64 (*get_long)(typed_value_union_t *data);
    float (*get_float)(typed_value_union_t *data);
    double (*get_double)(typed_value_union_t *data);
    char (*get_char)(typed_value_union_t *data);
    char *(*get_string)(typed_value_union_t *data); /* allocated */
    char *(*get_shared_string)(typed_value_union_t *data);
    buffer_t *(*get_buffer)(typed_value_union_t *data); /* allocated */
    void *(*get_ptr)(typed_value_union_t *data);
    int (*convert_int)(typed_value_union_t *data);
    short (*convert_short)(typed_value_union_t *data);
    gint64 (*convert_long)(typed_value_union_t *data);
    float (*convert_float)(typed_value_union_t *data);
    double (*convert_double)(typed_value_union_t *data);
    char (*convert_char)(typed_value_union_t *data);
    char *(*convert_string)(typed_value_union_t *data);
    char *(*convert_shared_string)(typed_value_union_t *data);
    buffer_t *(*convert_buffer)(typed_value_union_t *data);
    void *(*convert_ptr)(typed_value_union_t *data);
};

union _typed_value_union_t {
    char vchar;
    char achar[8];
    gint16 vshort;
    gint16 ashort[4];
    guint16 vushort;
    guint16 aushort[4];
    gint32 vint;
    gint32 aint[2];
    guint32 vuint;
    guint32 auint[2];
    gint64 vlong;
    gint64 along[1];
    guint64 vulong;
    guint64 aulong[1];
    float vfloat;
    float afloat[2];
    double vdouble;
    double adouble[1];
    char *vstring;
    char *astring[2];
    buffer_t *vbuffer;
    buffer_t *abuffer[2];
    void *vptr;
    void *aptr[2];
};

/* should be 16-bytes */
struct _typed_value_t {
    typed_value_type_t *type;
    char *to_string;            /* temporary allocated string */
    typed_value_union_t v;
};

extern typed_value_type_t typed_value_int_type;
extern typed_value_type_t typed_value_short_type;
extern typed_value_type_t typed_value_long_type;
extern typed_value_type_t typed_value_float_type;
extern typed_value_type_t typed_value_double_type;
extern typed_value_type_t typed_value_char_type;
extern typed_value_type_t typed_value_string_type;
extern typed_value_type_t typed_value_shared_string_type;
extern typed_value_type_t typed_value_buffer_type;
extern typed_value_type_t typed_value_ptr_type;

typed_value_t *
typed_value_new();              /* default int type */

void
typed_value_free(typed_value_t *tv);

const char *
typed_value_typename(typed_value_t *tv);

void
typed_value_set(typed_value_t *tv, typed_value_t *src);

void
typed_value_unset(typed_value_t *tv);

#define _typed_value_get_decl(vn, vt) \
    vt typed_value_get_##vn(typed_value_t *tv);
TYPED_VALUE_GENERIC(_typed_value_get_decl);

#define _typed_value_set_decl(vn, vt) \
    void typed_value_set_##vn(typed_value_t *tv, vt value);
TYPED_VALUE_GENERIC(_typed_value_set_decl);

#define _typed_value_convert_decl(vn, vt) \
    vt typed_value_convert_##vn(typed_value_t *tv);
TYPED_VALUE_GENERIC(_typed_value_convert_decl);

#endif
