#include <stdio.h>
#include <string.h>
#include <glib.h>
#include <stdlib.h>
#include "defs.h"
#include "tv.h"

/* .section. commons */

#define TYPE(vn) (&typed_value_##vn##_type)

static typed_value_type_t typed_value_int_type;
static typed_value_type_t typed_value_short_type;
static typed_value_type_t typed_value_long_type;
static typed_value_type_t typed_value_float_type;
static typed_value_type_t typed_value_double_type;
static typed_value_type_t typed_value_char_type;
static typed_value_type_t typed_value_string_type;
static typed_value_type_t typed_value_shared_string_type;
static typed_value_type_t typed_value_buffer_type;
static typed_value_type_t typed_value_ptr_type;

void null_dtor(typed_value_union_t *data) {}

void convert_failure(typed_value_type_t *from_type, typed_value_type_t *to_type, const char *msg) {
    g_error(msg);
}

/* .section. int */

static void int_ctor(typed_value_union_t *data, typed_value_union_t *init) {
    data->vint = init->vint;
}

static int int_get_int(typed_value_union_t *data) {
    return (int)data->vint;
}

static short int_get_short(typed_value_union_t *data) {
    return (short)data->vint;
}

static gint64 int_get_long(typed_value_union_t *data) {
    return (gint64)data->vint;
}

static float int_get_float(typed_value_union_t *data) {
    return (float)data->vint;
}

static double int_get_double(typed_value_union_t *data) {
    return (double)data->vint;
}

static char int_get_char(typed_value_union_t *data) {
    return (char)data->vint;
}

static char *int_get_string(typed_value_union_t *data) {
    char buf[20];
    sprintf(buf, "%d", data->vint);
    return strdup(buf);
}

static char *int_get_shared_string(typed_value_union_t *data) {
    data->aint[1] = 0;                  /* "\0" */
    return data->achar;
}

static buffer_t *int_get_buffer(typed_value_union_t *data) {
    char buf[20];
    int len = sprintf(buf, "%d", data->vint);
    buffer_t *buffer = buffer_sized_new(len);
    memcpy(buffer_ptr(buffer), buf, len);
    return buffer;
}

static void *int_get_ptr(typed_value_union_t *data) {
    /* ASSERT: sizeof(int) == sizeof(void *) */
    return data->vptr;                  /* reinterpret-cast */
}

static int int_convert_int(typed_value_union_t *data) {
    return data->vint;                  /* = */
}

static short int_convert_short(typed_value_union_t *data) {
    return data->vshort;                /* little-endian  */
}

static gint64 int_convert_long(typed_value_union_t *data) {
    data->aint[1] = 0;
    return data->vlong;                 /* little-endian */
}

static float int_convert_float(typed_value_union_t *data) {
    return data->vfloat = (float)data->vint;
}

static double int_convert_double(typed_value_union_t *data) {
    return data->vdouble = (double)data->vint;
}

static char int_convert_char(typed_value_union_t *data) {
    return data->vchar;                 /* little-endian */
}

static char *int_convert_string(typed_value_union_t *data) {
    return data->vstring = int_get_string(data);
}

static char *int_convert_shared_string(typed_value_union_t *data) {
    convert_failure(TYPE(int), TYPE(shared_string), "not supported");
    return NULL;
}

static buffer_t *int_convert_buffer(typed_value_union_t *data) {
    return data->vbuffer = int_get_buffer(data);
}

static void *int_convert_ptr(typed_value_union_t *data) {
    /* ASSERT: sizeof(int) == sizeof(void *) */
    return data->vptr;                  /* reinterpret-cast */
}

static void int_get(typed_value_union_t *data, typed_value_union_t *dest, typed_value_type_t *type) {
    ASSERT(data);
    ASSERT(dest);
    ASSERT(type);
    if (type == TYPE(int))
        dest->vint = int_get_int(data);
    else if (type == TYPE(short))
        dest->vshort = int_get_short(data);
    else if (type == TYPE(long))
        dest->vlong = int_get_long(data);
    else if (type == TYPE(float))
        dest->vfloat = int_get_float(data);
    else if (type == TYPE(double))
        dest->vdouble = int_get_double(data);
    else if (type == TYPE(char))
        dest->vchar = int_get_char(data);
    else if (type == TYPE(string))
        data->vstring = int_get_string(data);
    else if (type == TYPE(shared_string))
        data->vstring = int_get_shared_string(data);
    else if (type == TYPE(buffer))
        data->vbuffer = int_get_buffer(data);
    else if (type == TYPE(ptr))
        data->vptr = int_get_ptr(data);
    else
        convert_failure(TYPE(int), type, "unknown target type");
}

static void int_convert(typed_value_union_t *data, typed_value_type_t *type) {
    ASSERT(data);
    ASSERT(type);
    if (type == TYPE(int))
        int_convert_int(data);
    else if (type == TYPE(short))
        int_convert_short(data);
    else if (type == TYPE(long))
        int_convert_long(data);
    else if (type == TYPE(float))
        int_convert_float(data);
    else if (type == TYPE(double))
        int_convert_double(data);
    else if (type == TYPE(char))
        int_convert_char(data);
    else if (type == TYPE(string))
        int_convert_string(data);
    else if (type == TYPE(shared_string))
        int_convert_shared_string(data);
    else if (type == TYPE(buffer))
        int_convert_buffer(data);
    else if (type == TYPE(ptr))
        int_convert_ptr(data);
    else
        convert_failure(TYPE(int), type, "unknown target type");
}

static typed_value_type_t typed_value_int_type = {
    "int",
    int_ctor,
    null_dtor,                          /* don't need */
    int_get,
    int_convert,
    int_get_int,                        /* = */
    int_get_short,                      /* narrow-cast */
    int_get_long,                       /* cast */
    int_get_float,                      /* cast */
    int_get_double,                     /* cast */
    int_get_char,                       /* narrow-cast */
    int_get_string,                     /* sprintf, allocated */
    int_get_shared_string,              /* 4CC-string */
    int_get_buffer,                     /* memcpy, allocated */
    int_get_ptr,                        /* reinterpret-cast */
    int_convert_int,                    /* = */
    int_convert_short,                  /* narrow-cast */
    int_convert_long,                   /* cast */
    int_convert_float,                  /* cast */
    int_convert_double,                 /* cast */
    int_convert_char,                   /* narrow-cast */
    int_convert_string,                 /* sprintf, allocated */
    int_convert_shared_string,          /* ERROR, not support (3CC at max) */
    int_convert_buffer,                 /* memcpy, allocated */
    int_convert_ptr                     /* reinterpret-cast */
};

/* .section. short */

static void short_ctor(typed_value_union_t *data, typed_value_union_t *init) {
    data->vshort = init->vshort;
}

static int short_get_int(typed_value_union_t *data) {
    return (int)data->vshort;
}

static short short_get_short(typed_value_union_t *data) {
    return (short)data->vshort;
}

static gint64 short_get_long(typed_value_union_t *data) {
    return (gint64)data->vshort;
}

static float short_get_float(typed_value_union_t *data) {
    return (float)data->vshort;
}

static double short_get_double(typed_value_union_t *data) {
    return (double)data->vshort;
}

static char short_get_char(typed_value_union_t *data) {
    return (char)data->vshort;
}

static char *short_get_string(typed_value_union_t *data) {
    char buf[20];
    sprintf(buf, "%d", data->vshort);
    return strdup(buf);
}

static char *short_get_shared_string(typed_value_union_t *data) {
    data->ashort[1] = 0;                /* "\0" */
    return data->achar;
}

static buffer_t *short_get_buffer(typed_value_union_t *data) {
    char buf[20];
    int len = sprintf(buf, "%d", data->vshort);
    buffer_t *buffer = buffer_sized_new(len);
    memcpy(buffer_ptr(buffer), buf, len);
    return buffer;
}

static void *short_get_ptr(typed_value_union_t *data) {
    convert_failure(TYPE(short), TYPE(ptr), "address value truncated");
    return NULL;
}

static int short_convert_int(typed_value_union_t *data) {
    data->ashort[1] = 0;                /* little-endian */
    return data->vint;
}

static short short_convert_short(typed_value_union_t *data) {
    return data->vshort;                /* = */
}

static gint64 short_convert_long(typed_value_union_t *data) {
    data->ashort[1] = 0;                /* little-endian */
    data->aint[1] = 0;                  /* little-endian */
    return data->vlong;
}

