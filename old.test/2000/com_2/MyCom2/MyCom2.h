
#undef INTERFACE
#define INTERFACE	IMyCom2_Class1_Interface1
DECLARE_INTERFACE_(IMyCom2_Class1_Interface1, IUnknown) {
	STDMETHOD(Popup)() PURE;
};

typedef IMyCom2_Class1_Interface1
	*PMyCom2_Class1_Interface1,
	*LPMyCom2_Class1_Interface1;

DEFINE_GUID(CLSID_MyCom2_Class1,
	    0xA0000000, 0x0000, 0x0000, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);

DEFINE_GUID(IID_IMyCom2_Class1_Interface1,
	    0xA0000001, 0x0000, 0x0000, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);

