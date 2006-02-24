/* this ALWAYS GENERATED file contains the proxy stub code */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Feb 24 17:21:13 2006
 */
/* Compiler settings for C:\.lokaj\zbmis\module\bastype\src\bastype.idl:
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


#include "bastype.h"

#define TYPE_FORMAT_STRING_SIZE   1041
#define PROC_FORMAT_STRING_SIZE   439

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


/* Object interface: IComparable, ver. 0.0,
   GUID={0x3AD5FB90,0x8C80,0x461D,{0x8F,0x18,0xF6,0x57,0x32,0xFC,0xED,0x17}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IComparable_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IComparable_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0
    };

static const MIDL_SERVER_INFO IComparable_ServerInfo =
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IComparable_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IComparable_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IComparable_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(8) _IComparableProxyVtbl =
{
    &IComparable_ProxyInfo,
    &IID_IComparable,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IComparable::compareTo */
};


static const PRPC_STUB_FUNCTION IComparable_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2
};

CInterfaceStubVtbl _IComparableStubVtbl =
{
    &IID_IComparable,
    &IComparable_ServerInfo,
    8,
    &IComparable_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStringizable, ver. 0.0,
   GUID={0x99A5A9D2,0x90B9,0x48A6,{0x80,0x5F,0x2D,0x14,0xFE,0xD3,0x23,0x8A}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStringizable_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IStringizable_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    34
    };

static const MIDL_SERVER_INFO IStringizable_ServerInfo =
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IStringizable_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IStringizable_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IStringizable_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(8) _IStringizableProxyVtbl =
{
    &IStringizable_ProxyInfo,
    &IID_IStringizable,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IStringizable::toString */
};


static const PRPC_STUB_FUNCTION IStringizable_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2
};

