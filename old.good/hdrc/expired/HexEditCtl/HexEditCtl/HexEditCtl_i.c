/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Jul 21 18:16:30 2003
 */
/* Compiler settings for D:\HexEditCtl\HexEditCtl\HexEditCtl.odl:
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

const IID LIBID_HEXEDITCTLLib = {0x25EF98CA,0x3581,0x4BD3,{0xB3,0xB9,0x27,0xA7,0xC2,0xA8,0x2F,0x11}};


const IID DIID__DHexEditCtl = {0x194FFE66,0xE6EC,0x47FE,{0x8A,0x71,0x7B,0x27,0x4C,0x0C,0x3A,0x7F}};


const IID DIID__DHexEditCtlEvents = {0xF2BFA29B,0xD63D,0x471E,{0xA3,0xC2,0x4A,0x3C,0x98,0xAF,0x57,0xFF}};


const CLSID CLSID_HexEditCtl = {0xB9208ED7,0x2CCF,0x479A,{0xAC,0xE7,0x12,0x07,0x1F,0x12,0xA9,0xBB}};


#ifdef __cplusplus
}
#endif
