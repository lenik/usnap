/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Jul 28 21:47:18 2003
 */
/* Compiler settings for C:\s_prjs\Data Rescuer\modules\HexEditCtl\HexEdit\HexEdit.idl:
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

const IID IID_IHexEditCtl = {0x7D05FFFF,0x4764,0x4EAC,{0x93,0x80,0xC5,0x57,0x05,0x4F,0x54,0x42}};


const IID LIBID_HEXEDITLib = {0x5BF38F30,0xAFF3,0x48BF,{0x9B,0x2E,0x8C,0x18,0x82,0x72,0x9A,0xDC}};


const IID DIID__IHexEditCtlEvents = {0x30A34A3A,0xBB27,0x4E67,{0xB9,0x9E,0x23,0x7A,0xE4,0x3F,0x09,0xE0}};


const CLSID CLSID_HexEditCtl = {0xC9971570,0x4D04,0x48F5,{0xA3,0xE4,0x5C,0x2A,0xD6,0xE8,0x55,0x84}};


#ifdef __cplusplus
}
#endif
