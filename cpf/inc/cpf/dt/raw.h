#ifndef _basetype_umac_n_xWDeY4rY__w7ga_
#define _basetype_umac_n_xWDeY4rY__w7ga_

#include "config.h"

#define typedef_strict(t, s) \
    typedef struct { t v; } s;

typedef signed char i8_t;
typedef unsigned char u8_t;
typedef signed short i16_t;
typedef unsigned short u16_t;
typedef signed long i32_t;
typedef unsigned long u32_t;

typedef signed __int64 i64_t;
typedef unsigned __int64 u64_t;

typedef float f32_t;
typedef double f64_t;
typedef long double f128_t;
typedef struct _c32_t c32_t;
typedef struct _c64_t c64_t;
typedef struct _c128_t c128_t;
struct _c32_t { f32_t r, i; };
struct _c64_t { f64_t r, i; };
struct _c128_t { f128_t r, i; };

typedef struct _b8_t b8_t;
typedef struct _b16_t b16_t;
typedef struct _b32_t b32_t;
typedef struct _b64_t b64_t;
struct _b8_t {
    int _0: 1, _1: 1, _2: 1, _3: 1, _4: 1, _5: 1, _6: 1, _7: 1;
};
struct _b16_t {
    int _0: 1, _1: 1, _2: 1, _3: 1, _4: 1, _5: 1, _6: 1, _7: 1;
    int _8: 1, _9: 1, _a: 1, _b: 1, _c: 1, _d: 1, _e: 1, _f: 1;
};
struct _b32_t {
    int _0: 1, _1: 1, _2: 1, _3: 1, _4: 1, _5: 1, _6: 1, _7: 1;
    int _8: 1, _9: 1, _a: 1, _b: 1, _c: 1, _d: 1, _e: 1, _f: 1;
    int _g: 1, _h: 1, _i: 1, _j: 1, _k: 1, _l: 1, _m: 1, _n: 1;
    int _o: 1, _p: 1, _q: 1, _r: 1, _s: 1, _t: 1, _u: 1, _v: 1;
};
struct _b64_t {
    int _0: 1, _1: 1, _2: 1, _3: 1, _4: 1, _5: 1, _6: 1, _7: 1;
    int _8: 1, _9: 1, _a: 1, _b: 1, _c: 1, _d: 1, _e: 1, _f: 1;
    int _g: 1, _h: 1, _i: 1, _j: 1, _k: 1, _l: 1, _m: 1, _n: 1;
    int _o: 1, _p: 1, _q: 1, _r: 1, _s: 1, _t: 1, _u: 1, _v: 1;
    b32_t __;
};

#define typedef_matrixes(base) \
    typedef struct _##base##p_t { base##_t x, y; } base##p_t; \
    typedef struct _##base##v_t { base##_t x, y, z; } base##v_t; \
    typedef struct _##base##w_t { base##_t x, y, z, w; } base##w_t; \
    typedef struct _##base##P_t { base##_t \
        x0, y0, \
        x1, y1; } base##P_t; \
    typedef struct _##base##V_t { base##_t \
        x0, y0, z0, \
        x1, y1, z1, \
        x2, y2, z2; } base##V_t; \
    typedef struct _##base##W_t { base##_t \
        x0, y0, z0, w0, \
        x1, y1, z1, w1, \
        x2, y2, z2, w2, \
        x3, y3, z3, w3; } base##W_t

typedef_matrixes(i8);
typedef_matrixes(u8);
typedef_matrixes(i16);
typedef_matrixes(u16);
typedef_matrixes(i32);
typedef_matrixes(u32);
typedef_matrixes(f32);
typedef_matrixes(f64);
typedef_matrixes(f128);
typedef_matrixes(c32);
typedef_matrixes(c64);
typedef_matrixes(c128);

typedef void *unknown_t;

#endif
