/* this ALWAYS GENERATED file contains the proxy stub code */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue Aug 05 20:00:02 2003
 */
/* Compiler settings for C:\s_prjs\Data Rescuer\modules\HDR_Kernels\HDR_Kernels.idl:
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


#include "HDR_Kernels.h"

#define TYPE_FORMAT_STRING_SIZE   117
#define PROC_FORMAT_STRING_SIZE   335

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


/* Standard interface: __MIDL_itf_HDR_Kernels_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDriverLoader, ver. 0.0,
   GUID={0x2DD54D33,0xAC77,0x4189,{0xAB,0x52,0x8C,0xA2,0x78,0xA0,0x2D,0x8D}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IDriverLoader_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IDriverLoader_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0
    };

static const MIDL_SERVER_INFO IDriverLoader_ServerInfo =
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IDriverLoader_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IDriverLoader_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IDriverLoader_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(8) _IDriverLoaderProxyVtbl =
{
    &IDriverLoader_ProxyInfo,
    &IID_IDriverLoader,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IDriverLoader::LoadDriver */
};


static const PRPC_STUB_FUNCTION IDriverLoader_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2
};

CInterfaceStubVtbl _IDriverLoaderStubVtbl =
{
    &IID_IDriverLoader,
    &IDriverLoader_ServerInfo,
    8,
    &IDriverLoader_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IDriverEnum, ver. 0.0,
   GUID={0x2DD54D34,0xAC77,0x4189,{0xAB,0x52,0x8C,0xA2,0x78,0xA0,0x2D,0x8D}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IDriverEnum_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IDriverEnum_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    34,
    62
    };

static const MIDL_SERVER_INFO IDriverEnum_ServerInfo =
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IDriverEnum_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IDriverEnum_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IDriverEnum_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(9) _IDriverEnumProxyVtbl =
{
    &IDriverEnum_ProxyInfo,
    &IID_IDriverEnum,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IDriverEnum::GetDriversCount */ ,
    (void *)-1 /* IDriverEnum::GetDriverName */
};


static const PRPC_STUB_FUNCTION IDriverEnum_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IDriverEnumStubVtbl =
{
    &IID_IDriverEnum,
    &IDriverEnum_ServerInfo,
    9,
    &IDriverEnum_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: ILDAccess, ver. 0.0,
   GUID={0xBA6E48AA,0x25CC,0x45A4,{0xBB,0x80,0x56,0x77,0x9F,0x68,0xD4,0x75}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ILDAccess_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short ILDAccess_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    96,
    136,
    176,
    216
    };

static const MIDL_SERVER_INFO ILDAccess_ServerInfo =
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ILDAccess_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ILDAccess_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ILDAccess_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(11) _ILDAccessProxyVtbl =
{
    &ILDAccess_ProxyInfo,
    &IID_ILDAccess,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* ILDAccess::ReadSector */ ,
    (void *)-1 /* ILDAccess::WriteSector */ ,
    (void *)-1 /* ILDAccess::Seek */ ,
    (void *)-1 /* ILDAccess::GetPosition */
};


static const PRPC_STUB_FUNCTION ILDAccess_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ILDAccessStubVtbl =
{
    &IID_ILDAccess,
    &ILDAccess_ServerInfo,
    11,
    &ILDAccess_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: ILDCache, ver. 0.0,
   GUID={0xBA6E48AB,0x25CC,0x45A4,{0xBB,0x80,0x56,0x77,0x9F,0x68,0xD4,0x75}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ILDCache_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short ILDCache_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    250,
    278
    };

static const MIDL_SERVER_INFO ILDCache_ServerInfo =
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ILDCache_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ILDCache_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ILDCache_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(9) _ILDCacheProxyVtbl =
{
    &ILDCache_ProxyInfo,
    &IID_ILDCache,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* ILDCache::SetCacheSize */ ,
    (void *)-1 /* ILDCache::InvalidateCache */
};


static const PRPC_STUB_FUNCTION ILDCache_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ILDCacheStubVtbl =
{
    &IID_ILDCache,
    &ILDCache_ServerInfo,
    9,
    &ILDCache_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: ILDLargeIO, ver. 0.0,
   GUID={0xBA6E48AC,0x25CC,0x45A4,{0xBB,0x80,0x56,0x77,0x9F,0x68,0xD4,0x75}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")
CINTERFACE_PROXY_VTABLE(7) _ILDLargeIOProxyVtbl =
{
    0,
    &IID_ILDLargeIO,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */
};


static const PRPC_STUB_FUNCTION ILDLargeIO_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION
};

CInterfaceStubVtbl _ILDLargeIOStubVtbl =
{
    &IID_ILDLargeIO,
    0,
    7,
    &ILDLargeIO_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IWin32DiskLD, ver. 0.0,
   GUID={0xBA6E48FF,0x25CC,0x45A4,{0xBB,0x80,0x56,0x77,0x9F,0x68,0xD4,0x75}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWin32DiskLD_ServerInfo;

#pragma code_seg(".orpc")
extern const EXPR_EVAL ExprEvalRoutines[];
extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[1];

static const MIDL_STUB_DESC Object_StubDesc =
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    ExprEvalRoutines,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x20000, /* Ndr library version */
    0,
    0x50100a4, /* MIDL Version 5.1.164 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    1,  /* Flags */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
    };

static const unsigned short IWin32DiskLD_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    300
    };

static const MIDL_SERVER_INFO IWin32DiskLD_ServerInfo =
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWin32DiskLD_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IWin32DiskLD_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWin32DiskLD_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(8) _IWin32DiskLDProxyVtbl =
{
    &IWin32DiskLD_ProxyInfo,
    &IID_IWin32DiskLD,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IWin32DiskLD::BindToWin32Path */
};


static const PRPC_STUB_FUNCTION IWin32DiskLD_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2
};

CInterfaceStubVtbl _IWin32DiskLDStubVtbl =
{
    &IID_IWin32DiskLD,
    &IWin32DiskLD_ServerInfo,
    8,
    &IWin32DiskLD_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

#pragma data_seg(".rdata")

static void __RPC_USER ILDAccess_ReadSectorExprEval_0000( PMIDL_STUB_MESSAGE pStubMsg )
{

#ifndef _ALPHA_
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IWin32DiskLD __RPC_FAR *This;
        long nSectors;
        BYTE __RPC_FAR *pBuffer;
        long __RPC_FAR *nRead;
        HRESULT _RetVal;
        };
    #pragma pack()
#else
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IWin32DiskLD __RPC_FAR *This;
        char Pad0[4];
        long nSectors;
        char Pad1[4];
        BYTE __RPC_FAR *pBuffer;
        char Pad2[4];
        long __RPC_FAR *nRead;
        char Pad3[4];
        HRESULT _RetVal;
        };
    #pragma pack()
#endif

    struct _PARAM_STRUCT __RPC_FAR *pS	=	( struct _PARAM_STRUCT __RPC_FAR * )pStubMsg->StackTop;

    pStubMsg->Offset = 0;
    pStubMsg->MaxCount = ( unsigned long ) ( pS->nSectors * 512 );
}

static void __RPC_USER ILDAccess_WriteSectorExprEval_0001( PMIDL_STUB_MESSAGE pStubMsg )
{

#ifndef _ALPHA_
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IWin32DiskLD __RPC_FAR *This;
        long nSectors;
        BYTE __RPC_FAR *pBuffer;
        long __RPC_FAR *nWritten;
        HRESULT _RetVal;
        };
    #pragma pack()
#else
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IWin32DiskLD __RPC_FAR *This;
        char Pad0[4];
        long nSectors;
        char Pad1[4];
        BYTE __RPC_FAR *pBuffer;
        char Pad2[4];
        long __RPC_FAR *nWritten;
        char Pad3[4];
        HRESULT _RetVal;
        };
    #pragma pack()
#endif

    struct _PARAM_STRUCT __RPC_FAR *pS	=	( struct _PARAM_STRUCT __RPC_FAR * )pStubMsg->StackTop;

    pStubMsg->Offset = 0;
    pStubMsg->MaxCount = ( unsigned long ) ( pS->nSectors * 512 );
}

