/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Jun 09 08:15:03 2006
 */
/* Compiler settings for C:\.lokaj\zbmis\module\xnet\codec\codec.idl:
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

#ifndef __codec_h__
#define __codec_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __IStatement_FWD_DEFINED__
#define __IStatement_FWD_DEFINED__
typedef interface IStatement IStatement;
#endif 	/* __IStatement_FWD_DEFINED__ */


#ifndef __Statement_FWD_DEFINED__
#define __Statement_FWD_DEFINED__

#ifdef __cplusplus
typedef class Statement Statement;
#else
typedef struct Statement Statement;
#endif /* __cplusplus */

#endif 	/* __Statement_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );


#ifndef __XnetCodec_LIBRARY_DEFINED__
#define __XnetCodec_LIBRARY_DEFINED__

/* library XnetCodec */
/* [helpstring][version][uuid] */

typedef
enum StatementItemTypeConstants
    {	sitByte	= 0,
	sitInt	= sitByte + 1,
	sitLong	= sitInt + 1,
	sitSingle	= sitLong + 1,
	sitDouble	= sitSingle + 1,
	sitString	= sitDouble + 1,
	sitBytes	= sitString + 1
    }	StatementItemTypeConstants;


EXTERN_C const IID LIBID_XnetCodec;

#ifndef __IStatement_INTERFACE_DEFINED__
#define __IStatement_INTERFACE_DEFINED__

/* interface IStatement */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IStatement;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("94567C48-F5B2-4CF4-AFF5-13C8EA17C45C")
    IStatement : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add(
            /* [in] */ VARIANT __RPC_FAR *v) = 0;

        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item(
            /* [in] */ int index,
            /* [retval][out] */ VARIANT __RPC_FAR *ret) = 0;

        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Item(
            /* [in] */ int index,
            /* [in] */ VARIANT __RPC_FAR *newval) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TypedItem(
            /* [in] */ int index,
            /* [in] */ StatementItemTypeConstants type,
            /* [retval][out] */ VARIANT __RPC_FAR *ret) = 0;

        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count(
            /* [retval][out] */ int __RPC_FAR *pVal) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Encode(
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ret) = 0;

    };

#else 	/* C style interface */

    typedef struct IStatementVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IStatement __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IStatement __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IStatement __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IStatement __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IStatement __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IStatement __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IStatement __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )(
            IStatement __RPC_FAR * This,
            /* [in] */ VARIANT __RPC_FAR *v);

        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )(
            IStatement __RPC_FAR * This,
            /* [in] */ int index,
            /* [retval][out] */ VARIANT __RPC_FAR *ret);

        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Item )(
            IStatement __RPC_FAR * This,
            /* [in] */ int index,
            /* [in] */ VARIANT __RPC_FAR *newval);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TypedItem )(
            IStatement __RPC_FAR * This,
            /* [in] */ int index,
            /* [in] */ StatementItemTypeConstants type,
            /* [retval][out] */ VARIANT __RPC_FAR *ret);

        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )(
            IStatement __RPC_FAR * This,
            /* [retval][out] */ int __RPC_FAR *pVal);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Encode )(
            IStatement __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ret);

        END_INTERFACE
    } IStatementVtbl;

    interface IStatement
    {
        CONST_VTBL struct IStatementVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IStatement_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IStatement_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IStatement_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IStatement_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IStatement_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IStatement_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IStatement_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IStatement_Add(This,v)	\
    (This)->lpVtbl -> Add(This,v)

#define IStatement_get_Item(This,index,ret)	\
    (This)->lpVtbl -> get_Item(This,index,ret)

#define IStatement_put_Item(This,index,newval)	\
    (This)->lpVtbl -> put_Item(This,index,newval)

#define IStatement_TypedItem(This,index,type,ret)	\
    (This)->lpVtbl -> TypedItem(This,index,type,ret)

#define IStatement_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#define IStatement_Encode(This,ret)	\
    (This)->lpVtbl -> Encode(This,ret)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IStatement_Add_Proxy(
    IStatement __RPC_FAR * This,
    /* [in] */ VARIANT __RPC_FAR *v);


void __RPC_STUB IStatement_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IStatement_get_Item_Proxy(
    IStatement __RPC_FAR * This,
    /* [in] */ int index,
    /* [retval][out] */ VARIANT __RPC_FAR *ret);


void __RPC_STUB IStatement_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IStatement_put_Item_Proxy(
    IStatement __RPC_FAR * This,
    /* [in] */ int index,
    /* [in] */ VARIANT __RPC_FAR *newval);


void __RPC_STUB IStatement_put_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IStatement_TypedItem_Proxy(
    IStatement __RPC_FAR * This,
    /* [in] */ int index,
    /* [in] */ StatementItemTypeConstants type,
    /* [retval][out] */ VARIANT __RPC_FAR *ret);


void __RPC_STUB IStatement_TypedItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IStatement_get_Count_Proxy(
    IStatement __RPC_FAR * This,
    /* [retval][out] */ int __RPC_FAR *pVal);


void __RPC_STUB IStatement_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IStatement_Encode_Proxy(
    IStatement __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ret);


void __RPC_STUB IStatement_Encode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IStatement_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Statement;

#ifdef __cplusplus

class DECLSPEC_UUID("AA02BE05-8896-49C0-B138-F602F90D331F")
Statement;
#endif
#endif /* __XnetCodec_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
