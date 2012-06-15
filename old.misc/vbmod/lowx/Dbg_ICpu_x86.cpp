
#include "stdafx.h"
#include "LowX.h"
#include "Debugger.h"

#include "cpu_x86.h"

#include <pos/config.h>
using namespace pos;



STDMETHODIMP CDebugger::SaveRegisters(long pBuf)
{
	regs_x86_t *pr = (regs_x86_t *)pBuf;
	if (!pr) return E_POINTER;

	_x86_save_regs(pr);

	return S_OK;
}

STDMETHODIMP CDebugger::LoadRegisters(long pBuf)
{
	regs_x86_t *pr = (regs_x86_t *)pBuf;
	if (!pr) return E_POINTER;

	_x86_load_regs(pr);

	return S_OK;
}


STDMETHODIMP CDebugger::get_EAX(long *pVal)
{
	*pVal = (long)__eax();

	return S_OK;
}

STDMETHODIMP CDebugger::put_EAX(long newVal)
{
	__eax_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_EBX(long *pVal)
{
	*pVal = (long)__ebx();

	return S_OK;
}

STDMETHODIMP CDebugger::put_EBX(long newVal)
{
	__ebx_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_ECX(long *pVal)
{
	*pVal = (long)__ecx();

	return S_OK;
}

STDMETHODIMP CDebugger::put_ECX(long newVal)
{
	__ecx_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_EDX(long *pVal)
{
	*pVal = (long)__edx();

	return S_OK;
}

STDMETHODIMP CDebugger::put_EDX(long newVal)
{
	__edx_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_ESI(long *pVal)
{
	*pVal = (long)__esi();

	return S_OK;
}

STDMETHODIMP CDebugger::put_ESI(long newVal)
{
	__esi_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_EDI(long *pVal)
{
	*pVal = (long)__edi();

	return S_OK;
}

STDMETHODIMP CDebugger::put_EDI(long newVal)
{
	__edi_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_ESP(long *pVal)
{
	*pVal = (long)__esp();

	return S_OK;
}

STDMETHODIMP CDebugger::put_ESP(long newVal)
{
	__esp_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_EBP(long *pVal)
{
	*pVal = (long)__ebp();

	return S_OK;
}

STDMETHODIMP CDebugger::put_EBP(long newVal)
{
	__ebp_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_EF(long *pVal)
{
	*pVal = (long)__eflags();

	return S_OK;
}

STDMETHODIMP CDebugger::put_EF(long newVal)
{
	__eflags_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_CR0(long *pVal)
{
	*pVal = (long)__cr0();

	return S_OK;
}

STDMETHODIMP CDebugger::put_CR0(long newVal)
{
	__cr0_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_CR1(long *pVal)
{
	return E_NOTIMPL;
//	*pVal = (long)__cr1();

	return S_OK;
}

STDMETHODIMP CDebugger::put_CR1(long newVal)
{
	return E_NOTIMPL;
//	__cr1_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_CR2(long *pVal)
{
	*pVal = (long)__cr2();

	return S_OK;
}

STDMETHODIMP CDebugger::put_CR2(long newVal)
{
	__cr2_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_CR3(long *pVal)
{
	*pVal = (long)__cr3();

	return S_OK;
}

STDMETHODIMP CDebugger::put_CR3(long newVal)
{
	__cr3_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_TR4(long *pVal)
{
	return E_NOTIMPL;
//	*pVal = (long)__tr4();

	return S_OK;
}

STDMETHODIMP CDebugger::put_TR4(long newVal)
{
	return E_NOTIMPL;
//	__tr4_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_TR5(long *pVal)
{
	return E_NOTIMPL;
//	*pVal = (long)__tr5();

	return S_OK;
}

STDMETHODIMP CDebugger::put_TR5(long newVal)
{
	return E_NOTIMPL;
//	__tr5_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_TR6(long *pVal)
{
	*pVal = (long)__tr6();

	return S_OK;
}

STDMETHODIMP CDebugger::put_TR6(long newVal)
{
	__tr6_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_TR7(long *pVal)
{
	*pVal = (long)__tr7();

	return S_OK;
}

STDMETHODIMP CDebugger::put_TR7(long newVal)
{
	__tr7_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_DR0(long *pVal)
{
	*pVal = (long)__dr0();

	return S_OK;
}

STDMETHODIMP CDebugger::put_DR0(long newVal)
{
	__dr0_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_DR1(long *pVal)
{
	*pVal = (long)__dr1();

	return S_OK;
}

STDMETHODIMP CDebugger::put_DR1(long newVal)
{
	__dr1_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_DR2(long *pVal)
{
	*pVal = (long)__dr2();

	return S_OK;
}

STDMETHODIMP CDebugger::put_DR2(long newVal)
{
	__dr2_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_DR3(long *pVal)
{
	*pVal = (long)__dr3();

	return S_OK;
}

STDMETHODIMP CDebugger::put_DR3(long newVal)
{
	__dr3_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_DR4(long *pVal)
{
	return E_NOTIMPL;
//	*pVal = (long)__dr4();

	return S_OK;
}

STDMETHODIMP CDebugger::put_DR4(long newVal)
{
	return E_NOTIMPL;
//	__dr4_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_DR5(long *pVal)
{
	return E_NOTIMPL;
//	*pVal = (long)__dr5();

	return S_OK;
}

STDMETHODIMP CDebugger::put_DR5(long newVal)
{
	return E_NOTIMPL;
//	__dr5_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_DR6(long *pVal)
{
	*pVal = (long)__dr6();

	return S_OK;
}

STDMETHODIMP CDebugger::put_DR6(long newVal)
{
	__dr6_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_DR7(long *pVal)
{
	*pVal = (long)__dr7();

	return S_OK;
}

STDMETHODIMP CDebugger::put_DR7(long newVal)
{
	__dr7_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_CS(long *pVal)
{
	*pVal = (long)__cs();

	return S_OK;
}

STDMETHODIMP CDebugger::put_CS(long newVal)
{
	__cs_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_DS(long *pVal)
{
	*pVal = (long)__ds();

	return S_OK;
}

STDMETHODIMP CDebugger::put_DS(long newVal)
{
	__ds_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_ES(long *pVal)
{
	*pVal = (long)__es();

	return S_OK;
}

STDMETHODIMP CDebugger::put_ES(long newVal)
{
	__es_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_SS(long *pVal)
{
	*pVal = (long)__ss();

	return S_OK;
}

STDMETHODIMP CDebugger::put_SS(long newVal)
{
	__ss_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_FS(long *pVal)
{
	*pVal = (long)__fs();

	return S_OK;
}

STDMETHODIMP CDebugger::put_FS(long newVal)
{
	__fs_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_GS(long *pVal)
{
	*pVal = (long)__gs();

	return S_OK;
}

STDMETHODIMP CDebugger::put_GS(long newVal)
{
	__gs_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_EIP(long *pVal)
{
	*pVal = (long)__eip();

	return S_OK;
}

STDMETHODIMP CDebugger::put_EIP(long newVal)
{
	__eip_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_ST0(double *pVal)
{
	*pVal = (double)__st0();

	return S_OK;
}

STDMETHODIMP CDebugger::put_ST0(double newVal)
{
	__st0_((double)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_ST1(double *pVal)
{
	*pVal = __st1();

	return S_OK;
}

STDMETHODIMP CDebugger::put_ST1(double newVal)
{
	__st1_((double)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_ST2(double *pVal)
{
	*pVal = __st2();

	return S_OK;
}

STDMETHODIMP CDebugger::put_ST2(double newVal)
{
	__st2_((double)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_ST3(double *pVal)
{
	*pVal = __st3();

	return S_OK;
}

STDMETHODIMP CDebugger::put_ST3(double newVal)
{
	__st3_((double)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_ST4(double *pVal)
{
	*pVal = __st4();

	return S_OK;
}

STDMETHODIMP CDebugger::put_ST4(double newVal)
{
	__st4_((double)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_ST5(double *pVal)
{
	*pVal = __st5();

	return S_OK;
}

STDMETHODIMP CDebugger::put_ST5(double newVal)
{
	__st5_((double)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_ST6(double *pVal)
{
	*pVal = __st6();

	return S_OK;
}

STDMETHODIMP CDebugger::put_ST6(double newVal)
{
	__st6_((double)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_ST7(double *pVal)
{
	*pVal = __st7();

	return S_OK;
}

STDMETHODIMP CDebugger::put_ST7(double newVal)
{
	__st7_((double)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_MM0_H(long *pVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	u64_t u64;
	__mm0_arg(&u64);
	*pVal = ((u32_t *)&u64)[1];

	return S_OK;
}

STDMETHODIMP CDebugger::put_MM0_H(long newVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	u32_t ab[2];
	ab[0] = __mm0_l();
	ab[1] = (u32_t)newVal;
	__mm0_(*(u64_t *)ab);

	return S_OK;
}

STDMETHODIMP CDebugger::get_MM0_L(long *pVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	*pVal = (long)__mm0_l();

	return S_OK;
}

STDMETHODIMP CDebugger::put_MM0_L(long newVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	__mm0_l_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_MM1_H(long *pVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	u64_t u64;
	__mm1_arg(&u64);
	*pVal = ((u32_t *)&u64)[1];

	return S_OK;
}

STDMETHODIMP CDebugger::put_MM1_H(long newVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	u32_t ab[2];
	ab[0] = __mm1_l();
	ab[1] = (u32_t)newVal;
	__mm1_(*(u64_t *)ab);

	return S_OK;
}

STDMETHODIMP CDebugger::get_MM1_L(long *pVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	*pVal = (long)__mm1_l();

	return S_OK;
}

STDMETHODIMP CDebugger::put_MM1_L(long newVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	__mm1_l_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_MM2_H(long *pVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	u64_t u64;
	__mm2_arg(&u64);
	*pVal = ((u32_t *)&u64)[1];

	return S_OK;
}

STDMETHODIMP CDebugger::put_MM2_H(long newVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	u32_t ab[2];
	ab[0] = __mm2_l();
	ab[1] = (u32_t)newVal;
	__mm2_(*(u64_t *)ab);

	return S_OK;
}

STDMETHODIMP CDebugger::get_MM2_L(long *pVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	*pVal = (long)__mm2_l();

	return S_OK;
}

STDMETHODIMP CDebugger::put_MM2_L(long newVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	__mm2_l_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_MM3_H(long *pVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	u64_t u64;
	__mm3_arg(&u64);
	*pVal = ((u32_t *)&u64)[1];

	return S_OK;
}

STDMETHODIMP CDebugger::put_MM3_H(long newVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	u32_t ab[2];
	ab[0] = __mm3_l();
	ab[1] = (u32_t)newVal;
	__mm3_(*(u64_t *)ab);

	return S_OK;
}

STDMETHODIMP CDebugger::get_MM3_L(long *pVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	*pVal = (long)__mm3_l();

	return S_OK;
}

STDMETHODIMP CDebugger::put_MM3_L(long newVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	__mm3_l_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_MM4_H(long *pVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	u64_t u64;
	__mm4_arg(&u64);
	*pVal = ((u32_t *)&u64)[1];

	return S_OK;
}

STDMETHODIMP CDebugger::put_MM4_H(long newVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	u32_t ab[2];
	ab[0] = __mm4_l();
	ab[1] = (u32_t)newVal;
	__mm4_(*(u64_t *)ab);

	return S_OK;
}

STDMETHODIMP CDebugger::get_MM4_L(long *pVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	*pVal = (long)__mm4_l();

	return S_OK;
}

STDMETHODIMP CDebugger::put_MM4_L(long newVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	__mm4_l_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_MM5_H(long *pVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	u64_t u64;
	__mm5_arg(&u64);
	*pVal = ((u32_t *)&u64)[1];

	return S_OK;
}

STDMETHODIMP CDebugger::put_MM5_H(long newVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	u32_t ab[2];
	ab[0] = __mm5_l();
	ab[1] = (u32_t)newVal;
	__mm5_(*(u64_t *)ab);

	return S_OK;
}

STDMETHODIMP CDebugger::get_MM5_L(long *pVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	*pVal = (long)__mm5_l();

	return S_OK;
}

STDMETHODIMP CDebugger::put_MM5_L(long newVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	__mm5_l_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_MM6_H(long *pVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	u64_t u64;
	__mm6_arg(&u64);
	*pVal = ((u32_t *)&u64)[1];

	return S_OK;
}

STDMETHODIMP CDebugger::put_MM6_H(long newVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	u32_t ab[2];
	ab[0] = __mm6_l();
	ab[1] = (u32_t)newVal;
	__mm6_(*(u64_t *)ab);

	return S_OK;
}

STDMETHODIMP CDebugger::get_MM6_L(long *pVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	*pVal = (long)__mm6_l();

	return S_OK;
}

STDMETHODIMP CDebugger::put_MM6_L(long newVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	__mm6_l_((u32_t)newVal);

	return S_OK;
}

STDMETHODIMP CDebugger::get_MM7_H(long *pVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	u64_t u64;
	__mm7_arg(&u64);
	*pVal = ((u32_t *)&u64)[1];

	return S_OK;
}

STDMETHODIMP CDebugger::put_MM7_H(long newVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	u32_t ab[2];
	ab[0] = __mm7_l();
	ab[1] = (u32_t)newVal;
	__mm7_(*(u64_t *)ab);

	return S_OK;
}

STDMETHODIMP CDebugger::get_MM7_L(long *pVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	*pVal = (long)__mm7_l();

	return S_OK;
}

STDMETHODIMP CDebugger::put_MM7_L(long newVal)
{
	if (!_mmx_support()) return E_NOTIMPL;
	__mm7_l_((u32_t)newVal);

	return S_OK;
}
