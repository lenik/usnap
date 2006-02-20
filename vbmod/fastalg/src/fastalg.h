/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Feb 20 21:09:26 2006
 */
/* Compiler settings for C:\.lokaj\zbmis\module\fastalg\src\fastalg.idl:
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

#ifndef __fastalg_h__
#define __fastalg_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __ISAOT_FWD_DEFINED__
#define __ISAOT_FWD_DEFINED__
typedef interface ISAOT ISAOT;
#endif 	/* __ISAOT_FWD_DEFINED__ */


#ifndef __IDRIA_FWD_DEFINED__
#define __IDRIA_FWD_DEFINED__
typedef interface IDRIA IDRIA;
#endif 	/* __IDRIA_FWD_DEFINED__ */


#ifndef __SAOT_FWD_DEFINED__
#define __SAOT_FWD_DEFINED__

#ifdef __cplusplus
typedef class SAOT SAOT;
#else
typedef struct SAOT SAOT;
#endif /* __cplusplus */

#endif 	/* __SAOT_FWD_DEFINED__ */


#ifndef __DRIA_FWD_DEFINED__
#define __DRIA_FWD_DEFINED__

#ifdef __cplusplus
typedef class DRIA DRIA;
#else
typedef struct DRIA DRIA;
#endif /* __cplusplus */

#endif 	/* __DRIA_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );

#ifndef __ISAOT_INTERFACE_DEFINED__
#define __ISAOT_INTERFACE_DEFINED__

