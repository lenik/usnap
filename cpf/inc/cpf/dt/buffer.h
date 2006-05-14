#ifndef _buffer_utim_c7Q9SKNdrPidPwJP_
#define _buffer_utim_c7Q9SKNdrPidPwJP_ "$Id: buffer.h,v 1.4 2006-05-14 13:10:12 lenik Exp $"

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
buffer_t *buffer_prepend(buffer_t *buffer, const void *data, size_t size);
void *buffer_free(buffer_t *buffer, int free_data);

void *buffer_data(buffer_t *buffer, size_t offset);
void *buffer_dataend(buffer_t *buffer, int offset);

#define buffer_appendv(buf, t, v) \
    (*(t *)buffer_dataend(buffer_append((buf), 0, sizeof(t)), \
                          -sizeof(t)) \
        = (t)(v))

#define buffer_prependv(buf, t, v) \
    (*(t *)(buffer_prepend((buf), 0, sizeof(t))->data) \
        = (t)(v))

#endif
