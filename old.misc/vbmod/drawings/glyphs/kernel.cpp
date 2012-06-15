
#include "stdafx.h"
#include "glyphs.h"
#include "shape.h"
#include "kernel.h"
#include <math.h>

typedef enum arrowhead_si {
    ah_inspt = si_ext,                  /* 'inspt x y */
    ah_occupy,                          /* 'occupy len */
};

int ARROW_HEAD_SHAPE[][100] = {
    /* Normal        */ { ah_inspt, -3, 0,
                          si_poly, 3, -7, -4, 0, 0, -7, 4,
                          si_end },
    /* Normal-dbl    */ { ah_inspt, -6, 0,
                          ah_occupy, 3,
                          si_poly, 3, -7, -4, 0, 0, -7, 4,
                          si_poly, 3, -10, -4, -3, 0, -10, 4,
                          si_end },
    /* Sharp         */ { ah_inspt, -4, 0,
                          si_poly, 3, -7, -2, 0, 0, -7, 2,
                          si_end },
    /* Sharp-dbl     */ { ah_inspt, -8, 0,
                          ah_occupy, 4,
                          si_poly, 3, -7, -2, 0, 0, -7, 2,
                          si_poly, 3, -11, -2, -4, 0, -11, 2,
                          si_end },
    /* Diamond       */ { ah_inspt, -10, 0,
                          ah_occupy, 10,
                          si_poly, 5, 0, 0, -5, -3, -10, 0, -5, 3, 0, 0,
                          si_end },
    /* (end)         */ { si_end },
};

struct ArrowHeadShape {
    vector_t insert_more;
    // shape *shape;
};

void DrawArrow(HDC hDC, DWORD type, vector_t s, vector_t e) {
    int shape = type & 0xFFFF;

    // TODO: temporary impl.
    MoveToEx(hDC, s.x, s.y, NULL);
    LineTo(hDC, e.x, e.y);

    if (type == arrowNormal || type == arrowNormalDbl) {
        vector_t u;
        u.x = s.x - e.x;
        u.y = s.y - e.y;
        double len = sqrt(u.x * u.x + u.y * u.y);
        if (len > 0.01) {               // avoid divide by 0
            u.x = u.x / len * 10;
            u.y = u.y / len * 10;
        }
        vector_t sl = u;
        vector_t sr = u;
        rotate(&sl, -30 / 180.0 * 3.14);
        rotate(&sr,  30 / 180.0 * 3.14);
        sl.x += e.x;
        sl.y += e.y;
        sr.x += e.x;
        sr.y += e.y;
        MoveToEx(hDC, e.x, e.y, NULL);
        LineTo(hDC, sl.x, sl.y);
        MoveToEx(hDC, e.x, e.y, NULL);
        LineTo(hDC, sr.x, sr.y);

        if (type == arrowNormalDbl) {
            u.x *= 0.5;
            u.y *= 0.5;
            sl.x += u.x;
            sl.y += u.y;
            sr.x += u.x;
            sr.y += u.y;
            e.x += u.x;
            e.y += u.y;
            MoveToEx(hDC, e.x, e.y, NULL);
            LineTo(hDC, sl.x, sl.y);
            MoveToEx(hDC, e.x, e.y, NULL);
            LineTo(hDC, sr.x, sr.y);
        }
    } else {
        Ellipse(hDC, s.x, s.y, e.x, e.y);       // Draw anything unexpected.
    }
}
