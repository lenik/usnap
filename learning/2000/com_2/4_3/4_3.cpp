// 4_3.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include <string.h>

#include "Utility.h"
#include "Counts.h"
#include "4_3.h"
#include "Factory2.h"

static char *g_astrFortunes[] = {
	"You are strong is body and spirit. ",
	"You are strong in perspiration and odor. ",
	"Good fortune smiles upon the distributed. ",
	"You will solve the world hunger problem. ",
	"I never met an object I didn't like. ",
	"Edit, compile, link, crash, sigh. ",
	"Never judge a stack dump by its arguments. ",
	"Card carrying member off the Bug Police. ",
	"You make dilbert lok charming and sophisticated. "
};

static const ULONG g_ulNumFortunes = sizeof(g_astrFortunes) / sizeof(char *);

ComFortuneTeller::ComFortuneTeller() : m_cRef(0) {
	VerboseMsg("Constructing new ComFortuneTeller object. \n");

	struct _timeb timebuffer;
	_ftime(&timebuffer);
	srand(timebuffer.millitm);
}

STDMETHODIMP ComFortuneTeller::QueryInterface(REFIID riid, PPVOID ppInterface) {
	VerboseMsg("In ComFortuneTeller::QueryInterface\n");

	if (riid == IID_IUnknown) {
		VerboseMsg("	Requesting IUnknown Interface");
		*ppInterface	= this;
	}
	else if (riid == IID_IFortuneTeller) {
		VerboseMsg("	Request IFortuneTeller Interface");
		*ppInterface	= this;
	} else {
		VerboseMsg("	Requesting unsupported interface");
		*ppInterface	= NULL;
	}

	if (*ppInterface) {
		((LPUNKNOWN) *ppInterface)->AddRef();
	}
	return NOERROR;
}

STDMETHODIMP_(ULONG) ComFortuneTeller::AddRef() {
	m_cRef++;
	VerboseMsg("In ComFortuneTeller::AddRef. Reference count = " + ULongToStr(m_cRef));
	return m_cRef;
}

STDMETHODIMP_(ULONG) ComFortuneTeller::Release() {
	m_cRef--;
	VerboseMsg("In ComFortuneTeller::Release. Reference count = " + ULongToStr(m_cRef));

	if (m_cRef) return m_cRef;

	Counters::DecObjectCount();

	VerboseMsg("	ComFortuneTeller reference count is 0. Deleting self");
	delete this;
	return 0;
}

STDMETHODIMP ComFortuneTeller::GetFortune(BSTR *pbstrFortune) {
	VerboseMsg("In ComFortuneTeller::GetFortune");

	*pbstrFortune	= NULL;
	LPOLESTR pszFortuneW;

	AnsiToUnicode(g_astrFortunes[rand() % g_ulNumFortunes].c_str(), &pszFortuneW);

	*pbstrFortune = SysAllocString(pszFortuneW);

	CoTaskMemFree(pszFortuneW);

	if (*pbstrFortune) return NOERROR;

	return E_OUTOFMEMORY;
}
