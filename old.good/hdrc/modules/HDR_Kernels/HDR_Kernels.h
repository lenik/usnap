/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Aug 13 10:32:42 2003
 */
/* Compiler settings for C:\s_prjs\Data Rescuer\modules\HDR_Kernels\HDR_Kernels.idl:
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

#ifndef __HDR_Kernels_h__
#define __HDR_Kernels_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __IDriverLoader_FWD_DEFINED__
#define __IDriverLoader_FWD_DEFINED__
typedef interface IDriverLoader IDriverLoader;
#endif 	/* __IDriverLoader_FWD_DEFINED__ */


#ifndef __IDriverEnum_FWD_DEFINED__
#define __IDriverEnum_FWD_DEFINED__
typedef interface IDriverEnum IDriverEnum;
#endif 	/* __IDriverEnum_FWD_DEFINED__ */


#ifndef __ILDAccess_FWD_DEFINED__
#define __ILDAccess_FWD_DEFINED__
typedef interface ILDAccess ILDAccess;
#endif 	/* __ILDAccess_FWD_DEFINED__ */


#ifndef __ILDCache_FWD_DEFINED__
#define __ILDCache_FWD_DEFINED__
typedef interface ILDCache ILDCache;
#endif 	/* __ILDCache_FWD_DEFINED__ */


#ifndef __ILDLargeIO_FWD_DEFINED__
#define __ILDLargeIO_FWD_DEFINED__
typedef interface ILDLargeIO ILDLargeIO;
#endif 	/* __ILDLargeIO_FWD_DEFINED__ */


#ifndef __IWin32DiskLD_FWD_DEFINED__
#define __IWin32DiskLD_FWD_DEFINED__
typedef interface IWin32DiskLD IWin32DiskLD;
#endif 	/* __IWin32DiskLD_FWD_DEFINED__ */


#ifndef __IDiskAddress_FWD_DEFINED__
#define __IDiskAddress_FWD_DEFINED__
typedef interface IDiskAddress IDiskAddress;
#endif 	/* __IDiskAddress_FWD_DEFINED__ */


#ifndef ___IDriverEnumEvents_FWD_DEFINED__
#define ___IDriverEnumEvents_FWD_DEFINED__
typedef interface _IDriverEnumEvents _IDriverEnumEvents;
#endif 	/* ___IDriverEnumEvents_FWD_DEFINED__ */


#ifndef ___ILDLargeIOEvents_FWD_DEFINED__
#define ___ILDLargeIOEvents_FWD_DEFINED__
typedef interface _ILDLargeIOEvents _ILDLargeIOEvents;
#endif 	/* ___ILDLargeIOEvents_FWD_DEFINED__ */


#ifndef ___IDiskAddressEvents_FWD_DEFINED__
#define ___IDiskAddressEvents_FWD_DEFINED__
typedef interface _IDiskAddressEvents _IDiskAddressEvents;
#endif 	/* ___IDiskAddressEvents_FWD_DEFINED__ */


#ifndef __Win32DiskLD_FWD_DEFINED__
#define __Win32DiskLD_FWD_DEFINED__

#ifdef __cplusplus
typedef class Win32DiskLD Win32DiskLD;
#else
typedef struct Win32DiskLD Win32DiskLD;
#endif /* __cplusplus */

#endif 	/* __Win32DiskLD_FWD_DEFINED__ */


#ifndef __NetworkDiskLD_FWD_DEFINED__
#define __NetworkDiskLD_FWD_DEFINED__

#ifdef __cplusplus
typedef class NetworkDiskLD NetworkDiskLD;
#else
typedef struct NetworkDiskLD NetworkDiskLD;
#endif /* __cplusplus */

#endif 	/* __NetworkDiskLD_FWD_DEFINED__ */


#ifndef __DriverManager_FWD_DEFINED__
#define __DriverManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class DriverManager DriverManager;
#else
typedef struct DriverManager DriverManager;
#endif /* __cplusplus */

#endif 	/* __DriverManager_FWD_DEFINED__ */


#ifndef __DiskAddress_FWD_DEFINED__
#define __DiskAddress_FWD_DEFINED__

#ifdef __cplusplus
typedef class DiskAddress DiskAddress;
#else
typedef struct DiskAddress DiskAddress;
#endif /* __cplusplus */

#endif 	/* __DiskAddress_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );

/* interface __MIDL_itf_HDR_Kernels_0000 */
/* [local] */









