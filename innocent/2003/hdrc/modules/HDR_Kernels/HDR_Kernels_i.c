/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue Aug 05 20:00:02 2003
 */
/* Compiler settings for C:\s_prjs\Data Rescuer\modules\HDR_Kernels\HDR_Kernels.idl:
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

const IID IID_IDriverLoader = {0x2DD54D33,0xAC77,0x4189,{0xAB,0x52,0x8C,0xA2,0x78,0xA0,0x2D,0x8D}};


const IID IID_IDriverEnum = {0x2DD54D34,0xAC77,0x4189,{0xAB,0x52,0x8C,0xA2,0x78,0xA0,0x2D,0x8D}};


const IID IID_ILDAccess = {0xBA6E48AA,0x25CC,0x45A4,{0xBB,0x80,0x56,0x77,0x9F,0x68,0xD4,0x75}};


const IID IID_ILDCache = {0xBA6E48AB,0x25CC,0x45A4,{0xBB,0x80,0x56,0x77,0x9F,0x68,0xD4,0x75}};


const IID IID_ILDLargeIO = {0xBA6E48AC,0x25CC,0x45A4,{0xBB,0x80,0x56,0x77,0x9F,0x68,0xD4,0x75}};


const IID IID_IWin32DiskLD = {0xBA6E48FF,0x25CC,0x45A4,{0xBB,0x80,0x56,0x77,0x9F,0x68,0xD4,0x75}};


const IID LIBID_HDR_KernelsLib = {0xAF4C573C,0x9057,0x456F,{0x90,0x2F,0x56,0x50,0xCC,0xE6,0x70,0x8D}};


const IID DIID__IDriverEnumEvents = {0x288A49DD,0x01DA,0x4D2E,{0xB5,0x3F,0xA4,0x30,0x27,0x0A,0xCE,0xA1}};


const CLSID CLSID_DriversManager = {0x1059127F,0xB46F,0x4B73,{0xBE,0x8D,0x15,0xB7,0xDC,0x8C,0x39,0xFC}};


const CLSID CLSID_Win32DiskLD = {0x8270F7BD,0x1D9D,0x48D6,{0xB2,0x0F,0x38,0x23,0xE0,0xCE,0x2A,0xFF}};


#ifdef __cplusplus
}
#endif
