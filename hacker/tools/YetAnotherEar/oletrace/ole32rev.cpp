
#include "stdafx.h"

#include "ole32rev.h"


DWORD	_stdcall P_CoBuildVersion() {
	return 0;
}
HRESULT	_stdcall P_CoInitialize(LPVOID pvReserved) {
	return S_OK;
}
void	_stdcall P_CoUninitialize() {
}
HRESULT	_stdcall P_CoGetMalloc(DWORD dwMemP_Context, LPMALLOC FAR* ppMalloc) {
	return S_OK;
}
DWORD	_stdcall P_CoGetCurrentProcess() {
	return 0;
}
HRESULT	_stdcall P_CoRegisterMallocSpy(LPMALLOCSPY pMallocSpy) {
	return S_OK;
}
HRESULT	_stdcall P_CoRevokeMallocSpy() {
	return S_OK;
}
HRESULT	_stdcall P_CoCreateStandardMalloc(DWORD memctx, IMalloc FAR* FAR* ppMalloc) {
	return S_OK;
}
HRESULT	_stdcall P_CoInitializeEx(LPVOID pvReserved, DWORD dwP_CoInit) {
	return S_OK;
}
HRESULT	_stdcall P_CoGetCallerTID(LPDWORD lpdwTID) {
	return S_OK;
}
//HRESULT	_stdcall P_CoRegisterInitializeSpy(LPINITIALIZESPY pSpy, ULARGE_INTEGER *puliP_Cookie) {
//	return S_OK;
//}
HRESULT	_stdcall P_CoRevokeInitializeSpy(ULARGE_INTEGER uliP_Cookie) {
	return S_OK;
}
HRESULT	_stdcall P_CoGetP_ContextToken(ULONG_PTR* pToken) {
	return S_OK;
}
ULONG	_stdcall P_DebugCoGetRpcFault() {
	return 0;
}
void	_stdcall P_DebugCoSetRpcFault(ULONG) {
}
HRESULT	_stdcall P_CoGetObjectP_Context(REFIID riid, LPVOID FAR* ppv) {
	return S_OK;
}
HRESULT	_stdcall P_CoGetClassObject(REFCLSID rclsid, DWORD dwClsP_Context, LPVOID pvReserved, REFIID riid, LPVOID FAR* ppv) {
	return S_OK;
}
HRESULT	_stdcall P_CoRegisterClassObject(REFCLSID rclsid, LPUNKNOWN pUnk, DWORD dwClsP_Context, DWORD flags, LPDWORD lpdwRegister) {
	return S_OK;
}
HRESULT	_stdcall P_CoRevokeClassObject(DWORD dwRegister) {
	return S_OK;
}
HRESULT	_stdcall P_CoResumeClassObjects() {
	return S_OK;
}
HRESULT	_stdcall P_CoSuspendClassObjects() {
	return S_OK;
}
ULONG	_stdcall P_CoAddRefServerProcess() {
	return 0;
}
ULONG	_stdcall P_CoReleaseServerProcess() {
	return 0;
}
HRESULT	_stdcall P_CoGetPSClsid(REFIID riid, CLSID *pClsid) {
	return S_OK;
}
HRESULT	_stdcall P_CoRegisterPSClsid(REFIID riid, REFCLSID rclsid) {
	return S_OK;
}
HRESULT	_stdcall P_CoRegisterSurrogate(LPSURROGATE pSurrogate) {
	return S_OK;
}
HRESULT	_stdcall P_CoGetMarshalSizeMax(ULONG *pulSize, REFIID riid, LPUNKNOWN pUnk, DWORD dwDestP_Context, LPVOID pvDestP_Context, DWORD mshlflags) {
	return S_OK;
}
HRESULT	_stdcall P_CoMarshalInterface(LPSTREAM pStm, REFIID riid, LPUNKNOWN pUnk, DWORD dwDestP_Context, LPVOID pvDestP_Context, DWORD mshlflags) {
	return S_OK;
}
HRESULT	_stdcall P_CoUnmarshalInterface(LPSTREAM pStm, REFIID riid, LPVOID FAR* ppv) {
	return S_OK;
}
HRESULT	_stdcall P_CoMarshalHresult(LPSTREAM pstm, HRESULT hresult) {
	return S_OK;
}
HRESULT	_stdcall P_CoUnmarshalHresult(LPSTREAM pstm, HRESULT FAR * phresult) {
	return S_OK;
}
HRESULT	_stdcall P_CoReleaseMarshalData(LPSTREAM pStm) {
	return S_OK;
}
HRESULT	_stdcall P_CoDisconnectObject(LPUNKNOWN pUnk, DWORD dwReserved) {
	return S_OK;
}
HRESULT	_stdcall P_CoLockObjectExternal(LPUNKNOWN pUnk, BOOL fLock, BOOL fLastUnlockReleases) {
	return S_OK;
}
HRESULT	_stdcall P_CoGetStandardMarshal(REFIID riid, LPUNKNOWN pUnk, DWORD dwDestP_Context, LPVOID pvDestP_Context, DWORD mshlflags, LPMARSHAL FAR* ppMarshal) {
	return S_OK;
}
HRESULT	_stdcall P_CoGetStdMarshalEx(LPUNKNOWN pUnkOuter, DWORD smexflags, LPUNKNOWN FAR* ppUnkInner) {
	return S_OK;
}
BOOL	_stdcall P_CoIsHandlerP_Connected(LPUNKNOWN pUnk) {
	return FALSE;
}
HRESULT	_stdcall P_CoMarshalInterThreadInterfaceInStream(REFIID riid, LPUNKNOWN pUnk, LPSTREAM *ppStm) {
	return S_OK;
}
HRESULT	_stdcall P_CoGetInterfaceAndReleaseStream(LPSTREAM pStm, REFIID iid, LPVOID FAR* ppv) {
	return S_OK;
}
HRESULT	_stdcall P_CoCreateFreeThreadedMarshaler(LPUNKNOWN punkOuter, LPUNKNOWN *ppunkMarshal) {
	return S_OK;
}
HINSTANCE _stdcall P_CoLoadLibrary(LPOLESTR lpszLibName, BOOL bAutoFree) {
	return NULL;
}
void	_stdcall P_CoFreeLibrary(HINSTANCE hInst) {
}
void	_stdcall P_CoFreeAllLibraries() {
}
void	_stdcall P_CoFreeUnusedLibraries() {
}
void	_stdcall P_CoFreeUnusedLibrariesEx(DWORD dwUnloadDelay, DWORD dwReserved) {
}
//HRESULT	_stdcall P_CoInitializeSecurity(PSECURITY_DESCRIPTOR pSecDesc, LONG cAuthSvc, SOLE_AUTHENTICATION_SERVICE *asAuthSvc, void *pReserved1, DWORD dwAuthnLevel, DWORD dwImpLevel, void *pAuthList, DWORD dwCapabilities, void *pReserved3) {
//	return S_OK;
//}
HRESULT	_stdcall P_CoGetCallP_Context(REFIID riid, void **ppInterface) {
	return S_OK;
}
HRESULT	_stdcall P_CoQueryProxyBlanket( IUnknown *pProxy, DWORD *pwAuthnSvc, DWORD *pAuthzSvc, OLECHAR **pServerPrincName, DWORD *pAuthnLevel, DWORD *pImpLevel, RPC_AUTH_IDENTITY_HANDLE *pAuthInfo, DWORD *pCapabilites) {
	return S_OK;
}
HRESULT	_stdcall P_CoSetProxyBlanket(IUnknown *pProxy, DWORD dwAuthnSvc, DWORD dwAuthzSvc, OLECHAR *pServerPrincName, DWORD dwAuthnLevel, DWORD dwImpLevel, RPC_AUTH_IDENTITY_HANDLE pAuthInfo, DWORD dwCapabilities) {
	return S_OK;
}
HRESULT	_stdcall P_CoP_CopyProxy( IUnknown *pProxy, IUnknown **ppP_Copy) {
	return S_OK;
}
HRESULT	_stdcall P_CoQueryClientBlanket(DWORD *pAuthnSvc, DWORD *pAuthzSvc, OLECHAR **pServerPrincName, DWORD *pAuthnLevel, DWORD *pImpLevel, RPC_AUTHZ_HANDLE *pPrivs, DWORD *pCapabilities) {
	return S_OK;
}
HRESULT	_stdcall P_CoImpersonateClient() {
	return S_OK;
}
HRESULT	_stdcall P_CoRevertToSelf() {
	return S_OK;
}
//HRESULT	_stdcall P_CoQueryAuthenticationServices(DWORD *pcAuthSvc, SOLE_AUTHENTICATION_SERVICE **asAuthSvc) {
//	return S_OK;
//}
HRESULT	_stdcall P_CoSwitchCallP_Context(IUnknown *pNewObject, IUnknown **ppOldObject) {
	return S_OK;
}
HRESULT	_stdcall P_CoCreateInstance(REFCLSID rclsid, LPUNKNOWN pUnkOuter, DWORD dwClsP_Context, REFIID riid, LPVOID FAR* ppv) {
	return S_OK;
}
HRESULT	_stdcall P_CoGetInstanceFromFile(COSERVERINFO * pServerInfo, CLSID * pClsid, IUnknown * punkOuter, DWORD dwClsCtx, DWORD grfMode, OLECHAR * pwszName, DWORD dwP_Count, MULTI_QI * pResults) {
	return S_OK;
}
HRESULT	_stdcall P_CoGetInstanceFromIStorage(COSERVERINFO * pServerInfo, CLSID * pClsid, IUnknown * punkOuter, DWORD dwClsCtx, struct IStorage * pstg, DWORD dwP_Count, MULTI_QI * pResults) {
	return S_OK;
}
HRESULT	_stdcall P_CoCreateInstanceEx(REFCLSID Clsid, IUnknown * punkOuter, DWORD dwClsCtx, COSERVERINFO * pServerInfo, DWORD dwP_Count, MULTI_QI * pResults) {
	return S_OK;
}
HRESULT	_stdcall P_CoGetCancelObject(DWORD dwThreadId, REFIID iid, void **ppUnk) {
	return S_OK;
}
HRESULT	_stdcall P_CoSetCancelObject(IUnknown *pUnk) {
	return S_OK;
}
HRESULT	_stdcall P_CoCancelCall(DWORD dwThreadId, ULONG ulTimeout) {
	return S_OK;
}
HRESULT	_stdcall P_CoTestCancel() {
	return S_OK;
}
HRESULT	_stdcall P_CoEnableCallCancellation(LPVOID pReserved) {
	return S_OK;
}
HRESULT	_stdcall P_CoDisableCallCancellation(LPVOID pReserved) {
	return S_OK;
}
HRESULT	_stdcall P_CoAllowSetForegroundWindow(IUnknown *pUnk, LPVOID lpvReserved) {
	return S_OK;
}
HRESULT	_stdcall P_DcomChannelSetHResult(LPVOID pvReserved, ULONG* pulReserved, HRESULT appsHR) {
	return S_OK;
}
HRESULT	_stdcall P_StringFromCLSID(REFCLSID rclsid, LPOLESTR FAR* lplpsz) {
	return S_OK;
}
HRESULT	_stdcall P_CLSIDFromString(LPOLESTR lpsz, LPCLSID pclsid) {
	return S_OK;
}
HRESULT	_stdcall P_StringFromIID(REFIID rclsid, LPOLESTR FAR* lplpsz) {
	return S_OK;
}
HRESULT	_stdcall P_IIDFromString(LPOLESTR lpsz, LPIID lpiid) {
	return S_OK;
}
BOOL	_stdcall P_CoIsOle1Class(REFCLSID rclsid) {
	return FALSE;
}
HRESULT	_stdcall P_ProgIDFromCLSID (REFCLSID clsid, LPOLESTR FAR* lplpszProgID) {
	return S_OK;
}
HRESULT	_stdcall P_CLSIDFromProgID (LPCOLESTR lpszProgID, LPCLSID lpclsid) {
	return S_OK;
}
HRESULT	_stdcall P_CLSIDFromProgIDEx (LPCOLESTR lpszProgID, LPCLSID lpclsid) {
	return S_OK;
}
int	_stdcall P_StringFromGUID2(REFGUID rguid, LPOLESTR lpsz, int cchMax) {
	return 0;
}
HRESULT	_stdcall P_CoCreateGuid(GUID FAR *pguid) {
	return S_OK;
}
BOOL	_stdcall P_CoFileTimeToDosDateTime(FILETIME FAR* lpFileTime, LPWORD lpDosDate, LPWORD lpDosTime) {
	return FALSE;
}
BOOL	_stdcall P_CoDosDateTimeToFileTime(WORD nDosDate, WORD nDosTime, FILETIME FAR* lpFileTime) {
	return FALSE;
}
HRESULT	_stdcall P_CoFileTimeNow(FILETIME FAR* lpFileTime) {
	return S_OK;
}
HRESULT	_stdcall P_CoRegisterMessageFilter(LPMESSAGEFILTER lpMessageFilter, LPMESSAGEFILTER FAR* lplpMessageFilter) {
	return S_OK;
}
HRESULT	_stdcall P_CoRegisterChannelHook(REFGUID ExtensionUuid, IChannelHook *pChannelHook) {
	return S_OK;
}
HRESULT	_stdcall P_CoWaitForMultipleHandles (DWORD dwFlags, DWORD dwTimeout, ULONG cHandles, LPHANDLE pHandles, LPDWORD lpdwindex) {
	return S_OK;
}
HRESULT	_stdcall P_CoInvalidateRemoteMachineBindings(LPOLESTR pszMachineName) {
	return S_OK;
}
HRESULT	_stdcall P_CoGetTreatAsClass(REFCLSID clsidOld, LPCLSID pClsidNew) {
	return S_OK;
}
HRESULT	_stdcall P_CoTreatAsClass(REFCLSID clsidOld, REFCLSID clsidNew) {
	return S_OK;
}
LPVOID	_stdcall P_CoTaskMemAlloc(SIZE_T cb) {
	return NULL;
}
LPVOID	_stdcall P_CoTaskMemRealloc(LPVOID pv, SIZE_T cb) {
	return NULL;
}
void	_stdcall P_CoTaskMemFree(LPVOID pv) {
}
HRESULT	_stdcall P_CreateDataAdviseHolder(LPDATAADVISEHOLDER FAR* ppDAHolder) {
	return S_OK;
}
HRESULT	_stdcall P_CreateDataCache(LPUNKNOWN pUnkOuter, REFCLSID rclsid, REFIID iid, LPVOID FAR* ppv) {
	return S_OK;
}
HRESULT	_stdcall P_StgCreateDocfile(const OLECHAR FAR* pwcsName, DWORD grfMode, DWORD reserved, IStorage FAR * FAR *ppstgOpen) {
	return S_OK;
}
HRESULT	_stdcall P_StgCreateDocfileOnILockBytes(ILockBytes FAR *plkbyt, DWORD grfMode, DWORD reserved, IStorage FAR * FAR *ppstgOpen) {
	return S_OK;
}
HRESULT	_stdcall P_StgOpenStorage(const OLECHAR FAR* pwcsName, IStorage FAR *pstgPriority, DWORD grfMode, SNB snbExclude, DWORD reserved, IStorage FAR * FAR *ppstgOpen) {
	return S_OK;
}
HRESULT	_stdcall P_StgOpenStorageOnILockBytes(ILockBytes FAR *plkbyt, IStorage FAR *pstgPriority, DWORD grfMode, SNB snbExclude, DWORD reserved, IStorage FAR * FAR *ppstgOpen) {
	return S_OK;
}
HRESULT	_stdcall P_StgIsStorageFile(const OLECHAR FAR* pwcsName) {
	return S_OK;
}
HRESULT	_stdcall P_StgIsStorageILockBytes(ILockBytes FAR* plkbyt) {
	return S_OK;
}
HRESULT	_stdcall P_StgSetTimes(OLECHAR const FAR* lpszName, FILETIME const FAR* pctime, FILETIME const FAR* patime, FILETIME const FAR* pmtime) {
	return S_OK;
}
HRESULT	_stdcall P_StgOpenAsyncDocfileOnIFillLockBytes(IFillLockBytes *pflb, DWORD grfMode, DWORD asyncFlags, IStorage **ppstgOpen) {
	return S_OK;
}
HRESULT	_stdcall P_StgGetIFillLockBytesOnILockBytes(ILockBytes *pilb, IFillLockBytes **ppflb) {
	return S_OK;
}
HRESULT	_stdcall P_StgGetIFillLockBytesOnFile(OLECHAR const *pwcsName, IFillLockBytes **ppflb) {
	return S_OK;
}
HRESULT	_stdcall P_StgOpenLayoutDocfile(OLECHAR const *pwcsDfName, DWORD grfMode, DWORD reserved, IStorage **ppstgOpen) {
	return S_OK;
}
HRESULT	_stdcall P_StgCreateStorageEx (const WCHAR* pwcsName, DWORD grfMode, DWORD stgfmt, DWORD grfAttrs, STGOPTIONS * pStgOptions, void * reserved, REFIID riid, void ** ppObjectOpen) {
	return S_OK;
}
HRESULT	_stdcall P_StgOpenStorageEx (const WCHAR* pwcsName, DWORD grfMode, DWORD stgfmt, DWORD grfAttrs, STGOPTIONS * pStgOptions, void * reserved, REFIID riid, void ** ppObjectOpen) {
	return S_OK;
}
HRESULT	_stdcall P_BindMoniker(LPMONIKER pmk, DWORD grfOpt, REFIID iidResult, LPVOID FAR* ppvResult) {
	return S_OK;
}
HRESULT	_stdcall P_CoInstall(IBindCtx * pbc, DWORD dwFlags, uCLSSPEC * pClassSpec, QUERYCONTEXT * pQuery, LPWSTR pszP_CodeBase) {
	return S_OK;
}
HRESULT	_stdcall P_CoGetObject(LPCWSTR pszName, BIND_OPTS *pBindOptions, REFIID riid, void **ppv) {
	return S_OK;
}
HRESULT	_stdcall P_MkParseDisplayName(LPBC pbc, LPCOLESTR szUserName, ULONG FAR * pchEaten, LPMONIKER FAR * ppmk) {
	return S_OK;
}
HRESULT	_stdcall P_MonikerRelativePathTo(LPMONIKER pmkSrc, LPMONIKER pmkDest, LPMONIKER FAR* ppmkRelPath, BOOL dwReserved) {
	return S_OK;
}
HRESULT	_stdcall P_MonikerP_CommonPrefixWith(LPMONIKER pmkThis, LPMONIKER pmkOther, LPMONIKER FAR* ppmkP_Common) {
	return S_OK;
}
HRESULT	_stdcall P_CreateBindCtx(DWORD reserved, LPBC FAR* ppbc) {
	return S_OK;
}
HRESULT	_stdcall P_CreateGenericP_Composite(LPMONIKER pmkFirst, LPMONIKER pmkRest, LPMONIKER FAR* ppmkP_Composite) {
	return S_OK;
}
HRESULT	_stdcall P_GetClassFile (LPCOLESTR szFilename, CLSID FAR* pclsid) {
	return S_OK;
}
HRESULT	_stdcall P_CreateClassMoniker(REFCLSID rclsid, LPMONIKER FAR* ppmk) {
	return S_OK;
}
HRESULT	_stdcall P_CreateFileMoniker(LPCOLESTR lpszPathName, LPMONIKER FAR* ppmk) {
	return S_OK;
}
HRESULT	_stdcall P_CreateItemMoniker(LPCOLESTR lpszDelim, LPCOLESTR lpszItem, LPMONIKER FAR* ppmk) {
	return S_OK;
}
HRESULT	_stdcall P_CreateAntiMoniker(LPMONIKER FAR* ppmk) {
	return S_OK;
}
HRESULT	_stdcall P_CreatePointerMoniker(LPUNKNOWN punk, LPMONIKER FAR* ppmk) {
	return S_OK;
}
HRESULT	_stdcall P_CreateObjrefMoniker(LPUNKNOWN punk, LPMONIKER FAR * ppmk) {
	return S_OK;
}
HRESULT	_stdcall P_GetRunningObjectTable(DWORD reserved, LPRUNNINGOBJECTTABLE FAR* pprot) {
	return S_OK;
}
HRESULT	_stdcall P_CreateStdProgressIndicator(HWND hwndParent, LPCOLESTR pszTitle, IBindStatusCallback * pIbscCaller, IBindStatusCallback ** ppIbsc) {
	return S_OK;
}
