/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Nov 11 00:02:34 2001
 */
/* Compiler settings for C:\S\develop\General\temp1\g1\atl1\atl1.idl:
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

const IID IID_Ic1 = {0x819833DA,0xE706,0x44D1,{0x85,0x3B,0xD1,0xEC,0x4B,0x0D,0xF9,0xC8}};


const IID LIBID_ATL1Lib = {0xDAB14B83,0x12E0,0x4874,{0xAA,0x0E,0x37,0x80,0x47,0x31,0x9A,0x58}};


const CLSID CLSID_c1 = {0xF6480BDA,0x60AD,0x464B,{0xA7,0x64,0xC6,0x4F,0x8B,0x7E,0x48,0x01}};


#ifdef __cplusplus
}
#endif
