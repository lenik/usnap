
typedef struct _list_t list_t;

struct _list_t {
    list_t *next;
    list_t *prev;
    size_t size;
    u8_t data[1];
};

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
list_t *list_sort(list_t *list, int (*cmp)(void *, size_t, void *, size_t));
list_t *list_add_sorted(list_t *list, void *data, size_t size);
list_t *list_free(list_t *list);

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

static list_t *_list_new(void *data, size_t size) {
    list_t *list;
    if (size == 0) {
        list = (list_t *)malloc(16);
        if (! list) return 0;
        list->size = 4;
        list->data = data;
    } else {
        list = (list_t *)malloc(12 + size);
        if (! list) return 0;
        list->size = size;
        memcpy(list->data, data);
    }
}

list_t *list_insert(list_t *list, void *data, size_t size) {
    list_t *before = _list_new(data, size);
    if (! before) return list;
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

list_t *list_append(list_t *list, void *data, size_t size) {
    list_t *after = _list_new(data, size);
    if (! after) return list;
}

list_t *list_remove(list_t *list);
list_t *list_push(list_t *list, void *data, size_t size);
list_t *list_unshift(list_t *list, void *data, size_t size);
list_t *list_pop(list_t *list);
list_t *list_shift(list_t *list);
list_t *list_copy(list_t *list);
list_t *list_sort(list_t *list, int (*cmp)(void *, size_t, void *, size_t));
list_t *list_add_sorted(list_t *list, void *data, size_t size);
list_t *list_free(list_t *list);
