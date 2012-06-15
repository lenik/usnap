/* this ALWAYS GENERATED file contains the proxy stub code */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Aug 14 12:26:02 2003
 */
/* Compiler settings for C:\s_prjs\Data Rescuer\modules\HDR_StdLib\HDR_StdLib.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data
*/
//@@MIDL_FILE_HEADING(  )

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 440
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "HDR_StdLib.h"

#define TYPE_FORMAT_STRING_SIZE   3
#define PROC_FORMAT_STRING_SIZE   1

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IModuleProvider, ver. 0.0,
   GUID={0x3B945220,0x0A12,0x4739,{0xBF,0x4D,0xB1,0x78,0xB9,0xA2,0x75,0x67}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")
CINTERFACE_PROXY_VTABLE(7) _IModuleProviderProxyVtbl =
{
    0,
    &IID_IModuleProvider,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */
};


static const PRPC_STUB_FUNCTION IModuleProvider_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION
};

CInterfaceStubVtbl _IModuleProviderStubVtbl =
{
    &IID_IModuleProvider,
    0,
    7,
    &IModuleProvider_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFileTypeVerifier, ver. 0.0,
   GUID={0xA0C7541D,0xA322,0x4552,{0xAB,0xA5,0x1C,0x83,0x70,0x4B,0xBC,0x8C}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")

static const MIDL_STUB_DESC Object_StubDesc =
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x20000, /* Ndr library version */
    0,
    0x50100a4, /* MIDL Version 5.1.164 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    1,  /* Flags */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
    };

CINTERFACE_PROXY_VTABLE(7) _IFileTypeVerifierProxyVtbl =
{
    0,
    &IID_IFileTypeVerifier,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */
};


static const PRPC_STUB_FUNCTION IFileTypeVerifier_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION
};

CInterfaceStubVtbl _IFileTypeVerifierStubVtbl =
{
    &IID_IFileTypeVerifier,
    0,
    7,
    &IFileTypeVerifier_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

#pragma data_seg(".rdata")

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT40_OR_LATER)
#error You need a Windows NT 4.0 or later to run this stub because it uses these features:
#error   -Oif or -Oicf, more than 32 methods in the interface.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */

			0x0
        }
    };

const CInterfaceProxyVtbl * _HDR_StdLib_ProxyVtblList[] =
{
    ( CInterfaceProxyVtbl *) &_IFileTypeVerifierProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IModuleProviderProxyVtbl,
    0
};

const CInterfaceStubVtbl * _HDR_StdLib_StubVtblList[] =
{
    ( CInterfaceStubVtbl *) &_IFileTypeVerifierStubVtbl,
    ( CInterfaceStubVtbl *) &_IModuleProviderStubVtbl,
    0
};

PCInterfaceName const _HDR_StdLib_InterfaceNamesList[] =
{
    "IFileTypeVerifier",
    "IModuleProvider",
    0
};

const IID *  _HDR_StdLib_BaseIIDList[] =
{
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _HDR_StdLib_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _HDR_StdLib, pIID, n)

int __stdcall _HDR_StdLib_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _HDR_StdLib, 2, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _HDR_StdLib, 2, *pIndex )

}

const ExtendedProxyFileInfo HDR_StdLib_ProxyFileInfo =
{
    (PCInterfaceProxyVtblList *) & _HDR_StdLib_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _HDR_StdLib_StubVtblList,
    (const PCInterfaceName * ) & _HDR_StdLib_InterfaceNamesList,
    (const IID ** ) & _HDR_StdLib_BaseIIDList,
    & _HDR_StdLib_IID_Lookup,
    2,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