enum SeekRelationConstants
    {	srBegin	= 0,
	srEnd	= srBegin + 1,
	srCurrent	= srEnd + 1
    };

enum AddressModeConstants
    {	amLBA	= 0,
	amCHS	= amLBA + 1,
	amByte	= amCHS + 1
    };


extern RPC_IF_HANDLE __MIDL_itf_HDR_Kernels_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_HDR_Kernels_0000_v0_0_s_ifspec;

#ifndef __IDriverLoader_INTERFACE_DEFINED__
#define __IDriverLoader_INTERFACE_DEFINED__

/* interface IDriverLoader */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IDriverLoader;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("2DD54D33-AC77-4189-AB52-8CA278A02D8D")
    IDriverLoader : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadDriver(
            /* [in] */ BSTR Name,
            /* [retval][out] */ ILDAccess __RPC_FAR *__RPC_FAR *LinearDevice) = 0;

    };

#else 	/* C style interface */

    typedef struct IDriverLoaderVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IDriverLoader __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IDriverLoader __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IDriverLoader __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IDriverLoader __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IDriverLoader __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IDriverLoader __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IDriverLoader __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadDriver )(
            IDriverLoader __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ ILDAccess __RPC_FAR *__RPC_FAR *LinearDevice);

        END_INTERFACE
    } IDriverLoaderVtbl;

    interface IDriverLoader
    {
        CONST_VTBL struct IDriverLoaderVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IDriverLoader_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDriverLoader_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDriverLoader_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDriverLoader_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDriverLoader_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDriverLoader_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDriverLoader_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDriverLoader_LoadDriver(This,Name,LinearDevice)	\
    (This)->lpVtbl -> LoadDriver(This,Name,LinearDevice)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDriverLoader_LoadDriver_Proxy(
    IDriverLoader __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [retval][out] */ ILDAccess __RPC_FAR *__RPC_FAR *LinearDevice);


void __RPC_STUB IDriverLoader_LoadDriver_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDriverLoader_INTERFACE_DEFINED__ */


#ifndef __IDriverEnum_INTERFACE_DEFINED__
#define __IDriverEnum_INTERFACE_DEFINED__

/* interface IDriverEnum */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IDriverEnum;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("2DD54D34-AC77-4189-AB52-8CA278A02D8D")
    IDriverEnum : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDriversCount(
            /* [retval][out] */ int __RPC_FAR *Count) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDriverName(
            /* [in] */ int Index,
            /* [retval][out] */ BSTR __RPC_FAR *Name) = 0;

    };

#else 	/* C style interface */

    typedef struct IDriverEnumVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IDriverEnum __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IDriverEnum __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IDriverEnum __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IDriverEnum __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IDriverEnum __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IDriverEnum __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IDriverEnum __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDriversCount )(
            IDriverEnum __RPC_FAR * This,
            /* [retval][out] */ int __RPC_FAR *Count);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDriverName )(
            IDriverEnum __RPC_FAR * This,
            /* [in] */ int Index,
            /* [retval][out] */ BSTR __RPC_FAR *Name);

        END_INTERFACE
    } IDriverEnumVtbl;

    interface IDriverEnum
    {
        CONST_VTBL struct IDriverEnumVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IDriverEnum_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDriverEnum_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDriverEnum_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDriverEnum_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDriverEnum_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDriverEnum_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDriverEnum_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDriverEnum_GetDriversCount(This,Count)	\
    (This)->lpVtbl -> GetDriversCount(This,Count)

#define IDriverEnum_GetDriverName(This,Index,Name)	\
    (This)->lpVtbl -> GetDriverName(This,Index,Name)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDriverEnum_GetDriversCount_Proxy(
    IDriverEnum __RPC_FAR * This,
    /* [retval][out] */ int __RPC_FAR *Count);


void __RPC_STUB IDriverEnum_GetDriversCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDriverEnum_GetDriverName_Proxy(
    IDriverEnum __RPC_FAR * This,
    /* [in] */ int Index,
    /* [retval][out] */ BSTR __RPC_FAR *Name);


void __RPC_STUB IDriverEnum_GetDriverName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDriverEnum_INTERFACE_DEFINED__ */


#ifndef __ILDAccess_INTERFACE_DEFINED__
#define __ILDAccess_INTERFACE_DEFINED__

/* interface ILDAccess */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_ILDAccess;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("BA6E48AA-25CC-45A4-BB80-56779F68D475")
    ILDAccess : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadSector(
            /* [in] */ long LBA,
            /* [in] */ long nSectors,
            /* [size_is][out] */ BYTE __RPC_FAR *Buffer,
            /* [retval][out] */ long __RPC_FAR *nRead) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteSector(
            /* [in] */ long LBA,
            /* [in] */ long nSectors,
            /* [size_is][in] */ BYTE __RPC_FAR *Buffer,
            /* [retval][out] */ long __RPC_FAR *nWritten) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Read(
            /* [in] */ long cbSize,
            /* [size_is][out] */ BYTE __RPC_FAR *pbBuffer,
            /* [retval][out] */ long __RPC_FAR *pcbRead) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Write(
            /* [in] */ long cbSize,
            /* [size_is][in] */ BYTE __RPC_FAR *pbBuffer,
            /* [retval][out] */ long __RPC_FAR *pcbWritten) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Seek(
            /* [in] */ long Low,
            /* [in] */ long High,
            /* [in] */ enum SeekRelationConstants Rel) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPosition(
            /* [out] */ long __RPC_FAR *LBA,
            /* [out] */ long __RPC_FAR *BytesOffset) = 0;

    };

