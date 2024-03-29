/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue May 15 21:55:36 2001
 */
/* Compiler settings for S:\lib\oceanEngine\Working\OeSO\OeSO.idl:
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

const IID LIBID_OeSOLib = {0x00000000,0x4F45,0x0600,{0x00,0x04,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeSOParser = {0x00000000,0x4F45,0x0600,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID DIID_IOeSOParserEvents = {0x00000000,0x4F45,0x0600,{0x00,0x17,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeSOCompiler = {0x00000000,0x4F45,0x0601,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeSOEvaluator = {0x00000000,0x4F45,0x0602,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeSOObject = {0x00000000,0x4F45,0x0610,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeSOInterface = {0x00000000,0x4F45,0x0611,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeSOClass = {0x00000000,0x4F45,0x0612,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeSOStatus = {0x00000000,0x4F45,0x0613,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeSOAttribute = {0x00000000,0x4F45,0x0620,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID DIID_IOeSOAttributeEvents = {0x00000000,0x4F45,0x0620,{0x00,0x17,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeSOMethod = {0x00000000,0x4F45,0x0621,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeSOEvent = {0x00000000,0x4F45,0x0622,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeSOCollection = {0x00000000,0x4F45,0x0630,{0x00,0x81,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeSOObjectsCollection = {0x00000000,0x4F45,0x0630,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeSOInterfacesCollection = {0x00000000,0x4F45,0x0631,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeSOClassesCollection = {0x00000000,0x4F45,0x0632,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeSOStatusesCollection = {0x00000000,0x4F45,0x0633,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeSOAttributesCollection = {0x00000000,0x4F45,0x0640,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeSOMethodsCollection = {0x00000000,0x4F45,0x0641,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeSOEventsCollection = {0x00000000,0x4F45,0x0642,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeSOApplication = {0x00000000,0x4F45,0x0660,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeSOParser = {0x00000000,0x4F45,0x0600,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeSOCompiler = {0x00000000,0x4F45,0x0601,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeSOEvaluator = {0x00000000,0x4F45,0x0602,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeSOObject = {0x00000000,0x4F45,0x0610,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeSOInterface = {0x00000000,0x4F45,0x0611,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeSOClass = {0x00000000,0x4F45,0x0612,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeSOStatus = {0x00000000,0x4F45,0x0613,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeSOAttribute = {0x00000000,0x4F45,0x0620,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeSOMethod = {0x00000000,0x4F45,0x0621,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeSOEvent = {0x00000000,0x4F45,0x0622,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeSOCollection = {0x00000000,0x4F45,0x0630,{0x80,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeSOObjectsCollection = {0x00000000,0x4F45,0x0630,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeSOInterfacesCollection = {0x00000000,0x4F45,0x0631,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeSOClassesCollection = {0x00000000,0x4F45,0x0632,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeSOAttributesCollection = {0x00000000,0x4F45,0x0640,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeSOStatusesCollection = {0x00000000,0x4F45,0x0633,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeSOMethodsCollection = {0x00000000,0x4F45,0x0641,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeSOEventsCollection = {0x00000000,0x4F45,0x0642,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeSOApplication = {0x00000000,0x4F45,0x0660,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


#ifdef __cplusplus
}
#endif