CInterfaceStubVtbl _IStringizableStubVtbl =
{
    &IID_IStringizable,
    &IStringizable_ServerInfo,
    8,
    &IStringizable_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IIterator, ver. 0.0,
   GUID={0x9A64E934,0xFB27,0x4584,{0x90,0x4D,0x2D,0xFF,0xD2,0xD7,0x55,0x65}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IIterator_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IIterator_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    62,
    90,
    118
    };

static const MIDL_SERVER_INFO IIterator_ServerInfo =
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IIterator_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IIterator_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IIterator_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(10) _IIteratorProxyVtbl =
{
    &IIterator_ProxyInfo,
    &IID_IIterator,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IIterator::hasNext */ ,
    (void *)-1 /* IIterator::fetch */ ,
    (void *)-1 /* IIterator::remove */
};


static const PRPC_STUB_FUNCTION IIterator_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IIteratorStubVtbl =
{
    &IID_IIterator,
    &IIterator_ServerInfo,
    10,
    &IIterator_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IList, ver. 0.0,
   GUID={0xC5D3407B,0xD364,0x4328,{0xBC,0x1A,0x3C,0x4C,0xCA,0x63,0x1D,0xDA}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IList_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IList_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    140,
    168,
    196,
    224,
    252,
    280
    };

static const MIDL_SERVER_INFO IList_ServerInfo =
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IList_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IList_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IList_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(13) _IListProxyVtbl =
{
    &IList_ProxyInfo,
    &IID_IList,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IList::get_size */ ,
    (void *)-1 /* IList::push */ ,
    (void *)-1 /* IList::pop */ ,
    (void *)-1 /* IList::unshift */ ,
    (void *)-1 /* IList::shift */ ,
    (void *)-1 /* IList::iterator */
};


static const PRPC_STUB_FUNCTION IList_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IListStubVtbl =
{
    &IID_IList,
    &IList_ServerInfo,
    13,
    &IList_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IVector, ver. 0.0,
   GUID={0x9583076E,0x91BC,0x4F21,{0x89,0x73,0x48,0xEE,0xF1,0xBA,0xF5,0x67}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IVector_ServerInfo;

#pragma code_seg(".orpc")
extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[2];

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
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    1,  /* Flags */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
    };

static const unsigned short IVector_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    140,
    168,
    196,
    224,
    252,
    280,
    308,
    342,
    376,
    410
    };

static const MIDL_SERVER_INFO IVector_ServerInfo =
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IVector_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IVector_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IVector_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(17) _IVectorProxyVtbl =
{
    &IVector_ProxyInfo,
    &IID_IVector,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IList::get_size */ ,
    (void *)-1 /* IList::push */ ,
    (void *)-1 /* IList::pop */ ,
    (void *)-1 /* IList::unshift */ ,
    (void *)-1 /* IList::shift */ ,
    (void *)-1 /* IList::iterator */ ,
    (void *)-1 /* IVector::get_item */ ,
    (void *)-1 /* IVector::put_item */ ,
    (void *)-1 /* IVector::insert */ ,
    (void *)-1 /* IVector::remove */
};


static const PRPC_STUB_FUNCTION IVector_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IVectorStubVtbl =
{
    &IID_IVector,
    &IVector_ServerInfo,
    17,
    &IVector_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

#pragma data_seg(".rdata")

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[2] =
        {

            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            },
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

	/* Procedure compareTo */

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
/* 12 */	NdrFcShort( 0x10 ),	/* 16 */
/* 14 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter rhs */

/* 16 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
#ifndef _ALPHA_
/* 18 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 20 */	NdrFcShort( 0x3c4 ),	/* Type Offset=964 */

	/* Parameter result */

/* 22 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 24 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 26 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 28 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 30 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 32 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure toString */

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
/* 46 */	NdrFcShort( 0x8 ),	/* 8 */
/* 48 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter result */

/* 50 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 52 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 54 */	NdrFcShort( 0x3da ),	/* Type Offset=986 */

	/* Return value */

/* 56 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 58 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 60 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure hasNext */

/* 62 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 64 */	NdrFcLong( 0x0 ),	/* 0 */
/* 68 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/* 70 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 72 */	NdrFcShort( 0x0 ),	/* 0 */
/* 74 */	NdrFcShort( 0xe ),	/* 14 */
/* 76 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter result */

/* 78 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 80 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 82 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 84 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 86 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 88 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure fetch */

/* 90 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 92 */	NdrFcLong( 0x0 ),	/* 0 */
/* 96 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
/* 98 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 102 */	NdrFcShort( 0x8 ),	/* 8 */
/* 104 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter result */

/* 106 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
#ifndef _ALPHA_
/* 108 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 110 */	NdrFcShort( 0x3f0 ),	/* Type Offset=1008 */

	/* Return value */

/* 112 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 114 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure remove */

/* 118 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 120 */	NdrFcLong( 0x0 ),	/* 0 */
/* 124 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
/* 126 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x8 ),	/* 8 */
/* 132 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 134 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 136 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 138 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_size */

/* 140 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 142 */	NdrFcLong( 0x0 ),	/* 0 */
/* 146 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/* 148 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 152 */	NdrFcShort( 0x10 ),	/* 16 */
/* 154 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 156 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 158 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 160 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 162 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 164 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 166 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure push */

/* 168 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 170 */	NdrFcLong( 0x0 ),	/* 0 */
/* 174 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
/* 176 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 180 */	NdrFcShort( 0x8 ),	/* 8 */
/* 182 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter var */

/* 184 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
#ifndef _ALPHA_
/* 186 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 188 */	NdrFcShort( 0x3c4 ),	/* Type Offset=964 */

	/* Return value */

/* 190 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 192 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure pop */

/* 196 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 202 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
/* 204 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 208 */	NdrFcShort( 0x8 ),	/* 8 */
/* 210 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter var */

/* 212 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
#ifndef _ALPHA_
/* 214 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 216 */	NdrFcShort( 0x3f0 ),	/* Type Offset=1008 */

	/* Return value */

/* 218 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 220 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 222 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure unshift */

/* 224 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 226 */	NdrFcLong( 0x0 ),	/* 0 */
/* 230 */	NdrFcShort( 0xa ),	/* 10 */
#ifndef _ALPHA_
/* 232 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 236 */	NdrFcShort( 0x8 ),	/* 8 */
/* 238 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter var */

/* 240 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
#ifndef _ALPHA_
/* 242 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 244 */	NdrFcShort( 0x3c4 ),	/* Type Offset=964 */

	/* Return value */

/* 246 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 248 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 250 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure shift */

/* 252 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 258 */	NdrFcShort( 0xb ),	/* 11 */
#ifndef _ALPHA_
/* 260 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 264 */	NdrFcShort( 0x8 ),	/* 8 */
/* 266 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter var */

/* 268 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
#ifndef _ALPHA_
/* 270 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 272 */	NdrFcShort( 0x3f0 ),	/* Type Offset=1008 */

	/* Return value */

/* 274 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 276 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 278 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure iterator */

/* 280 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 282 */	NdrFcLong( 0x0 ),	/* 0 */
/* 286 */	NdrFcShort( 0xc ),	/* 12 */
#ifndef _ALPHA_
/* 288 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 292 */	NdrFcShort( 0x8 ),	/* 8 */
/* 294 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter result */

/* 296 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
#ifndef _ALPHA_
/* 298 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 300 */	NdrFcShort( 0x3fa ),	/* Type Offset=1018 */

	/* Return value */

/* 302 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 304 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 306 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_item */

/* 308 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 310 */	NdrFcLong( 0x0 ),	/* 0 */
/* 314 */	NdrFcShort( 0xd ),	/* 13 */
#ifndef _ALPHA_
/* 316 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 318 */	NdrFcShort( 0x8 ),	/* 8 */
/* 320 */	NdrFcShort( 0x8 ),	/* 8 */
/* 322 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x3,		/* 3 */

	/* Parameter index */

/* 324 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 326 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 330 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
#ifndef _ALPHA_
/* 332 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 334 */	NdrFcShort( 0x3f0 ),	/* Type Offset=1008 */

	/* Return value */

/* 336 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 338 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 340 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_item */

/* 342 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 344 */	NdrFcLong( 0x0 ),	/* 0 */
/* 348 */	NdrFcShort( 0xe ),	/* 14 */
#ifndef _ALPHA_
/* 350 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 352 */	NdrFcShort( 0x8 ),	/* 8 */
/* 354 */	NdrFcShort( 0x8 ),	/* 8 */
/* 356 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter index */

/* 358 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 360 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 362 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 364 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
#ifndef _ALPHA_
/* 366 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 368 */	NdrFcShort( 0x3c4 ),	/* Type Offset=964 */

	/* Return value */

/* 370 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 372 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 374 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure insert */

/* 376 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 378 */	NdrFcLong( 0x0 ),	/* 0 */
/* 382 */	NdrFcShort( 0xf ),	/* 15 */
#ifndef _ALPHA_
/* 384 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 386 */	NdrFcShort( 0x8 ),	/* 8 */
/* 388 */	NdrFcShort( 0x8 ),	/* 8 */
/* 390 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter index */

/* 392 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 394 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter var */

/* 398 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
#ifndef _ALPHA_
/* 400 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 402 */	NdrFcShort( 0x3c4 ),	/* Type Offset=964 */

	/* Return value */

/* 404 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 406 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 408 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure remove */

/* 410 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 412 */	NdrFcLong( 0x0 ),	/* 0 */
/* 416 */	NdrFcShort( 0x10 ),	/* 16 */
#ifndef _ALPHA_
/* 418 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 420 */	NdrFcShort( 0x8 ),	/* 8 */
/* 422 */	NdrFcShort( 0x8 ),	/* 8 */
/* 424 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter index */

/* 426 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 428 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 430 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 432 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 434 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 436 */	0x8,		/* FC_LONG */
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
			0x11, 0x0,	/* FC_RP */
/*  4 */	NdrFcShort( 0x3c0 ),	/* Offset= 960 (964) */
/*  6 */
			0x12, 0x0,	/* FC_UP */
/*  8 */	NdrFcShort( 0x3a8 ),	/* Offset= 936 (944) */
/* 10 */
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 12 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 14 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 16 */	NdrFcShort( 0x2 ),	/* Offset= 2 (18) */
/* 18 */	NdrFcShort( 0x10 ),	/* 16 */
/* 20 */	NdrFcShort( 0x2b ),	/* 43 */
/* 22 */	NdrFcLong( 0x3 ),	/* 3 */
/* 26 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 28 */	NdrFcLong( 0x11 ),	/* 17 */
/* 32 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 34 */	NdrFcLong( 0x2 ),	/* 2 */
/* 38 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 40 */	NdrFcLong( 0x4 ),	/* 4 */
/* 44 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 46 */	NdrFcLong( 0x5 ),	/* 5 */
/* 50 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 52 */	NdrFcLong( 0xb ),	/* 11 */
/* 56 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 58 */	NdrFcLong( 0xa ),	/* 10 */
/* 62 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 64 */	NdrFcLong( 0x6 ),	/* 6 */
/* 68 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (282) */
/* 70 */	NdrFcLong( 0x7 ),	/* 7 */
/* 74 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 76 */	NdrFcLong( 0x8 ),	/* 8 */
/* 80 */	NdrFcShort( 0xd0 ),	/* Offset= 208 (288) */
/* 82 */	NdrFcLong( 0xd ),	/* 13 */
/* 86 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (312) */
/* 88 */	NdrFcLong( 0x9 ),	/* 9 */
/* 92 */	NdrFcShort( 0xee ),	/* Offset= 238 (330) */
/* 94 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 98 */	NdrFcShort( 0xfa ),	/* Offset= 250 (348) */
/* 100 */	NdrFcLong( 0x24 ),	/* 36 */
/* 104 */	NdrFcShort( 0x304 ),	/* Offset= 772 (876) */
/* 106 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 110 */	NdrFcShort( 0x2fe ),	/* Offset= 766 (876) */
/* 112 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 116 */	NdrFcShort( 0x2fc ),	/* Offset= 764 (880) */
/* 118 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 122 */	NdrFcShort( 0x2fa ),	/* Offset= 762 (884) */
/* 124 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 128 */	NdrFcShort( 0x2f8 ),	/* Offset= 760 (888) */
/* 130 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 134 */	NdrFcShort( 0x2f6 ),	/* Offset= 758 (892) */
/* 136 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 140 */	NdrFcShort( 0x2f4 ),	/* Offset= 756 (896) */
/* 142 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 146 */	NdrFcShort( 0x2e2 ),	/* Offset= 738 (884) */
/* 148 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 152 */	NdrFcShort( 0x2e0 ),	/* Offset= 736 (888) */
/* 154 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 158 */	NdrFcShort( 0x2e6 ),	/* Offset= 742 (900) */
/* 160 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 164 */	NdrFcShort( 0x2dc ),	/* Offset= 732 (896) */
/* 166 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 170 */	NdrFcShort( 0x2de ),	/* Offset= 734 (904) */
/* 172 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 176 */	NdrFcShort( 0x2dc ),	/* Offset= 732 (908) */
/* 178 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 182 */	NdrFcShort( 0x2da ),	/* Offset= 730 (912) */
/* 184 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 188 */	NdrFcShort( 0x2d8 ),	/* Offset= 728 (916) */
/* 190 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 194 */	NdrFcShort( 0x2d6 ),	/* Offset= 726 (920) */
/* 196 */	NdrFcLong( 0x10 ),	/* 16 */
/* 200 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 202 */	NdrFcLong( 0x12 ),	/* 18 */
/* 206 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 208 */	NdrFcLong( 0x13 ),	/* 19 */
/* 212 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 214 */	NdrFcLong( 0x16 ),	/* 22 */
/* 218 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 220 */	NdrFcLong( 0x17 ),	/* 23 */
/* 224 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 226 */	NdrFcLong( 0xe ),	/* 14 */
/* 230 */	NdrFcShort( 0x2ba ),	/* Offset= 698 (928) */
/* 232 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 236 */	NdrFcShort( 0x2c0 ),	/* Offset= 704 (940) */
/* 238 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 242 */	NdrFcShort( 0x27e ),	/* Offset= 638 (880) */
/* 244 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 248 */	NdrFcShort( 0x27c ),	/* Offset= 636 (884) */
/* 250 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 254 */	NdrFcShort( 0x27a ),	/* Offset= 634 (888) */
/* 256 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 260 */	NdrFcShort( 0x274 ),	/* Offset= 628 (888) */
/* 262 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 266 */	NdrFcShort( 0x26e ),	/* Offset= 622 (888) */
/* 268 */	NdrFcLong( 0x0 ),	/* 0 */
/* 272 */	NdrFcShort( 0x0 ),	/* Offset= 0 (272) */
/* 274 */	NdrFcLong( 0x1 ),	/* 1 */
/* 278 */	NdrFcShort( 0x0 ),	/* Offset= 0 (278) */
/* 280 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (279) */
/* 282 */
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 284 */	NdrFcShort( 0x8 ),	/* 8 */
/* 286 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 288 */
			0x12, 0x0,	/* FC_UP */
/* 290 */	NdrFcShort( 0xc ),	/* Offset= 12 (302) */
/* 292 */
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 294 */	NdrFcShort( 0x2 ),	/* 2 */
/* 296 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 298 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 300 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 302 */
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 304 */	NdrFcShort( 0x8 ),	/* 8 */
/* 306 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (292) */
/* 308 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 310 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 312 */
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 314 */	NdrFcLong( 0x0 ),	/* 0 */
/* 318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 322 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 324 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 326 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 328 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 330 */
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 332 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 340 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 342 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 344 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 346 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 348 */
			0x12, 0x0,	/* FC_UP */
/* 350 */	NdrFcShort( 0x1fc ),	/* Offset= 508 (858) */
/* 352 */
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 354 */	NdrFcShort( 0x18 ),	/* 24 */
/* 356 */	NdrFcShort( 0xa ),	/* 10 */
/* 358 */	NdrFcLong( 0x8 ),	/* 8 */
/* 362 */	NdrFcShort( 0x58 ),	/* Offset= 88 (450) */
/* 364 */	NdrFcLong( 0xd ),	/* 13 */
/* 368 */	NdrFcShort( 0x78 ),	/* Offset= 120 (488) */
/* 370 */	NdrFcLong( 0x9 ),	/* 9 */
/* 374 */	NdrFcShort( 0x94 ),	/* Offset= 148 (522) */
/* 376 */	NdrFcLong( 0xc ),	/* 12 */
/* 380 */	NdrFcShort( 0xbc ),	/* Offset= 188 (568) */
/* 382 */	NdrFcLong( 0x24 ),	/* 36 */
/* 386 */	NdrFcShort( 0x114 ),	/* Offset= 276 (662) */
/* 388 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 392 */	NdrFcShort( 0x130 ),	/* Offset= 304 (696) */
/* 394 */	NdrFcLong( 0x10 ),	/* 16 */
/* 398 */	NdrFcShort( 0x148 ),	/* Offset= 328 (726) */
/* 400 */	NdrFcLong( 0x2 ),	/* 2 */
/* 404 */	NdrFcShort( 0x160 ),	/* Offset= 352 (756) */
/* 406 */	NdrFcLong( 0x3 ),	/* 3 */
/* 410 */	NdrFcShort( 0x178 ),	/* Offset= 376 (786) */
/* 412 */	NdrFcLong( 0x14 ),	/* 20 */
/* 416 */	NdrFcShort( 0x190 ),	/* Offset= 400 (816) */
/* 418 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (417) */
/* 420 */
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 422 */	NdrFcShort( 0x4 ),	/* 4 */
/* 424 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 428 */
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 430 */
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 432 */	NdrFcShort( 0x4 ),	/* 4 */
/* 434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 436 */	NdrFcShort( 0x1 ),	/* 1 */
/* 438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 440 */	NdrFcShort( 0x0 ),	/* 0 */
/* 442 */	0x12, 0x0,	/* FC_UP */
/* 444 */	NdrFcShort( 0xffffff72 ),	/* Offset= -142 (302) */
/* 446 */
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 448 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 450 */
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 452 */	NdrFcShort( 0x8 ),	/* 8 */
/* 454 */
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 456 */
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 458 */	NdrFcShort( 0x4 ),	/* 4 */
/* 460 */	NdrFcShort( 0x4 ),	/* 4 */
/* 462 */	0x11, 0x0,	/* FC_RP */
/* 464 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (420) */
/* 466 */
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 468 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 470 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 474 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 478 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 482 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 484 */	NdrFcShort( 0xffffff54 ),	/* Offset= -172 (312) */
/* 486 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 488 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 490 */	NdrFcShort( 0x8 ),	/* 8 */
/* 492 */	NdrFcShort( 0x0 ),	/* 0 */
/* 494 */	NdrFcShort( 0x6 ),	/* Offset= 6 (500) */
/* 496 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 498 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 500 */
			0x11, 0x0,	/* FC_RP */
/* 502 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (470) */
/* 504 */
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 506 */	NdrFcShort( 0x0 ),	/* 0 */
/* 508 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 512 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 516 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 518 */	NdrFcShort( 0xffffff44 ),	/* Offset= -188 (330) */
/* 520 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 522 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 524 */	NdrFcShort( 0x8 ),	/* 8 */
/* 526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 528 */	NdrFcShort( 0x6 ),	/* Offset= 6 (534) */
/* 530 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 532 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 534 */
			0x11, 0x0,	/* FC_RP */
/* 536 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (504) */
/* 538 */
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 540 */	NdrFcShort( 0x4 ),	/* 4 */
/* 542 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 546 */
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 548 */
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 550 */	NdrFcShort( 0x4 ),	/* 4 */
/* 552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 554 */	NdrFcShort( 0x1 ),	/* 1 */
/* 556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 560 */	0x12, 0x0,	/* FC_UP */
/* 562 */	NdrFcShort( 0x17e ),	/* Offset= 382 (944) */
/* 564 */
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 566 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 568 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 570 */	NdrFcShort( 0x8 ),	/* 8 */
/* 572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 574 */	NdrFcShort( 0x6 ),	/* Offset= 6 (580) */
/* 576 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 578 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 580 */
			0x11, 0x0,	/* FC_RP */
/* 582 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (538) */
/* 584 */
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 586 */	NdrFcLong( 0x2f ),	/* 47 */
/* 590 */	NdrFcShort( 0x0 ),	/* 0 */
/* 592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 594 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 596 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 598 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 600 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 602 */
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 604 */	NdrFcShort( 0x1 ),	/* 1 */
/* 606 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 608 */	NdrFcShort( 0x4 ),	/* 4 */
/* 610 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 612 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 614 */	NdrFcShort( 0x10 ),	/* 16 */
/* 616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 618 */	NdrFcShort( 0xa ),	/* Offset= 10 (628) */
/* 620 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 622 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 624 */	NdrFcShort( 0xffffffd8 ),	/* Offset= -40 (584) */
/* 626 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 628 */
			0x12, 0x0,	/* FC_UP */
/* 630 */	NdrFcShort( 0xffffffe4 ),	/* Offset= -28 (602) */
/* 632 */
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 634 */	NdrFcShort( 0x4 ),	/* 4 */
/* 636 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 640 */
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 642 */
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 644 */	NdrFcShort( 0x4 ),	/* 4 */
/* 646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 648 */	NdrFcShort( 0x1 ),	/* 1 */
/* 650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 654 */	0x12, 0x0,	/* FC_UP */
/* 656 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (612) */
/* 658 */
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 660 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 662 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 664 */	NdrFcShort( 0x8 ),	/* 8 */
/* 666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 668 */	NdrFcShort( 0x6 ),	/* Offset= 6 (674) */
/* 670 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 672 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 674 */
			0x11, 0x0,	/* FC_RP */
/* 676 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (632) */
/* 678 */
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 680 */	NdrFcShort( 0x8 ),	/* 8 */
/* 682 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 684 */
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 686 */	NdrFcShort( 0x10 ),	/* 16 */
/* 688 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 690 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 692 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffff1 ),	/* Offset= -15 (678) */
			0x5b,		/* FC_END */
/* 696 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 698 */	NdrFcShort( 0x18 ),	/* 24 */
/* 700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 702 */	NdrFcShort( 0xa ),	/* Offset= 10 (712) */
/* 704 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 706 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 708 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (684) */
/* 710 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 712 */
			0x11, 0x0,	/* FC_RP */
/* 714 */	NdrFcShort( 0xffffff0c ),	/* Offset= -244 (470) */
/* 716 */
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 718 */	NdrFcShort( 0x1 ),	/* 1 */
/* 720 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 724 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 726 */
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 728 */	NdrFcShort( 0x8 ),	/* 8 */
/* 730 */
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 732 */
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 734 */	NdrFcShort( 0x4 ),	/* 4 */
/* 736 */	NdrFcShort( 0x4 ),	/* 4 */
/* 738 */	0x12, 0x0,	/* FC_UP */
/* 740 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (716) */
/* 742 */
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 744 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 746 */
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 748 */	NdrFcShort( 0x2 ),	/* 2 */
/* 750 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 754 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 756 */
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 758 */	NdrFcShort( 0x8 ),	/* 8 */
/* 760 */
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 762 */
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 764 */	NdrFcShort( 0x4 ),	/* 4 */
/* 766 */	NdrFcShort( 0x4 ),	/* 4 */
/* 768 */	0x12, 0x0,	/* FC_UP */
/* 770 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (746) */
/* 772 */
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 774 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 776 */
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 778 */	NdrFcShort( 0x4 ),	/* 4 */
/* 780 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 784 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 786 */
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 788 */	NdrFcShort( 0x8 ),	/* 8 */
/* 790 */
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 792 */
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 794 */	NdrFcShort( 0x4 ),	/* 4 */
/* 796 */	NdrFcShort( 0x4 ),	/* 4 */
/* 798 */	0x12, 0x0,	/* FC_UP */
/* 800 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (776) */
/* 802 */
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 804 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 806 */
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 808 */	NdrFcShort( 0x8 ),	/* 8 */
/* 810 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 814 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 816 */
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 818 */	NdrFcShort( 0x8 ),	/* 8 */
/* 820 */
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 822 */
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 824 */	NdrFcShort( 0x4 ),	/* 4 */
/* 826 */	NdrFcShort( 0x4 ),	/* 4 */
/* 828 */	0x12, 0x0,	/* FC_UP */
/* 830 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (806) */
/* 832 */
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 834 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 836 */
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 838 */	NdrFcShort( 0x8 ),	/* 8 */
/* 840 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 842 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 844 */
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 846 */	NdrFcShort( 0x8 ),	/* 8 */
/* 848 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 850 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 852 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 854 */	NdrFcShort( 0xffffffee ),	/* Offset= -18 (836) */
/* 856 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 858 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 860 */	NdrFcShort( 0x28 ),	/* 40 */
/* 862 */	NdrFcShort( 0xffffffee ),	/* Offset= -18 (844) */
/* 864 */	NdrFcShort( 0x0 ),	/* Offset= 0 (864) */
/* 866 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 868 */	0x38,		/* FC_ALIGNM4 */
			0x8,		/* FC_LONG */
/* 870 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 872 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffdf7 ),	/* Offset= -521 (352) */
			0x5b,		/* FC_END */
/* 876 */
			0x12, 0x0,	/* FC_UP */
/* 878 */	NdrFcShort( 0xfffffef6 ),	/* Offset= -266 (612) */
/* 880 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 882 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 884 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 886 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 888 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 890 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 892 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 894 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 896 */
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 898 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 900 */
			0x12, 0x0,	/* FC_UP */
/* 902 */	NdrFcShort( 0xfffffd94 ),	/* Offset= -620 (282) */
/* 904 */
			0x12, 0x10,	/* FC_UP */
/* 906 */	NdrFcShort( 0xfffffd96 ),	/* Offset= -618 (288) */
/* 908 */
			0x12, 0x10,	/* FC_UP */
/* 910 */	NdrFcShort( 0xfffffdaa ),	/* Offset= -598 (312) */
/* 912 */
			0x12, 0x10,	/* FC_UP */
/* 914 */	NdrFcShort( 0xfffffdb8 ),	/* Offset= -584 (330) */
/* 916 */
			0x12, 0x10,	/* FC_UP */
/* 918 */	NdrFcShort( 0xfffffdc6 ),	/* Offset= -570 (348) */
/* 920 */
			0x12, 0x10,	/* FC_UP */
/* 922 */	NdrFcShort( 0x2 ),	/* Offset= 2 (924) */
/* 924 */
			0x12, 0x0,	/* FC_UP */
/* 926 */	NdrFcShort( 0xfffffc62 ),	/* Offset= -926 (0) */
/* 928 */
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 930 */	NdrFcShort( 0x10 ),	/* 16 */
/* 932 */	0x6,		/* FC_SHORT */
			0x2,		/* FC_CHAR */
/* 934 */	0x2,		/* FC_CHAR */
			0x38,		/* FC_ALIGNM4 */
/* 936 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 938 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 940 */
			0x12, 0x0,	/* FC_UP */
/* 942 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (928) */
/* 944 */
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 946 */	NdrFcShort( 0x20 ),	/* 32 */
/* 948 */	NdrFcShort( 0x0 ),	/* 0 */
/* 950 */	NdrFcShort( 0x0 ),	/* Offset= 0 (950) */
/* 952 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 954 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 956 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 958 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 960 */	NdrFcShort( 0xfffffc4a ),	/* Offset= -950 (10) */
/* 962 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 964 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 968 */	NdrFcShort( 0x10 ),	/* 16 */
/* 970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 972 */	NdrFcShort( 0xfffffc3a ),	/* Offset= -966 (6) */
/* 974 */
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 976 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 978 */
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 980 */	NdrFcShort( 0x6 ),	/* Offset= 6 (986) */
/* 982 */
			0x13, 0x0,	/* FC_OP */
/* 984 */	NdrFcShort( 0xfffffd56 ),	/* Offset= -682 (302) */
/* 986 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 988 */	NdrFcShort( 0x1 ),	/* 1 */
/* 990 */	NdrFcShort( 0x4 ),	/* 4 */
/* 992 */	NdrFcShort( 0x0 ),	/* 0 */
/* 994 */	NdrFcShort( 0xfffffff4 ),	/* Offset= -12 (982) */
/* 996 */
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 998 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 1000 */
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1002 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1008) */
/* 1004 */
			0x13, 0x0,	/* FC_OP */
/* 1006 */	NdrFcShort( 0xffffffc2 ),	/* Offset= -62 (944) */
/* 1008 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1012 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1014 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1016 */	NdrFcShort( 0xfffffff4 ),	/* Offset= -12 (1004) */
/* 1018 */
			0x11, 0x10,	/* FC_RP */
/* 1020 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1022) */
/* 1022 */
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1024 */	NdrFcLong( 0x9a64e934 ),	/* -1704662732 */
/* 1028 */	NdrFcShort( 0xfb27 ),	/* -1241 */
/* 1030 */	NdrFcShort( 0x4584 ),	/* 17796 */
/* 1032 */	0x90,		/* 144 */
			0x4d,		/* 77 */
/* 1034 */	0x2d,		/* 45 */
			0xff,		/* 255 */
/* 1036 */	0xd2,		/* 210 */
			0xd7,		/* 215 */
/* 1038 */	0x55,		/* 85 */
			0x65,		/* 101 */

			0x0
        }
    };

