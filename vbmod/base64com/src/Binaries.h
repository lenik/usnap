/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Sep 01 13:43:32 2005
 */
/* Compiler settings for X:\base64com\Binaries\Binaries.idl:
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

#ifndef __Binaries_h__
#define __Binaries_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __IBase64_FWD_DEFINED__
#define __IBase64_FWD_DEFINED__
typedef interface IBase64 IBase64;
#endif 	/* __IBase64_FWD_DEFINED__ */


#ifndef __Base64_FWD_DEFINED__
#define __Base64_FWD_DEFINED__

#ifdef __cplusplus
typedef class Base64 Base64;
#else
typedef struct Base64 Base64;
#endif /* __cplusplus */

#endif 	/* __Base64_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );


#ifndef __BinariesLib_LIBRARY_DEFINED__
#define __BinariesLib_LIBRARY_DEFINED__

/* library BinariesLib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_BinariesLib;

#ifndef __IBase64_INTERFACE_DEFINED__
#define __IBase64_INTERFACE_DEFINED__

/* interface IBase64 */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IBase64;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("E75C5C81-06E1-45A4-B72C-26B4D1933ABA")
    IBase64 : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EncodeString(
            /* [in] */ BSTR str,
            /* [retval][out] */ BSTR __RPC_FAR *ret) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DecodeString(
            /* [in] */ BSTR base64,
            /* [retval][out] */ BSTR __RPC_FAR *ret) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EncodeData(
            /* [in] */ VARIANT __RPC_FAR *data,
            /* [retval][out] */ BSTR __RPC_FAR *ret) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DecodeData(
            /* [in] */ BSTR base64,
            /* [retval][out] */ VARIANT __RPC_FAR *data) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EncodeFile(
            /* [in] */ BSTR fileName,
            /* [retval][out] */ BSTR __RPC_FAR *ret) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DecodeFile(
            /* [in] */ BSTR base64,
            /* [in] */ BSTR outputFileName) = 0;

    };

#else 	/* C style interface */

    typedef struct IBase64Vtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IBase64 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IBase64 __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IBase64 __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IBase64 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IBase64 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IBase64 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IBase64 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EncodeString )(
            IBase64 __RPC_FAR * This,
            /* [in] */ BSTR str,
            /* [retval][out] */ BSTR __RPC_FAR *ret);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DecodeString )(
            IBase64 __RPC_FAR * This,
            /* [in] */ BSTR base64,
            /* [retval][out] */ BSTR __RPC_FAR *ret);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EncodeData )(
            IBase64 __RPC_FAR * This,
            /* [in] */ VARIANT __RPC_FAR *data,
            /* [retval][out] */ BSTR __RPC_FAR *ret);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DecodeData )(
            IBase64 __RPC_FAR * This,
            /* [in] */ BSTR base64,
            /* [retval][out] */ VARIANT __RPC_FAR *data);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EncodeFile )(
            IBase64 __RPC_FAR * This,
            /* [in] */ BSTR fileName,
            /* [retval][out] */ BSTR __RPC_FAR *ret);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DecodeFile )(
            IBase64 __RPC_FAR * This,
            /* [in] */ BSTR base64,
            /* [in] */ BSTR outputFileName);

        END_INTERFACE
    } IBase64Vtbl;

    interface IBase64
    {
        CONST_VTBL struct IBase64Vtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IBase64_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBase64_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBase64_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBase64_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IBase64_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IBase64_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IBase64_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IBase64_EncodeString(This,str,ret)	\
    (This)->lpVtbl -> EncodeString(This,str,ret)

#define IBase64_DecodeString(This,base64,ret)	\
    (This)->lpVtbl -> DecodeString(This,base64,ret)

#define IBase64_EncodeData(This,data,ret)	\
    (This)->lpVtbl -> EncodeData(This,data,ret)

#define IBase64_DecodeData(This,base64,data)	\
    (This)->lpVtbl -> DecodeData(This,base64,data)

#define IBase64_EncodeFile(This,fileName,ret)	\
    (This)->lpVtbl -> EncodeFile(This,fileName,ret)

#define IBase64_DecodeFile(This,base64,outputFileName)	\
    (This)->lpVtbl -> DecodeFile(This,base64,outputFileName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBase64_EncodeString_Proxy(
    IBase64 __RPC_FAR * This,
    /* [in] */ BSTR str,
    /* [retval][out] */ BSTR __RPC_FAR *ret);


void __RPC_STUB IBase64_EncodeString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBase64_DecodeString_Proxy(
    IBase64 __RPC_FAR * This,
    /* [in] */ BSTR base64,
    /* [retval][out] */ BSTR __RPC_FAR *ret);


void __RPC_STUB IBase64_DecodeString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBase64_EncodeData_Proxy(
    IBase64 __RPC_FAR * This,
    /* [in] */ VARIANT __RPC_FAR *data,
    /* [retval][out] */ BSTR __RPC_FAR *ret);


void __RPC_STUB IBase64_EncodeData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBase64_DecodeData_Proxy(
    IBase64 __RPC_FAR * This,
    /* [in] */ BSTR base64,
    /* [retval][out] */ VARIANT __RPC_FAR *data);


void __RPC_STUB IBase64_DecodeData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBase64_EncodeFile_Proxy(
    IBase64 __RPC_FAR * This,
    /* [in] */ BSTR fileName,
    /* [retval][out] */ BSTR __RPC_FAR *ret);


void __RPC_STUB IBase64_EncodeFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBase64_DecodeFile_Proxy(
    IBase64 __RPC_FAR * This,
    /* [in] */ BSTR base64,
    /* [in] */ BSTR outputFileName);


void __RPC_STUB IBase64_DecodeFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBase64_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Base64;

#ifdef __cplusplus

class DECLSPEC_UUID("A7687779-319D-4291-A4B3-48E043627242")
Base64;
#endif
#endif /* __BinariesLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
