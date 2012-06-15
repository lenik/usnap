// PseudoControl.cpp : Implementation of CPseudoControl
#include "stdafx.h"
#include "LowX.h"
#include "PseudoControl.h"

/////////////////////////////////////////////////////////////////////////////
// CPseudoControl


namespace PCDEFAULT {
	BOOL _DEFAULT_CONDITION		= FALSE;
	long _DEFAULT_SWITCH_CONDITION	= 0;
	long _DEFAULT_FROM		= 0;
	long _DEFAULT_TO		= 1023;
	long _DEFAULT_STEP		= 1;
	long _DEFAULT_CONTAINER		= 0;

	BOOL _stdcall _if_condition() {
		return _DEFAULT_CONDITION;
	}
	long _stdcall _if_true() {
		return 0;
	}
	long _stdcall _if_false() {
		return 0;
	}
	long _stdcall _switch_condition() {
		return _DEFAULT_SWITCH_CONDITION;
	}
	long _stdcall _case_value() {
		return 0;
	}
	BOOL _stdcall _case_action(long nCase) {
		return FALSE;
	}
	BOOL _stdcall _case_judgement(long a, long b) {
		return a == b;
	}
	BOOL _stdcall _case_default_judgement(long a, long b) {
		return TRUE;
	}
	long _stdcall _for_start() {
		return _DEFAULT_FROM;
	}
	BOOL _stdcall _for_condition(long i) {
		return i <= _DEFAULT_TO;
	}
	long _stdcall _for_step(long iLast) {
		return iLast + _DEFAULT_STEP;
	}
	BOOL _stdcall _for_action(long i) {
		return TRUE;
	}
	long _stdcall _for_container() {
		return _DEFAULT_CONTAINER;
	}
	BOOL _stdcall _for_iteration(long lContainer, long *i) {
		static long _lContainer = 0;
		static BOOL bContainerLoaded = FALSE;

		if (i == NULL) {
			// initialize
			lContainer = lContainer;
			bContainerLoaded = FALSE;
			return TRUE;
		}

		if (bContainerLoaded) {
			*i += _DEFAULT_STEP;
		} else {
			*i = _DEFAULT_FROM;
		}

		return *i <= _DEFAULT_TO;
	}

	BOOL _stdcall _while_condition() {
		return _DEFAULT_CONDITION;
	}
	BOOL _stdcall _while_action() {
		// break
		return FALSE;
	}
}

STDMETHODIMP CPseudoControl::If(long pCondition, long pTrue, long pFalse, long *pRet)
{
	PCPROC_IF_CONDITION _pCondition = (PCPROC_IF_CONDITION)pCondition;
	PCPROC_IF_TRUE _pTrue = (PCPROC_IF_TRUE)pTrue;
	PCPROC_IF_FALSE _pFalse = (PCPROC_IF_FALSE)pFalse;

	if (NULL == _pCondition) _pCondition = PCDEFAULT::_if_condition;
	if (NULL == _pTrue) _pTrue = PCDEFAULT::_if_true;
	if (NULL == _pFalse) _pFalse = PCDEFAULT::_if_false;

	long r;
	if (m_bEvaluateAll) {
		long lT = _pTrue();
		long lF = _pFalse();

		r = _pCondition() ? lT : lF;
	} else {
		if (_pCondition()) {
			r = _pTrue();
		} else {
			r = _pFalse();
		}
	}
	*pRet = r;
	return S_OK;
}

STDMETHODIMP CPseudoControl::Switch(long pProc, long nCases, long aVals, long apActions, long apJudgements, long *pRet)
{
	PCPROC_SWITCH_CONDITION _pCondition = (PCPROC_SWITCH_CONDITION)pProc;
	PCPROC_SWITCH_CASE_VALUES _pCases = (PCPROC_SWITCH_CASE_VALUES)aVals;
	PCPROC_SWITCH_CASE_ACTIONS _pActions = (PCPROC_SWITCH_CASE_ACTIONS)apActions;
	PCPROC_SWITCH_CASE_JUDGEMENTS _pJudgements = (PCPROC_SWITCH_CASE_JUDGEMENTS)apJudgements;

	if (NULL == _pCondition) _pCondition = PCDEFAULT::_switch_condition;
	if (NULL == _pCases) return E_INVALIDARG;

	BOOL bAllDefaultJudgement = _pJudgements == NULL;

	long lCondition = _pCondition();

	BOOL bMatch = FALSE;
	BOOL _bBreaked = FALSE;
	int iCaseBegin = -1;
	for (int iCase = 0; iCase < nCases; iCase++) {
		// prepare case() and judgement() callback
		PCPROC_SWITCH_CASE_VALUE _pCase =
			_pCases == NULL ? PCDEFAULT::_case_value
			: _pCases[iCase];
		if (_pCase == NULL) _pCase = PCDEFAULT::_case_value;

		PCPROC_SWITCH_CASE_JUDGEMENT _pJudgement =
			bAllDefaultJudgement ? PCDEFAULT::_case_judgement
			: _pJudgements[iCase];
		if (_pJudgement == NULL) _pJudgement = PCDEFAULT::_case_default_judgement;

		// make call
		long lCaseVal = _pCase();
		bMatch = bMatch || _pJudgement(lCondition, lCaseVal);

		// if breaked, the left for/loop make judgement() called.
		if (!_bBreaked && bMatch) {
			iCaseBegin = iCase;

			PCPROC_SWITCH_CASE_ACTION _pAction =
				_pActions == NULL ? PCDEFAULT::_case_action
				: _pActions[iCase];
			if (_pAction == NULL) _pAction = PCDEFAULT::_case_action;

			BOOL bAct;
			bAct = _pAction(iCase);
			if (!bAct) _bBreaked = TRUE;

			// Evaluting was totally controled by this statement.
			if (!m_bEvaluateAll) break;
		}
	}

	*pRet = iCaseBegin;
	return S_OK;
}