static float short_convert_float(typed_value_union_t *data) {
    return data->vfloat = (float)data->vshort;
}

static double short_convert_double(typed_value_union_t *data) {
    return data->vdouble = (double)data->vshort;
}

static char short_convert_char(typed_value_union_t *data) {
    return data->vchar;                 /* little-endian */
}

static char *short_convert_string(typed_value_union_t *data) {
    return data->vstring = short_get_string(data);
}

static char *short_convert_shared_string(typed_value_union_t *data) {
    data->ashort[2] = data->ashort[0];  /* copy 2CC */
    data->ashort[3] = 0;                /* "\0" */
    return data->vstring = data->achar + 4;
}

static buffer_t *short_convert_buffer(typed_value_union_t *data) {
    return data->vbuffer = short_get_buffer(data);
}

static void *short_convert_ptr(typed_value_union_t *data) {
    convert_failure(TYPE(short), TYPE(ptr), "address value truncated");
    return NULL;
}

static void short_get(typed_value_union_t *data, typed_value_union_t *dest, typed_value_type_t *type) {
    ASSERT(data);
    ASSERT(dest);
    ASSERT(type);
    if (type == TYPE(int))
        dest->vint = short_get_int(data);
    else if (type == TYPE(short))
        dest->vshort = short_get_short(data);
    else if (type == TYPE(long))
        dest->vlong = short_get_long(data);
    else if (type == TYPE(float))
        dest->vfloat = short_get_float(data);
    else if (type == TYPE(double))
        dest->vdouble = short_get_double(data);
    else if (type == TYPE(char))
        dest->vchar = short_get_char(data);
    else if (type == TYPE(string))
        data->vstring = short_get_string(data);
    else if (type == TYPE(shared_string))
        data->vstring = short_get_shared_string(data);
    else if (type == TYPE(buffer))
        data->vbuffer = short_get_buffer(data);
    else if (type == TYPE(ptr))
        data->vptr = short_get_ptr(data);
    else
        convert_failure(TYPE(short), type, "unknown target type");
}

static void short_convert(typed_value_union_t *data, typed_value_type_t *type) {
    ASSERT(data);
    ASSERT(type);
    if (type == TYPE(int))
        short_convert_int(data);
    else if (type == TYPE(short))
        short_convert_short(data);
    else if (type == TYPE(long))
        short_convert_long(data);
    else if (type == TYPE(float))
        short_convert_float(data);
    else if (type == TYPE(double))
        short_convert_double(data);
    else if (type == TYPE(char))
        short_convert_char(data);
    else if (type == TYPE(string))
        short_convert_string(data);
    else if (type == TYPE(shared_string))
        short_convert_shared_string(data);
    else if (type == TYPE(buffer))
        short_convert_buffer(data);
    else if (type == TYPE(ptr))
        short_convert_ptr(data);
    else
        convert_failure(TYPE(short), type, "unknown target type");
}

static typed_value_type_t typed_value_short_type = {
    "short",
    short_ctor,
    null_dtor,                          /* don't need */
    short_get,
    short_convert,
    short_get_int,                      /* cast */
    short_get_short,                    /* = */
    short_get_long,                     /* cast */
    short_get_float,                    /* cast */
    short_get_double,                   /* cast */
    short_get_char,                     /* narrow-cast */
    short_get_string,                   /* sprintf, allocated */
    short_get_shared_string,            /* 2CC-string */
    short_get_buffer,                   /* memcpy, allocated */
    short_get_ptr,                      /* ERROR, address value truncated */
    short_convert_int,                  /* cast */
    short_convert_short,                /* = */
    short_convert_long,                 /* cast */
    short_convert_float,                /* cast */
    short_convert_double,               /* cast */
    short_convert_char,                 /* narrow-cast */
    short_convert_string,               /* sprintf, allocated */
    short_convert_shared_string,        /* 2CC-string */
    short_convert_buffer,               /* memcpy, allocated */
    short_convert_ptr,                  /* ERROR, address value truncated */
};

/* .section. long */

static void long_ctor(typed_value_union_t *data, typed_value_union_t *init) {
    data->vlong = init->vlong;
}

static int long_get_int(typed_value_union_t *data) {
    return data->vint;                  /* little-endian */
}

static short long_get_short(typed_value_union_t *data) {
    return data->vshort;                /* little-endian */
}

static gint64 long_get_long(typed_value_union_t *data) {
    return data->vlong;
}

static float long_get_float(typed_value_union_t *data) {
    return (float)data->vlong;
}

static double long_get_double(typed_value_union_t *data) {
    return (double)data->vlong;
}

static char long_get_char(typed_value_union_t *data) {
    return data->vchar;                 /* little-endian */
}

static char *long_get_string(typed_value_union_t *data) {
    char buf[40];
    sprintf(buf, "%I64d", data->vlong);
    return strdup(buf);
}

static char *long_get_shared_string(typed_value_union_t *data) {
    data->achar[7] = '\0';              /* "\0" */
    return data->achar;
}

static buffer_t *long_get_buffer(typed_value_union_t *data) {
    char buf[40];
    int len = sprintf(buf, "%I64d", data->vlong);
    buffer_t *buffer = buffer_sized_new(len);
    memcpy(buffer_ptr(buffer), buf, len);
    return buffer;
}

static void *long_get_ptr(typed_value_union_t *data) {
    return (void *)data->vlong;         /* reinterpret-cast */
}

static int long_convert_int(typed_value_union_t *data) {
    return data->vint;                  /* little-endian */
}

static short long_convert_short(typed_value_union_t *data) {
    return data->vshort;                /* little-endian */
}

static gint64 long_convert_long(typed_value_union_t *data) {
    return data->vlong;                 /* = */
}

static float long_convert_float(typed_value_union_t *data) {
    return data->vfloat = (float)data->vlong;
}

static double long_convert_double(typed_value_union_t *data) {
    return data->vdouble = (double)data->vlong;
}

static char long_convert_char(typed_value_union_t *data) {
    return data->vchar;                 /* little-endian */
}

static char *long_convert_string(typed_value_union_t *data) {
    return data->vstring = long_get_string(data);
}

static char *long_convert_shared_string(typed_value_union_t *data) {
    convert_failure(TYPE(long), TYPE(shared_string), "not supported");
    return NULL;
}

static buffer_t *long_convert_buffer(typed_value_union_t *data) {
    return data->vbuffer = long_get_buffer(data);
}

static void *long_convert_ptr(typed_value_union_t *data) {
    return data->vptr = (void *)data->vlong; /* reinterpret-cast */
}

static void long_get(typed_value_union_t *data, typed_value_union_t *dest, typed_value_type_t *type) {
    ASSERT(data);
    ASSERT(dest);
    ASSERT(type);
    if (type == TYPE(int))
        dest->vint = long_get_int(data);
    else if (type == TYPE(short))
        dest->vshort = long_get_short(data);
    else if (type == TYPE(long))
        dest->vlong = long_get_long(data);
    else if (type == TYPE(float))
        dest->vfloat = long_get_float(data);
    else if (type == TYPE(double))
        dest->vdouble = long_get_double(data);
    else if (type == TYPE(char))
        dest->vchar = long_get_char(data);
    else if (type == TYPE(string))
        data->vstring = long_get_string(data);
    else if (type == TYPE(shared_string))
        data->vstring = long_get_shared_string(data);
    else if (type == TYPE(buffer))
        data->vbuffer = long_get_buffer(data);
    else if (type == TYPE(ptr))
        data->vptr = long_get_ptr(data);
    else
        convert_failure(TYPE(long), type, "unknown target type");
}

static void long_convert(typed_value_union_t *data, typed_value_type_t *type) {
    ASSERT(data);
    ASSERT(type);
    if (type == TYPE(int))
        long_convert_int(data);
    else if (type == TYPE(short))
        long_convert_short(data);
    else if (type == TYPE(long))
        long_convert_long(data);
    else if (type == TYPE(float))
        long_convert_float(data);
    else if (type == TYPE(double))
        long_convert_double(data);
    else if (type == TYPE(char))
        long_convert_char(data);
    else if (type == TYPE(string))
        long_convert_string(data);
    else if (type == TYPE(shared_string))
        long_convert_shared_string(data);
    else if (type == TYPE(buffer))
        long_convert_buffer(data);
    else if (type == TYPE(ptr))
        long_convert_ptr(data);
    else
        convert_failure(TYPE(long), type, "unknown target type");
}

