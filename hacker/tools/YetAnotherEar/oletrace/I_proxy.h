
#pragma once


#define __entry_(n)		\
	void *_entry##n;

// n0~n9
#define __entry_x(n)		\
	__entry_(n##0)		\
	__entry_(n##1)		\
	__entry_(n##2)		\
	__entry_(n##3)		\
	__entry_(n##4)		\
	__entry_(n##5)		\
	__entry_(n##6)		\
	__entry_(n##7)		\
	__entry_(n##8)		\
	__entry_(n##9)

// n00~n99
#define __entry_xx(n)		\
	__entry_x(n##0)		\
	__entry_x(n##1)		\
	__entry_x(n##2)		\
	__entry_x(n##3)		\
	__entry_x(n##4)		\
	__entry_x(n##5)		\
	__entry_x(n##6)		\
	__entry_x(n##7)		\
	__entry_x(n##8)		\
	__entry_x(n##9)

// n000~n999
#define __entry_xxx(n)		\
	__entry_xx(n##0)	\
	__entry_xx(n##1)	\
	__entry_xx(n##2)	\
	__entry_xx(n##3)	\
	__entry_xx(n##4)	\
	__entry_xx(n##5)	\
	__entry_xx(n##6)	\
	__entry_xx(n##7)	\
	__entry_xx(n##8)	\
	__entry_xx(n##9)

struct _vtbls {
	// 00~49, a coclass must export no more than 50 interfaces.
	__entry_x(0)
	__entry_x(1)
	__entry_x(2)
	__entry_x(3)
	__entry_x(4)
	void *_raw_vtbls;
};

struct _vtbl {
	// 0000~1999, an interface must have less than 2000 method/properties.
	__entry_xxx(0)
	__entry_xxx(1)
	void *_raw_vtbl;
};



	// off: DWORD offset from the beginning of vtbl.
		// stack:
		//	esp -> (this word)
		//	this
		//	params
		//	ret_addr
		//	-------------------
		//	eax,edx,... ret_val
#define _IMP_VTBL_JMP_STDCALL_(off)					\
	void __declspec(naked) _vtbl_stdcall_jmp_raw_##off() {		\
		__asm {							\
		__asm	mov eax, [esp + 4]				\
		__asm	push 0x##off					\
		__asm	push eax					\
		__asm	call _vtbl_made_call				\
									\
		__asm	mov eax, [esp + 4]				\
			/* eax = _raw_vtbl */				\
		__asm	mov eax, [eax + 2000 * 4]			\
		__asm	add eax, 0x##off * 4				\
		__asm	jmp dword ptr [eax]				\
		}							\
	}

#define _DECL_VTBL_JMP_STDCALL_(off)					\
	void /*__declspec(naked)*/ _vtbl_stdcall_jmp_raw_##off();

// n0~n9
#define _IMP_VTBL_JMP_STDCALL_x(n)	\
	_IMP_VTBL_JMP_STDCALL_(n##0)	\
	_IMP_VTBL_JMP_STDCALL_(n##1)	\
	_IMP_VTBL_JMP_STDCALL_(n##2)	\
	_IMP_VTBL_JMP_STDCALL_(n##3)	\
	_IMP_VTBL_JMP_STDCALL_(n##4)	\
	_IMP_VTBL_JMP_STDCALL_(n##5)	\
	_IMP_VTBL_JMP_STDCALL_(n##6)	\
	_IMP_VTBL_JMP_STDCALL_(n##7)	\
	_IMP_VTBL_JMP_STDCALL_(n##8)	\
	_IMP_VTBL_JMP_STDCALL_(n##9)

// n00~n99
#define _IMP_VTBL_JMP_STDCALL_xx(n)	\
	_IMP_VTBL_JMP_STDCALL_x(n##0)	\
	_IMP_VTBL_JMP_STDCALL_x(n##1)	\
	_IMP_VTBL_JMP_STDCALL_x(n##2)	\
	_IMP_VTBL_JMP_STDCALL_x(n##3)	\
	_IMP_VTBL_JMP_STDCALL_x(n##4)	\
	_IMP_VTBL_JMP_STDCALL_x(n##5)	\
	_IMP_VTBL_JMP_STDCALL_x(n##6)	\
	_IMP_VTBL_JMP_STDCALL_x(n##7)	\
	_IMP_VTBL_JMP_STDCALL_x(n##8)	\
	_IMP_VTBL_JMP_STDCALL_x(n##9)

// n000~n999
#define _IMP_VTBL_JMP_STDCALL_xxx(n)	\
	_IMP_VTBL_JMP_STDCALL_xx(n##0)	\
	_IMP_VTBL_JMP_STDCALL_xx(n##1)	\
	_IMP_VTBL_JMP_STDCALL_xx(n##2)	\
	_IMP_VTBL_JMP_STDCALL_xx(n##3)	\
	_IMP_VTBL_JMP_STDCALL_xx(n##4)	\
	_IMP_VTBL_JMP_STDCALL_xx(n##5)	\
	_IMP_VTBL_JMP_STDCALL_xx(n##6)	\
	_IMP_VTBL_JMP_STDCALL_xx(n##7)	\
	_IMP_VTBL_JMP_STDCALL_xx(n##8)	\
	_IMP_VTBL_JMP_STDCALL_xx(n##9)


// n0~n9
#define _DECL_VTBL_JMP_STDCALL_x(n)	\
	_DECL_VTBL_JMP_STDCALL_(n##0)	\
	_DECL_VTBL_JMP_STDCALL_(n##1)	\
	_DECL_VTBL_JMP_STDCALL_(n##2)	\
	_DECL_VTBL_JMP_STDCALL_(n##3)	\
	_DECL_VTBL_JMP_STDCALL_(n##4)	\
	_DECL_VTBL_JMP_STDCALL_(n##5)	\
	_DECL_VTBL_JMP_STDCALL_(n##6)	\
	_DECL_VTBL_JMP_STDCALL_(n##7)	\
	_DECL_VTBL_JMP_STDCALL_(n##8)	\
	_DECL_VTBL_JMP_STDCALL_(n##9)

// n00~n99
#define _DECL_VTBL_JMP_STDCALL_xx(n)	\
	_DECL_VTBL_JMP_STDCALL_x(n##0)	\
	_DECL_VTBL_JMP_STDCALL_x(n##1)	\
	_DECL_VTBL_JMP_STDCALL_x(n##2)	\
	_DECL_VTBL_JMP_STDCALL_x(n##3)	\
	_DECL_VTBL_JMP_STDCALL_x(n##4)	\
	_DECL_VTBL_JMP_STDCALL_x(n##5)	\
	_DECL_VTBL_JMP_STDCALL_x(n##6)	\
	_DECL_VTBL_JMP_STDCALL_x(n##7)	\
	_DECL_VTBL_JMP_STDCALL_x(n##8)	\
	_DECL_VTBL_JMP_STDCALL_x(n##9)

// n000~n999
#define _DECL_VTBL_JMP_STDCALL_xxx(n)	\
	_DECL_VTBL_JMP_STDCALL_xx(n##0)	\
	_DECL_VTBL_JMP_STDCALL_xx(n##1)	\
	_DECL_VTBL_JMP_STDCALL_xx(n##2)	\
	_DECL_VTBL_JMP_STDCALL_xx(n##3)	\
	_DECL_VTBL_JMP_STDCALL_xx(n##4)	\
	_DECL_VTBL_JMP_STDCALL_xx(n##5)	\
	_DECL_VTBL_JMP_STDCALL_xx(n##6)	\
	_DECL_VTBL_JMP_STDCALL_xx(n##7)	\
	_DECL_VTBL_JMP_STDCALL_xx(n##8)	\
	_DECL_VTBL_JMP_STDCALL_xx(n##9)

// _vtbl_stdcall_jmp_raw_0000~_vtbl_stdcall_jmp_raw_1999
_DECL_VTBL_JMP_STDCALL_xxx(0)
_DECL_VTBL_JMP_STDCALL_xxx(1)
