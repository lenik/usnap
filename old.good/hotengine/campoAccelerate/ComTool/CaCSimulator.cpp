
#include "StdAfx.h"

#include "resource.h"

#include "ComTool.h"
#include "CaCSimulator.h"

CaCSimulator::CaCSimulator() {
	this->m_pSimulatorObject = NULL;
}

CaCSimulator::~CaCSimulator() {
	if (this->m_pSimulatorObject != NULL) {
		this->m_pSimulatorObject->Release();
		this->m_pSimulatorObject = NULL;
	}
}

STDMETHODIMP
CaCSimulator::simulate(IDispatch *simulate_object) {
	if (this->m_pSimulatorObject != NULL) {
		this->m_pSimulatorObject->Release();
	}

	if (simulate_object == NULL) {
		this->m_pSimulatorObject = NULL;
		return NOERROR;
	}

	this->m_pSimulatorObject = simulate_object;
	this->m_pSimulatorObject->AddRef();
	return NOERROR;
}

// COMµ×²ã¹Ò¹³
STDMETHODIMP
CaCSimulator::GetTypeInfoCount(UINT *pctinfo) {
	if (this->m_pSimulatorObject != NULL) {
		return this->m_pSimulatorObject->GetTypeInfoCount(pctinfo);
	} else {
		return IDispatchImpl<ICaCSimulator, &IID_ICaCSimulator>::GetTypeInfoCount(pctinfo);
	}
}

STDMETHODIMP
CaCSimulator::GetTypeInfo(INT iTInfo, LCID lcid, ITypeInfo **ppTInfo) {
	if (this->m_pSimulatorObject != NULL) {
		return this->m_pSimulatorObject->GetTypeInfo(
			iTInfo,
			lcid,
			ppTInfo);
	} else {
		return IDispatchImpl<ICaCSimulator, &IID_ICaCSimulator>::GetTypeInfo(
			iTInfo,
			lcid,
			ppTInfo);
	}
}

STDMETHODIMP
CaCSimulator::GetIDsOfNames(REFIID riid, LPOLESTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId) {
	if (this->m_pSimulatorObject != NULL) {
		return this->m_pSimulatorObject->GetIDsOfNames(
			riid,
			rgszNames,
			cNames,
			lcid,
			rgDispId);
	} else {
		return IDispatchImpl<ICaCSimulator, &IID_ICaCSimulator>::GetIDsOfNames(
			riid,
			rgszNames,
			cNames,
			lcid,
			rgDispId);
	}
}

STDMETHODIMP
CaCSimulator::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags,
		     DISPPARAMS *pDispParams, VARIANT *pVarResult,
		     EXCEPINFO *pExcepInfo, UINT *puArgErr) {
	if (this->m_pSimulatorObject != NULL) {
		return this->m_pSimulatorObject->Invoke(
			dispIdMember,
			riid,
			lcid,
			wFlags,
			pDispParams,
			pVarResult,
			pExcepInfo,
			puArgErr);
	} else {
		return IDispatchImpl<ICaCSimulator, &IID_ICaCSimulator>::Invoke(
			dispIdMember,
			riid,
			lcid,
			wFlags,
			pDispParams,
			pVarResult,
			pExcepInfo,
			puArgErr);
	}
}
