

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Wed Aug 20 14:05:54 2008
 */
/* Compiler settings for .\winexmagicinfo.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data
    VC __declspec() decoration level:
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


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

#ifndef __winexmagicinfo_h__
#define __winexmagicinfo_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */

#ifndef __ISettings_FWD_DEFINED__
#define __ISettings_FWD_DEFINED__
typedef interface ISettings ISettings;
#endif 	/* __ISettings_FWD_DEFINED__ */


#ifndef __IFragmentsColumn_FWD_DEFINED__
#define __IFragmentsColumn_FWD_DEFINED__
typedef interface IFragmentsColumn IFragmentsColumn;
#endif 	/* __IFragmentsColumn_FWD_DEFINED__ */


#ifndef __Settings_FWD_DEFINED__
#define __Settings_FWD_DEFINED__

#ifdef __cplusplus
typedef class Settings Settings;
#else
typedef struct Settings Settings;
#endif /* __cplusplus */

#endif 	/* __Settings_FWD_DEFINED__ */


#ifndef __FragmentsColumn_FWD_DEFINED__
#define __FragmentsColumn_FWD_DEFINED__

#ifdef __cplusplus
typedef class FragmentsColumn FragmentsColumn;
#else
typedef struct FragmentsColumn FragmentsColumn;
#endif /* __cplusplus */

#endif 	/* __FragmentsColumn_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif


#ifndef __ISettings_INTERFACE_DEFINED__
#define __ISettings_INTERFACE_DEFINED__

/* interface ISettings */
/* [unique][helpstring][nonextensible][dual][uuid][object] */


EXTERN_C const IID IID_ISettings;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("535E61FA-3432-4A9C-A613-7D14A5D3489C")
    ISettings : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct ISettingsVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            ISettings * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */
            __RPC__deref_out  void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            ISettings * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            ISettings * This);

        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )(
            ISettings * This,
            /* [out] */ UINT *pctinfo);

        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )(
            ISettings * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);

        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )(
            ISettings * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )(
            ISettings * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);

        END_INTERFACE
    } ISettingsVtbl;

    interface ISettings
    {
        CONST_VTBL struct ISettingsVtbl *lpVtbl;
    };



#ifdef COBJMACROS


#define ISettings_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )

#define ISettings_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) )

#define ISettings_Release(This)	\
    ( (This)->lpVtbl -> Release(This) )


#define ISettings_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) )

#define ISettings_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) )

#define ISettings_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) )

#define ISettings_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) )


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISettings_INTERFACE_DEFINED__ */


#ifndef __IFragmentsColumn_INTERFACE_DEFINED__
#define __IFragmentsColumn_INTERFACE_DEFINED__

/* interface IFragmentsColumn */
/* [unique][helpstring][nonextensible][dual][uuid][object] */


EXTERN_C const IID IID_IFragmentsColumn;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("F8EC50B7-C58F-4716-856B-0103530E2D32")
    IFragmentsColumn : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE init( void) = 0;

    };

#else 	/* C style interface */

    typedef struct IFragmentsColumnVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IFragmentsColumn * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */
            __RPC__deref_out  void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IFragmentsColumn * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IFragmentsColumn * This);

        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )(
            IFragmentsColumn * This,
            /* [out] */ UINT *pctinfo);

        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )(
            IFragmentsColumn * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);

        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )(
            IFragmentsColumn * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )(
            IFragmentsColumn * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *init )(
            IFragmentsColumn * This);

        END_INTERFACE
    } IFragmentsColumnVtbl;

    interface IFragmentsColumn
    {
        CONST_VTBL struct IFragmentsColumnVtbl *lpVtbl;
    };



#ifdef COBJMACROS


#define IFragmentsColumn_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )

#define IFragmentsColumn_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) )

#define IFragmentsColumn_Release(This)	\
    ( (This)->lpVtbl -> Release(This) )


#define IFragmentsColumn_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) )

#define IFragmentsColumn_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) )

#define IFragmentsColumn_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) )

#define IFragmentsColumn_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) )


#define IFragmentsColumn_init(This)	\
    ( (This)->lpVtbl -> init(This) )

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFragmentsColumn_INTERFACE_DEFINED__ */



#ifndef __WinexMagicInfo_LIBRARY_DEFINED__
#define __WinexMagicInfo_LIBRARY_DEFINED__

/* library WinexMagicInfo */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_WinexMagicInfo;

EXTERN_C const CLSID CLSID_Settings;

#ifdef __cplusplus

class DECLSPEC_UUID("2295AED8-B593-4390-A7CB-6700DC829C5C")
Settings;
#endif

EXTERN_C const CLSID CLSID_FragmentsColumn;

#ifdef __cplusplus

class DECLSPEC_UUID("B7BD4C40-C269-4C65-AB8D-FD0B3DFB77A9")
FragmentsColumn;
#endif
#endif /* __WinexMagicInfo_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