#else 	/* C style interface */

    typedef struct ILDAccessVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ILDAccess __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ILDAccess __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ILDAccess __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ILDAccess __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ILDAccess __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ILDAccess __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ILDAccess __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadSector )(
            ILDAccess __RPC_FAR * This,
            /* [in] */ long LBA,
            /* [in] */ long nSectors,
            /* [size_is][out] */ BYTE __RPC_FAR *Buffer,
            /* [retval][out] */ long __RPC_FAR *nRead);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteSector )(
            ILDAccess __RPC_FAR * This,
            /* [in] */ long LBA,
            /* [in] */ long nSectors,
            /* [size_is][in] */ BYTE __RPC_FAR *Buffer,
            /* [retval][out] */ long __RPC_FAR *nWritten);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Read )(
            ILDAccess __RPC_FAR * This,
            /* [in] */ long cbSize,
            /* [size_is][out] */ BYTE __RPC_FAR *pbBuffer,
            /* [retval][out] */ long __RPC_FAR *pcbRead);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Write )(
            ILDAccess __RPC_FAR * This,
            /* [in] */ long cbSize,
            /* [size_is][in] */ BYTE __RPC_FAR *pbBuffer,
            /* [retval][out] */ long __RPC_FAR *pcbWritten);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Seek )(
            ILDAccess __RPC_FAR * This,
            /* [in] */ long Low,
            /* [in] */ long High,
            /* [in] */ enum SeekRelationConstants Rel);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPosition )(
            ILDAccess __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *LBA,
            /* [out] */ long __RPC_FAR *BytesOffset);

        END_INTERFACE
    } ILDAccessVtbl;

    interface ILDAccess
    {
        CONST_VTBL struct ILDAccessVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ILDAccess_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ILDAccess_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ILDAccess_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ILDAccess_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ILDAccess_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ILDAccess_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ILDAccess_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ILDAccess_ReadSector(This,LBA,nSectors,Buffer,nRead)	\
    (This)->lpVtbl -> ReadSector(This,LBA,nSectors,Buffer,nRead)

#define ILDAccess_WriteSector(This,LBA,nSectors,Buffer,nWritten)	\
    (This)->lpVtbl -> WriteSector(This,LBA,nSectors,Buffer,nWritten)

#define ILDAccess_Read(This,cbSize,pbBuffer,pcbRead)	\
    (This)->lpVtbl -> Read(This,cbSize,pbBuffer,pcbRead)

#define ILDAccess_Write(This,cbSize,pbBuffer,pcbWritten)	\
    (This)->lpVtbl -> Write(This,cbSize,pbBuffer,pcbWritten)

#define ILDAccess_Seek(This,Low,High,Rel)	\
    (This)->lpVtbl -> Seek(This,Low,High,Rel)

#define ILDAccess_GetPosition(This,LBA,BytesOffset)	\
    (This)->lpVtbl -> GetPosition(This,LBA,BytesOffset)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILDAccess_ReadSector_Proxy(
    ILDAccess __RPC_FAR * This,
    /* [in] */ long LBA,
    /* [in] */ long nSectors,
    /* [size_is][out] */ BYTE __RPC_FAR *Buffer,
    /* [retval][out] */ long __RPC_FAR *nRead);


void __RPC_STUB ILDAccess_ReadSector_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILDAccess_WriteSector_Proxy(
    ILDAccess __RPC_FAR * This,
    /* [in] */ long LBA,
    /* [in] */ long nSectors,
    /* [size_is][in] */ BYTE __RPC_FAR *Buffer,
    /* [retval][out] */ long __RPC_FAR *nWritten);


void __RPC_STUB ILDAccess_WriteSector_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILDAccess_Read_Proxy(
    ILDAccess __RPC_FAR * This,
    /* [in] */ long cbSize,
    /* [size_is][out] */ BYTE __RPC_FAR *pbBuffer,
    /* [retval][out] */ long __RPC_FAR *pcbRead);


void __RPC_STUB ILDAccess_Read_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILDAccess_Write_Proxy(
    ILDAccess __RPC_FAR * This,
    /* [in] */ long cbSize,
    /* [size_is][in] */ BYTE __RPC_FAR *pbBuffer,
    /* [retval][out] */ long __RPC_FAR *pcbWritten);


void __RPC_STUB ILDAccess_Write_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILDAccess_Seek_Proxy(
    ILDAccess __RPC_FAR * This,
    /* [in] */ long Low,
    /* [in] */ long High,
    /* [in] */ enum SeekRelationConstants Rel);


void __RPC_STUB ILDAccess_Seek_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILDAccess_GetPosition_Proxy(
    ILDAccess __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *LBA,
    /* [out] */ long __RPC_FAR *BytesOffset);


void __RPC_STUB ILDAccess_GetPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ILDAccess_INTERFACE_DEFINED__ */


#ifndef __ILDCache_INTERFACE_DEFINED__
#define __ILDCache_INTERFACE_DEFINED__

/* interface ILDCache */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_ILDCache;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("BA6E48AB-25CC-45A4-BB80-56779F68D475")
    ILDCache : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCacheSize(
            /* [in] */ long nSectors) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InvalidateCache( void) = 0;

    };

