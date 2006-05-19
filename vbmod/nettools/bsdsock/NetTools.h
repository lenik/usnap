/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue May 02 14:54:29 2006
 */
/* Compiler settings for C:\.lokaj\zbmis\module\nettools\NetTools.idl:
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

#ifndef __NetTools_h__
#define __NetTools_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __IGlobals_FWD_DEFINED__
#define __IGlobals_FWD_DEFINED__
typedef interface IGlobals IGlobals;
#endif 	/* __IGlobals_FWD_DEFINED__ */


#ifndef __IRemoteFSO_FWD_DEFINED__
#define __IRemoteFSO_FWD_DEFINED__
typedef interface IRemoteFSO IRemoteFSO;
#endif 	/* __IRemoteFSO_FWD_DEFINED__ */


#ifndef __Globals_FWD_DEFINED__
#define __Globals_FWD_DEFINED__

#ifdef __cplusplus
typedef class Globals Globals;
#else
typedef struct Globals Globals;
#endif /* __cplusplus */

#endif 	/* __Globals_FWD_DEFINED__ */


#ifndef __RemoteFSO_FWD_DEFINED__
#define __RemoteFSO_FWD_DEFINED__

#ifdef __cplusplus
typedef class RemoteFSO RemoteFSO;
#else
typedef struct RemoteFSO RemoteFSO;
#endif /* __cplusplus */

#endif 	/* __RemoteFSO_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );


#ifndef __NetToolsLib_LIBRARY_DEFINED__
#define __NetToolsLib_LIBRARY_DEFINED__

/* library NetToolsLib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_NetToolsLib;

#ifndef __IGlobals_INTERFACE_DEFINED__
#define __IGlobals_INTERFACE_DEFINED__

/* interface IGlobals */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IGlobals;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("FA417E17-08CF-4D1D-8E5A-D3BD57964456")
    IGlobals : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateRemoteFSO(
            /* [in] */ BSTR Server,
            /* [in] */ int Port,
            /* [retval][out] */ /* external definition not present */ IFileSystem __RPC_FAR *__RPC_FAR *FSO) = 0;

    };

#else 	/* C style interface */

    typedef struct IGlobalsVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IGlobals __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IGlobals __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IGlobals __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IGlobals __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IGlobals __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IGlobals __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IGlobals __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateRemoteFSO )(
            IGlobals __RPC_FAR * This,
            /* [in] */ BSTR Server,
            /* [in] */ int Port,
            /* [retval][out] */ /* external definition not present */ IFileSystem __RPC_FAR *__RPC_FAR *FSO);

        END_INTERFACE
    } IGlobalsVtbl;

    interface IGlobals
    {
        CONST_VTBL struct IGlobalsVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IGlobals_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGlobals_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGlobals_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGlobals_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IGlobals_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IGlobals_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IGlobals_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IGlobals_CreateRemoteFSO(This,Server,Port,FSO)	\
    (This)->lpVtbl -> CreateRemoteFSO(This,Server,Port,FSO)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGlobals_CreateRemoteFSO_Proxy(
    IGlobals __RPC_FAR * This,
    /* [in] */ BSTR Server,
    /* [in] */ int Port,
    /* [retval][out] */ /* external definition not present */ IFileSystem __RPC_FAR *__RPC_FAR *FSO);


void __RPC_STUB IGlobals_CreateRemoteFSO_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGlobals_INTERFACE_DEFINED__ */


#ifndef __IRemoteFSO_INTERFACE_DEFINED__
#define __IRemoteFSO_INTERFACE_DEFINED__

/* interface IRemoteFSO */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IRemoteFSO;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("29138607-9B6E-4128-B137-7D6329029DD4")
    IRemoteFSO : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct IRemoteFSOVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IRemoteFSO __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IRemoteFSO __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IRemoteFSO __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IRemoteFSO __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IRemoteFSO __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IRemoteFSO __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IRemoteFSO __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } IRemoteFSOVtbl;

    interface IRemoteFSO
    {
        CONST_VTBL struct IRemoteFSOVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IRemoteFSO_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRemoteFSO_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRemoteFSO_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRemoteFSO_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRemoteFSO_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRemoteFSO_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRemoteFSO_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRemoteFSO_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Globals;

#ifdef __cplusplus

class DECLSPEC_UUID("F3BAD689-A6EF-44D8-93D3-79F50F0C791D")
Globals;
#endif

EXTERN_C const CLSID CLSID_RemoteFSO;

#ifdef __cplusplus

class DECLSPEC_UUID("7FFFE503-AC6C-4B17-AB54-7733624BC775")
RemoteFSO;
#endif
#endif /* __NetToolsLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