static const EXPR_EVAL ExprEvalRoutines[] =
    {
    ILDAccess_ReadSectorExprEval_0000
    ,ILDAccess_WriteSectorExprEval_0001
    };


static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[1] =
        {

            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            }

        };


#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT40_OR_LATER)
#error You need a Windows NT 4.0 or later to run this stub because it uses these features:
#error   -Oif or -Oicf, [wire_marshal] or [user_marshal] attribute, more than 32 methods in the interface.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure LoadDriver */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/*  8 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter Name */

/* 16 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 18 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 20 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter LinearDevice */

/* 22 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
#ifndef _ALPHA_
/* 24 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 26 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 28 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 30 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 32 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDriversCount */

/* 34 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 36 */	NdrFcLong( 0x0 ),	/* 0 */
/* 40 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/* 42 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 44 */	NdrFcShort( 0x0 ),	/* 0 */
/* 46 */	NdrFcShort( 0x10 ),	/* 16 */
/* 48 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter Count */

/* 50 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 52 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 54 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 56 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 58 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 60 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDriverName */

/* 62 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 64 */	NdrFcLong( 0x0 ),	/* 0 */
/* 68 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
/* 70 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 72 */	NdrFcShort( 0x8 ),	/* 8 */
/* 74 */	NdrFcShort( 0x8 ),	/* 8 */
/* 76 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x3,		/* 3 */

	/* Parameter Index */

