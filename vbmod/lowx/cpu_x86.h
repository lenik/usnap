

#pragma once

#include <pos/config.h>
using namespace pos;

#pragma pack(push, 4)

struct regs_x86_t {
	/*
	union u64_t {
		pos::u64_t	_64;
		struct {
			u32_t	_32_l;
			u32_t	_32_h;
		};	// little-endian.
	};
	*/

	union {
		u32_t	mask;
		struct {
			int _basic: 1;		// eax ebx ecx edx esi edi esp ebp
			int _flags: 1;		// eflags
			int _seg: 1;		// cs ds es ss fs gs
			int _cr: 1;		// cr0 (cr1) cr2 cr3
			int _tr: 1;		// (tr4 tr5) tr6 tr7
			int _dr: 1;		// dr0 dr1 dr2 dr3 dr6 dr7
			int _st: 1;		// st0 .. st7
			int _mmx: 1;		// mmx0 .. mmx7
		};
	} a;

	u32_t	_eax_;
	u32_t	_ebx_;
	u32_t	_ecx_;
	u32_t	_edx_;
	u32_t	_esi_;
	u32_t	_edi_;
	u32_t	_esp_;
	u32_t	_ebp_;
	u32_t	_eflags_;
	u32_t	_cs_;
	u32_t	_ds_;
	u32_t	_es_;
	u32_t	_ss_;
	u32_t	_fs_;
	u32_t	_gs_;
	u32_t	_cr0_;					// Priviledge
	u32_t	_cr1_; 					// N/A
	u32_t	_cr2_; 					// Priviledge
	u32_t	_cr3_; 					// Priviledge
	u32_t	_tr4_; 					// N/A
	u32_t	_tr5_; 					// N/A
	u32_t	_tr6_; 					// No name
	u32_t	_tr7_; 					// Illegal
	u32_t	_dr0_; 					// Priviledge
	u32_t	_dr1_; 					// Priviledge
	u32_t	_dr2_; 					// Priviledge
	u32_t	_dr3_; 					// Priviledge
	u32_t	_dr4_; 					// Priviledge
	u32_t	_dr5_; 					// Priviledge
	u32_t	_dr6_; 					// Priviledge
	u32_t	_dr7_; 					// Priviledge
	r64_t	_st0_;
	r64_t	_st1_;
	r64_t	_st2_;
	r64_t	_st3_;
	r64_t	_st4_;
	r64_t	_st5_;
	r64_t	_st6_;
	r64_t	_st7_;

	u64_t	_mm0_;
	u64_t	_mm1_;
	u64_t	_mm2_;
	u64_t	_mm3_;
	u64_t	_mm4_;
	u64_t	_mm5_;
	u64_t	_mm6_;
	u64_t	_mm7_;
};

#pragma pack(pop)


bool	__stdcall _mmx_support();

void	__stdcall _x86_save_regs(regs_x86_t *);
void	__stdcall _x86_load_regs(regs_x86_t *);


u32_t	__stdcall __eax(), __stdcall __ebx(), __stdcall __ecx(), __stdcall __edx(),
	__stdcall __esi(), __stdcall __edi(), __stdcall __esp(), __stdcall __ebp();
u32_t	__stdcall __cs(), __stdcall __ds(), __stdcall __es(), __stdcall __ss(),
	__stdcall __fs(), __stdcall __gs();
u32_t	__stdcall __flags(), __stdcall __eflags();
u32_t	__stdcall __eip();

void	__stdcall __eax_(u32_t), __stdcall __ebx_(u32_t), __stdcall __ecx_(u32_t), __stdcall __edx_(u32_t),
	__stdcall __esi_(u32_t), __stdcall __edi_(u32_t), __stdcall __esp_(u32_t), __stdcall __ebp_(u32_t);
void	__stdcall __cs_(u32_t), __stdcall __ds_(u32_t), __stdcall __es_(u32_t), __stdcall __ss_(u32_t),
	__stdcall __fs_(u32_t), __stdcall __gs_(u32_t);
void	__stdcall __flags_(u32_t), __stdcall __eflags_(u32_t);
void	__stdcall __eip_(u32_t);


u32_t	__stdcall __cr0(), __stdcall __cr1(), __stdcall __cr2(), __stdcall __cr3(),
	__stdcall __tr4(), __stdcall __tr5(), __stdcall __tr6(), __stdcall __tr7();
u32_t	__stdcall __dr0(), __stdcall __dr1(), __stdcall __dr2(), __stdcall __dr3(),
	__stdcall __dr4(), __stdcall __dr5(), __stdcall __dr6(), __stdcall __dr7();
r64_t	__stdcall __st0(), __stdcall __st1(), __stdcall __st2(), __stdcall __st3(),
	__stdcall __st4(), __stdcall __st5(), __stdcall __st6(), __stdcall __st7();
u32_t	__stdcall __mm0_l(), __stdcall __mm1_l(), __stdcall __mm2_l(), __stdcall __mm3_l(),
	__stdcall __mm4_l(), __stdcall __mm5_l(), __stdcall __mm6_l(), __stdcall __mm7_l();
void	__stdcall __mm0_arg(u64_t *), __stdcall __mm1_arg(u64_t *), __stdcall __mm2_arg(u64_t *), __stdcall __mm3_arg(u64_t *),
	__stdcall __mm4_arg(u64_t *), __stdcall __mm5_arg(u64_t *), __stdcall __mm6_arg(u64_t *), __stdcall __mm7_arg(u64_t *);

void	__stdcall __cr0_(u32_t), __stdcall __cr1_(u32_t), __stdcall __cr2_(u32_t), __stdcall __cr3_(u32_t),
	__stdcall __tr4_(u32_t), __stdcall __tr5_(u32_t), __stdcall __tr6_(u32_t), __stdcall __tr7_(u32_t);
void	__stdcall __dr0_(u32_t), __stdcall __dr1_(u32_t), __stdcall __dr2_(u32_t), __stdcall __dr3_(u32_t),
	__stdcall __dr4_(u32_t), __stdcall __dr5_(u32_t), __stdcall __dr6_(u32_t), __stdcall __dr7_(u32_t);
void	__stdcall __st0_(r64_t), __stdcall __st1_(r64_t), __stdcall __st2_(r64_t), __stdcall __st3_(r64_t),
	__stdcall __st4_(r64_t), __stdcall __st5_(r64_t), __stdcall __st6_(r64_t), __stdcall __st7_(r64_t);
void	__stdcall __mm0_l_(u32_t), __stdcall __mm1_l_(u32_t), __stdcall __mm2_l_(u32_t), __stdcall __mm3_l_(u32_t),
	__stdcall __mm4_l_(u32_t), __stdcall __mm5_l_(u32_t), __stdcall __mm6_l_(u32_t), __stdcall __mm7_l_(u32_t);
void	__stdcall __mm0_(u64_t), __stdcall __mm1_(u64_t), __stdcall __mm2_(u64_t), __stdcall __mm3_(u64_t),
	__stdcall __mm4_(u64_t), __stdcall __mm5_(u64_t), __stdcall __mm6_(u64_t), __stdcall __mm7_(u64_t);
