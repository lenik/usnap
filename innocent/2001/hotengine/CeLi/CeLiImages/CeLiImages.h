/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat Apr 21 06:15:49 2001
 */
/* Compiler settings for S:\lib\campoEngine\2DWorking\CeLi\CeLiImages\CeLiImages.idl:
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

#ifndef __CeLiImages_h__
#define __CeLiImages_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

#ifndef __ICeLIDevice_FWD_DEFINED__
#define __ICeLIDevice_FWD_DEFINED__
typedef interface ICeLIDevice ICeLIDevice;
#endif 	/* __ICeLIDevice_FWD_DEFINED__ */


#ifndef __ICeLIBits_FWD_DEFINED__
#define __ICeLIBits_FWD_DEFINED__
typedef interface ICeLIBits ICeLIBits;
#endif 	/* __ICeLIBits_FWD_DEFINED__ */


#ifndef __ICeLIBits2_FWD_DEFINED__
#define __ICeLIBits2_FWD_DEFINED__
typedef interface ICeLIBits2 ICeLIBits2;
#endif 	/* __ICeLIBits2_FWD_DEFINED__ */


#ifndef __ICeLIBitsX_FWD_DEFINED__
#define __ICeLIBitsX_FWD_DEFINED__
typedef interface ICeLIBitsX ICeLIBitsX;
#endif 	/* __ICeLIBitsX_FWD_DEFINED__ */


#ifndef __ICeLIBlocks_FWD_DEFINED__
#define __ICeLIBlocks_FWD_DEFINED__
typedef interface ICeLIBlocks ICeLIBlocks;
#endif 	/* __ICeLIBlocks_FWD_DEFINED__ */


#ifndef __CeLIDevice_FWD_DEFINED__
#define __CeLIDevice_FWD_DEFINED__

#ifdef __cplusplus
typedef class CeLIDevice CeLIDevice;
#else
typedef struct CeLIDevice CeLIDevice;
#endif /* __cplusplus */

#endif 	/* __CeLIDevice_FWD_DEFINED__ */


#ifndef __CeLIBits_FWD_DEFINED__
#define __CeLIBits_FWD_DEFINED__

#ifdef __cplusplus
typedef class CeLIBits CeLIBits;
#else
typedef struct CeLIBits CeLIBits;
#endif /* __cplusplus */

#endif 	/* __CeLIBits_FWD_DEFINED__ */


#ifndef __CeLIBits2_FWD_DEFINED__
#define __CeLIBits2_FWD_DEFINED__

#ifdef __cplusplus
typedef class CeLIBits2 CeLIBits2;
#else
typedef struct CeLIBits2 CeLIBits2;
#endif /* __cplusplus */

#endif 	/* __CeLIBits2_FWD_DEFINED__ */


#ifndef __CeLIBitsX_FWD_DEFINED__
#define __CeLIBitsX_FWD_DEFINED__

#ifdef __cplusplus
typedef class CeLIBitsX CeLIBitsX;
#else
typedef struct CeLIBitsX CeLIBitsX;
#endif /* __cplusplus */

#endif 	/* __CeLIBitsX_FWD_DEFINED__ */


#ifndef __CeLIBlocks_FWD_DEFINED__
#define __CeLIBlocks_FWD_DEFINED__

#ifdef __cplusplus
typedef class CeLIBlocks CeLIBlocks;
#else
typedef struct CeLIBlocks CeLIBlocks;
#endif /* __cplusplus */

#endif 	/* __CeLIBlocks_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );

#ifndef __ICeLIDevice_INTERFACE_DEFINED__
#define __ICeLIDevice_INTERFACE_DEFINED__

/* interface ICeLIDevice */
/* [object][helpstring][oleautomation][dual][uuid] */