static typed_value_type_t typed_value_long_type = {
    "long",
    long_ctor,
    null_dtor,                          /* don't need */
    long_get,
    long_convert,
    long_get_int,                       /* narrow-cast */
    long_get_short,                     /* narrow-cast */
    long_get_long,                      /* = */
    long_get_float,                     /* narrow-cast */
    long_get_double,                    /* cast */
    long_get_char,                      /* narrow-cast */
    long_get_string,                    /* sprintf, allocated */
    long_get_shared_string,             /* 7CC-string */
    long_get_buffer,                    /* memcpy, allocated */
    long_get_ptr,                       /* reinterpret-cast */
    long_convert_int,                   /* narrow-cast */
    long_convert_short,                 /* narrow-cast */
    long_convert_long,                  /* = */
    long_convert_float,                 /* narrow-cast */
    long_convert_double,                /* cast */
    long_convert_char,                  /* narrow-cast */
    long_convert_string,                /* sprintf, allocated */
    long_convert_shared_string,         /* ERROR, not support */
    long_convert_buffer,                /* memcpy, allocated */
    long_convert_ptr,                   /* reinterpret-cast */
};

/* .section. float */

static void float_ctor(typed_value_union_t *data, typed_value_union_t *init) {
    data->vfloat = init->vfloat;
}

static int float_get_int(typed_value_union_t *data) {
    return (int)data->vfloat;
}

static short float_get_short(typed_value_union_t *data) {
    return (short)data->vfloat;
}

static gint64 float_get_long(typed_value_union_t *data) {
    return (gint64)data->vfloat;
}

static float float_get_float(typed_value_union_t *data) {
    return (float)data->vfloat;
}

static double float_get_double(typed_value_union_t *data) {
    return (double)data->vfloat;
}

static char float_get_char(typed_value_union_t *data) {
    return (char)(int)data->vfloat;
}

static char *float_get_string(typed_value_union_t *data) {
    char buf[30];
    sprintf(buf, "%f", data->vfloat);
    return strdup(buf);
}

static char *float_get_shared_string(typed_value_union_t *data) {
    convert_failure(TYPE(float), TYPE(shared_string), "not supported");
    return NULL;
}

static buffer_t *float_get_buffer(typed_value_union_t *data) {
    char buf[30];
    int len = sprintf(buf, "%f", data->vfloat);
    buffer_t *buffer = buffer_sized_new(len);
    memcpy(buffer_ptr(buffer), buf, len);
    return buffer;
}

static void *float_get_ptr(typed_value_union_t *data) {
    convert_failure(TYPE(float), TYPE(ptr), "meaningless");
    return NULL;
}

static int float_convert_int(typed_value_union_t *data) {
    return data->vint = (int)data->vfloat;
}

static short float_convert_short(typed_value_union_t *data) {
    return data->vshort = (short)data->vfloat;
}

static gint64 float_convert_long(typed_value_union_t *data) {
    return data->vlong = (gint64)data->vfloat;
}

static float float_convert_float(typed_value_union_t *data) {
    return data->vfloat;                /* = */
}

static double float_convert_double(typed_value_union_t *data) {
    return data->vdouble = (double)data->vfloat;
}

static char float_convert_char(typed_value_union_t *data) {
    return (char)(int)data->vfloat;
}

static char *float_convert_string(typed_value_union_t *data) {
    return data->vstring = float_get_string(data);
}

static char *float_convert_shared_string(typed_value_union_t *data) {
    convert_failure(TYPE(float), TYPE(shared_string), "not supported");
    return NULL;
}

static buffer_t *float_convert_buffer(typed_value_union_t *data) {
    return data->vbuffer = float_get_buffer(data);
}

static void *float_convert_ptr(typed_value_union_t *data) {
    convert_failure(TYPE(float), TYPE(ptr), "meaningless");
    return NULL;
}

static void float_get(typed_value_union_t *data, typed_value_union_t *dest, typed_value_type_t *type) {
    ASSERT(data);
    ASSERT(dest);
    ASSERT(type);
    if (type == TYPE(int))
        dest->vint = float_get_int(data);
    else if (type == TYPE(short))
        dest->vshort = float_get_short(data);
    else if (type == TYPE(long))
        dest->vlong = float_get_long(data);
    else if (type == TYPE(float))
        dest->vfloat = float_get_float(data);
    else if (type == TYPE(double))
        dest->vdouble = float_get_double(data);
    else if (type == TYPE(char))
        dest->vchar = float_get_char(data);
    else if (type == TYPE(string))
        data->vstring = float_get_string(data);
    else if (type == TYPE(shared_string))
        data->vstring = float_get_shared_string(data);
    else if (type == TYPE(buffer))
        data->vbuffer = float_get_buffer(data);
    else if (type == TYPE(ptr))
        data->vptr = float_get_ptr(data);
    else
        convert_failure(TYPE(float), type, "unknown target type");
}

static void float_convert(typed_value_union_t *data, typed_value_type_t *type) {
    ASSERT(data);
    ASSERT(type);
    if (type == TYPE(int))
        float_convert_int(data);
    else if (type == TYPE(short))
        float_convert_short(data);
    else if (type == TYPE(long))
        float_convert_long(data);
    else if (type == TYPE(float))
        float_convert_float(data);
    else if (type == TYPE(double))
        float_convert_double(data);
    else if (type == TYPE(char))
        float_convert_char(data);
    else if (type == TYPE(string))
        float_convert_string(data);
    else if (type == TYPE(shared_string))
        float_convert_shared_string(data);
    else if (type == TYPE(buffer))
        float_convert_buffer(data);
    else if (type == TYPE(ptr))
        float_convert_ptr(data);
    else
        convert_failure(TYPE(float), type, "unknown target type");
}

static typed_value_type_t typed_value_float_type = {
    "float",
    float_ctor,
    null_dtor,                          /* don't need */
    float_get,
    float_convert,
    float_get_int,                      /* narrow-cast */
    float_get_short,                    /* narrow-cast */
    float_get_long,                     /* narrow-cast */
    float_get_float,                    /* = */
    float_get_double,                   /* cast */
    float_get_char,                     /* narrow-cast (thru int) */
    float_get_string,                   /* sprintf, allocated */
    float_get_shared_string,            /* ERROR, not support */
    float_get_buffer,                   /* memcpy, allocated */
    float_get_ptr,                      /* ERROR, meaningless */
    float_convert_int,                  /* narrow-cast */
    float_convert_short,                /* narrow-cast */
    float_convert_long,                 /* narrow;-cast */
    float_convert_float,                /* = */
    float_convert_double,               /* cast */
    float_convert_char,                 /* narrow-cast (thru int) */
    float_convert_string,               /* sprintf, allocated */
    float_convert_shared_string,        /* ERROR, not support */
    float_convert_buffer,               /* memcpy, allocated */
    float_convert_ptr,                  /* ERROR, meaningless */
};

/* .section. double */

static void double_ctor(typed_value_union_t *data, typed_value_union_t *init) {
    data->vdouble = init->vdouble;
}

static int double_get_int(typed_value_union_t *data) {
    return (int)data->vdouble;
}

static short double_get_short(typed_value_union_t *data) {
    return (short)data->vdouble;
}

static gint64 double_get_long(typed_value_union_t *data) {
    return (gint64)data->vdouble;
}

static float double_get_float(typed_value_union_t *data) {
    return (float)data->vdouble;
}

static double double_get_double(typed_value_union_t *data) {
    return data->vdouble;               /* = */
}

static char double_get_char(typed_value_union_t *data) {
    return (char)(int)data->vdouble;
}

static char *double_get_string(typed_value_union_t *data) {
    char buf[30];
    sprintf(buf, "%lf", data->vdouble);
    return strdup(buf);
}

static char *double_get_shared_string(typed_value_union_t *data) {
    convert_failure(TYPE(double), TYPE(shared_string), "not supported");
    return NULL;
}

static buffer_t *double_get_buffer(typed_value_union_t *data) {
    char buf[30];
    int len = sprintf(buf, "%lf", data->vdouble);
    buffer_t *buffer = buffer_sized_new(len);
    memcpy(buffer_ptr(buffer), buf, len);
    return buffer;
}

static void *double_get_ptr(typed_value_union_t *data) {
    convert_failure(TYPE(double), TYPE(ptr), "meaningless");
    return NULL;
}

static int double_convert_int(typed_value_union_t *data) {
    return data->vint = (int)data->vdouble;
}

static short double_convert_short(typed_value_union_t *data) {
    return data->vshort = (short)data->vdouble;
}

