/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Nov 18 22:33:23 2002
 */
/* Compiler settings for C:\s\l\campoAccelerate\ComTool\ComTool.idl:
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

#ifndef __ComTool_h__
#define __ComTool_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __ICaCTools_FWD_DEFINED__
#define __ICaCTools_FWD_DEFINED__
typedef interface ICaCTools ICaCTools;
#endif 	/* __ICaCTools_FWD_DEFINED__ */


#ifndef __ICaCSimulator_FWD_DEFINED__
#define __ICaCSimulator_FWD_DEFINED__
typedef interface ICaCSimulator ICaCSimulator;
#endif 	/* __ICaCSimulator_FWD_DEFINED__ */


#ifndef __ICaCPacker_FWD_DEFINED__
#define __ICaCPacker_FWD_DEFINED__
typedef interface ICaCPacker ICaCPacker;
#endif 	/* __ICaCPacker_FWD_DEFINED__ */


#ifndef __ICaCProxyUnknown_FWD_DEFINED__
#define __ICaCProxyUnknown_FWD_DEFINED__
typedef interface ICaCProxyUnknown ICaCProxyUnknown;
#endif 	/* __ICaCProxyUnknown_FWD_DEFINED__ */


#ifndef __ICaCProxyDispatch_FWD_DEFINED__
#define __ICaCProxyDispatch_FWD_DEFINED__
typedef interface ICaCProxyDispatch ICaCProxyDispatch;
#endif 	/* __ICaCProxyDispatch_FWD_DEFINED__ */


#ifndef __CaCTools_FWD_DEFINED__
#define __CaCTools_FWD_DEFINED__

#ifdef __cplusplus
typedef class CaCTools CaCTools;
#else
typedef struct CaCTools CaCTools;
#endif /* __cplusplus */

#endif 	/* __CaCTools_FWD_DEFINED__ */


#ifndef __CaCSimulator_FWD_DEFINED__
#define __CaCSimulator_FWD_DEFINED__

#ifdef __cplusplus
typedef class CaCSimulator CaCSimulator;
#else
typedef struct CaCSimulator CaCSimulator;
#endif /* __cplusplus */

#endif 	/* __CaCSimulator_FWD_DEFINED__ */


#ifndef __CaCPacker_FWD_DEFINED__
#define __CaCPacker_FWD_DEFINED__

#ifdef __cplusplus
typedef class CaCPacker CaCPacker;
#else
typedef struct CaCPacker CaCPacker;
#endif /* __cplusplus */

#endif 	/* __CaCPacker_FWD_DEFINED__ */


#ifndef __CaCProxyUnknown_FWD_DEFINED__
#define __CaCProxyUnknown_FWD_DEFINED__

#ifdef __cplusplus
typedef class CaCProxyUnknown CaCProxyUnknown;
#else
typedef struct CaCProxyUnknown CaCProxyUnknown;
#endif /* __cplusplus */

#endif 	/* __CaCProxyUnknown_FWD_DEFINED__ */


#ifndef __CaCProxyDispatch_FWD_DEFINED__
#define __CaCProxyDispatch_FWD_DEFINED__

#ifdef __cplusplus
typedef class CaCProxyDispatch CaCProxyDispatch;
#else
typedef struct CaCProxyDispatch CaCProxyDispatch;
#endif /* __cplusplus */

#endif 	/* __CaCProxyDispatch_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );

/* interface __MIDL_itf_ComTool_0000 */
/* [local] */








extern RPC_IF_HANDLE __MIDL_itf_ComTool_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ComTool_0000_v0_0_s_ifspec;

#ifndef __ICaCTools_INTERFACE_DEFINED__
#define __ICaCTools_INTERFACE_DEFINED__

/* interface ICaCTools */
/* [object][helpstring][oleautomation][dual][uuid] */


