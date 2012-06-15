/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Jul 16 19:47:52 2003
 */
/* Compiler settings for C:\S_PRJS\DATA RESCUER\MODULES\DiskDriveKernel\DiskDriveKernel.idl:
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

#ifndef __DiskDriveKernel_h__
#define __DiskDriveKernel_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __ISysDriveEnum_FWD_DEFINED__
#define __ISysDriveEnum_FWD_DEFINED__
typedef interface ISysDriveEnum ISysDriveEnum;
#endif 	/* __ISysDriveEnum_FWD_DEFINED__ */


#ifndef ___ISysDriveEnumEvents_FWD_DEFINED__
#define ___ISysDriveEnumEvents_FWD_DEFINED__
typedef interface _ISysDriveEnumEvents _ISysDriveEnumEvents;
#endif 	/* ___ISysDriveEnumEvents_FWD_DEFINED__ */


#ifndef __SysDriveEnum_FWD_DEFINED__
#define __SysDriveEnum_FWD_DEFINED__

#ifdef __cplusplus
typedef class SysDriveEnum SysDriveEnum;
#else
typedef struct SysDriveEnum SysDriveEnum;
#endif /* __cplusplus */

#endif 	/* __SysDriveEnum_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );

#ifndef __ISysDriveEnum_INTERFACE_DEFINED__
#define __ISysDriveEnum_INTERFACE_DEFINED__

/* interface ISysDriveEnum */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_ISysDriveEnum;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("8E152B2A-C5DB-4B5E-91A5-44D16D229B9D")
    ISysDriveEnum : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct ISysDriveEnumVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ISysDriveEnum __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ISysDriveEnum __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ISysDriveEnum __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ISysDriveEnum __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ISysDriveEnum __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ISysDriveEnum __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ISysDriveEnum __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } ISysDriveEnumVtbl;

    interface ISysDriveEnum
    {
        CONST_VTBL struct ISysDriveEnumVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ISysDriveEnum_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISysDriveEnum_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISysDriveEnum_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISysDriveEnum_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISysDriveEnum_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISysDriveEnum_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISysDriveEnum_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISysDriveEnum_INTERFACE_DEFINED__ */



#ifndef __DiskDriveKernel_LIBRARY_DEFINED__
#define __DiskDriveKernel_LIBRARY_DEFINED__

/* library DiskDriveKernel */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_DiskDriveKernel;

#ifndef ___ISysDriveEnumEvents_DISPINTERFACE_DEFINED__
#define ___ISysDriveEnumEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ISysDriveEnumEvents */
/* [helpstring][uuid] */


EXTERN_C const IID DIID__ISysDriveEnumEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("8CD361E9-1B05-4798-87EE-C51DEDD87999")
    _ISysDriveEnumEvents : public IDispatch
    {
    };

#else 	/* C style interface */

    typedef struct _ISysDriveEnumEventsVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            _ISysDriveEnumEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            _ISysDriveEnumEvents __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            _ISysDriveEnumEvents __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            _ISysDriveEnumEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            _ISysDriveEnumEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            _ISysDriveEnumEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            _ISysDriveEnumEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } _ISysDriveEnumEventsVtbl;

    interface _ISysDriveEnumEvents
    {
        CONST_VTBL struct _ISysDriveEnumEventsVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define _ISysDriveEnumEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _ISysDriveEnumEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _ISysDriveEnumEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _ISysDriveEnumEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _ISysDriveEnumEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _ISysDriveEnumEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _ISysDriveEnumEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ISysDriveEnumEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SysDriveEnum;

#ifdef __cplusplus

class DECLSPEC_UUID("1C0EA6C8-A4AB-4987-BEE8-57FDFF6051F4")
SysDriveEnum;
#endif
#endif /* __DiskDriveKernel_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
