
#include "StdAfx.h"

#include "resource.h"

#include "CeLiImages.h"
#include "CeLIBits2.h"


CeLIBits2::CeLIBits2() {}

CeLIBits2::~CeLIBits2() {}

STDMETHODIMP
CeLIBits2::Blit(ICeLIDevice *cldDest,
		LONG destx, LONG desty, LONG width, LONG height,
		LONG rop) {
	return NOERROR;
}
