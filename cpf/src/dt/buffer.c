
#include "stdhdrs.h"
#include <cpf/assert.h>
#include <cpf/dt/buffer.h>

buffer_t *
buffer_new(void *data, size_t size, size_t alloc, size_t growth) {
    buffer_t *buffer;
    buffer = (buffer_t *)malloc(sizeof(buffer_t));

    if (alloc == 0)
        alloc = size;
    if (growth == 0) {
        growth = alloc >> 4;            /* default growth = 1/16 alloc */
        if (growth == 0)
            growth = sizeof(u32_t);
    }
    buffer->data = malloc(alloc);
    buffer->size = size;
    buffer->alloc = alloc;
    buffer->growth = growth;
    if (data)
        memcpy(buffer->data, data, size);
    return buffer;
}

buffer_t *
buffer_append(buffer_t *buffer, void *data, size_t size) {
    if (! buffer) {
        buffer = buffer_new(data, size, size, 0);
        return buffer;
    }
    if (buffer->alloc >= buffer->size + size) {
        memcpy(((u8_t *)buffer->data) + buffer->size, data, size);
        buffer->size += size;
        return buffer;
    }
    buffer->data = realloc(buffer->data, buffer->alloc + buffer->growth);
    memcpy(((u8_t *)buffer->data) + buffer->size, data, size);
    return buffer;
}

void *
buffer_dataend(buffer_t *buffer, int offset) {
    _assert_(buffer);
    _assert_(offset <= 0 && offset >= -(int)buffer->size);
    return ((u8_t *)buffer->data) + buffer->size + offset;
}

buffer_t *
buffer_prepend(buffer_t *buffer, void *data, size_t size) {
    return buffer;
}

void *
buffer_free(buffer_t *buffer, int free_data) {
    void *data;
    if (! buffer)
        return 0;
    if (free_data) {
        if (buffer->data)
            free(buffer->data);
        data = 0;
    } else
        data = buffer->data;
    free(buffer);
    return data;
}