EXTERN_C const IID IID_ICeLIDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4345-1200-0001-486954656368")
    ICeLIDevice : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_bitsVal(
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [retval][out] */ LONG __RPC_FAR *ret) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_bitsVal(
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ LONG newBits) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_bindHandle(
            /* [retval][out] */ LONG __RPC_FAR *ret) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_bindHandle(
            /* [in] */ LONG bindHandle) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_bitsWidth(
            /* [retval][out] */ LONG __RPC_FAR *ret) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_bitsWidth(
            /* [in] */ LONG width) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_bitsHeight(
            /* [retval][out] */ LONG __RPC_FAR *ret) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_bitsHeight(
            /* [in] */ LONG height) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_bitsPitch(
            /* [retval][out] */ LONG __RPC_FAR *ret) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_bitsPitch(
            /* [in] */ LONG pitch) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_bitsDepth(
            /* [retval][out] */ LONG __RPC_FAR *ret) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_bitsDepth(
            /* [in] */ LONG pitch) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_outLeft(
            /* [retval][out] */ LONG __RPC_FAR *ret) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_outLeft(
            /* [in] */ LONG l) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_outTop(
            /* [retval][out] */ LONG __RPC_FAR *ret) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_outTop(
            /* [in] */ LONG l) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_outWidth(
            /* [retval][out] */ LONG __RPC_FAR *ret) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_outWidth(
            /* [in] */ LONG l) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_outHeight(
            /* [retval][out] */ LONG __RPC_FAR *ret) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_outHeight(
            /* [in] */ LONG l) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_currentX(
            /* [retval][out] */ LONG __RPC_FAR *ret) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_currentX(
            /* [in] */ LONG cx) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_currentY(
            /* [retval][out] */ LONG __RPC_FAR *ret) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_currentY(
            /* [in] */ LONG cx) = 0;

        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_bitsPointer(
            /* [retval][out] */ LONG __RPC_FAR *ret) = 0;

        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_bitsPointer(
            /* [in] */ LONG newPointer) = 0;

        virtual HRESULT STDMETHODCALLTYPE outX(
            /* [in] */ LONG inX,
            /* [retval][out] */ LONG __RPC_FAR *ret) = 0;

        virtual HRESULT STDMETHODCALLTYPE outY(
            /* [in] */ LONG inY,
            /* [retval][out] */ LONG __RPC_FAR *ret) = 0;

        virtual HRESULT STDMETHODCALLTYPE inX(
            /* [in] */ LONG outX,
            /* [retval][out] */ LONG __RPC_FAR *ret) = 0;

        virtual HRESULT STDMETHODCALLTYPE inY(
            /* [in] */ LONG outY,
            /* [retval][out] */ LONG __RPC_FAR *ret) = 0;

        virtual HRESULT STDMETHODCALLTYPE getPixel(
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [retval][out] */ LONG __RPC_FAR *ret) = 0;

        virtual HRESULT STDMETHODCALLTYPE setPixel(
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ LONG color) = 0;

        virtual HRESULT STDMETHODCALLTYPE setLine(
            /* [in] */ LONG x0,
            /* [in] */ LONG y0,
            /* [in] */ LONG x1,
            /* [in] */ LONG y1,
            /* [in] */ LONG color) = 0;

        virtual HRESULT STDMETHODCALLTYPE setRect(
            /* [in] */ LONG x0,
            /* [in] */ LONG y0,
            /* [in] */ LONG x1,
            /* [in] */ LONG y1,
            /* [in] */ LONG color) = 0;

        virtual HRESULT STDMETHODCALLTYPE moveTo(
            /* [in] */ LONG x,
            /* [in] */ LONG y) = 0;

        virtual HRESULT STDMETHODCALLTYPE lineTo(
            /* [in] */ LONG x,
            /* [in] */ LONG y) = 0;

        virtual HRESULT STDMETHODCALLTYPE lineStepTo(
            /* [in] */ LONG dx,
            /* [in] */ LONG dy) = 0;

    };

