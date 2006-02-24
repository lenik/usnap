/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Feb 24 17:21:13 2006
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


#ifndef __IIterator_FWD_DEFINED__
#define __IIterator_FWD_DEFINED__
typedef interface IIterator IIterator;
#endif 	/* __IIterator_FWD_DEFINED__ */


#ifndef __IList_FWD_DEFINED__
#define __IList_FWD_DEFINED__
typedef interface IList IList;
#endif 	/* __IList_FWD_DEFINED__ */


#ifndef __IVector_FWD_DEFINED__
#define __IVector_FWD_DEFINED__
typedef interface IVector IVector;
#endif 	/* __IVector_FWD_DEFINED__ */


#ifndef __Iterator_FWD_DEFINED__
#define __Iterator_FWD_DEFINED__

#ifdef __cplusplus
typedef class Iterator Iterator;
#else
typedef struct Iterator Iterator;
#endif /* __cplusplus */

#endif 	/* __Iterator_FWD_DEFINED__ */


#ifndef __List_FWD_DEFINED__
#define __List_FWD_DEFINED__

#ifdef __cplusplus
typedef class List List;
#else
typedef struct List List;
#endif /* __cplusplus */

#endif 	/* __List_FWD_DEFINED__ */


#ifndef __Vector_FWD_DEFINED__
#define __Vector_FWD_DEFINED__

#ifdef __cplusplus
typedef class Vector Vector;
#else
typedef struct Vector Vector;
#endif /* __cplusplus */

#endif 	/* __Vector_FWD_DEFINED__ */


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


#ifndef __IIterator_INTERFACE_DEFINED__
#define __IIterator_INTERFACE_DEFINED__

/* interface IIterator */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IIterator;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("9A64E934-FB27-4584-904D-2DFFD2D75565")
    IIterator : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE hasNext(
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *result) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE fetch(
            /* [retval][out] */ VARIANT __RPC_FAR *result) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE remove( void) = 0;

    };