EXTERN_C const IID IID_ICaCTools;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4341-0100-0001-486954656368")
    ICaCTools : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_progid(
            /* [retval][out] */ BSTR __RPC_FAR *ret) = 0;

        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_progid(
            /* [in] */ BSTR progid) = 0;

        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_clsid(
            /* [retval][out] */ BSTR __RPC_FAR *ret) = 0;

        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_clsid(
            /* [in] */ BSTR clsid) = 0;

        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_iid(
            /* [retval][out] */ BSTR __RPC_FAR *ret) = 0;

        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_iid(
            /* [in] */ BSTR iid) = 0;

        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE createObject(
            /* [defaultvalue][in] */ BOOL forceCreate,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *obj) = 0;

        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE createObject2(
            /* [defaultvalue][in] */ BOOL forceCreate,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *obj) = 0;

        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE createObjectByProgid(
            /* [in] */ BSTR progid,
            /* [defaultvalue][in] */ BOOL forceCreate,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *obj) = 0;

        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE createObjectByProgid2(
            /* [in] */ BSTR progid,
            /* [in] */ BSTR iface,
            /* [defaultvalue][in] */ BOOL forceCreate,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *obj) = 0;

        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE createObjectByClsid(
            /* [in] */ BSTR clsid,
            /* [defaultvalue][in] */ BOOL forceCreate,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *obj) = 0;

        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE createObjectByClsid2(
            /* [in] */ BSTR clsid,
            /* [in] */ BSTR iid,
            /* [defaultvalue][in] */ BOOL forceCreate,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *obj) = 0;

        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_reference(
            /* [ref][in] */ IUnknown __RPC_FAR *obj,
            /* [retval][out] */ LONG __RPC_FAR *ret) = 0;

        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE forceAddRef(
            /* [in] */ IUnknown __RPC_FAR *obj,
            /* [retval][out] */ LONG __RPC_FAR *ret) = 0;

        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE forceRelease(
            /* [in] */ IUnknown __RPC_FAR *obj,
            /* [retval][out] */ LONG __RPC_FAR *ret) = 0;

        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE forceQueryInterface(
            /* [in] */ IUnknown __RPC_FAR *obj,
            /* [in] */ BSTR iid,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppv,
            /* [retval][out] */ HRESULT __RPC_FAR *ret) = 0;

        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE forceGetTypeInfoCount(
            /* [in] */ IDispatch __RPC_FAR *obj,
            /* [retval][out] */ LONG __RPC_FAR *ret) = 0;

        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE forceGetTypeInfo(
            /* [in] */ IDispatch __RPC_FAR *obj,
            /* [in] */ LONG iTInfo,
            /* [in] */ LONG Lcid,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ret) = 0;

        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE forceGetIDsOfNames(
            /* [in] */ IDispatch __RPC_FAR *obj,
            /* [in] */ BSTR riid,
            /* [in] */ BSTR __RPC_FAR *rgszNames,
            /* [in] */ LONG cNames,
            /* [in] */ LONG Lcid,
            /* [retval][out] */ LONG __RPC_FAR *rgDispId) = 0;

        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE forceGetIDOfName(
            /* [in] */ IDispatch __RPC_FAR *obj,
            /* [in] */ BSTR riid,
            /* [in] */ BSTR rgszNames,
            /* [in] */ LONG Lcid,
            /* [retval][out] */ LONG __RPC_FAR *rgDispId) = 0;

    };

