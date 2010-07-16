
// [campo-freeware]
// [the free code conform to GPL]
//
// simple object | memory organization descriptor
// dansei, 1999.7.4
//

#pragma once

// FE_BAISC		width
// FE_ASC
// FE_WSC
// FE_TRACE		template *
// FE_EOO
enum FIELD_ENUM {
	FE_BASIC,			// basic [width]
	FE_ASZ,				// ansi sz-string
	FE_WSZ,				// unicode sz-string
	FE_TRACE,			// down trace usage pointer [template *]
	FE_EMBED,			// embed object
	FE_EOO				// end of object
};

static __asciz_string[]		= { FE_ASC, FE_EOO };
static __unicode_string[]	= { FE_WSC, FE_EOO };

typedef bool (_stdcall *BYTESTREAMPROC)(__int8);
typedef __int8 (_stdcall *BYTESTREAMRESTOREPROC)();

__int8 _stdcall _bytestream_restore_memory(__int8 *pbase, bool reset = false);

bool _dump_binary(__int8 *p, size_t size, BYTESTREAMPROC bsp);
bool _dump_word(__int16 w, BYTESTREAMPROC bsp);
bool _dump_dword(__int32 dw, BYTESTREAMPROC bsp);
template<typename _Ty>
bool _dump_basic(_Ty d, BYTESTREAMPROC bsp);

__int8 *_restore_binary(__int8 *p, size_t size, BYTESTREAMRESTOREPROC bsrp);
__int16 _restore_word(BYTESTREAMRESTOREPROC bsrp);
__int32 _restore_dword(BYTESTREAMRESTOREPROC bsrp);
template<typename _Ty>
_Ty _restore_basic(BYTESTREAMRESTOREPROC bsrp);


size_t	object_size(__int8 *instance, int *object_descriptor);

void	object_dump(__int8 *instance, int *object_descriptor, BYTESTREAMPROC bsp);
int	object_restore_size(BYTESTREAMRESTOREPROC bsrp, bool nest);
int	object_restore_odsize(BYTESTREAMRESTOREPROC bsrp, bool nest);
// also can restore object_descriptor, if it isn't NULL.
void	object_restore(__int8 *instance, int *object_descriptor, BYTESTREAMRESTOREPROC bsrp);

void	object_dump_pure(__int8 *instance, int *object_descriptor, BYTESTREAMPROC bsp);
int	object_restore_pure_size(int *object_descriptor, BYTESTREAMRESTOREPROC bsrp, bool nest);
// object_descriptor determines restore method.
void	object_restore_pure(__int8 *instance, int *object_descriptor, BYTESTREAMRESTOREPROC bsrp);

