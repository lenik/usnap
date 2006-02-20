/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Feb 20 14:16:41 2006
 */
/* Compiler settings for C:\.lokaj\zbmis\module\fastalg\src\fastalg.idl:
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

#ifndef __fastalg_h__
#define __fastalg_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __ISAOT_FWD_DEFINED__
#define __ISAOT_FWD_DEFINED__
typedef interface ISAOT ISAOT;
#endif 	/* __ISAOT_FWD_DEFINED__ */


#ifndef __IDRIA_FWD_DEFINED__
#define __IDRIA_FWD_DEFINED__
typedef interface IDRIA IDRIA;
#endif 	/* __IDRIA_FWD_DEFINED__ */


#ifndef __SAOT_FWD_DEFINED__
#define __SAOT_FWD_DEFINED__

#ifdef __cplusplus
typedef class SAOT SAOT;
#else
typedef struct SAOT SAOT;
#endif /* __cplusplus */

#endif 	/* __SAOT_FWD_DEFINED__ */


#ifndef __DRIA_FWD_DEFINED__
#define __DRIA_FWD_DEFINED__

#ifdef __cplusplus
typedef class DRIA DRIA;
#else
typedef struct DRIA DRIA;
#endif /* __cplusplus */

#endif 	/* __DRIA_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );

#ifndef __ISAOT_INTERFACE_DEFINED__
#define __ISAOT_INTERFACE_DEFINED__

/* interface ISAOT */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_ISAOT;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("AECAFF4C-5D51-483A-8619-E80511E69439")
    ISAOT : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct ISAOTVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ISAOT __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ISAOT __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ISAOT __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ISAOT __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ISAOT __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ISAOT __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ISAOT __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } ISAOTVtbl;

    interface ISAOT
    {
        CONST_VTBL struct ISAOTVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ISAOT_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAOT_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAOT_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAOT_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISAOT_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISAOT_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISAOT_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISAOT_INTERFACE_DEFINED__ */


#ifndef __IDRIA_INTERFACE_DEFINED__
#define __IDRIA_INTERFACE_DEFINED__

/* interface IDRIA */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IDRIA;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("604D4559-902D-4066-B1FA-81F692610519")
    IDRIA : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct IDRIAVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IDRIA __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IDRIA __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IDRIA __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IDRIA __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IDRIA __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IDRIA __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IDRIA __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } IDRIAVtbl;

    interface IDRIA
    {
        CONST_VTBL struct IDRIAVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IDRIA_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDRIA_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDRIA_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDRIA_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDRIA_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDRIA_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDRIA_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDRIA_INTERFACE_DEFINED__ */



#ifndef __FastAlgLib_LIBRARY_DEFINED__
#define __FastAlgLib_LIBRARY_DEFINED__

/* library FastAlgLib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_FastAlgLib;

EXTERN_C const CLSID CLSID_SAOT;

#ifdef __cplusplus

class DECLSPEC_UUID("CD583388-D348-4A9E-BBBB-9A8D25F3DAAD")
SAOT;
#endif

EXTERN_C const CLSID CLSID_DRIA;

#ifdef __cplusplus

class DECLSPEC_UUID("AF43CEA4-BF31-4BF7-AEB6-EAD41BB7B476")
DRIA;
#endif
#endif /* __FastAlgLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
