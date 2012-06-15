/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Mar 02 18:47:29 2006
 */
/* Compiler settings for C:\.lokaj\zbmis\module\dbproxy\mapping\mapping.idl:
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

#ifndef __mapping_h__
#define __mapping_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __IConnection_FWD_DEFINED__
#define __IConnection_FWD_DEFINED__
typedef interface IConnection IConnection;
#endif 	/* __IConnection_FWD_DEFINED__ */


#ifndef __IRecordset_FWD_DEFINED__
#define __IRecordset_FWD_DEFINED__
typedef interface IRecordset IRecordset;
#endif 	/* __IRecordset_FWD_DEFINED__ */


#ifndef __ICommand_FWD_DEFINED__
#define __ICommand_FWD_DEFINED__
typedef interface ICommand ICommand;
#endif 	/* __ICommand_FWD_DEFINED__ */


#ifndef __IConnectionAdapter_FWD_DEFINED__
#define __IConnectionAdapter_FWD_DEFINED__
typedef interface IConnectionAdapter IConnectionAdapter;
#endif 	/* __IConnectionAdapter_FWD_DEFINED__ */


#ifndef __ICommandAdapter_FWD_DEFINED__
#define __ICommandAdapter_FWD_DEFINED__
typedef interface ICommandAdapter ICommandAdapter;
#endif 	/* __ICommandAdapter_FWD_DEFINED__ */


#ifndef __IRecordsetAdapter_FWD_DEFINED__
#define __IRecordsetAdapter_FWD_DEFINED__
typedef interface IRecordsetAdapter IRecordsetAdapter;
#endif 	/* __IRecordsetAdapter_FWD_DEFINED__ */


#ifndef __IGlobals_FWD_DEFINED__
#define __IGlobals_FWD_DEFINED__
typedef interface IGlobals IGlobals;
#endif 	/* __IGlobals_FWD_DEFINED__ */


#ifndef __ConnectionAdapter_FWD_DEFINED__
#define __ConnectionAdapter_FWD_DEFINED__

#ifdef __cplusplus
typedef class ConnectionAdapter ConnectionAdapter;
#else
typedef struct ConnectionAdapter ConnectionAdapter;
#endif /* __cplusplus */

#endif 	/* __ConnectionAdapter_FWD_DEFINED__ */


#ifndef __CommandAdapter_FWD_DEFINED__
#define __CommandAdapter_FWD_DEFINED__

#ifdef __cplusplus
typedef class CommandAdapter CommandAdapter;
#else
typedef struct CommandAdapter CommandAdapter;
#endif /* __cplusplus */

#endif 	/* __CommandAdapter_FWD_DEFINED__ */


#ifndef __RecordsetAdapter_FWD_DEFINED__
#define __RecordsetAdapter_FWD_DEFINED__

#ifdef __cplusplus
typedef class RecordsetAdapter RecordsetAdapter;
#else
typedef struct RecordsetAdapter RecordsetAdapter;
#endif /* __cplusplus */

#endif 	/* __RecordsetAdapter_FWD_DEFINED__ */


#ifndef __Globals_FWD_DEFINED__
#define __Globals_FWD_DEFINED__

#ifdef __cplusplus
typedef class Globals Globals;
#else
typedef struct Globals Globals;
#endif /* __cplusplus */

#endif 	/* __Globals_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "adoenum.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );


#ifndef __ADOMapping_LIBRARY_DEFINED__
#define __ADOMapping_LIBRARY_DEFINED__

/* library ADOMapping */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_ADOMapping;

#ifndef __IConnection_INTERFACE_DEFINED__
#define __IConnection_INTERFACE_DEFINED__

/* interface IConnection */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IConnection;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("7BA7DF7A-D03B-4147-A3A6-94BA9EB8E4A5")
    IConnection : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Properties(
            /* [retval][out] */ /* external definition not present */ Properties __RPC_FAR *__RPC_FAR *pVal) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ConnectionString(
            /* [retval][out] */ BSTR __RPC_FAR *pbstr) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_ConnectionString(
            /* [in] */ BSTR pbstr) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_CommandTimeout(
            /* [retval][out] */ long __RPC_FAR *plTimeout) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_CommandTimeout(
            /* [in] */ long plTimeout) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ConnectionTimeout(
            /* [retval][out] */ long __RPC_FAR *plTimeout) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_ConnectionTimeout(
            /* [in] */ long plTimeout) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Version(
            /* [retval][out] */ BSTR __RPC_FAR *pbstr) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Execute(
            /* [in] */ BSTR CommandText,
            /* [optional][out] */ VARIANT __RPC_FAR *RecordsAffected,
            /* [defaultvalue][optional][in] */ long Options,
            /* [retval][out] */ /* external definition not present */ _Recordset __RPC_FAR *__RPC_FAR *ppiRset) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE BeginTrans(
            /* [retval][out] */ long __RPC_FAR *TransactionLevel) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CommitTrans( void) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RollbackTrans( void) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Open(
            /* [defaultvalue][optional][in] */ BSTR ConnectionString = L"",
            /* [defaultvalue][optional][in] */ BSTR UserID = L"",
            /* [defaultvalue][optional][in] */ BSTR Password = L"",
            /* [defaultvalue][optional][in] */ long Options = -1) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Errors(
            /* [retval][out] */ /* external definition not present */ Errors __RPC_FAR *__RPC_FAR *ppvObject) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_DefaultDatabase(
            /* [retval][out] */ BSTR __RPC_FAR *pbstr) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_DefaultDatabase(
            /* [in] */ BSTR pbstr) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_IsolationLevel(
            /* [retval][out] */ IsolationLevelEnum __RPC_FAR *Level) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_IsolationLevel(
            /* [in] */ IsolationLevelEnum Level) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Attributes(
            /* [retval][out] */ long __RPC_FAR *plAttr) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Attributes(
            /* [in] */ long plAttr) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_CursorLocation(
            /* [retval][out] */ CursorLocationEnum __RPC_FAR *plCursorLoc) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_CursorLocation(
            /* [in] */ CursorLocationEnum plCursorLoc) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Mode(
            /* [retval][out] */ ConnectModeEnum __RPC_FAR *plMode) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Mode(
            /* [in] */ ConnectModeEnum plMode) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Provider(
            /* [retval][out] */ BSTR __RPC_FAR *pbstr) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Provider(
            /* [in] */ BSTR pbstr) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_State(
            /* [retval][out] */ long __RPC_FAR *plObjState) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OpenSchema(
            /* [in] */ SchemaEnum Schema,
            /* [optional][in] */ VARIANT Restrictions,
            /* [optional][in] */ VARIANT SchemaID,
            /* [retval][out] */ /* external definition not present */ _Recordset __RPC_FAR *__RPC_FAR *pprset) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Cancel( void) = 0;

    };