static gint64 double_convert_long(typed_value_union_t *data) {
    return data->vlong = (gint64)data->vdouble;
}

static float double_convert_float(typed_value_union_t *data) {
    return data->vfloat = (float)data->vdouble;
}

static double double_convert_double(typed_value_union_t *data) {
    return data->vdouble;               /* = */
}

static char double_convert_char(typed_value_union_t *data) {
    return (char)(int)data->vdouble;
}

static char *double_convert_string(typed_value_union_t *data) {
    return data->vstring = double_get_string(data);
}

static char *double_convert_shared_string(typed_value_union_t *data) {
    convert_failure(TYPE(double), TYPE(shared_string), "not supported");
    return NULL;
}

static buffer_t *double_convert_buffer(typed_value_union_t *data) {
    return data->vbuffer = double_get_buffer(data);
}

static void *double_convert_ptr(typed_value_union_t *data) {
    convert_failure(TYPE(double), TYPE(ptr), "meaningless");
    return NULL;
}

static void double_get(typed_value_union_t *data, typed_value_union_t *dest, typed_value_type_t *type) {
    ASSERT(data);
    ASSERT(dest);
    ASSERT(type);
    if (type == TYPE(int))
        dest->vint = double_get_int(data);
    else if (type == TYPE(short))
        dest->vshort = double_get_short(data);
    else if (type == TYPE(long))
        dest->vlong = double_get_long(data);
    else if (type == TYPE(float))
        dest->vfloat = double_get_float(data);
    else if (type == TYPE(double))
        dest->vdouble = double_get_double(data);
    else if (type == TYPE(char))
        dest->vchar = double_get_char(data);
    else if (type == TYPE(string))
        data->vstring = double_get_string(data);
    else if (type == TYPE(shared_string))
        data->vstring = double_get_shared_string(data);
    else if (type == TYPE(buffer))
        data->vbuffer = double_get_buffer(data);
    else if (type == TYPE(ptr))
        data->vptr = double_get_ptr(data);
    else
        convert_failure(TYPE(double), type, "unknown target type");
}

static void double_convert(typed_value_union_t *data, typed_value_type_t *type) {
    ASSERT(data);
    ASSERT(type);
    if (type == TYPE(int))
        double_convert_int(data);
    else if (type == TYPE(short))
        double_convert_short(data);
    else if (type == TYPE(long))
        double_convert_long(data);
    else if (type == TYPE(float))
        double_convert_float(data);
    else if (type == TYPE(double))
        double_convert_double(data);
    else if (type == TYPE(char))
        double_convert_char(data);
    else if (type == TYPE(string))
        double_convert_string(data);
    else if (type == TYPE(shared_string))
        double_convert_shared_string(data);
    else if (type == TYPE(buffer))
        double_convert_buffer(data);
    else if (type == TYPE(ptr))
        double_convert_ptr(data);
    else
        convert_failure(TYPE(double), type, "unknown target type");
}

static typed_value_type_t typed_value_double_type = {
    "double",
    double_ctor,
    null_dtor,                          /* don't need */
    double_get,
    double_convert,
    double_get_int,                     /* narrow-cast */
    double_get_short,                   /* narrow-cast */
    double_get_long,                    /* narrow-cast */
    double_get_float,                   /* narrow-cast */
    double_get_double,                  /* = */
    double_get_char,                    /* narrow-cast (thru int) */
    double_get_string,                  /* sprintf, allocated */
    double_get_shared_string,           /* ERROR, not support */
    double_get_buffer,                  /* memcpy, allocated */
    double_get_ptr,                     /* ERROR, meaningless */
    double_convert_int,                 /* narrow-cast */
    double_convert_short,               /* narrow-cast */
    double_convert_long,                /* narrow-cast */
    double_convert_float,               /* narrow-cast */
    double_convert_double,              /* = */
    double_convert_char,                /* narrow-cast (thru int) */
    double_convert_string,              /* sprintf, allocated */
    double_convert_shared_string,       /* ERROR, not support */
    double_convert_buffer,              /* memcpy, allocated */
    double_convert_ptr,                 /* ERROR, meaningless */
};

/* .section. char */

static void char_ctor(typed_value_union_t *data, typed_value_union_t *init) {
    data->vchar = init->vchar;
}

static int char_get_int(typed_value_union_t *data) {
    return (int)data->vchar;
}

static short char_get_short(typed_value_union_t *data) {
    return (short)data->vchar;
}

static gint64 char_get_long(typed_value_union_t *data) {
    return (gint64)data->vchar;
}

static float char_get_float(typed_value_union_t *data) {
    return (float)data->vchar;
}

static double char_get_double(typed_value_union_t *data) {
    return (double)data->vchar;
}

static char char_get_char(typed_value_union_t *data) {
    return data->vchar;                 /* = */
}

static char *char_get_string(typed_value_union_t *data) {
    int string;
    string = (int)(unsigned char)data->vchar;
    return strdup((const char *)&string);
}

static char *char_get_shared_string(typed_value_union_t *data) {
    data->achar[1] = '\0';              /* 1CC-string */
    return data->achar;
}

static buffer_t *char_get_buffer(typed_value_union_t *data) {
    buffer_t *buffer = buffer_sized_new(1);
    *(char *)buffer_ptr(buffer) = data->vchar;
    return buffer;
}

static void *char_get_ptr(typed_value_union_t *data) {
    convert_failure(TYPE(char), TYPE(ptr), "meaningless");
    return NULL;
}

static int char_convert_int(typed_value_union_t *data) {
    return data->vint = (int)data->vchar;
}

static short char_convert_short(typed_value_union_t *data) {
    return data->vshort = (int)data->vchar;
}

static gint64 char_convert_long(typed_value_union_t *data) {
    return data->vlong = (gint64)data->vchar;
}

static float char_convert_float(typed_value_union_t *data) {
    return data->vfloat = (float)data->vchar;
}

static double char_convert_double(typed_value_union_t *data) {
    return data->vdouble = (double)data->vchar;
}

static char char_convert_char(typed_value_union_t *data) {
    return data->vchar;                 /* = */
}

static char *char_convert_string(typed_value_union_t *data) {
    return data->vstring = char_get_string(data);
}

static char *char_convert_shared_string(typed_value_union_t *data) {
    data->achar[4] = data->achar[0];    /* 1CC-string */
    data->achar[5] = '\0';
    return data->vstring = data->achar + 4;
}

static buffer_t *char_convert_buffer(typed_value_union_t *data) {
    return data->vbuffer = char_get_buffer(data);
}

static void *char_convert_ptr(typed_value_union_t *data) {
    convert_failure(TYPE(char), TYPE(ptr), "meaningless");
    return NULL;
}

static void char_get(typed_value_union_t *data, typed_value_union_t *dest, typed_value_type_t *type) {
    ASSERT(data);
    ASSERT(dest);
    ASSERT(type);
    if (type == TYPE(int))
        dest->vint = char_get_int(data);
    else if (type == TYPE(short))
        dest->vshort = char_get_short(data);
    else if (type == TYPE(long))
        dest->vlong = char_get_long(data);
    else if (type == TYPE(float))
        dest->vfloat = char_get_float(data);
    else if (type == TYPE(double))
        dest->vdouble = char_get_double(data);
    else if (type == TYPE(char))
        dest->vchar = char_get_char(data);
    else if (type == TYPE(string))
        data->vstring = char_get_string(data);
    else if (type == TYPE(shared_string))
        data->vstring = char_get_shared_string(data);
    else if (type == TYPE(buffer))
        data->vbuffer = char_get_buffer(data);
    else if (type == TYPE(ptr))
        data->vptr = char_get_ptr(data);
    else
        convert_failure(TYPE(char), type, "unknown target type");
}

static void char_convert(typed_value_union_t *data, typed_value_type_t *type) {
    ASSERT(data);
    ASSERT(type);
    if (type == TYPE(int))
        char_convert_int(data);
    else if (type == TYPE(short))
        char_convert_short(data);
    else if (type == TYPE(long))
        char_convert_long(data);
    else if (type == TYPE(float))
        char_convert_float(data);
    else if (type == TYPE(double))
        char_convert_double(data);
    else if (type == TYPE(char))
        char_convert_char(data);
    else if (type == TYPE(string))
        char_convert_string(data);
    else if (type == TYPE(shared_string))
        char_convert_shared_string(data);
    else if (type == TYPE(buffer))
        char_convert_buffer(data);
    else if (type == TYPE(ptr))
        char_convert_ptr(data);
    else
        convert_failure(TYPE(char), type, "unknown target type");
}