#else 	/* C style interface */

    typedef struct ILDCacheVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ILDCache __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ILDCache __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ILDCache __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ILDCache __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ILDCache __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ILDCache __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ILDCache __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCacheSize )(
            ILDCache __RPC_FAR * This,
            /* [in] */ long nSectors);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InvalidateCache )(
            ILDCache __RPC_FAR * This);

        END_INTERFACE
    } ILDCacheVtbl;

    interface ILDCache
    {
        CONST_VTBL struct ILDCacheVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ILDCache_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ILDCache_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ILDCache_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ILDCache_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ILDCache_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ILDCache_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ILDCache_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ILDCache_SetCacheSize(This,nSectors)	\
    (This)->lpVtbl -> SetCacheSize(This,nSectors)

#define ILDCache_InvalidateCache(This)	\
    (This)->lpVtbl -> InvalidateCache(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILDCache_SetCacheSize_Proxy(
    ILDCache __RPC_FAR * This,
    /* [in] */ long nSectors);


void __RPC_STUB ILDCache_SetCacheSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILDCache_InvalidateCache_Proxy(
    ILDCache __RPC_FAR * This);


void __RPC_STUB ILDCache_InvalidateCache_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ILDCache_INTERFACE_DEFINED__ */


#ifndef __ILDLargeIO_INTERFACE_DEFINED__
#define __ILDLargeIO_INTERFACE_DEFINED__

/* interface ILDLargeIO */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_ILDLargeIO;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("BA6E48AC-25CC-45A4-BB80-56779F68D475")
    ILDLargeIO : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExportToFile(
            /* [in] */ IDiskAddress __RPC_FAR *StartAddr,
            /* [in] */ IDiskAddress __RPC_FAR *EndAddr,
            /* [in] */ BSTR BinaryFile,
            /* [in] */ BSTR LogFile) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ImportFromFile(
            /* [in] */ IDiskAddress __RPC_FAR *StartAddr,
            /* [in] */ BSTR BinaryFile,
            /* [in] */ BSTR LogFile) = 0;

    };

#else 	/* C style interface */

    typedef struct ILDLargeIOVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ILDLargeIO __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ILDLargeIO __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ILDLargeIO __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ILDLargeIO __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ILDLargeIO __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ILDLargeIO __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ILDLargeIO __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExportToFile )(
            ILDLargeIO __RPC_FAR * This,
            /* [in] */ IDiskAddress __RPC_FAR *StartAddr,
            /* [in] */ IDiskAddress __RPC_FAR *EndAddr,
            /* [in] */ BSTR BinaryFile,
            /* [in] */ BSTR LogFile);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ImportFromFile )(
            ILDLargeIO __RPC_FAR * This,
            /* [in] */ IDiskAddress __RPC_FAR *StartAddr,
            /* [in] */ BSTR BinaryFile,
            /* [in] */ BSTR LogFile);

        END_INTERFACE
    } ILDLargeIOVtbl;

    interface ILDLargeIO
    {
        CONST_VTBL struct ILDLargeIOVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ILDLargeIO_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ILDLargeIO_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ILDLargeIO_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ILDLargeIO_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ILDLargeIO_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ILDLargeIO_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ILDLargeIO_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ILDLargeIO_ExportToFile(This,StartAddr,EndAddr,BinaryFile,LogFile)	\
    (This)->lpVtbl -> ExportToFile(This,StartAddr,EndAddr,BinaryFile,LogFile)

#define ILDLargeIO_ImportFromFile(This,StartAddr,BinaryFile,LogFile)	\
    (This)->lpVtbl -> ImportFromFile(This,StartAddr,BinaryFile,LogFile)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILDLargeIO_ExportToFile_Proxy(
    ILDLargeIO __RPC_FAR * This,
    /* [in] */ IDiskAddress __RPC_FAR *StartAddr,
    /* [in] */ IDiskAddress __RPC_FAR *EndAddr,
    /* [in] */ BSTR BinaryFile,
    /* [in] */ BSTR LogFile);


void __RPC_STUB ILDLargeIO_ExportToFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILDLargeIO_ImportFromFile_Proxy(
    ILDLargeIO __RPC_FAR * This,
    /* [in] */ IDiskAddress __RPC_FAR *StartAddr,
    /* [in] */ BSTR BinaryFile,
    /* [in] */ BSTR LogFile);


void __RPC_STUB ILDLargeIO_ImportFromFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ILDLargeIO_INTERFACE_DEFINED__ */


#ifndef __IWin32DiskLD_INTERFACE_DEFINED__
#define __IWin32DiskLD_INTERFACE_DEFINED__

/* interface IWin32DiskLD */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IWin32DiskLD;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("BA6E48FF-25CC-45A4-BB80-56779F68D475")
    IWin32DiskLD : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BindToWin32Path(
            /* [in] */ LPCTSTR szDevicePath,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *ret) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Unbind( void) = 0;

    };

