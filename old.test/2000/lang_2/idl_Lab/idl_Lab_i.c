/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed May 09 10:06:17 2001
 */
/* Compiler settings for V:\temp\LABc\idl_Lab\idl_Lab.idl:
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

const IID LIBID_IDL_LABLib = {0x3D1F6C9E,0x3E6A,0x46D8,{0x9B,0x02,0x34,0xC9,0x07,0xF7,0x31,0x27}};


const IID IID_I1 = {0x10000000,0x3E6A,0x46D8,{0x9B,0x02,0x34,0xC9,0x07,0xF7,0x31,0x27}};


const IID IID_I2 = {0x10000001,0x3E6A,0x46D8,{0x9B,0x02,0x34,0xC9,0x07,0xF7,0x31,0x27}};


const IID IID_IRedeclare = {0x4C210737,0x8C2C,0x453A,{0x9E,0xEF,0x82,0x08,0xAE,0x5B,0x43,0xD4}};


const IID DIID_IRedeclareEvents = {0x43289783,0x3278,0x6489,{0x23,0x45,0x67,0x89,0x32,0x31,0x28,0x90}};


const CLSID CLSID_Redeclare = {0x34096CD0,0xC731,0x4630,{0xBB,0x45,0x68,0xB5,0x91,0x57,0x40,0xC3}};


#ifdef __cplusplus
}
#endif