#else 	/* C style interface */

    typedef struct IConnectionVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IConnection __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IConnection __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IConnection __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IConnection __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IConnection __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IConnection __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IConnection __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )(
            IConnection __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ Properties __RPC_FAR *__RPC_FAR *pVal);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ConnectionString )(
            IConnection __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pbstr);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ConnectionString )(
            IConnection __RPC_FAR * This,
            /* [in] */ BSTR pbstr);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CommandTimeout )(
            IConnection __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plTimeout);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CommandTimeout )(
            IConnection __RPC_FAR * This,
            /* [in] */ long plTimeout);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ConnectionTimeout )(
            IConnection __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plTimeout);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ConnectionTimeout )(
            IConnection __RPC_FAR * This,
            /* [in] */ long plTimeout);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Version )(
            IConnection __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pbstr);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )(
            IConnection __RPC_FAR * This);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Execute )(
            IConnection __RPC_FAR * This,
            /* [in] */ BSTR CommandText,
            /* [optional][out] */ VARIANT __RPC_FAR *RecordsAffected,
            /* [defaultvalue][optional][in] */ long Options,
            /* [retval][out] */ /* external definition not present */ _Recordset __RPC_FAR *__RPC_FAR *ppiRset);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BeginTrans )(
            IConnection __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *TransactionLevel);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CommitTrans )(
            IConnection __RPC_FAR * This);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RollbackTrans )(
            IConnection __RPC_FAR * This);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )(
            IConnection __RPC_FAR * This,
            /* [defaultvalue][optional][in] */ BSTR ConnectionString,
            /* [defaultvalue][optional][in] */ BSTR UserID,
            /* [defaultvalue][optional][in] */ BSTR Password,
            /* [defaultvalue][optional][in] */ long Options);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Errors )(
            IConnection __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ Errors __RPC_FAR *__RPC_FAR *ppvObject);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DefaultDatabase )(
            IConnection __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pbstr);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DefaultDatabase )(
            IConnection __RPC_FAR * This,
            /* [in] */ BSTR pbstr);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IsolationLevel )(
            IConnection __RPC_FAR * This,
            /* [retval][out] */ IsolationLevelEnum __RPC_FAR *Level);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_IsolationLevel )(
            IConnection __RPC_FAR * This,
            /* [in] */ IsolationLevelEnum Level);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Attributes )(
            IConnection __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plAttr);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Attributes )(
            IConnection __RPC_FAR * This,
            /* [in] */ long plAttr);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CursorLocation )(
            IConnection __RPC_FAR * This,
            /* [retval][out] */ CursorLocationEnum __RPC_FAR *plCursorLoc);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CursorLocation )(
            IConnection __RPC_FAR * This,
            /* [in] */ CursorLocationEnum plCursorLoc);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Mode )(
            IConnection __RPC_FAR * This,
            /* [retval][out] */ ConnectModeEnum __RPC_FAR *plMode);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Mode )(
            IConnection __RPC_FAR * This,
            /* [in] */ ConnectModeEnum plMode);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Provider )(
            IConnection __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pbstr);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Provider )(
            IConnection __RPC_FAR * This,
            /* [in] */ BSTR pbstr);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_State )(
            IConnection __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plObjState);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenSchema )(
            IConnection __RPC_FAR * This,
            /* [in] */ SchemaEnum Schema,
            /* [optional][in] */ VARIANT Restrictions,
            /* [optional][in] */ VARIANT SchemaID,
            /* [retval][out] */ /* external definition not present */ _Recordset __RPC_FAR *__RPC_FAR *pprset);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Cancel )(
            IConnection __RPC_FAR * This);

        END_INTERFACE
    } IConnectionVtbl;

    interface IConnection
    {
        CONST_VTBL struct IConnectionVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IConnection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IConnection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IConnection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IConnection_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IConnection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IConnection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IConnection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IConnection_get_Properties(This,pVal)	\
    (This)->lpVtbl -> get_Properties(This,pVal)

#define IConnection_get_ConnectionString(This,pbstr)	\
    (This)->lpVtbl -> get_ConnectionString(This,pbstr)

#define IConnection_put_ConnectionString(This,pbstr)	\
    (This)->lpVtbl -> put_ConnectionString(This,pbstr)

#define IConnection_get_CommandTimeout(This,plTimeout)	\
    (This)->lpVtbl -> get_CommandTimeout(This,plTimeout)

#define IConnection_put_CommandTimeout(This,plTimeout)	\
    (This)->lpVtbl -> put_CommandTimeout(This,plTimeout)

#define IConnection_get_ConnectionTimeout(This,plTimeout)	\
    (This)->lpVtbl -> get_ConnectionTimeout(This,plTimeout)

#define IConnection_put_ConnectionTimeout(This,plTimeout)	\
    (This)->lpVtbl -> put_ConnectionTimeout(This,plTimeout)

#define IConnection_get_Version(This,pbstr)	\
    (This)->lpVtbl -> get_Version(This,pbstr)

#define IConnection_Close(This)	\
    (This)->lpVtbl -> Close(This)

#define IConnection_Execute(This,CommandText,RecordsAffected,Options,ppiRset)	\
    (This)->lpVtbl -> Execute(This,CommandText,RecordsAffected,Options,ppiRset)

#define IConnection_BeginTrans(This,TransactionLevel)	\
    (This)->lpVtbl -> BeginTrans(This,TransactionLevel)

#define IConnection_CommitTrans(This)	\
    (This)->lpVtbl -> CommitTrans(This)

#define IConnection_RollbackTrans(This)	\
    (This)->lpVtbl -> RollbackTrans(This)

#define IConnection_Open(This,ConnectionString,UserID,Password,Options)	\
    (This)->lpVtbl -> Open(This,ConnectionString,UserID,Password,Options)

#define IConnection_get_Errors(This,ppvObject)	\
    (This)->lpVtbl -> get_Errors(This,ppvObject)

#define IConnection_get_DefaultDatabase(This,pbstr)	\
    (This)->lpVtbl -> get_DefaultDatabase(This,pbstr)

#define IConnection_put_DefaultDatabase(This,pbstr)	\
    (This)->lpVtbl -> put_DefaultDatabase(This,pbstr)

#define IConnection_get_IsolationLevel(This,Level)	\
    (This)->lpVtbl -> get_IsolationLevel(This,Level)

#define IConnection_put_IsolationLevel(This,Level)	\
    (This)->lpVtbl -> put_IsolationLevel(This,Level)

#define IConnection_get_Attributes(This,plAttr)	\
    (This)->lpVtbl -> get_Attributes(This,plAttr)

#define IConnection_put_Attributes(This,plAttr)	\
    (This)->lpVtbl -> put_Attributes(This,plAttr)

#define IConnection_get_CursorLocation(This,plCursorLoc)	\
    (This)->lpVtbl -> get_CursorLocation(This,plCursorLoc)

#define IConnection_put_CursorLocation(This,plCursorLoc)	\
    (This)->lpVtbl -> put_CursorLocation(This,plCursorLoc)

#define IConnection_get_Mode(This,plMode)	\
    (This)->lpVtbl -> get_Mode(This,plMode)

#define IConnection_put_Mode(This,plMode)	\
    (This)->lpVtbl -> put_Mode(This,plMode)

#define IConnection_get_Provider(This,pbstr)	\
    (This)->lpVtbl -> get_Provider(This,pbstr)

#define IConnection_put_Provider(This,pbstr)	\
    (This)->lpVtbl -> put_Provider(This,pbstr)

#define IConnection_get_State(This,plObjState)	\
    (This)->lpVtbl -> get_State(This,plObjState)

#define IConnection_OpenSchema(This,Schema,Restrictions,SchemaID,pprset)	\
    (This)->lpVtbl -> OpenSchema(This,Schema,Restrictions,SchemaID,pprset)

#define IConnection_Cancel(This)	\
    (This)->lpVtbl -> Cancel(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IConnection_get_Properties_Proxy(
    IConnection __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ Properties __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IConnection_get_Properties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IConnection_get_ConnectionString_Proxy(
    IConnection __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstr);


void __RPC_STUB IConnection_get_ConnectionString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IConnection_put_ConnectionString_Proxy(
    IConnection __RPC_FAR * This,
    /* [in] */ BSTR pbstr);


void __RPC_STUB IConnection_put_ConnectionString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IConnection_get_CommandTimeout_Proxy(
    IConnection __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *plTimeout);


void __RPC_STUB IConnection_get_CommandTimeout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IConnection_put_CommandTimeout_Proxy(
    IConnection __RPC_FAR * This,
    /* [in] */ long plTimeout);


void __RPC_STUB IConnection_put_CommandTimeout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IConnection_get_ConnectionTimeout_Proxy(
    IConnection __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *plTimeout);


void __RPC_STUB IConnection_get_ConnectionTimeout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IConnection_put_ConnectionTimeout_Proxy(
    IConnection __RPC_FAR * This,
    /* [in] */ long plTimeout);


void __RPC_STUB IConnection_put_ConnectionTimeout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IConnection_get_Version_Proxy(
    IConnection __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstr);


void __RPC_STUB IConnection_get_Version_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IConnection_Close_Proxy(
    IConnection __RPC_FAR * This);


void __RPC_STUB IConnection_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IConnection_Execute_Proxy(
    IConnection __RPC_FAR * This,
    /* [in] */ BSTR CommandText,
    /* [optional][out] */ VARIANT __RPC_FAR *RecordsAffected,
    /* [defaultvalue][optional][in] */ long Options,
    /* [retval][out] */ /* external definition not present */ _Recordset __RPC_FAR *__RPC_FAR *ppiRset);


void __RPC_STUB IConnection_Execute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IConnection_BeginTrans_Proxy(
    IConnection __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *TransactionLevel);


void __RPC_STUB IConnection_BeginTrans_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IConnection_CommitTrans_Proxy(
    IConnection __RPC_FAR * This);


void __RPC_STUB IConnection_CommitTrans_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IConnection_RollbackTrans_Proxy(
    IConnection __RPC_FAR * This);


void __RPC_STUB IConnection_RollbackTrans_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IConnection_Open_Proxy(
    IConnection __RPC_FAR * This,
    /* [defaultvalue][optional][in] */ BSTR ConnectionString,
    /* [defaultvalue][optional][in] */ BSTR UserID,
    /* [defaultvalue][optional][in] */ BSTR Password,
    /* [defaultvalue][optional][in] */ long Options);


void __RPC_STUB IConnection_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IConnection_get_Errors_Proxy(
    IConnection __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ Errors __RPC_FAR *__RPC_FAR *ppvObject);


void __RPC_STUB IConnection_get_Errors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IConnection_get_DefaultDatabase_Proxy(
    IConnection __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstr);


void __RPC_STUB IConnection_get_DefaultDatabase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IConnection_put_DefaultDatabase_Proxy(
    IConnection __RPC_FAR * This,
    /* [in] */ BSTR pbstr);


void __RPC_STUB IConnection_put_DefaultDatabase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IConnection_get_IsolationLevel_Proxy(
    IConnection __RPC_FAR * This,
    /* [retval][out] */ IsolationLevelEnum __RPC_FAR *Level);


void __RPC_STUB IConnection_get_IsolationLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IConnection_put_IsolationLevel_Proxy(
    IConnection __RPC_FAR * This,
    /* [in] */ IsolationLevelEnum Level);


void __RPC_STUB IConnection_put_IsolationLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IConnection_get_Attributes_Proxy(
    IConnection __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *plAttr);


void __RPC_STUB IConnection_get_Attributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IConnection_put_Attributes_Proxy(
    IConnection __RPC_FAR * This,
    /* [in] */ long plAttr);


void __RPC_STUB IConnection_put_Attributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IConnection_get_CursorLocation_Proxy(
    IConnection __RPC_FAR * This,
    /* [retval][out] */ CursorLocationEnum __RPC_FAR *plCursorLoc);


void __RPC_STUB IConnection_get_CursorLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IConnection_put_CursorLocation_Proxy(
    IConnection __RPC_FAR * This,
    /* [in] */ CursorLocationEnum plCursorLoc);


void __RPC_STUB IConnection_put_CursorLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IConnection_get_Mode_Proxy(
    IConnection __RPC_FAR * This,
    /* [retval][out] */ ConnectModeEnum __RPC_FAR *plMode);


void __RPC_STUB IConnection_get_Mode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IConnection_put_Mode_Proxy(
    IConnection __RPC_FAR * This,
    /* [in] */ ConnectModeEnum plMode);


void __RPC_STUB IConnection_put_Mode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IConnection_get_Provider_Proxy(
    IConnection __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstr);


void __RPC_STUB IConnection_get_Provider_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IConnection_put_Provider_Proxy(
    IConnection __RPC_FAR * This,
    /* [in] */ BSTR pbstr);


void __RPC_STUB IConnection_put_Provider_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IConnection_get_State_Proxy(
    IConnection __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *plObjState);


void __RPC_STUB IConnection_get_State_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IConnection_OpenSchema_Proxy(
    IConnection __RPC_FAR * This,
    /* [in] */ SchemaEnum Schema,
    /* [optional][in] */ VARIANT Restrictions,
    /* [optional][in] */ VARIANT SchemaID,
    /* [retval][out] */ /* external definition not present */ _Recordset __RPC_FAR *__RPC_FAR *pprset);


void __RPC_STUB IConnection_OpenSchema_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IConnection_Cancel_Proxy(
    IConnection __RPC_FAR * This);


void __RPC_STUB IConnection_Cancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IConnection_INTERFACE_DEFINED__ */


#ifndef __IRecordset_INTERFACE_DEFINED__
#define __IRecordset_INTERFACE_DEFINED__

/* interface IRecordset */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IRecordset;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("C26EE01B-C5F7-44A5-9551-66BDCD7963CD")
    IRecordset : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Properties(
            /* [retval][out] */ /* external definition not present */ Properties __RPC_FAR *__RPC_FAR *pVal) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_AbsolutePosition(
            /* [retval][out] */ PositionEnum_Param __RPC_FAR *pl) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_AbsolutePosition(
            /* [in] */ PositionEnum_Param pl) = 0;

        virtual /* [propputref][id] */ HRESULT STDMETHODCALLTYPE putref_ActiveConnection(
            /* [in] */ IDispatch __RPC_FAR *pvar) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_ActiveConnection(
            /* [in] */ VARIANT pvar) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveConnection(
            /* [retval][out] */ VARIANT __RPC_FAR *pvar) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_BOF(
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pb) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Bookmark(
            /* [retval][out] */ VARIANT __RPC_FAR *pvBookmark) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Bookmark(
            /* [in] */ VARIANT pvBookmark) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_CacheSize(
            /* [retval][out] */ long __RPC_FAR *pl) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_CacheSize(
            /* [in] */ long pl) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_CursorType(
            /* [retval][out] */ CursorTypeEnum __RPC_FAR *plCursorType) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_CursorType(
            /* [in] */ CursorTypeEnum plCursorType) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_EOF(
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pb) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Fields(
            /* [retval][out] */ /* external definition not present */ Fields __RPC_FAR *__RPC_FAR *ppvObject) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_LockType(
            /* [retval][out] */ LockTypeEnum __RPC_FAR *plLockType) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_LockType(
            /* [in] */ LockTypeEnum plLockType) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_MaxRecords(
            /* [retval][out] */ long __RPC_FAR *plMaxRecords) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_MaxRecords(
            /* [in] */ long plMaxRecords) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_RecordCount(
            /* [retval][out] */ long __RPC_FAR *pl) = 0;

        virtual /* [propputref][id] */ HRESULT STDMETHODCALLTYPE putref_Source(
            /* [in] */ VARIANT __RPC_FAR *pvSource) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Source(
            /* [in] */ VARIANT pvSource) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Source(
            /* [retval][out] */ VARIANT __RPC_FAR *pvSource) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AddNew(
            /* [optional][in] */ VARIANT FieldList,
            /* [optional][in] */ VARIANT Values) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CancelUpdate( void) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Delete(
            /* [defaultvalue][optional][in] */ AffectEnum AffectRecords = adAffectCurrent) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetRows(
            /* [defaultvalue][optional][in] */ long Rows,
            /* [optional][in] */ VARIANT Start,
            /* [optional][in] */ VARIANT Fields,
            /* [retval][out] */ VARIANT __RPC_FAR *pvar) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Move(
            /* [in] */ long NumRecords,
            /* [optional][in] */ VARIANT Start) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE MoveNext( void) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE MovePrevious( void) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE MoveFirst( void) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE MoveLast( void) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Open(
            /* [optional][in] */ VARIANT Source,
            /* [optional][in] */ VARIANT ActiveConnection,
            /* [defaultvalue][optional][in] */ CursorTypeEnum CursorType = adOpenUnspecified,
            /* [defaultvalue][optional][in] */ LockTypeEnum LockType = adLockUnspecified,
            /* [defaultvalue][optional][in] */ long Options = -1) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Requery(
            /* [defaultvalue][optional][in] */ long Options = -1) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE xxResync(
            /* [defaultvalue][optional][in] */ AffectEnum AffectRecords = adAffectAll) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Update(
            /* [optional][in] */ VARIANT Fields,
            /* [optional][in] */ VARIANT Values) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_AbsolutePage(
            /* [retval][out] */ PositionEnum_Param __RPC_FAR *pl) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_AbsolutePage(
            /* [in] */ PositionEnum_Param pl) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_EditMode(
            /* [retval][out] */ EditModeEnum __RPC_FAR *pl) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Filter(
            /* [retval][out] */ VARIANT __RPC_FAR *Criteria) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Filter(
            /* [in] */ VARIANT Criteria) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_PageCount(
            /* [retval][out] */ long __RPC_FAR *pl) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_PageSize(
            /* [retval][out] */ long __RPC_FAR *pl) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_PageSize(
            /* [in] */ long pl) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Sort(
            /* [retval][out] */ BSTR __RPC_FAR *Criteria) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Sort(
            /* [in] */ BSTR Criteria) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Status(
            /* [retval][out] */ long __RPC_FAR *pl) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_State(
            /* [retval][out] */ long __RPC_FAR *plObjState) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE xxClone(
            /* [retval][out] */ /* external definition not present */ _Recordset __RPC_FAR *__RPC_FAR *ppvObject) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE UpdateBatch(
            /* [defaultvalue][optional][in] */ AffectEnum AffectRecords = adAffectAll) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CancelBatch(
            /* [defaultvalue][optional][in] */ AffectEnum AffectRecords = adAffectAll) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_CursorLocation(
            /* [retval][out] */ CursorLocationEnum __RPC_FAR *plCursorLoc) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_CursorLocation(
            /* [in] */ CursorLocationEnum plCursorLoc) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE NextRecordset(
            /* [optional][out] */ VARIANT __RPC_FAR *RecordsAffected,
            /* [retval][out] */ /* external definition not present */ _Recordset __RPC_FAR *__RPC_FAR *ppiRs) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Supports(
            /* [in] */ CursorOptionEnum CursorOptions,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pb) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Collect(
            /* [in] */ VARIANT Index,
            /* [retval][out] */ VARIANT __RPC_FAR *pvar) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Collect(
            /* [in] */ VARIANT Index,
            /* [in] */ VARIANT pvar) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_MarshalOptions(
            /* [retval][out] */ MarshalOptionsEnum __RPC_FAR *peMarshal) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_MarshalOptions(
            /* [in] */ MarshalOptionsEnum peMarshal) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Find(
            /* [in] */ BSTR Criteria,
            /* [defaultvalue][optional][in] */ long SkipRecords,
            /* [defaultvalue][optional][in] */ SearchDirectionEnum SearchDirection,
            /* [optional][in] */ VARIANT Start) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Cancel( void) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_DataSource(
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppunkDataSource) = 0;

        virtual /* [propputref][id] */ HRESULT STDMETHODCALLTYPE putref_DataSource(
            /* [in] */ IDispatch __RPC_FAR *ppunkDataSource) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE xxSave(
            /* [defaultvalue][optional][in] */ BSTR FileName = L"",
            /* [defaultvalue][optional][in] */ PersistFormatEnum PersistFormat = adPersistADTG) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveCommand(
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppCmd) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_StayInSync(
            /* [in] */ VARIANT_BOOL pbStayInSync) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_StayInSync(
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbStayInSync) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetString(
            /* [defaultvalue][optional][in] */ StringFormatEnum StringFormat,
            /* [defaultvalue][optional][in] */ long NumRows,
            /* [defaultvalue][optional][in] */ BSTR ColumnDelimeter,
            /* [defaultvalue][optional][in] */ BSTR RowDelimeter,
            /* [defaultvalue][optional][in] */ BSTR NullExpr,
            /* [retval][out] */ BSTR __RPC_FAR *pRetString) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_DataMember(
            /* [retval][out] */ BSTR __RPC_FAR *pbstrDataMember) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_DataMember(
            /* [in] */ BSTR pbstrDataMember) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CompareBookmarks(
            /* [in] */ VARIANT Bookmark1,
            /* [in] */ VARIANT Bookmark2,
            /* [retval][out] */ CompareEnum __RPC_FAR *pCompare) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Clone(
            /* [defaultvalue][optional][in] */ LockTypeEnum LockType,
            /* [retval][out] */ /* external definition not present */ _Recordset __RPC_FAR *__RPC_FAR *ppvObject) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Resync(
            /* [defaultvalue][optional][in] */ AffectEnum AffectRecords = adAffectAll,
            /* [defaultvalue][optional][in] */ ResyncEnum ResyncValues = adResyncAllValues) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Seek(
            /* [in] */ VARIANT KeyValues,
            /* [defaultvalue][optional][in] */ SeekEnum SeekOption = adSeekFirstEQ) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Index(
            /* [in] */ BSTR pbstrIndex) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Index(
            /* [retval][out] */ BSTR __RPC_FAR *pbstrIndex) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Save(
            /* [optional][in] */ VARIANT Destination,
            /* [defaultvalue][optional][in] */ PersistFormatEnum PersistFormat = adPersistADTG) = 0;

    };

#else 	/* C style interface */

    typedef struct IRecordsetVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IRecordset __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IRecordset __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IRecordset __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IRecordset __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IRecordset __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IRecordset __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IRecordset __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ Properties __RPC_FAR *__RPC_FAR *pVal);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AbsolutePosition )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ PositionEnum_Param __RPC_FAR *pl);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AbsolutePosition )(
            IRecordset __RPC_FAR * This,
            /* [in] */ PositionEnum_Param pl);

        /* [propputref][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_ActiveConnection )(
            IRecordset __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *pvar);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActiveConnection )(
            IRecordset __RPC_FAR * This,
            /* [in] */ VARIANT pvar);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActiveConnection )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pvar);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BOF )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pb);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Bookmark )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pvBookmark);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Bookmark )(
            IRecordset __RPC_FAR * This,
            /* [in] */ VARIANT pvBookmark);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CacheSize )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pl);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CacheSize )(
            IRecordset __RPC_FAR * This,
            /* [in] */ long pl);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CursorType )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ CursorTypeEnum __RPC_FAR *plCursorType);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CursorType )(
            IRecordset __RPC_FAR * This,
            /* [in] */ CursorTypeEnum plCursorType);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_EOF )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pb);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Fields )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ Fields __RPC_FAR *__RPC_FAR *ppvObject);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LockType )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ LockTypeEnum __RPC_FAR *plLockType);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_LockType )(
            IRecordset __RPC_FAR * This,
            /* [in] */ LockTypeEnum plLockType);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MaxRecords )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plMaxRecords);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_MaxRecords )(
            IRecordset __RPC_FAR * This,
            /* [in] */ long plMaxRecords);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RecordCount )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pl);

        /* [propputref][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_Source )(
            IRecordset __RPC_FAR * This,
            /* [in] */ VARIANT __RPC_FAR *pvSource);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Source )(
            IRecordset __RPC_FAR * This,
            /* [in] */ VARIANT pvSource);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Source )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pvSource);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddNew )(
            IRecordset __RPC_FAR * This,
            /* [optional][in] */ VARIANT FieldList,
            /* [optional][in] */ VARIANT Values);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CancelUpdate )(
            IRecordset __RPC_FAR * This);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )(
            IRecordset __RPC_FAR * This);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Delete )(
            IRecordset __RPC_FAR * This,
            /* [defaultvalue][optional][in] */ AffectEnum AffectRecords);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRows )(
            IRecordset __RPC_FAR * This,
            /* [defaultvalue][optional][in] */ long Rows,
            /* [optional][in] */ VARIANT Start,
            /* [optional][in] */ VARIANT Fields,
            /* [retval][out] */ VARIANT __RPC_FAR *pvar);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Move )(
            IRecordset __RPC_FAR * This,
            /* [in] */ long NumRecords,
            /* [optional][in] */ VARIANT Start);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveNext )(
            IRecordset __RPC_FAR * This);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MovePrevious )(
            IRecordset __RPC_FAR * This);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveFirst )(
            IRecordset __RPC_FAR * This);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveLast )(
            IRecordset __RPC_FAR * This);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )(
            IRecordset __RPC_FAR * This,
            /* [optional][in] */ VARIANT Source,
            /* [optional][in] */ VARIANT ActiveConnection,
            /* [defaultvalue][optional][in] */ CursorTypeEnum CursorType,
            /* [defaultvalue][optional][in] */ LockTypeEnum LockType,
            /* [defaultvalue][optional][in] */ long Options);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Requery )(
            IRecordset __RPC_FAR * This,
            /* [defaultvalue][optional][in] */ long Options);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *xxResync )(
            IRecordset __RPC_FAR * This,
            /* [defaultvalue][optional][in] */ AffectEnum AffectRecords);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Update )(
            IRecordset __RPC_FAR * This,
            /* [optional][in] */ VARIANT Fields,
            /* [optional][in] */ VARIANT Values);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AbsolutePage )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ PositionEnum_Param __RPC_FAR *pl);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AbsolutePage )(
            IRecordset __RPC_FAR * This,
            /* [in] */ PositionEnum_Param pl);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_EditMode )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ EditModeEnum __RPC_FAR *pl);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Filter )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *Criteria);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Filter )(
            IRecordset __RPC_FAR * This,
            /* [in] */ VARIANT Criteria);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PageCount )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pl);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PageSize )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pl);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PageSize )(
            IRecordset __RPC_FAR * This,
            /* [in] */ long pl);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Sort )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Criteria);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Sort )(
            IRecordset __RPC_FAR * This,
            /* [in] */ BSTR Criteria);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Status )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pl);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_State )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plObjState);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *xxClone )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ _Recordset __RPC_FAR *__RPC_FAR *ppvObject);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UpdateBatch )(
            IRecordset __RPC_FAR * This,
            /* [defaultvalue][optional][in] */ AffectEnum AffectRecords);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CancelBatch )(
            IRecordset __RPC_FAR * This,
            /* [defaultvalue][optional][in] */ AffectEnum AffectRecords);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CursorLocation )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ CursorLocationEnum __RPC_FAR *plCursorLoc);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CursorLocation )(
            IRecordset __RPC_FAR * This,
            /* [in] */ CursorLocationEnum plCursorLoc);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *NextRecordset )(
            IRecordset __RPC_FAR * This,
            /* [optional][out] */ VARIANT __RPC_FAR *RecordsAffected,
            /* [retval][out] */ /* external definition not present */ _Recordset __RPC_FAR *__RPC_FAR *ppiRs);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Supports )(
            IRecordset __RPC_FAR * This,
            /* [in] */ CursorOptionEnum CursorOptions,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pb);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Collect )(
            IRecordset __RPC_FAR * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ VARIANT __RPC_FAR *pvar);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Collect )(
            IRecordset __RPC_FAR * This,
            /* [in] */ VARIANT Index,
            /* [in] */ VARIANT pvar);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MarshalOptions )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ MarshalOptionsEnum __RPC_FAR *peMarshal);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_MarshalOptions )(
            IRecordset __RPC_FAR * This,
            /* [in] */ MarshalOptionsEnum peMarshal);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Find )(
            IRecordset __RPC_FAR * This,
            /* [in] */ BSTR Criteria,
            /* [defaultvalue][optional][in] */ long SkipRecords,
            /* [defaultvalue][optional][in] */ SearchDirectionEnum SearchDirection,
            /* [optional][in] */ VARIANT Start);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Cancel )(
            IRecordset __RPC_FAR * This);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DataSource )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppunkDataSource);

        /* [propputref][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_DataSource )(
            IRecordset __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *ppunkDataSource);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *xxSave )(
            IRecordset __RPC_FAR * This,
            /* [defaultvalue][optional][in] */ BSTR FileName,
            /* [defaultvalue][optional][in] */ PersistFormatEnum PersistFormat);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActiveCommand )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppCmd);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_StayInSync )(
            IRecordset __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pbStayInSync);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_StayInSync )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbStayInSync);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetString )(
            IRecordset __RPC_FAR * This,
            /* [defaultvalue][optional][in] */ StringFormatEnum StringFormat,
            /* [defaultvalue][optional][in] */ long NumRows,
            /* [defaultvalue][optional][in] */ BSTR ColumnDelimeter,
            /* [defaultvalue][optional][in] */ BSTR RowDelimeter,
            /* [defaultvalue][optional][in] */ BSTR NullExpr,
            /* [retval][out] */ BSTR __RPC_FAR *pRetString);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DataMember )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrDataMember);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DataMember )(
            IRecordset __RPC_FAR * This,
            /* [in] */ BSTR pbstrDataMember);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CompareBookmarks )(
            IRecordset __RPC_FAR * This,
            /* [in] */ VARIANT Bookmark1,
            /* [in] */ VARIANT Bookmark2,
            /* [retval][out] */ CompareEnum __RPC_FAR *pCompare);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )(
            IRecordset __RPC_FAR * This,
            /* [defaultvalue][optional][in] */ LockTypeEnum LockType,
            /* [retval][out] */ /* external definition not present */ _Recordset __RPC_FAR *__RPC_FAR *ppvObject);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Resync )(
            IRecordset __RPC_FAR * This,
            /* [defaultvalue][optional][in] */ AffectEnum AffectRecords,
            /* [defaultvalue][optional][in] */ ResyncEnum ResyncValues);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Seek )(
            IRecordset __RPC_FAR * This,
            /* [in] */ VARIANT KeyValues,
            /* [defaultvalue][optional][in] */ SeekEnum SeekOption);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Index )(
            IRecordset __RPC_FAR * This,
            /* [in] */ BSTR pbstrIndex);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Index )(
            IRecordset __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrIndex);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Save )(
            IRecordset __RPC_FAR * This,
            /* [optional][in] */ VARIANT Destination,
            /* [defaultvalue][optional][in] */ PersistFormatEnum PersistFormat);

        END_INTERFACE
    } IRecordsetVtbl;

    interface IRecordset
    {
        CONST_VTBL struct IRecordsetVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IRecordset_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRecordset_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRecordset_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRecordset_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRecordset_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRecordset_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRecordset_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRecordset_get_Properties(This,pVal)	\
    (This)->lpVtbl -> get_Properties(This,pVal)

#define IRecordset_get_AbsolutePosition(This,pl)	\
    (This)->lpVtbl -> get_AbsolutePosition(This,pl)

#define IRecordset_put_AbsolutePosition(This,pl)	\
    (This)->lpVtbl -> put_AbsolutePosition(This,pl)

#define IRecordset_putref_ActiveConnection(This,pvar)	\
    (This)->lpVtbl -> putref_ActiveConnection(This,pvar)

#define IRecordset_put_ActiveConnection(This,pvar)	\
    (This)->lpVtbl -> put_ActiveConnection(This,pvar)

#define IRecordset_get_ActiveConnection(This,pvar)	\
    (This)->lpVtbl -> get_ActiveConnection(This,pvar)

#define IRecordset_get_BOF(This,pb)	\
    (This)->lpVtbl -> get_BOF(This,pb)

#define IRecordset_get_Bookmark(This,pvBookmark)	\
    (This)->lpVtbl -> get_Bookmark(This,pvBookmark)

#define IRecordset_put_Bookmark(This,pvBookmark)	\
    (This)->lpVtbl -> put_Bookmark(This,pvBookmark)

#define IRecordset_get_CacheSize(This,pl)	\
    (This)->lpVtbl -> get_CacheSize(This,pl)

#define IRecordset_put_CacheSize(This,pl)	\
    (This)->lpVtbl -> put_CacheSize(This,pl)

#define IRecordset_get_CursorType(This,plCursorType)	\
    (This)->lpVtbl -> get_CursorType(This,plCursorType)

#define IRecordset_put_CursorType(This,plCursorType)	\
    (This)->lpVtbl -> put_CursorType(This,plCursorType)

#define IRecordset_get_EOF(This,pb)	\
    (This)->lpVtbl -> get_EOF(This,pb)

#define IRecordset_get_Fields(This,ppvObject)	\
    (This)->lpVtbl -> get_Fields(This,ppvObject)

#define IRecordset_get_LockType(This,plLockType)	\
    (This)->lpVtbl -> get_LockType(This,plLockType)

#define IRecordset_put_LockType(This,plLockType)	\
    (This)->lpVtbl -> put_LockType(This,plLockType)

#define IRecordset_get_MaxRecords(This,plMaxRecords)	\
    (This)->lpVtbl -> get_MaxRecords(This,plMaxRecords)

#define IRecordset_put_MaxRecords(This,plMaxRecords)	\
    (This)->lpVtbl -> put_MaxRecords(This,plMaxRecords)

#define IRecordset_get_RecordCount(This,pl)	\
    (This)->lpVtbl -> get_RecordCount(This,pl)

#define IRecordset_putref_Source(This,pvSource)	\
    (This)->lpVtbl -> putref_Source(This,pvSource)

#define IRecordset_put_Source(This,pvSource)	\
    (This)->lpVtbl -> put_Source(This,pvSource)

#define IRecordset_get_Source(This,pvSource)	\
    (This)->lpVtbl -> get_Source(This,pvSource)

#define IRecordset_AddNew(This,FieldList,Values)	\
    (This)->lpVtbl -> AddNew(This,FieldList,Values)

#define IRecordset_CancelUpdate(This)	\
    (This)->lpVtbl -> CancelUpdate(This)

#define IRecordset_Close(This)	\
    (This)->lpVtbl -> Close(This)

#define IRecordset_Delete(This,AffectRecords)	\
    (This)->lpVtbl -> Delete(This,AffectRecords)

#define IRecordset_GetRows(This,Rows,Start,Fields,pvar)	\
    (This)->lpVtbl -> GetRows(This,Rows,Start,Fields,pvar)

#define IRecordset_Move(This,NumRecords,Start)	\
    (This)->lpVtbl -> Move(This,NumRecords,Start)

#define IRecordset_MoveNext(This)	\
    (This)->lpVtbl -> MoveNext(This)

#define IRecordset_MovePrevious(This)	\
    (This)->lpVtbl -> MovePrevious(This)

#define IRecordset_MoveFirst(This)	\
    (This)->lpVtbl -> MoveFirst(This)

#define IRecordset_MoveLast(This)	\
    (This)->lpVtbl -> MoveLast(This)

#define IRecordset_Open(This,Source,ActiveConnection,CursorType,LockType,Options)	\
    (This)->lpVtbl -> Open(This,Source,ActiveConnection,CursorType,LockType,Options)

#define IRecordset_Requery(This,Options)	\
    (This)->lpVtbl -> Requery(This,Options)

#define IRecordset_xxResync(This,AffectRecords)	\
    (This)->lpVtbl -> xxResync(This,AffectRecords)

#define IRecordset_Update(This,Fields,Values)	\
    (This)->lpVtbl -> Update(This,Fields,Values)

#define IRecordset_get_AbsolutePage(This,pl)	\
    (This)->lpVtbl -> get_AbsolutePage(This,pl)

#define IRecordset_put_AbsolutePage(This,pl)	\
    (This)->lpVtbl -> put_AbsolutePage(This,pl)

#define IRecordset_get_EditMode(This,pl)	\
    (This)->lpVtbl -> get_EditMode(This,pl)

#define IRecordset_get_Filter(This,Criteria)	\
    (This)->lpVtbl -> get_Filter(This,Criteria)

#define IRecordset_put_Filter(This,Criteria)	\
    (This)->lpVtbl -> put_Filter(This,Criteria)

#define IRecordset_get_PageCount(This,pl)	\
    (This)->lpVtbl -> get_PageCount(This,pl)

#define IRecordset_get_PageSize(This,pl)	\
    (This)->lpVtbl -> get_PageSize(This,pl)

#define IRecordset_put_PageSize(This,pl)	\
    (This)->lpVtbl -> put_PageSize(This,pl)

#define IRecordset_get_Sort(This,Criteria)	\
    (This)->lpVtbl -> get_Sort(This,Criteria)

#define IRecordset_put_Sort(This,Criteria)	\
    (This)->lpVtbl -> put_Sort(This,Criteria)

#define IRecordset_get_Status(This,pl)	\
    (This)->lpVtbl -> get_Status(This,pl)

#define IRecordset_get_State(This,plObjState)	\
    (This)->lpVtbl -> get_State(This,plObjState)

#define IRecordset_xxClone(This,ppvObject)	\
    (This)->lpVtbl -> xxClone(This,ppvObject)

#define IRecordset_UpdateBatch(This,AffectRecords)	\
    (This)->lpVtbl -> UpdateBatch(This,AffectRecords)

#define IRecordset_CancelBatch(This,AffectRecords)	\
    (This)->lpVtbl -> CancelBatch(This,AffectRecords)

#define IRecordset_get_CursorLocation(This,plCursorLoc)	\
    (This)->lpVtbl -> get_CursorLocation(This,plCursorLoc)

#define IRecordset_put_CursorLocation(This,plCursorLoc)	\
    (This)->lpVtbl -> put_CursorLocation(This,plCursorLoc)

#define IRecordset_NextRecordset(This,RecordsAffected,ppiRs)	\
    (This)->lpVtbl -> NextRecordset(This,RecordsAffected,ppiRs)

#define IRecordset_Supports(This,CursorOptions,pb)	\
    (This)->lpVtbl -> Supports(This,CursorOptions,pb)

#define IRecordset_get_Collect(This,Index,pvar)	\
    (This)->lpVtbl -> get_Collect(This,Index,pvar)

#define IRecordset_put_Collect(This,Index,pvar)	\
    (This)->lpVtbl -> put_Collect(This,Index,pvar)

#define IRecordset_get_MarshalOptions(This,peMarshal)	\
    (This)->lpVtbl -> get_MarshalOptions(This,peMarshal)

#define IRecordset_put_MarshalOptions(This,peMarshal)	\
    (This)->lpVtbl -> put_MarshalOptions(This,peMarshal)

#define IRecordset_Find(This,Criteria,SkipRecords,SearchDirection,Start)	\
    (This)->lpVtbl -> Find(This,Criteria,SkipRecords,SearchDirection,Start)

#define IRecordset_Cancel(This)	\
    (This)->lpVtbl -> Cancel(This)

#define IRecordset_get_DataSource(This,ppunkDataSource)	\
    (This)->lpVtbl -> get_DataSource(This,ppunkDataSource)

#define IRecordset_putref_DataSource(This,ppunkDataSource)	\
    (This)->lpVtbl -> putref_DataSource(This,ppunkDataSource)

#define IRecordset_xxSave(This,FileName,PersistFormat)	\
    (This)->lpVtbl -> xxSave(This,FileName,PersistFormat)

#define IRecordset_get_ActiveCommand(This,ppCmd)	\
    (This)->lpVtbl -> get_ActiveCommand(This,ppCmd)

#define IRecordset_put_StayInSync(This,pbStayInSync)	\
    (This)->lpVtbl -> put_StayInSync(This,pbStayInSync)

#define IRecordset_get_StayInSync(This,pbStayInSync)	\
    (This)->lpVtbl -> get_StayInSync(This,pbStayInSync)

#define IRecordset_GetString(This,StringFormat,NumRows,ColumnDelimeter,RowDelimeter,NullExpr,pRetString)	\
    (This)->lpVtbl -> GetString(This,StringFormat,NumRows,ColumnDelimeter,RowDelimeter,NullExpr,pRetString)

#define IRecordset_get_DataMember(This,pbstrDataMember)	\
    (This)->lpVtbl -> get_DataMember(This,pbstrDataMember)

#define IRecordset_put_DataMember(This,pbstrDataMember)	\
    (This)->lpVtbl -> put_DataMember(This,pbstrDataMember)

#define IRecordset_CompareBookmarks(This,Bookmark1,Bookmark2,pCompare)	\
    (This)->lpVtbl -> CompareBookmarks(This,Bookmark1,Bookmark2,pCompare)

#define IRecordset_Clone(This,LockType,ppvObject)	\
    (This)->lpVtbl -> Clone(This,LockType,ppvObject)

#define IRecordset_Resync(This,AffectRecords,ResyncValues)	\
    (This)->lpVtbl -> Resync(This,AffectRecords,ResyncValues)

#define IRecordset_Seek(This,KeyValues,SeekOption)	\
    (This)->lpVtbl -> Seek(This,KeyValues,SeekOption)

#define IRecordset_put_Index(This,pbstrIndex)	\
    (This)->lpVtbl -> put_Index(This,pbstrIndex)

#define IRecordset_get_Index(This,pbstrIndex)	\
    (This)->lpVtbl -> get_Index(This,pbstrIndex)

#define IRecordset_Save(This,Destination,PersistFormat)	\
    (This)->lpVtbl -> Save(This,Destination,PersistFormat)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_Properties_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ Properties __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IRecordset_get_Properties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_AbsolutePosition_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ PositionEnum_Param __RPC_FAR *pl);


