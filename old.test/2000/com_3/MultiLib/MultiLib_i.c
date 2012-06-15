/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 16 08:15:35 2001
 */
/* Compiler settings for V:\Components\Lab\TestCom\MultiLib\MultiLib.idl:
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

const IID IID_ICaMultiInt1_1 = {0x00000000,0x4341,0xFFF0,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_ICaMultiInt2_1 = {0x00000000,0x4341,0xFFF1,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID LIBID_CaMultiIntLib = {0x00000000,0x4341,0xFFF0,{0x00,0x04,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_CaMultiInt1 = {0x00000000,0x4341,0xFFF0,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_CaMultiInt2 = {0x00000000,0x4341,0xFFF1,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


#ifdef __cplusplus
}
#endif