/* 78 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 80 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 82 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Name */

/* 84 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 86 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 88 */	NdrFcShort( 0x46 ),	/* Type Offset=70 */

	/* Return value */

/* 90 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 92 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 94 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReadSector */

/* 96 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 98 */	NdrFcLong( 0x0 ),	/* 0 */
/* 102 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/* 104 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 106 */	NdrFcShort( 0x8 ),	/* 8 */
/* 108 */	NdrFcShort( 0x10 ),	/* 16 */
/* 110 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x4,		/* 4 */

	/* Parameter nSectors */

/* 112 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 114 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pBuffer */

/* 118 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
#ifndef _ALPHA_
/* 120 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 122 */	NdrFcShort( 0x54 ),	/* Type Offset=84 */

	/* Parameter nRead */

/* 124 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 126 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 128 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 130 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 132 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 134 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WriteSector */

/* 136 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 138 */	NdrFcLong( 0x0 ),	/* 0 */
/* 142 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
/* 144 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 146 */	NdrFcShort( 0x8 ),	/* 8 */
/* 148 */	NdrFcShort( 0x10 ),	/* 16 */
/* 150 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter nSectors */

/* 152 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 154 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pBuffer */

/* 158 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
#ifndef _ALPHA_
/* 160 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 162 */	NdrFcShort( 0x62 ),	/* Type Offset=98 */

	/* Parameter nWritten */

/* 164 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 166 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 168 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 170 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 172 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 174 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Seek */

/* 176 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 178 */	NdrFcLong( 0x0 ),	/* 0 */
/* 182 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
/* 184 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 186 */	NdrFcShort( 0x18 ),	/* 24 */
/* 188 */	NdrFcShort( 0x8 ),	/* 8 */
/* 190 */	0x4,		/* Oi2 Flags:  has return, */
			0x4,		/* 4 */

	/* Parameter Unit */

/* 192 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 194 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 196 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Offset */

/* 198 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 200 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Direction */

/* 204 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 206 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 208 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 210 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 212 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 214 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPosition */

/* 216 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 218 */	NdrFcLong( 0x0 ),	/* 0 */
/* 222 */	NdrFcShort( 0xa ),	/* 10 */
#ifndef _ALPHA_
/* 224 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 228 */	NdrFcShort( 0x18 ),	/* 24 */
/* 230 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter LBA */

/* 232 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 234 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 236 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter BytesOffset */

/* 238 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 240 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 242 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 244 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 246 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 248 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCacheSize */

/* 250 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 252 */	NdrFcLong( 0x0 ),	/* 0 */
/* 256 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/* 258 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 260 */	NdrFcShort( 0x8 ),	/* 8 */
/* 262 */	NdrFcShort( 0x8 ),	/* 8 */
/* 264 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nSectors */

/* 266 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 268 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 272 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 274 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InvalidateCache */

/* 278 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 280 */	NdrFcLong( 0x0 ),	/* 0 */
/* 284 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
/* 286 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 290 */	NdrFcShort( 0x8 ),	/* 8 */
/* 292 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 294 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 296 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 298 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BindToWin32Path */

/* 300 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 302 */	NdrFcLong( 0x0 ),	/* 0 */
/* 306 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/* 308 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 312 */	NdrFcShort( 0xe ),	/* 14 */
/* 314 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter szDevicePath */

/* 316 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
#ifndef _ALPHA_
/* 318 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 320 */	NdrFcShort( 0x6e ),	/* Type Offset=110 */

	/* Parameter ret */

/* 322 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 324 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 326 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 328 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 330 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 332 */	0x8,		/* FC_LONG */
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
			0x12, 0x0,	/* FC_UP */
/*  4 */	NdrFcShort( 0xc ),	/* Offset= 12 (16) */
/*  6 */
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/*  8 */	NdrFcShort( 0x2 ),	/* 2 */
/* 10 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 12 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 14 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 16 */
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 18 */	NdrFcShort( 0x8 ),	/* 8 */
/* 20 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (6) */
/* 22 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 24 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 26 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 28 */	NdrFcShort( 0x0 ),	/* 0 */
/* 30 */	NdrFcShort( 0x4 ),	/* 4 */
/* 32 */	NdrFcShort( 0x0 ),	/* 0 */
/* 34 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (2) */
/* 36 */
			0x11, 0x10,	/* FC_RP */