static typed_value_type_t typed_value_char_type = {
    "char",
    char_ctor,
    null_dtor,                          /* don't need */
    char_get,
    char_convert,
    char_get_int,                       /* cast */
    char_get_short,                     /* cast */
    char_get_long,                      /* cast */
    char_get_float,                     /* cast */
    char_get_double,                    /* cast */
    char_get_char,                      /* = */
    char_get_string,                    /* 1-length-string, allocated */
    char_get_shared_string,             /* 1CC-string */
    char_get_buffer,                    /* memcpy, allocated */
    char_get_ptr,                       /* ERROR, meaningless */
    char_convert_int,                   /* cast */
    char_convert_short,                 /* cast */
    char_convert_long,                  /* cast */
    char_convert_float,                 /* cast */
    char_convert_double,                /* cast */
    char_convert_char,                  /* = */
    char_convert_string,                /* 1-length-string, allocated */
    char_convert_shared_string,         /* 1CC-string */
    char_convert_buffer,                /* memcpy, allocated */
    char_convert_ptr,                   /* ERROR, meaningless */
};

/* .section. string */

static void string_ctor(typed_value_union_t *data, typed_value_union_t *init) {
    if (init->vstring)
        data->vstring = strdup(init->vstring);
    else
        data->vstring = NULL;
}

static void string_dtor(typed_value_union_t *data) {
    if (data->vstring)
        free(data->vstring);
}

static int string_get_int(typed_value_union_t *data) {
    if (data->vstring)
        return (int)strtol(data->vstring, NULL, 0);
    return 0;
}

static short string_get_short(typed_value_union_t *data) {
    if (data->vstring)
        return (short)strtol(data->vstring, NULL, 0);
    return 0;
}

static gint64 string_get_long(typed_value_union_t *data) {
    if (data->vstring)
        return (gint64)strtod(data->vstring, NULL);
    return 0l;
}

static float string_get_float(typed_value_union_t *data) {
    if (data->vstring)
        return (float)strtod(data->vstring, NULL);
    return 0.0f;
}

static double string_get_double(typed_value_union_t *data) {
    if (data->vstring)
        return (double)strtod(data->vstring, NULL);
    return 0.0;
}

static char string_get_char(typed_value_union_t *data) {
    if (data->vstring)
        return data->vchar;
    return '\0';
}

static char *string_get_string(typed_value_union_t *data) {
    if (data->vstring)
        return strdup(data->vstring);
    return NULL;
}

static char *string_get_shared_string(typed_value_union_t *data) {
    return data->vstring;               /* cast */
}

static buffer_t *string_get_buffer(typed_value_union_t *data) {
    if (data->vstring) {
        int len = strlen(data->vstring);
        buffer_t *buffer = buffer_sized_new(len);
        memcpy(buffer_ptr(buffer), data->vstring, len);
        return buffer;
    }
    return NULL;
}

static void *string_get_ptr(typed_value_union_t *data) {
    return data->vstring;               /* cast */
}

static int string_convert_int(typed_value_union_t *data) {
    if (data->vstring) {
        int value = string_get_int(data);
        string_dtor(data);
        return data->vint = value;
    }
    return 0;
}

static short string_convert_short(typed_value_union_t *data) {
    if (data->vstring) {
        short value = string_get_short(data);
        string_dtor(data);
        return data->vshort = value;
    }
    return 0;
}

static gint64 string_convert_long(typed_value_union_t *data) {
    if (data->vstring) {
        gint64 value = string_get_long(data);
        string_dtor(data);
        return data->vlong = value;
    }
    return 0;
}

static float string_convert_float(typed_value_union_t *data) {
    if (data->vstring) {
        float value = string_get_float(data);
        string_dtor(data);
        return data->vfloat = value;
    }
    return 0;
}

static double string_convert_double(typed_value_union_t *data) {
    if (data->vstring) {
        double value = string_get_double(data);
        string_dtor(data);
        return data->vdouble = value;
    }
    return 0;
}

static char string_convert_char(typed_value_union_t *data) {
    if (data->vstring) {
        char value = string_get_char(data);
        string_dtor(data);
        return data->vchar = value;
    }
    return 0;
}

static char *string_convert_string(typed_value_union_t *data) {
    return data->vstring;               /* = */
}

static char *string_convert_shared_string(typed_value_union_t *data) {
    convert_failure(TYPE(string), TYPE(shared_string), "may result in memory-leaks");
    return NULL;
}

static buffer_t *string_convert_buffer(typed_value_union_t *data) {
    if (data->vstring) {
        buffer_t *value = string_get_buffer(data);
        string_dtor(data);
        return data->vbuffer = value;
    }
    return NULL;
}

static void *string_convert_ptr(typed_value_union_t *data) {
    convert_failure(TYPE(string), TYPE(ptr), "may result in memory-leaks");
    return NULL;
}

static void string_get(typed_value_union_t *data, typed_value_union_t *dest, typed_value_type_t *type) {
    ASSERT(data);
    ASSERT(dest);
    ASSERT(type);
    if (type == TYPE(int))
        dest->vint = string_get_int(data);
    else if (type == TYPE(short))
        dest->vshort = string_get_short(data);
    else if (type == TYPE(long))
        dest->vlong = string_get_long(data);
    else if (type == TYPE(float))
        dest->vfloat = string_get_float(data);
    else if (type == TYPE(double))
        dest->vdouble = string_get_double(data);
    else if (type == TYPE(char))
        dest->vchar = string_get_char(data);
    else if (type == TYPE(string))
        data->vstring = string_get_string(data);
    else if (type == TYPE(shared_string))
        data->vstring = string_get_shared_string(data);
    else if (type == TYPE(buffer))
        data->vbuffer = string_get_buffer(data);
    else if (type == TYPE(ptr))
        data->vptr = string_get_ptr(data);
    else
        convert_failure(TYPE(string), type, "unknown target type");
}

static void string_convert(typed_value_union_t *data, typed_value_type_t *type) {
    ASSERT(data);
    ASSERT(type);
    if (type == TYPE(int))
        string_convert_int(data);
    else if (type == TYPE(short))
        string_convert_short(data);
    else if (type == TYPE(long))
        string_convert_long(data);
    else if (type == TYPE(float))
        string_convert_float(data);
    else if (type == TYPE(double))
        string_convert_double(data);
    else if (type == TYPE(char))
        string_convert_char(data);
    else if (type == TYPE(string))
        string_convert_string(data);
    else if (type == TYPE(shared_string))
        string_convert_shared_string(data);
    else if (type == TYPE(buffer))
        string_convert_buffer(data);
    else if (type == TYPE(ptr))
        string_convert_ptr(data);
    else
        convert_failure(TYPE(string), type, "unknown target type");
}

static typed_value_type_t typed_value_string_type = {
    "string",
    string_ctor,                        /* strdup, allocated */
    null_dtor,                          /* free */
    string_get,
    string_convert,
    string_get_int,                     /* strtol, narrow-cast */
    string_get_short,                   /* strtol, narrow-cast */
    string_get_long,                    /* strtod, narrow-cast */
    string_get_float,                   /* strtod, narrow-cast */
    string_get_double,                  /* strtod, narrow-cast */
    string_get_char,                    /* string[0], narrow-cast */
    string_get_string,                  /* strdup, allocated */
    string_get_shared_string,           /* cast */
    string_get_buffer,                  /* memcpy, allocated */
    string_get_ptr,                     /* cast */
    string_convert_int,                 /* strtol, narrow-cast */
    string_convert_short,               /* strtol, narrow-cast */
    string_convert_long,                /* strtod, narrow-cast */
    string_convert_float,               /* strtod, narrow-cast */
    string_convert_double,              /* strtod, narrow-cast */
    string_convert_char,                /* string[0], narrow-cast */
    string_convert_string,              /* = */
    string_convert_shared_string,       /* ERROR, memory-leaks */
    string_convert_buffer,              /* memcpy, allocated */
    string_convert_ptr,                 /* ERROR, memory-leaks */
};

/* .section. shared-string */

static void shared_string_ctor(typed_value_union_t *data, typed_value_union_t *init) {
    data->vstring = init->vstring;
}

static int shared_string_get_int(typed_value_union_t *data) {
    if (data->vstring)
        return (int)strtol(data->vstring, NULL, 0);
    return 0;
}

