
#include "stdafx.h"

#include "object_descriptor.h"


bool _dump_binary(__int8 *p, size_t size, BYTESTREAMPROC bsp) {
	while (size--) if (!bsp(*p++)) return false;
	return true;
}

bool _dump_word(__int16 w, BYTESTREAMPROC bsp) {
	return _dump_binary((__int8 *)&w, 2, bsp);
}

bool _dump_dword(__int32 dw, BYTESTREAMPROC bsp) {
	return _dump_binary((__int8 *)&dw, 4, bsp);
}

template<typename _Ty>
bool _dump_basic(_Ty d, BYTESTREAMPROC bsp) {
	return _dump_binary((__int8 *)&d, sizeof(_Ty), bsp);
}

__int8 *_restore_binary(__int8 *p, size_t size, BYTESTREAMRESTOREPROC bsrp) {
	__int8 *r = p;
	while (size--) if (p) *p++ = bsrp(); else bsrp();
	return r;
}

__int16 _restore_word(BYTESTREAMRESTOREPROC bsrp) {
	__int16 r = 0;
	_restore_binary((__int8 *)&r, 2, bsrp);
	return r;
}

__int32 _restore_dword(BYTESTREAMRESTOREPROC bsrp) {
	__int32 r = 0;
	_restore_binary((__int8 *)&r, 4, bsrp);
	return r;
}

template<typename _Ty>
_Ty _restore_basic(BYTESTREAMRESTOREPROC bsrp) {
	static _Ty r;
	_restore_binary((__int8 *)&r, sizeof(_Ty), bsrp);
	return r;
}


size_t object_size(__int8 *instance, int *object_descriptor) {
	size_t	total	= 0;
	size_t	embed	= 0;

	if (instance == NULL) return 0;
	if (object_descriptor != NULL) return 0;

	while (*object_descriptor != FE_EOO) {
		switch (object_descriptor[0]) {
		case FE_BASIC:
			total += object_descriptor[1];
			instance += object_descriptor[1];
			object_descriptor += 2;
			break;
		case FE_ASZ:
			while (*instance++) total++;
			object_descriptor++;
			break;
		case FE_WSZ:
			while (*(__int16 *)instance) {
				total += 2;
				instance += 2;
			}
			object_descriptor++;
			break;
		case FE_TRACE:
			if ((__int8 *)*(int *)instance != NULL) {
				total += object_size((__int8 *)*(int *)instance, (int *)(object_descriptor[1]));
				instance += sizeof(int);
			}
			object_descriptor += 2;
			break;
		case FE_EMBED:
			embed		= object_size(instance, (int *)(object_descriptor[1]));
			total		+= embed;
			instance	+= embed;
			object_descriptor	+= 2;
			break;
		default:
			assert(false);
			object_descriptor++;
			break;
		}
	}
	return total;
}

void object_dump(__int8 *instance, int *object_descriptor, BYTESTREAMPROC bsp) {
	assert(bsp != NULL);

	size_t	embed	= 0;

	if (instance == NULL) return;
	if (object_descriptor == NULL) return;

	while (*object_descriptor != FE_EOO) {
		_dump_dword(object_descriptor[0], bsp);
		switch (object_descriptor[0]) {
		case FE_BASIC:
			instance += object_descriptor[1];
			_dump_dword(object_descriptor[1], bsp);
			_dump_binary(instance, object_descriptor[1], bsp);
			object_descriptor += 2;
			break;
		case FE_ASZ:
			while (*instance) {
				bsp(*instance);
				instance++;
			}
			object_descriptor++;
			break;
		case FE_WSZ:
			while (*(__int16 *)instance) {
				_dump_word(*(__int16 *)instance, bsp);
				instance += 2;
			}
			object_descriptor++;
			break;
		case FE_EMBED:
			_dump_dword(object_descriptor[1]/*no used*/, bsp);
			embed	= object_size(instance, object_descriptor);
			object_dump(instance, (int *)(object_descriptor[1]), bsp);
			instance	+= embed;
			object_descriptor	+= 2;
			break;
		case FE_TRACE:
			_dump_dword(object_descriptor[1]/*no used*/, bsp);
			_dump_dword((int)(__int8 *)*(int *)instance/*no used*/, bsp);
			if ((__int8 *)*(int *)instance != NULL) {
				object_dump((__int8 *)*(int *)instance, (int *)(object_descriptor[1]), bsp);
			}
			instance	+= sizeof(int);
			object_descriptor += 2;
			break;
		default:
			assert(false);
			object_descriptor++;
			break;
		}
	}
	_dump_dword(FE_EOO, bsp);
}

int object_restore_size(BYTESTREAMRESTOREPROC bsrp, bool nest) {
	assert(bsrp != NULL);

	int total	= 0;
	int field_type	= 0;
	int field_size	= 0;

	while ((field_type = _restore_dword(bsrp)) != FE_EOO) {
		switch (field_type) {
		case FE_BASIC:
			field_size	= _restore_dword(bsrp);
			_restore_binary(NULL, field_size, bsrp);
			total		+= field_size;
			break;
		case FE_ASZ:
			while (bsrp()) total++;
			total++;	// '\0' always occupy space
			break;
		case FE_WSZ:
			while (_restore_word(bsrp)) {
				total += 2;
			}
			total += 2;
			break;
		case FE_EMBED:
			_restore_dword(bsrp);	// ignored
			// following object_descriptor begins a new dump content.
			total	+= object_restore_size(bsrp);
			break;
		case FE_TRACE:
			_restore_dword(bsrp);	// ignored
			if (_restore_dword(bsrp)/* (__int8 *)*(int *)instance */ != NULL) {
				if (nest) {
					// following object_descriptor begins a new dump content.
					total	+= object_restore_size(bsrp);
				}
			}
			total	+= sizeof(int);	// see last _restore_dword(bsrp)
			break;
		default:
			assert(false);
			__assume(0);
		}
	}
	return total;
}

