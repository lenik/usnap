/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat Apr 21 06:26:01 2001
 */
/* Compiler settings for S:\lib\campoEngine\working\CeE2D\CeE2D.idl:
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

#ifndef __CeE2D_h__
#define __CeE2D_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __ICeE2DBase_FWD_DEFINED__
#define __ICeE2DBase_FWD_DEFINED__
typedef interface ICeE2DBase ICeE2DBase;
#endif 	/* __ICeE2DBase_FWD_DEFINED__ */


#ifndef __ICeE2DPage_FWD_DEFINED__
#define __ICeE2DPage_FWD_DEFINED__
typedef interface ICeE2DPage ICeE2DPage;
#endif 	/* __ICeE2DPage_FWD_DEFINED__ */


#ifndef __ICeE2DAux_FWD_DEFINED__
#define __ICeE2DAux_FWD_DEFINED__
typedef interface ICeE2DAux ICeE2DAux;
#endif 	/* __ICeE2DAux_FWD_DEFINED__ */


#ifndef __CeE2DBase_FWD_DEFINED__
#define __CeE2DBase_FWD_DEFINED__

#ifdef __cplusplus
typedef class CeE2DBase CeE2DBase;
#else
typedef struct CeE2DBase CeE2DBase;
#endif /* __cplusplus */

#endif 	/* __CeE2DBase_FWD_DEFINED__ */


#ifndef __CeE2DDevice_FWD_DEFINED__
#define __CeE2DDevice_FWD_DEFINED__

#ifdef __cplusplus
typedef class CeE2DDevice CeE2DDevice;
#else
typedef struct CeE2DDevice CeE2DDevice;
#endif /* __cplusplus */

#endif 	/* __CeE2DDevice_FWD_DEFINED__ */


#ifndef __CeE2DPage_FWD_DEFINED__
#define __CeE2DPage_FWD_DEFINED__

#ifdef __cplusplus
typedef class CeE2DPage CeE2DPage;
#else
typedef struct CeE2DPage CeE2DPage;
#endif /* __cplusplus */

#endif 	/* __CeE2DPage_FWD_DEFINED__ */


#ifndef __CeE2DAux_FWD_DEFINED__
#define __CeE2DAux_FWD_DEFINED__

#ifdef __cplusplus
typedef class CeE2DAux CeE2DAux;
#else
typedef struct CeE2DAux CeE2DAux;
#endif /* __cplusplus */

#endif 	/* __CeE2DAux_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );

/* interface __MIDL_itf_CeE2D_0000 */
/* [local] */

#if 0
typedef LONG HWND;

typedef LONG HDC;

#endif



extern RPC_IF_HANDLE __MIDL_itf_CeE2D_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_CeE2D_0000_v0_0_s_ifspec;

#ifndef __ICeE2DBase_INTERFACE_DEFINED__
#define __ICeE2DBase_INTERFACE_DEFINED__

/* interface ICeE2DBase */
/* [object][helpstring][oleautomation][dual][uuid] */


EXTERN_C const IID IID_ICeE2DBase;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4345-2000-0001-486954656368")
    ICeE2DBase : public IDispatch
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Resolution(
            /* [in] */ LONG width,
            /* [in] */ LONG height,
            /* [in] */ LONG depth,
            /* [retval][out] */ BOOL __RPC_FAR *ret) = 0;

        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreatePage(
            /* [in] */ LONG width,
            /* [in] */ LONG height,
            /* [in] */ LONG nAdditionPages,
            /* [in] */ BOOL bOffScreen,
            /* [retval][out] */ ICeE2DPage __RPC_FAR *__RPC_FAR *ret) = 0;

    };

