/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Mar 17 08:32:13 2006
 */
/* Compiler settings for C:\.lokaj\zbmis\module\crypt\src\Crypt.idl:
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

const IID IID_IDigest = {0x37ECCF71,0xE520,0x4791,{0xAB,0x28,0x48,0x24,0x55,0xE1,0x18,0x1F}};


const IID LIBID_CryptLib = {0xD8D70B81,0x644C,0x48F2,{0xAB,0xC2,0x3F,0xCE,0xC3,0xB2,0x1B,0xCA}};


const CLSID CLSID_Digest = {0x5585D1C0,0x3D20,0x4E4D,{0x9E,0xA0,0x78,0xA1,0x3D,0x55,0x54,0x0D}};


#ifdef __cplusplus
}
#endif
