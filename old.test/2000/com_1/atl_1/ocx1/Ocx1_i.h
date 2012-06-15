/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Mar 28 18:27:39 2001
 */
/* Compiler settings for V:\temp\atl01\ocx1\ocx1.odl:
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

#ifndef __Ocx1_i_h__
#define __Ocx1_i_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef ___DOcx1_FWD_DEFINED__
#define ___DOcx1_FWD_DEFINED__
typedef interface _DOcx1 _DOcx1;
#endif 	/* ___DOcx1_FWD_DEFINED__ */


#ifndef ___DOcx1Events_FWD_DEFINED__
#define ___DOcx1Events_FWD_DEFINED__
typedef interface _DOcx1Events _DOcx1Events;
#endif 	/* ___DOcx1Events_FWD_DEFINED__ */


#ifndef __IHelloControl_FWD_DEFINED__
#define __IHelloControl_FWD_DEFINED__
typedef interface IHelloControl IHelloControl;
#endif 	/* __IHelloControl_FWD_DEFINED__ */


#ifndef __Ocx1_FWD_DEFINED__
#define __Ocx1_FWD_DEFINED__

#ifdef __cplusplus
typedef class Ocx1 Ocx1;
#else
typedef struct Ocx1 Ocx1;
#endif /* __cplusplus */

#endif 	/* __Ocx1_FWD_DEFINED__ */


#ifndef __HelloControl_FWD_DEFINED__
#define __HelloControl_FWD_DEFINED__

#ifdef __cplusplus
typedef class HelloControl HelloControl;
#else
typedef struct HelloControl HelloControl;
#endif /* __cplusplus */

#endif 	/* __HelloControl_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );


#ifndef __OCX1Lib_LIBRARY_DEFINED__
#define __OCX1Lib_LIBRARY_DEFINED__

/* library OCX1Lib */
/* [control][helpstring][helpfile][version][uuid] */


EXTERN_C const IID LIBID_OCX1Lib;

#ifndef ___DOcx1_DISPINTERFACE_DEFINED__
#define ___DOcx1_DISPINTERFACE_DEFINED__

/* dispinterface _DOcx1 */
/* [hidden][helpstring][uuid] */


EXTERN_C const IID DIID__DOcx1;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("8E36F09E-BC6A-4A8E-8B7F-7895349F5DB3")
    _DOcx1 : public IDispatch
    {
    };

#else 	/* C style interface */

    typedef struct _DOcx1Vtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            _DOcx1 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            _DOcx1 __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            _DOcx1 __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            _DOcx1 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            _DOcx1 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            _DOcx1 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            _DOcx1 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } _DOcx1Vtbl;

    interface _DOcx1
    {
        CONST_VTBL struct _DOcx1Vtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define _DOcx1_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _DOcx1_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _DOcx1_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _DOcx1_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _DOcx1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _DOcx1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _DOcx1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DOcx1_DISPINTERFACE_DEFINED__ */


#ifndef ___DOcx1Events_DISPINTERFACE_DEFINED__
#define ___DOcx1Events_DISPINTERFACE_DEFINED__

/* dispinterface _DOcx1Events */
/* [helpstring][uuid] */


EXTERN_C const IID DIID__DOcx1Events;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("19548CCB-D942-42A6-B10A-A986E01E5865")
    _DOcx1Events : public IDispatch
    {
    };

#else 	/* C style interface */

    typedef struct _DOcx1EventsVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            _DOcx1Events __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            _DOcx1Events __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            _DOcx1Events __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            _DOcx1Events __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            _DOcx1Events __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            _DOcx1Events __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            _DOcx1Events __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } _DOcx1EventsVtbl;

    interface _DOcx1Events
    {
        CONST_VTBL struct _DOcx1EventsVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define _DOcx1Events_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _DOcx1Events_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _DOcx1Events_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _DOcx1Events_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _DOcx1Events_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _DOcx1Events_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _DOcx1Events_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DOcx1Events_DISPINTERFACE_DEFINED__ */


#ifndef __IHelloControl_INTERFACE_DEFINED__
#define __IHelloControl_INTERFACE_DEFINED__

/* interface IHelloControl */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IHelloControl;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("6F723297-7201-4B7A-BD51-A87148698788")
    IHelloControl : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct IHelloControlVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IHelloControl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IHelloControl __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IHelloControl __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IHelloControl __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IHelloControl __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IHelloControl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IHelloControl __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } IHelloControlVtbl;

    interface IHelloControl
    {
        CONST_VTBL struct IHelloControlVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IHelloControl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHelloControl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHelloControl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHelloControl_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IHelloControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IHelloControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IHelloControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHelloControl_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Ocx1;

#ifdef __cplusplus

class DECLSPEC_UUID("B06B99C6-E6A2-4C0A-97F4-6EA9D2756BDF")
Ocx1;
#endif

EXTERN_C const CLSID CLSID_HelloControl;

#ifdef __cplusplus

class DECLSPEC_UUID("E2CD5265-B80F-4A18-9AA2-71FEB22C6DF2")
HelloControl;
#endif
#endif /* __OCX1Lib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
