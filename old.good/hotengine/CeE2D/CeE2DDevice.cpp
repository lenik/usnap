
#include "StdAfx.h"

#include "resource.h"

#include "CeE2D.h"
#include "CeE2DDevice.h"

const IID IID_ICeLIDevice = {0x00000000,0x4345,0x1200,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};

CeE2DDevice::CeE2DDevice() {}

CeE2DDevice::~CeE2DDevice() {}


STDMETHODIMP
CeE2DDevice::get_bitsVal(LONG x, LONG y, LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::put_bitsVal(LONG x, LONG y, LONG newBits) {
	return NOERROR;
}


STDMETHODIMP
CeE2DDevice::get_bindHandle(LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::put_bindHandle(LONG bindHandle) {
	return NOERROR;
}


STDMETHODIMP
CeE2DDevice::get_bitsWidth(LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::put_bitsWidth(LONG width) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::get_bitsHeight(LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::put_bitsHeight(LONG height) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::get_bitsPitch(LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::put_bitsPitch(LONG pitch) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::get_bitsDepth(LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::put_bitsDepth(LONG pitch) {
	return NOERROR;
}


STDMETHODIMP
CeE2DDevice::get_outLeft(LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::put_outLeft(LONG l) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::get_outTop(LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::put_outTop(LONG l) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::get_outWidth(LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::put_outWidth(LONG l) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::get_outHeight(LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::put_outHeight(LONG l) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::get_currentX(LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::put_currentX(LONG cx) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::get_currentY(LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::put_currentY(LONG cx) {
	return NOERROR;
}


STDMETHODIMP
CeE2DDevice::get_bitsPointer(LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::put_bitsPointer(LONG newPointer) {
	return NOERROR;
}


STDMETHODIMP
CeE2DDevice::outX(LONG inX, LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::outY(LONG inY, LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::inX(LONG outX, LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::inY(LONG outY, LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::getPixel(LONG x, LONG y, LONG *ret) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::setPixel(LONG x, LONG y, LONG color) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::setLine(LONG x0, LONG y0, LONG x1, LONG y1, LONG color) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::setRect(LONG x0, LONG y0, LONG x1, LONG y1, LONG color) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::moveTo(LONG x, LONG y) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::lineTo(LONG x, LONG y) {
	return NOERROR;
}

STDMETHODIMP
CeE2DDevice::lineStepTo(LONG dx, LONG dy) {
	return NOERROR;
}