static short shared_string_get_short(typed_value_union_t *data) {
    if (data->vstring)
        return (short)strtol(data->vstring, NULL, 0);
    return 0;
}

static gint64 shared_string_get_long(typed_value_union_t *data) {
    if (data->vstring)
        return (gint64)strtod(data->vstring, NULL);
    return 0l;
}

static float shared_string_get_float(typed_value_union_t *data) {
    if (data->vstring)
        return (float)strtod(data->vstring, NULL);
    return 0.0f;
}

static double shared_string_get_double(typed_value_union_t *data) {
    if (data->vstring)
        return (double)strtod(data->vstring, NULL);
    return 0.0;
}

static char shared_string_get_char(typed_value_union_t *data) {
    if (data->vstring)
        return data->vchar;
    return '\0';
}

static char *shared_string_get_string(typed_value_union_t *data) {
    if (data->vstring)
        return strdup(data->vstring);
    return NULL;
}

static char *shared_string_get_shared_string(typed_value_union_t *data) {
    return data->vstring;               /* = */
}

static buffer_t *shared_string_get_buffer(typed_value_union_t *data) {
    if (data->vstring) {
        int len = strlen(data->vstring);
        buffer_t *buffer = buffer_sized_new(len);
        memcpy(buffer_ptr(buffer), data->vstring, len);
        return buffer;
    }
    return NULL;
}

static void *shared_string_get_ptr(typed_value_union_t *data) {
    return data->vstring;               /* cast */
}

static int shared_string_convert_int(typed_value_union_t *data) {
    if (data->vstring) {
        int value = shared_string_get_int(data);
        return data->vint = value;
    }
    return 0;
}

static short shared_string_convert_short(typed_value_union_t *data) {
    if (data->vstring) {
        short value = shared_string_get_short(data);
        return data->vshort = value;
    }
    return 0;
}

static gint64 shared_string_convert_long(typed_value_union_t *data) {
    if (data->vstring) {
        gint64 value = shared_string_get_long(data);
        return data->vlong = value;
    }
    return 0;
}

static float shared_string_convert_float(typed_value_union_t *data) {
    if (data->vstring) {
        float value = shared_string_get_float(data);
        return data->vfloat = value;
    }
    return 0;
}

static double shared_string_convert_double(typed_value_union_t *data) {
    if (data->vstring) {
        double value = shared_string_get_double(data);
        return data->vdouble = value;
    }
    return 0;
}

static char shared_string_convert_char(typed_value_union_t *data) {
    if (data->vstring) {
        char value = shared_string_get_char(data);
        return data->vchar = value;
    }
    return 0;
}

static char *shared_string_convert_string(typed_value_union_t *data) {
    if (data->vstring) {
        char *value = shared_string_get_string(data);
        return data->vstring = value;
    }
    return NULL;
}

static char *shared_string_convert_shared_string(typed_value_union_t *data) {
    return data->vstring;               /* = */
}

static buffer_t *shared_string_convert_buffer(typed_value_union_t *data) {
    if (data->vstring) {
        buffer_t *value = shared_string_get_buffer(data);
        return data->vbuffer = value;
    }
    return NULL;
}

static void *shared_string_convert_ptr(typed_value_union_t *data) {
    return (void *)data->vstring;       /* cast */
}

static void shared_string_get(typed_value_union_t *data, typed_value_union_t *dest, typed_value_type_t *type) {
    ASSERT(data);
    ASSERT(dest);
    ASSERT(type);
    if (type == TYPE(int))
        dest->vint = shared_string_get_int(data);
    else if (type == TYPE(short))
        dest->vshort = shared_string_get_short(data);
    else if (type == TYPE(long))
        dest->vlong = shared_string_get_long(data);
    else if (type == TYPE(float))
        dest->vfloat = shared_string_get_float(data);
    else if (type == TYPE(double))
        dest->vdouble = shared_string_get_double(data);
    else if (type == TYPE(char))
        dest->vchar = shared_string_get_char(data);
    else if (type == TYPE(string))
        data->vstring = shared_string_get_string(data);
    else if (type == TYPE(shared_string))
        data->vstring = shared_string_get_shared_string(data);
    else if (type == TYPE(buffer))
        data->vbuffer = shared_string_get_buffer(data);
    else if (type == TYPE(ptr))
        data->vptr = shared_string_get_ptr(data);
    else
        convert_failure(TYPE(shared_string), type, "unknown target type");
}

static void shared_string_convert(typed_value_union_t *data, typed_value_type_t *type) {
    ASSERT(data);
    ASSERT(type);
    if (type == TYPE(int))
        shared_string_convert_int(data);
    else if (type == TYPE(short))
        shared_string_convert_short(data);
    else if (type == TYPE(long))
        shared_string_convert_long(data);
    else if (type == TYPE(float))
        shared_string_convert_float(data);
    else if (type == TYPE(double))
        shared_string_convert_double(data);
    else if (type == TYPE(char))
        shared_string_convert_char(data);
    else if (type == TYPE(string))
        shared_string_convert_string(data);
    else if (type == TYPE(shared_string))
        shared_string_convert_shared_string(data);
    else if (type == TYPE(buffer))
        shared_string_convert_buffer(data);
    else if (type == TYPE(ptr))
        shared_string_convert_ptr(data);
    else
        convert_failure(TYPE(shared_string), type, "unknown target type");
}

static typed_value_type_t typed_value_shared_string_type = {
    "shared-string",
    shared_string_ctor,                 /* = */
    null_dtor,
    shared_string_get,
    shared_string_convert,
    shared_string_get_int,              /* strtol, narrow-cast */
    shared_string_get_short,            /* strtol, narrow-cast */
    shared_string_get_long,             /* strtod, narrow-cast */
    shared_string_get_float,            /* strtod, narrow-cast */
    shared_string_get_double,           /* strtod, narrow-cast */
    shared_string_get_char,             /* string[0], narrow-cast */
    shared_string_get_string,           /* strdup, allocated */
    shared_string_get_shared_string,    /* = */
    shared_string_get_buffer,           /* memcpy, allocated */
    shared_string_get_ptr,              /* cast */
    shared_string_convert_int,          /* strtol, narrow-cast */
    shared_string_convert_short,        /* strtol, narrow-cast */
    shared_string_convert_long,         /* strtod, narrow-cast */
    shared_string_convert_float,        /* strtod, narrow-cast */
    shared_string_convert_double,       /* strtod, narrow-cast */
    shared_string_convert_char,         /* string[0], narrow-cast */
    shared_string_convert_string,       /* strdup, allocated */
    shared_string_convert_shared_string, /* = */
    shared_string_convert_buffer,       /* memcpy, allocated */
    shared_string_convert_ptr,          /* cast */
};

/* .section. buffer */

static void buffer_ctor(typed_value_union_t *data, typed_value_union_t *init) {
    if (init->vbuffer)
        data->vbuffer = buffer_copy(init->vbuffer);
    else
        data->vbuffer = NULL;
}

static void buffer_dtor(typed_value_union_t *data) {
    if (data->vbuffer)
        buffer_free(data->vbuffer);
}

static int buffer_get_int(typed_value_union_t *data) {
    if (data->vbuffer)                  /* BUG: non-term */
        return (int)strtol((char *)buffer_ptr(data->vbuffer), NULL, 0);
    return 0;
}

static short buffer_get_short(typed_value_union_t *data) {
    if (data->vbuffer)                  /* BUG: non-term */
        return (short)strtol((char *)buffer_ptr(data->vbuffer), NULL, 0);
    return 0;
}

static gint64 buffer_get_long(typed_value_union_t *data) {
    if (data->vbuffer)                  /* BUG: non-term */
        return (gint64)strtod((char *)buffer_ptr(data->vbuffer), NULL);
    return 0l;
}

static float buffer_get_float(typed_value_union_t *data) {
    if (data->vbuffer)                  /* BUG: non-term */
        return (float)strtod((char *)buffer_ptr(data->vbuffer), NULL);
    return 0.0f;
}

static double buffer_get_double(typed_value_union_t *data) {
    if (data->vbuffer)                  /* BUG: non-term */
        return (double)strtod((char *)buffer_ptr(data->vbuffer), NULL);
    return 0.0;
}

static char buffer_get_char(typed_value_union_t *data) {
    if (data->vbuffer)
        return data->vchar;
    return '\0';
}

static char *buffer_get_string(typed_value_union_t *data) {
    if (data->vbuffer) {
      void *ptr = buffer_ptr(data->vbuffer);
      if (ptr)
        return g_strndup((char *)ptr, buffer_size(data->vbuffer));
    }
    return NULL;
}

