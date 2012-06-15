/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Jul 21 18:16:30 2003
 */
/* Compiler settings for D:\HexEditCtl\HexEditCtl\HexEditCtl.odl:
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

#ifndef __HexEditCtl_i_h__
#define __HexEditCtl_i_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef ___DHexEditCtl_FWD_DEFINED__
#define ___DHexEditCtl_FWD_DEFINED__
typedef interface _DHexEditCtl _DHexEditCtl;
#endif 	/* ___DHexEditCtl_FWD_DEFINED__ */


#ifndef ___DHexEditCtlEvents_FWD_DEFINED__
#define ___DHexEditCtlEvents_FWD_DEFINED__
typedef interface _DHexEditCtlEvents _DHexEditCtlEvents;
#endif 	/* ___DHexEditCtlEvents_FWD_DEFINED__ */


#ifndef __HexEditCtl_FWD_DEFINED__
#define __HexEditCtl_FWD_DEFINED__

#ifdef __cplusplus
typedef class HexEditCtl HexEditCtl;
#else
typedef struct HexEditCtl HexEditCtl;
#endif /* __cplusplus */

#endif 	/* __HexEditCtl_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );


#ifndef __HEXEDITCTLLib_LIBRARY_DEFINED__
#define __HEXEDITCTLLib_LIBRARY_DEFINED__

/* library HEXEDITCTLLib */
/* [control][helpstring][helpfile][version][uuid] */


EXTERN_C const IID LIBID_HEXEDITCTLLib;

#ifndef ___DHexEditCtl_DISPINTERFACE_DEFINED__
#define ___DHexEditCtl_DISPINTERFACE_DEFINED__

/* dispinterface _DHexEditCtl */
/* [hidden][helpstring][uuid] */


EXTERN_C const IID DIID__DHexEditCtl;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("194FFE66-E6EC-47FE-8A71-7B274C0C3A7F")
    _DHexEditCtl : public IDispatch
    {
    };

#else 	/* C style interface */

    typedef struct _DHexEditCtlVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            _DHexEditCtl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            _DHexEditCtl __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            _DHexEditCtl __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            _DHexEditCtl __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            _DHexEditCtl __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            _DHexEditCtl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            _DHexEditCtl __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } _DHexEditCtlVtbl;

    interface _DHexEditCtl
    {
        CONST_VTBL struct _DHexEditCtlVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define _DHexEditCtl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _DHexEditCtl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _DHexEditCtl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _DHexEditCtl_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _DHexEditCtl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _DHexEditCtl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _DHexEditCtl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DHexEditCtl_DISPINTERFACE_DEFINED__ */


#ifndef ___DHexEditCtlEvents_DISPINTERFACE_DEFINED__
#define ___DHexEditCtlEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DHexEditCtlEvents */
/* [helpstring][uuid] */


EXTERN_C const IID DIID__DHexEditCtlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("F2BFA29B-D63D-471E-A3C2-4A3C98AF57FF")
    _DHexEditCtlEvents : public IDispatch
    {
    };

#else 	/* C style interface */

    typedef struct _DHexEditCtlEventsVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            _DHexEditCtlEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            _DHexEditCtlEvents __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            _DHexEditCtlEvents __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            _DHexEditCtlEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            _DHexEditCtlEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            _DHexEditCtlEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            _DHexEditCtlEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } _DHexEditCtlEventsVtbl;

    interface _DHexEditCtlEvents
    {
        CONST_VTBL struct _DHexEditCtlEventsVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define _DHexEditCtlEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _DHexEditCtlEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _DHexEditCtlEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _DHexEditCtlEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _DHexEditCtlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _DHexEditCtlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _DHexEditCtlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DHexEditCtlEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_HexEditCtl;

#ifdef __cplusplus

class DECLSPEC_UUID("B9208ED7-2CCF-479A-ACE7-12071F12A9BB")
HexEditCtl;
#endif
#endif /* __HEXEDITCTLLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
