/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Aug 25 10:51:51 2003
 */
/* Compiler settings for C:\S_PRJS\DATA RESCUER\MODULES\HDR_Services\HDR_Services.idl:
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

#ifndef __HDR_Services_h__
#define __HDR_Services_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __IFSPMapper_FWD_DEFINED__
#define __IFSPMapper_FWD_DEFINED__
typedef interface IFSPMapper IFSPMapper;
#endif 	/* __IFSPMapper_FWD_DEFINED__ */


#ifndef __IFSPReconstruct_FWD_DEFINED__
#define __IFSPReconstruct_FWD_DEFINED__
typedef interface IFSPReconstruct IFSPReconstruct;
#endif 	/* __IFSPReconstruct_FWD_DEFINED__ */


#ifndef __IFSPRecstrMonitor_FWD_DEFINED__
#define __IFSPRecstrMonitor_FWD_DEFINED__
typedef interface IFSPRecstrMonitor IFSPRecstrMonitor;
#endif 	/* __IFSPRecstrMonitor_FWD_DEFINED__ */


#ifndef __IFSPAddInsMgr_FWD_DEFINED__
#define __IFSPAddInsMgr_FWD_DEFINED__
typedef interface IFSPAddInsMgr IFSPAddInsMgr;
#endif 	/* __IFSPAddInsMgr_FWD_DEFINED__ */


#ifndef __IFSPFATxParser_FWD_DEFINED__
#define __IFSPFATxParser_FWD_DEFINED__
typedef interface IFSPFATxParser IFSPFATxParser;
#endif 	/* __IFSPFATxParser_FWD_DEFINED__ */


#ifndef ___IFSPMapperEvents_FWD_DEFINED__
#define ___IFSPMapperEvents_FWD_DEFINED__
typedef interface _IFSPMapperEvents _IFSPMapperEvents;
#endif 	/* ___IFSPMapperEvents_FWD_DEFINED__ */


#ifndef __FATx_FWD_DEFINED__
#define __FATx_FWD_DEFINED__

#ifdef __cplusplus
typedef class FATx FATx;
#else
typedef struct FATx FATx;
#endif /* __cplusplus */

#endif 	/* __FATx_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );

/* interface __MIDL_itf_HDR_Services_0000 */
/* [local] */








extern RPC_IF_HANDLE __MIDL_itf_HDR_Services_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_HDR_Services_0000_v0_0_s_ifspec;

#ifndef __IFSPMapper_INTERFACE_DEFINED__
#define __IFSPMapper_INTERFACE_DEFINED__

