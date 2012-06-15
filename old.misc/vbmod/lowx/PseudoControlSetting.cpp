// PseudoControlSetting.cpp : Implementation of CPseudoControlSetting
#include "stdafx.h"
#include "LowX.h"
#include "PseudoControlSetting.h"

/////////////////////////////////////////////////////////////////////////////
// CPseudoControlSetting


STDMETHODIMP CPseudoControlSetting::get_DefaultCondition(VARIANT_BOOL *pVal)
{
	*pVal = (VARIANT_BOOL)PCDEFAULT::_DEFAULT_CONDITION;
	return S_OK;
}

STDMETHODIMP CPseudoControlSetting::put_DefaultCondition(VARIANT_BOOL newVal)
{
	PCDEFAULT::_DEFAULT_CONDITION = (BOOL)newVal;
	return S_OK;
}

STDMETHODIMP CPseudoControlSetting::get_DefaultSwitchCondition(long *pVal)
{
	*pVal = PCDEFAULT::_DEFAULT_SWITCH_CONDITION;
	return S_OK;
}

STDMETHODIMP CPseudoControlSetting::put_DefaultSwitchCondition(long newVal)
{
	PCDEFAULT::_DEFAULT_SWITCH_CONDITION = newVal;
	return S_OK;
}

STDMETHODIMP CPseudoControlSetting::get_DefaultFrom(long *pVal)
{
	*pVal = PCDEFAULT::_DEFAULT_FROM;
	return S_OK;
}

STDMETHODIMP CPseudoControlSetting::put_DefaultFrom(long newVal)
{
	PCDEFAULT::_DEFAULT_FROM = newVal;
	return S_OK;
}

STDMETHODIMP CPseudoControlSetting::get_DefaultTo(long *pVal)
{
	*pVal = PCDEFAULT::_DEFAULT_TO;
	return S_OK;
}

STDMETHODIMP CPseudoControlSetting::put_DefaultTo(long newVal)
{
	PCDEFAULT::_DEFAULT_TO = newVal;
	return S_OK;
}

STDMETHODIMP CPseudoControlSetting::get_DefaultStep(long *pVal)
{
	*pVal = PCDEFAULT::_DEFAULT_STEP;
	return S_OK;
}

STDMETHODIMP CPseudoControlSetting::put_DefaultStep(long newVal)
{
	PCDEFAULT::_DEFAULT_STEP = newVal;
	return S_OK;
}

STDMETHODIMP CPseudoControlSetting::get_DefaultContainer(long *pVal)
{
	*pVal = PCDEFAULT::_DEFAULT_CONTAINER;
	return S_OK;
}

STDMETHODIMP CPseudoControlSetting::put_DefaultContainer(long newVal)
{
	PCDEFAULT::_DEFAULT_CONTAINER = newVal;
	return S_OK;
}

STDMETHODIMP CPseudoControlSetting::get_pDefaultIfCondition(long *pVal)
{
	*pVal = (long)PCDEFAULT::_if_condition;
	return S_OK;
}

STDMETHODIMP CPseudoControlSetting::get_pDefaultIfTrue(long *pVal)
{
	*pVal = (long)PCDEFAULT::_if_true;
	return S_OK;
}

STDMETHODIMP CPseudoControlSetting::get_pDefaultIfFalse(long *pVal)
{
	*pVal = (long)PCDEFAULT::_if_false;
	return S_OK;
}

STDMETHODIMP CPseudoControlSetting::get_pDefaultSwitchCondition(long *pVal)
{
	*pVal = (long)PCDEFAULT::_switch_condition;
	return S_OK;
}

STDMETHODIMP CPseudoControlSetting::get_pDefaultCaseValue(long *pVal)
{
	*pVal = (long)PCDEFAULT::_case_value;
	return S_OK;
}

STDMETHODIMP CPseudoControlSetting::get_pDefaultCaseAction(long *pVal)
{
	*pVal = (long)PCDEFAULT::_case_action;
	return S_OK;
}

STDMETHODIMP CPseudoControlSetting::get_pDefaultCaseJudgement(long *pVal)
{
	*pVal = (long)PCDEFAULT::_case_judgement;
	return S_OK;
}

STDMETHODIMP CPseudoControlSetting::get_pDefaultCaseDefaultJudgement(long *pVal)
{
	*pVal = (long)PCDEFAULT::_case_default_judgement;
	return S_OK;
}

STDMETHODIMP CPseudoControlSetting::get_pDefaultForStart(long *pVal)
{
	*pVal = (long)PCDEFAULT::_for_start;
	return S_OK;
}

STDMETHODIMP CPseudoControlSetting::get_pDefaultForCondition(long *pVal)
{
	*pVal = (long)PCDEFAULT::_for_condition;
	return S_OK;
}

STDMETHODIMP CPseudoControlSetting::get_pDefaultForStep(long *pVal)
{
	*pVal = (long)PCDEFAULT::_for_step;
	return S_OK;
}

STDMETHODIMP CPseudoControlSetting::get_pDefaultForContainer(long *pVal)
{
	*pVal = (long)PCDEFAULT::_for_container;
	return S_OK;
}

STDMETHODIMP CPseudoControlSetting::get_pDefaultForIteration(long *pVal)
{
	*pVal = (long)PCDEFAULT::_for_iteration;
	return S_OK;
}
