
#include "stdafx.h"

#include <pos/config.h>
using namespace pos;

#include "cpu_x86.h"


// --------------------------------------------------------------------------------
//	kernel test functions
// --------------------------------------------------------------------------------

// __stdcall
bool	__declspec(naked) __stdcall _mmx_support() {
	__asm {
		mov eax, 1
		cpuid
		test edx, 800000h
		setnz al
		and eax, 1
	}
}


// --------------------------------------------------------------------------------
//	implementation templates
// --------------------------------------------------------------------------------

#define __IMP_GET_REG(ty, regname)						\
	ty	__declspec(naked) __stdcall __##regname() {			\
		__asm mov eax, regname						\
		__asm ret							\
	}
#define __IMP_SET_REG(regname)							\
	void	__declspec(naked) __stdcall __##regname##_(u32_t) {		\
		__asm mov regname, [esp + 4]					\
		__asm ret 4							\
	}
#define __IMP_SET_REG_A(regname)						\
	void	__declspec(naked) __stdcall __##regname##_(u32_t) {		\
		__asm mov eax, [esp + 4]					\
		__asm mov regname, eax						\
		__asm ret 4							\
	}
#define __IMP_GET_REGPP(ty, regname)						\
	ty	__declspec(naked) __stdcall __##regname() {			\
		__asm push regname						\
		__asm pop eax							\
		__asm ret							\
	}
#define __IMP_SET_REGPP(regname)	/* by push/pop */			\
	void	__declspec(naked) __stdcall __##regname##_(u32_t) {		\
		__asm push eax			/* save */			\
		__asm mov eax, [esp + 8]	/* arg_0 */			\
		__asm push eax							\
		__asm pop regname		/* reg = eax	(movzx) */	\
		__asm pop eax			/* restore */			\
		__asm ret 4			/* __stdcall */			\
	}

#define __IMP_GET_STi(i)							\
	r64_t	__declspec(naked) __stdcall __st##i##() {			\
		__asm fld st(i)			/* st = st(i) */		\
		__asm ret							\
	}
#define __IMP_SET_STi(i)							\
	void	__declspec(naked) __stdcall __st##i##_(r64_t) {			\
		__asm fincstp			/* next fld will inc. it */	\
		__asm fld qword ptr [esp + 4]	/* st = *val */			\
		__asm fxch st(i)		/* st(i) ~ st */		\
		__asm ret 8			/* __stdcall */			\
	}

#define __IMP_GET_MMi_LO(i)							\
	u32_t	__declspec(naked) __stdcall __mm##i##_l() {			\
		__asm movd eax, mm##i		/* eax = mm(i).loword	*/	\
	}
#define __IMP_SET_MMi_LO(i)							\
	void	__declspec(naked) __stdcall __mm##i##_l_(u32_t) {		\
		__asm mov eax, [esp + 4]	/* eax = arg0 */		\
		__asm movd mm##i, eax		/* mm(i) = eax */		\
		__asm ret 4			/* __stdcall */			\
	}

/* u32_t/loword _stdcall mm(i)arg(u64_t *ret) */
#define __IMP_GET_MMi_arg(i)							\
	void	__declspec(naked) __stdcall __mm##i##_arg(u64_t *) {		\
		__asm mov eax, [esp + 4]	/* u64_t *pArg0 */		\
		__asm movq [eax], mm##i		/* *pArg0 = mm(i) */		\
		__asm ret 4							\
	}

/* _stdcall mm(i)_(u64_t) */
#define __IMP_SET_MMi(i)							\
	void	__declspec(naked) __stdcall __mm##i##_(u64_t) {			\
		__asm movq mm##i, [esp + 4]	/* mm(i) = *pArg0 */		\
		__asm ret 8			/* __stdcall */			\
	}



