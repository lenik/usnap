/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Mar 16 14:07:55 2006
 */
/* Compiler settings for C:\.lokaj\zbmis\module\crypt\src\Crypt.idl:
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

#ifndef __Crypt_h__
#define __Crypt_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __IDigest_FWD_DEFINED__
#define __IDigest_FWD_DEFINED__
typedef interface IDigest IDigest;
#endif 	/* __IDigest_FWD_DEFINED__ */


#ifndef __Digest_FWD_DEFINED__
#define __Digest_FWD_DEFINED__

#ifdef __cplusplus
typedef class Digest Digest;
#else
typedef struct Digest Digest;
#endif /* __cplusplus */

#endif 	/* __Digest_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );

#ifndef __IDigest_INTERFACE_DEFINED__
#define __IDigest_INTERFACE_DEFINED__

/* interface IDigest */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IDigest;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("37ECCF71-E520-4791-AB28-482455E1181F")
    IDigest : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MD5_String(
            /* [in] */ BSTR message,
            /* [out] */ long __RPC_FAR *a_msb,
            /* [out] */ long __RPC_FAR *b,
            /* [out] */ long __RPC_FAR *c,
            /* [out] */ long __RPC_FAR *d_lsb) = 0;

    };

#else 	/* C style interface */

    typedef struct IDigestVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IDigest __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IDigest __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IDigest __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IDigest __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IDigest __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IDigest __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IDigest __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MD5_String )(
            IDigest __RPC_FAR * This,
            /* [in] */ BSTR message,
            /* [out] */ long __RPC_FAR *a_msb,
            /* [out] */ long __RPC_FAR *b,
            /* [out] */ long __RPC_FAR *c,
            /* [out] */ long __RPC_FAR *d_lsb);

        END_INTERFACE
    } IDigestVtbl;

    interface IDigest
    {
        CONST_VTBL struct IDigestVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IDigest_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDigest_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDigest_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDigest_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDigest_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDigest_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDigest_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDigest_MD5_String(This,message,a_msb,b,c,d_lsb)	\
    (This)->lpVtbl -> MD5_String(This,message,a_msb,b,c,d_lsb)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDigest_MD5_String_Proxy(
    IDigest __RPC_FAR * This,
    /* [in] */ BSTR message,
    /* [out] */ long __RPC_FAR *a_msb,
    /* [out] */ long __RPC_FAR *b,
    /* [out] */ long __RPC_FAR *c,
    /* [out] */ long __RPC_FAR *d_lsb);


void __RPC_STUB IDigest_MD5_String_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDigest_INTERFACE_DEFINED__ */



#ifndef __CryptLib_LIBRARY_DEFINED__
#define __CryptLib_LIBRARY_DEFINED__

/* library CryptLib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_CryptLib;

EXTERN_C const CLSID CLSID_Digest;

#ifdef __cplusplus

class DECLSPEC_UUID("5585D1C0-3D20-4E4D-9EA0-78A13D55540D")
Digest;
#endif
#endif /* __CryptLib_LIBRARY_DEFINED__ */

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
