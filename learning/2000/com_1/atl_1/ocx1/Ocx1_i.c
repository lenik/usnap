/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Mar 28 18:27:39 2001
 */
/* Compiler settings for V:\temp\atl01\ocx1\ocx1.odl:
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

const IID LIBID_OCX1Lib = {0xBAA75D00,0x2035,0x4FEE,{0xBA,0x07,0x7D,0x6E,0x78,0xA5,0x41,0xC9}};


const IID DIID__DOcx1 = {0x8E36F09E,0xBC6A,0x4A8E,{0x8B,0x7F,0x78,0x95,0x34,0x9F,0x5D,0xB3}};


const IID DIID__DOcx1Events = {0x19548CCB,0xD942,0x42A6,{0xB1,0x0A,0xA9,0x86,0xE0,0x1E,0x58,0x65}};


const IID IID_IHelloControl = {0x6F723297,0x7201,0x4B7A,{0xBD,0x51,0xA8,0x71,0x48,0x69,0x87,0x88}};


const CLSID CLSID_Ocx1 = {0xB06B99C6,0xE6A2,0x4C0A,{0x97,0xF4,0x6E,0xA9,0xD2,0x75,0x6B,0xDF}};


const CLSID CLSID_HelloControl = {0xE2CD5265,0xB80F,0x4A18,{0x9A,0xA2,0x71,0xFE,0xB2,0x2C,0x6D,0xF2}};


#ifdef __cplusplus
}
#endif
