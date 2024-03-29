/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Mar 02 18:47:29 2006
 */
/* Compiler settings for C:\.lokaj\zbmis\module\dbproxy\mapping\mapping.idl:
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

const IID LIBID_ADOMapping = {0x487159B4,0x4EA2,0x48A0,{0xAA,0x60,0xDE,0x05,0xCB,0x29,0x83,0xDC}};


const IID IID_IConnection = {0x7BA7DF7A,0xD03B,0x4147,{0xA3,0xA6,0x94,0xBA,0x9E,0xB8,0xE4,0xA5}};


const IID IID_IRecordset = {0xC26EE01B,0xC5F7,0x44A5,{0x95,0x51,0x66,0xBD,0xCD,0x79,0x63,0xCD}};


const IID IID_ICommand = {0xA0FA3E07,0xF428,0x490E,{0x81,0x4D,0x11,0x74,0xF3,0x94,0x63,0x51}};


const IID IID_IConnectionAdapter = {0xBF6957E5,0x4714,0x4DF5,{0x89,0xE6,0xB5,0x05,0x40,0x88,0x7E,0x9D}};


const IID IID_ICommandAdapter = {0x8E77C00C,0x0CF0,0x4962,{0x83,0x02,0xF1,0xD1,0xF9,0x65,0x98,0x19}};


const IID IID_IRecordsetAdapter = {0x34C365DA,0x3190,0x403C,{0xB9,0xDA,0x57,0xF2,0x87,0x3C,0xCA,0x0C}};


const IID IID_IGlobals = {0x1D0FD8E1,0xB2B6,0x477F,{0xA4,0x77,0x97,0x61,0x87,0x8C,0x2E,0x7A}};


const CLSID CLSID_ConnectionAdapter = {0x57AF83EC,0xE40D,0x484A,{0x97,0xFB,0xF9,0xA8,0x20,0x72,0x02,0xD5}};


const CLSID CLSID_CommandAdapter = {0x9674967D,0x95EF,0x40ED,{0xBB,0x73,0x1A,0xF1,0x50,0x6D,0x51,0xCF}};


const CLSID CLSID_RecordsetAdapter = {0x13534E37,0x13D6,0x4438,{0x8B,0x79,0x83,0x0C,0x3D,0x80,0x0E,0x88}};


const CLSID CLSID_Globals = {0xE58DE534,0x6E51,0x45BF,{0xAD,0x8C,0x7E,0x02,0xC0,0x9B,0x27,0x58}};


#ifdef __cplusplus
}
#endif
