
#include "StdAfx.h"

#include "resource.h"

#include "CeLiImages.h"
#include "CeLIDevice.h"


CeLIDevice::CeLIDevice() {}

CeLIDevice::~CeLIDevice() {}

STDMETHODIMP
CeLIDevice::get_bitsVal(LONG x, LONG y, LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::put_bitsVal(LONG x, LONG y, LONG newBits) {
	return NOERROR;
}


STDMETHODIMP
CeLIDevice::get_bindHandle(LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::put_bindHandle(LONG bindHandle) {
	return NOERROR;
}


STDMETHODIMP
CeLIDevice::get_bitsWidth(LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::put_bitsWidth(LONG width) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::get_bitsHeight(LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::put_bitsHeight(LONG height) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::get_bitsPitch(LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::put_bitsPitch(LONG pitch) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::get_bitsDepth(LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::put_bitsDepth(LONG pitch) {
	return NOERROR;
}


STDMETHODIMP
CeLIDevice::get_outLeft(LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::put_outLeft(LONG l) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::get_outTop(LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::put_outTop(LONG l) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::get_outWidth(LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::put_outWidth(LONG l) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::get_outHeight(LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::put_outHeight(LONG l) {
	return NOERROR;
}


STDMETHODIMP
CeLIDevice::get_currentX(LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::put_currentX(LONG cx) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::get_currentY(LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::put_currentY(LONG cx) {
	return NOERROR;
}


STDMETHODIMP
CeLIDevice::get_bitsPointer(LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::put_bitsPointer(LONG newPointer) {
	return NOERROR;
}


STDMETHODIMP
CeLIDevice::outX(LONG inX, LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::outY(LONG inY, LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::inX(LONG outX, LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::inY(LONG outY, LONG *ret) {
	return NOERROR;
}


STDMETHODIMP
CeLIDevice::getPixel(LONG x, LONG y, LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::setPixel(LONG x, LONG y, LONG color) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::setLine(LONG x0, LONG y0, LONG x1, LONG y1, LONG color) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::setRect(LONG x0, LONG y0, LONG x1, LONG y1, LONG color) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::moveTo(LONG x, LONG y) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::lineTo(LONG x, LONG y) {
	return NOERROR;
}

STDMETHODIMP
CeLIDevice::lineStepTo(LONG dx, LONG dy) {
	return NOERROR;
}