#else 	/* C style interface */

    typedef struct ICaCToolsVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICaCTools __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICaCTools __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICaCTools __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICaCTools __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICaCTools __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICaCTools __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICaCTools __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_progid )(
            ICaCTools __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *ret);

        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_progid )(
            ICaCTools __RPC_FAR * This,
            /* [in] */ BSTR progid);

        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_clsid )(
            ICaCTools __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *ret);

        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_clsid )(
            ICaCTools __RPC_FAR * This,
            /* [in] */ BSTR clsid);

        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_iid )(
            ICaCTools __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *ret);

        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_iid )(
            ICaCTools __RPC_FAR * This,
            /* [in] */ BSTR iid);

        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *createObject )(
            ICaCTools __RPC_FAR * This,
            /* [defaultvalue][in] */ BOOL forceCreate,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *obj);

        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *createObject2 )(
            ICaCTools __RPC_FAR * This,
            /* [defaultvalue][in] */ BOOL forceCreate,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *obj);

        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *createObjectByProgid )(
            ICaCTools __RPC_FAR * This,
            /* [in] */ BSTR progid,
            /* [defaultvalue][in] */ BOOL forceCreate,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *obj);

        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *createObjectByProgid2 )(
            ICaCTools __RPC_FAR * This,
            /* [in] */ BSTR progid,
            /* [in] */ BSTR iface,
            /* [defaultvalue][in] */ BOOL forceCreate,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *obj);

        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *createObjectByClsid )(
            ICaCTools __RPC_FAR * This,
            /* [in] */ BSTR clsid,
            /* [defaultvalue][in] */ BOOL forceCreate,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *obj);

        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *createObjectByClsid2 )(
            ICaCTools __RPC_FAR * This,
            /* [in] */ BSTR clsid,
            /* [in] */ BSTR iid,
            /* [defaultvalue][in] */ BOOL forceCreate,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *obj);

        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_reference )(
            ICaCTools __RPC_FAR * This,
            /* [ref][in] */ IUnknown __RPC_FAR *obj,
            /* [retval][out] */ LONG __RPC_FAR *ret);

        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *forceAddRef )(
            ICaCTools __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *obj,
            /* [retval][out] */ LONG __RPC_FAR *ret);

        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *forceRelease )(
            ICaCTools __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *obj,
            /* [retval][out] */ LONG __RPC_FAR *ret);

        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *forceQueryInterface )(
            ICaCTools __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *obj,
            /* [in] */ BSTR iid,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppv,
            /* [retval][out] */ HRESULT __RPC_FAR *ret);

        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *forceGetTypeInfoCount )(
            ICaCTools __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *obj,
            /* [retval][out] */ LONG __RPC_FAR *ret);

        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *forceGetTypeInfo )(
            ICaCTools __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *obj,
            /* [in] */ LONG iTInfo,
            /* [in] */ LONG Lcid,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ret);

        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *forceGetIDsOfNames )(
            ICaCTools __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *obj,
            /* [in] */ BSTR riid,
            /* [in] */ BSTR __RPC_FAR *rgszNames,
            /* [in] */ LONG cNames,
            /* [in] */ LONG Lcid,
            /* [retval][out] */ LONG __RPC_FAR *rgDispId);

        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *forceGetIDOfName )(
            ICaCTools __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *obj,
            /* [in] */ BSTR riid,
            /* [in] */ BSTR rgszNames,
            /* [in] */ LONG Lcid,
            /* [retval][out] */ LONG __RPC_FAR *rgDispId);

        END_INTERFACE
    } ICaCToolsVtbl;

    interface ICaCTools
    {
        CONST_VTBL struct ICaCToolsVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICaCTools_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICaCTools_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICaCTools_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICaCTools_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICaCTools_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICaCTools_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICaCTools_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICaCTools_get_progid(This,ret)	\
    (This)->lpVtbl -> get_progid(This,ret)

#define ICaCTools_put_progid(This,progid)	\
    (This)->lpVtbl -> put_progid(This,progid)

#define ICaCTools_get_clsid(This,ret)	\
    (This)->lpVtbl -> get_clsid(This,ret)

#define ICaCTools_put_clsid(This,clsid)	\
    (This)->lpVtbl -> put_clsid(This,clsid)

#define ICaCTools_get_iid(This,ret)	\
    (This)->lpVtbl -> get_iid(This,ret)

#define ICaCTools_put_iid(This,iid)	\
    (This)->lpVtbl -> put_iid(This,iid)

#define ICaCTools_createObject(This,forceCreate,obj)	\
    (This)->lpVtbl -> createObject(This,forceCreate,obj)

#define ICaCTools_createObject2(This,forceCreate,obj)	\
    (This)->lpVtbl -> createObject2(This,forceCreate,obj)

#define ICaCTools_createObjectByProgid(This,progid,forceCreate,obj)	\
    (This)->lpVtbl -> createObjectByProgid(This,progid,forceCreate,obj)

#define ICaCTools_createObjectByProgid2(This,progid,iface,forceCreate,obj)	\
    (This)->lpVtbl -> createObjectByProgid2(This,progid,iface,forceCreate,obj)

#define ICaCTools_createObjectByClsid(This,clsid,forceCreate,obj)	\
    (This)->lpVtbl -> createObjectByClsid(This,clsid,forceCreate,obj)

#define ICaCTools_createObjectByClsid2(This,clsid,iid,forceCreate,obj)	\
    (This)->lpVtbl -> createObjectByClsid2(This,clsid,iid,forceCreate,obj)

#define ICaCTools_get_reference(This,obj,ret)	\
    (This)->lpVtbl -> get_reference(This,obj,ret)

#define ICaCTools_forceAddRef(This,obj,ret)	\
    (This)->lpVtbl -> forceAddRef(This,obj,ret)

#define ICaCTools_forceRelease(This,obj,ret)	\
    (This)->lpVtbl -> forceRelease(This,obj,ret)

#define ICaCTools_forceQueryInterface(This,obj,iid,ppv,ret)	\
    (This)->lpVtbl -> forceQueryInterface(This,obj,iid,ppv,ret)

#define ICaCTools_forceGetTypeInfoCount(This,obj,ret)	\
    (This)->lpVtbl -> forceGetTypeInfoCount(This,obj,ret)

#define ICaCTools_forceGetTypeInfo(This,obj,iTInfo,Lcid,ret)	\
    (This)->lpVtbl -> forceGetTypeInfo(This,obj,iTInfo,Lcid,ret)

#define ICaCTools_forceGetIDsOfNames(This,obj,riid,rgszNames,cNames,Lcid,rgDispId)	\
    (This)->lpVtbl -> forceGetIDsOfNames(This,obj,riid,rgszNames,cNames,Lcid,rgDispId)

#define ICaCTools_forceGetIDOfName(This,obj,riid,rgszNames,Lcid,rgDispId)	\
    (This)->lpVtbl -> forceGetIDOfName(This,obj,riid,rgszNames,Lcid,rgDispId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ICaCTools_get_progid_Proxy(
    ICaCTools __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *ret);


void __RPC_STUB ICaCTools_get_progid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE ICaCTools_put_progid_Proxy(
    ICaCTools __RPC_FAR * This,
    /* [in] */ BSTR progid);


void __RPC_STUB ICaCTools_put_progid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ICaCTools_get_clsid_Proxy(
    ICaCTools __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *ret);


void __RPC_STUB ICaCTools_get_clsid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE ICaCTools_put_clsid_Proxy(
    ICaCTools __RPC_FAR * This,
    /* [in] */ BSTR clsid);


void __RPC_STUB ICaCTools_put_clsid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ICaCTools_get_iid_Proxy(
    ICaCTools __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *ret);


void __RPC_STUB ICaCTools_get_iid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE ICaCTools_put_iid_Proxy(
    ICaCTools __RPC_FAR * This,
    /* [in] */ BSTR iid);


void __RPC_STUB ICaCTools_put_iid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICaCTools_createObject_Proxy(
    ICaCTools __RPC_FAR * This,
    /* [defaultvalue][in] */ BOOL forceCreate,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *obj);


void __RPC_STUB ICaCTools_createObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICaCTools_createObject2_Proxy(
    ICaCTools __RPC_FAR * This,
    /* [defaultvalue][in] */ BOOL forceCreate,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *obj);


void __RPC_STUB ICaCTools_createObject2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICaCTools_createObjectByProgid_Proxy(
    ICaCTools __RPC_FAR * This,
    /* [in] */ BSTR progid,
    /* [defaultvalue][in] */ BOOL forceCreate,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *obj);


void __RPC_STUB ICaCTools_createObjectByProgid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICaCTools_createObjectByProgid2_Proxy(
    ICaCTools __RPC_FAR * This,
    /* [in] */ BSTR progid,
    /* [in] */ BSTR iface,
    /* [defaultvalue][in] */ BOOL forceCreate,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *obj);


void __RPC_STUB ICaCTools_createObjectByProgid2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICaCTools_createObjectByClsid_Proxy(
    ICaCTools __RPC_FAR * This,
    /* [in] */ BSTR clsid,
    /* [defaultvalue][in] */ BOOL forceCreate,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *obj);


void __RPC_STUB ICaCTools_createObjectByClsid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICaCTools_createObjectByClsid2_Proxy(
    ICaCTools __RPC_FAR * This,
    /* [in] */ BSTR clsid,
    /* [in] */ BSTR iid,
    /* [defaultvalue][in] */ BOOL forceCreate,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *obj);


void __RPC_STUB ICaCTools_createObjectByClsid2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ICaCTools_get_reference_Proxy(
    ICaCTools __RPC_FAR * This,
    /* [ref][in] */ IUnknown __RPC_FAR *obj,
    /* [retval][out] */ LONG __RPC_FAR *ret);


void __RPC_STUB ICaCTools_get_reference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICaCTools_forceAddRef_Proxy(
    ICaCTools __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *obj,
    /* [retval][out] */ LONG __RPC_FAR *ret);


void __RPC_STUB ICaCTools_forceAddRef_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICaCTools_forceRelease_Proxy(
    ICaCTools __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *obj,
    /* [retval][out] */ LONG __RPC_FAR *ret);


void __RPC_STUB ICaCTools_forceRelease_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICaCTools_forceQueryInterface_Proxy(
    ICaCTools __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *obj,
    /* [in] */ BSTR iid,
    /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppv,
    /* [retval][out] */ HRESULT __RPC_FAR *ret);


void __RPC_STUB ICaCTools_forceQueryInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICaCTools_forceGetTypeInfoCount_Proxy(
    ICaCTools __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *obj,
    /* [retval][out] */ LONG __RPC_FAR *ret);


void __RPC_STUB ICaCTools_forceGetTypeInfoCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICaCTools_forceGetTypeInfo_Proxy(
    ICaCTools __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *obj,
    /* [in] */ LONG iTInfo,
    /* [in] */ LONG Lcid,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ret);


void __RPC_STUB ICaCTools_forceGetTypeInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICaCTools_forceGetIDsOfNames_Proxy(
    ICaCTools __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *obj,
    /* [in] */ BSTR riid,
    /* [in] */ BSTR __RPC_FAR *rgszNames,
    /* [in] */ LONG cNames,
    /* [in] */ LONG Lcid,
    /* [retval][out] */ LONG __RPC_FAR *rgDispId);


void __RPC_STUB ICaCTools_forceGetIDsOfNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICaCTools_forceGetIDOfName_Proxy(
    ICaCTools __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *obj,
    /* [in] */ BSTR riid,
    /* [in] */ BSTR rgszNames,
    /* [in] */ LONG Lcid,
    /* [retval][out] */ LONG __RPC_FAR *rgDispId);


void __RPC_STUB ICaCTools_forceGetIDOfName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICaCTools_INTERFACE_DEFINED__ */


#ifndef __ICaCSimulator_INTERFACE_DEFINED__
#define __ICaCSimulator_INTERFACE_DEFINED__

/* interface ICaCSimulator */
/* [object][helpstring][oleautomation][dual][uuid] */


EXTERN_C const IID IID_ICaCSimulator;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4341-0101-0001-486954656368")
    ICaCSimulator : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE simulate(
            /* [in] */ IDispatch __RPC_FAR *simulate_object) = 0;

    };

#else 	/* C style interface */

    typedef struct ICaCSimulatorVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICaCSimulator __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICaCSimulator __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICaCSimulator __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICaCSimulator __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICaCSimulator __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICaCSimulator __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICaCSimulator __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *simulate )(
            ICaCSimulator __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *simulate_object);

        END_INTERFACE
    } ICaCSimulatorVtbl;

    interface ICaCSimulator
    {
        CONST_VTBL struct ICaCSimulatorVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICaCSimulator_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICaCSimulator_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICaCSimulator_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICaCSimulator_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICaCSimulator_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICaCSimulator_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICaCSimulator_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICaCSimulator_simulate(This,simulate_object)	\
    (This)->lpVtbl -> simulate(This,simulate_object)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ICaCSimulator_simulate_Proxy(
    ICaCSimulator __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *simulate_object);


void __RPC_STUB ICaCSimulator_simulate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICaCSimulator_INTERFACE_DEFINED__ */


#ifndef __ICaCPacker_INTERFACE_DEFINED__
#define __ICaCPacker_INTERFACE_DEFINED__

/* interface ICaCPacker */
/* [object][helpstring][oleautomation][dual][uuid] */


EXTERN_C const IID IID_ICaCPacker;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4341-0102-0001-486954656368")
    ICaCPacker : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_members(
            /* [in] */ int index,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ret) = 0;

        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_members(
            /* [in] */ int index,
            /* [in] */ IDispatch __RPC_FAR *replace_pack_object) = 0;

        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_count(
            /* [retval][out] */ int __RPC_FAR *ret) = 0;

        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE pack(
            /* [in] */ IDispatch __RPC_FAR *pack_object) = 0;

        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE unpack(
            /* [in] */ IDispatch __RPC_FAR *unpack_object,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ret) = 0;

    };

