/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 16 08:15:35 2001
 */
/* Compiler settings for V:\Components\Lab\TestCom\MultiLib\MultiLib.idl:
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

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __MultiLib_h__
#define __MultiLib_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __ICaMultiInt1_1_FWD_DEFINED__
#define __ICaMultiInt1_1_FWD_DEFINED__
typedef interface ICaMultiInt1_1 ICaMultiInt1_1;
#endif 	/* __ICaMultiInt1_1_FWD_DEFINED__ */


#ifndef __ICaMultiInt2_1_FWD_DEFINED__
#define __ICaMultiInt2_1_FWD_DEFINED__
typedef interface ICaMultiInt2_1 ICaMultiInt2_1;
#endif 	/* __ICaMultiInt2_1_FWD_DEFINED__ */


#ifndef __CaMultiInt1_FWD_DEFINED__
#define __CaMultiInt1_FWD_DEFINED__

#ifdef __cplusplus
typedef class CaMultiInt1 CaMultiInt1;
#else
typedef struct CaMultiInt1 CaMultiInt1;
#endif /* __cplusplus */

#endif 	/* __CaMultiInt1_FWD_DEFINED__ */


#ifndef __CaMultiInt2_FWD_DEFINED__
#define __CaMultiInt2_FWD_DEFINED__

#ifdef __cplusplus
typedef class CaMultiInt2 CaMultiInt2;
#else
typedef struct CaMultiInt2 CaMultiInt2;
#endif /* __cplusplus */

#endif 	/* __CaMultiInt2_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );

#ifndef __ICaMultiInt1_1_INTERFACE_DEFINED__
#define __ICaMultiInt1_1_INTERFACE_DEFINED__

/* interface ICaMultiInt1_1 */
/* [object][uuid] */


EXTERN_C const IID IID_ICaMultiInt1_1;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4341-FFF0-0001-486954656368")
    ICaMultiInt1_1 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AboutBox( void) = 0;

    };

#else 	/* C style interface */

    typedef struct ICaMultiInt1_1Vtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICaMultiInt1_1 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICaMultiInt1_1 __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICaMultiInt1_1 __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AboutBox )(
            ICaMultiInt1_1 __RPC_FAR * This);

        END_INTERFACE
    } ICaMultiInt1_1Vtbl;

    interface ICaMultiInt1_1
    {
        CONST_VTBL struct ICaMultiInt1_1Vtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICaMultiInt1_1_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICaMultiInt1_1_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICaMultiInt1_1_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICaMultiInt1_1_AboutBox(This)	\
    (This)->lpVtbl -> AboutBox(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ICaMultiInt1_1_AboutBox_Proxy(
    ICaMultiInt1_1 __RPC_FAR * This);


void __RPC_STUB ICaMultiInt1_1_AboutBox_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICaMultiInt1_1_INTERFACE_DEFINED__ */


#ifndef __ICaMultiInt2_1_INTERFACE_DEFINED__
#define __ICaMultiInt2_1_INTERFACE_DEFINED__

/* interface ICaMultiInt2_1 */
/* [object][uuid] */


EXTERN_C const IID IID_ICaMultiInt2_1;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4341-FFF1-0001-486954656368")
    ICaMultiInt2_1 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AboutBox( void) = 0;

    };

#else 	/* C style interface */

    typedef struct ICaMultiInt2_1Vtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICaMultiInt2_1 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICaMultiInt2_1 __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICaMultiInt2_1 __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AboutBox )(
            ICaMultiInt2_1 __RPC_FAR * This);

        END_INTERFACE
    } ICaMultiInt2_1Vtbl;

    interface ICaMultiInt2_1
    {
        CONST_VTBL struct ICaMultiInt2_1Vtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICaMultiInt2_1_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICaMultiInt2_1_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICaMultiInt2_1_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICaMultiInt2_1_AboutBox(This)	\
    (This)->lpVtbl -> AboutBox(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ICaMultiInt2_1_AboutBox_Proxy(
    ICaMultiInt2_1 __RPC_FAR * This);


void __RPC_STUB ICaMultiInt2_1_AboutBox_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICaMultiInt2_1_INTERFACE_DEFINED__ */



#ifndef __CaMultiIntLib_LIBRARY_DEFINED__
#define __CaMultiIntLib_LIBRARY_DEFINED__

/* library CaMultiIntLib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_CaMultiIntLib;

EXTERN_C const CLSID CLSID_CaMultiInt1;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4341-FFF0-0002-486954656368")
CaMultiInt1;
#endif

EXTERN_C const CLSID CLSID_CaMultiInt2;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4341-FFF1-0002-486954656368")
CaMultiInt2;
#endif
#endif /* __CaMultiIntLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
