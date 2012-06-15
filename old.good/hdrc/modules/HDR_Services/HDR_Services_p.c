/* this ALWAYS GENERATED file contains the proxy stub code */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Aug 25 10:51:51 2003
 */
/* Compiler settings for C:\S_PRJS\DATA RESCUER\MODULES\HDR_Services\HDR_Services.idl:
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


#include "HDR_Services.h"

#define TYPE_FORMAT_STRING_SIZE   7
#define PROC_FORMAT_STRING_SIZE   29

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


/* Standard interface: __MIDL_itf_HDR_Services_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IFSPMapper, ver. 0.0,
   GUID={0xAC48B470,0x0211,0x4616,{0xAA,0x96,0x0F,0x14,0xEC,0xB9,0x4E,0x3B}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")
CINTERFACE_PROXY_VTABLE(7) _IFSPMapperProxyVtbl =
{
    0,
    &IID_IFSPMapper,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */
};


static const PRPC_STUB_FUNCTION IFSPMapper_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION
};

CInterfaceStubVtbl _IFSPMapperStubVtbl =
{
    &IID_IFSPMapper,
    0,
    7,
    &IFSPMapper_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFSPReconstruct, ver. 0.0,
   GUID={0xAC48B471,0x0211,0x4616,{0xAA,0x96,0x0F,0x14,0xEC,0xB9,0x4E,0x3B}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")
CINTERFACE_PROXY_VTABLE(7) _IFSPReconstructProxyVtbl =
{
    0,
    &IID_IFSPReconstruct,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */
};


static const PRPC_STUB_FUNCTION IFSPReconstruct_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION
};

CInterfaceStubVtbl _IFSPReconstructStubVtbl =
{
    &IID_IFSPReconstruct,
    0,
    7,
    &IFSPReconstruct_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFSPRecstrMonitor, ver. 0.0,
   GUID={0xAC48B472,0x0211,0x4616,{0xAA,0x96,0x0F,0x14,0xEC,0xB9,0x4E,0x3B}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")
CINTERFACE_PROXY_VTABLE(7) _IFSPRecstrMonitorProxyVtbl =
{
    0,
    &IID_IFSPRecstrMonitor,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */
};


static const PRPC_STUB_FUNCTION IFSPRecstrMonitor_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION
};

CInterfaceStubVtbl _IFSPRecstrMonitorStubVtbl =
{
    &IID_IFSPRecstrMonitor,
    0,
    7,
    &IFSPRecstrMonitor_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFSPAddInsMgr, ver. 0.0,
   GUID={0xAC48B473,0x0211,0x4616,{0xAA,0x96,0x0F,0x14,0xEC,0xB9,0x4E,0x3B}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFSPAddInsMgr_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IFSPAddInsMgr_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0
    };

static const MIDL_SERVER_INFO IFSPAddInsMgr_ServerInfo =
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFSPAddInsMgr_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IFSPAddInsMgr_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFSPAddInsMgr_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(8) _IFSPAddInsMgrProxyVtbl =
{
    &IFSPAddInsMgr_ProxyInfo,
    &IID_IFSPAddInsMgr,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IFSPAddInsMgr::get_FiltersCount */
};


static const PRPC_STUB_FUNCTION IFSPAddInsMgr_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2
};

CInterfaceStubVtbl _IFSPAddInsMgrStubVtbl =
{
    &IID_IFSPAddInsMgr,
    &IFSPAddInsMgr_ServerInfo,
    8,
    &IFSPAddInsMgr_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFSPFATxParser, ver. 0.0,
   GUID={0xAC48B480,0x0211,0x4616,{0xAA,0x96,0x0F,0x14,0xEC,0xB9,0x4E,0x3B}} */


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

CINTERFACE_PROXY_VTABLE(7) _IFSPFATxParserProxyVtbl =
{
    0,
    &IID_IFSPFATxParser,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */
};


static const PRPC_STUB_FUNCTION IFSPFATxParser_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION
};

CInterfaceStubVtbl _IFSPFATxParserStubVtbl =
{
    &IID_IFSPFATxParser,
    0,
    7,
    &IFSPFATxParser_table[-3],
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

	/* Procedure get_FiltersCount */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/*  8 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x10 ),	/* 16 */
/* 14 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 16 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 18 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 20 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 22 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 24 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 26 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  4 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */

			0x0
        }
    };

const CInterfaceProxyVtbl * _HDR_Services_ProxyVtblList[] =
{
    ( CInterfaceProxyVtbl *) &_IFSPMapperProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFSPReconstructProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFSPRecstrMonitorProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFSPAddInsMgrProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFSPFATxParserProxyVtbl,
    0
};

const CInterfaceStubVtbl * _HDR_Services_StubVtblList[] =
{
    ( CInterfaceStubVtbl *) &_IFSPMapperStubVtbl,
    ( CInterfaceStubVtbl *) &_IFSPReconstructStubVtbl,
    ( CInterfaceStubVtbl *) &_IFSPRecstrMonitorStubVtbl,
    ( CInterfaceStubVtbl *) &_IFSPAddInsMgrStubVtbl,
    ( CInterfaceStubVtbl *) &_IFSPFATxParserStubVtbl,
    0
};

PCInterfaceName const _HDR_Services_InterfaceNamesList[] =
{
    "IFSPMapper",
    "IFSPReconstruct",
    "IFSPRecstrMonitor",
    "IFSPAddInsMgr",
    "IFSPFATxParser",
    0
};

const IID *  _HDR_Services_BaseIIDList[] =
{
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _HDR_Services_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _HDR_Services, pIID, n)

int __stdcall _HDR_Services_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _HDR_Services, 5, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _HDR_Services, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _HDR_Services, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _HDR_Services, 5, *pIndex )

}

const ExtendedProxyFileInfo HDR_Services_ProxyFileInfo =
{
    (PCInterfaceProxyVtblList *) & _HDR_Services_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _HDR_Services_StubVtblList,
    (const PCInterfaceName * ) & _HDR_Services_InterfaceNamesList,
    (const IID ** ) & _HDR_Services_BaseIIDList,
    & _HDR_Services_IID_Lookup,
    5,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