#else 	/* C style interface */

    typedef struct ICeLIDeviceVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICeLIDevice __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICeLIDevice __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICeLIDevice __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_bitsVal )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [retval][out] */ LONG __RPC_FAR *ret);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_bitsVal )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ LONG newBits);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_bindHandle )(
            ICeLIDevice __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *ret);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_bindHandle )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ LONG bindHandle);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_bitsWidth )(
            ICeLIDevice __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *ret);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_bitsWidth )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ LONG width);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_bitsHeight )(
            ICeLIDevice __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *ret);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_bitsHeight )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ LONG height);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_bitsPitch )(
            ICeLIDevice __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *ret);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_bitsPitch )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ LONG pitch);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_bitsDepth )(
            ICeLIDevice __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *ret);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_bitsDepth )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ LONG pitch);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_outLeft )(
            ICeLIDevice __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *ret);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_outLeft )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ LONG l);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_outTop )(
            ICeLIDevice __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *ret);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_outTop )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ LONG l);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_outWidth )(
            ICeLIDevice __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *ret);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_outWidth )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ LONG l);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_outHeight )(
            ICeLIDevice __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *ret);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_outHeight )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ LONG l);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_currentX )(
            ICeLIDevice __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *ret);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_currentX )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ LONG cx);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_currentY )(
            ICeLIDevice __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *ret);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_currentY )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ LONG cx);

        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_bitsPointer )(
            ICeLIDevice __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *ret);

        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_bitsPointer )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ LONG newPointer);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *outX )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ LONG inX,
            /* [retval][out] */ LONG __RPC_FAR *ret);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *outY )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ LONG inY,
            /* [retval][out] */ LONG __RPC_FAR *ret);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *inX )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ LONG outX,
            /* [retval][out] */ LONG __RPC_FAR *ret);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *inY )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ LONG outY,
            /* [retval][out] */ LONG __RPC_FAR *ret);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getPixel )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [retval][out] */ LONG __RPC_FAR *ret);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setPixel )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ LONG color);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setLine )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ LONG x0,
            /* [in] */ LONG y0,
            /* [in] */ LONG x1,
            /* [in] */ LONG y1,
            /* [in] */ LONG color);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setRect )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ LONG x0,
            /* [in] */ LONG y0,
            /* [in] */ LONG x1,
            /* [in] */ LONG y1,
            /* [in] */ LONG color);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *moveTo )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *lineTo )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *lineStepTo )(
            ICeLIDevice __RPC_FAR * This,
            /* [in] */ LONG dx,
            /* [in] */ LONG dy);

        END_INTERFACE
    } ICeLIDeviceVtbl;

    interface ICeLIDevice
    {
        CONST_VTBL struct ICeLIDeviceVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICeLIDevice_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICeLIDevice_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICeLIDevice_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICeLIDevice_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICeLIDevice_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICeLIDevice_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICeLIDevice_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICeLIDevice_get_bitsVal(This,x,y,ret)	\
    (This)->lpVtbl -> get_bitsVal(This,x,y,ret)

#define ICeLIDevice_put_bitsVal(This,x,y,newBits)	\
    (This)->lpVtbl -> put_bitsVal(This,x,y,newBits)

#define ICeLIDevice_get_bindHandle(This,ret)	\
    (This)->lpVtbl -> get_bindHandle(This,ret)

#define ICeLIDevice_put_bindHandle(This,bindHandle)	\
    (This)->lpVtbl -> put_bindHandle(This,bindHandle)

#define ICeLIDevice_get_bitsWidth(This,ret)	\
    (This)->lpVtbl -> get_bitsWidth(This,ret)

#define ICeLIDevice_put_bitsWidth(This,width)	\
    (This)->lpVtbl -> put_bitsWidth(This,width)

#define ICeLIDevice_get_bitsHeight(This,ret)	\
    (This)->lpVtbl -> get_bitsHeight(This,ret)

#define ICeLIDevice_put_bitsHeight(This,height)	\
    (This)->lpVtbl -> put_bitsHeight(This,height)

#define ICeLIDevice_get_bitsPitch(This,ret)	\
    (This)->lpVtbl -> get_bitsPitch(This,ret)

#define ICeLIDevice_put_bitsPitch(This,pitch)	\
    (This)->lpVtbl -> put_bitsPitch(This,pitch)

#define ICeLIDevice_get_bitsDepth(This,ret)	\
    (This)->lpVtbl -> get_bitsDepth(This,ret)

#define ICeLIDevice_put_bitsDepth(This,pitch)	\
    (This)->lpVtbl -> put_bitsDepth(This,pitch)

#define ICeLIDevice_get_outLeft(This,ret)	\
    (This)->lpVtbl -> get_outLeft(This,ret)

#define ICeLIDevice_put_outLeft(This,l)	\
    (This)->lpVtbl -> put_outLeft(This,l)

#define ICeLIDevice_get_outTop(This,ret)	\
    (This)->lpVtbl -> get_outTop(This,ret)

#define ICeLIDevice_put_outTop(This,l)	\
    (This)->lpVtbl -> put_outTop(This,l)

#define ICeLIDevice_get_outWidth(This,ret)	\
    (This)->lpVtbl -> get_outWidth(This,ret)

#define ICeLIDevice_put_outWidth(This,l)	\
    (This)->lpVtbl -> put_outWidth(This,l)

#define ICeLIDevice_get_outHeight(This,ret)	\
    (This)->lpVtbl -> get_outHeight(This,ret)

#define ICeLIDevice_put_outHeight(This,l)	\
    (This)->lpVtbl -> put_outHeight(This,l)

#define ICeLIDevice_get_currentX(This,ret)	\
    (This)->lpVtbl -> get_currentX(This,ret)

#define ICeLIDevice_put_currentX(This,cx)	\
    (This)->lpVtbl -> put_currentX(This,cx)

#define ICeLIDevice_get_currentY(This,ret)	\
    (This)->lpVtbl -> get_currentY(This,ret)

#define ICeLIDevice_put_currentY(This,cx)	\
    (This)->lpVtbl -> put_currentY(This,cx)

#define ICeLIDevice_get_bitsPointer(This,ret)	\
    (This)->lpVtbl -> get_bitsPointer(This,ret)

#define ICeLIDevice_put_bitsPointer(This,newPointer)	\
    (This)->lpVtbl -> put_bitsPointer(This,newPointer)

#define ICeLIDevice_outX(This,inX,ret)	\
    (This)->lpVtbl -> outX(This,inX,ret)

#define ICeLIDevice_outY(This,inY,ret)	\
    (This)->lpVtbl -> outY(This,inY,ret)

#define ICeLIDevice_inX(This,outX,ret)	\
    (This)->lpVtbl -> inX(This,outX,ret)

#define ICeLIDevice_inY(This,outY,ret)	\
    (This)->lpVtbl -> inY(This,outY,ret)

#define ICeLIDevice_getPixel(This,x,y,ret)	\
    (This)->lpVtbl -> getPixel(This,x,y,ret)

#define ICeLIDevice_setPixel(This,x,y,color)	\
    (This)->lpVtbl -> setPixel(This,x,y,color)

#define ICeLIDevice_setLine(This,x0,y0,x1,y1,color)	\
    (This)->lpVtbl -> setLine(This,x0,y0,x1,y1,color)

#define ICeLIDevice_setRect(This,x0,y0,x1,y1,color)	\
    (This)->lpVtbl -> setRect(This,x0,y0,x1,y1,color)

#define ICeLIDevice_moveTo(This,x,y)	\
    (This)->lpVtbl -> moveTo(This,x,y)

#define ICeLIDevice_lineTo(This,x,y)	\
    (This)->lpVtbl -> lineTo(This,x,y)

#define ICeLIDevice_lineStepTo(This,dx,dy)	\
    (This)->lpVtbl -> lineStepTo(This,dx,dy)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_get_bitsVal_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [in] */ LONG x,
    /* [in] */ LONG y,
    /* [retval][out] */ LONG __RPC_FAR *ret);