// --------------------------------------------------------------------------------
//	general registers
// --------------------------------------------------------------------------------
	u32_t	__declspec(naked) __stdcall __eax() {
		__asm ret
	}
	void	__declspec(naked) __stdcall __eax_(u32_t) {
		__asm mov eax, [esp + 4]
		__asm ret 4
	}
	u32_t	__declspec(naked) __stdcall __esp() {
		__asm mov eax, esp
		__asm add eax, 4			/* subtract the ret-address stuff */
		__asm ret
	}
	void	__declspec(naked) __stdcall __esp_(u32_t/*newESP*/) {
		__asm mov eax, [esp + 4]		/* eax = newESP */
		__asm mov ebx, [esp]			/* ebx = ret-addr */
		__asm mov esp, eax			/* esp = newESP */
		__asm jmp ebx				/* ret */
	}

	__IMP_GET_REG(u32_t, ebx)
	__IMP_GET_REG(u32_t, ecx)
	__IMP_GET_REG(u32_t, edx)
	__IMP_GET_REG(u32_t, esi)
	__IMP_GET_REG(u32_t, edi)
	__IMP_GET_REG(u32_t, ebp)
	__IMP_SET_REG(ebx)
	__IMP_SET_REG(ecx)
	__IMP_SET_REG(edx)
	__IMP_SET_REG(esi)
	__IMP_SET_REG(edi)
	__IMP_SET_REG(ebp)

// --------------------------------------------------------------------------------
//	segment registers
// --------------------------------------------------------------------------------
	__IMP_GET_REGPP(u32_t, cs)
	__IMP_GET_REGPP(u32_t, ds)
	__IMP_GET_REGPP(u32_t, es)
	__IMP_GET_REGPP(u32_t, ss)
	__IMP_GET_REGPP(u32_t, fs)
	__IMP_GET_REGPP(u32_t, gs)
	void __declspec(naked) __stdcall __cs_(u32_t) {
		__asm push eax
		__asm mov eax, [esp + 4]
		__asm push eax
		__asm int 3
		__asm nop
		__asm nop
		__asm nop
		__asm nop
		__asm pop eax
		__asm ret 4
	}
	__IMP_SET_REGPP(ds)
	__IMP_SET_REGPP(es)
	__IMP_SET_REGPP(ss)
	__IMP_SET_REGPP(fs)
	__IMP_SET_REGPP(gs)

	u32_t __declspec(naked) __stdcall __eip() {
		__asm mov eax, [esp]		/* ret-address */
		__asm ret
	}
	void __declspec(naked) __stdcall __eip_(u32_t) {
		__asm mov eax, [esp + 4]
		__asm jmp eax
	}

// --------------------------------------------------------------------------------
//	flags registers
// --------------------------------------------------------------------------------
	u32_t __declspec(naked) __stdcall __flags() {
		__asm pushf
		__asm mov eax, 0
		__asm pop ax
		__asm ret
	}
	void __declspec(naked) __stdcall __flags_(u32_t) {
		__asm push eax
		__asm mov eax, [esp + 4]
		__asm push ax
		__asm popf
		__asm pop eax
		__asm ret 4
	}
	u32_t __declspec(naked) __stdcall __eflags() {
		__asm pushfd
		__asm pop eax
		__asm ret
	}
	void __declspec(naked) __stdcall __eflags_(u32_t) {
		__asm push eax
		__asm mov eax, [esp + 4]
		__asm push eax
		__asm popfd
		__asm pop eax
		__asm ret 4
	}


// --------------------------------------------------------------------------------
//	FP-87 registers
// --------------------------------------------------------------------------------

	__IMP_GET_STi(0)
	__IMP_GET_STi(1)
	__IMP_GET_STi(2)
	__IMP_GET_STi(3)
	__IMP_GET_STi(4)
	__IMP_GET_STi(5)
	__IMP_GET_STi(6)
	__IMP_GET_STi(7)
	__IMP_SET_STi(0)
	__IMP_SET_STi(1)
	__IMP_SET_STi(2)
	__IMP_SET_STi(3)
	__IMP_SET_STi(4)
	__IMP_SET_STi(5)
	__IMP_SET_STi(6)
	__IMP_SET_STi(7)


