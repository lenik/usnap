/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Nov 11 00:02:34 2001
 */
/* Compiler settings for C:\S\develop\General\temp1\g1\atl1\atl1.idl:
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

#ifndef __atl1_h__
#define __atl1_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __Ic1_FWD_DEFINED__
#define __Ic1_FWD_DEFINED__
typedef interface Ic1 Ic1;
#endif 	/* __Ic1_FWD_DEFINED__ */


#ifndef __c1_FWD_DEFINED__
#define __c1_FWD_DEFINED__

#ifdef __cplusplus
typedef class c1 c1;
#else
typedef struct c1 c1;
#endif /* __cplusplus */

#endif 	/* __c1_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );

#ifndef __Ic1_INTERFACE_DEFINED__
#define __Ic1_INTERFACE_DEFINED__

/* interface Ic1 */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_Ic1;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("819833DA-E706-44D1-853B-D1EC4B0DF9C8")
    Ic1 : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE f1( void) = 0;

    };

#else 	/* C style interface */

    typedef struct Ic1Vtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            Ic1 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            Ic1 __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            Ic1 __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            Ic1 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            Ic1 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            Ic1 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            Ic1 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *f1 )(
            Ic1 __RPC_FAR * This);

        END_INTERFACE
    } Ic1Vtbl;

    interface Ic1
    {
        CONST_VTBL struct Ic1Vtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define Ic1_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define Ic1_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define Ic1_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define Ic1_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define Ic1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define Ic1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define Ic1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define Ic1_f1(This)	\
    (This)->lpVtbl -> f1(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Ic1_f1_Proxy(
    Ic1 __RPC_FAR * This);


void __RPC_STUB Ic1_f1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __Ic1_INTERFACE_DEFINED__ */



#ifndef __ATL1Lib_LIBRARY_DEFINED__
#define __ATL1Lib_LIBRARY_DEFINED__

/* library ATL1Lib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_ATL1Lib;

EXTERN_C const CLSID CLSID_c1;

#ifdef __cplusplus

class DECLSPEC_UUID("F6480BDA-60AD-464B-A764-C64F8B7E4801")
c1;
#endif
#endif /* __ATL1Lib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