/* interface ISAOT */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_ISAOT;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("AECAFF4C-5D51-483A-8619-E80511E69439")
    ISAOT : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SlotAllocated(
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;

        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Size(
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SlotAdd(
            /* [retval][out] */ long __RPC_FAR *result) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SlotRemove(
            /* [in] */ long Slot) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SlotClear( void) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Insert(
            /* [in] */ long Index,
            /* [retval][out] */ long __RPC_FAR *result) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove(
            /* [in] */ long Index,
            /* [retval][out] */ long __RPC_FAR *result) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindSlot(
            /* [in] */ long Slot,
            /* [retval][out] */ long __RPC_FAR *result) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindIndex(
            /* [in] */ long Index,
            /* [retval][out] */ long __RPC_FAR *result) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SortSlots(
            /* [retval][out] */ VARIANT __RPC_FAR *SortedSlots) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Append(
            /* [in] */ long count,
            /* [retval][out] */ long __RPC_FAR *result) = 0;

    };

#else 	/* C style interface */

    typedef struct ISAOTVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ISAOT __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ISAOT __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ISAOT __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ISAOT __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ISAOT __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ISAOT __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ISAOT __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SlotAllocated )(
            ISAOT __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);

        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Size )(
            ISAOT __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SlotAdd )(
            ISAOT __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *result);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SlotRemove )(
            ISAOT __RPC_FAR * This,
            /* [in] */ long Slot);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SlotClear )(
            ISAOT __RPC_FAR * This);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Insert )(
            ISAOT __RPC_FAR * This,
            /* [in] */ long Index,
            /* [retval][out] */ long __RPC_FAR *result);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove )(
            ISAOT __RPC_FAR * This,
            /* [in] */ long Index,
            /* [retval][out] */ long __RPC_FAR *result);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindSlot )(
            ISAOT __RPC_FAR * This,
            /* [in] */ long Slot,
            /* [retval][out] */ long __RPC_FAR *result);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindIndex )(
            ISAOT __RPC_FAR * This,
            /* [in] */ long Index,
            /* [retval][out] */ long __RPC_FAR *result);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SortSlots )(
            ISAOT __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *SortedSlots);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Append )(
            ISAOT __RPC_FAR * This,
            /* [in] */ long count,
            /* [retval][out] */ long __RPC_FAR *result);

        END_INTERFACE
    } ISAOTVtbl;

    interface ISAOT
    {
        CONST_VTBL struct ISAOTVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ISAOT_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAOT_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAOT_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAOT_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISAOT_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISAOT_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISAOT_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISAOT_get_SlotAllocated(This,pVal)	\
    (This)->lpVtbl -> get_SlotAllocated(This,pVal)

#define ISAOT_get_Size(This,pVal)	\
    (This)->lpVtbl -> get_Size(This,pVal)

#define ISAOT_SlotAdd(This,result)	\
    (This)->lpVtbl -> SlotAdd(This,result)

#define ISAOT_SlotRemove(This,Slot)	\
    (This)->lpVtbl -> SlotRemove(This,Slot)

#define ISAOT_SlotClear(This)	\
    (This)->lpVtbl -> SlotClear(This)

#define ISAOT_Insert(This,Index,result)	\
    (This)->lpVtbl -> Insert(This,Index,result)

#define ISAOT_Remove(This,Index,result)	\
    (This)->lpVtbl -> Remove(This,Index,result)

#define ISAOT_FindSlot(This,Slot,result)	\
    (This)->lpVtbl -> FindSlot(This,Slot,result)

#define ISAOT_FindIndex(This,Index,result)	\
    (This)->lpVtbl -> FindIndex(This,Index,result)

#define ISAOT_SortSlots(This,SortedSlots)	\
    (This)->lpVtbl -> SortSlots(This,SortedSlots)

#define ISAOT_Append(This,count,result)	\
    (This)->lpVtbl -> Append(This,count,result)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISAOT_get_SlotAllocated_Proxy(
    ISAOT __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ISAOT_get_SlotAllocated_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISAOT_get_Size_Proxy(
    ISAOT __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ISAOT_get_Size_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAOT_SlotAdd_Proxy(
    ISAOT __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *result);


void __RPC_STUB ISAOT_SlotAdd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAOT_SlotRemove_Proxy(
    ISAOT __RPC_FAR * This,
    /* [in] */ long Slot);


void __RPC_STUB ISAOT_SlotRemove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAOT_SlotClear_Proxy(
    ISAOT __RPC_FAR * This);


void __RPC_STUB ISAOT_SlotClear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAOT_Insert_Proxy(
    ISAOT __RPC_FAR * This,
    /* [in] */ long Index,
    /* [retval][out] */ long __RPC_FAR *result);


void __RPC_STUB ISAOT_Insert_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAOT_Remove_Proxy(
    ISAOT __RPC_FAR * This,
    /* [in] */ long Index,
    /* [retval][out] */ long __RPC_FAR *result);


void __RPC_STUB ISAOT_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAOT_FindSlot_Proxy(
    ISAOT __RPC_FAR * This,
    /* [in] */ long Slot,
    /* [retval][out] */ long __RPC_FAR *result);


void __RPC_STUB ISAOT_FindSlot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAOT_FindIndex_Proxy(
    ISAOT __RPC_FAR * This,
    /* [in] */ long Index,
    /* [retval][out] */ long __RPC_FAR *result);


void __RPC_STUB ISAOT_FindIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAOT_SortSlots_Proxy(
    ISAOT __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *SortedSlots);


void __RPC_STUB ISAOT_SortSlots_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAOT_Append_Proxy(
    ISAOT __RPC_FAR * This,
    /* [in] */ long count,
    /* [retval][out] */ long __RPC_FAR *result);


void __RPC_STUB ISAOT_Append_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAOT_INTERFACE_DEFINED__ */


#ifndef __IDRIA_INTERFACE_DEFINED__
#define __IDRIA_INTERFACE_DEFINED__

/* interface IDRIA */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IDRIA;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("604D4559-902D-4066-B1FA-81F692610519")
    IDRIA : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Ceil(
            /* [in] */ long x,
            /* [retval][out] */ int __RPC_FAR *retval) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Floor(
            /* [in] */ long x,
            /* [retval][out] */ int __RPC_FAR *retval) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddRange(
            /* [in] */ long lower,
            /* [in] */ long upper,
            /* [retval][out] */ BOOL __RPC_FAR *retval) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveRange(
            /* [in] */ long lower,
            /* [in] */ long upper,
            /* [retval][out] */ BOOL __RPC_FAR *retval) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add(
            /* [in] */ long x,
            /* [retval][out] */ BOOL __RPC_FAR *retval) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove(
            /* [in] */ long x,
            /* [retval][out] */ BOOL __RPC_FAR *retval) = 0;

        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count(
            /* [retval][out] */ int __RPC_FAR *pVal) = 0;

        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RangeLower(
            /* [in] */ int index,
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;

        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RangeUpper(
            /* [in] */ int index,
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;

    };

#else 	/* C style interface */

    typedef struct IDRIAVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IDRIA __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IDRIA __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IDRIA __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IDRIA __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IDRIA __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IDRIA __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IDRIA __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clear )(
            IDRIA __RPC_FAR * This);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Ceil )(
            IDRIA __RPC_FAR * This,
            /* [in] */ long x,
            /* [retval][out] */ int __RPC_FAR *retval);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Floor )(
            IDRIA __RPC_FAR * This,
            /* [in] */ long x,
            /* [retval][out] */ int __RPC_FAR *retval);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddRange )(
            IDRIA __RPC_FAR * This,
            /* [in] */ long lower,
            /* [in] */ long upper,
            /* [retval][out] */ BOOL __RPC_FAR *retval);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveRange )(
            IDRIA __RPC_FAR * This,
            /* [in] */ long lower,
            /* [in] */ long upper,
            /* [retval][out] */ BOOL __RPC_FAR *retval);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )(
            IDRIA __RPC_FAR * This,
            /* [in] */ long x,
            /* [retval][out] */ BOOL __RPC_FAR *retval);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove )(
            IDRIA __RPC_FAR * This,
            /* [in] */ long x,
            /* [retval][out] */ BOOL __RPC_FAR *retval);

        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )(
            IDRIA __RPC_FAR * This,
            /* [retval][out] */ int __RPC_FAR *pVal);

        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RangeLower )(
            IDRIA __RPC_FAR * This,
            /* [in] */ int index,
            /* [retval][out] */ long __RPC_FAR *pVal);

        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RangeUpper )(
            IDRIA __RPC_FAR * This,
            /* [in] */ int index,
            /* [retval][out] */ long __RPC_FAR *pVal);

        END_INTERFACE
    } IDRIAVtbl;

    interface IDRIA
    {
        CONST_VTBL struct IDRIAVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IDRIA_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDRIA_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDRIA_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDRIA_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDRIA_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDRIA_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDRIA_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDRIA_Clear(This)	\
    (This)->lpVtbl -> Clear(This)

#define IDRIA_Ceil(This,x,retval)	\
    (This)->lpVtbl -> Ceil(This,x,retval)

#define IDRIA_Floor(This,x,retval)	\
    (This)->lpVtbl -> Floor(This,x,retval)

#define IDRIA_AddRange(This,lower,upper,retval)	\
    (This)->lpVtbl -> AddRange(This,lower,upper,retval)

#define IDRIA_RemoveRange(This,lower,upper,retval)	\
    (This)->lpVtbl -> RemoveRange(This,lower,upper,retval)

#define IDRIA_Add(This,x,retval)	\
    (This)->lpVtbl -> Add(This,x,retval)

#define IDRIA_Remove(This,x,retval)	\
    (This)->lpVtbl -> Remove(This,x,retval)

#define IDRIA_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#define IDRIA_get_RangeLower(This,index,pVal)	\
    (This)->lpVtbl -> get_RangeLower(This,index,pVal)

#define IDRIA_get_RangeUpper(This,index,pVal)	\
    (This)->lpVtbl -> get_RangeUpper(This,index,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDRIA_Clear_Proxy(
    IDRIA __RPC_FAR * This);


void __RPC_STUB IDRIA_Clear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDRIA_Ceil_Proxy(
    IDRIA __RPC_FAR * This,
    /* [in] */ long x,
    /* [retval][out] */ int __RPC_FAR *retval);


void __RPC_STUB IDRIA_Ceil_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDRIA_Floor_Proxy(
    IDRIA __RPC_FAR * This,
    /* [in] */ long x,
    /* [retval][out] */ int __RPC_FAR *retval);


void __RPC_STUB IDRIA_Floor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDRIA_AddRange_Proxy(
    IDRIA __RPC_FAR * This,
    /* [in] */ long lower,
    /* [in] */ long upper,
    /* [retval][out] */ BOOL __RPC_FAR *retval);


void __RPC_STUB IDRIA_AddRange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDRIA_RemoveRange_Proxy(
    IDRIA __RPC_FAR * This,
    /* [in] */ long lower,
    /* [in] */ long upper,
    /* [retval][out] */ BOOL __RPC_FAR *retval);


void __RPC_STUB IDRIA_RemoveRange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDRIA_Add_Proxy(
    IDRIA __RPC_FAR * This,
    /* [in] */ long x,
    /* [retval][out] */ BOOL __RPC_FAR *retval);


void __RPC_STUB IDRIA_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDRIA_Remove_Proxy(
    IDRIA __RPC_FAR * This,
    /* [in] */ long x,
    /* [retval][out] */ BOOL __RPC_FAR *retval);


void __RPC_STUB IDRIA_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDRIA_get_Count_Proxy(
    IDRIA __RPC_FAR * This,
    /* [retval][out] */ int __RPC_FAR *pVal);


void __RPC_STUB IDRIA_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDRIA_get_RangeLower_Proxy(
    IDRIA __RPC_FAR * This,
    /* [in] */ int index,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IDRIA_get_RangeLower_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDRIA_get_RangeUpper_Proxy(
    IDRIA __RPC_FAR * This,
    /* [in] */ int index,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IDRIA_get_RangeUpper_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDRIA_INTERFACE_DEFINED__ */



#ifndef __FastAlgLib_LIBRARY_DEFINED__
#define __FastAlgLib_LIBRARY_DEFINED__

/* library FastAlgLib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_FastAlgLib;

EXTERN_C const CLSID CLSID_SAOT;

#ifdef __cplusplus

class DECLSPEC_UUID("CD583388-D348-4A9E-BBBB-9A8D25F3DAAD")
SAOT;
#endif

EXTERN_C const CLSID CLSID_DRIA;

#ifdef __cplusplus

class DECLSPEC_UUID("AF43CEA4-BF31-4BF7-AEB6-EAD41BB7B476")
DRIA;
#endif
#endif /* __FastAlgLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long __RPC_FAR *, unsigned long            , VARIANT __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * );
void                      __RPC_USER  VARIANT_UserFree(     unsigned long __RPC_FAR *, VARIANT __RPC_FAR * );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