#else 	/* C style interface */

    typedef struct IWin32DiskLDVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IWin32DiskLD __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IWin32DiskLD __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IWin32DiskLD __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IWin32DiskLD __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IWin32DiskLD __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IWin32DiskLD __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IWin32DiskLD __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BindToWin32Path )(
            IWin32DiskLD __RPC_FAR * This,
            /* [in] */ LPCTSTR szDevicePath,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *ret);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Unbind )(
            IWin32DiskLD __RPC_FAR * This);

        END_INTERFACE
    } IWin32DiskLDVtbl;

    interface IWin32DiskLD
    {
        CONST_VTBL struct IWin32DiskLDVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IWin32DiskLD_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWin32DiskLD_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWin32DiskLD_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWin32DiskLD_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IWin32DiskLD_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IWin32DiskLD_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IWin32DiskLD_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IWin32DiskLD_BindToWin32Path(This,szDevicePath,ret)	\
    (This)->lpVtbl -> BindToWin32Path(This,szDevicePath,ret)

#define IWin32DiskLD_Unbind(This)	\
    (This)->lpVtbl -> Unbind(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWin32DiskLD_BindToWin32Path_Proxy(
    IWin32DiskLD __RPC_FAR * This,
    /* [in] */ LPCTSTR szDevicePath,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *ret);


void __RPC_STUB IWin32DiskLD_BindToWin32Path_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWin32DiskLD_Unbind_Proxy(
    IWin32DiskLD __RPC_FAR * This);


void __RPC_STUB IWin32DiskLD_Unbind_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWin32DiskLD_INTERFACE_DEFINED__ */


#ifndef __IDiskAddress_INTERFACE_DEFINED__
#define __IDiskAddress_INTERFACE_DEFINED__

/* interface IDiskAddress */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IDiskAddress;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("178F4DEB-63A8-4AA3-B1F5-6F31EE741BAE")
    IDiskAddress : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LBA(
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;

        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Cylinder(
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;

        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Head(
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;

        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Sector(
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;

        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OffsetWithinSector(
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;

        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LinearLow(
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;

        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LinearHigh(
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;

        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Mode(
            /* [retval][out] */ enum AddressModeConstants __RPC_FAR *pVal) = 0;

        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Mode(
            /* [in] */ enum AddressModeConstants newVal) = 0;

        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Cylinders(
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;

        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Cylinders(
            /* [in] */ long newVal) = 0;

        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Heads(
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;

        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Heads(
            /* [in] */ short newVal) = 0;

        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Sectors(
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;

        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Sectors(
            /* [in] */ short newVal) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Update( void) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetLBA(
            /* [in] */ long LBA,
            /* [in] */ short Offset) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCHS(
            /* [in] */ long Cylinder,
            /* [in] */ short Head,
            /* [in] */ short Sector,
            /* [in] */ short Offset) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetLinear(
            /* [in] */ long Low,
            /* [in] */ long High) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsValid(
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *retVal) = 0;

    };

#else 	/* C style interface */

    typedef struct IDiskAddressVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IDiskAddress __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IDiskAddress __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IDiskAddress __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IDiskAddress __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IDiskAddress __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IDiskAddress __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IDiskAddress __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LBA )(
            IDiskAddress __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);

        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Cylinder )(
            IDiskAddress __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);

        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Head )(
            IDiskAddress __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);

        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Sector )(
            IDiskAddress __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);

        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OffsetWithinSector )(
            IDiskAddress __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);

        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LinearLow )(
            IDiskAddress __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);

        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LinearHigh )(
            IDiskAddress __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);

        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Mode )(
            IDiskAddress __RPC_FAR * This,
            /* [retval][out] */ enum AddressModeConstants __RPC_FAR *pVal);

        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Mode )(
            IDiskAddress __RPC_FAR * This,
            /* [in] */ enum AddressModeConstants newVal);

        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Cylinders )(
            IDiskAddress __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);

        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Cylinders )(
            IDiskAddress __RPC_FAR * This,
            /* [in] */ long newVal);

        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Heads )(
            IDiskAddress __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);

        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Heads )(
            IDiskAddress __RPC_FAR * This,
            /* [in] */ short newVal);

        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Sectors )(
            IDiskAddress __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);

        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Sectors )(
            IDiskAddress __RPC_FAR * This,
            /* [in] */ short newVal);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Update )(
            IDiskAddress __RPC_FAR * This);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLBA )(
            IDiskAddress __RPC_FAR * This,
            /* [in] */ long LBA,
            /* [in] */ short Offset);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCHS )(
            IDiskAddress __RPC_FAR * This,
            /* [in] */ long Cylinder,
            /* [in] */ short Head,
            /* [in] */ short Sector,
            /* [in] */ short Offset);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLinear )(
            IDiskAddress __RPC_FAR * This,
            /* [in] */ long Low,
            /* [in] */ long High);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsValid )(
            IDiskAddress __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *retVal);

        END_INTERFACE
    } IDiskAddressVtbl;

    interface IDiskAddress
    {
        CONST_VTBL struct IDiskAddressVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IDiskAddress_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDiskAddress_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDiskAddress_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDiskAddress_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDiskAddress_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDiskAddress_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDiskAddress_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDiskAddress_get_LBA(This,pVal)	\
    (This)->lpVtbl -> get_LBA(This,pVal)

#define IDiskAddress_get_Cylinder(This,pVal)	\
    (This)->lpVtbl -> get_Cylinder(This,pVal)

#define IDiskAddress_get_Head(This,pVal)	\
    (This)->lpVtbl -> get_Head(This,pVal)

#define IDiskAddress_get_Sector(This,pVal)	\
    (This)->lpVtbl -> get_Sector(This,pVal)

#define IDiskAddress_get_OffsetWithinSector(This,pVal)	\
    (This)->lpVtbl -> get_OffsetWithinSector(This,pVal)

#define IDiskAddress_get_LinearLow(This,pVal)	\
    (This)->lpVtbl -> get_LinearLow(This,pVal)

#define IDiskAddress_get_LinearHigh(This,pVal)	\
    (This)->lpVtbl -> get_LinearHigh(This,pVal)

#define IDiskAddress_get_Mode(This,pVal)	\
    (This)->lpVtbl -> get_Mode(This,pVal)

#define IDiskAddress_put_Mode(This,newVal)	\
    (This)->lpVtbl -> put_Mode(This,newVal)

#define IDiskAddress_get_Cylinders(This,pVal)	\
    (This)->lpVtbl -> get_Cylinders(This,pVal)

#define IDiskAddress_put_Cylinders(This,newVal)	\
    (This)->lpVtbl -> put_Cylinders(This,newVal)

#define IDiskAddress_get_Heads(This,pVal)	\
    (This)->lpVtbl -> get_Heads(This,pVal)

#define IDiskAddress_put_Heads(This,newVal)	\
    (This)->lpVtbl -> put_Heads(This,newVal)

#define IDiskAddress_get_Sectors(This,pVal)	\
    (This)->lpVtbl -> get_Sectors(This,pVal)

#define IDiskAddress_put_Sectors(This,newVal)	\
    (This)->lpVtbl -> put_Sectors(This,newVal)

#define IDiskAddress_Update(This)	\
    (This)->lpVtbl -> Update(This)

#define IDiskAddress_SetLBA(This,LBA,Offset)	\
    (This)->lpVtbl -> SetLBA(This,LBA,Offset)

#define IDiskAddress_SetCHS(This,Cylinder,Head,Sector,Offset)	\
    (This)->lpVtbl -> SetCHS(This,Cylinder,Head,Sector,Offset)

#define IDiskAddress_SetLinear(This,Low,High)	\
    (This)->lpVtbl -> SetLinear(This,Low,High)

#define IDiskAddress_IsValid(This,retVal)	\
    (This)->lpVtbl -> IsValid(This,retVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDiskAddress_get_LBA_Proxy(
    IDiskAddress __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IDiskAddress_get_LBA_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDiskAddress_get_Cylinder_Proxy(
    IDiskAddress __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IDiskAddress_get_Cylinder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDiskAddress_get_Head_Proxy(
    IDiskAddress __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB IDiskAddress_get_Head_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDiskAddress_get_Sector_Proxy(
    IDiskAddress __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB IDiskAddress_get_Sector_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDiskAddress_get_OffsetWithinSector_Proxy(
    IDiskAddress __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB IDiskAddress_get_OffsetWithinSector_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDiskAddress_get_LinearLow_Proxy(
    IDiskAddress __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IDiskAddress_get_LinearLow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDiskAddress_get_LinearHigh_Proxy(
    IDiskAddress __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IDiskAddress_get_LinearHigh_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDiskAddress_get_Mode_Proxy(
    IDiskAddress __RPC_FAR * This,
    /* [retval][out] */ enum AddressModeConstants __RPC_FAR *pVal);


void __RPC_STUB IDiskAddress_get_Mode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDiskAddress_put_Mode_Proxy(
    IDiskAddress __RPC_FAR * This,
    /* [in] */ enum AddressModeConstants newVal);


void __RPC_STUB IDiskAddress_put_Mode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDiskAddress_get_Cylinders_Proxy(
    IDiskAddress __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IDiskAddress_get_Cylinders_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDiskAddress_put_Cylinders_Proxy(
    IDiskAddress __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IDiskAddress_put_Cylinders_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDiskAddress_get_Heads_Proxy(
    IDiskAddress __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB IDiskAddress_get_Heads_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDiskAddress_put_Heads_Proxy(
    IDiskAddress __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB IDiskAddress_put_Heads_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDiskAddress_get_Sectors_Proxy(
    IDiskAddress __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB IDiskAddress_get_Sectors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDiskAddress_put_Sectors_Proxy(
    IDiskAddress __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB IDiskAddress_put_Sectors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDiskAddress_Update_Proxy(
    IDiskAddress __RPC_FAR * This);


void __RPC_STUB IDiskAddress_Update_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDiskAddress_SetLBA_Proxy(
    IDiskAddress __RPC_FAR * This,
    /* [in] */ long LBA,
    /* [in] */ short Offset);


void __RPC_STUB IDiskAddress_SetLBA_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDiskAddress_SetCHS_Proxy(
    IDiskAddress __RPC_FAR * This,
    /* [in] */ long Cylinder,
    /* [in] */ short Head,
    /* [in] */ short Sector,
    /* [in] */ short Offset);


void __RPC_STUB IDiskAddress_SetCHS_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDiskAddress_SetLinear_Proxy(
    IDiskAddress __RPC_FAR * This,
    /* [in] */ long Low,
    /* [in] */ long High);


void __RPC_STUB IDiskAddress_SetLinear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDiskAddress_IsValid_Proxy(
    IDiskAddress __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *retVal);


void __RPC_STUB IDiskAddress_IsValid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDiskAddress_INTERFACE_DEFINED__ */



#ifndef __HDR_KernelsLib_LIBRARY_DEFINED__
#define __HDR_KernelsLib_LIBRARY_DEFINED__

/* library HDR_KernelsLib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_HDR_KernelsLib;

#ifndef ___IDriverEnumEvents_DISPINTERFACE_DEFINED__
#define ___IDriverEnumEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IDriverEnumEvents */
/* [helpstring][uuid] */


EXTERN_C const IID DIID__IDriverEnumEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("288A49DD-01DA-4D2E-B53F-A430270ACEA1")
    _IDriverEnumEvents : public IDispatch
    {
    };

#else 	/* C style interface */

    typedef struct _IDriverEnumEventsVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            _IDriverEnumEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            _IDriverEnumEvents __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            _IDriverEnumEvents __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            _IDriverEnumEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            _IDriverEnumEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            _IDriverEnumEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            _IDriverEnumEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } _IDriverEnumEventsVtbl;

    interface _IDriverEnumEvents
    {
        CONST_VTBL struct _IDriverEnumEventsVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define _IDriverEnumEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IDriverEnumEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IDriverEnumEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IDriverEnumEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IDriverEnumEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IDriverEnumEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IDriverEnumEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IDriverEnumEvents_DISPINTERFACE_DEFINED__ */


#ifndef ___ILDLargeIOEvents_DISPINTERFACE_DEFINED__
#define ___ILDLargeIOEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ILDLargeIOEvents */
/* [helpstring][uuid] */


EXTERN_C const IID DIID__ILDLargeIOEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("D6914D50-247D-411B-A7A4-FFF9A6119CA6")
    _ILDLargeIOEvents : public IDispatch
    {
    };

#else 	/* C style interface */

    typedef struct _ILDLargeIOEventsVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            _ILDLargeIOEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            _ILDLargeIOEvents __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            _ILDLargeIOEvents __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            _ILDLargeIOEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            _ILDLargeIOEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            _ILDLargeIOEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            _ILDLargeIOEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } _ILDLargeIOEventsVtbl;

    interface _ILDLargeIOEvents
    {
        CONST_VTBL struct _ILDLargeIOEventsVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define _ILDLargeIOEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _ILDLargeIOEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _ILDLargeIOEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _ILDLargeIOEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _ILDLargeIOEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _ILDLargeIOEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _ILDLargeIOEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ILDLargeIOEvents_DISPINTERFACE_DEFINED__ */


#ifndef ___IDiskAddressEvents_DISPINTERFACE_DEFINED__
#define ___IDiskAddressEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IDiskAddressEvents */
/* [helpstring][uuid] */


EXTERN_C const IID DIID__IDiskAddressEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("D6914D4F-247D-411B-A7A4-FFF9A6119CA6")
    _IDiskAddressEvents : public IDispatch
    {
    };

#else 	/* C style interface */

    typedef struct _IDiskAddressEventsVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            _IDiskAddressEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            _IDiskAddressEvents __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            _IDiskAddressEvents __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            _IDiskAddressEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            _IDiskAddressEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            _IDiskAddressEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            _IDiskAddressEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } _IDiskAddressEventsVtbl;

    interface _IDiskAddressEvents
    {
        CONST_VTBL struct _IDiskAddressEventsVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define _IDiskAddressEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IDiskAddressEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IDiskAddressEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IDiskAddressEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IDiskAddressEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IDiskAddressEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IDiskAddressEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IDiskAddressEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Win32DiskLD;

#ifdef __cplusplus

class DECLSPEC_UUID("8270F7BD-1D9D-48D6-B20F-3823E0CE2AFF")
Win32DiskLD;
#endif

EXTERN_C const CLSID CLSID_NetworkDiskLD;

#ifdef __cplusplus

class DECLSPEC_UUID("1BBB6AC8-B281-433C-A8B3-E2C5C45BB249")
NetworkDiskLD;
#endif

EXTERN_C const CLSID CLSID_DriverManager;

#ifdef __cplusplus

class DECLSPEC_UUID("CAE5C5EC-AC3F-4227-AC83-68A9B6E91C4E")
DriverManager;
#endif

EXTERN_C const CLSID CLSID_DiskAddress;

#ifdef __cplusplus

class DECLSPEC_UUID("35F10299-B9B2-4787-842D-F116376F7603")
DiskAddress;
#endif
#endif /* __HDR_KernelsLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * );
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
