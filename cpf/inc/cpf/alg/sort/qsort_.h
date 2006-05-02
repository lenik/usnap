#ifndef _qsort_utim_c7d3UgWqQgRddz34_
#define _qsort_utim_c7d3UgWqQgRddz34_ "$Id: qsort_.h,v 1.2 2006-05-02 16:01:59 dansei Exp $"

typedef int (_cdecl *qsort_cmpf_t)(const void *, const void *, void *);

void qsort_(void *base, size_t num, size_t width, qsort_cmpf_t cmpf,
            void *user);

#endif
