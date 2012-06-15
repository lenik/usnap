// PseudoControlSetting.h : Declaration of the CPseudoControlSetting

#ifndef __PSEUDOCONTROLSETTING_H_
#define __PSEUDOCONTROLSETTING_H_

#include "resource.h"       // main symbols


namespace PCDEFAULT {
	extern BOOL _DEFAULT_CONDITION;
	extern long _DEFAULT_SWITCH_CONDITION;
	extern long _DEFAULT_FROM;
	extern long _DEFAULT_TO;
	extern long _DEFAULT_STEP;
	extern long _DEFAULT_CONTAINER;

	BOOL _stdcall _if_condition();
	long _stdcall _if_true();
	long _stdcall _if_false();
	long _stdcall _switch_condition();
	long _stdcall _case_value();
	BOOL _stdcall _case_action(long nCase);
	BOOL _stdcall _case_judgement(long a, long b);
	BOOL _stdcall _case_default_judgement(long a, long b);
	long _stdcall _for_start();
	BOOL _stdcall _for_condition(long i);
	long _stdcall _for_step(long iLast);
	long _stdcall _for_container();
	BOOL _stdcall _for_iteration(long lContainer, long *i);
};

/////////////////////////////////////////////////////////////////////
// CPseudoControlSetting
class ATL_NO_VTABLE CPseudoControlSetting :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CPseudoControlSetting, &CLSID_PseudoControlSetting>,
	public IDispatchImpl<IPseudoControlSetting, &IID_IPseudoControlSetting, &LIBID_LowXRuntime>
{
public:
	CPseudoControlSetting()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PSEUDOCONTROLSETTING)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CPseudoControlSetting)
	COM_INTERFACE_ENTRY(IPseudoControlSetting)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IPseudoControlSetting
public:
	STDMETHOD(get_pDefaultForIteration)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_pDefaultForContainer)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_pDefaultForStep)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_pDefaultForCondition)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_pDefaultForStart)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_pDefaultCaseDefaultJudgement)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_pDefaultCaseJudgement)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_pDefaultCaseAction)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_pDefaultCaseValue)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_pDefaultSwitchCondition)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_pDefaultIfFalse)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_pDefaultIfTrue)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_pDefaultIfCondition)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_DefaultContainer)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_DefaultContainer)(/*[in]*/ long newVal);
	STDMETHOD(get_DefaultStep)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_DefaultStep)(/*[in]*/ long newVal);
	STDMETHOD(get_DefaultTo)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_DefaultTo)(/*[in]*/ long newVal);
	STDMETHOD(get_DefaultFrom)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_DefaultFrom)(/*[in]*/ long newVal);
	STDMETHOD(get_DefaultSwitchCondition)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_DefaultSwitchCondition)(/*[in]*/ long newVal);
	STDMETHOD(get_DefaultCondition)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_DefaultCondition)(/*[in]*/ VARIANT_BOOL newVal);
};

#endif //__PSEUDOCONTROLSETTING_H_