/* interface IFSPMapper */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IFSPMapper;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("AC48B470-0211-4616-AA96-0F14ECB94E3B")
    IFSPMapper : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct IFSPMapperVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IFSPMapper __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IFSPMapper __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IFSPMapper __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IFSPMapper __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IFSPMapper __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IFSPMapper __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IFSPMapper __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } IFSPMapperVtbl;

    interface IFSPMapper
    {
        CONST_VTBL struct IFSPMapperVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IFSPMapper_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFSPMapper_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFSPMapper_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFSPMapper_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFSPMapper_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFSPMapper_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFSPMapper_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFSPMapper_INTERFACE_DEFINED__ */


#ifndef __IFSPReconstruct_INTERFACE_DEFINED__
#define __IFSPReconstruct_INTERFACE_DEFINED__

/* interface IFSPReconstruct */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IFSPReconstruct;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("AC48B471-0211-4616-AA96-0F14ECB94E3B")
    IFSPReconstruct : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct IFSPReconstructVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IFSPReconstruct __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IFSPReconstruct __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IFSPReconstruct __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IFSPReconstruct __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IFSPReconstruct __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IFSPReconstruct __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IFSPReconstruct __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } IFSPReconstructVtbl;

    interface IFSPReconstruct
    {
        CONST_VTBL struct IFSPReconstructVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IFSPReconstruct_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFSPReconstruct_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFSPReconstruct_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFSPReconstruct_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFSPReconstruct_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFSPReconstruct_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFSPReconstruct_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFSPReconstruct_INTERFACE_DEFINED__ */


#ifndef __IFSPRecstrMonitor_INTERFACE_DEFINED__
#define __IFSPRecstrMonitor_INTERFACE_DEFINED__

/* interface IFSPRecstrMonitor */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IFSPRecstrMonitor;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("AC48B472-0211-4616-AA96-0F14ECB94E3B")
    IFSPRecstrMonitor : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct IFSPRecstrMonitorVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IFSPRecstrMonitor __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IFSPRecstrMonitor __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IFSPRecstrMonitor __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IFSPRecstrMonitor __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IFSPRecstrMonitor __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IFSPRecstrMonitor __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IFSPRecstrMonitor __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } IFSPRecstrMonitorVtbl;

    interface IFSPRecstrMonitor
    {
        CONST_VTBL struct IFSPRecstrMonitorVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IFSPRecstrMonitor_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFSPRecstrMonitor_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFSPRecstrMonitor_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFSPRecstrMonitor_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFSPRecstrMonitor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFSPRecstrMonitor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFSPRecstrMonitor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFSPRecstrMonitor_INTERFACE_DEFINED__ */


#ifndef __IFSPAddInsMgr_INTERFACE_DEFINED__
#define __IFSPAddInsMgr_INTERFACE_DEFINED__

/* interface IFSPAddInsMgr */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IFSPAddInsMgr;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("AC48B473-0211-4616-AA96-0F14ECB94E3B")
    IFSPAddInsMgr : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FiltersCount(
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;

    };

#else 	/* C style interface */

    typedef struct IFSPAddInsMgrVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IFSPAddInsMgr __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IFSPAddInsMgr __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IFSPAddInsMgr __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IFSPAddInsMgr __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IFSPAddInsMgr __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IFSPAddInsMgr __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IFSPAddInsMgr __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FiltersCount )(
            IFSPAddInsMgr __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);

        END_INTERFACE
    } IFSPAddInsMgrVtbl;

    interface IFSPAddInsMgr
    {
        CONST_VTBL struct IFSPAddInsMgrVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IFSPAddInsMgr_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFSPAddInsMgr_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFSPAddInsMgr_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFSPAddInsMgr_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFSPAddInsMgr_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFSPAddInsMgr_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFSPAddInsMgr_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFSPAddInsMgr_get_FiltersCount(This,pVal)	\
    (This)->lpVtbl -> get_FiltersCount(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFSPAddInsMgr_get_FiltersCount_Proxy(
    IFSPAddInsMgr __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IFSPAddInsMgr_get_FiltersCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFSPAddInsMgr_INTERFACE_DEFINED__ */


#ifndef __IFSPFATxParser_INTERFACE_DEFINED__
#define __IFSPFATxParser_INTERFACE_DEFINED__

/* interface IFSPFATxParser */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IFSPFATxParser;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("AC48B480-0211-4616-AA96-0F14ECB94E3B")
    IFSPFATxParser : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct IFSPFATxParserVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IFSPFATxParser __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IFSPFATxParser __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IFSPFATxParser __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IFSPFATxParser __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IFSPFATxParser __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IFSPFATxParser __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IFSPFATxParser __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } IFSPFATxParserVtbl;

    interface IFSPFATxParser
    {
        CONST_VTBL struct IFSPFATxParserVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IFSPFATxParser_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFSPFATxParser_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFSPFATxParser_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFSPFATxParser_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFSPFATxParser_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFSPFATxParser_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFSPFATxParser_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFSPFATxParser_INTERFACE_DEFINED__ */



#ifndef __HDR_ServicesLib_LIBRARY_DEFINED__
#define __HDR_ServicesLib_LIBRARY_DEFINED__

/* library HDR_ServicesLib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_HDR_ServicesLib;

#ifndef ___IFSPMapperEvents_DISPINTERFACE_DEFINED__
#define ___IFSPMapperEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IFSPMapperEvents */
/* [helpstring][uuid] */


EXTERN_C const IID DIID__IFSPMapperEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("BAB0F8C5-6F3E-4A47-83A4-9C0A71C8272E")
    _IFSPMapperEvents : public IDispatch
    {
    };

#else 	/* C style interface */

    typedef struct _IFSPMapperEventsVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            _IFSPMapperEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            _IFSPMapperEvents __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            _IFSPMapperEvents __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            _IFSPMapperEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            _IFSPMapperEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            _IFSPMapperEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            _IFSPMapperEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } _IFSPMapperEventsVtbl;

    interface _IFSPMapperEvents
    {
        CONST_VTBL struct _IFSPMapperEventsVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define _IFSPMapperEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IFSPMapperEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IFSPMapperEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IFSPMapperEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IFSPMapperEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IFSPMapperEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IFSPMapperEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IFSPMapperEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_FATx;

#ifdef __cplusplus

class DECLSPEC_UUID("E267B01A-6FAA-42E3-A55B-FFB18D359F27")
FATx;
#endif
#endif /* __HDR_ServicesLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