// --------------------------------------------------------------------------------
//	386+ registers
// --------------------------------------------------------------------------------
	__IMP_GET_REG(u32_t, cr0)
	//__IMP_GET_REG(u32_t, cr1)
	__IMP_GET_REG(u32_t, cr2)
	__IMP_GET_REG(u32_t, cr3)
	//__IMP_GET_REG(u32_t, tr4)
	//__IMP_GET_REG(u32_t, tr5)
	__IMP_GET_REG(u32_t, tr6)
	__IMP_GET_REG(u32_t, tr7)
	__IMP_GET_REG(u32_t, dr0)
	__IMP_GET_REG(u32_t, dr1)
	__IMP_GET_REG(u32_t, dr2)
	__IMP_GET_REG(u32_t, dr3)
	//__IMP_GET_REG(u32_t, dr4)
	//__IMP_GET_REG(u32_t, dr5)
	__IMP_GET_REG(u32_t, dr6)
	__IMP_GET_REG(u32_t, dr7)

	__IMP_SET_REG_A(cr0)
	//__IMP_SET_REG_A(cr1)
	__IMP_SET_REG_A(cr2)
	__IMP_SET_REG_A(cr3)
	//__IMP_SET_REG_A(tr4)
	//__IMP_SET_REG_A(tr5)
	__IMP_SET_REG_A(tr6)
	__IMP_SET_REG_A(tr7)
	__IMP_SET_REG_A(dr0)
	__IMP_SET_REG_A(dr1)
	__IMP_SET_REG_A(dr2)
	__IMP_SET_REG_A(dr3)
	//__IMP_SET_REG_A(dr4)
	//__IMP_SET_REG_A(dr5)
	__IMP_SET_REG_A(dr6)
	__IMP_SET_REG_A(dr7)


// --------------------------------------------------------------------------------
//	mmx registers
// --------------------------------------------------------------------------------
#	pragma warning(disable: 4799)			// C4799: function has no EMMS instruction
	// get mm(i).loword
	__IMP_GET_MMi_LO(0)
	__IMP_GET_MMi_LO(1)
	__IMP_GET_MMi_LO(2)
	__IMP_GET_MMi_LO(3)
	__IMP_GET_MMi_LO(4)
	__IMP_GET_MMi_LO(5)
	__IMP_GET_MMi_LO(6)
	__IMP_GET_MMi_LO(7)

	// set mm(i).hiword
	__IMP_SET_MMi_LO(0)
	__IMP_SET_MMi_LO(1)
	__IMP_SET_MMi_LO(2)
	__IMP_SET_MMi_LO(3)
	__IMP_SET_MMi_LO(4)
	__IMP_SET_MMi_LO(5)
	__IMP_SET_MMi_LO(6)
	__IMP_SET_MMi_LO(7)

	// get mm(i, u64_t *)
	__IMP_GET_MMi_arg(0)
	__IMP_GET_MMi_arg(1)
	__IMP_GET_MMi_arg(2)
	__IMP_GET_MMi_arg(3)
	__IMP_GET_MMi_arg(4)
	__IMP_GET_MMi_arg(5)
	__IMP_GET_MMi_arg(6)
	__IMP_GET_MMi_arg(7)

	// set mm(i, u64_t)
	__IMP_SET_MMi(0)
	__IMP_SET_MMi(1)
	__IMP_SET_MMi(2)
	__IMP_SET_MMi(3)
	__IMP_SET_MMi(4)
	__IMP_SET_MMi(5)
	__IMP_SET_MMi(6)
	__IMP_SET_MMi(7)


