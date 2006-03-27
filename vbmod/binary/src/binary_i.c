/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Mar 22 17:03:49 2006
 */
/* Compiler settings for C:\.lokaj\zbmis\module\binary\src\binary.idl:
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

const IID IID_IBase64 = {0xA051359F,0xBF80,0x4014,{0xB5,0x0D,0x74,0xC5,0x97,0xCB,0x0F,0xE4}};


const IID LIBID_BinaryLib = {0xE8017760,0xAC1B,0x47E5,{0x91,0x9B,0xDE,0x90,0xC2,0x98,0xBB,0xE3}};


const CLSID CLSID_Base64 = {0x7867B0A2,0xC95C,0x4B3D,{0x8E,0x0D,0x7A,0x00,0x6D,0xAA,0xB0,0xBC}};


#ifdef __cplusplus
}
#endif
