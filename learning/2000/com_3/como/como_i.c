/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed May 23 15:07:10 2001
 */
/* Compiler settings for V:\Components\Lab\TestCom\como\como.idl:
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

const IID IID_IComo1 = {0x15543F16,0x8B52,0x4D45,{0x89,0x42,0x5A,0x47,0xF8,0xE6,0x26,0x56}};


const IID LIBID_COMOLib = {0xFB196AC8,0x4E59,0x4562,{0xBD,0x7B,0xC0,0x2A,0x4A,0xE0,0x20,0xAF}};


const CLSID CLSID_Como1 = {0xE426ABDA,0x158A,0x42BE,{0x92,0x4B,0x2A,0x40,0x7A,0x37,0xFF,0x36}};


#ifdef __cplusplus
}
#endif
