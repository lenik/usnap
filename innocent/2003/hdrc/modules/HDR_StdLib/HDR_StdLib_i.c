/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Aug 14 12:26:02 2003
 */
/* Compiler settings for C:\s_prjs\Data Rescuer\modules\HDR_StdLib\HDR_StdLib.idl:
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

const IID IID_IModuleProvider = {0x3B945220,0x0A12,0x4739,{0xBF,0x4D,0xB1,0x78,0xB9,0xA2,0x75,0x67}};


const IID IID_IFileTypeVerifier = {0xA0C7541D,0xA322,0x4552,{0xAB,0xA5,0x1C,0x83,0x70,0x4B,0xBC,0x8C}};


const IID LIBID_HDR_StdLib = {0x82455322,0x674D,0x4C99,{0xAB,0xA8,0x46,0x76,0x46,0xCA,0xB8,0x3F}};


const CLSID CLSID_ModuleProvider = {0xA90F2663,0x2290,0x430A,{0x9B,0x48,0x28,0xA0,0x9D,0xF9,0xC3,0x79}};


const CLSID CLSID_StdFileTypeVerifier = {0x32C84E18,0x9406,0x4AE2,{0xA8,0xED,0xBB,0x55,0xDB,0xF2,0xA9,0xB9}};


#ifdef __cplusplus
}
#endif