void __RPC_STUB ICeLIDevice_get_bitsVal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_put_bitsVal_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [in] */ LONG x,
    /* [in] */ LONG y,
    /* [in] */ LONG newBits);


void __RPC_STUB ICeLIDevice_put_bitsVal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_get_bindHandle_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *ret);


void __RPC_STUB ICeLIDevice_get_bindHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_put_bindHandle_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [in] */ LONG bindHandle);


void __RPC_STUB ICeLIDevice_put_bindHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_get_bitsWidth_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *ret);


void __RPC_STUB ICeLIDevice_get_bitsWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_put_bitsWidth_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [in] */ LONG width);


void __RPC_STUB ICeLIDevice_put_bitsWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_get_bitsHeight_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *ret);


void __RPC_STUB ICeLIDevice_get_bitsHeight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_put_bitsHeight_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [in] */ LONG height);


void __RPC_STUB ICeLIDevice_put_bitsHeight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_get_bitsPitch_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *ret);


void __RPC_STUB ICeLIDevice_get_bitsPitch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_put_bitsPitch_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [in] */ LONG pitch);


void __RPC_STUB ICeLIDevice_put_bitsPitch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_get_bitsDepth_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *ret);


void __RPC_STUB ICeLIDevice_get_bitsDepth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_put_bitsDepth_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [in] */ LONG pitch);


