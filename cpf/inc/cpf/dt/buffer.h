#ifndef _buffer_utim_c7Q9SKNdrPidPwJP_
#define _buffer_utim_c7Q9SKNdrPidPwJP_ "$Id: buffer.h,v 1.3 2006-05-14 04:58:29 dansei Exp $"

#include "raw.h"

typedef struct _buffer_t buffer_t;

struct _buffer_t {
    u8_t *data;
    size_t size;
    size_t alloc;
    size_t growth;
};

buffer_t *buffer_new(void *data, size_t size, size_t alloc, size_t growth);

buffer_t *buffer_append(buffer_t *buffer, const void *data, size_t size);

#define buffer_append_val(buf, t, v) \
    (*(t *)buffer_dataend(buffer_append((buf), 0, sizeof(t)), \
                          -sizeof(t)) \
        = (t)(v))

void *buffer_dataend(buffer_t *buffer, int offset);

buffer_t *buffer_prepend(buffer_t *buffer, const void *data, size_t size);

#define buffer_prepend_val(buf, t, v) \
    (*(t *)(buffer_prepend((buf), 0, sizeof(t))->data) \
        = (t)(v))

void *buffer_free(buffer_t *buffer, int free_data);

#endif