/* 38 */	NdrFcShort( 0x2 ),	/* Offset= 2 (40) */
/* 40 */
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 42 */	NdrFcLong( 0xba6e48aa ),	/* -1167177558 */
/* 46 */	NdrFcShort( 0x25cc ),	/* 9676 */
/* 48 */	NdrFcShort( 0x45a4 ),	/* 17828 */
/* 50 */	0xbb,		/* 187 */
			0x80,		/* 128 */
/* 52 */	0x56,		/* 86 */
			0x77,		/* 119 */
/* 54 */	0x9f,		/* 159 */
			0x68,		/* 104 */
/* 56 */	0xd4,		/* 212 */
			0x75,		/* 117 */
/* 58 */
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 60 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 62 */
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 64 */	NdrFcShort( 0x6 ),	/* Offset= 6 (70) */
/* 66 */
			0x13, 0x0,	/* FC_OP */
/* 68 */	NdrFcShort( 0xffffffcc ),	/* Offset= -52 (16) */
/* 70 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 72 */	NdrFcShort( 0x0 ),	/* 0 */
/* 74 */	NdrFcShort( 0x4 ),	/* 4 */
/* 76 */	NdrFcShort( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0xfffffff4 ),	/* Offset= -12 (66) */
/* 80 */
			0x11, 0x0,	/* FC_RP */
/* 82 */	NdrFcShort( 0x2 ),	/* Offset= 2 (84) */
/* 84 */
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 86 */	NdrFcShort( 0x1 ),	/* 1 */
/* 88 */	0x20,		/* Corr desc:  parameter,  */
			0x59,		/* FC_CALLBACK */
/* 90 */	NdrFcShort( 0x0 ),	/* 0 */
/* 92 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 94 */
			0x11, 0x0,	/* FC_RP */
/* 96 */	NdrFcShort( 0x2 ),	/* Offset= 2 (98) */
/* 98 */
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 100 */	NdrFcShort( 0x1 ),	/* 1 */
/* 102 */	0x20,		/* Corr desc:  parameter,  */
			0x59,		/* FC_CALLBACK */
/* 104 */	NdrFcShort( 0x1 ),	/* 1 */
/* 106 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 108 */
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 110 */
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 112 */
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 114 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */

			0x0
        }
    };

const CInterfaceProxyVtbl * _HDR_Kernels_ProxyVtblList[] =
{
    ( CInterfaceProxyVtbl *) &_IDriverLoaderProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IDriverEnumProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ILDAccessProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ILDCacheProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ILDLargeIOProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWin32DiskLDProxyVtbl,
    0
};

const CInterfaceStubVtbl * _HDR_Kernels_StubVtblList[] =
{
    ( CInterfaceStubVtbl *) &_IDriverLoaderStubVtbl,
    ( CInterfaceStubVtbl *) &_IDriverEnumStubVtbl,
    ( CInterfaceStubVtbl *) &_ILDAccessStubVtbl,
    ( CInterfaceStubVtbl *) &_ILDCacheStubVtbl,
    ( CInterfaceStubVtbl *) &_ILDLargeIOStubVtbl,
    ( CInterfaceStubVtbl *) &_IWin32DiskLDStubVtbl,
    0
};

PCInterfaceName const _HDR_Kernels_InterfaceNamesList[] =
{
    "IDriverLoader",
    "IDriverEnum",
    "ILDAccess",
    "ILDCache",
    "ILDLargeIO",
    "IWin32DiskLD",
    0
};

const IID *  _HDR_Kernels_BaseIIDList[] =
{
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _HDR_Kernels_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _HDR_Kernels, pIID, n)

int __stdcall _HDR_Kernels_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _HDR_Kernels, 6, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _HDR_Kernels, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _HDR_Kernels, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _HDR_Kernels, 6, *pIndex )

}

const ExtendedProxyFileInfo HDR_Kernels_ProxyFileInfo =
{
    (PCInterfaceProxyVtblList *) & _HDR_Kernels_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _HDR_Kernels_StubVtblList,
    (const PCInterfaceName * ) & _HDR_Kernels_InterfaceNamesList,
    (const IID ** ) & _HDR_Kernels_BaseIIDList,
    & _HDR_Kernels_IID_Lookup,
    6,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
