
#include "stdhdrs.h"

#include <cpf/assert.h>
#include <cpf/dt/list.h>
#include <cpf/alg/sort/qsort_.h>

list_t *list_first(list_t *list) {
    if (list == 0)
        return 0;
    while (list->prev)
        list = list->prev;
    return list;
}

list_t *list_last(list_t *list) {
    if (list == 0)
        return 0;
    while (list->next)
        list = list->next;
    return list;
}

list_t *list_sibling(list_t *list, int index) {
    if (list == 0)
        return 0;
    if (index == 0)
        return list;
    if (index < 0)
        /* -2 | -1 0 */
        while (index++ && list)
            list = list->prev;
    else
        while (index-- && list)
            list = list->next;
    return list;
}

static list_t *_list_new(const void *data, size_t size) {
    list_t *list;
    if (size == 0) {
        list = (list_t *)malloc(16);
        if (! list) return 0;
        list->size = 0;                 /* special size */
        list_setv(list, data);
    } else {
        list = (list_t *)malloc(12 + size);
        if (! list) return 0;
        list->size = size;
        memcpy(list_data(list), data, size);
    }
    return list;
}

list_t *list_insert(list_t *list, const void *data, size_t size) {
    list_t *before = _list_new(data, size);
    if (! before) return 0;
    if (list) {
        before->next = list;
        if (before->prev = list->prev)
            list->prev->next = before;
        list->prev = before;
    } else {
        before->next = 0;
        before->prev = 0;
    }
    return before;
}

list_t *list_append(list_t *list, const void *data, size_t size) {
    list_t *after = _list_new(data, size);
    if (! after) return 0;
    if (list) {
        after->prev = list;
        if (after->next = list->next)
            list->next->prev = after;
        list->next = after;
    } else {
        after->next = 0;
        after->prev = 0;
    }
    return after;
}

list_t *list_detach(list_t **list) {
    list_t *d;
    _assert_(list);
    if (! (d = *list))
        return 0;
    if (d->prev) {
        if (d->prev->next = d->next) {
            d->next->prev = d->prev;
            d->next = 0;
        }
        *list = d->prev;
        d->prev = 0;
    } else {
        if (*list = d->next)
            (*list)->prev = 0;
        d->next = 0;
    }
    return d;
}

list_t *list_remove(list_t *list) {
    list_t *d;
    if (! list)
        return 0;
    d = list_detach(&list);
    free(d);
    return list;
}

list_t *list_push(list_t *list, const void *data, size_t size) {
    return list_append(list_last(list), data, size);
}

list_t *list_unshift(list_t *list, const void *data, size_t size) {
    return list_insert(list_first(list), data, size);
}

list_t *list_pop(list_t **list) {
    list_t *last;
    _assert_(list);
    if (! *list)
        return 0;
    last = list_last(*list);
    if (last)
        if (*list = last->prev) {
            (*list)->next = 0;
            last->prev = 0;
        }
    return last;
}

list_t *list_shift(list_t **list) {
    list_t *first;
    _assert_(list);
    if (! *list)
        return 0;
    first = list_first(*list);
    if (*list = first->next) {
        (*list)->prev = 0;
        first->next = 0;
    }
    return first;
}

list_t *list_copy(list_t *list) {
    list_t *copy;
    list_t *x;
    list_t *copy_x;

    if (! list)
        return 0;

    /* ... <list> ... */
    copy_x = copy = list_insert(0, list_data(list), list->size);

    if (x = list->prev) {
        while (x) {
            copy_x = list_insert(copy_x, list_data(x), x->size);
            x = x->prev;
        }
        copy_x = copy;
    }
    if (x = list->next) {
        while (x) {
            copy_x = list_append(copy_x, list_data(x), x->size);
            x = x->next;
        }
    }
    return copy;
}

struct _list_sort_cmpf_ctx {
    mem_cmpf_t mcmpf;
    void *mcmpf_param;
};

static int _cdecl _list_sort_cmpf(const void *a, const void *b, void *user) {
    struct _list_sort_cmpf_ctx *ctx =
        (struct _list_sort_cmpf_ctx *)user;
    const list_t *la = (const list_t *)a;
    const list_t *lb = (const list_t *)b;
    _assert_(ctx);
    _assert_(ctx->mcmpf);
    return ctx->mcmpf(list_data(la), la->size, list_data(lb), lb->size,
                      ctx->mcmpf_param);
}

list_t *list_sort(list_t *list, mem_cmpf_t mcmpf, void *user) {
    int n = 1;                          /* ... < list > ... */
    int i = 0;
    list_t *x;
    list_t **tbl;
    struct _list_sort_cmpf_ctx ctx;

    _assert_(mcmpf);

    if (! list)
        return 0;
    x = list;
    while (x->next) {
        x = x->next;
        n++;                            /* ... list < ... > */
    }
    while (list->prev) {
        list = list->prev;
        n++;                            /* < ... > list ... */
    }
    /* now list -> head */

    /* sort to temp table */
    tbl = (list_t **)malloc(n * sizeof(void *));
    x = list;
    while (x) {
        tbl[i++] =  x;
        x = x->next;
    }

    ctx.mcmpf = mcmpf;
    ctx.mcmpf_param = user;
    qsort_(tbl, n, sizeof(list_t *), _list_sort_cmpf, &ctx);

    /* re-link the list nodes according to the temp table */
    tbl[0]->prev = 0;
    for (i = 1; i < n; i++) {
        tbl[i - 1]->next = tbl[i];
        tbl[i]->prev = tbl[i - 1];
    }
    tbl[i - 1]->next = 0;

    free(tbl);
    return list;                        /* head */
}

list_t *list_add_sorted(list_t *list, const void *data, size_t size,
                        mem_cmpf_t cmpf, void *user) {
    int d;
    if (! list)
        return list_insert(0, data, size);
    d = cmpf(data, size, list_data(list), list->size, user);
    if (d > 0) {                        /* list ... > add */
        do {
            if (list->next)
                list = list->next;
            else
                return list_append(list, data, size);
        } while (cmpf(data, size, list_data(list), list->size, user) > 0);
        return list_insert(list, data, size);
    } else if (d < 0) {                 /* add > ... list */
        do {
            if (list->prev)
                list = list->prev;
            else
                return list_insert(list, data, size);
        } while (cmpf(data, size, list_data(list), list->size, user) > 0);
    }
    _assert_(d == 0);
    return list_insert(list, data, size);
}

list_t *list_free(list_t *list) {
    list_t *x;
    if (! list)
        return 0;
    if (x = list->prev) {               /* < ... > list ... */
        while (x->prev) {
            x = x->prev;
            free(x->next);
        }
        free(x);
    }
    x = list;                           /* ... < list ... > */
    while (x->next) {
        x = x->next;
        free(x->prev);
    }
    free(x);
    return 0;
}