void __RPC_STUB IRecordset_get_AbsolutePosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IRecordset_put_AbsolutePosition_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ PositionEnum_Param pl);


void __RPC_STUB IRecordset_put_AbsolutePosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propputref][id] */ HRESULT STDMETHODCALLTYPE IRecordset_putref_ActiveConnection_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *pvar);


void __RPC_STUB IRecordset_putref_ActiveConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IRecordset_put_ActiveConnection_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ VARIANT pvar);


void __RPC_STUB IRecordset_put_ActiveConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_ActiveConnection_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pvar);


void __RPC_STUB IRecordset_get_ActiveConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_BOF_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pb);


void __RPC_STUB IRecordset_get_BOF_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_Bookmark_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pvBookmark);


void __RPC_STUB IRecordset_get_Bookmark_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IRecordset_put_Bookmark_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ VARIANT pvBookmark);


void __RPC_STUB IRecordset_put_Bookmark_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_CacheSize_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pl);


void __RPC_STUB IRecordset_get_CacheSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IRecordset_put_CacheSize_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ long pl);


void __RPC_STUB IRecordset_put_CacheSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_CursorType_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ CursorTypeEnum __RPC_FAR *plCursorType);


void __RPC_STUB IRecordset_get_CursorType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IRecordset_put_CursorType_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ CursorTypeEnum plCursorType);


