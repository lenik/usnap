/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Feb 23 16:33:49 2006
 */
/* Compiler settings for C:\.lokaj\zbmis\module\drawings\glyphs\glyphs.idl:
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

const IID IID_ILines = {0xD0B0E3AC,0xE38C,0x4C94,{0xB0,0x1A,0xB7,0xBE,0xF0,0xD9,0x2A,0x46}};


const IID IID_IShapes = {0xE3430624,0x662E,0x41E1,{0xB3,0x5C,0xED,0x33,0xF4,0x3C,0x5F,0x61}};


const IID LIBID_GlyphsLib = {0x4C3F115E,0xAF2C,0x4FEC,{0x9D,0x69,0xF8,0xE9,0x72,0x45,0xF9,0x48}};


const CLSID CLSID_Lines = {0x61901D17,0x346A,0x48A1,{0xAC,0xAF,0xBF,0x67,0xDF,0x63,0x87,0x49}};


const CLSID CLSID_Shapes = {0x03505851,0xD307,0x4160,{0x9A,0x6F,0xF1,0xB7,0xCB,0xEB,0x42,0x88}};


#ifdef __cplusplus
}
#endif
