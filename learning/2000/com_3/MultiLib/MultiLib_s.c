/* this ALWAYS GENERATED file contains the RPC server stubs */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 16 08:12:16 2001
 */
/* Compiler settings for V:\Components\Lab\TestCom\MultiLib\MultiLib.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data
*/
//@@MIDL_FILE_HEADING(  )

#include <string.h>
#include "MultiLib.h"

#define TYPE_FORMAT_STRING_SIZE   3
#define PROC_FORMAT_STRING_SIZE   23

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

/* Standard interface: ICaMultiInt1_1, ver. 0.0,
   GUID={0x00000000,0x4341,0xFFF0,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}} */


extern const MIDL_SERVER_INFO ICaMultiInt1_1_ServerInfo;

extern RPC_DISPATCH_TABLE ICaMultiInt1_1_v0_0_DispatchTable;

static const RPC_SERVER_INTERFACE ICaMultiInt1_1___RpcServerInterface =
    {
    sizeof(RPC_SERVER_INTERFACE),
    {{0x00000000,0x4341,0xFFF0,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}},{0,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    &ICaMultiInt1_1_v0_0_DispatchTable,
    0,
    0,
    0,
    &ICaMultiInt1_1_ServerInfo,
    0
    };
RPC_IF_HANDLE ICaMultiInt1_1_v0_0_s_ifspec = (RPC_IF_HANDLE)& ICaMultiInt1_1___RpcServerInterface;

extern const MIDL_STUB_DESC ICaMultiInt1_1_StubDesc;


static const MIDL_STUB_DESC ICaMultiInt1_1_StubDesc =
    {
    (void __RPC_FAR *)& ICaMultiInt1_1___RpcServerInterface,
    MIDL_user_allocate,
    MIDL_user_free,
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

static RPC_DISPATCH_FUNCTION ICaMultiInt1_1_table[] =
    {
    NdrServerCall2,
    0
    };
RPC_DISPATCH_TABLE ICaMultiInt1_1_v0_0_DispatchTable =
    {
    1,
    ICaMultiInt1_1_table
    };

static const SERVER_ROUTINE ICaMultiInt1_1_ServerRoutineTable[] =
    {
    (SERVER_ROUTINE)AboutBox
    };

static const unsigned short ICaMultiInt1_1_FormatStringOffsetTable[] =
    {
    0
    };

static const MIDL_SERVER_INFO ICaMultiInt1_1_ServerInfo =
    {
    &ICaMultiInt1_1_StubDesc,
    ICaMultiInt1_1_ServerRoutineTable,
    __MIDL_ProcFormatString.Format,
    ICaMultiInt1_1_FormatStringOffsetTable,
    0,
    0,
    0,
    0
    };


/* Standard interface: ICaMultiInt2_1, ver. 0.0,
   GUID={0x00000000,0x4341,0xFFF1,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}} */


extern const MIDL_SERVER_INFO ICaMultiInt2_1_ServerInfo;

extern RPC_DISPATCH_TABLE ICaMultiInt2_1_v0_0_DispatchTable;

static const RPC_SERVER_INTERFACE ICaMultiInt2_1___RpcServerInterface =
    {
    sizeof(RPC_SERVER_INTERFACE),
    {{0x00000000,0x4341,0xFFF1,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}},{0,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    &ICaMultiInt2_1_v0_0_DispatchTable,
    0,
    0,
    0,
    &ICaMultiInt2_1_ServerInfo,
    0
    };
RPC_IF_HANDLE ICaMultiInt2_1_v0_0_s_ifspec = (RPC_IF_HANDLE)& ICaMultiInt2_1___RpcServerInterface;

extern const MIDL_STUB_DESC ICaMultiInt2_1_StubDesc;


static const MIDL_STUB_DESC ICaMultiInt2_1_StubDesc =
    {
    (void __RPC_FAR *)& ICaMultiInt2_1___RpcServerInterface,
    MIDL_user_allocate,
    MIDL_user_free,
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

static RPC_DISPATCH_FUNCTION ICaMultiInt2_1_table[] =
    {
    NdrServerCall2,
    0
    };
RPC_DISPATCH_TABLE ICaMultiInt2_1_v0_0_DispatchTable =
    {
    1,
    ICaMultiInt2_1_table
    };

static const SERVER_ROUTINE ICaMultiInt2_1_ServerRoutineTable[] =
    {
    (SERVER_ROUTINE)AboutBox2
    };

static const unsigned short ICaMultiInt2_1_FormatStringOffsetTable[] =
    {
    0
    };

static const MIDL_SERVER_INFO ICaMultiInt2_1_ServerInfo =
    {
    &ICaMultiInt2_1_StubDesc,
    ICaMultiInt2_1_ServerRoutineTable,
    __MIDL_ProcFormatString.Format,
    ICaMultiInt2_1_FormatStringOffsetTable,
    0,
    0,
    0,
    0
    };

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

	/* Procedure AboutBox2 */


	/* Procedure AboutBox */

			0x33,		/* FC_AUTO_HANDLE */
			0x48,		/* Old Flags:  */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
#ifndef _ALPHA_
/*  8 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */


	/* Return value */

/* 16 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 18 */	NdrFcShort( 0x0 ),	/* x86, MIPS, PPC Stack size/offset = 0 */
#else
			NdrFcShort( 0x0 ),	/* Alpha Stack size/offset = 0 */
#endif
/* 20 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

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
