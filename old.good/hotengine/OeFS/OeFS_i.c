/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Apr 25 03:41:49 2001
 */
/* Compiler settings for S:\lib\oceanEngine\Working\OeSO\OeFS\OeFS.idl:
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

const IID IID_IOeFSDriver = {0x00000000,0x4F45,0x0F00,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeFSObject = {0x00000000,0x4F45,0x0F01,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeFSProxy = {0x00000000,0x4F45,0x0F02,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeFSDirectory = {0x00000000,0x4F45,0x0F10,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeFSFile = {0x00000000,0x4F45,0x0F11,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeFSLink = {0x00000000,0x4F45,0x0F12,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeFSTools = {0x00000000,0x4F45,0x0F20,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID LIBID_OeFSLib = {0x00000000,0x4F45,0x0F00,{0x00,0x04,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeFSDriver = {0x00000000,0x4F45,0x0F00,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeFSLocalDriver = {0x00000000,0x4F45,0x0F00,{0x01,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeFSNullDriver = {0x00000000,0x4F45,0x0F00,{0x02,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_IeFSObject = {0x00000000,0x4F45,0x0F01,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeFSProxy = {0x00000000,0x4F45,0x0F02,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeFSDirectory = {0x00000000,0x4F45,0x0F10,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeFSFile = {0x00000000,0x4F45,0x0F11,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeFSLink = {0x00000000,0x4F45,0x0F12,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeFSTools = {0x00000000,0x4F45,0x0F20,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


#ifdef __cplusplus
}
#endif