#else 	/* C style interface */

    typedef struct ICeE2DBaseVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICeE2DBase __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICeE2DBase __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICeE2DBase __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICeE2DBase __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICeE2DBase __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICeE2DBase __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICeE2DBase __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Resolution )(
            ICeE2DBase __RPC_FAR * This,
            /* [in] */ LONG width,
            /* [in] */ LONG height,
            /* [in] */ LONG depth,
            /* [retval][out] */ BOOL __RPC_FAR *ret);

        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreatePage )(
            ICeE2DBase __RPC_FAR * This,
            /* [in] */ LONG width,
            /* [in] */ LONG height,
            /* [in] */ LONG nAdditionPages,
            /* [in] */ BOOL bOffScreen,
            /* [retval][out] */ ICeE2DPage __RPC_FAR *__RPC_FAR *ret);

        END_INTERFACE
    } ICeE2DBaseVtbl;

    interface ICeE2DBase
    {
        CONST_VTBL struct ICeE2DBaseVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICeE2DBase_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICeE2DBase_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICeE2DBase_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICeE2DBase_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICeE2DBase_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICeE2DBase_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICeE2DBase_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICeE2DBase_Resolution(This,width,height,depth,ret)	\
    (This)->lpVtbl -> Resolution(This,width,height,depth,ret)

#define ICeE2DBase_CreatePage(This,width,height,nAdditionPages,bOffScreen,ret)	\
    (This)->lpVtbl -> CreatePage(This,width,height,nAdditionPages,bOffScreen,ret)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICeE2DBase_Resolution_Proxy(
    ICeE2DBase __RPC_FAR * This,
    /* [in] */ LONG width,
    /* [in] */ LONG height,
    /* [in] */ LONG depth,
    /* [retval][out] */ BOOL __RPC_FAR *ret);


void __RPC_STUB ICeE2DBase_Resolution_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICeE2DBase_CreatePage_Proxy(
    ICeE2DBase __RPC_FAR * This,
    /* [in] */ LONG width,
    /* [in] */ LONG height,
    /* [in] */ LONG nAdditionPages,
    /* [in] */ BOOL bOffScreen,
    /* [retval][out] */ ICeE2DPage __RPC_FAR *__RPC_FAR *ret);


void __RPC_STUB ICeE2DBase_CreatePage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICeE2DBase_INTERFACE_DEFINED__ */


#ifndef __ICeE2DPage_INTERFACE_DEFINED__
#define __ICeE2DPage_INTERFACE_DEFINED__

/* interface ICeE2DPage */
/* [object][helpstring][oleautomation][dual][uuid] */


EXTERN_C const IID IID_ICeE2DPage;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4345-2002-0001-486954656368")
    ICeE2DPage : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE NextPage(
            /* [retval][out] */ ICeE2DPage __RPC_FAR *__RPC_FAR *ret) = 0;

        virtual HRESULT STDMETHODCALLTYPE SwapPage( void) = 0;

        virtual HRESULT STDMETHODCALLTYPE DrawBegin(
            /* [retval][out] */ HDC __RPC_FAR *ret) = 0;

        virtual HRESULT STDMETHODCALLTYPE DrawEnd( void) = 0;

        virtual HRESULT STDMETHODCALLTYPE ProcessBegin(
            /* [retval][out] */ LONG __RPC_FAR *ret) = 0;

        virtual HRESULT STDMETHODCALLTYPE ProcessEnd( void) = 0;

        virtual HRESULT STDMETHODCALLTYPE BitBlt(
            /* [in] */ ICeE2DPage __RPC_FAR *pdest,
            /* [in] */ LONG destx,
            /* [in] */ LONG desty,
            /* [in] */ LONG width,
            /* [in] */ LONG height,
            /* [in] */ LONG srcx,
            /* [in] */ LONG srcy,
            /* [in] */ LONG rop) = 0;

    };