void __RPC_STUB IRecordset_put_CursorType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_EOF_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pb);


void __RPC_STUB IRecordset_get_EOF_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_Fields_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ Fields __RPC_FAR *__RPC_FAR *ppvObject);


void __RPC_STUB IRecordset_get_Fields_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_LockType_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ LockTypeEnum __RPC_FAR *plLockType);


void __RPC_STUB IRecordset_get_LockType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IRecordset_put_LockType_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ LockTypeEnum plLockType);


void __RPC_STUB IRecordset_put_LockType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_MaxRecords_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *plMaxRecords);


void __RPC_STUB IRecordset_get_MaxRecords_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IRecordset_put_MaxRecords_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ long plMaxRecords);


void __RPC_STUB IRecordset_put_MaxRecords_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_RecordCount_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pl);


void __RPC_STUB IRecordset_get_RecordCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propputref][id] */ HRESULT STDMETHODCALLTYPE IRecordset_putref_Source_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ VARIANT __RPC_FAR *pvSource);


void __RPC_STUB IRecordset_putref_Source_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IRecordset_put_Source_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ VARIANT pvSource);


void __RPC_STUB IRecordset_put_Source_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_Source_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pvSource);


void __RPC_STUB IRecordset_get_Source_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_AddNew_Proxy(
    IRecordset __RPC_FAR * This,
    /* [optional][in] */ VARIANT FieldList,
    /* [optional][in] */ VARIANT Values);