// --------------------------------------------------------------------------------
//	utilities
// --------------------------------------------------------------------------------
	void	_stdcall _x86_save_regs(regs_x86_t *pr) {
		if (pr->a._basic) {
			pr->_eax_ = __eax();
			pr->_ebx_ = __ebx();
			pr->_ecx_ = __ecx();
			pr->_edx_ = __edx();
			pr->_esi_ = __esi();
			pr->_edi_ = __edi();
			pr->_esp_ = __esp();
			pr->_ebp_ = __ebp();
		}
		if (pr->a._flags) {
			pr->_eflags_ = __eflags();
		}
		if (pr->a._seg) {
			pr->_cs_ = __cs();
			pr->_ds_ = __ds();
			pr->_es_ = __es();
			pr->_ss_ = __ss();
			pr->_fs_ = __fs();
			pr->_gs_ = __gs();
		}
		if (pr->a._st) {
			pr->_st0_ = __st0();
			pr->_st1_ = __st1();
			pr->_st2_ = __st2();
			pr->_st3_ = __st3();
			pr->_st4_ = __st4();
			pr->_st5_ = __st5();
			pr->_st6_ = __st6();
			pr->_st7_ = __st7();
		}
		if (pr->a._cr) {
			pr->_cr0_ = __cr0();
			// pr->_cr1_ = __cr1();
			pr->_cr2_ = __cr2();
			pr->_cr3_ = __cr3();
		}
		if (pr->a._tr) {
			// pr->_tr4_ = __tr4();
			// pr->_tr5_ = __tr5();
			pr->_tr6_ = __tr6();
			pr->_tr7_ = __tr7();
		}
		if (pr->a._dr) {
			pr->_dr0_ = __dr0();
			pr->_dr1_ = __dr1();
			pr->_dr2_ = __dr2();
			pr->_dr3_ = __dr3();
			// pr->_dr4_ = __dr4();
			// pr->_dr5_ = __dr5();
			pr->_dr6_ = __dr6();
			pr->_dr7_ = __dr7();
		}
		if (pr->a._mmx) {
			__mm0_arg(&pr->_mm0_);
			__mm1_arg(&pr->_mm1_);
			__mm2_arg(&pr->_mm2_);
			__mm3_arg(&pr->_mm3_);
			__mm4_arg(&pr->_mm4_);
			__mm5_arg(&pr->_mm5_);
			__mm6_arg(&pr->_mm6_);
			__mm7_arg(&pr->_mm7_);
		}
	}

	void	__stdcall _x86_load_regs(regs_x86_t *pr) {
		if (pr->a._basic) {
			__eax_(pr->_eax_);
			__ebx_(pr->_ebx_);
			__ecx_(pr->_ecx_);
			__edx_(pr->_edx_);
			__esi_(pr->_esi_);
			__edi_(pr->_edi_);
			__esp_(pr->_esp_);
			__ebp_(pr->_ebp_);
		}
		if (pr->a._flags) {
			__eflags_(pr->_eflags_);
		}
		if (pr->a._seg) {
			__cs_(pr->_cs_);
			__ds_(pr->_ds_);
			__es_(pr->_es_);
			__ss_(pr->_ss_);
			__fs_(pr->_fs_);
			__gs_(pr->_gs_);
		}
		if (pr->a._st) {
			__st0_(pr->_st0_);
			__st1_(pr->_st1_);
			__st2_(pr->_st2_);
			__st3_(pr->_st3_);
			__st4_(pr->_st4_);
			__st5_(pr->_st5_);
			__st6_(pr->_st6_);
			__st7_(pr->_st7_);
		}
		if (pr->a._cr) {
			__cr0_(pr->_cr0_);
			// __cr1_(pr->_cr1_);
			__cr2_(pr->_cr2_);
			__cr3_(pr->_cr3_);
		}
		if (pr->a._tr) {
			// __tr4_(pr->_tr4_);
			// __tr5_(pr->_tr5_);
			__tr6_(pr->_tr6_);
			__tr7_(pr->_tr7_);
		}
		if (pr->a._dr) {
			__dr0_(pr->_dr0_);
			__dr1_(pr->_dr1_);
			__dr2_(pr->_dr2_);
			__dr3_(pr->_dr3_);
			// __dr4_(pr->_dr4_);
			// __dr5_(pr->_dr5_);
			__dr6_(pr->_dr6_);
			__dr7_(pr->_dr7_);
		}
		if (pr->a._mmx) {
			__mm0_(pr->_mm0_);
			__mm1_(pr->_mm1_);
			__mm2_(pr->_mm2_);
			__mm3_(pr->_mm3_);
			__mm4_(pr->_mm4_);
			__mm5_(pr->_mm5_);
			__mm6_(pr->_mm6_);
			__mm7_(pr->_mm7_);
		}
	}