const CInterfaceProxyVtbl * _bastype_ProxyVtblList[] =
{
    ( CInterfaceProxyVtbl *) &_IIteratorProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IVectorProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IListProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IComparableProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStringizableProxyVtbl,
    0
};

const CInterfaceStubVtbl * _bastype_StubVtblList[] =
{
    ( CInterfaceStubVtbl *) &_IIteratorStubVtbl,
    ( CInterfaceStubVtbl *) &_IVectorStubVtbl,
    ( CInterfaceStubVtbl *) &_IListStubVtbl,
    ( CInterfaceStubVtbl *) &_IComparableStubVtbl,
    ( CInterfaceStubVtbl *) &_IStringizableStubVtbl,
    0
};

PCInterfaceName const _bastype_InterfaceNamesList[] =
{
    "IIterator",
    "IVector",
    "IList",
    "IComparable",
    "IStringizable",
    0
};

const IID *  _bastype_BaseIIDList[] =
{
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _bastype_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _bastype, pIID, n)

int __stdcall _bastype_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _bastype, 5, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _bastype, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _bastype, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _bastype, 5, *pIndex )

}

const ExtendedProxyFileInfo bastype_ProxyFileInfo =
{
    (PCInterfaceProxyVtblList *) & _bastype_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _bastype_StubVtblList,
    (const PCInterfaceName * ) & _bastype_InterfaceNamesList,
    (const IID ** ) & _bastype_BaseIIDList,
    & _bastype_IID_Lookup,
    5,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
