/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat Apr 28 20:21:40 2001
 */
/* Compiler settings for V:\Components\Lab\TestCom\DogCat\DogCat.idl:
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

#ifndef __DogCat_h__
#define __DogCat_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __ICaDog_FWD_DEFINED__
#define __ICaDog_FWD_DEFINED__
typedef interface ICaDog ICaDog;
#endif 	/* __ICaDog_FWD_DEFINED__ */


#ifndef __ICaDogEvents_FWD_DEFINED__
#define __ICaDogEvents_FWD_DEFINED__
typedef interface ICaDogEvents ICaDogEvents;
#endif 	/* __ICaDogEvents_FWD_DEFINED__ */


#ifndef __ICaCat_FWD_DEFINED__
#define __ICaCat_FWD_DEFINED__
typedef interface ICaCat ICaCat;
#endif 	/* __ICaCat_FWD_DEFINED__ */


#ifndef __CaDog_FWD_DEFINED__
#define __CaDog_FWD_DEFINED__

#ifdef __cplusplus
typedef class CaDog CaDog;
#else
typedef struct CaDog CaDog;
#endif /* __cplusplus */

#endif 	/* __CaDog_FWD_DEFINED__ */


#ifndef __CaCat_FWD_DEFINED__
#define __CaCat_FWD_DEFINED__

#ifdef __cplusplus
typedef class CaCat CaCat;
#else
typedef struct CaCat CaCat;
#endif /* __cplusplus */

#endif 	/* __CaCat_FWD_DEFINED__ */


#ifndef __ICaEarthquake_FWD_DEFINED__
#define __ICaEarthquake_FWD_DEFINED__
typedef interface ICaEarthquake ICaEarthquake;
#endif 	/* __ICaEarthquake_FWD_DEFINED__ */


#ifndef __ICaEarthquakeEvents_FWD_DEFINED__
#define __ICaEarthquakeEvents_FWD_DEFINED__
typedef interface ICaEarthquakeEvents ICaEarthquakeEvents;
#endif 	/* __ICaEarthquakeEvents_FWD_DEFINED__ */


#ifndef __CaEarthquake_FWD_DEFINED__
#define __CaEarthquake_FWD_DEFINED__

#ifdef __cplusplus
typedef class CaEarthquake CaEarthquake;
#else
typedef struct CaEarthquake CaEarthquake;
#endif /* __cplusplus */

#endif 	/* __CaEarthquake_FWD_DEFINED__ */


#ifndef __ICaHorse_FWD_DEFINED__
#define __ICaHorse_FWD_DEFINED__
typedef interface ICaHorse ICaHorse;
#endif 	/* __ICaHorse_FWD_DEFINED__ */


#ifndef __CaHorse_FWD_DEFINED__
#define __CaHorse_FWD_DEFINED__

#ifdef __cplusplus
typedef class CaHorse CaHorse;
#else
typedef struct CaHorse CaHorse;
#endif /* __cplusplus */

#endif 	/* __CaHorse_FWD_DEFINED__ */


#ifndef __ICaPlane_FWD_DEFINED__
#define __ICaPlane_FWD_DEFINED__
typedef interface ICaPlane ICaPlane;
#endif 	/* __ICaPlane_FWD_DEFINED__ */


#ifndef __ICaPlaneEvents_FWD_DEFINED__
#define __ICaPlaneEvents_FWD_DEFINED__
typedef interface ICaPlaneEvents ICaPlaneEvents;
#endif 	/* __ICaPlaneEvents_FWD_DEFINED__ */


#ifndef __ICaBomb_FWD_DEFINED__
#define __ICaBomb_FWD_DEFINED__
typedef interface ICaBomb ICaBomb;
#endif 	/* __ICaBomb_FWD_DEFINED__ */


#ifndef __CaPlane_FWD_DEFINED__
#define __CaPlane_FWD_DEFINED__

#ifdef __cplusplus
typedef class CaPlane CaPlane;
#else
typedef struct CaPlane CaPlane;
#endif /* __cplusplus */

#endif 	/* __CaPlane_FWD_DEFINED__ */


#ifndef __CaBomb_FWD_DEFINED__
#define __CaBomb_FWD_DEFINED__

#ifdef __cplusplus
typedef class CaBomb CaBomb;
#else
typedef struct CaBomb CaBomb;
#endif /* __cplusplus */

#endif 	/* __CaBomb_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );

/* interface __MIDL_itf_DogCat_0000 */
/* [local] */








