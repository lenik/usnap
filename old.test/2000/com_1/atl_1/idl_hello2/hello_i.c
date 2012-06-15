/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Mar 28 18:24:18 2001
 */
/* Compiler settings for V:\temp\atl01\idl_hello\hello.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
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

const IID IID_IHello = {0x00000000,0x1200,0x0001,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}};


const CLSID CLSID_Hello1 = {0x00000000,0x1200,0x0001,{0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00}};


#ifdef __cplusplus
}
#endif
