/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Apr 26 22:22:22 2001
 */
/* Compiler settings for V:\Components\Lab\TestCom\PureCOM\PureCOM.idl:
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

#ifndef __PureCOM_h__
#define __PureCOM_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __ICaPureDog_FWD_DEFINED__
#define __ICaPureDog_FWD_DEFINED__
typedef interface ICaPureDog ICaPureDog;
#endif 	/* __ICaPureDog_FWD_DEFINED__ */


#ifndef __ICaPureDogEvents_FWD_DEFINED__
#define __ICaPureDogEvents_FWD_DEFINED__
typedef interface ICaPureDogEvents ICaPureDogEvents;
#endif 	/* __ICaPureDogEvents_FWD_DEFINED__ */


#ifndef __CaPureDog_FWD_DEFINED__
#define __CaPureDog_FWD_DEFINED__

#ifdef __cplusplus
typedef class CaPureDog CaPureDog;
#else
typedef struct CaPureDog CaPureDog;
#endif /* __cplusplus */

#endif 	/* __CaPureDog_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );


#ifndef __CaPureCOMLib_LIBRARY_DEFINED__
#define __CaPureCOMLib_LIBRARY_DEFINED__

/* library CaPureCOMLib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_CaPureCOMLib;

#ifndef __ICaPureDog_INTERFACE_DEFINED__
#define __ICaPureDog_INTERFACE_DEFINED__

/* interface ICaPureDog */
/* [object][helpstring][oleautomation][dual][uuid] */


EXTERN_C const IID IID_ICaPureDog;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4341-FFC0-0001-486954656368")
    ICaPureDog : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE shout( void) = 0;

    };

#else 	/* C style interface */

    typedef struct ICaPureDogVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICaPureDog __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICaPureDog __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICaPureDog __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICaPureDog __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICaPureDog __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICaPureDog __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICaPureDog __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *shout )(
            ICaPureDog __RPC_FAR * This);

        END_INTERFACE
    } ICaPureDogVtbl;

    interface ICaPureDog
    {
        CONST_VTBL struct ICaPureDogVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICaPureDog_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICaPureDog_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICaPureDog_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICaPureDog_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICaPureDog_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICaPureDog_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICaPureDog_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICaPureDog_shout(This)	\
    (This)->lpVtbl -> shout(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ICaPureDog_shout_Proxy(
    ICaPureDog __RPC_FAR * This);


void __RPC_STUB ICaPureDog_shout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICaPureDog_INTERFACE_DEFINED__ */


#ifndef __ICaPureDogEvents_DISPINTERFACE_DEFINED__
#define __ICaPureDogEvents_DISPINTERFACE_DEFINED__

/* dispinterface ICaPureDogEvents */
/* [helpstring][uuid] */


EXTERN_C const IID DIID_ICaPureDogEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4341-FFC0-0017-486954656368")
    ICaPureDogEvents : public IDispatch
    {
    };

#else 	/* C style interface */

    typedef struct ICaPureDogEventsVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICaPureDogEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICaPureDogEvents __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICaPureDogEvents __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICaPureDogEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICaPureDogEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICaPureDogEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICaPureDogEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } ICaPureDogEventsVtbl;

    interface ICaPureDogEvents
    {
        CONST_VTBL struct ICaPureDogEventsVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICaPureDogEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICaPureDogEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICaPureDogEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICaPureDogEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICaPureDogEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICaPureDogEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICaPureDogEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ICaPureDogEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CaPureDog;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4341-FFC0-0002-486954656368")
CaPureDog;
#endif
#endif /* __CaPureCOMLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
