/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Jul 28 20:52:51 2003
 */
/* Compiler settings for C:\s_prjs\Data Rescuer\modules\HexEditCtl\cat\cat.idl:
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

const IID IID_ICat002 = {0x406C16E3,0xF287,0x410C,{0xB8,0xF9,0xB3,0xC9,0xE0,0x91,0xD2,0x54}};


const IID LIBID_CATLib = {0x0F986A37,0x84AB,0x4B4E,{0xBE,0x26,0xD1,0x8C,0xBE,0xF1,0x30,0x4B}};


const CLSID CLSID_Cat002 = {0x2D21A1FB,0x35CD,0x4AC2,{0x81,0xCC,0x4C,0x2C,0x0D,0xA6,0x0B,0x16}};


const CLSID CLSID_CatPropPage = {0x3F4FA292,0x0594,0x4EF6,{0x81,0x9A,0x12,0xB1,0x67,0xC7,0xFE,0x8D}};


#ifdef __cplusplus
}
#endif
