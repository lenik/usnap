
#include <cpf/alg/sort/qsort_.h>

static qsort_cmpf_t _cmpf_new;
static void *_cmpf_user;
static int _cdecl _cmpf_old(const void *a, const void *b) {
    return _cmpf_new(a, b, _cmpf_user);
}

void qsort_(void *base, size_t num, size_t width, qsort_cmpf_t cmpf,
            void *user) {
    /* _qsort_lock */
    _cmpf_new = cmpf;
    _cmpf_user = user;
    qsort(base, num, width, _cmpf_old);
    /* _qsort_unlock */
}
