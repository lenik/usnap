/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Jul 28 21:47:18 2003
 */
/* Compiler settings for C:\s_prjs\Data Rescuer\modules\HexEditCtl\HexEdit\HexEdit.idl:
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

#ifndef __HexEdit_h__
#define __HexEdit_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __IHexEditCtl_FWD_DEFINED__
#define __IHexEditCtl_FWD_DEFINED__
typedef interface IHexEditCtl IHexEditCtl;
#endif 	/* __IHexEditCtl_FWD_DEFINED__ */


#ifndef ___IHexEditCtlEvents_FWD_DEFINED__
#define ___IHexEditCtlEvents_FWD_DEFINED__
typedef interface _IHexEditCtlEvents _IHexEditCtlEvents;
#endif 	/* ___IHexEditCtlEvents_FWD_DEFINED__ */


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
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );

#ifndef __IHexEditCtl_INTERFACE_DEFINED__
#define __IHexEditCtl_INTERFACE_DEFINED__

/* interface IHexEditCtl */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IHexEditCtl;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("7D05FFFF-4764-4EAC-9380-C557054F5442")
    IHexEditCtl : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct IHexEditCtlVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IHexEditCtl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IHexEditCtl __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IHexEditCtl __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IHexEditCtl __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IHexEditCtl __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IHexEditCtl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IHexEditCtl __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } IHexEditCtlVtbl;

    interface IHexEditCtl
    {
        CONST_VTBL struct IHexEditCtlVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IHexEditCtl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHexEditCtl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHexEditCtl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHexEditCtl_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IHexEditCtl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IHexEditCtl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IHexEditCtl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHexEditCtl_INTERFACE_DEFINED__ */



#ifndef __HEXEDITLib_LIBRARY_DEFINED__
#define __HEXEDITLib_LIBRARY_DEFINED__

/* library HEXEDITLib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_HEXEDITLib;

#ifndef ___IHexEditCtlEvents_DISPINTERFACE_DEFINED__
#define ___IHexEditCtlEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IHexEditCtlEvents */
/* [helpstring][uuid] */


EXTERN_C const IID DIID__IHexEditCtlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("30A34A3A-BB27-4E67-B99E-237AE43F09E0")
    _IHexEditCtlEvents : public IDispatch
    {
    };

#else 	/* C style interface */

    typedef struct _IHexEditCtlEventsVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            _IHexEditCtlEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            _IHexEditCtlEvents __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            _IHexEditCtlEvents __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            _IHexEditCtlEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            _IHexEditCtlEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            _IHexEditCtlEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            _IHexEditCtlEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } _IHexEditCtlEventsVtbl;

    interface _IHexEditCtlEvents
    {
        CONST_VTBL struct _IHexEditCtlEventsVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define _IHexEditCtlEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IHexEditCtlEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IHexEditCtlEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IHexEditCtlEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IHexEditCtlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IHexEditCtlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IHexEditCtlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IHexEditCtlEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_HexEditCtl;

#ifdef __cplusplus

class DECLSPEC_UUID("C9971570-4D04-48F5-A3E4-5C2AD6E85584")
HexEditCtl;
#endif
#endif /* __HEXEDITLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
