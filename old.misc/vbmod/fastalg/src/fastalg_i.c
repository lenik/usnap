/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Jun 01 14:22:02 2006
 */
/* Compiler settings for C:\.lokaj\zbmis\module\fastalg\src\fastalg.idl:
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

const IID IID_ISAOT = {0xAECAFF4C,0x5D51,0x483A,{0x86,0x19,0xE8,0x05,0x11,0xE6,0x94,0x39}};


const IID IID_IDRIA = {0x604D4559,0x902D,0x4066,{0xB1,0xFA,0x81,0xF6,0x92,0x61,0x05,0x19}};


const IID LIBID_FastAlgLib = {0x5B4DC081,0x852D,0x4465,{0x89,0x8E,0xD1,0x79,0x45,0x42,0x34,0xDA}};


const IID DIID__ISAOTEvents = {0x8DDACB85,0x672D,0x47D7,{0x80,0x74,0x4F,0x3B,0x57,0xA9,0x2F,0x3D}};


const IID IID_IHashCode = {0x7F1F1F9A,0x2B2A,0x407D,{0xBC,0x23,0xB7,0xD9,0xD3,0xF8,0xA2,0x30}};


const CLSID CLSID_SAOT = {0xCD583388,0xD348,0x4A9E,{0xBB,0xBB,0x9A,0x8D,0x25,0xF3,0xDA,0xAD}};


const CLSID CLSID_DRIA = {0xAF43CEA4,0xBF31,0x4BF7,{0xAE,0xB6,0xEA,0xD4,0x1B,0xB7,0xB4,0x76}};


const CLSID CLSID_HashCode = {0x4773BB15,0x41A1,0x4AC1,{0x96,0x61,0x2B,0x83,0xD1,0x8C,0x2A,0x95}};


#ifdef __cplusplus
}
#endif