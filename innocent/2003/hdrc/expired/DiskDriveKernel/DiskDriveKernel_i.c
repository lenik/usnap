/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Jul 16 19:47:52 2003
 */
/* Compiler settings for C:\S_PRJS\DATA RESCUER\MODULES\DiskDriveKernel\DiskDriveKernel.idl:
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

const IID IID_ISysDriveEnum = {0x8E152B2A,0xC5DB,0x4B5E,{0x91,0xA5,0x44,0xD1,0x6D,0x22,0x9B,0x9D}};


const IID LIBID_DiskDriveKernel = {0xE6EB98ED,0x8D27,0x4BA9,{0xB0,0xCF,0xCE,0x76,0xB5,0xD8,0x86,0x40}};


const IID DIID__ISysDriveEnumEvents = {0x8CD361E9,0x1B05,0x4798,{0x87,0xEE,0xC5,0x1D,0xED,0xD8,0x79,0x99}};


const CLSID CLSID_SysDriveEnum = {0x1C0EA6C8,0xA4AB,0x4987,{0xBE,0xE8,0x57,0xFD,0xFF,0x60,0x51,0xF4}};


#ifdef __cplusplus
}
#endif