#else 	/* C style interface */

    typedef struct ICeE2DPageVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICeE2DPage __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICeE2DPage __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICeE2DPage __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICeE2DPage __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICeE2DPage __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICeE2DPage __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICeE2DPage __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *NextPage )(
            ICeE2DPage __RPC_FAR * This,
            /* [retval][out] */ ICeE2DPage __RPC_FAR *__RPC_FAR *ret);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SwapPage )(
            ICeE2DPage __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawBegin )(
            ICeE2DPage __RPC_FAR * This,
            /* [retval][out] */ HDC __RPC_FAR *ret);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawEnd )(
            ICeE2DPage __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ProcessBegin )(
            ICeE2DPage __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *ret);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ProcessEnd )(
            ICeE2DPage __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BitBlt )(
            ICeE2DPage __RPC_FAR * This,
            /* [in] */ ICeE2DPage __RPC_FAR *pdest,
            /* [in] */ LONG destx,
            /* [in] */ LONG desty,
            /* [in] */ LONG width,
            /* [in] */ LONG height,
            /* [in] */ LONG srcx,
            /* [in] */ LONG srcy,
            /* [in] */ LONG rop);

        END_INTERFACE
    } ICeE2DPageVtbl;

    interface ICeE2DPage
    {
        CONST_VTBL struct ICeE2DPageVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICeE2DPage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICeE2DPage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICeE2DPage_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICeE2DPage_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICeE2DPage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICeE2DPage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICeE2DPage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICeE2DPage_NextPage(This,ret)	\
    (This)->lpVtbl -> NextPage(This,ret)

#define ICeE2DPage_SwapPage(This)	\
    (This)->lpVtbl -> SwapPage(This)

#define ICeE2DPage_DrawBegin(This,ret)	\
    (This)->lpVtbl -> DrawBegin(This,ret)

#define ICeE2DPage_DrawEnd(This)	\
    (This)->lpVtbl -> DrawEnd(This)

#define ICeE2DPage_ProcessBegin(This,ret)	\
    (This)->lpVtbl -> ProcessBegin(This,ret)

#define ICeE2DPage_ProcessEnd(This)	\
    (This)->lpVtbl -> ProcessEnd(This)

#define ICeE2DPage_BitBlt(This,pdest,destx,desty,width,height,srcx,srcy,rop)	\
    (This)->lpVtbl -> BitBlt(This,pdest,destx,desty,width,height,srcx,srcy,rop)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ICeE2DPage_NextPage_Proxy(
    ICeE2DPage __RPC_FAR * This,
    /* [retval][out] */ ICeE2DPage __RPC_FAR *__RPC_FAR *ret);


void __RPC_STUB ICeE2DPage_NextPage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICeE2DPage_SwapPage_Proxy(
    ICeE2DPage __RPC_FAR * This);


void __RPC_STUB ICeE2DPage_SwapPage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICeE2DPage_DrawBegin_Proxy(
    ICeE2DPage __RPC_FAR * This,
    /* [retval][out] */ HDC __RPC_FAR *ret);


void __RPC_STUB ICeE2DPage_DrawBegin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICeE2DPage_DrawEnd_Proxy(
    ICeE2DPage __RPC_FAR * This);


void __RPC_STUB ICeE2DPage_DrawEnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICeE2DPage_ProcessBegin_Proxy(
    ICeE2DPage __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *ret);


void __RPC_STUB ICeE2DPage_ProcessBegin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICeE2DPage_ProcessEnd_Proxy(
    ICeE2DPage __RPC_FAR * This);


void __RPC_STUB ICeE2DPage_ProcessEnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICeE2DPage_BitBlt_Proxy(
    ICeE2DPage __RPC_FAR * This,
    /* [in] */ ICeE2DPage __RPC_FAR *pdest,
    /* [in] */ LONG destx,
    /* [in] */ LONG desty,
    /* [in] */ LONG width,
    /* [in] */ LONG height,
    /* [in] */ LONG srcx,
    /* [in] */ LONG srcy,
    /* [in] */ LONG rop);


void __RPC_STUB ICeE2DPage_BitBlt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICeE2DPage_INTERFACE_DEFINED__ */


#ifndef __ICeE2DAux_INTERFACE_DEFINED__
#define __ICeE2DAux_INTERFACE_DEFINED__

/* interface ICeE2DAux */
/* [object][helpstring][oleautomation][dual][uuid] */


EXTERN_C const IID IID_ICeE2DAux;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4345-2003-0001-486954656368")
    ICeE2DAux : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct ICeE2DAuxVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICeE2DAux __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICeE2DAux __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICeE2DAux __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICeE2DAux __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICeE2DAux __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICeE2DAux __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICeE2DAux __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } ICeE2DAuxVtbl;

    interface ICeE2DAux
    {
        CONST_VTBL struct ICeE2DAuxVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICeE2DAux_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICeE2DAux_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICeE2DAux_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICeE2DAux_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICeE2DAux_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICeE2DAux_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICeE2DAux_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICeE2DAux_INTERFACE_DEFINED__ */



#ifndef __CeE2DLib_LIBRARY_DEFINED__
#define __CeE2DLib_LIBRARY_DEFINED__

/* library CeE2DLib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_CeE2DLib;

EXTERN_C const CLSID CLSID_CeE2DBase;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4345-2000-0002-486954656368")
CeE2DBase;
#endif

EXTERN_C const CLSID CLSID_CeE2DDevice;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4345-2001-0002-486954656368")
CeE2DDevice;
#endif

EXTERN_C const CLSID CLSID_CeE2DPage;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4345-2002-0002-486954656368")
CeE2DPage;
#endif

EXTERN_C const CLSID CLSID_CeE2DAux;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4345-2003-0002-486954656368")
CeE2DAux;
#endif


#ifndef __CeE2DModule_MODULE_DEFINED__
#define __CeE2DModule_MODULE_DEFINED__


/* module CeE2DModule */
/* [helpstring][dllname][uuid] */

/* [helpstring][entry] */ HRESULT __stdcall CreateCeE2D(
    /* [in] */ HWND hMainWnd,
    /* [retval][out] */ ICeE2DBase __RPC_FAR *__RPC_FAR *ret);

#endif /* __CeE2DModule_MODULE_DEFINED__ */
#endif /* __CeE2DLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