#else 	/* C style interface */

    typedef struct IIteratorVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IIterator __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IIterator __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IIterator __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IIterator __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IIterator __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IIterator __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IIterator __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *hasNext )(
            IIterator __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *result);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *fetch )(
            IIterator __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *result);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *remove )(
            IIterator __RPC_FAR * This);

        END_INTERFACE
    } IIteratorVtbl;

    interface IIterator
    {
        CONST_VTBL struct IIteratorVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IIterator_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IIterator_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IIterator_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IIterator_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IIterator_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IIterator_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IIterator_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IIterator_hasNext(This,result)	\
    (This)->lpVtbl -> hasNext(This,result)

#define IIterator_fetch(This,result)	\
    (This)->lpVtbl -> fetch(This,result)

#define IIterator_remove(This)	\
    (This)->lpVtbl -> remove(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIterator_hasNext_Proxy(
    IIterator __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *result);


void __RPC_STUB IIterator_hasNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIterator_fetch_Proxy(
    IIterator __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *result);


void __RPC_STUB IIterator_fetch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIterator_remove_Proxy(
    IIterator __RPC_FAR * This);


void __RPC_STUB IIterator_remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IIterator_INTERFACE_DEFINED__ */


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

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE iterator(
            /* [retval][out] */ IIterator __RPC_FAR *__RPC_FAR *result) = 0;

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

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *iterator )(
            IList __RPC_FAR * This,
            /* [retval][out] */ IIterator __RPC_FAR *__RPC_FAR *result);

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

#define IList_iterator(This,result)	\
    (This)->lpVtbl -> iterator(This,result)

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


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IList_iterator_Proxy(
    IList __RPC_FAR * This,
    /* [retval][out] */ IIterator __RPC_FAR *__RPC_FAR *result);


void __RPC_STUB IList_iterator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IList_INTERFACE_DEFINED__ */


#ifndef __IVector_INTERFACE_DEFINED__
#define __IVector_INTERFACE_DEFINED__

/* interface IVector */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IVector;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("9583076E-91BC-4F21-8973-48EEF1BAF567")
    IVector : public IList
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_item(
            /* [in] */ long index,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;

        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_item(
            /* [in] */ long index,
            /* [in] */ VARIANT __RPC_FAR *newVal) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE insert(
            /* [in] */ long index,
            /* [in] */ VARIANT __RPC_FAR *var) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE remove(
            /* [in] */ long index) = 0;

    };

#else 	/* C style interface */

    typedef struct IVectorVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IVector __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IVector __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IVector __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IVector __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IVector __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IVector __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IVector __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_size )(
            IVector __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *push )(
            IVector __RPC_FAR * This,
            /* [in] */ VARIANT __RPC_FAR *var);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *pop )(
            IVector __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *var);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *unshift )(
            IVector __RPC_FAR * This,
            /* [in] */ VARIANT __RPC_FAR *var);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *shift )(
            IVector __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *var);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *iterator )(
            IVector __RPC_FAR * This,
            /* [retval][out] */ IIterator __RPC_FAR *__RPC_FAR *result);

        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_item )(
            IVector __RPC_FAR * This,
            /* [in] */ long index,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);

        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_item )(
            IVector __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ VARIANT __RPC_FAR *newVal);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *insert )(
            IVector __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ VARIANT __RPC_FAR *var);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *remove )(
            IVector __RPC_FAR * This,
            /* [in] */ long index);

        END_INTERFACE
    } IVectorVtbl;

    interface IVector
    {
        CONST_VTBL struct IVectorVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IVector_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVector_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVector_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVector_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IVector_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IVector_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IVector_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IVector_get_size(This,pVal)	\
    (This)->lpVtbl -> get_size(This,pVal)

#define IVector_push(This,var)	\
    (This)->lpVtbl -> push(This,var)

#define IVector_pop(This,var)	\
    (This)->lpVtbl -> pop(This,var)

#define IVector_unshift(This,var)	\
    (This)->lpVtbl -> unshift(This,var)

#define IVector_shift(This,var)	\
    (This)->lpVtbl -> shift(This,var)

#define IVector_iterator(This,result)	\
    (This)->lpVtbl -> iterator(This,result)


#define IVector_get_item(This,index,pVal)	\
    (This)->lpVtbl -> get_item(This,index,pVal)

#define IVector_put_item(This,index,newVal)	\
    (This)->lpVtbl -> put_item(This,index,newVal)

#define IVector_insert(This,index,var)	\
    (This)->lpVtbl -> insert(This,index,var)

#define IVector_remove(This,index)	\
    (This)->lpVtbl -> remove(This,index)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IVector_get_item_Proxy(
    IVector __RPC_FAR * This,
    /* [in] */ long index,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IVector_get_item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IVector_put_item_Proxy(
    IVector __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ VARIANT __RPC_FAR *newVal);


void __RPC_STUB IVector_put_item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_insert_Proxy(
    IVector __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ VARIANT __RPC_FAR *var);


void __RPC_STUB IVector_insert_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_remove_Proxy(
    IVector __RPC_FAR * This,
    /* [in] */ long index);


void __RPC_STUB IVector_remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVector_INTERFACE_DEFINED__ */



#ifndef __BasTypeLib_LIBRARY_DEFINED__
#define __BasTypeLib_LIBRARY_DEFINED__

/* library BasTypeLib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_BasTypeLib;

EXTERN_C const CLSID CLSID_Iterator;

#ifdef __cplusplus

class DECLSPEC_UUID("9F0FD3A4-6DC8-4F5E-A56E-1935D49EE840")
Iterator;
#endif

EXTERN_C const CLSID CLSID_List;

#ifdef __cplusplus

class DECLSPEC_UUID("B4C78A36-6E54-4E66-A1E9-776E6BA8FB80")
List;
#endif

EXTERN_C const CLSID CLSID_Vector;

#ifdef __cplusplus

class DECLSPEC_UUID("B0361D48-3618-4267-9FA5-90FF3849E5A2")
Vector;
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
