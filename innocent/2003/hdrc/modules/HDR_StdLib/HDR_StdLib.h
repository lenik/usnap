/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Aug 14 12:26:02 2003
 */
/* Compiler settings for C:\s_prjs\Data Rescuer\modules\HDR_StdLib\HDR_StdLib.idl:
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

#ifndef __HDR_StdLib_h__
#define __HDR_StdLib_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __IModuleProvider_FWD_DEFINED__
#define __IModuleProvider_FWD_DEFINED__
typedef interface IModuleProvider IModuleProvider;
#endif 	/* __IModuleProvider_FWD_DEFINED__ */


#ifndef __IFileTypeVerifier_FWD_DEFINED__
#define __IFileTypeVerifier_FWD_DEFINED__
typedef interface IFileTypeVerifier IFileTypeVerifier;
#endif 	/* __IFileTypeVerifier_FWD_DEFINED__ */


#ifndef __ModuleProvider_FWD_DEFINED__
#define __ModuleProvider_FWD_DEFINED__

#ifdef __cplusplus
typedef class ModuleProvider ModuleProvider;
#else
typedef struct ModuleProvider ModuleProvider;
#endif /* __cplusplus */

#endif 	/* __ModuleProvider_FWD_DEFINED__ */


#ifndef __StdFileTypeVerifier_FWD_DEFINED__
#define __StdFileTypeVerifier_FWD_DEFINED__

#ifdef __cplusplus
typedef class StdFileTypeVerifier StdFileTypeVerifier;
#else
typedef struct StdFileTypeVerifier StdFileTypeVerifier;
#endif /* __cplusplus */

#endif 	/* __StdFileTypeVerifier_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );

#ifndef __IModuleProvider_INTERFACE_DEFINED__
#define __IModuleProvider_INTERFACE_DEFINED__

/* interface IModuleProvider */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IModuleProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("3B945220-0A12-4739-BF4D-B178B9A27567")
    IModuleProvider : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct IModuleProviderVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IModuleProvider __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IModuleProvider __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IModuleProvider __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IModuleProvider __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IModuleProvider __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IModuleProvider __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IModuleProvider __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } IModuleProviderVtbl;

    interface IModuleProvider
    {
        CONST_VTBL struct IModuleProviderVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IModuleProvider_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IModuleProvider_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IModuleProvider_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IModuleProvider_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IModuleProvider_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IModuleProvider_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IModuleProvider_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IModuleProvider_INTERFACE_DEFINED__ */


#ifndef __IFileTypeVerifier_INTERFACE_DEFINED__
#define __IFileTypeVerifier_INTERFACE_DEFINED__

/* interface IFileTypeVerifier */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IFileTypeVerifier;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("A0C7541D-A322-4552-ABA5-1C83704BBC8C")
    IFileTypeVerifier : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct IFileTypeVerifierVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IFileTypeVerifier __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IFileTypeVerifier __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IFileTypeVerifier __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IFileTypeVerifier __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IFileTypeVerifier __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IFileTypeVerifier __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IFileTypeVerifier __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } IFileTypeVerifierVtbl;

    interface IFileTypeVerifier
    {
        CONST_VTBL struct IFileTypeVerifierVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IFileTypeVerifier_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFileTypeVerifier_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFileTypeVerifier_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFileTypeVerifier_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFileTypeVerifier_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFileTypeVerifier_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFileTypeVerifier_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFileTypeVerifier_INTERFACE_DEFINED__ */



#ifndef __HDR_StdLib_LIBRARY_DEFINED__
#define __HDR_StdLib_LIBRARY_DEFINED__

/* library HDR_StdLib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_HDR_StdLib;

EXTERN_C const CLSID CLSID_ModuleProvider;

#ifdef __cplusplus

class DECLSPEC_UUID("A90F2663-2290-430A-9B48-28A09DF9C379")
ModuleProvider;
#endif

EXTERN_C const CLSID CLSID_StdFileTypeVerifier;

#ifdef __cplusplus

class DECLSPEC_UUID("32C84E18-9406-4AE2-A8ED-BB55DBF2A9B9")
StdFileTypeVerifier;
#endif
#endif /* __HDR_StdLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