extern RPC_IF_HANDLE __MIDL_itf_DogCat_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_DogCat_0000_v0_0_s_ifspec;


#ifndef __CaDogCatLib_LIBRARY_DEFINED__
#define __CaDogCatLib_LIBRARY_DEFINED__

/* library CaDogCatLib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_CaDogCatLib;

#ifndef __ICaDog_INTERFACE_DEFINED__
#define __ICaDog_INTERFACE_DEFINED__

/* interface ICaDog */
/* [object][oleautomation][dual][uuid] */


EXTERN_C const IID IID_ICaDog;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4341-FFE0-0001-486954656368")
    ICaDog : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE shout( void) = 0;

        virtual HRESULT STDMETHODCALLTYPE bornCat(
            /* [retval][out] */ ICaCat __RPC_FAR *__RPC_FAR *ret) = 0;

        virtual HRESULT STDMETHODCALLTYPE bornDog(
            /* [retval][out] */ ICaDog __RPC_FAR *__RPC_FAR *ret) = 0;

    };

#else 	/* C style interface */

    typedef struct ICaDogVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICaDog __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICaDog __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICaDog __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICaDog __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICaDog __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICaDog __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICaDog __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *shout )(
            ICaDog __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *bornCat )(
            ICaDog __RPC_FAR * This,
            /* [retval][out] */ ICaCat __RPC_FAR *__RPC_FAR *ret);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *bornDog )(
            ICaDog __RPC_FAR * This,
            /* [retval][out] */ ICaDog __RPC_FAR *__RPC_FAR *ret);

        END_INTERFACE
    } ICaDogVtbl;

    interface ICaDog
    {
        CONST_VTBL struct ICaDogVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICaDog_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICaDog_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICaDog_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICaDog_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICaDog_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICaDog_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICaDog_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICaDog_shout(This)	\
    (This)->lpVtbl -> shout(This)

#define ICaDog_bornCat(This,ret)	\
    (This)->lpVtbl -> bornCat(This,ret)

#define ICaDog_bornDog(This,ret)	\
    (This)->lpVtbl -> bornDog(This,ret)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ICaDog_shout_Proxy(
    ICaDog __RPC_FAR * This);


void __RPC_STUB ICaDog_shout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICaDog_bornCat_Proxy(
    ICaDog __RPC_FAR * This,
    /* [retval][out] */ ICaCat __RPC_FAR *__RPC_FAR *ret);


void __RPC_STUB ICaDog_bornCat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICaDog_bornDog_Proxy(
    ICaDog __RPC_FAR * This,
    /* [retval][out] */ ICaDog __RPC_FAR *__RPC_FAR *ret);


void __RPC_STUB ICaDog_bornDog_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICaDog_INTERFACE_DEFINED__ */


#ifndef __ICaDogEvents_DISPINTERFACE_DEFINED__
#define __ICaDogEvents_DISPINTERFACE_DEFINED__

/* dispinterface ICaDogEvents */
/* [helpstring][uuid] */


EXTERN_C const IID DIID_ICaDogEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4341-FFE0-0007-486954656368")
    ICaDogEvents : public IDispatch
    {
    };

#else 	/* C style interface */

    typedef struct ICaDogEventsVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICaDogEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICaDogEvents __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICaDogEvents __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICaDogEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICaDogEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICaDogEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICaDogEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } ICaDogEventsVtbl;

    interface ICaDogEvents
    {
        CONST_VTBL struct ICaDogEventsVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICaDogEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICaDogEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICaDogEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICaDogEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICaDogEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICaDogEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICaDogEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ICaDogEvents_DISPINTERFACE_DEFINED__ */


#ifndef __ICaCat_INTERFACE_DEFINED__
#define __ICaCat_INTERFACE_DEFINED__

/* interface ICaCat */
/* [object][oleautomation][dual][uuid] */


EXTERN_C const IID IID_ICaCat;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4341-FFE1-0001-486954656368")
    ICaCat : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE shout( void) = 0;

        virtual HRESULT STDMETHODCALLTYPE catshout( void) = 0;

    };