#else 	/* C style interface */

    typedef struct ICaCPackerVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICaCPacker __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICaCPacker __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICaCPacker __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICaCPacker __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICaCPacker __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICaCPacker __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICaCPacker __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_members )(
            ICaCPacker __RPC_FAR * This,
            /* [in] */ int index,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ret);

        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_members )(
            ICaCPacker __RPC_FAR * This,
            /* [in] */ int index,
            /* [in] */ IDispatch __RPC_FAR *replace_pack_object);

        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_count )(
            ICaCPacker __RPC_FAR * This,
            /* [retval][out] */ int __RPC_FAR *ret);

        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *pack )(
            ICaCPacker __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *pack_object);

        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *unpack )(
            ICaCPacker __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *unpack_object,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ret);

        END_INTERFACE
    } ICaCPackerVtbl;

    interface ICaCPacker
    {
        CONST_VTBL struct ICaCPackerVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICaCPacker_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICaCPacker_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICaCPacker_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICaCPacker_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICaCPacker_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICaCPacker_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICaCPacker_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICaCPacker_get_members(This,index,ret)	\
    (This)->lpVtbl -> get_members(This,index,ret)

#define ICaCPacker_put_members(This,index,replace_pack_object)	\
    (This)->lpVtbl -> put_members(This,index,replace_pack_object)

#define ICaCPacker_get_count(This,ret)	\
    (This)->lpVtbl -> get_count(This,ret)

#define ICaCPacker_pack(This,pack_object)	\
    (This)->lpVtbl -> pack(This,pack_object)

#define ICaCPacker_unpack(This,unpack_object,ret)	\
    (This)->lpVtbl -> unpack(This,unpack_object,ret)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ICaCPacker_get_members_Proxy(
    ICaCPacker __RPC_FAR * This,
    /* [in] */ int index,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ret);


void __RPC_STUB ICaCPacker_get_members_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE ICaCPacker_put_members_Proxy(
    ICaCPacker __RPC_FAR * This,
    /* [in] */ int index,
    /* [in] */ IDispatch __RPC_FAR *replace_pack_object);


void __RPC_STUB ICaCPacker_put_members_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ICaCPacker_get_count_Proxy(
    ICaCPacker __RPC_FAR * This,
    /* [retval][out] */ int __RPC_FAR *ret);


void __RPC_STUB ICaCPacker_get_count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICaCPacker_pack_Proxy(
    ICaCPacker __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *pack_object);


void __RPC_STUB ICaCPacker_pack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICaCPacker_unpack_Proxy(
    ICaCPacker __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *unpack_object,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ret);


void __RPC_STUB ICaCPacker_unpack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICaCPacker_INTERFACE_DEFINED__ */


#ifndef __ICaCProxyUnknown_INTERFACE_DEFINED__
#define __ICaCProxyUnknown_INTERFACE_DEFINED__

/* interface ICaCProxyUnknown */
/* [object][helpstring][oleautomation][dual][uuid] */


EXTERN_C const IID IID_ICaCProxyUnknown;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4341-0110-0001-486954656368")
    ICaCProxyUnknown : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct ICaCProxyUnknownVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICaCProxyUnknown __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICaCProxyUnknown __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICaCProxyUnknown __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICaCProxyUnknown __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICaCProxyUnknown __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICaCProxyUnknown __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICaCProxyUnknown __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } ICaCProxyUnknownVtbl;

    interface ICaCProxyUnknown
    {
        CONST_VTBL struct ICaCProxyUnknownVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICaCProxyUnknown_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICaCProxyUnknown_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICaCProxyUnknown_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICaCProxyUnknown_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICaCProxyUnknown_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICaCProxyUnknown_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICaCProxyUnknown_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICaCProxyUnknown_INTERFACE_DEFINED__ */


#ifndef __ICaCProxyDispatch_INTERFACE_DEFINED__
#define __ICaCProxyDispatch_INTERFACE_DEFINED__

/* interface ICaCProxyDispatch */
/* [object][helpstring][oleautomation][dual][uuid] */


EXTERN_C const IID IID_ICaCProxyDispatch;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4341-0111-0001-486954656368")
    ICaCProxyDispatch : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct ICaCProxyDispatchVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICaCProxyDispatch __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICaCProxyDispatch __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICaCProxyDispatch __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICaCProxyDispatch __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICaCProxyDispatch __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICaCProxyDispatch __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICaCProxyDispatch __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } ICaCProxyDispatchVtbl;

    interface ICaCProxyDispatch
    {
        CONST_VTBL struct ICaCProxyDispatchVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICaCProxyDispatch_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICaCProxyDispatch_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICaCProxyDispatch_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICaCProxyDispatch_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICaCProxyDispatch_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICaCProxyDispatch_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICaCProxyDispatch_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICaCProxyDispatch_INTERFACE_DEFINED__ */



#ifndef __CaComToolLib_LIBRARY_DEFINED__
#define __CaComToolLib_LIBRARY_DEFINED__

/* library CaComToolLib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_CaComToolLib;

EXTERN_C const CLSID CLSID_CaCTools;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4341-0100-0002-486954656368")
CaCTools;
#endif

EXTERN_C const CLSID CLSID_CaCSimulator;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4341-0101-0002-486954656368")
CaCSimulator;
#endif

EXTERN_C const CLSID CLSID_CaCPacker;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4341-0102-0002-486954656368")
CaCPacker;
#endif

EXTERN_C const CLSID CLSID_CaCProxyUnknown;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4341-0110-0002-486954656368")
CaCProxyUnknown;
#endif

EXTERN_C const CLSID CLSID_CaCProxyDispatch;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4341-0111-0002-486954656368")
CaCProxyDispatch;
#endif
#endif /* __CaComToolLib_LIBRARY_DEFINED__ */

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
