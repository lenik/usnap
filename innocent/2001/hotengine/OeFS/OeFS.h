/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Apr 25 03:41:49 2001
 */
/* Compiler settings for S:\lib\oceanEngine\Working\OeSO\OeFS\OeFS.idl:
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

#ifndef __OeFS_h__
#define __OeFS_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __IOeFSDriver_FWD_DEFINED__
#define __IOeFSDriver_FWD_DEFINED__
typedef interface IOeFSDriver IOeFSDriver;
#endif 	/* __IOeFSDriver_FWD_DEFINED__ */


#ifndef __IOeFSObject_FWD_DEFINED__
#define __IOeFSObject_FWD_DEFINED__
typedef interface IOeFSObject IOeFSObject;
#endif 	/* __IOeFSObject_FWD_DEFINED__ */


#ifndef __IOeFSProxy_FWD_DEFINED__
#define __IOeFSProxy_FWD_DEFINED__
typedef interface IOeFSProxy IOeFSProxy;
#endif 	/* __IOeFSProxy_FWD_DEFINED__ */


#ifndef __IOeFSDirectory_FWD_DEFINED__
#define __IOeFSDirectory_FWD_DEFINED__
typedef interface IOeFSDirectory IOeFSDirectory;
#endif 	/* __IOeFSDirectory_FWD_DEFINED__ */


#ifndef __IOeFSFile_FWD_DEFINED__
#define __IOeFSFile_FWD_DEFINED__
typedef interface IOeFSFile IOeFSFile;
#endif 	/* __IOeFSFile_FWD_DEFINED__ */


#ifndef __IOeFSLink_FWD_DEFINED__
#define __IOeFSLink_FWD_DEFINED__
typedef interface IOeFSLink IOeFSLink;
#endif 	/* __IOeFSLink_FWD_DEFINED__ */


#ifndef __IOeFSTools_FWD_DEFINED__
#define __IOeFSTools_FWD_DEFINED__
typedef interface IOeFSTools IOeFSTools;
#endif 	/* __IOeFSTools_FWD_DEFINED__ */


#ifndef __OeFSDriver_FWD_DEFINED__
#define __OeFSDriver_FWD_DEFINED__

#ifdef __cplusplus
typedef class OeFSDriver OeFSDriver;
#else
typedef struct OeFSDriver OeFSDriver;
#endif /* __cplusplus */

#endif 	/* __OeFSDriver_FWD_DEFINED__ */


#ifndef __OeFSLocalDriver_FWD_DEFINED__
#define __OeFSLocalDriver_FWD_DEFINED__

#ifdef __cplusplus
typedef class OeFSLocalDriver OeFSLocalDriver;
#else
typedef struct OeFSLocalDriver OeFSLocalDriver;
#endif /* __cplusplus */

#endif 	/* __OeFSLocalDriver_FWD_DEFINED__ */


#ifndef __OeFSNullDriver_FWD_DEFINED__
#define __OeFSNullDriver_FWD_DEFINED__

#ifdef __cplusplus
typedef class OeFSNullDriver OeFSNullDriver;
#else
typedef struct OeFSNullDriver OeFSNullDriver;
#endif /* __cplusplus */

#endif 	/* __OeFSNullDriver_FWD_DEFINED__ */


#ifndef __IeFSObject_FWD_DEFINED__
#define __IeFSObject_FWD_DEFINED__

#ifdef __cplusplus
typedef class IeFSObject IeFSObject;
#else
typedef struct IeFSObject IeFSObject;
#endif /* __cplusplus */

#endif 	/* __IeFSObject_FWD_DEFINED__ */


#ifndef __OeFSProxy_FWD_DEFINED__
#define __OeFSProxy_FWD_DEFINED__

#ifdef __cplusplus
typedef class OeFSProxy OeFSProxy;
#else
typedef struct OeFSProxy OeFSProxy;
#endif /* __cplusplus */

#endif 	/* __OeFSProxy_FWD_DEFINED__ */


#ifndef __OeFSDirectory_FWD_DEFINED__
#define __OeFSDirectory_FWD_DEFINED__

#ifdef __cplusplus
typedef class OeFSDirectory OeFSDirectory;
#else
typedef struct OeFSDirectory OeFSDirectory;
#endif /* __cplusplus */

#endif 	/* __OeFSDirectory_FWD_DEFINED__ */


#ifndef __OeFSFile_FWD_DEFINED__
#define __OeFSFile_FWD_DEFINED__

#ifdef __cplusplus
typedef class OeFSFile OeFSFile;
#else
typedef struct OeFSFile OeFSFile;
#endif /* __cplusplus */

#endif 	/* __OeFSFile_FWD_DEFINED__ */


#ifndef __OeFSLink_FWD_DEFINED__
#define __OeFSLink_FWD_DEFINED__

#ifdef __cplusplus
typedef class OeFSLink OeFSLink;
#else
typedef struct OeFSLink OeFSLink;
#endif /* __cplusplus */

