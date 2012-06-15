/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Apr 18 02:21:29 2001
 */
/* Compiler settings for V:\Components\CampoAccelerate\EasyDialog\EasyDialog.idl:
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

#ifndef __EasyDialog_h__
#define __EasyDialog_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __ICaEDSmalls_FWD_DEFINED__
#define __ICaEDSmalls_FWD_DEFINED__
typedef interface ICaEDSmalls ICaEDSmalls;
#endif 	/* __ICaEDSmalls_FWD_DEFINED__ */


#ifndef __ICaEDViewer_FWD_DEFINED__
#define __ICaEDViewer_FWD_DEFINED__
typedef interface ICaEDViewer ICaEDViewer;
#endif 	/* __ICaEDViewer_FWD_DEFINED__ */


#ifndef __CaEDSmalls_FWD_DEFINED__
#define __CaEDSmalls_FWD_DEFINED__

#ifdef __cplusplus
typedef class CaEDSmalls CaEDSmalls;
#else
typedef struct CaEDSmalls CaEDSmalls;
#endif /* __cplusplus */

#endif 	/* __CaEDSmalls_FWD_DEFINED__ */


#ifndef __CaEDViewer_FWD_DEFINED__
#define __CaEDViewer_FWD_DEFINED__

#ifdef __cplusplus
typedef class CaEDViewer CaEDViewer;
#else
typedef struct CaEDViewer CaEDViewer;
#endif /* __cplusplus */

#endif 	/* __CaEDViewer_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );

#ifndef __ICaEDSmalls_INTERFACE_DEFINED__
#define __ICaEDSmalls_INTERFACE_DEFINED__

/* interface ICaEDSmalls */
/* [object][helpstring][uuid] */


EXTERN_C const IID IID_ICaEDSmalls;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4341-1000-0001-486954656368")
    ICaEDSmalls : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DoPrompt(
            /* [retval][out] */ int __RPC_FAR *ret) = 0;

    };

#else 	/* C style interface */

    typedef struct ICaEDSmallsVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICaEDSmalls __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICaEDSmalls __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICaEDSmalls __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoPrompt )(
            ICaEDSmalls __RPC_FAR * This,
            /* [retval][out] */ int __RPC_FAR *ret);

        END_INTERFACE
    } ICaEDSmallsVtbl;

    interface ICaEDSmalls
    {
        CONST_VTBL struct ICaEDSmallsVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICaEDSmalls_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICaEDSmalls_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICaEDSmalls_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICaEDSmalls_DoPrompt(This,ret)	\
    (This)->lpVtbl -> DoPrompt(This,ret)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ICaEDSmalls_DoPrompt_Proxy(
    ICaEDSmalls __RPC_FAR * This,
    /* [retval][out] */ int __RPC_FAR *ret);


void __RPC_STUB ICaEDSmalls_DoPrompt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICaEDSmalls_INTERFACE_DEFINED__ */


#ifndef __ICaEDViewer_INTERFACE_DEFINED__
#define __ICaEDViewer_INTERFACE_DEFINED__

/* interface ICaEDViewer */
/* [object][helpstring][uuid] */


EXTERN_C const IID IID_ICaEDViewer;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4341-1001-0001-486954656368")
    ICaEDViewer : public IUnknown
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Html(
            /* [retval][out] */ BSTR __RPC_FAR *ret) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Html(
            /* [in] */ BSTR __RPC_FAR *htmlcode) = 0;

        virtual HRESULT STDMETHODCALLTYPE DoModal(
            /* [retval][out] */ int __RPC_FAR *ret) = 0;

    };

#else 	/* C style interface */

    typedef struct ICaEDViewerVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICaEDViewer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICaEDViewer __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICaEDViewer __RPC_FAR * This);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Html )(
            ICaEDViewer __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *ret);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Html )(
            ICaEDViewer __RPC_FAR * This,
            /* [in] */ BSTR __RPC_FAR *htmlcode);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoModal )(
            ICaEDViewer __RPC_FAR * This,
            /* [retval][out] */ int __RPC_FAR *ret);

        END_INTERFACE
    } ICaEDViewerVtbl;

    interface ICaEDViewer
    {
        CONST_VTBL struct ICaEDViewerVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICaEDViewer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICaEDViewer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICaEDViewer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICaEDViewer_get_Html(This,ret)	\
    (This)->lpVtbl -> get_Html(This,ret)

#define ICaEDViewer_put_Html(This,htmlcode)	\
    (This)->lpVtbl -> put_Html(This,htmlcode)

#define ICaEDViewer_DoModal(This,ret)	\
    (This)->lpVtbl -> DoModal(This,ret)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICaEDViewer_get_Html_Proxy(
    ICaEDViewer __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *ret);


void __RPC_STUB ICaEDViewer_get_Html_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE ICaEDViewer_put_Html_Proxy(
    ICaEDViewer __RPC_FAR * This,
    /* [in] */ BSTR __RPC_FAR *htmlcode);


void __RPC_STUB ICaEDViewer_put_Html_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICaEDViewer_DoModal_Proxy(
    ICaEDViewer __RPC_FAR * This,
    /* [retval][out] */ int __RPC_FAR *ret);


void __RPC_STUB ICaEDViewer_DoModal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICaEDViewer_INTERFACE_DEFINED__ */



#ifndef __CaEasyDialogLib_LIBRARY_DEFINED__
#define __CaEasyDialogLib_LIBRARY_DEFINED__

/* library CaEasyDialogLib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_CaEasyDialogLib;

EXTERN_C const CLSID CLSID_CaEDSmalls;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4341-1000-0002-486954656368")
CaEDSmalls;
#endif

EXTERN_C const CLSID CLSID_CaEDViewer;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4341-1001-0002-486954656368")
CaEDViewer;
#endif
#endif /* __CaEasyDialogLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * );
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