static char *buffer_get_shared_string(typed_value_union_t *data) {
    return (char *)buffer_ptr(data->vbuffer); /* cast */
}

static buffer_t *buffer_get_buffer(typed_value_union_t *data) {
    if (data->vbuffer) {
        char *string = (char *)buffer_ptr(data->vbuffer);
        if (string) {
            int len = strlen(string);
            buffer_t *buffer = buffer_sized_new(len);
            memcpy(string, data->vbuffer, len);
            return buffer;
        }
    }
    return NULL;
}

static void *buffer_get_ptr(typed_value_union_t *data) {
    return data->vbuffer;               /* cast */
}

static int buffer_convert_int(typed_value_union_t *data) {
    if (data->vbuffer) {
        int value = buffer_get_int(data);
        buffer_dtor(data);
        return data->vint = value;
    }
    return 0;
}

static short buffer_convert_short(typed_value_union_t *data) {
    if (data->vbuffer) {
        short value = buffer_get_short(data);
        buffer_dtor(data);
        return data->vshort = value;
    }
    return 0;
}

static gint64 buffer_convert_long(typed_value_union_t *data) {
    if (data->vbuffer) {
        gint64 value = buffer_get_long(data);
        buffer_dtor(data);
        return data->vlong = value;
    }
    return 0;
}

static float buffer_convert_float(typed_value_union_t *data) {
    if (data->vbuffer) {
        float value = buffer_get_float(data);
        buffer_dtor(data);
        return data->vfloat = value;
    }
    return 0;
}

static double buffer_convert_double(typed_value_union_t *data) {
    if (data->vbuffer) {
        double value = buffer_get_double(data);
        buffer_dtor(data);
        return data->vdouble = value;
    }
    return 0;
}

static char buffer_convert_char(typed_value_union_t *data) {
    if (data->vbuffer) {
        char value = buffer_get_char(data);
        buffer_dtor(data);
        return data->vchar = value;
    }
    return 0;
}

static char *buffer_convert_string(typed_value_union_t *data) {
    if (data->vbuffer) {
        char *value = buffer_get_string(data);
        buffer_dtor(data);
        return data->vstring = value;
    }
    return NULL;
}

static char *buffer_convert_shared_string(typed_value_union_t *data) {
    convert_failure(TYPE(buffer), TYPE(shared_string), "may result in memory-leaks");
    return NULL;
}

static buffer_t *buffer_convert_buffer(typed_value_union_t *data) {
    return data->vbuffer;               /* = */
}

static void *buffer_convert_ptr(typed_value_union_t *data) {
    convert_failure(TYPE(buffer), TYPE(ptr), "may result in memory-leaks");
    return NULL;
}

static void buffer_get(typed_value_union_t *data, typed_value_union_t *dest, typed_value_type_t *type) {
    ASSERT(data);
    ASSERT(dest);
    ASSERT(type);
    if (type == TYPE(int))
        dest->vint = buffer_get_int(data);
    else if (type == TYPE(short))
        dest->vshort = buffer_get_short(data);
    else if (type == TYPE(long))
        dest->vlong = buffer_get_long(data);
    else if (type == TYPE(float))
        dest->vfloat = buffer_get_float(data);
    else if (type == TYPE(double))
        dest->vdouble = buffer_get_double(data);
    else if (type == TYPE(char))
        dest->vchar = buffer_get_char(data);
    else if (type == TYPE(string))
        data->vstring = buffer_get_string(data);
    else if (type == TYPE(shared_string))
        data->vstring = buffer_get_shared_string(data);
    else if (type == TYPE(buffer))
        data->vbuffer = buffer_get_buffer(data);
    else if (type == TYPE(ptr))
        data->vptr = buffer_get_ptr(data);
    else
        convert_failure(TYPE(buffer), type, "unknown target type");
}

static void buffer_convert(typed_value_union_t *data, typed_value_type_t *type) {
    ASSERT(data);
    ASSERT(type);
    if (type == TYPE(int))
        buffer_convert_int(data);
    else if (type == TYPE(short))
        buffer_convert_short(data);
    else if (type == TYPE(long))
        buffer_convert_long(data);
    else if (type == TYPE(float))
        buffer_convert_float(data);
    else if (type == TYPE(double))
        buffer_convert_double(data);
    else if (type == TYPE(char))
        buffer_convert_char(data);
    else if (type == TYPE(string))
        buffer_convert_string(data);
    else if (type == TYPE(shared_string))
        buffer_convert_shared_string(data);
    else if (type == TYPE(buffer))
        buffer_convert_buffer(data);
    else if (type == TYPE(ptr))
        buffer_convert_ptr(data);
    else
        convert_failure(TYPE(buffer), type, "unknown target type");
}

static typed_value_type_t typed_value_buffer_type = {
    "buffer",
    buffer_ctor,                        /* buffer_copy, allocated */
    buffer_dtor,                        /* free */
    buffer_get,
    buffer_convert,
    buffer_get_int,                     /* strtol, narrow-cast */
    buffer_get_short,                   /* strtol, narrow-cast */
    buffer_get_long,                    /* strtod, narrow-cast */
    buffer_get_float,                   /* strtod, narrow-cast */
    buffer_get_double,                  /* strtod, narrow-cast */
    buffer_get_char,                    /* buffer[0], narrow-cast */
    buffer_get_string,                  /* strdup, narrow-cast */
    buffer_get_shared_string,           /* cast buffer-ptr */
    buffer_get_buffer,                  /* buffer_copy, allocated */
    buffer_get_ptr,                     /* cast buffer-ptr */
    buffer_convert_int,                 /* strtol, narrow-cast */
    buffer_convert_short,               /* strtol, narrow-cast */
    buffer_convert_long,                /* strtod, narrow-cast */
    buffer_convert_float,               /* strtod, narrow-cast */
    buffer_convert_double,              /* strtod, narrow-cast */
    buffer_convert_char,                /* buffer[0], narrow-cast */
    buffer_convert_string,              /* strdup, allocated */
    buffer_convert_shared_string,       /* ERROR, memory-leaks */
    buffer_convert_buffer,              /* = */
    buffer_convert_ptr,                 /* ERROR, memory-leaks */
};

/* .section. ptr */

static void ptr_ctor(typed_value_union_t *data, typed_value_union_t *init) {
    data->vptr = init->vptr;
}

static int ptr_get_int(typed_value_union_t *data) {
    return (int)data->vptr;             /* reinterpret-cast */
}

static short ptr_get_short(typed_value_union_t *data) {
    convert_failure(TYPE(ptr), TYPE(short), "meaningless");
    return 0;
}

static gint64 ptr_get_long(typed_value_union_t *data) {
    return (gint64)data->vptr;          /* reinterpret-cast */
}

static float ptr_get_float(typed_value_union_t *data) {
    convert_failure(TYPE(ptr), TYPE(float), "meaningless");
    return 0.0f;
}

static double ptr_get_double(typed_value_union_t *data) {
    convert_failure(TYPE(ptr), TYPE(double), "meaningless");
    return 0.0;
}

static char ptr_get_char(typed_value_union_t *data) {
    convert_failure(TYPE(ptr), TYPE(char), "meaningless");
    return '\0';
}

static char *ptr_get_string(typed_value_union_t *data) {
    convert_failure(TYPE(ptr), TYPE(string), "unknown length");
    return NULL;
}

static char *ptr_get_shared_string(typed_value_union_t *data) {
    return (char *)data->vptr;          /* cast */
}

static buffer_t *ptr_get_buffer(typed_value_union_t *data) {
    convert_failure(TYPE(ptr), TYPE(buffer), "unknown length");
    return NULL;
}

static void *ptr_get_ptr(typed_value_union_t *data) {
    return data->vptr;                  /* = */
}

static int ptr_convert_int(typed_value_union_t *data) {
    return data->vint = (int)data->vptr; /* reinterpret-cast */
}

static short ptr_convert_short(typed_value_union_t *data) {
    convert_failure(TYPE(ptr), TYPE(short), "meaningless");
    return 0;
}

static gint64 ptr_convert_long(typed_value_union_t *data) {
    return data->vlong = (gint64)data->vptr; /* reinterpret-cast */
}

static float ptr_convert_float(typed_value_union_t *data) {
    convert_failure(TYPE(ptr), TYPE(float), "meaningless");
    return 0;
}