#endif 	/* __OeFSLink_FWD_DEFINED__ */


#ifndef __OeFSTools_FWD_DEFINED__
#define __OeFSTools_FWD_DEFINED__

#ifdef __cplusplus
typedef class OeFSTools OeFSTools;
#else
typedef struct OeFSTools OeFSTools;
#endif /* __cplusplus */

#endif 	/* __OeFSTools_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );

/* interface __MIDL_itf_OeFS_0000 */
/* [local] */










extern RPC_IF_HANDLE __MIDL_itf_OeFS_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_OeFS_0000_v0_0_s_ifspec;

#ifndef __IOeFSDriver_INTERFACE_DEFINED__
#define __IOeFSDriver_INTERFACE_DEFINED__

/* interface IOeFSDriver */
/* [object][helpstring][oleautomation][dual][uuid] */


EXTERN_C const IID IID_IOeFSDriver;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4F45-0F00-0001-486954656368")
    IOeFSDriver : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_currentPath(
            /* [retval][out] */ IOeFSDirectory __RPC_FAR *ret) = 0;

        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_currentPath(
            /* [in] */ IOeFSDirectory __RPC_FAR *newpath) = 0;

    };

#else 	/* C style interface */

    typedef struct IOeFSDriverVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IOeFSDriver __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IOeFSDriver __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IOeFSDriver __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IOeFSDriver __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IOeFSDriver __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IOeFSDriver __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IOeFSDriver __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_currentPath )(
            IOeFSDriver __RPC_FAR * This,
            /* [retval][out] */ IOeFSDirectory __RPC_FAR *ret);

        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_currentPath )(
            IOeFSDriver __RPC_FAR * This,
            /* [in] */ IOeFSDirectory __RPC_FAR *newpath);

        END_INTERFACE
    } IOeFSDriverVtbl;

    interface IOeFSDriver
    {
        CONST_VTBL struct IOeFSDriverVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IOeFSDriver_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOeFSDriver_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOeFSDriver_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOeFSDriver_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOeFSDriver_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOeFSDriver_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOeFSDriver_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IOeFSDriver_get_currentPath(This,ret)	\
    (This)->lpVtbl -> get_currentPath(This,ret)

#define IOeFSDriver_put_currentPath(This,newpath)	\
    (This)->lpVtbl -> put_currentPath(This,newpath)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IOeFSDriver_get_currentPath_Proxy(
    IOeFSDriver __RPC_FAR * This,
    /* [retval][out] */ IOeFSDirectory __RPC_FAR *ret);


void __RPC_STUB IOeFSDriver_get_currentPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IOeFSDriver_put_currentPath_Proxy(
    IOeFSDriver __RPC_FAR * This,
    /* [in] */ IOeFSDirectory __RPC_FAR *newpath);


void __RPC_STUB IOeFSDriver_put_currentPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOeFSDriver_INTERFACE_DEFINED__ */


#ifndef __IOeFSObject_INTERFACE_DEFINED__
#define __IOeFSObject_INTERFACE_DEFINED__

/* interface IOeFSObject */
/* [object][helpstring][oleautomation][dual][uuid] */


EXTERN_C const IID IID_IOeFSObject;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4F45-0F01-0001-486954656368")
    IOeFSObject : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct IOeFSObjectVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IOeFSObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IOeFSObject __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IOeFSObject __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IOeFSObject __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IOeFSObject __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IOeFSObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IOeFSObject __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } IOeFSObjectVtbl;

    interface IOeFSObject
    {
        CONST_VTBL struct IOeFSObjectVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IOeFSObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOeFSObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOeFSObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOeFSObject_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOeFSObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOeFSObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOeFSObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOeFSObject_INTERFACE_DEFINED__ */


#ifndef __IOeFSProxy_INTERFACE_DEFINED__
#define __IOeFSProxy_INTERFACE_DEFINED__

/* interface IOeFSProxy */
/* [object][helpstring][oleautomation][dual][uuid] */


EXTERN_C const IID IID_IOeFSProxy;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4F45-0F02-0001-486954656368")
    IOeFSProxy : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct IOeFSProxyVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IOeFSProxy __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IOeFSProxy __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IOeFSProxy __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IOeFSProxy __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IOeFSProxy __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IOeFSProxy __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IOeFSProxy __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } IOeFSProxyVtbl;

    interface IOeFSProxy
    {
        CONST_VTBL struct IOeFSProxyVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IOeFSProxy_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOeFSProxy_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOeFSProxy_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOeFSProxy_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOeFSProxy_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOeFSProxy_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOeFSProxy_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOeFSProxy_INTERFACE_DEFINED__ */


#ifndef __IOeFSDirectory_INTERFACE_DEFINED__
#define __IOeFSDirectory_INTERFACE_DEFINED__

/* interface IOeFSDirectory */
/* [object][helpstring][oleautomation][dual][uuid] */


EXTERN_C const IID IID_IOeFSDirectory;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4F45-0F10-0001-486954656368")
    IOeFSDirectory : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct IOeFSDirectoryVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IOeFSDirectory __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IOeFSDirectory __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IOeFSDirectory __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IOeFSDirectory __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IOeFSDirectory __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IOeFSDirectory __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IOeFSDirectory __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } IOeFSDirectoryVtbl;

    interface IOeFSDirectory
    {
        CONST_VTBL struct IOeFSDirectoryVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IOeFSDirectory_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOeFSDirectory_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOeFSDirectory_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOeFSDirectory_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOeFSDirectory_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOeFSDirectory_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOeFSDirectory_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOeFSDirectory_INTERFACE_DEFINED__ */


#ifndef __IOeFSFile_INTERFACE_DEFINED__
#define __IOeFSFile_INTERFACE_DEFINED__

/* interface IOeFSFile */
/* [object][helpstring][oleautomation][dual][uuid] */


EXTERN_C const IID IID_IOeFSFile;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4F45-0F11-0001-486954656368")
    IOeFSFile : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct IOeFSFileVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IOeFSFile __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IOeFSFile __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IOeFSFile __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IOeFSFile __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IOeFSFile __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IOeFSFile __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IOeFSFile __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } IOeFSFileVtbl;

    interface IOeFSFile
    {
        CONST_VTBL struct IOeFSFileVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IOeFSFile_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOeFSFile_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOeFSFile_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOeFSFile_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOeFSFile_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOeFSFile_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOeFSFile_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOeFSFile_INTERFACE_DEFINED__ */


#ifndef __IOeFSLink_INTERFACE_DEFINED__
#define __IOeFSLink_INTERFACE_DEFINED__

/* interface IOeFSLink */
/* [object][helpstring][oleautomation][dual][uuid] */


EXTERN_C const IID IID_IOeFSLink;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4F45-0F12-0001-486954656368")
    IOeFSLink : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct IOeFSLinkVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IOeFSLink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IOeFSLink __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IOeFSLink __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IOeFSLink __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IOeFSLink __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IOeFSLink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IOeFSLink __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } IOeFSLinkVtbl;

    interface IOeFSLink
    {
        CONST_VTBL struct IOeFSLinkVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IOeFSLink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOeFSLink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOeFSLink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOeFSLink_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOeFSLink_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOeFSLink_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOeFSLink_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOeFSLink_INTERFACE_DEFINED__ */


#ifndef __IOeFSTools_INTERFACE_DEFINED__
#define __IOeFSTools_INTERFACE_DEFINED__

/* interface IOeFSTools */
/* [object][helpstring][oleautomation][dual][uuid] */


EXTERN_C const IID IID_IOeFSTools;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4F45-0F20-0001-486954656368")
    IOeFSTools : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct IOeFSToolsVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IOeFSTools __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IOeFSTools __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IOeFSTools __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IOeFSTools __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IOeFSTools __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IOeFSTools __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IOeFSTools __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } IOeFSToolsVtbl;

    interface IOeFSTools
    {
        CONST_VTBL struct IOeFSToolsVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IOeFSTools_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOeFSTools_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOeFSTools_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOeFSTools_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOeFSTools_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOeFSTools_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOeFSTools_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOeFSTools_INTERFACE_DEFINED__ */



#ifndef __OeFSLib_LIBRARY_DEFINED__
#define __OeFSLib_LIBRARY_DEFINED__

/* library OeFSLib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_OeFSLib;

EXTERN_C const CLSID CLSID_OeFSDriver;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4F45-0F00-0002-486954656368")
OeFSDriver;
#endif

EXTERN_C const CLSID CLSID_OeFSLocalDriver;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4F45-0F00-0102-486954656368")
OeFSLocalDriver;
#endif

EXTERN_C const CLSID CLSID_OeFSNullDriver;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4F45-0F00-0202-486954656368")
OeFSNullDriver;
#endif

EXTERN_C const CLSID CLSID_IeFSObject;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4F45-0F01-0002-486954656368")
IeFSObject;
#endif

EXTERN_C const CLSID CLSID_OeFSProxy;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4F45-0F02-0002-486954656368")
OeFSProxy;
#endif

EXTERN_C const CLSID CLSID_OeFSDirectory;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4F45-0F10-0002-486954656368")
OeFSDirectory;
#endif

EXTERN_C const CLSID CLSID_OeFSFile;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4F45-0F11-0002-486954656368")
OeFSFile;
#endif

EXTERN_C const CLSID CLSID_OeFSLink;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4F45-0F12-0002-486954656368")
OeFSLink;
#endif

EXTERN_C const CLSID CLSID_OeFSTools;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4F45-0F20-0002-486954656368")
OeFSTools;
#endif
#endif /* __OeFSLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
