/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 02 22:21:11 2001
 */
/* Compiler settings for S:\lib\campoEngine\working\ceVersion\ceVersion.idl:
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

const IID LIBID_CeVersionLib = {0x00000000,0x4345,0x0001,{0x00,0x04,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_ICeVersion = {0x00000000,0x4345,0x0001,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_CeVersionSimple = {0x00000000,0x4345,0x0001,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


#ifdef __cplusplus
}
#endif
