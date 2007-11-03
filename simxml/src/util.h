#ifndef _util_umac_n_xWDeY3K21j6cTZ_
#define _util_umac_n_xWDeY3K21j6cTZ_ "$Id: util.h,v 1.1 2007-11-03 12:23:06 lenik Exp $"

/* .section. string utilities */

char *
strhead(const char *full, char *buffer, unsigned int buffer_size);

/* .section. buffer */

typedef struct _buffer_t buffer_t;

buffer_t *
buffer_new();

buffer_t *
buffer_sized_new(int size);

void
buffer_append(buffer_t *buffer, void *data, int len);

void
buffer_prepend(buffer_t *buffer, void *data, int len);

int
buffer_size(buffer_t *buffer);

void
buffer_set_size(buffer_t *buffer, int size);

void
buffer_free(buffer_t *buffer);

void *
buffer_detach(buffer_t *buffer);

void *
buffer_ptr(buffer_t *buffer);

buffer_t *
buffer_copy(buffer_t *src);

#endif
