/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Mar 20 09:12:03 2006
 */
/* Compiler settings for C:\.lokaj\zbmis\module\binary\src\binary.idl:
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

#ifndef __binary_h__
#define __binary_h__

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

#ifndef __IBase64_INTERFACE_DEFINED__
#define __IBase64_INTERFACE_DEFINED__

/* interface IBase64 */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IBase64;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("A051359F-BF80-4014-B50D-74C597CB0FE4")
    IBase64 : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetStringB(
            /* [in] */ BSTR stringB) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetString(
            /* [in] */ BSTR stringUnicode,
            /* [defaultvalue][optional][in] */ BSTR encoding = L"gb2312") = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetBase64(
            /* [retval][out] */ BSTR __RPC_FAR *base64) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetStringB(
            /* [retval][out] */ BSTR __RPC_FAR *stringB) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetString(
            /* [defaultvalue][optional][in] */ BSTR encoding,
            /* [retval][out] */ BSTR __RPC_FAR *string) = 0;

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

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetStringB )(
            IBase64 __RPC_FAR * This,
            /* [in] */ BSTR stringB);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetString )(
            IBase64 __RPC_FAR * This,
            /* [in] */ BSTR stringUnicode,
            /* [defaultvalue][optional][in] */ BSTR encoding);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBase64 )(
            IBase64 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *base64);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStringB )(
            IBase64 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *stringB);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetString )(
            IBase64 __RPC_FAR * This,
            /* [defaultvalue][optional][in] */ BSTR encoding,
            /* [retval][out] */ BSTR __RPC_FAR *string);

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


#define IBase64_SetStringB(This,stringB)	\
    (This)->lpVtbl -> SetStringB(This,stringB)

#define IBase64_SetString(This,stringUnicode,encoding)	\
    (This)->lpVtbl -> SetString(This,stringUnicode,encoding)

#define IBase64_GetBase64(This,base64)	\
    (This)->lpVtbl -> GetBase64(This,base64)

#define IBase64_GetStringB(This,stringB)	\
    (This)->lpVtbl -> GetStringB(This,stringB)

#define IBase64_GetString(This,encoding,string)	\
    (This)->lpVtbl -> GetString(This,encoding,string)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBase64_SetStringB_Proxy(
    IBase64 __RPC_FAR * This,
    /* [in] */ BSTR stringB);


void __RPC_STUB IBase64_SetStringB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBase64_SetString_Proxy(
    IBase64 __RPC_FAR * This,
    /* [in] */ BSTR stringUnicode,
    /* [defaultvalue][optional][in] */ BSTR encoding);


void __RPC_STUB IBase64_SetString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBase64_GetBase64_Proxy(
    IBase64 __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *base64);


void __RPC_STUB IBase64_GetBase64_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBase64_GetStringB_Proxy(
    IBase64 __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *stringB);


void __RPC_STUB IBase64_GetStringB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBase64_GetString_Proxy(
    IBase64 __RPC_FAR * This,
    /* [defaultvalue][optional][in] */ BSTR encoding,
    /* [retval][out] */ BSTR __RPC_FAR *string);


void __RPC_STUB IBase64_GetString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBase64_INTERFACE_DEFINED__ */



#ifndef __BinaryLib_LIBRARY_DEFINED__
#define __BinaryLib_LIBRARY_DEFINED__

/* library BinaryLib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_BinaryLib;

EXTERN_C const CLSID CLSID_Base64;

#ifdef __cplusplus

class DECLSPEC_UUID("7867B0A2-C95C-4B3D-8E0D-7A006DAAB0BC")
Base64;
#endif
#endif /* __BinaryLib_LIBRARY_DEFINED__ */

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
