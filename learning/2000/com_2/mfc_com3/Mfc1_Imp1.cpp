
#include "stdafx.h"

#include "Mfc1_Imp1.h"

IMPLEMENT_DYNCREATE(CMfc1_Imp1, CCmdTarget);

IMPLEMENT_OLECREATE(CMfc1_Imp1, "Mfc1_Imp1",
		    0x00000000, 0x0010, 0x0000, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);

BEGIN_INTERFACE_MAP(CMfc1_Imp1, CCmdTarget)
	INTERFACE_PART(CMfc1_Imp1, IID_IMfc1_Interface1, CMfc1_Interface1_Imp1)
	INTERFACE_PART(CMfc1_Imp1, IID_IMfc1_Interface2, CMfc1_Interface2_Imp1)
END_INTERFACE_MAP()

CMfc1_Imp1::CMfc1_Imp1() {
	AfxOleLockApp();
}

CMfc1_Imp1::~CMfc1_Imp1() {
	AfxOleUnlockApp();
}

STDMETHODIMP
CMfc1_Imp1::XCMfc1_Interface1_Imp1::QueryInterface(REFIID iid, LPVOID *ppv) {
	METHOD_PROLOGUE(CMfc1_Imp1, CMfc1_Interface1_Imp1);
	return pThis->ExternalQueryInterface(&iid, ppv);
}

STDMETHODIMP_(ULONG)
CMfc1_Imp1::XCMfc1_Interface1_Imp1::AddRef() {
	METHOD_PROLOGUE(CMfc1_Imp1, CMfc1_Interface1_Imp1);
	return pThis->ExternalAddRef();
}
STDMETHODIMP_(ULONG)
CMfc1_Imp1::XCMfc1_Interface1_Imp1::Release() {
	METHOD_PROLOGUE(CMfc1_Imp1, CMfc1_Interface1_Imp1);
	return pThis->ExternalRelease();
}
STDMETHODIMP
CMfc1_Imp1::XCMfc1_Interface1_Imp1::I1_Method1() {
	METHOD_PROLOGUE(CMfc1_Imp1, CMfc1_Interface1_Imp1);
	MessageBox(NULL,
		"CMfc1_Imp1::XCMfc1_Interface1_Imp1::I1_Method()",
		"CMfc1_Imp1::XCMfc1_Interface1_Imp1", MB_OK);
	return NOERROR;
}

STDMETHODIMP
CMfc1_Imp1::XCMfc1_Interface2_Imp1::QueryInterface(REFIID iid, LPVOID *ppv) {
	METHOD_PROLOGUE(CMfc1_Imp1, CMfc1_Interface2_Imp1);
	return pThis->ExternalQueryInterface(&iid, ppv);
}
STDMETHODIMP_(ULONG)
CMfc1_Imp1::XCMfc1_Interface2_Imp1::AddRef() {
	METHOD_PROLOGUE(CMfc1_Imp1, CMfc1_Interface2_Imp1);
	return pThis->ExternalAddRef();
}
STDMETHODIMP_(ULONG)
CMfc1_Imp1::XCMfc1_Interface2_Imp1::Release() {
	METHOD_PROLOGUE(CMfc1_Imp1, CMfc1_Interface2_Imp1);
	return pThis->ExternalRelease();
}
STDMETHODIMP
CMfc1_Imp1::XCMfc1_Interface2_Imp1::I2_Method1() {
	METHOD_PROLOGUE(CMfc1_Imp1, CMfc1_Interface2_Imp1);
	MessageBox(NULL,
		"CMfc1_Imp1::XCMfc1_Interface2_Imp1::I2_Method1()",
		"CMfc1_Imp1::XCMfc1_Interface2_Imp1", MB_OK);
	return NOERROR;
}

// IMPLEMENT_NESTED_IUNKNOWN(CMfc1_Imp1, CMfc1_Interface1_Imp1)
// IMPLEMENT_NESTED_IUNKONWN(CMfc1_Imp1, CMfc1_Interface2_Imp1)
