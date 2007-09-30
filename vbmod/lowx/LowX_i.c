/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed May 28 10:17:10 2003
 */
/* Compiler settings for Z:\s\t\X-api\LowX\LowX.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID LIBID_LowXRuntime = {0x36BC9BEB,0xBB9A,0x4AD0,{0x9F,0x70,0x17,0x34,0x9F,0xCD,0xE1,0x41}};


const IID IID_IVtbl = {0x8D38C0E7,0xD874,0x4CA7,{0x8C,0x3D,0x10,0xA7,0x3A,0xFE,0x09,0xFE}};


const IID IID_IPseudoControl = {0xC962462E,0x72F9,0x4EDB,{0x83,0xF8,0xCA,0xCA,0x71,0x87,0x9D,0x4A}};


const IID IID_IPseudoControlSetting = {0x65A27F5B,0x0458,0x4708,{0xB7,0xEE,0x18,0x92,0xE3,0x37,0xDA,0x40}};


const IID IID_IRawDataType = {0xA17F4A94,0xF191,0x4FE6,{0xAA,0x97,0x2A,0xC1,0x92,0x36,0xFA,0x4A}};


const IID IID_IPointer = {0xD6AD9A66,0xC2AD,0x430C,{0xBD,0xCA,0x7E,0x29,0x87,0xF2,0xE3,0x79}};


const IID IID_ICall = {0x540EF1A7,0x3138,0x4CEA,{0xB6,0x87,0x70,0x23,0x2B,0xE4,0x10,0x4B}};


const IID IID_IExecute = {0xBCF5F099,0xE368,0x4A58,{0xBE,0x7E,0xA5,0xAD,0xE4,0x2B,0xD0,0x6A}};


const IID IID_IDebugger = {0x1BCC83D3,0x1109,0x4E67,{0x80,0x8D,0xB2,0x2E,0x68,0x1D,0xB7,0x12}};


const IID IID_ICpu_x86 = {0x1BCC8400,0x1109,0x4E67,{0x80,0x8D,0xB2,0x2E,0x68,0x1D,0xB7,0x12}};


const IID IID_IString = {0xA6AD47FE,0xD7D6,0x4C93,{0x8B,0x44,0x50,0x39,0x43,0x4D,0xF9,0x03}};


const IID IID_IMemory = {0xEEA54CDA,0x4E5D,0x43EE,{0xA3,0x63,0x72,0xEF,0xAB,0x0C,0xBC,0x19}};


const CLSID CLSID_Vtbl = {0xA2D85E1C,0x5085,0x4F25,{0xBB,0x95,0xB4,0x20,0x45,0x10,0x08,0xF9}};


const CLSID CLSID_PseudoControl = {0x3579734B,0x194A,0x4C23,{0x84,0xA2,0xB8,0x61,0x5E,0x29,0x20,0x94}};


const CLSID CLSID_PseudoControlSetting = {0x21E39224,0xA960,0x48CD,{0xA0,0x76,0xD5,0xD4,0x23,0xE0,0x35,0x84}};


const CLSID CLSID_RawDataType = {0x913916A2,0x4868,0x4CC0,{0xBF,0x09,0x78,0xA6,0xAD,0x5B,0x90,0x83}};


const CLSID CLSID_Pointer = {0x6B3EFF6B,0x7EB4,0x4E08,{0xA6,0x90,0x1B,0xC3,0x8D,0x31,0xF5,0x3C}};


const CLSID CLSID_Call = {0x5AFD4512,0x5609,0x49A1,{0xAD,0x89,0x80,0xF8,0x8D,0x44,0x64,0xFC}};


const CLSID CLSID_Execute = {0xED472E8C,0x54B5,0x4408,{0x96,0x63,0x1D,0x97,0x0E,0x1F,0x40,0x8A}};


const CLSID CLSID_Debugger = {0x375066FE,0x8E0F,0x4A0B,{0xAF,0xDE,0x61,0x5E,0xE7,0x9E,0xC2,0xD1}};


const CLSID CLSID_String = {0x955CE7C6,0x615A,0x4798,{0xAD,0x8A,0x9A,0x24,0x97,0xD6,0x5D,0x62}};


const CLSID CLSID_Memory = {0xBF70DC19,0xCECB,0x45A9,{0xB7,0x9F,0x05,0x90,0xE5,0x44,0x9B,0x73}};


#ifdef __cplusplus
}
#endif