void __RPC_STUB ICeLIDevice_put_bitsDepth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_get_outLeft_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *ret);


void __RPC_STUB ICeLIDevice_get_outLeft_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_put_outLeft_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [in] */ LONG l);


void __RPC_STUB ICeLIDevice_put_outLeft_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_get_outTop_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *ret);


void __RPC_STUB ICeLIDevice_get_outTop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_put_outTop_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [in] */ LONG l);


void __RPC_STUB ICeLIDevice_put_outTop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_get_outWidth_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *ret);


void __RPC_STUB ICeLIDevice_get_outWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_put_outWidth_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [in] */ LONG l);


void __RPC_STUB ICeLIDevice_put_outWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_get_outHeight_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *ret);


void __RPC_STUB ICeLIDevice_get_outHeight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_put_outHeight_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [in] */ LONG l);


void __RPC_STUB ICeLIDevice_put_outHeight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_get_currentX_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *ret);


void __RPC_STUB ICeLIDevice_get_currentX_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_put_currentX_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [in] */ LONG cx);


void __RPC_STUB ICeLIDevice_put_currentX_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_get_currentY_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *ret);


void __RPC_STUB ICeLIDevice_get_currentY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_put_currentY_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [in] */ LONG cx);


void __RPC_STUB ICeLIDevice_put_currentY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_get_bitsPointer_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *ret);


void __RPC_STUB ICeLIDevice_get_bitsPointer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE ICeLIDevice_put_bitsPointer_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [in] */ LONG newPointer);


void __RPC_STUB ICeLIDevice_put_bitsPointer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICeLIDevice_outX_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [in] */ LONG inX,
    /* [retval][out] */ LONG __RPC_FAR *ret);


void __RPC_STUB ICeLIDevice_outX_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICeLIDevice_outY_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [in] */ LONG inY,
    /* [retval][out] */ LONG __RPC_FAR *ret);


void __RPC_STUB ICeLIDevice_outY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICeLIDevice_inX_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [in] */ LONG outX,
    /* [retval][out] */ LONG __RPC_FAR *ret);


void __RPC_STUB ICeLIDevice_inX_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICeLIDevice_inY_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [in] */ LONG outY,
    /* [retval][out] */ LONG __RPC_FAR *ret);


void __RPC_STUB ICeLIDevice_inY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICeLIDevice_getPixel_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [in] */ LONG x,
    /* [in] */ LONG y,
    /* [retval][out] */ LONG __RPC_FAR *ret);


void __RPC_STUB ICeLIDevice_getPixel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICeLIDevice_setPixel_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [in] */ LONG x,
    /* [in] */ LONG y,
    /* [in] */ LONG color);


void __RPC_STUB ICeLIDevice_setPixel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICeLIDevice_setLine_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [in] */ LONG x0,
    /* [in] */ LONG y0,
    /* [in] */ LONG x1,
    /* [in] */ LONG y1,
    /* [in] */ LONG color);


void __RPC_STUB ICeLIDevice_setLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICeLIDevice_setRect_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [in] */ LONG x0,
    /* [in] */ LONG y0,
    /* [in] */ LONG x1,
    /* [in] */ LONG y1,
    /* [in] */ LONG color);


