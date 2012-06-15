
#pragma once

#include "stdafx.h"

#include "GUIDs.h"

DECLARE_INTERFACE_(IFortuneTeller, IUnknown) {
	STDMETHOD(GetFortune)(/*out*/ BSTR *) PURE;
};

typedef IFortuneTeller	*PFortuneTeller, *LPFortuneTeller;