void __RPC_STUB IRecordset_AddNew_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_CancelUpdate_Proxy(
    IRecordset __RPC_FAR * This);


void __RPC_STUB IRecordset_CancelUpdate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_Close_Proxy(
    IRecordset __RPC_FAR * This);


void __RPC_STUB IRecordset_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_Delete_Proxy(
    IRecordset __RPC_FAR * This,
    /* [defaultvalue][optional][in] */ AffectEnum AffectRecords);


void __RPC_STUB IRecordset_Delete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_GetRows_Proxy(
    IRecordset __RPC_FAR * This,
    /* [defaultvalue][optional][in] */ long Rows,
    /* [optional][in] */ VARIANT Start,
    /* [optional][in] */ VARIANT Fields,
    /* [retval][out] */ VARIANT __RPC_FAR *pvar);


void __RPC_STUB IRecordset_GetRows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_Move_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ long NumRecords,
    /* [optional][in] */ VARIANT Start);


void __RPC_STUB IRecordset_Move_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_MoveNext_Proxy(
    IRecordset __RPC_FAR * This);


void __RPC_STUB IRecordset_MoveNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_MovePrevious_Proxy(
    IRecordset __RPC_FAR * This);


void __RPC_STUB IRecordset_MovePrevious_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_MoveFirst_Proxy(
    IRecordset __RPC_FAR * This);


