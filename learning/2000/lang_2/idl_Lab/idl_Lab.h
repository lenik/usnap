/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed May 09 10:06:17 2001
 */
/* Compiler settings for V:\temp\LABc\idl_Lab\idl_Lab.idl:
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

#ifndef __idl_Lab_h__
#define __idl_Lab_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __I1_FWD_DEFINED__
#define __I1_FWD_DEFINED__
typedef interface I1 I1;
#endif 	/* __I1_FWD_DEFINED__ */


#ifndef __I2_FWD_DEFINED__
#define __I2_FWD_DEFINED__
typedef interface I2 I2;
#endif 	/* __I2_FWD_DEFINED__ */


#ifndef __IRedeclare_FWD_DEFINED__
#define __IRedeclare_FWD_DEFINED__
typedef interface IRedeclare IRedeclare;
#endif 	/* __IRedeclare_FWD_DEFINED__ */


#ifndef __IRedeclareEvents_FWD_DEFINED__
#define __IRedeclareEvents_FWD_DEFINED__
typedef interface IRedeclareEvents IRedeclareEvents;
#endif 	/* __IRedeclareEvents_FWD_DEFINED__ */


#ifndef __Redeclare_FWD_DEFINED__
#define __Redeclare_FWD_DEFINED__

#ifdef __cplusplus
typedef class Redeclare Redeclare;
#else
typedef struct Redeclare Redeclare;
#endif /* __cplusplus */

#endif 	/* __Redeclare_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );


#ifndef __IDL_LABLib_LIBRARY_DEFINED__
#define __IDL_LABLib_LIBRARY_DEFINED__

/* library IDL_LABLib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_IDL_LABLib;

#ifndef __I1_INTERFACE_DEFINED__
#define __I1_INTERFACE_DEFINED__

/* interface I1 */
/* [object][uuid] */


EXTERN_C const IID IID_I1;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("10000000-3E6A-46D8-9B02-34C907F73127")
    I1 : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE f1(
            int a) = 0;

    };

#else 	/* C style interface */

    typedef struct I1Vtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            I1 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            I1 __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            I1 __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            I1 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            I1 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            I1 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            I1 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *f1 )(
            I1 __RPC_FAR * This,
            int a);

        END_INTERFACE
    } I1Vtbl;

    interface I1
    {
        CONST_VTBL struct I1Vtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define I1_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define I1_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define I1_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define I1_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define I1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define I1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define I1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define I1_f1(This,a)	\
    (This)->lpVtbl -> f1(This,a)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE I1_f1_Proxy(
    I1 __RPC_FAR * This,
    int a);


void __RPC_STUB I1_f1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __I1_INTERFACE_DEFINED__ */


#ifndef __I2_INTERFACE_DEFINED__
#define __I2_INTERFACE_DEFINED__

/* interface I2 */
/* [object][uuid] */


EXTERN_C const IID IID_I2;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("10000001-3E6A-46D8-9B02-34C907F73127")
    I2 : public I1
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE f2( void) = 0;

    };

#else 	/* C style interface */

    typedef struct I2Vtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            I2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            I2 __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            I2 __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            I2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            I2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            I2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            I2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *f1 )(
            I2 __RPC_FAR * This,
            int a);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *f2 )(
            I2 __RPC_FAR * This);

        END_INTERFACE
    } I2Vtbl;

    interface I2
    {
        CONST_VTBL struct I2Vtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define I2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define I2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define I2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define I2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define I2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define I2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define I2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define I2_f1(This,a)	\
    (This)->lpVtbl -> f1(This,a)


#define I2_f2(This)	\
    (This)->lpVtbl -> f2(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE I2_f2_Proxy(
    I2 __RPC_FAR * This);


void __RPC_STUB I2_f2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __I2_INTERFACE_DEFINED__ */


#ifndef __IRedeclare_INTERFACE_DEFINED__
#define __IRedeclare_INTERFACE_DEFINED__

/* interface IRedeclare */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IRedeclare;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("4C210737-8C2C-453A-9EEF-8208AE5B43D4")
    IRedeclare : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE f1(
            /* [in] */ IDispatch __RPC_FAR *pDisp1) = 0;

    };

#else 	/* C style interface */

    typedef struct IRedeclareVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IRedeclare __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IRedeclare __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IRedeclare __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IRedeclare __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IRedeclare __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IRedeclare __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IRedeclare __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *f1 )(
            IRedeclare __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *pDisp1);

        END_INTERFACE
    } IRedeclareVtbl;

    interface IRedeclare
    {
        CONST_VTBL struct IRedeclareVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IRedeclare_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRedeclare_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRedeclare_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRedeclare_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRedeclare_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRedeclare_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRedeclare_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRedeclare_f1(This,pDisp1)	\
    (This)->lpVtbl -> f1(This,pDisp1)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRedeclare_f1_Proxy(
    IRedeclare __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *pDisp1);


void __RPC_STUB IRedeclare_f1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRedeclare_INTERFACE_DEFINED__ */


#ifndef __IRedeclareEvents_DISPINTERFACE_DEFINED__
#define __IRedeclareEvents_DISPINTERFACE_DEFINED__

/* dispinterface IRedeclareEvents */
/* [uuid] */


EXTERN_C const IID DIID_IRedeclareEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("43289783-3278-6489-2345-678932312890")
    IRedeclareEvents : public IDispatch
    {
    };

#else 	/* C style interface */

    typedef struct IRedeclareEventsVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IRedeclareEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IRedeclareEvents __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IRedeclareEvents __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IRedeclareEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IRedeclareEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IRedeclareEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IRedeclareEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } IRedeclareEventsVtbl;

    interface IRedeclareEvents
    {
        CONST_VTBL struct IRedeclareEventsVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IRedeclareEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRedeclareEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRedeclareEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRedeclareEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRedeclareEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRedeclareEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRedeclareEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IRedeclareEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Redeclare;

#ifdef __cplusplus

class DECLSPEC_UUID("34096CD0-C731-4630-BB45-68B5915740C3")
Redeclare;
#endif
#endif /* __IDL_LABLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
