
#pragma once

#import "CeLiImg.dll"
using namespace CeLiImagesLib;

extern const IID IID_ICeLIDevice;

class CeE2DDevice :
	public CComObjectRoot,
	public CComCoClass<CeE2DDevice, &CLSID_CeE2DDevice>,
	public IDispatchImpl<CeLiImagesLib::ICeLIDevice, &IID_ICeLIDevice> {
public:
	CeE2DDevice();
	virtual ~CeE2DDevice();

	STDMETHOD(get_bitsVal)(LONG x, LONG y, LONG *ret);
	STDMETHOD(put_bitsVal)(LONG x, LONG y, LONG newBits);

	STDMETHOD(get_bindHandle)(LONG *ret);
	STDMETHOD(put_bindHandle)(LONG bindHandle);

	STDMETHOD(get_bitsWidth)(LONG *ret);
	STDMETHOD(put_bitsWidth)(LONG width);
	STDMETHOD(get_bitsHeight)(LONG *ret);
	STDMETHOD(put_bitsHeight)(LONG height);
	STDMETHOD(get_bitsPitch)(LONG *ret);
	STDMETHOD(put_bitsPitch)(LONG pitch);
	STDMETHOD(get_bitsDepth)(LONG *ret);
	STDMETHOD(put_bitsDepth)(LONG pitch);

	STDMETHOD(get_outLeft)(LONG *ret);
	STDMETHOD(put_outLeft)(LONG l);
	STDMETHOD(get_outTop)(LONG *ret);
	STDMETHOD(put_outTop)(LONG l);
	STDMETHOD(get_outWidth)(LONG *ret);
	STDMETHOD(put_outWidth)(LONG l);
	STDMETHOD(get_outHeight)(LONG *ret);
	STDMETHOD(put_outHeight)(LONG l);

	STDMETHOD(get_currentX)(LONG *ret);
	STDMETHOD(put_currentX)(LONG cx);
	STDMETHOD(get_currentY)(LONG *ret);
	STDMETHOD(put_currentY)(LONG cx);

	STDMETHOD(get_bitsPointer)(LONG *ret);
	STDMETHOD(put_bitsPointer)(LONG newPointer);

	STDMETHOD(outX)(LONG inX, LONG *ret);
	STDMETHOD(outY)(LONG inY, LONG *ret);
	STDMETHOD(inX)(LONG outX, LONG *ret);
	STDMETHOD(inY)(LONG outY, LONG *ret);

	STDMETHOD(getPixel)(LONG x, LONG y, LONG *ret);
	STDMETHOD(setPixel)(LONG x, LONG y, LONG color);
	STDMETHOD(setLine)(LONG x0, LONG y0, LONG x1, LONG y1, LONG color);
	STDMETHOD(setRect)(LONG x0, LONG y0, LONG x1, LONG y1, LONG color);
	STDMETHOD(moveTo)(LONG x, LONG y);
	STDMETHOD(lineTo)(LONG x, LONG y);
	STDMETHOD(lineStepTo)(LONG dx, LONG dy);

public:
	BEGIN_COM_MAP(CeE2DDevice)
		COM_INTERFACE_ENTRY2(IDispatch, CeLiImagesLib::ICeLIDevice)
		COM_INTERFACE_ENTRY(CeLiImagesLib::ICeLIDevice)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CeE2D)
	DECLARE_NOT_AGGREGATABLE(CeE2DDevice)

protected:
};

typedef ATL::CComObject<CeE2DDevice>	CCeE2DDevice;