#else 	/* C style interface */

    typedef struct ICaCatVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICaCat __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICaCat __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICaCat __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICaCat __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICaCat __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICaCat __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICaCat __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *shout )(
            ICaCat __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *catshout )(
            ICaCat __RPC_FAR * This);

        END_INTERFACE
    } ICaCatVtbl;

    interface ICaCat
    {
        CONST_VTBL struct ICaCatVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICaCat_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICaCat_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICaCat_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICaCat_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICaCat_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICaCat_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICaCat_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICaCat_shout(This)	\
    (This)->lpVtbl -> shout(This)

#define ICaCat_catshout(This)	\
    (This)->lpVtbl -> catshout(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ICaCat_shout_Proxy(
    ICaCat __RPC_FAR * This);


void __RPC_STUB ICaCat_shout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICaCat_catshout_Proxy(
    ICaCat __RPC_FAR * This);


void __RPC_STUB ICaCat_catshout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICaCat_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CaDog;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4341-FFE0-0002-486954656368")
CaDog;
#endif

EXTERN_C const CLSID CLSID_CaCat;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4341-FFE1-0002-486954656368")
CaCat;
#endif

#ifndef __ICaEarthquake_INTERFACE_DEFINED__
#define __ICaEarthquake_INTERFACE_DEFINED__

/* interface ICaEarthquake */
/* [object][helpstring][oleautomation][dual][uuid] */


EXTERN_C const IID IID_ICaEarthquake;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4341-FFE3-0001-486954656368")
    ICaEarthquake : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE quakeNow( void) = 0;

    };

#else 	/* C style interface */

    typedef struct ICaEarthquakeVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICaEarthquake __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICaEarthquake __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICaEarthquake __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICaEarthquake __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICaEarthquake __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICaEarthquake __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICaEarthquake __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *quakeNow )(
            ICaEarthquake __RPC_FAR * This);

        END_INTERFACE
    } ICaEarthquakeVtbl;

    interface ICaEarthquake
    {
        CONST_VTBL struct ICaEarthquakeVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICaEarthquake_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICaEarthquake_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICaEarthquake_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICaEarthquake_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICaEarthquake_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICaEarthquake_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICaEarthquake_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICaEarthquake_quakeNow(This)	\
    (This)->lpVtbl -> quakeNow(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ICaEarthquake_quakeNow_Proxy(
    ICaEarthquake __RPC_FAR * This);


void __RPC_STUB ICaEarthquake_quakeNow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICaEarthquake_INTERFACE_DEFINED__ */


#ifndef __ICaEarthquakeEvents_DISPINTERFACE_DEFINED__
#define __ICaEarthquakeEvents_DISPINTERFACE_DEFINED__

/* dispinterface ICaEarthquakeEvents */
/* [helpstring][uuid] */


EXTERN_C const IID DIID_ICaEarthquakeEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4341-FFE4-0001-486954656368")
    ICaEarthquakeEvents : public IDispatch
    {
    };

#else 	/* C style interface */

    typedef struct ICaEarthquakeEventsVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICaEarthquakeEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICaEarthquakeEvents __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICaEarthquakeEvents __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICaEarthquakeEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICaEarthquakeEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICaEarthquakeEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICaEarthquakeEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } ICaEarthquakeEventsVtbl;

    interface ICaEarthquakeEvents
    {
        CONST_VTBL struct ICaEarthquakeEventsVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICaEarthquakeEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICaEarthquakeEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICaEarthquakeEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICaEarthquakeEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICaEarthquakeEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICaEarthquakeEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICaEarthquakeEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ICaEarthquakeEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CaEarthquake;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4341-FFE3-0002-486954656368")
CaEarthquake;
#endif

#ifndef __ICaHorse_DISPINTERFACE_DEFINED__
#define __ICaHorse_DISPINTERFACE_DEFINED__

/* dispinterface ICaHorse */
/* [helpstring][uuid] */


EXTERN_C const IID DIID_ICaHorse;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4341-FFE5-0001-486954656368")
    ICaHorse : public IDispatch
    {
    };

#else 	/* C style interface */

    typedef struct ICaHorseVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICaHorse __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICaHorse __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICaHorse __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICaHorse __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICaHorse __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICaHorse __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICaHorse __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } ICaHorseVtbl;

    interface ICaHorse
    {
        CONST_VTBL struct ICaHorseVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICaHorse_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICaHorse_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICaHorse_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICaHorse_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICaHorse_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICaHorse_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICaHorse_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ICaHorse_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CaHorse;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4341-FFE5-0002-486954656368")
CaHorse;
#endif

#ifndef __ICaPlane_INTERFACE_DEFINED__
#define __ICaPlane_INTERFACE_DEFINED__

/* interface ICaPlane */
/* [object][helpstring][oleautomation][dual][uuid] */


EXTERN_C const IID IID_ICaPlane;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4341-FFE6-0001-486954656368")
    ICaPlane : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE fly( void) = 0;

    };

#else 	/* C style interface */

    typedef struct ICaPlaneVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICaPlane __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICaPlane __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICaPlane __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICaPlane __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICaPlane __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICaPlane __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICaPlane __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *fly )(
            ICaPlane __RPC_FAR * This);

        END_INTERFACE
    } ICaPlaneVtbl;

    interface ICaPlane
    {
        CONST_VTBL struct ICaPlaneVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICaPlane_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICaPlane_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICaPlane_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICaPlane_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICaPlane_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICaPlane_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICaPlane_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICaPlane_fly(This)	\
    (This)->lpVtbl -> fly(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ICaPlane_fly_Proxy(
    ICaPlane __RPC_FAR * This);


void __RPC_STUB ICaPlane_fly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICaPlane_INTERFACE_DEFINED__ */


#ifndef __ICaPlaneEvents_DISPINTERFACE_DEFINED__
#define __ICaPlaneEvents_DISPINTERFACE_DEFINED__

/* dispinterface ICaPlaneEvents */
/* [helpstring][uuid] */


EXTERN_C const IID DIID_ICaPlaneEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4341-FFE6-0017-486954656368")
    ICaPlaneEvents : public IDispatch
    {
    };

#else 	/* C style interface */

    typedef struct ICaPlaneEventsVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICaPlaneEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICaPlaneEvents __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICaPlaneEvents __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICaPlaneEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICaPlaneEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICaPlaneEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICaPlaneEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } ICaPlaneEventsVtbl;

    interface ICaPlaneEvents
    {
        CONST_VTBL struct ICaPlaneEventsVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICaPlaneEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICaPlaneEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICaPlaneEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICaPlaneEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICaPlaneEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICaPlaneEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICaPlaneEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ICaPlaneEvents_DISPINTERFACE_DEFINED__ */


#ifndef __ICaBomb_INTERFACE_DEFINED__
#define __ICaBomb_INTERFACE_DEFINED__

/* interface ICaBomb */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_ICaBomb;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("7ADFF5A5-3CE9-4E93-92A0-1EC38B09BA19")
    ICaBomb : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE bomb( void) = 0;

        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_p1(
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;

        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_p1(
            /* [in] */ long newVal) = 0;

    };

#else 	/* C style interface */

    typedef struct ICaBombVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICaBomb __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICaBomb __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICaBomb __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICaBomb __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICaBomb __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICaBomb __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICaBomb __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *bomb )(
            ICaBomb __RPC_FAR * This);

        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_p1 )(
            ICaBomb __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);

        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_p1 )(
            ICaBomb __RPC_FAR * This,
            /* [in] */ long newVal);

        END_INTERFACE
    } ICaBombVtbl;

    interface ICaBomb
    {
        CONST_VTBL struct ICaBombVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICaBomb_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICaBomb_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICaBomb_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICaBomb_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICaBomb_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICaBomb_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICaBomb_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICaBomb_bomb(This)	\
    (This)->lpVtbl -> bomb(This)

#define ICaBomb_get_p1(This,pVal)	\
    (This)->lpVtbl -> get_p1(This,pVal)

#define ICaBomb_put_p1(This,newVal)	\
    (This)->lpVtbl -> put_p1(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICaBomb_bomb_Proxy(
    ICaBomb __RPC_FAR * This);


void __RPC_STUB ICaBomb_bomb_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICaBomb_get_p1_Proxy(
    ICaBomb __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ICaBomb_get_p1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ICaBomb_put_p1_Proxy(
    ICaBomb __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB ICaBomb_put_p1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICaBomb_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CaPlane;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4341-FFE6-0002-486954656368")
CaPlane;
#endif

EXTERN_C const CLSID CLSID_CaBomb;

#ifdef __cplusplus

class DECLSPEC_UUID("A2264F9F-35E7-4D88-B662-E349D439225D")
CaBomb;
#endif
#endif /* __CaDogCatLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
