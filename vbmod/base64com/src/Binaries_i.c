/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Sep 01 13:43:32 2005
 */
/* Compiler settings for X:\base64com\Binaries\Binaries.idl:
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

const IID LIBID_BinariesLib = {0xC565B2A3,0xF3A2,0x4BD9,{0xB0,0xB9,0x29,0xCE,0xBE,0x33,0x0C,0x3B}};


const IID IID_IBase64 = {0xE75C5C81,0x06E1,0x45A4,{0xB7,0x2C,0x26,0xB4,0xD1,0x93,0x3A,0xBA}};


const CLSID CLSID_Base64 = {0xA7687779,0x319D,0x4291,{0xA4,0xB3,0x48,0xE0,0x43,0x62,0x72,0x42}};


#ifdef __cplusplus
}
#endif
