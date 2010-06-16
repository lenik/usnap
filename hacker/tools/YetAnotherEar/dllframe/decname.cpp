
#include "stdafx.h"
#include <pos/variant.h>
#include <pos/bdt.h>
using namespace pos;
#include "decname.h"


inline bool eqn(asz_t a, asz_t part) {
	return strncmp(a, part, strlen(part)) == 0;
};

c_types *get_index(c_types *begin, int index) {
	while (begin && index > 0) {
		begin = begin->l;
		index--;
	}
	return begin;
}

c_type UndecName(asz_t dec) {
	c_type t;
	__zero(t);

	a_t _buf[1024];
	asz_t p = _buf;

	if (*dec == '@') {
		asz_t _inmost = p;
		t.proto = c_type::proto_class;

		while (*++dec) {
			if (*dec == '@') {
				*p++ = ':';
				*p++ = ':';
			} else {
				if (*dec == '$') {	// func_name terminated, params start.
					*p = '\0';
					break;
				} else if (eqn(dec, "$bctr")) {
					int n = strlen(_inmost);
					while (n > 0) {
						*p++ = *_inmost++;
						n--;
					}
				} else if (eqn(dec, "$bdtr")) {
					*p++ = '~';
					int n = strlen(_inmost);
					while (n > 0) {
						*p++ = *_inmost++;
						n--;
					}
				} else {
					*p++ = *dec;
				}
			}
		}
		t._dispname = strdup(_buf);

		// func(void)
		if (*dec == 'v') return t;

		bool bFirst = true;
		c_types *s = new c_types;
		t._params = s;
		bool bListEnd = false;
		do {
			if (bFirst) {
				s->_l = NULL;
			} else {
				s->l = new c_types;
				s->l->_l = s;
				s = s->l;
			}
			c_type *_t = new c_type;
			s->data = _t;
			__zero(*_t);

			bool bItemEnd = false;
			_t->type = c_type::key_enum;
			while (*dec && !bItemEnd) {
				// "qqr" is often to seem at begin.
				switch (*dec++) {
				case 'r':
					_t->bByref = true;
					break;
				case 'p':
					_t->ptr_level++;
					break;
				case 'x':
					_t->type = c_type::key_structure;
					break;
				case 'i':
					_t->type = c_type::key_int;
					bItemEnd = true;
					break;
				case 'v':
					_t->type = c_type::key_void;
					bItemEnd = true;
					break;
				case 't':
					{
						int look;
						look = strtol(dec, &dec, 10) - 1;	// index starts from 0
						c_type *_ref = get_index(t._params, look)->data;
						*_t = *_ref;
						_t->_dispname = strdup(_t->_dispname);
					}
					bItemEnd = true;
					break;
				case '0': case '1': case '2': case '3': case '4':
				case '5': case '6': case '7': case '8': case '9':
					{
						int num;
						num = strtol(dec - 1, &dec, 10);
						strncpy(_t->_dispname, dec, num);
						dec += num;
					}
					bItemEnd = true;
					break;
				default:
					break;
				} // switch *dec
			} // while *dec && !bItemEnd
		} while (!bListEnd);
		s->l = NULL;
		return t;
	} // if first=='@'
	else {
		bool iscdecl = false;
		if (*dec == '_') {
			asz_t _rev;
			_rev = strrev(strdup(dec));
			if (*_rev >= '0' && *_rev <= '9') {
				strtol(_rev, &_rev, 10);
				if (*_rev == '@') {
					iscdecl = true;
				}
			}
			free(_rev);
		}

		if (iscdecl) {
			t.proto = c_type::proto_cdecl;
			dec++;
			while (*dec++ != '@') {
				*p++ = *dec;
			}

			// dec-> ...@|num
			int nret = strtol(dec, NULL, 10);
			c_types *s = new c_types;
			bool b1st = false;
			t._params = s;
			while (nret >= 4) {
				if (b1st) {
					s->_l = NULL;
				} else {
					s->l = new c_types;
					s->l->_l = s;
					s = s->l;
				}
				c_type *_t = new c_type;
				s->data = _t;
				__zero(*_t);
				_t->type = c_type::key_u32;
				nret -= 4;
			}
			if (nret >= 2) {
				if (b1st) {
					s->_l = NULL;
				} else {
					s->l = new c_types;
					s->l->_l = s;
					s = s->l;
				}
				c_type *_t = new c_type;
				s->data = _t;
				__zero(*_t);
				_t->type = c_type::key_u16;
				nret -= 2;
			}
			if (nret >= 1) {
				if (b1st) {
					s->_l = NULL;
				} else {
					s->l = new c_types;
					s->l->_l = s;
					s = s->l;
				}
				c_type *_t = new c_type;
				s->data = _t;
				__zero(*_t);
				_t->type = c_type::key_u8;
				nret -= 1;
			}
			return t;
		}

		t.proto = c_type::proto_stdcall;
		{
			t._dispname = strdup(dec);
			// eval_params(t, proc_addr)
		}
	}
	return t;
}