void __RPC_STUB ICeLIDevice_setRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICeLIDevice_moveTo_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [in] */ LONG x,
    /* [in] */ LONG y);


void __RPC_STUB ICeLIDevice_moveTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICeLIDevice_lineTo_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [in] */ LONG x,
    /* [in] */ LONG y);


void __RPC_STUB ICeLIDevice_lineTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICeLIDevice_lineStepTo_Proxy(
    ICeLIDevice __RPC_FAR * This,
    /* [in] */ LONG dx,
    /* [in] */ LONG dy);


void __RPC_STUB ICeLIDevice_lineStepTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICeLIDevice_INTERFACE_DEFINED__ */


#ifndef __ICeLIBits_INTERFACE_DEFINED__
#define __ICeLIBits_INTERFACE_DEFINED__

/* interface ICeLIBits */
/* [object][helpstring][oleautomation][dual][uuid] */


EXTERN_C const IID IID_ICeLIBits;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4345-1201-0001-486954656368")
    ICeLIBits : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Mosaic( void) = 0;

    };

#else 	/* C style interface */

    typedef struct ICeLIBitsVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICeLIBits __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICeLIBits __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICeLIBits __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICeLIBits __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICeLIBits __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICeLIBits __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICeLIBits __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Mosaic )(
            ICeLIBits __RPC_FAR * This);

        END_INTERFACE
    } ICeLIBitsVtbl;

    interface ICeLIBits
    {
        CONST_VTBL struct ICeLIBitsVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICeLIBits_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICeLIBits_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICeLIBits_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICeLIBits_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICeLIBits_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICeLIBits_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICeLIBits_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICeLIBits_Mosaic(This)	\
    (This)->lpVtbl -> Mosaic(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ICeLIBits_Mosaic_Proxy(
    ICeLIBits __RPC_FAR * This);


void __RPC_STUB ICeLIBits_Mosaic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICeLIBits_INTERFACE_DEFINED__ */


#ifndef __ICeLIBits2_INTERFACE_DEFINED__
#define __ICeLIBits2_INTERFACE_DEFINED__

/* interface ICeLIBits2 */
/* [object][helpstring][oleautomation][dual][uuid] */


EXTERN_C const IID IID_ICeLIBits2;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4345-1202-0001-486954656368")
    ICeLIBits2 : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Blit(
            /* [in] */ ICeLIDevice __RPC_FAR *cldDest,
            /* [in] */ LONG destx,
            /* [in] */ LONG desty,
            /* [in] */ LONG width,
            /* [in] */ LONG height,
            /* [in] */ LONG Rop) = 0;

    };

#else 	/* C style interface */

    typedef struct ICeLIBits2Vtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICeLIBits2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICeLIBits2 __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICeLIBits2 __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICeLIBits2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICeLIBits2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICeLIBits2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICeLIBits2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Blit )(
            ICeLIBits2 __RPC_FAR * This,
            /* [in] */ ICeLIDevice __RPC_FAR *cldDest,
            /* [in] */ LONG destx,
            /* [in] */ LONG desty,
            /* [in] */ LONG width,
            /* [in] */ LONG height,
            /* [in] */ LONG Rop);

        END_INTERFACE
    } ICeLIBits2Vtbl;

    interface ICeLIBits2
    {
        CONST_VTBL struct ICeLIBits2Vtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICeLIBits2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICeLIBits2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICeLIBits2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICeLIBits2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICeLIBits2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICeLIBits2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICeLIBits2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICeLIBits2_Blit(This,cldDest,destx,desty,width,height,Rop)	\
    (This)->lpVtbl -> Blit(This,cldDest,destx,desty,width,height,Rop)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ICeLIBits2_Blit_Proxy(
    ICeLIBits2 __RPC_FAR * This,
    /* [in] */ ICeLIDevice __RPC_FAR *cldDest,
    /* [in] */ LONG destx,
    /* [in] */ LONG desty,
    /* [in] */ LONG width,
    /* [in] */ LONG height,
    /* [in] */ LONG Rop);


void __RPC_STUB ICeLIBits2_Blit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICeLIBits2_INTERFACE_DEFINED__ */


#ifndef __ICeLIBitsX_INTERFACE_DEFINED__
#define __ICeLIBitsX_INTERFACE_DEFINED__

/* interface ICeLIBitsX */
/* [object][helpstring][oleautomation][dual][uuid] */


EXTERN_C const IID IID_ICeLIBitsX;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4345-1203-0001-486954656368")
    ICeLIBitsX : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct ICeLIBitsXVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICeLIBitsX __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICeLIBitsX __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICeLIBitsX __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICeLIBitsX __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICeLIBitsX __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICeLIBitsX __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICeLIBitsX __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } ICeLIBitsXVtbl;

    interface ICeLIBitsX
    {
        CONST_VTBL struct ICeLIBitsXVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICeLIBitsX_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICeLIBitsX_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICeLIBitsX_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICeLIBitsX_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICeLIBitsX_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICeLIBitsX_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICeLIBitsX_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICeLIBitsX_INTERFACE_DEFINED__ */


#ifndef __ICeLIBlocks_INTERFACE_DEFINED__
#define __ICeLIBlocks_INTERFACE_DEFINED__

/* interface ICeLIBlocks */
/* [object][helpstring][oleautomation][dual][uuid] */


EXTERN_C const IID IID_ICeLIBlocks;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00000000-4345-1204-0001-486954656368")
    ICeLIBlocks : public IDispatch
    {
    public:
    };

#else 	/* C style interface */

    typedef struct ICeLIBlocksVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )(
            ICeLIBlocks __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )(
            ICeLIBlocks __RPC_FAR * This);

        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )(
            ICeLIBlocks __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )(
            ICeLIBlocks __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )(
            ICeLIBlocks __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )(
            ICeLIBlocks __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )(
            ICeLIBlocks __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);

        END_INTERFACE
    } ICeLIBlocksVtbl;

    interface ICeLIBlocks
    {
        CONST_VTBL struct ICeLIBlocksVtbl __RPC_FAR *lpVtbl;
    };



