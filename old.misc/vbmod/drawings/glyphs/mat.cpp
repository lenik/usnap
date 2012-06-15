
#include "stdafx.h"
#include "mat.h"
#include <math.h>

vector_t *normalize(vector_t *v) {
    if (v->z != 1.0f) {
        v->x = v->x / v->z;
        v->y = v->y / v->z;
        v->z = 1.0f;
    }
    return v;
}

vector_t *translate(vector_t *v, double dx, double dy) {
    v->x += dx;
    v->y += dy;
    return v;
}

vector_t *translate(vector_t *v, vector_t *d) {
    normalize(v);
    normalize(d);
    v->x += d->x;
    v->y += d->y;
    return v;
}

vector_t *mirrorDiag(vector_t *v) {
    v->x = -v->x;
    v->y = -v->y;
    return v;
}

vector_t *mirrorH(vector_t *v) {
    v->x = -v->x;
    return v;
}

vector_t *mirrorV(vector_t *v) {
    v->y = -v->y;
    return v;
}

vector_t *transpose(vector_t *v) {
    double f = v->x;
    v->x = v->y;
    v->y = f;
    return v;
}

vector_t *rotate(vector_t *v, double angle) {
    double C = cos(angle);
    double S = sin(angle);
    vector_t t;
    t.x =  C * v->x + S * v->y;
    t.y = -S * v->x + C * v->y;
    v->x = t.x;
    v->y = t.y;
    return v;
}

vector_t *rotate(vector_t *v, vector_t *o, double angle) {
    normalize(v);
    normalize(o);
    translate(v, -o->x, -o->y);
    rotate(v, angle);
    translate(v, o->x, o->y);
    return v;
}

double dist_euclid(vector_t *a, vector_t *b) {
    normalize(a);
    normalize(b);
    double dx = a->x - b->x;
    double dy = a->y - b->y;
    return sqrt(dx * dx + dy * dy);
}
