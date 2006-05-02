#ifndef _list_utim_c6OdoyATHaEjqss5_
#define _list_utim_c6OdoyATHaEjqss5_ "$Id: list.h,v 1.2 2006-05-02 13:30:27 dansei Exp $"

typedef struct _list_t list_t;

struct _list_t {
    list_t *next;
    list_t *prev;
    size_t size;
    union {
        char data[1];
        void *p;
        x8_t x[1];
        x16_t xx[1];
        x32_t xxxx[1];
    };
};

typedef int (_cdecl *mem_cmpf_t)(const void *, size_t, const void *, size_t,
                                 void *);

list_t *list_first(list_t *list);
list_t *list_last(list_t *list);
list_t *list_sibling(list_t *list, int index);
list_t *list_insert(list_t *list, void *data, size_t size);
list_t *list_append(list_t *list, void *data, size_t size);
list_t *list_remove(list_t *list);
list_t *list_push(list_t *list, void *data, size_t size);
list_t *list_unshift(list_t *list, void *data, size_t size);
list_t *list_pop(list_t *list);
list_t *list_shift(list_t *list);
list_t *list_copy(list_t *list);
list_t *list_sort(list_t *list, mem_cmpf_t cmpf, void *user);
list_t *list_add_sorted(list_t *list, void *data, size_t size,
                        mem_cmpf_t cmpf, void *user);

list_t *list_free(list_t *list);

#endif
