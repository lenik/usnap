
#pragma once

#include "mat.h"

typedef enum shapedef_instruction {
    si_nop,                             /* 'nop */
    si_stack,                           /* 'stack * 'end (enable stack-mode) */
    si_end,                             /* 'end */
    si_skip,                            /* 'skip n ... */
    si_abs,                             /* 'abs * 'end (absolute-coord-mode) */
    si_rel,                             /* 'rel * 'end (relative-coord-mode) */
    si_at,                              /* 'at x y * 'end */
    si_pt,                              /* 'pt x y */
    si_line,                            /* 'line x y x y */
    si_lineto,                          /* 'lineto x y */
    si_rect,                            /* 'rect x y x y */
    si_rectto,                          /* 'rectto x y */
    si_tri,                             /* 'tri x y x y x y */
    si_trito,                           /* 'trito x y x y */
    si_poly,                            /* 'poly n x y ... */
    si_polyto,                          /* 'polyto n x y ... */
    si_fill,                            /* 'fill */
    si_nofill,                          /* 'nofill */
    si_fg,                              /* 'fg color * 'end */
    si_nofg,                            /* 'nofg * 'end */
    si_bg,                              /* 'bg color * 'end */
    si_nobg,                            /* 'nobg * 'end */
    si_fontname,                        /* 'fontname c... 0 * 'end */
    si_fontbold,                        /* 'fontbold bool * 'end */
    si_fontitalic,                      /* 'fontitalic bool * 'end */
    si_fontunderline,                   /* 'fontunderline bool * 'end */
    si_char,                            /* 'char c */
    si_string,                          /* 'string c... 0 */
    si_ext,
} shapedef_pi;

#define SBF_FG                          0x00000001
#define SBF_BG                          0x00000002
#define SBF_FONTNAME                    0x00000100
#define SBF_FONTBOLD                    0x00000200
#define SBF_FONTITALIC                  0x00000400
#define SBF_FONTUNDERLINE               0x00000800

struct shape_basic {
    DWORD flags;
    int npt;
    HFONT hFont;
    vector_t *pts;
};
