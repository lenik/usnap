/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Sep 14 21:34:12 2003
 */
/* Compiler settings for C:\s_prjs\Data Rescuer\modules\UtFiles\UtFiles.idl:
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

const IID IID_IUt1 = {0x39C5D144,0xD3B0,0x488C,{0xB4,0x62,0x44,0xA1,0x15,0x6E,0x07,0x14}};


const IID LIBID_UtLib_Files = {0xC48F5E69,0x0159,0x4B83,{0xAA,0xB9,0x9B,0x8D,0xA0,0x7B,0x8D,0x0A}};


const CLSID CLSID_Ut1 = {0xFDB75471,0x8CFF,0x40F0,{0xA9,0x43,0x6B,0x35,0x02,0xE8,0x3A,0x70}};


#ifdef __cplusplus
}
#endif