void __RPC_STUB IRecordset_MoveFirst_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_MoveLast_Proxy(
    IRecordset __RPC_FAR * This);


void __RPC_STUB IRecordset_MoveLast_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_Open_Proxy(
    IRecordset __RPC_FAR * This,
    /* [optional][in] */ VARIANT Source,
    /* [optional][in] */ VARIANT ActiveConnection,
    /* [defaultvalue][optional][in] */ CursorTypeEnum CursorType,
    /* [defaultvalue][optional][in] */ LockTypeEnum LockType,
    /* [defaultvalue][optional][in] */ long Options);


void __RPC_STUB IRecordset_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_Requery_Proxy(
    IRecordset __RPC_FAR * This,
    /* [defaultvalue][optional][in] */ long Options);


void __RPC_STUB IRecordset_Requery_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_xxResync_Proxy(
    IRecordset __RPC_FAR * This,
    /* [defaultvalue][optional][in] */ AffectEnum AffectRecords);


void __RPC_STUB IRecordset_xxResync_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_Update_Proxy(
    IRecordset __RPC_FAR * This,
    /* [optional][in] */ VARIANT Fields,
    /* [optional][in] */ VARIANT Values);


void __RPC_STUB IRecordset_Update_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_AbsolutePage_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ PositionEnum_Param __RPC_FAR *pl);


void __RPC_STUB IRecordset_get_AbsolutePage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IRecordset_put_AbsolutePage_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ PositionEnum_Param pl);


void __RPC_STUB IRecordset_put_AbsolutePage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_EditMode_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ EditModeEnum __RPC_FAR *pl);


void __RPC_STUB IRecordset_get_EditMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_Filter_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *Criteria);


void __RPC_STUB IRecordset_get_Filter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IRecordset_put_Filter_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ VARIANT Criteria);


void __RPC_STUB IRecordset_put_Filter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_PageCount_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pl);


void __RPC_STUB IRecordset_get_PageCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_PageSize_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pl);


void __RPC_STUB IRecordset_get_PageSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IRecordset_put_PageSize_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ long pl);


void __RPC_STUB IRecordset_put_PageSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_Sort_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Criteria);


void __RPC_STUB IRecordset_get_Sort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IRecordset_put_Sort_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ BSTR Criteria);


void __RPC_STUB IRecordset_put_Sort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_Status_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pl);


void __RPC_STUB IRecordset_get_Status_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_State_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *plObjState);


void __RPC_STUB IRecordset_get_State_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_xxClone_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ _Recordset __RPC_FAR *__RPC_FAR *ppvObject);


void __RPC_STUB IRecordset_xxClone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_UpdateBatch_Proxy(
    IRecordset __RPC_FAR * This,
    /* [defaultvalue][optional][in] */ AffectEnum AffectRecords);


void __RPC_STUB IRecordset_UpdateBatch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_CancelBatch_Proxy(
    IRecordset __RPC_FAR * This,
    /* [defaultvalue][optional][in] */ AffectEnum AffectRecords);


void __RPC_STUB IRecordset_CancelBatch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_CursorLocation_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ CursorLocationEnum __RPC_FAR *plCursorLoc);


void __RPC_STUB IRecordset_get_CursorLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IRecordset_put_CursorLocation_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ CursorLocationEnum plCursorLoc);


void __RPC_STUB IRecordset_put_CursorLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_NextRecordset_Proxy(
    IRecordset __RPC_FAR * This,
    /* [optional][out] */ VARIANT __RPC_FAR *RecordsAffected,
    /* [retval][out] */ /* external definition not present */ _Recordset __RPC_FAR *__RPC_FAR *ppiRs);


void __RPC_STUB IRecordset_NextRecordset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_Supports_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ CursorOptionEnum CursorOptions,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pb);


void __RPC_STUB IRecordset_Supports_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_Collect_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ VARIANT Index,
    /* [retval][out] */ VARIANT __RPC_FAR *pvar);


void __RPC_STUB IRecordset_get_Collect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IRecordset_put_Collect_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ VARIANT Index,
    /* [in] */ VARIANT pvar);


void __RPC_STUB IRecordset_put_Collect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_MarshalOptions_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ MarshalOptionsEnum __RPC_FAR *peMarshal);


void __RPC_STUB IRecordset_get_MarshalOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IRecordset_put_MarshalOptions_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ MarshalOptionsEnum peMarshal);


void __RPC_STUB IRecordset_put_MarshalOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_Find_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ BSTR Criteria,
    /* [defaultvalue][optional][in] */ long SkipRecords,
    /* [defaultvalue][optional][in] */ SearchDirectionEnum SearchDirection,
    /* [optional][in] */ VARIANT Start);


void __RPC_STUB IRecordset_Find_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_Cancel_Proxy(
    IRecordset __RPC_FAR * This);


void __RPC_STUB IRecordset_Cancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_DataSource_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppunkDataSource);


void __RPC_STUB IRecordset_get_DataSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propputref][id] */ HRESULT STDMETHODCALLTYPE IRecordset_putref_DataSource_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *ppunkDataSource);


void __RPC_STUB IRecordset_putref_DataSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_xxSave_Proxy(
    IRecordset __RPC_FAR * This,
    /* [defaultvalue][optional][in] */ BSTR FileName,
    /* [defaultvalue][optional][in] */ PersistFormatEnum PersistFormat);


void __RPC_STUB IRecordset_xxSave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_ActiveCommand_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppCmd);


void __RPC_STUB IRecordset_get_ActiveCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IRecordset_put_StayInSync_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL pbStayInSync);


void __RPC_STUB IRecordset_put_StayInSync_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_StayInSync_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbStayInSync);


void __RPC_STUB IRecordset_get_StayInSync_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_GetString_Proxy(
    IRecordset __RPC_FAR * This,
    /* [defaultvalue][optional][in] */ StringFormatEnum StringFormat,
    /* [defaultvalue][optional][in] */ long NumRows,
    /* [defaultvalue][optional][in] */ BSTR ColumnDelimeter,
    /* [defaultvalue][optional][in] */ BSTR RowDelimeter,
    /* [defaultvalue][optional][in] */ BSTR NullExpr,
    /* [retval][out] */ BSTR __RPC_FAR *pRetString);


void __RPC_STUB IRecordset_GetString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_DataMember_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrDataMember);


void __RPC_STUB IRecordset_get_DataMember_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IRecordset_put_DataMember_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ BSTR pbstrDataMember);


void __RPC_STUB IRecordset_put_DataMember_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_CompareBookmarks_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ VARIANT Bookmark1,
    /* [in] */ VARIANT Bookmark2,
    /* [retval][out] */ CompareEnum __RPC_FAR *pCompare);


void __RPC_STUB IRecordset_CompareBookmarks_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_Clone_Proxy(
    IRecordset __RPC_FAR * This,
    /* [defaultvalue][optional][in] */ LockTypeEnum LockType,
    /* [retval][out] */ /* external definition not present */ _Recordset __RPC_FAR *__RPC_FAR *ppvObject);


void __RPC_STUB IRecordset_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_Resync_Proxy(
    IRecordset __RPC_FAR * This,
    /* [defaultvalue][optional][in] */ AffectEnum AffectRecords,
    /* [defaultvalue][optional][in] */ ResyncEnum ResyncValues);


void __RPC_STUB IRecordset_Resync_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_Seek_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ VARIANT KeyValues,
    /* [defaultvalue][optional][in] */ SeekEnum SeekOption);


void __RPC_STUB IRecordset_Seek_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IRecordset_put_Index_Proxy(
    IRecordset __RPC_FAR * This,
    /* [in] */ BSTR pbstrIndex);


void __RPC_STUB IRecordset_put_Index_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRecordset_get_Index_Proxy(
    IRecordset __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrIndex);


void __RPC_STUB IRecordset_get_Index_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRecordset_Save_Proxy(
    IRecordset __RPC_FAR * This,
    /* [optional][in] */ VARIANT Destination,
    /* [defaultvalue][optional][in] */ PersistFormatEnum PersistFormat);


void __RPC_STUB IRecordset_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRecordset_INTERFACE_DEFINED__ */


#ifndef __ICommand_INTERFACE_DEFINED__
#define __ICommand_INTERFACE_DEFINED__

