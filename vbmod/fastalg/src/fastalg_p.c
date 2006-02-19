/* this ALWAYS GENERATED file contains the proxy stub code */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Feb 20 00:25:31 2006
 */
/* Compiler settings for C:\.lokaj\zbmis\module\fastalg\src\fastalg.idl:
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


#include "fastalg.h"

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


/* Object interface: ISAOT, ver. 0.0,
   GUID={0xAECAFF4C,0x5D51,0x483A,{0x86,0x19,0xE8,0x05,0x11,0xE6,0x94,0x39}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")
CINTERFACE_PROXY_VTABLE(7) _ISAOTProxyVtbl =
{
    0,
    &IID_ISAOT,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */
};


static const PRPC_STUB_FUNCTION ISAOT_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION
};

CInterfaceStubVtbl _ISAOTStubVtbl =
{
    &IID_ISAOT,
    0,
    7,
    &ISAOT_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IDRIA, ver. 0.0,
   GUID={0x604D4559,0x902D,0x4066,{0xB1,0xFA,0x81,0xF6,0x92,0x61,0x05,0x19}} */


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

CINTERFACE_PROXY_VTABLE(7) _IDRIAProxyVtbl =
{
    0,
    &IID_IDRIA,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */
};


static const PRPC_STUB_FUNCTION IDRIA_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION
};

CInterfaceStubVtbl _IDRIAStubVtbl =
{
    &IID_IDRIA,
    0,
    7,
    &IDRIA_table[-3],
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

const CInterfaceProxyVtbl * _fastalg_ProxyVtblList[] =
{
    ( CInterfaceProxyVtbl *) &_ISAOTProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IDRIAProxyVtbl,
    0
};

const CInterfaceStubVtbl * _fastalg_StubVtblList[] =
{
    ( CInterfaceStubVtbl *) &_ISAOTStubVtbl,
    ( CInterfaceStubVtbl *) &_IDRIAStubVtbl,
    0
};

PCInterfaceName const _fastalg_InterfaceNamesList[] =
{
    "ISAOT",
    "IDRIA",
    0
};

const IID *  _fastalg_BaseIIDList[] =
{
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _fastalg_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _fastalg, pIID, n)

int __stdcall _fastalg_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _fastalg, 2, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _fastalg, 2, *pIndex )

}

const ExtendedProxyFileInfo fastalg_ProxyFileInfo =
{
    (PCInterfaceProxyVtblList *) & _fastalg_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _fastalg_StubVtblList,
    (const PCInterfaceName * ) & _fastalg_InterfaceNamesList,
    (const IID ** ) & _fastalg_BaseIIDList,
    & _fastalg_IID_Lookup,
    2,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
