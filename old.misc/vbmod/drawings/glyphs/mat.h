
#pragma once

// Column vector.
typedef f64v_t vector_t;
typedef f64p_t point_t;

vector_t *normalize(vector_t *v);
vector_t *translate(vector_t *v, double dx, double dy);
vector_t *translate(vector_t *v, vector_t *d);
vector_t *mirrorDiag(vector_t *v);
vector_t *mirrorH(vector_t *v);
vector_t *mirrorV(vector_t *v);
vector_t *transpose(vector_t *v);
vector_t *rotate(vector_t *v, double angle);
vector_t *rotate(vector_t *v, vector_t *o, double angle);
