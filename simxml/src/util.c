#include <string.h>
#include <stdarg.h>
#include <glib.h>
#include "defs.h"
#include "util.h"

/* .section. string utilities */

char *
strhead(const char *full, char *buffer, unsigned int buffer_size) {
    ASSERT(buffer);
    ASSERT(buffer_size >= 5);   /* include term \0 */
    if (full) {
        g_strlcpy(buffer, full, buffer_size);
        if (strlen(full) >= buffer_size)
            strcpy(buffer + buffer_size - 4, "...");
    } else {
        g_strlcpy(buffer, "(null)", buffer_size);
    }
    return buffer;
}

/* .section. buffer */

/* using struct instead of void* is for type-safe. */
struct _buffer_t {
    void *dummy;
};

buffer_t *
buffer_new() {
    return (buffer_t *)g_byte_array_new();
}

buffer_t *
buffer_sized_new(int size) {
    return (buffer_t *)g_byte_array_sized_new(size);
}

void
buffer_append(buffer_t *buffer, void *data, int len) {
    ASSERT(buffer);
    ASSERT(data);
    ASSERT(len >= 0);
    g_byte_array_append((GByteArray *)buffer, data, len);
}

void
buffer_prepend(buffer_t *buffer, void *data, int len) {
    ASSERT(buffer);
    ASSERT(data);
    ASSERT(len >= 0);
    g_byte_array_prepend((GByteArray *)buffer, data, len);
}

int
buffer_size(buffer_t *buffer) {
    ASSERT(buffer);
    return ((GByteArray *)buffer)->len;
}

void
buffer_set_size(buffer_t *buffer, int size) {
    ASSERT(buffer);
    ASSERT(size >= 0);
    g_byte_array_set_size((GByteArray *)buffer, size);
}

void
buffer_free(buffer_t *buffer) {
    ASSERT(buffer);
    g_byte_array_free((GByteArray *)buffer, TRUE);
}

void *
buffer_detach(buffer_t *buffer) {
    ASSERT(buffer);
    return g_byte_array_free((GByteArray *)buffer, FALSE);
}

void *
buffer_ptr(buffer_t *buffer) {
    ASSERT(buffer);
    return ((GByteArray *)buffer)->data;
}

buffer_t *
buffer_copy(buffer_t *src) {
    buffer_t *copy;
    int size;

    ASSERT(src);
    size = buffer_size(src);
    copy = buffer_sized_new(size);
    buffer_append(copy, buffer_ptr(src), size);
    return copy;
}
