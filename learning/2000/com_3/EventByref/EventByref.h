/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat Apr 28 04:25:55 2001
 */
/* Compiler settings for V:\Components\Lab\TestCom\EventByref\EventByref.idl:
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

#ifndef __EventByref_h__
#define __EventByref_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __ICaEventByref_FWD_DEFINED__
#define __ICaEventByref_FWD_DEFINED__
typedef interface ICaEventByref ICaEventByref;
#endif 	/* __ICaEventByref_FWD_DEFINED__ */


#ifndef __ICaEventByrefEvents_FWD_DEFINED__
#define __ICaEventByrefEvents_FWD_DEFINED__
typedef interface ICaEventByrefEvents ICaEventByrefEvents;
#endif 	/* __ICaEventByrefEvents_FWD_DEFINED__ */


#ifndef __CaEventByref_FWD_DEFINED__
#define __CaEventByref_FWD_DEFINED__

#ifdef __cplusplus
typedef class CaEventByref CaEventByref;
#else
typedef struct CaEventByref CaEventByref;
#endif /* __cplusplus */

#endif 	/* __CaEventByref_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );


#ifndef __EventByrefLib_LIBRARY_DEFINED__
#define __EventByrefLib_LIBRARY_DEFINED__

/* library EventByrefLib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_EventByrefLib;

#ifndef __ICaEventByref_INTERFACE_DEFINED__
#define __ICaEventByref_INTERFACE_DEFINED__

/* interface ICaEventByref */
/* [object][oleautomation][dual][uuid] */


EXTERN_C const IID IID_ICaEventByref;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4341-FFB0-0001-486954656368")
    ICaEventByref : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_prop1(
            /* [retval][out] */ long __RPC_FAR *ret) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_prop1(
            /* [in] */ long newlong) = 0;

        virtual HRESULT STDMETHODCALLTYPE makeEventTest( void) = 0;

        virtual HRESULT STDMETHODCALLTYPE makeEvent1( void) = 0;

        virtual HRESULT STDMETHODCALLTYPE makeEvent2( void) = 0;

    };

#else 	/* C style interface */

    typedef struct ICaEventByrefVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICaEventByref __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICaEventByref __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICaEventByref __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICaEventByref __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICaEventByref __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICaEventByref __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICaEventByref __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_prop1 )(
            ICaEventByref __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *ret);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_prop1 )(
            ICaEventByref __RPC_FAR * This,
            /* [in] */ long newlong);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *makeEventTest )(
            ICaEventByref __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *makeEvent1 )(
            ICaEventByref __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *makeEvent2 )(
            ICaEventByref __RPC_FAR * This);

        END_INTERFACE
    } ICaEventByrefVtbl;

    interface ICaEventByref
    {
        CONST_VTBL struct ICaEventByrefVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICaEventByref_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICaEventByref_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICaEventByref_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICaEventByref_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICaEventByref_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICaEventByref_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICaEventByref_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICaEventByref_get_prop1(This,ret)	\
    (This)->lpVtbl -> get_prop1(This,ret)

#define ICaEventByref_put_prop1(This,newlong)	\
    (This)->lpVtbl -> put_prop1(This,newlong)

#define ICaEventByref_makeEventTest(This)	\
    (This)->lpVtbl -> makeEventTest(This)

#define ICaEventByref_makeEvent1(This)	\
    (This)->lpVtbl -> makeEvent1(This)

#define ICaEventByref_makeEvent2(This)	\
    (This)->lpVtbl -> makeEvent2(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICaEventByref_get_prop1_Proxy(
    ICaEventByref __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *ret);


void __RPC_STUB ICaEventByref_get_prop1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE ICaEventByref_put_prop1_Proxy(
    ICaEventByref __RPC_FAR * This,
    /* [in] */ long newlong);


void __RPC_STUB ICaEventByref_put_prop1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICaEventByref_makeEventTest_Proxy(
    ICaEventByref __RPC_FAR * This);


void __RPC_STUB ICaEventByref_makeEventTest_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICaEventByref_makeEvent1_Proxy(
    ICaEventByref __RPC_FAR * This);


void __RPC_STUB ICaEventByref_makeEvent1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICaEventByref_makeEvent2_Proxy(
    ICaEventByref __RPC_FAR * This);


void __RPC_STUB ICaEventByref_makeEvent2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICaEventByref_INTERFACE_DEFINED__ */


#ifndef __ICaEventByrefEvents_DISPINTERFACE_DEFINED__
#define __ICaEventByrefEvents_DISPINTERFACE_DEFINED__

/* dispinterface ICaEventByrefEvents */
/* [uuid] */


EXTERN_C const IID DIID_ICaEventByrefEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4341-FFB0-0017-486954656368")
    ICaEventByrefEvents : public IDispatch
    {
    };

#else 	/* C style interface */

    typedef struct ICaEventByrefEventsVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICaEventByrefEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICaEventByrefEvents __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICaEventByrefEvents __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICaEventByrefEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICaEventByrefEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICaEventByrefEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICaEventByrefEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } ICaEventByrefEventsVtbl;

    interface ICaEventByrefEvents
    {
        CONST_VTBL struct ICaEventByrefEventsVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICaEventByrefEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICaEventByrefEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICaEventByrefEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICaEventByrefEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICaEventByrefEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICaEventByrefEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICaEventByrefEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ICaEventByrefEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CaEventByref;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4341-FFB0-0002-486954656368")
CaEventByref;
#endif
#endif /* __EventByrefLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
