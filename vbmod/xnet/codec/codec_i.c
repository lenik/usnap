/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Jun 11 08:40:18 2006
 */
/* Compiler settings for C:\.lokaj\zbmis\module\xnet\codec\codec.idl:
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

const IID LIBID_XnetCodec = {0xC4249C87,0x3E35,0x46ED,{0xA9,0x0F,0x49,0x05,0xDE,0x37,0xCF,0x38}};


const IID IID_IStatement = {0x94567C48,0xF5B2,0x4CF4,{0xAF,0xF5,0x13,0xC8,0xEA,0x17,0xC4,0x5C}};


const IID IID_IInputBuffer = {0xCC0D8002,0x81AE,0x462F,{0x81,0x86,0x23,0x89,0xA9,0x4F,0x57,0xF7}};


const CLSID CLSID_Statement = {0xAA02BE05,0x8896,0x49C0,{0xB1,0x38,0xF6,0x02,0xF9,0x0D,0x33,0x1F}};


const CLSID CLSID_InputBuffer = {0x42590081,0x98E7,0x4C1C,{0xB7,0x9B,0xEC,0x19,0x1D,0xD0,0xD8,0x93}};


#ifdef __cplusplus
}
#endif