static double ptr_convert_double(typed_value_union_t *data) {
    convert_failure(TYPE(ptr), TYPE(double), "meaningless");
    return 0;
}

static char ptr_convert_char(typed_value_union_t *data) {
    convert_failure(TYPE(ptr), TYPE(char), "meaningless");
    return 0;
}

static char *ptr_convert_string(typed_value_union_t *data) {
    convert_failure(TYPE(ptr), TYPE(string), "unknown length");
    return NULL;
}

static char *ptr_convert_shared_string(typed_value_union_t *data) {
    return (char *)data->vptr;
}

static buffer_t *ptr_convert_buffer(typed_value_union_t *data) {
    convert_failure(TYPE(ptr), TYPE(buffer), "unknown length");
    return NULL;
}

static void *ptr_convert_ptr(typed_value_union_t *data) {
    return (void *)data->vptr;          /* = */
}

static void ptr_get(typed_value_union_t *data, typed_value_union_t *dest, typed_value_type_t *type) {
    ASSERT(data);
    ASSERT(dest);
    ASSERT(type);
    if (type == TYPE(int))
        dest->vint = ptr_get_int(data);
    else if (type == TYPE(short))
        dest->vshort = ptr_get_short(data);
    else if (type == TYPE(long))
        dest->vlong = ptr_get_long(data);
    else if (type == TYPE(float))
        dest->vfloat = ptr_get_float(data);
    else if (type == TYPE(double))
        dest->vdouble = ptr_get_double(data);
    else if (type == TYPE(char))
        dest->vchar = ptr_get_char(data);
    else if (type == TYPE(string))
        data->vstring = ptr_get_string(data);
    else if (type == TYPE(shared_string))
        data->vstring = ptr_get_shared_string(data);
    else if (type == TYPE(buffer))
        data->vbuffer = ptr_get_buffer(data);
    else if (type == TYPE(ptr))
        data->vptr = ptr_get_ptr(data);
    else
        convert_failure(TYPE(ptr), type, "unknown target type");
}

static void ptr_convert(typed_value_union_t *data, typed_value_type_t *type) {
    ASSERT(data);
    ASSERT(type);
    if (type == TYPE(int))
        ptr_convert_int(data);
    else if (type == TYPE(short))
        ptr_convert_short(data);
    else if (type == TYPE(long))
        ptr_convert_long(data);
    else if (type == TYPE(float))
        ptr_convert_float(data);
    else if (type == TYPE(double))
        ptr_convert_double(data);
    else if (type == TYPE(char))
        ptr_convert_char(data);
    else if (type == TYPE(string))
        ptr_convert_string(data);
    else if (type == TYPE(shared_string))
        ptr_convert_shared_string(data);
    else if (type == TYPE(buffer))
        ptr_convert_buffer(data);
    else if (type == TYPE(ptr))
        ptr_convert_ptr(data);
    else
        convert_failure(TYPE(ptr), type, "unknown target type");
}

static typed_value_type_t typed_value_ptr_type = {
    "shared-string",
    ptr_ctor,
    null_dtor,
    ptr_get,
    ptr_convert,
    ptr_get_int,                        /* reinterpret-cast */
    ptr_get_short,                      /* ERROR: meaningless */
    ptr_get_long,                       /* reinterpret-cast */
    ptr_get_float,                      /* ERROR: meaningless */
    ptr_get_double,                     /* ERROR: meaningless */
    ptr_get_char,                       /* ERROR: meaningless */
    ptr_get_string,                     /* ERROR: unknown-length */
    ptr_get_shared_string,              /* cast */
    ptr_get_buffer,                     /* ERROR: unknown-length */
    ptr_get_ptr,                        /* = */
    ptr_convert_int,                    /* reinterpret-cast */
    ptr_convert_short,                  /* ERROR: meaningless */
    ptr_convert_long,                   /* reinterpret-cast */
    ptr_convert_float,                  /* ERROR: meaningless */
    ptr_convert_double,                 /* ERROR: meaningless */
    ptr_convert_char,                   /* ERROR: meaningless */
    ptr_convert_string,                 /* ERROR: unknown length */
    ptr_convert_shared_string,          /* cast */
    ptr_convert_buffer,                 /* ERROR: unknown length */
    ptr_convert_ptr,                    /* = */
};

/* .section. top-level api */

typed_value_t *
typed_value_new() {
    typed_value_t *tv;
    tv = g_new(typed_value_t, 1);
    tv->type = TYPED_VALUE_INT;
    tv->to_string = NULL;
    tv->v.vint = 0;
    return tv;
}

void
typed_value_free(typed_value_t *tv) {
    ASSERT(tv);
    ASSERT(tv->type);
    tv->type->dtor(&tv->v);             /* unset */
    if (tv->to_string)
        free(tv->to_string);            /* free to_string */
    free(tv);
}

const char *
typed_value_typename(typed_value_t *tv) {
    ASSERT(tv);
    ASSERT(tv->type);
    return tv->type->typename;
}

void
typed_value_set(typed_value_t *tv, typed_value_t *src) {
    ASSERT(tv);
    ASSERT(src);
    ASSERT(tv->type);
    ASSERT(src->type);
    tv->type->dtor(&tv->v);             /* unset */
    tv->type = src->type;
    tv->type->ctor(&tv->v, &src->v);    /* value copy */
}

void
typed_value_unset(typed_value_t *tv) {
    ASSERT(tv);
    ASSERT(tv->type);
    tv->type->dtor(&tv->v);             /* unset */
    tv->type = TYPED_VALUE_INT;         /* reset type */
}

int
typed_value_get_int(typed_value_t *tv) {
    ASSERT(tv);
    ASSERT(tv->type);
    return tv->type->get_int(&tv->v);
}

short
typed_value_get_short(typed_value_t *tv) {
    ASSERT(tv);
    ASSERT(tv->type);
    return tv->type->get_short(&tv->v);
}

gint64
typed_value_get_long(typed_value_t *tv) {
    ASSERT(tv);
    ASSERT(tv->type);
    return tv->type->get_long(&tv->v);
}

float
typed_value_get_float(typed_value_t *tv) {
    ASSERT(tv);
    ASSERT(tv->type);
    return tv->type->get_float(&tv->v);
}

double
typed_value_get_double(typed_value_t *tv) {
    ASSERT(tv);
    ASSERT(tv->type);
    return tv->type->get_double(&tv->v);
}

char
typed_value_get_char(typed_value_t *tv) {
    ASSERT(tv);
    ASSERT(tv->type);
    return tv->type->get_char(&tv->v);
}

char *
typed_value_get_string(typed_value_t *tv) {
    ASSERT(tv);
    ASSERT(tv->type);
    if (tv->to_string)
        free(tv->to_string);
    return tv->to_string = tv->type->get_string(&tv->v);
}

char *
typed_value_get_shared_string(typed_value_t *tv) {
    ASSERT(tv);
    ASSERT(tv->type);
    return tv->type->get_shared_string(&tv->v);
}

buffer_t *
typed_value_get_buffer(typed_value_t *tv) {
    ASSERT(tv);
    ASSERT(tv->type);
    /* this "easy api" don't allow to get buffer from other types, for avoid
     * memory-leaks. */
    if (tv->type == TYPED_VALUE_BUFFER)
        return tv->v.vbuffer;
    convert_failure(tv->type, TYPED_VALUE_BUFFER,
                    "using this method in 'easy-api' may result in memory-leaks");
    return NULL;
}

void *
typed_value_get_ptr(typed_value_t *tv) {
    ASSERT(tv);
    ASSERT(tv->type);
    return tv->type->get_ptr(&tv->v);
}

#define _typed_value_set_impl(vn, vt) \
    void typed_value_set_##vn(typed_value_t *tv, vt value) { \
        ASSERT(tv); \
        ASSERT(tv->type); \
        typed_value_unset(tv); \
        tv->type->ctor(&tv->v, (typed_value_union_t *)&value); \
        tv->type = &typed_value_##vn##_type; \
    }
TYPED_VALUE_GENERIC(_typed_value_set_impl);

#define _typed_value_convert_impl(vn, vt) \
    vt typed_value_convert_##vn(typed_value_t *tv) { \
        typed_value_type_t *old_type; \
        ASSERT(tv); \
        ASSERT(old_type = tv->type); \
        tv->type = &typed_value_##vn##_type; \
        return old_type->convert_##vn(&tv->v); \
    }
TYPED_VALUE_GENERIC(_typed_value_convert_impl);
