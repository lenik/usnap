
#include "StdAfx.h"

#include "resource.h"

#include "CeLiImages.h"
#include "CeLIColor.h"

HRESULT _stdcall rgb24Plus(LONG c1, LONG c2, LONG *ret) {
	*ret = c1 + c2;
	return NOERROR;
}