int object_restore_odsize(BYTESTREAMRESTOREPROC bsrp, bool nest) {
	assert(bsrp != NULL);

	int total	= 0;
	int field_type	= 0;
	int field_size	= 0;

	while ((field_type = _restore_dword(bsrp)) != FE_EOO) {
		total++;
		switch (field_type) {
		case FE_BASIC:
			field_size	= _restore_dword(bsrp);
			_restore_binary(NULL, field_size, bsrp);
			total++;
			break;
		case FE_ASZ:
			while (bsrp());
			break;
		case FE_WSZ:
			while (_restore_word(bsrp));
			break;
		case FE_EMBED:
			_restore_dword(bsrp);	// ignored
			// following object_descriptor begins a new dump content.
			total += object_restore_odsize(bsrp);
			break;
		case FE_TRACE:
			_restore_dword(bsrp);	// ignored
			total++;
			if (_restore_dword(bsrp)/* (__int8 *)*(int *)instance */ != NULL) {
				if (nest) {
					// following object_descriptor begins a new dump content.
					total	+= object_restore_odsize(bsrp);
				}
			}
			break;
		default:
			assert(false);
			__assume(0);
		}
	}
	return total;
}


// also can restore object_descriptor, if it isn't NULL.
void object_restore(__int8 *instance, int *object_descriptor, BYTESTREAMRESTOREPROC bsrp) {
	assert(instance != NULL);

	int field_type	= 0;
	int field_size	= 0;
	__int8 *newinstance		= NULL;
	int *new_object_descriptor	= NULL;

	while ((field_type = _restore_dword(bsrp)) != FE_EOO) {
		__int16 w	= 0;

		if (object_descriptor != NULL) {
			*object_descriptor++ = field_type;
		}
		switch (field_type) {
		case FE_BASIC:
			field_size	= _restore_dword(bsrp);
			if (object_descriptor != NULL) {
				*object_descriptor++ = field_size;
			}
			_restore_binary(instance, field_size, bsrp);
			instance	+= field_size;
			break;
		case FE_ASZ:
			while (*instance++ = bsrp());
			break;
		case FE_WSZ:
			while (w = _restore_word(bsrp)) {
				*(__int16 *)instance = w;
				instance += 2;
			}
			break;
		case FE_EMBED:
		case FE_TRACE:
			_restore_dword(bsrp);	// ignored
			newinstance = new __int8[object_restore_size(bsrp)];
			new_object_descriptor = NULL;
			if (object_descriptor != NULL) {
				new_object_descriptor = new int[object_restore_odsize(bsrp)];
			}
			object_restore(newinstance, new_object_descriptor, bsrp);
			*(int *)instance = (int)newinstance;
			if (object_descriptor++ != NULL) {
				*object_descriptor = (int)new_object_descriptor;
			}
			instance += 4;
			object_descriptor++;
			break;
		default:
			assert(false);
			__assume(0);
		}
	}
}


int object_restore_pure_size(int *object_descriptor, BYTESTREAMRESTOREPROC bsrp) {
	assert(bsrp != NULL);

	int total	= 0;

	if (object_descriptor == NULL) return 0;

	while (object_descriptor[0] != FE_EOO) {
		switch (object_descriptor[0]) {
		case FE_BASIC:
			_restore_binary(NULL, object_descriptor[1], bsrp);
			total		+= object_descriptor[1];
			break;
		case FE_ASZ:
			while (bsrp()) total++;
			total++;	// '\0' always occupy space
			break;
		case FE_WSZ:
			while (_restore_word(bsrp)) {
				total += 2;
			}
			total += 2;
			break;
		case FE_TRACE:
			total += object_restore_pure_size((int *)(object_descriptor[1]), bsrp);
			break;
		default:
			assert(false);
			__assume(0);
		}
	}
	return total;
}


// object_descriptor determines restore method.
void object_restore_pure(__int8 *instance, int *object_descriptor, BYTESTREAMRESTOREPROC bsrp) {
	assert(instance != NULL);

	if (object_descriptor == NULL) return;

	__int8 *newinstance;

	while (object_descriptor[0] != FE_EOO) {
		__int16 w = 0;

		switch (object_descriptor[0]) {
		case FE_BASIC:
			_restore_binary(instance, object_descriptor[1], bsrp);
			instance += object_descriptor[1];
			object_descriptor += 2;
			break;
		case FE_ASZ:
			while (*instance++ = bsrp());
			object_descriptor++;
			break;
		case FE_WSZ:
			while (w = _restore_word(bsrp)) {
				*(__int16 *)instance = w;
				instance += 2;
			}
			object_descriptor++;
			break;
		case FE_TRACE:
			newinstance = new __int8[object_restore_size(bsrp)];
			object_restore_pure(newinstance, (int *)(object_descriptor[1]), bsrp);
			*(int *)instance = (int)newinstance;
			instance += 4;
			object_descriptor += 2;
			break;
		default:
			assert(false);
			object_descriptor++;
			__assume(0);
		}
	}
}
