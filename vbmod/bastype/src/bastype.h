/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Feb 23 22:36:43 2006
 */
/* Compiler settings for C:\.lokaj\zbmis\module\bastype\src\bastype.idl:
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

#ifndef __bastype_h__
#define __bastype_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __IComparable_FWD_DEFINED__
#define __IComparable_FWD_DEFINED__
typedef interface IComparable IComparable;
#endif 	/* __IComparable_FWD_DEFINED__ */


#ifndef __IStringizable_FWD_DEFINED__
#define __IStringizable_FWD_DEFINED__
typedef interface IStringizable IStringizable;
#endif 	/* __IStringizable_FWD_DEFINED__ */


#ifndef __IList_FWD_DEFINED__
#define __IList_FWD_DEFINED__
typedef interface IList IList;
#endif 	/* __IList_FWD_DEFINED__ */


#ifndef __List_FWD_DEFINED__
#define __List_FWD_DEFINED__

#ifdef __cplusplus
typedef class List List;
#else
typedef struct List List;
#endif /* __cplusplus */

#endif 	/* __List_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );

#ifndef __IComparable_INTERFACE_DEFINED__
#define __IComparable_INTERFACE_DEFINED__

/* interface IComparable */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IComparable;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("3AD5FB90-8C80-461D-8F18-F65732FCED17")
    IComparable : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE compareTo(
            /* [in] */ VARIANT __RPC_FAR *rhs,
            /* [retval][out] */ int __RPC_FAR *result) = 0;

    };

#else 	/* C style interface */

    typedef struct IComparableVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IComparable __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IComparable __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IComparable __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IComparable __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IComparable __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IComparable __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IComparable __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *compareTo )(
            IComparable __RPC_FAR * This,
            /* [in] */ VARIANT __RPC_FAR *rhs,
            /* [retval][out] */ int __RPC_FAR *result);

        END_INTERFACE
    } IComparableVtbl;

    interface IComparable
    {
        CONST_VTBL struct IComparableVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IComparable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IComparable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IComparable_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IComparable_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IComparable_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IComparable_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IComparable_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IComparable_compareTo(This,rhs,result)	\
    (This)->lpVtbl -> compareTo(This,rhs,result)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IComparable_compareTo_Proxy(
    IComparable __RPC_FAR * This,
    /* [in] */ VARIANT __RPC_FAR *rhs,
    /* [retval][out] */ int __RPC_FAR *result);


void __RPC_STUB IComparable_compareTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IComparable_INTERFACE_DEFINED__ */


#ifndef __IStringizable_INTERFACE_DEFINED__
#define __IStringizable_INTERFACE_DEFINED__

/* interface IStringizable */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IStringizable;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("99A5A9D2-90B9-48A6-805F-2D14FED3238A")
    IStringizable : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE toString(
            /* [retval][out] */ BSTR __RPC_FAR *result) = 0;

    };

#else 	/* C style interface */

    typedef struct IStringizableVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IStringizable __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IStringizable __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IStringizable __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IStringizable __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IStringizable __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IStringizable __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IStringizable __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *toString )(
            IStringizable __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *result);

        END_INTERFACE
    } IStringizableVtbl;

    interface IStringizable
    {
        CONST_VTBL struct IStringizableVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IStringizable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IStringizable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IStringizable_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IStringizable_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IStringizable_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IStringizable_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IStringizable_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IStringizable_toString(This,result)	\
    (This)->lpVtbl -> toString(This,result)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IStringizable_toString_Proxy(
    IStringizable __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *result);


void __RPC_STUB IStringizable_toString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IStringizable_INTERFACE_DEFINED__ */


#ifndef __IList_INTERFACE_DEFINED__
#define __IList_INTERFACE_DEFINED__

/* interface IList */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IList;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("C5D3407B-D364-4328-BC1A-3C4CCA631DDA")
    IList : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_size(
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE push(
            /* [in] */ VARIANT __RPC_FAR *var) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE pop(
            /* [retval][out] */ VARIANT __RPC_FAR *var) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE unshift(
            /* [in] */ VARIANT __RPC_FAR *var) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE shift(
            /* [retval][out] */ VARIANT __RPC_FAR *var) = 0;

    };

#else 	/* C style interface */

    typedef struct IListVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IList __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IList __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IList __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IList __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IList __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IList __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IList __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_size )(
            IList __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *push )(
            IList __RPC_FAR * This,
            /* [in] */ VARIANT __RPC_FAR *var);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *pop )(
            IList __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *var);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *unshift )(
            IList __RPC_FAR * This,
            /* [in] */ VARIANT __RPC_FAR *var);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *shift )(
            IList __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *var);

        END_INTERFACE
    } IListVtbl;

    interface IList
    {
        CONST_VTBL struct IListVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IList_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IList_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IList_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IList_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IList_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IList_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IList_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IList_get_size(This,pVal)	\
    (This)->lpVtbl -> get_size(This,pVal)

#define IList_push(This,var)	\
    (This)->lpVtbl -> push(This,var)

#define IList_pop(This,var)	\
    (This)->lpVtbl -> pop(This,var)

#define IList_unshift(This,var)	\
    (This)->lpVtbl -> unshift(This,var)

#define IList_shift(This,var)	\
    (This)->lpVtbl -> shift(This,var)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IList_get_size_Proxy(
    IList __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IList_get_size_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IList_push_Proxy(
    IList __RPC_FAR * This,
    /* [in] */ VARIANT __RPC_FAR *var);


void __RPC_STUB IList_push_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IList_pop_Proxy(
    IList __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *var);


void __RPC_STUB IList_pop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IList_unshift_Proxy(
    IList __RPC_FAR * This,
    /* [in] */ VARIANT __RPC_FAR *var);


void __RPC_STUB IList_unshift_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IList_shift_Proxy(
    IList __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *var);


void __RPC_STUB IList_shift_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IList_INTERFACE_DEFINED__ */



#ifndef __BasTypeLib_LIBRARY_DEFINED__
#define __BasTypeLib_LIBRARY_DEFINED__

/* library BasTypeLib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_BasTypeLib;

EXTERN_C const CLSID CLSID_List;

#ifdef __cplusplus

class DECLSPEC_UUID("B4C78A36-6E54-4E66-A1E9-776E6BA8FB80")
List;
#endif
#endif /* __BasTypeLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * );
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * );

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long __RPC_FAR *, unsigned long            , VARIANT __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * );
void                      __RPC_USER  VARIANT_UserFree(     unsigned long __RPC_FAR *, VARIANT __RPC_FAR * );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
