/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Jul 28 20:52:51 2003
 */
/* Compiler settings for C:\s_prjs\Data Rescuer\modules\HexEditCtl\cat\cat.idl:
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

#ifndef __cat_h__
#define __cat_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __ICat002_FWD_DEFINED__
#define __ICat002_FWD_DEFINED__
typedef interface ICat002 ICat002;
#endif 	/* __ICat002_FWD_DEFINED__ */


#ifndef __Cat002_FWD_DEFINED__
#define __Cat002_FWD_DEFINED__

#ifdef __cplusplus
typedef class Cat002 Cat002;
#else
typedef struct Cat002 Cat002;
#endif /* __cplusplus */

#endif 	/* __Cat002_FWD_DEFINED__ */


#ifndef __CatPropPage_FWD_DEFINED__
#define __CatPropPage_FWD_DEFINED__

#ifdef __cplusplus
typedef class CatPropPage CatPropPage;
#else
typedef struct CatPropPage CatPropPage;
#endif /* __cplusplus */

#endif 	/* __CatPropPage_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );

#ifndef __ICat002_INTERFACE_DEFINED__
#define __ICat002_INTERFACE_DEFINED__

/* interface ICat002 */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_ICat002;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("406C16E3-F287-410C-B8F9-B3C9E091D254")
    ICat002 : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRawObject(
            long __RPC_FAR *pRawAddr) = 0;

    };

#else 	/* C style interface */

    typedef struct ICat002Vtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICat002 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICat002 __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICat002 __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICat002 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICat002 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICat002 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICat002 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRawObject )(
            ICat002 __RPC_FAR * This,
            long __RPC_FAR *pRawAddr);

        END_INTERFACE
    } ICat002Vtbl;

    interface ICat002
    {
        CONST_VTBL struct ICat002Vtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICat002_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICat002_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICat002_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICat002_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICat002_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICat002_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICat002_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICat002_GetRawObject(This,pRawAddr)	\
    (This)->lpVtbl -> GetRawObject(This,pRawAddr)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICat002_GetRawObject_Proxy(
    ICat002 __RPC_FAR * This,
    long __RPC_FAR *pRawAddr);


void __RPC_STUB ICat002_GetRawObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICat002_INTERFACE_DEFINED__ */



#ifndef __CATLib_LIBRARY_DEFINED__
#define __CATLib_LIBRARY_DEFINED__

/* library CATLib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_CATLib;

EXTERN_C const CLSID CLSID_Cat002;

#ifdef __cplusplus

class DECLSPEC_UUID("2D21A1FB-35CD-4AC2-81CC-4C2C0DA60B16")
Cat002;
#endif

EXTERN_C const CLSID CLSID_CatPropPage;

#ifdef __cplusplus

class DECLSPEC_UUID("3F4FA292-0594-4EF6-819A-12B167C7FE8D")
CatPropPage;
#endif
#endif /* __CATLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
