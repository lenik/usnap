/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Sep 14 21:34:12 2003
 */
/* Compiler settings for C:\s_prjs\Data Rescuer\modules\UtFiles\UtFiles.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __UtFiles_h__
#define __UtFiles_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __IUt1_FWD_DEFINED__
#define __IUt1_FWD_DEFINED__
typedef interface IUt1 IUt1;
#endif 	/* __IUt1_FWD_DEFINED__ */


#ifndef __Ut1_FWD_DEFINED__
#define __Ut1_FWD_DEFINED__

#ifdef __cplusplus
typedef class Ut1 Ut1;
#else
typedef struct Ut1 Ut1;
#endif /* __cplusplus */

#endif 	/* __Ut1_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );

#ifndef __IUt1_INTERFACE_DEFINED__
#define __IUt1_INTERFACE_DEFINED__

/* interface IUt1 */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IUt1;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("39C5D144-D3B0-488C-B462-44A1156E0714")
    IUt1 : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDragFileNames(
            /* [in] */ IDataObject __RPC_FAR *pData,
            /* [in] */ int Index,
            /* [retval][out] */ BSTR __RPC_FAR *pName) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDragFileNamesCount(
            /* [in] */ IDataObject __RPC_FAR *pData,
            /* [retval][out] */ int __RPC_FAR *pVal) = 0;

    };

#else 	/* C style interface */

    typedef struct IUt1Vtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IUt1 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IUt1 __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IUt1 __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IUt1 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IUt1 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IUt1 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IUt1 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDragFileNames )(
            IUt1 __RPC_FAR * This,
            /* [in] */ IDataObject __RPC_FAR *pData,
            /* [in] */ int Index,
            /* [retval][out] */ BSTR __RPC_FAR *pName);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDragFileNamesCount )(
            IUt1 __RPC_FAR * This,
            /* [in] */ IDataObject __RPC_FAR *pData,
            /* [retval][out] */ int __RPC_FAR *pVal);

        END_INTERFACE
    } IUt1Vtbl;

    interface IUt1
    {
        CONST_VTBL struct IUt1Vtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IUt1_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUt1_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUt1_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IUt1_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IUt1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IUt1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IUt1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IUt1_GetDragFileNames(This,pData,Index,pName)	\
    (This)->lpVtbl -> GetDragFileNames(This,pData,Index,pName)

#define IUt1_GetDragFileNamesCount(This,pData,pVal)	\
    (This)->lpVtbl -> GetDragFileNamesCount(This,pData,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IUt1_GetDragFileNames_Proxy(
    IUt1 __RPC_FAR * This,
    /* [in] */ IDataObject __RPC_FAR *pData,
    /* [in] */ int Index,
    /* [retval][out] */ BSTR __RPC_FAR *pName);


void __RPC_STUB IUt1_GetDragFileNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IUt1_GetDragFileNamesCount_Proxy(
    IUt1 __RPC_FAR * This,
    /* [in] */ IDataObject __RPC_FAR *pData,
    /* [retval][out] */ int __RPC_FAR *pVal);


void __RPC_STUB IUt1_GetDragFileNamesCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IUt1_INTERFACE_DEFINED__ */



#ifndef __UtLib_Files_LIBRARY_DEFINED__
#define __UtLib_Files_LIBRARY_DEFINED__

/* library UtLib_Files */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_UtLib_Files;

EXTERN_C const CLSID CLSID_Ut1;

#ifdef __cplusplus

class DECLSPEC_UUID("FDB75471-8CFF-40F0-A943-6B3502E83A70")
Ut1;
#endif
#endif /* __UtLib_Files_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * );
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
