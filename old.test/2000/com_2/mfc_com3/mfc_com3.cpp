// mfc_com3.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "mfc_com3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMfc_com3App

BEGIN_MESSAGE_MAP(CMfc_com3App, CWinApp)
	//{{AFX_MSG_MAP(CMfc_com3App)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMfc_com3App construction

CMfc_com3App::CMfc_com3App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMfc_com3App object

CMfc_com3App theApp;

BOOL CMfc_com3App::InitInstance()
{
	// TODO: Add your specialized code here and/or call the base class
	AfxOleLockApp();
	CWinApp::InitInstance();
	return COleObjectFactory::RegisterAll();
}

int CMfc_com3App::ExitInstance()
{
	// TODO: Add your specialized code here and/or call the base class
	AfxOleUnlockApp();
	return CWinApp::ExitInstance();
}

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppv) {
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return AfxDllGetClassObject(rclsid, riid, ppv);
}

STDAPI DllCanUnloadNow() {
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return AfxDllCanUnloadNow();
}

STDAPI DllRegisterServer() {
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (!COleObjectFactory::UpdateRegistryAll()) {
		return ResultFromScode(SELFREG_E_CLASS);
	}
	return NOERROR;
}

STDAPI DllUnregisterServer() {
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
/*
	CString	strClassID, strProgID;
	strClassID.LoadString(IDS_CLSID_MFC1_IMP1);
	strProgID.LoadString(IDS_PROGID_MFC1_IMP1);

	CLSID	CLSID_Component;
	BSTR	bstrClassID = strClassID.AllocSysString();
	CLSIDFromString(bstrClassID, &CLSID_Component);
	SysFreeString(bstrClassID);

	return AfxOleUnregisterClass(CLSID_Component, strProgID);
*/
	if (!COleObjectFactory::UpdateRegistryAll(FALSE)) {
		return ResultFromScode(SELFREG_E_CLASS);
	}
	return NOERROR;
}
