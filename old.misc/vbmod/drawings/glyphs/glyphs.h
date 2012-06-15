/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Apr 19 14:27:09 2006
 */
/* Compiler settings for .\glyphs.idl:
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

#ifndef __glyphs_h__
#define __glyphs_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __ILines_FWD_DEFINED__
#define __ILines_FWD_DEFINED__
typedef interface ILines ILines;
#endif 	/* __ILines_FWD_DEFINED__ */


#ifndef __IShapes_FWD_DEFINED__
#define __IShapes_FWD_DEFINED__
typedef interface IShapes IShapes;
#endif 	/* __IShapes_FWD_DEFINED__ */


#ifndef __Lines_FWD_DEFINED__
#define __Lines_FWD_DEFINED__

#ifdef __cplusplus
typedef class Lines Lines;
#else
typedef struct Lines Lines;
#endif /* __cplusplus */

#endif 	/* __Lines_FWD_DEFINED__ */


#ifndef __Shapes_FWD_DEFINED__
#define __Shapes_FWD_DEFINED__

#ifdef __cplusplus
typedef class Shapes Shapes;
#else
typedef struct Shapes Shapes;
#endif /* __cplusplus */

#endif 	/* __Shapes_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );

#ifndef __ILines_INTERFACE_DEFINED__
#define __ILines_INTERFACE_DEFINED__

/* interface ILines */
/* [unique][helpstring][dual][uuid][object] */

typedef
enum ArrowTypeConstants
    {	arrowNormal	= 0,
	arrowNormalDbl	= arrowNormal + 1,
	arrowSharp	= arrowNormalDbl + 1,
	arrowSharpDbl	= arrowSharp + 1,
	arrowDiamond	= arrowSharpDbl + 1
    }	ArrowTypeConstants;


EXTERN_C const IID IID_ILines;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("D0B0E3AC-E38C-4C94-B01A-B7BEF0D92A46")
    ILines : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Arrow(
            /* [in] */ long hDC,
            /* [in] */ ArrowTypeConstants type,
            /* [in] */ long x0,
            /* [in] */ long y0,
            /* [in] */ long x1,
            /* [in] */ long y1) = 0;

    };

#else 	/* C style interface */

    typedef struct ILinesVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ILines __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ILines __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ILines __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ILines __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ILines __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ILines __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ILines __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Arrow )(
            ILines __RPC_FAR * This,
            /* [in] */ long hDC,
            /* [in] */ ArrowTypeConstants type,
            /* [in] */ long x0,
            /* [in] */ long y0,
            /* [in] */ long x1,
            /* [in] */ long y1);

        END_INTERFACE
    } ILinesVtbl;

    interface ILines
    {
        CONST_VTBL struct ILinesVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ILines_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ILines_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ILines_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ILines_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ILines_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ILines_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ILines_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ILines_Arrow(This,hDC,type,x0,y0,x1,y1)	\
    (This)->lpVtbl -> Arrow(This,hDC,type,x0,y0,x1,y1)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILines_Arrow_Proxy(
    ILines __RPC_FAR * This,
    /* [in] */ long hDC,
    /* [in] */ ArrowTypeConstants type,
    /* [in] */ long x0,
    /* [in] */ long y0,
    /* [in] */ long x1,
    /* [in] */ long y1);


void __RPC_STUB ILines_Arrow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ILines_INTERFACE_DEFINED__ */


#ifndef __IShapes_INTERFACE_DEFINED__
#define __IShapes_INTERFACE_DEFINED__

/* interface IShapes */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IShapes;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("E3430624-662E-41E1-B35C-ED33F43C5F61")
    IShapes : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Lines(
            /* [retval][out] */ ILines __RPC_FAR *__RPC_FAR *pVal) = 0;

    };

#else 	/* C style interface */

    typedef struct IShapesVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IShapes __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IShapes __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IShapes __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IShapes __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IShapes __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IShapes __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IShapes __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Lines )(
            IShapes __RPC_FAR * This,
            /* [retval][out] */ ILines __RPC_FAR *__RPC_FAR *pVal);

        END_INTERFACE
    } IShapesVtbl;

    interface IShapes
    {
        CONST_VTBL struct IShapesVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IShapes_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IShapes_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IShapes_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IShapes_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IShapes_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IShapes_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IShapes_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IShapes_get_Lines(This,pVal)	\
    (This)->lpVtbl -> get_Lines(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IShapes_get_Lines_Proxy(
    IShapes __RPC_FAR * This,
    /* [retval][out] */ ILines __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IShapes_get_Lines_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IShapes_INTERFACE_DEFINED__ */



#ifndef __GlyphsLib_LIBRARY_DEFINED__
#define __GlyphsLib_LIBRARY_DEFINED__

/* library GlyphsLib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_GlyphsLib;

EXTERN_C const CLSID CLSID_Lines;

#ifdef __cplusplus

class DECLSPEC_UUID("61901D17-346A-48A1-ACAF-BF67DF638749")
Lines;
#endif

EXTERN_C const CLSID CLSID_Shapes;

#ifdef __cplusplus

class DECLSPEC_UUID("03505851-D307-4160-9A6F-F1B7CBEB4288")
Shapes;
#endif
#endif /* __GlyphsLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
