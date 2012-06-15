// PseudoControl.h : Declaration of the CPseudoControl

#ifndef __PSEUDOCONTROL_H_
#define __PSEUDOCONTROL_H_

#include "resource.h"       // main symbols



////////////////////////////////////////////////////////////////////////////////////////
//
// callback procedure declarations
// -------------------------------------------------------------------------------------
//

// if (condition()) true(); else false();
// BOOL _stdcall condition();
// BOOL _stdcall true();
// BOOL _stdcall false();
typedef BOOL (_stdcall *PCPROC_IF_CONDITION)();
typedef long (_stdcall *PCPROC_IF_TRUE)();
typedef long (_stdcall *PCPROC_IF_FALSE)();

// switch (condition()) { case case()...: if (!action()) break; ...;  }
// long _stdcall condition();
// long _stdcall case();
// BOOL _stdcall action(long);
// BOOL _stdcall judgement(long, long);
typedef long (_stdcall *PCPROC_SWITCH_CONDITION)();
typedef long (_stdcall *PCPROC_SWITCH_CASE_VALUE)();
typedef PCPROC_SWITCH_CASE_VALUE *PCPROC_SWITCH_CASE_VALUES;
typedef BOOL (_stdcall *PCPROC_SWITCH_CASE_ACTION)(long nCaseValue);
typedef PCPROC_SWITCH_CASE_ACTION *PCPROC_SWITCH_CASE_ACTIONS;
typedef BOOL (_stdcall *PCPROC_SWITCH_CASE_JUDGEMENT)(long nCondition, long nCaseValue);
typedef PCPROC_SWITCH_CASE_JUDGEMENT *PCPROC_SWITCH_CASE_JUDGEMENTS;

// for (i = start(); condition(i); i = step(i)) { if (!action(i)) break; }
// long _stdcall start();
// BOOL _stdcall condition(long);
// long _stdcall step(long);
// BOOL _stdcall action(long);
typedef long (_stdcall *PCPROC_FOR_START)();
typedef BOOL (_stdcall *PCPROC_FOR_CONDITION)(long i);
typedef long (_stdcall *PCPROC_FOR_STEP)(long iLast);
typedef BOOL (_stdcall *PCPROC_FOR_ACTION)(long i);

// for (i = nFrom; i <= nTo; i += nStep) { if (!action(i)) break; }
// BOOL _stdcall action(long);
typedef BOOL (_stdcall *PCPROC_FORNUMERIC_ACTION)(long i);

// for (s = iteration(container(), NULL); s; s = iteration(container(), &i))
//	{ if (!action(i)) break; }
// long _stdcall container();
// BOOL _stdcall iteration(long, long *);
// BOOL _stdcall action(long);
typedef long (_stdcall *PCPROC_FORITEM_CONTAINER)();
typedef BOOL (_stdcall *PCPROC_FORITEM_ITERATION)(long lContainer, long *i);
typedef BOOL (_stdcall *PCPROC_FORITEM_ACTION)(long i);

// while (condition()) { if (!action()) break; }
// BOOL _stdcall condition();
// BOOL _stdcall action();
typedef BOOL (_stdcall *PCPROC_WHILE_CONDITION)();
typedef BOOL (_stdcall *PCPROC_WHILE_ACTION)();



/////////////////////////////////////////////////////////////////////////////
// CPseudoControl
class ATL_NO_VTABLE CPseudoControl :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CPseudoControl, &CLSID_PseudoControl>,
	public IDispatchImpl<IPseudoControl, &IID_IPseudoControl, &LIBID_LowXRuntime>
{
public:
	CPseudoControl()
	{
		m_bEvaluateAll = FALSE;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PSEUDOCONTROL)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CPseudoControl)
	COM_INTERFACE_ENTRY(IPseudoControl)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IPseudoControl
public:
	STDMETHOD(If)(long pCondition, long pTrue, long pFalse, long *pRet);
	STDMETHOD(Switch)(long pProc, long nCases, long aVals, long apActions, long apJudgements, /*[out, retval]*/long *pRet);
	STDMETHOD(For)(long pStart, long pCondition, long pStep, long pAction);
	STDMETHOD(Break)();
	STDMETHOD(Continue)();
	STDMETHOD(While)(long pCondition, long pAction);
	STDMETHOD(ForNumeric)(long nFrom, long nTo, long nStep, long pAction);
	STDMETHOD(ForItem)(long pIteration, long pContainer, long pAction);

public:
	BOOL m_bEvaluateAll;
};

#endif //__PSEUDOCONTROL_H_
