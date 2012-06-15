/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Apr 27 00:07:12 2001
 */
/* Compiler settings for V:\Components\Lab\TestCom\ClassUsage\ClassUsage.idl:
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

const IID IID_IA = {0x2F8F423F,0x5966,0x43EF,{0x89,0xEB,0x49,0xE1,0xF5,0xF7,0x5D,0x12}};


const IID LIBID_CLASSUSAGELib = {0xDFEA8E82,0x55DE,0x445D,{0xB7,0x0D,0xD0,0xF9,0xA4,0x85,0x6B,0xC0}};


const CLSID CLSID_A = {0x5C1CC9F7,0xC55E,0x4563,{0x86,0xE6,0xE3,0xB9,0x15,0x06,0xC7,0x5D}};


#ifdef __cplusplus
}
#endif
