/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Apr 18 02:21:29 2001
 */
/* Compiler settings for V:\Components\CampoAccelerate\EasyDialog\EasyDialog.idl:
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

const IID IID_ICaEDSmalls = {0x00000000,0x4341,0x1000,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_ICaEDViewer = {0x00000000,0x4341,0x1001,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID LIBID_CaEasyDialogLib = {0x00000000,0x4341,0x1000,{0x00,0x04,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_CaEDSmalls = {0x00000000,0x4341,0x1000,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_CaEDViewer = {0x00000000,0x4341,0x1001,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


#ifdef __cplusplus
}
#endif
