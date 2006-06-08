#ifndef __KERNEL_H
#define __KERNEL_H

#include "../../include/array.h"

ByteArray *encode(unsigned char *p, int cb) {
	ByteArray *pBA = new ByteArray();
	bool escape = false;
	int i;
	unsigned char c;
	bool b;

	for (i = 0; i < cb; i++) {
		c = p[i];
		switch (c) {
		case ' ':
		case '\t':
		case '\n':
		case '\r':
		case ';':
		case '"':
		case '\\':
			escape = true;
			break;
		}
	}

	if (! escape) {
		b = pBA->write(p, cb);
		_assert_(b);
		return pBA;
	}

	pBA->write('\"');

	while (cb-- > 0) {
		unsigned char c = *p++;
		switch (c) {
		case '\t':	c = 't'; break;
		case '\n':	c = 'n'; break;
		case '\r':	c = 'r'; break;
		case '"':	c = '"'; break;
		case '\\':	c = '\\'; break;
		default:
			pBA->write(c);
			continue;
		}
		pBA->write('\\');
		pBA->write(c);
	}

	pBA->write('\"');
	return pBA;
}

struct elm_t {
	void *data;
	size_t size;
	int type;

public:
	elm_t() {
		data = 0;
	}
	~elm_t() {
		if (data)
			free(data);
	}
};

typedef std::list<elm_t> elms_t;

struct stmt_t {
	elms_t elms;
};

struct buf_t {
	void *data;
	size_t alloc;
	size_t size;
	int growth;

public:
	buf_t() {
		data = 0;
		alloc = 0;
		size = 0;
		growth = 16;
	}

	~buf_t() {
		if (data)
			free(data);
	}

	void extend(size_t);
	void write(void *, size_t);
};

struct iobuf_t : public ArrayInput {
	int offset;
	size_t s_pos;
	int s_ok;
	stmt_t *stmt;

public:
	iobuf_t() {
		offset = 0;
		s_ok = 0;
		stmt = 0;
	}

	~iobuf_t() {
		if (stmt)
			delete stmt;
	}

	void opt();
	int is_stmt_ok();
	stmt_t *fetch_stmt();
};

#endif
