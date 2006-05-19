/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue May 02 14:54:29 2006
 */
/* Compiler settings for C:\.lokaj\zbmis\module\nettools\NetTools.idl:
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

const IID LIBID_NetToolsLib = {0xD430659F,0xA6B1,0x4482,{0x8E,0xF0,0x31,0xA4,0x50,0xE4,0xF2,0x68}};


const IID IID_IGlobals = {0xFA417E17,0x08CF,0x4D1D,{0x8E,0x5A,0xD3,0xBD,0x57,0x96,0x44,0x56}};


const IID IID_IRemoteFSO = {0x29138607,0x9B6E,0x4128,{0xB1,0x37,0x7D,0x63,0x29,0x02,0x9D,0xD4}};


const CLSID CLSID_Globals = {0xF3BAD689,0xA6EF,0x44D8,{0x93,0xD3,0x79,0xF5,0x0F,0x0C,0x79,0x1D}};


const CLSID CLSID_RemoteFSO = {0x7FFFE503,0xAC6C,0x4B17,{0xAB,0x54,0x77,0x33,0x62,0x4B,0xC7,0x75}};


#ifdef __cplusplus
}
#endif