#ifdef COBJMACROS


#define ICeLIBlocks_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICeLIBlocks_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICeLIBlocks_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICeLIBlocks_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICeLIBlocks_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICeLIBlocks_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICeLIBlocks_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICeLIBlocks_INTERFACE_DEFINED__ */



#ifndef __CeLiImagesLib_LIBRARY_DEFINED__
#define __CeLiImagesLib_LIBRARY_DEFINED__

/* library CeLiImagesLib */
/* [helpstring][version][uuid] */


EXTERN_C const IID LIBID_CeLiImagesLib;

EXTERN_C const CLSID CLSID_CeLIDevice;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4345-1200-0002-486954656368")
CeLIDevice;
#endif

EXTERN_C const CLSID CLSID_CeLIBits;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4345-1201-0002-486954656368")
CeLIBits;
#endif

EXTERN_C const CLSID CLSID_CeLIBits2;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4345-1202-0002-486954656368")
CeLIBits2;
#endif

EXTERN_C const CLSID CLSID_CeLIBitsX;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4345-1203-0002-486954656368")
CeLIBitsX;
#endif

EXTERN_C const CLSID CLSID_CeLIBlocks;

#ifdef __cplusplus

class DECLSPEC_UUID("00000000-4345-1204-0002-486954656368")
CeLIBlocks;
#endif


#ifndef __CeLIColor_MODULE_DEFINED__
#define __CeLIColor_MODULE_DEFINED__


/* module CeLIColor */
/* [helpstring][dllname][uuid] */

/* [entry] */ HRESULT __stdcall CeLIColorRgb24Plus(
    /* [in] */ LONG c1,
    /* [in] */ LONG c2,
    /* [retval][out] */ LONG __RPC_FAR *ret);

#endif /* __CeLIColor_MODULE_DEFINED__ */
#endif /* __CeLiImagesLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
