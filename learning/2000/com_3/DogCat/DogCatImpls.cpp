
#include "StdAfx.h"

#include "DogCatImpls.h"

#import "DogCat.tlb"

STDMETHODIMP
CaDog::shout() {
	MessageBox(NULL, _T("Dog shout!"), _T("Dog shout!"), MB_OK);
	return NOERROR;
}

STDMETHODIMP
CaDog::bornDog(ICaDog **ret) {
	if (0) {
		CCaDog	*adog = new CCaDog;
		*ret	= adog;
		adog->AddRef();
	} else {
		CaDogCatLib::ICaDogPtr pnewdog;
		pnewdog.CreateInstance(_T("CampoAccelerate.CaDog"));
		*ret	= (ICaDog *)((CaDogCatLib::ICaDog *)pnewdog);
		pnewdog->AddRef();
	}
	return S_OK;
}

STDMETHODIMP
CaDog::bornCat(ICaCat **ret) {
	*ret	= new CCaCat;
	return S_OK;
}

STDMETHODIMP
CaCat::shout() {
	MessageBox(NULL, _T("Cat shout2!"), _T("Cat shout2!"), MB_OK);
	return NOERROR;
}

STDMETHODIMP
CaCat::catshout() {
	MessageBox(NULL, _T("Cat shout123!"), _T("Cat shout123!"), MB_OK);
	return NOERROR;
}


STDMETHODIMP
CaEarthquake::quakeNow() {
	this->Fire_onQuake();
	MessageBox(NULL, _T("quake again!"), NULL, MB_OK);
	this->Fire_onQuake();
	return NOERROR;
}

void
CaEarthquake::onQuake() {
	MessageBox(NULL, _T("if you seen this message, that means object has problem. "),
		_T("you won't see this in mind. "), MB_OK);
	return;
}

/*
void CaEarthquake::Fire_onQuake() {
	int nConnectionIndex	= 0;
	int nConnections	= m_vec.GetSize();

	for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++) {
		this->Lock();
		CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
		this->Unlock();

		IDispatch *pDispatch = reinterpret_cast<IDispatch *>(sp.p);
		if (pDispatch != NULL) {
			DISPPARAMS disp = { NULL, NULL, 0, 0 };
			pDispatch->Invoke(2000001, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
		}
	}
}
*/

STDMETHODIMP
CaHorse::run() {
	MessageBox(NULL, _T("Horse running!"), NULL, MB_OK);
	return NOERROR;
}


STDMETHODIMP
CaPlane::fly() {
	MessageBox(NULL, _T("I can fly!!!"), NULL, MB_OK);

	this->Fire_onCrashed();
	return NOERROR;
}