STDMETHODIMP CPseudoControl::For(long pStart, long pCondition, long pStep, long pAction)
{
	PCPROC_FOR_START _pStart = (PCPROC_FOR_START)pStart;
	PCPROC_FOR_CONDITION _pCondition = (PCPROC_FOR_CONDITION)pCondition;
	PCPROC_FOR_STEP _pStep = (PCPROC_FOR_STEP)pStep;
	PCPROC_FOR_ACTION _pAction = (PCPROC_FOR_ACTION)pAction;

	if (NULL == _pStart) _pStart = PCDEFAULT::_for_start;
	if (NULL == _pCondition) _pCondition = PCDEFAULT::_for_condition;
	if (NULL == _pStep) _pStep = PCDEFAULT::_for_step;
	if (NULL == _pAction) _pAction = PCDEFAULT::_for_action;

	long i;
	for (i = _pStart(); _pCondition(i); i = _pStep(i)) {
		BOOL bAct;
		bAct = _pAction(i);
		if (!bAct) break;
	}

	return S_OK;
}

STDMETHODIMP CPseudoControl::Break()
{
	return S_OK;
}

STDMETHODIMP CPseudoControl::Continue()
{
	return S_OK;
}

STDMETHODIMP CPseudoControl::While(long pCondition, long pAction)
{
	PCPROC_WHILE_CONDITION _pCondition = (PCPROC_WHILE_CONDITION)pCondition;
	PCPROC_WHILE_ACTION _pAction = (PCPROC_WHILE_ACTION)pAction;

	if (NULL == _pCondition) _pCondition = PCDEFAULT::_while_condition;
	if (NULL == _pAction) _pAction = PCDEFAULT::_while_action;

	while (_pCondition()) {
		if (!_pAction()) break;
	}

	return S_OK;
}

STDMETHODIMP CPseudoControl::ForNumeric(long nFrom, long nTo, long nStep, long pAction)
{
	long i = nFrom;

	PCPROC_FORNUMERIC_ACTION _pAction = (PCPROC_FORNUMERIC_ACTION)pAction;
	if (NULL == _pAction) _pAction = PCDEFAULT::_for_action;

	if (nStep > 0) {
		for (; i <= nTo; i += nStep) {
			if (!_pAction(i)) {
				break;
			}
		}
	} else {
		for (; i >= nTo; i += nStep) {
			if (!_pAction(i)) {
				break;
			}
		}
	}

	return S_OK;
}

STDMETHODIMP CPseudoControl::ForItem(long pIteration, long pContainer, long pAction)
{
	PCPROC_FORITEM_CONTAINER _pContainer = (PCPROC_FORITEM_CONTAINER)pContainer;
	PCPROC_FORITEM_ITERATION _pIteration = (PCPROC_FORITEM_ITERATION)pIteration;
	PCPROC_FORITEM_ACTION _pAction = (PCPROC_FORITEM_ACTION)pAction;

	if (NULL == _pContainer) _pContainer = PCDEFAULT::_for_container;
	if (NULL == _pIteration) _pIteration = PCDEFAULT::_for_iteration;
	if (NULL == _pAction) _pAction = PCDEFAULT::_for_action;

	long lContainer = _pContainer();

	// the initiazling must be succeeded.
	BOOL b = _pIteration(lContainer, NULL);
	if (!b) return E_FAIL;

	long iIteration = 0;
	while (b = _pIteration(lContainer, &iIteration)) {
		BOOL bAct = _pAction(iIteration);
		if (!bAct) {
			break;
		}
	}

	return S_OK;
}