/* interface ICommand */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_ICommand;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("A0FA3E07-F428-490E-814D-1174F3946351")
    ICommand : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Properties(
            /* [retval][out] */ /* external definition not present */ Properties __RPC_FAR *__RPC_FAR *pVal) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveConnection(
            /* [retval][out] */ /* external definition not present */ _Connection __RPC_FAR *__RPC_FAR *ppvObject) = 0;

        virtual /* [propputref][id] */ HRESULT STDMETHODCALLTYPE putref_ActiveConnection(
            /* [in] */ /* external definition not present */ _Connection __RPC_FAR *ppvObject) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_ActiveConnection(
            /* [in] */ VARIANT ppvObject) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_CommandText(
            /* [retval][out] */ BSTR __RPC_FAR *pbstr) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_CommandText(
            /* [in] */ BSTR pbstr) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_CommandTimeout(
            /* [retval][out] */ long __RPC_FAR *pl) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_CommandTimeout(
            /* [in] */ long pl) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Prepared(
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pfPrepared) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Prepared(
            /* [in] */ VARIANT_BOOL pfPrepared) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Execute(
            /* [optional][out] */ VARIANT __RPC_FAR *RecordsAffected,
            /* [optional][in] */ VARIANT __RPC_FAR *Parameters,
            /* [defaultvalue][optional][in] */ long Options,
            /* [retval][out] */ /* external definition not present */ _Recordset __RPC_FAR *__RPC_FAR *ppiRs) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateParameter(
            /* [defaultvalue][optional][in] */ BSTR Name,
            /* [defaultvalue][optional][in] */ DataTypeEnum Type,
            /* [defaultvalue][optional][in] */ ParameterDirectionEnum Direction,
            /* [defaultvalue][optional][in] */ long Size,
            /* [optional][in] */ VARIANT Value,
            /* [retval][out] */ /* external definition not present */ _Parameter __RPC_FAR *__RPC_FAR *ppiprm) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Parameters(
            /* [retval][out] */ /* external definition not present */ Parameters __RPC_FAR *__RPC_FAR *ppvObject) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_CommandType(
            /* [in] */ CommandTypeEnum plCmdType) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_CommandType(
            /* [retval][out] */ CommandTypeEnum __RPC_FAR *plCmdType) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Name(
            /* [retval][out] */ BSTR __RPC_FAR *pbstrName) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Name(
            /* [in] */ BSTR pbstrName) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_State(
            /* [retval][out] */ long __RPC_FAR *plObjState) = 0;

        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Cancel( void) = 0;

        virtual /* [propputref][id] */ HRESULT STDMETHODCALLTYPE putref_CommandStream(
            /* [in] */ IDispatch __RPC_FAR *pvStream) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_CommandStream(
            /* [retval][out] */ VARIANT __RPC_FAR *pvStream) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Dialect(
            /* [in] */ BSTR pbstrDialect) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Dialect(
            /* [retval][out] */ BSTR __RPC_FAR *pbstrDialect) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_NamedParameters(
            /* [in] */ VARIANT_BOOL pfNamedParameters) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_NamedParameters(
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pfNamedParameters) = 0;

    };

#else 	/* C style interface */

    typedef struct ICommandVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICommand __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICommand __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICommand __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICommand __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICommand __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICommand __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICommand __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )(
            ICommand __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ Properties __RPC_FAR *__RPC_FAR *pVal);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActiveConnection )(
            ICommand __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ _Connection __RPC_FAR *__RPC_FAR *ppvObject);

        /* [propputref][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_ActiveConnection )(
            ICommand __RPC_FAR * This,
            /* [in] */ /* external definition not present */ _Connection __RPC_FAR *ppvObject);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActiveConnection )(
            ICommand __RPC_FAR * This,
            /* [in] */ VARIANT ppvObject);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CommandText )(
            ICommand __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pbstr);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CommandText )(
            ICommand __RPC_FAR * This,
            /* [in] */ BSTR pbstr);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CommandTimeout )(
            ICommand __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pl);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CommandTimeout )(
            ICommand __RPC_FAR * This,
            /* [in] */ long pl);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Prepared )(
            ICommand __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pfPrepared);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Prepared )(
            ICommand __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pfPrepared);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Execute )(
            ICommand __RPC_FAR * This,
            /* [optional][out] */ VARIANT __RPC_FAR *RecordsAffected,
            /* [optional][in] */ VARIANT __RPC_FAR *Parameters,
            /* [defaultvalue][optional][in] */ long Options,
            /* [retval][out] */ /* external definition not present */ _Recordset __RPC_FAR *__RPC_FAR *ppiRs);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateParameter )(
            ICommand __RPC_FAR * This,
            /* [defaultvalue][optional][in] */ BSTR Name,
            /* [defaultvalue][optional][in] */ DataTypeEnum Type,
            /* [defaultvalue][optional][in] */ ParameterDirectionEnum Direction,
            /* [defaultvalue][optional][in] */ long Size,
            /* [optional][in] */ VARIANT Value,
            /* [retval][out] */ /* external definition not present */ _Parameter __RPC_FAR *__RPC_FAR *ppiprm);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Parameters )(
            ICommand __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ Parameters __RPC_FAR *__RPC_FAR *ppvObject);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CommandType )(
            ICommand __RPC_FAR * This,
            /* [in] */ CommandTypeEnum plCmdType);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CommandType )(
            ICommand __RPC_FAR * This,
            /* [retval][out] */ CommandTypeEnum __RPC_FAR *plCmdType);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )(
            ICommand __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrName);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Name )(
            ICommand __RPC_FAR * This,
            /* [in] */ BSTR pbstrName);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_State )(
            ICommand __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plObjState);

        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Cancel )(
            ICommand __RPC_FAR * This);

        /* [propputref][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_CommandStream )(
            ICommand __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *pvStream);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CommandStream )(
            ICommand __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pvStream);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Dialect )(
            ICommand __RPC_FAR * This,
            /* [in] */ BSTR pbstrDialect);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Dialect )(
            ICommand __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrDialect);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_NamedParameters )(
            ICommand __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pfNamedParameters);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_NamedParameters )(
            ICommand __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pfNamedParameters);

        END_INTERFACE
    } ICommandVtbl;

    interface ICommand
    {
        CONST_VTBL struct ICommandVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICommand_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICommand_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICommand_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICommand_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICommand_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICommand_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICommand_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICommand_get_Properties(This,pVal)	\
    (This)->lpVtbl -> get_Properties(This,pVal)

#define ICommand_get_ActiveConnection(This,ppvObject)	\
    (This)->lpVtbl -> get_ActiveConnection(This,ppvObject)

#define ICommand_putref_ActiveConnection(This,ppvObject)	\
    (This)->lpVtbl -> putref_ActiveConnection(This,ppvObject)

#define ICommand_put_ActiveConnection(This,ppvObject)	\
    (This)->lpVtbl -> put_ActiveConnection(This,ppvObject)

#define ICommand_get_CommandText(This,pbstr)	\
    (This)->lpVtbl -> get_CommandText(This,pbstr)

#define ICommand_put_CommandText(This,pbstr)	\
    (This)->lpVtbl -> put_CommandText(This,pbstr)

#define ICommand_get_CommandTimeout(This,pl)	\
    (This)->lpVtbl -> get_CommandTimeout(This,pl)

#define ICommand_put_CommandTimeout(This,pl)	\
    (This)->lpVtbl -> put_CommandTimeout(This,pl)

#define ICommand_get_Prepared(This,pfPrepared)	\
    (This)->lpVtbl -> get_Prepared(This,pfPrepared)

#define ICommand_put_Prepared(This,pfPrepared)	\
    (This)->lpVtbl -> put_Prepared(This,pfPrepared)

#define ICommand_Execute(This,RecordsAffected,Parameters,Options,ppiRs)	\
    (This)->lpVtbl -> Execute(This,RecordsAffected,Parameters,Options,ppiRs)

#define ICommand_CreateParameter(This,Name,Type,Direction,Size,Value,ppiprm)	\
    (This)->lpVtbl -> CreateParameter(This,Name,Type,Direction,Size,Value,ppiprm)

#define ICommand_get_Parameters(This,ppvObject)	\
    (This)->lpVtbl -> get_Parameters(This,ppvObject)

#define ICommand_put_CommandType(This,plCmdType)	\
    (This)->lpVtbl -> put_CommandType(This,plCmdType)

#define ICommand_get_CommandType(This,plCmdType)	\
    (This)->lpVtbl -> get_CommandType(This,plCmdType)

#define ICommand_get_Name(This,pbstrName)	\
    (This)->lpVtbl -> get_Name(This,pbstrName)

#define ICommand_put_Name(This,pbstrName)	\
    (This)->lpVtbl -> put_Name(This,pbstrName)

#define ICommand_get_State(This,plObjState)	\
    (This)->lpVtbl -> get_State(This,plObjState)

#define ICommand_Cancel(This)	\
    (This)->lpVtbl -> Cancel(This)

#define ICommand_putref_CommandStream(This,pvStream)	\
    (This)->lpVtbl -> putref_CommandStream(This,pvStream)

#define ICommand_get_CommandStream(This,pvStream)	\
    (This)->lpVtbl -> get_CommandStream(This,pvStream)

#define ICommand_put_Dialect(This,pbstrDialect)	\
    (This)->lpVtbl -> put_Dialect(This,pbstrDialect)

#define ICommand_get_Dialect(This,pbstrDialect)	\
    (This)->lpVtbl -> get_Dialect(This,pbstrDialect)

#define ICommand_put_NamedParameters(This,pfNamedParameters)	\
    (This)->lpVtbl -> put_NamedParameters(This,pfNamedParameters)

#define ICommand_get_NamedParameters(This,pfNamedParameters)	\
    (This)->lpVtbl -> get_NamedParameters(This,pfNamedParameters)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ICommand_get_Properties_Proxy(
    ICommand __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ Properties __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB ICommand_get_Properties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICommand_get_ActiveConnection_Proxy(
    ICommand __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ _Connection __RPC_FAR *__RPC_FAR *ppvObject);


void __RPC_STUB ICommand_get_ActiveConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propputref][id] */ HRESULT STDMETHODCALLTYPE ICommand_putref_ActiveConnection_Proxy(
    ICommand __RPC_FAR * This,
    /* [in] */ /* external definition not present */ _Connection __RPC_FAR *ppvObject);


void __RPC_STUB ICommand_putref_ActiveConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE ICommand_put_ActiveConnection_Proxy(
    ICommand __RPC_FAR * This,
    /* [in] */ VARIANT ppvObject);


void __RPC_STUB ICommand_put_ActiveConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICommand_get_CommandText_Proxy(
    ICommand __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstr);


void __RPC_STUB ICommand_get_CommandText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE ICommand_put_CommandText_Proxy(
    ICommand __RPC_FAR * This,
    /* [in] */ BSTR pbstr);


void __RPC_STUB ICommand_put_CommandText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICommand_get_CommandTimeout_Proxy(
    ICommand __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pl);


void __RPC_STUB ICommand_get_CommandTimeout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE ICommand_put_CommandTimeout_Proxy(
    ICommand __RPC_FAR * This,
    /* [in] */ long pl);


void __RPC_STUB ICommand_put_CommandTimeout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICommand_get_Prepared_Proxy(
    ICommand __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pfPrepared);


void __RPC_STUB ICommand_get_Prepared_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE ICommand_put_Prepared_Proxy(
    ICommand __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL pfPrepared);


void __RPC_STUB ICommand_put_Prepared_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE ICommand_Execute_Proxy(
    ICommand __RPC_FAR * This,
    /* [optional][out] */ VARIANT __RPC_FAR *RecordsAffected,
    /* [optional][in] */ VARIANT __RPC_FAR *Parameters,
    /* [defaultvalue][optional][in] */ long Options,
    /* [retval][out] */ /* external definition not present */ _Recordset __RPC_FAR *__RPC_FAR *ppiRs);


void __RPC_STUB ICommand_Execute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE ICommand_CreateParameter_Proxy(
    ICommand __RPC_FAR * This,
    /* [defaultvalue][optional][in] */ BSTR Name,
    /* [defaultvalue][optional][in] */ DataTypeEnum Type,
    /* [defaultvalue][optional][in] */ ParameterDirectionEnum Direction,
    /* [defaultvalue][optional][in] */ long Size,
    /* [optional][in] */ VARIANT Value,
    /* [retval][out] */ /* external definition not present */ _Parameter __RPC_FAR *__RPC_FAR *ppiprm);


void __RPC_STUB ICommand_CreateParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICommand_get_Parameters_Proxy(
    ICommand __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ Parameters __RPC_FAR *__RPC_FAR *ppvObject);


void __RPC_STUB ICommand_get_Parameters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE ICommand_put_CommandType_Proxy(
    ICommand __RPC_FAR * This,
    /* [in] */ CommandTypeEnum plCmdType);


void __RPC_STUB ICommand_put_CommandType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICommand_get_CommandType_Proxy(
    ICommand __RPC_FAR * This,
    /* [retval][out] */ CommandTypeEnum __RPC_FAR *plCmdType);


void __RPC_STUB ICommand_get_CommandType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICommand_get_Name_Proxy(
    ICommand __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrName);


void __RPC_STUB ICommand_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE ICommand_put_Name_Proxy(
    ICommand __RPC_FAR * This,
    /* [in] */ BSTR pbstrName);


void __RPC_STUB ICommand_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICommand_get_State_Proxy(
    ICommand __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *plObjState);


void __RPC_STUB ICommand_get_State_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE ICommand_Cancel_Proxy(
    ICommand __RPC_FAR * This);


void __RPC_STUB ICommand_Cancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propputref][id] */ HRESULT STDMETHODCALLTYPE ICommand_putref_CommandStream_Proxy(
    ICommand __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *pvStream);


