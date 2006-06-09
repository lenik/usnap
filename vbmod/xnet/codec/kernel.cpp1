
#include <stdlib.h>
#include <list>
#include "kernel.h"

int msb(unsigned n) {
	int bits = 0;
	while (n) {
		n >>= 1;
		bits++;
	}
	if (bits-- == 0)
		return 0;
	n = 1;
	while (bits--)
		n <<= 1;
	return n;
}

void buf_t::extend(size_t cb) {
	if (cb > alloc) {
		int delta = cb - alloc;
		if (delta > growth) {
			// 2 ^ int(log2(delta))
			int aligned = msb(delta);
			if (aligned != delta)
				aligned <<= 1;
			growth = aligned;
		}
		// extend at growth.
		size_t newalloc = alloc + growth;
		if (data) {
			data = realloc(data, newalloc);
		} else {
			data = malloc(newalloc);
		}
		alloc = newalloc;
	}
	size = cb;
}

void buf_t::write(void *pb, size_t cb) {
	if (cb == 0) return;
	size_t p = size;
	extend(size + cb);
	memcpy((char *)data + p, pb, cb);
}

void buf_t::opt() {
	int used = size - offset;
	if (alloc < 256)
		return;
	if (alloc < used * 2)
		return;
	void *cpy = malloc(used);
	memcpy(cpy, (char *)data + offset, used);
	free(data);
	data = cpy;
	offset = 0;
	alloc = size = used;
}

int buf_t::is_stmt_ok() {
	if (s_ok)
		return 1;

	/* step in */


	return s_ok;
}

stmt_t *buf_t::fetch_stmt() {
	if (s_ok) {
		stmt_t *ret = stmt;
		stmt = 0;
		s_ok = 0;
		return ret;
	}
	return 0;
}
