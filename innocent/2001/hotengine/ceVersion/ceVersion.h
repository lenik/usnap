/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 02 22:21:11 2001
 */
/* Compiler settings for S:\lib\campoEngine\working\ceVersion\ceVersion.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __ceVersion_h__
#define __ceVersion_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __ICeVersion_FWD_DEFINED__
#define __ICeVersion_FWD_DEFINED__
typedef interface ICeVersion ICeVersion;
#endif 	/* __ICeVersion_FWD_DEFINED__ */


#ifndef __CeVersionSimple_FWD_DEFINED__
#define __CeVersionSimple_FWD_DEFINED__

#ifdef __cplusplus
typedef class CeVersionSimple CeVersionSimple;
#else
typedef struct CeVersionSimple CeVersionSimple;
#endif /* __cplusplus */

#endif 	/* __CeVersionSimple_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );


#ifndef __CeVersionLib_LIBRARY_DEFINED__
#define __CeVersionLib_LIBRARY_DEFINED__

/* library CeVersionLib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_CeVersionLib;

#ifndef __ICeVersion_INTERFACE_DEFINED__
#define __ICeVersion_INTERFACE_DEFINED__

/* interface ICeVersion */
/* [object][helpstring][uuid] */


EXTERN_C const IID IID_ICeVersion;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4345-0001-0001-486954656368")
    ICeVersion : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AboutBox( void) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetCurrentVersion(
            /* [retval][out] */ LONG __RPC_FAR *pVer) = 0;

    };

#else 	/* C style interface */

    typedef struct ICeVersionVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICeVersion __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICeVersion __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICeVersion __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AboutBox )(
            ICeVersion __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentVersion )(
            ICeVersion __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVer);

        END_INTERFACE
    } ICeVersionVtbl;

    interface ICeVersion
    {
        CONST_VTBL struct ICeVersionVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICeVersion_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICeVersion_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICeVersion_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICeVersion_AboutBox(This)	\
    (This)->lpVtbl -> AboutBox(This)

#define ICeVersion_GetCurrentVersion(This,pVer)	\
    (This)->lpVtbl -> GetCurrentVersion(This,pVer)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ICeVersion_AboutBox_Proxy(
    ICeVersion __RPC_FAR * This);


void __RPC_STUB ICeVersion_AboutBox_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICeVersion_GetCurrentVersion_Proxy(
    ICeVersion __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVer);


void __RPC_STUB ICeVersion_GetCurrentVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICeVersion_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CeVersionSimple;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4345-0001-0002-486954656368")
CeVersionSimple;
#endif
#endif /* __CeVersionLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