void __RPC_STUB ICommand_putref_CommandStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICommand_get_CommandStream_Proxy(
    ICommand __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pvStream);


void __RPC_STUB ICommand_get_CommandStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE ICommand_put_Dialect_Proxy(
    ICommand __RPC_FAR * This,
    /* [in] */ BSTR pbstrDialect);


void __RPC_STUB ICommand_put_Dialect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICommand_get_Dialect_Proxy(
    ICommand __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrDialect);


void __RPC_STUB ICommand_get_Dialect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE ICommand_put_NamedParameters_Proxy(
    ICommand __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL pfNamedParameters);


void __RPC_STUB ICommand_put_NamedParameters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICommand_get_NamedParameters_Proxy(
    ICommand __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pfNamedParameters);


void __RPC_STUB ICommand_get_NamedParameters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICommand_INTERFACE_DEFINED__ */


#ifndef __IConnectionAdapter_INTERFACE_DEFINED__
#define __IConnectionAdapter_INTERFACE_DEFINED__

/* interface IConnectionAdapter */
/* [unique][helpstring][dual][hidden][uuid][object] */


EXTERN_C const IID IID_IConnectionAdapter;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("BF6957E5-4714-4DF5-89E6-B50540887E9D")
    IConnectionAdapter : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct IConnectionAdapterVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IConnectionAdapter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IConnectionAdapter __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IConnectionAdapter __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IConnectionAdapter __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IConnectionAdapter __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IConnectionAdapter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IConnectionAdapter __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } IConnectionAdapterVtbl;

    interface IConnectionAdapter
    {
        CONST_VTBL struct IConnectionAdapterVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IConnectionAdapter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IConnectionAdapter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IConnectionAdapter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IConnectionAdapter_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IConnectionAdapter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IConnectionAdapter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IConnectionAdapter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IConnectionAdapter_INTERFACE_DEFINED__ */


#ifndef __ICommandAdapter_INTERFACE_DEFINED__
#define __ICommandAdapter_INTERFACE_DEFINED__

/* interface ICommandAdapter */
/* [unique][helpstring][dual][hidden][uuid][object] */


EXTERN_C const IID IID_ICommandAdapter;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("8E77C00C-0CF0-4962-8302-F1D1F9659819")
    ICommandAdapter : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct ICommandAdapterVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICommandAdapter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICommandAdapter __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICommandAdapter __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICommandAdapter __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICommandAdapter __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICommandAdapter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICommandAdapter __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } ICommandAdapterVtbl;

    interface ICommandAdapter
    {
        CONST_VTBL struct ICommandAdapterVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICommandAdapter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICommandAdapter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICommandAdapter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICommandAdapter_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICommandAdapter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICommandAdapter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICommandAdapter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICommandAdapter_INTERFACE_DEFINED__ */


#ifndef __IRecordsetAdapter_INTERFACE_DEFINED__
#define __IRecordsetAdapter_INTERFACE_DEFINED__

/* interface IRecordsetAdapter */
/* [unique][helpstring][dual][hidden][uuid][object] */


EXTERN_C const IID IID_IRecordsetAdapter;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("34C365DA-3190-403C-B9DA-57F2873CCA0C")
    IRecordsetAdapter : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct IRecordsetAdapterVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IRecordsetAdapter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IRecordsetAdapter __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IRecordsetAdapter __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IRecordsetAdapter __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IRecordsetAdapter __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IRecordsetAdapter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IRecordsetAdapter __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } IRecordsetAdapterVtbl;

    interface IRecordsetAdapter
    {
        CONST_VTBL struct IRecordsetAdapterVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IRecordsetAdapter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRecordsetAdapter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRecordsetAdapter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRecordsetAdapter_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRecordsetAdapter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRecordsetAdapter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRecordsetAdapter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRecordsetAdapter_INTERFACE_DEFINED__ */


#ifndef __IGlobals_INTERFACE_DEFINED__
#define __IGlobals_INTERFACE_DEFINED__

/* interface IGlobals */
/* [unique][helpstring][dual][uuid][object] */


EXTERN_C const IID IID_IGlobals;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("1D0FD8E1-B2B6-477F-A477-9761878C2E7A")
    IGlobals : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExportConnection(
            /* [in] */ IConnection __RPC_FAR *impl,
            /* [retval][out] */ /* external definition not present */ _Connection __RPC_FAR *__RPC_FAR *result) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExportRecordset(
            /* [in] */ IRecordset __RPC_FAR *impl,
            /* [retval][out] */ /* external definition not present */ _Recordset __RPC_FAR *__RPC_FAR *result) = 0;

        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExportCommand(
            /* [in] */ ICommand __RPC_FAR *impl,
            /* [retval][out] */ /* external definition not present */ _Command __RPC_FAR *__RPC_FAR *result) = 0;

    };

#else 	/* C style interface */

    typedef struct IGlobalsVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            IGlobals __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            IGlobals __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            IGlobals __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            IGlobals __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            IGlobals __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            IGlobals __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            IGlobals __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExportConnection )(
            IGlobals __RPC_FAR * This,
            /* [in] */ IConnection __RPC_FAR *impl,
            /* [retval][out] */ /* external definition not present */ _Connection __RPC_FAR *__RPC_FAR *result);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExportRecordset )(
            IGlobals __RPC_FAR * This,
            /* [in] */ IRecordset __RPC_FAR *impl,
            /* [retval][out] */ /* external definition not present */ _Recordset __RPC_FAR *__RPC_FAR *result);

        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExportCommand )(
            IGlobals __RPC_FAR * This,
            /* [in] */ ICommand __RPC_FAR *impl,
            /* [retval][out] */ /* external definition not present */ _Command __RPC_FAR *__RPC_FAR *result);

        END_INTERFACE
    } IGlobalsVtbl;

    interface IGlobals
    {
        CONST_VTBL struct IGlobalsVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define IGlobals_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGlobals_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGlobals_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGlobals_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IGlobals_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IGlobals_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IGlobals_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IGlobals_ExportConnection(This,impl,result)	\
    (This)->lpVtbl -> ExportConnection(This,impl,result)

#define IGlobals_ExportRecordset(This,impl,result)	\
    (This)->lpVtbl -> ExportRecordset(This,impl,result)

#define IGlobals_ExportCommand(This,impl,result)	\
    (This)->lpVtbl -> ExportCommand(This,impl,result)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGlobals_ExportConnection_Proxy(
    IGlobals __RPC_FAR * This,
    /* [in] */ IConnection __RPC_FAR *impl,
    /* [retval][out] */ /* external definition not present */ _Connection __RPC_FAR *__RPC_FAR *result);


void __RPC_STUB IGlobals_ExportConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGlobals_ExportRecordset_Proxy(
    IGlobals __RPC_FAR * This,
    /* [in] */ IRecordset __RPC_FAR *impl,
    /* [retval][out] */ /* external definition not present */ _Recordset __RPC_FAR *__RPC_FAR *result);


void __RPC_STUB IGlobals_ExportRecordset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGlobals_ExportCommand_Proxy(
    IGlobals __RPC_FAR * This,
    /* [in] */ ICommand __RPC_FAR *impl,
    /* [retval][out] */ /* external definition not present */ _Command __RPC_FAR *__RPC_FAR *result);


void __RPC_STUB IGlobals_ExportCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGlobals_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ConnectionAdapter;

#ifdef __cplusplus

class DECLSPEC_UUID("57AF83EC-E40D-484A-97FB-F9A8207202D5")
ConnectionAdapter;
#endif

EXTERN_C const CLSID CLSID_CommandAdapter;

#ifdef __cplusplus

class DECLSPEC_UUID("9674967D-95EF-40ED-BB73-1AF1506D51CF")
CommandAdapter;
#endif

EXTERN_C const CLSID CLSID_RecordsetAdapter;

#ifdef __cplusplus

class DECLSPEC_UUID("13534E37-13D6-4438-8B79-830C3D800E88")
RecordsetAdapter;
#endif

EXTERN_C const CLSID CLSID_Globals;

#ifdef __cplusplus

class DECLSPEC_UUID("E58DE534-6E51-45BF-AD8C-7E02C09B2758")
Globals;
#endif
#endif /* __ADOMapping_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
