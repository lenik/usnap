/*
                                                                  * CVI DRAFT *
    POS - Practice-Oriented Structure (System)                        Version 1
    ---------------------------------------------------------------------------
                                Power Of the Software !

    License:    POS.LCL
    See Also:   X@A LaS PoX EPFS HFVC 1/bios HAS/HAD Aipos

    Ci Virtuality Integrated,
    Copyright 1997-2003, CHINA. All rights reserved.

    File:
        Module Name:    POS Pointer
        Description:    ___________________________________________________
                        ___________________________________________________
        Version:        0.0.1
        Author:         (ZD) ZAUJ G.DANSEI
    History:
        2003-4-17       ZD|started
        2003-5-14       ZD|add the util::new_pointer forward declaration.
        2003-6-24       ZD|modify the structure, added vp16_t (for graph::edge_t).
        2003-6-29       ZD|adjust layout to conform SLIMUXA.
        2003-7-13       ZD|remove 64-bit support, and add bExisted bit.
    ---------------------------------------------------------------------------
                                                                  * CVI DRAFT *
*/



#ifndef __POINTER_INCLUDED__
#define __POINTER_INCLUDED__
#ifdef POS_CF_ONCE
#   pragma once
#endif

#include "config.h"



///////////////////////////////////////////////////////////////////////////////
//
// Forward Declaration, Macros and Constants
// ----------------------------------------------------------------------------
POS_BEGIN

#	define POINTERF_EXISTED			0x00010000
#	define POINTERF_CACHE			0x00020000
#	define POINTERF_VALUE			0x00040000
#	define POINTERF_RAWVALUE		0x00080000
#	define POINTERF_LOCK			0x00100000
#	define POINTERF_SYNC			0x00200000
#	define POINTERF_CONST			0x00400000
#	define POINTERF_VOLATILE		0x00800000
#	define POINTERF_OVERLOAD		0x01000000
#	define POINTERF_BINDVAL_		0x20000000
#	define POINTERF_BIND_			0x40000000
#	define POINTERF_COMPLEX			0x00008000
#	define POINTERF_COMPLEXMASK		0x00068000	// complexed pointer have 4 fields.

	enum pointer_type {
		pointer_pv = 0,			// void *, sizeof(void *) == cpu word
		pointer_index,			// integer index,
		pointer_rel,			// relative pointer, offset from the pointer value.
		pointer_null = 0x7FFE,		// just a null pointer.
		pointer_invalid = 0x7FFF, 	// sizeof(CPTR) = 4, other value is invalid.
		pointer_thick = 0x8000,		// multi-level pointer
		pointer_remote, 		// may be remote computer's memory
		pointer_file,			// mapped into file
		pointer_device,
		pointer_callback,
	};

	struct pointer_t;

	namespace pointer {
		struct thick_t;		// ptr: multi-level pv-pointer or Pointer-pointer.
		struct remote_t;	// ptr: resident on remote computer
		struct file_t;		// ptr: mapped into file
		struct device_t;	// ptr: mapped into device
		struct callback_t;	// ptr: dynamics data, by calling I/O callbacks.
	}

	namespace ab {
		typedef pointer_t		    vP;
		typedef pointer::thick_t	tP;
		typedef pointer::remote_t	rP;
		typedef pointer::file_t		fP;
		typedef pointer::device_t	dP;
		//typedef pointer::callback_t	xP;
	} // pos:ab:

	namespace util {
		// forward declaration for follow pointer_t::friend.
		inline pointer_t *new_pointer(const u32_t hdr, const size_t bufsize);
	};

POS_END



// Header files to use
#include "variant.h"

///////////////////////////////////////////////////////////////////////////////
//
// Prototypes
// ----------------------------------------------------------------------------
#include "config/alignment_begin.h"
POS_BEGIN
    // flags;type | pv/complex* | (cache_t*) | PVT-padded
    struct pointer_t {
	    union {
		    u32_t hdr;
		    union {
			    struct {
				    u16_t type;
				    u16_t flags;
			    };
			    struct {
				    int _type_pad: 15;
				    int bComplex: 1;

				    //
				    int b_res1: 1;

				    // the buffer (or the target) is existed, so it can be indexed to.
				    int bExisted: 1;

				    // enable cache buffer into local memory, use _cache() to get the cache.
				    int bCache: 1;

				    // the buffer is constant. constant pointer can be optimized.
				    int bConst: 1;

				    // the buffer is volatiled, generally it shouldn't be cached.
				    int bVolatile: 1;

				    // partial overload for the buffer, or for the cache.
				    // invalid if not bInfo.
				    int bOverload: 1;

				    // the value for pointer is available, retrieved by _val().
				    int bValue: 1;

				    // value has no header, var_t::_vt only. (like bdt/agg items)
				    int bRawValue: 1;

				    // SLIMUAAX, the pointer is synchoronized
				    int bSync: 1;

				    // the buffer is locked.
				    int bLock: 1;

				    // object is invalid. e.g. wrong format, expired, etc.
				    int bInvalid: 1;

				    // object is marked
				    int bMark: 1;

				    // reserved for user.
				    int bUser: 1;

				    // shall release the buffer.
				    int bBindVal_: 1;

				    // shall release the struct, WARN: not include the pointed buffer.
				    // when PVT::bPointer, the Pointer will be released if PVT::bBind_.
				    int bBind_: 1;

				    int _res2: 1;
			    };
		    };
	    };

	    // ----------------------------------------------------------------------
	    // predefined pointer type
	    // {
		    struct thick_t {
			    void *		m_pv;
			    // a thick pointer is multi-level, each u32_t is a pointer_t::header,
			    // from the outermost to the innermost. so "volatile char * const ** const" is:
			    //   [const]->[ ]->[const]->[volatile]->0
			    u32_t *		m_pv_detail;
		    };
		    struct remote_t {
			    u32_t flags;
			    asz_ct name;		// remote computer name (or other resource name)
			    union {
				    u32_t ipv4;	// IPv4 address
				    struct {
					    u32_t dw[4];
				    } ipv6;		// IPv6 (128-bit) address
			    };
			    // pointer information place holder
			    void *remote_ptr;	// virtual address residented on remote computer.
		    };
		    struct file_t {
			    u32_t flags;
			    asz_ct name;		// file name (in Windows, this may also be device file name.)
			    asz_ct subname;		// this may be stream name of specified file.
			    HANDLE handle;		// opened file handle
			    size_t offset;		// offset from begining
			    void *map_virtual;	// virtual address to file mapping.
		    };
		    struct device_t {
			    u32_t flags;
			    asz_ct name;		// device name
			    u32_t ports[4];		// ports selected
			    HANDLE handle;		// device handle
			    void *map_virtual;	// virtual address mapped
		    };
		    struct callback_t {
			    // flags may include:
			    //	bReentrant: 1;	// threads-safe
			    //	bCdecl: 1;	// cdecl call protocol
			    u32_t flags;
			    u8_t (_stdcall *_read_byte)(void *p);
			    u8_t (_stdcall *_write_byte)(void *p, u8_t b);
			    size_t (_stdcall *_read_bytes)(void *p, u8_t *pbuf, size_t bytes);
			    size_t (_stdcall *_write_bytes)(void *p, u8_t *pbuf, size_t bytes);
		    };
	    // } predefined pointer type

	    struct _ptr_cache_t {
		    union {
			    u32_t flags;
			    struct {
				    int bCached: 1;		// when bCached ASSERT(!bLocalDirty && !bRemoteDirty)
				    int bLocalDirty: 1;	// dirty of cache buffer on local memory
				    int bRemoteDirty: 1;	// dirty of original buffer
				    int bPartialCache: 1;	// is partial cache started from dwPartialOffset
			    };
		    };
		    void *pCached;
		    u32_t size;
		    u32_t dwPartialOffset;
	    };

	    union {
		    u32_t		_index;
		    i32_t		_rel;
		    void *		_pv;		// pointer_pv only: the very pointer to buffer
		    thick_t *	_thick;
		    remote_t *	_remote;
		    file_t *	_file;
		    device_t *	_device;
		    callback_t *	_callback;
	    };

	    inline void *_0() const { return (void *)this; }
	    inline void *_4() const { return (void *)((u8_t *)this + 4); }
	    inline operator void *() const { return _4(); }
	    // such as thick, remote pointer called complex pointer.
	    inline _ptr_cache_t *&_cache() const {
		    POS_ASSERT(bCache);
		    return *(_ptr_cache_t **)((u8_t *)this + 8);
	    }
	    inline var_t *_val() const {
		    POS_ASSERT(bValue);
		    return (var_t *)((u8_t *)this + (bCache ? 12 : 8));
	    }
	    inline var_t::_vt *_raw() const {
		    POS_ASSERT(bValue);
		    if (bRawValue) {
			    return (var_t::_vt *)((u8_t *)this + (bCache ? 12 : 8));
		    }
		    return ((var_t *)((u8_t *)this + (bCache ? 12 : 8)))->_body();
	    }

	    inline void _release(const bool _destroy_self = false) {
		    if (!bBind_) {
			    if (!bBindVal_) {
				    if (_pv) {
					    // when POINTER_COMPLEX(0x8000) bit was set, the type specific info
					    // will be destroyed, however, pv in that specfic info won't destroy.
					    delete _pv;
				    }
			    }
			    if (bCache) {
				    delete _cache();
			    }
			    if (bValue) {
				    if (!bRawValue) {
					    _val()->_free();
				    } // else: WARN!! the "agg" should noticed for release.
			    }
		    }
		    if (_destroy_self) delete (void *)this;
	    }
	    inline void _free() { _release(true); }
	    // the constructor/destructor are commented out,
	    // so pointer_t can embedded into general C/C++ struct.
	    // caller should remember to call release() after use it.
	    /*
		    ~pointer_t() { if (bBind_) release(FALSE); }
		    pointer_t(const u32_t hdr, void *pv = NULL)
			    : hdr(hdr), m_pv(pv), _info(NULL), _cache(NULL) {
			    alloc_site();
		    }
		    pointer_t() : hdr(POINTERF_AUTO | pointer_pv), m_pv(NULL), _info(NULL), _cache(NULL) {}
	    */

    protected:
	    friend inline pointer_t *util::new_pointer(const u32_t hdr, const size_t bufsize);
	    // !! DON'T CALL THIS MORE THAN ONCE !!
	    inline void _init_complex() {
		    if (!bBind_) {
			    if (bComplex) _pv/* * */;
			    if (bCache) {
				    _cache() = new _ptr_cache_t;
			    }
			    if (bValue) {
				    // what to do with?
			    }
		    }
	    }
    }; // pointer_t

    struct vp16_t : public pointer_t {
	    union {
		    // cache & raw
		    struct {
			    _ptr_cache_t *_cache;
			    union {
				    _v32_t	_32;
				    _v_p_t	_p;
				    pv_t	_pv;
			    };
		    } cr;
		    // no cache & raw
		    union {
			    _v32_t	_32;
			    _v64_t	_64;
			    _v_p_t	_p;
			    pv_t	_pv;
		    } nr;
		    // no cache & var
		    struct {
			    var8_t _v8;
		    } nv;
	    };
	    vp16_t(bool _bCache = false, bool _bRaw = false) {
		    bCache	= _bCache;
		    bValue	= true;
		    bRawValue = _bRaw;
	    }
    };

POS_END
#include "config/alignment_end.h"



///////////////////////////////////////////////////////////////////////////////
//
// Inline implementations & Utility functions
// ----------------------------------------------------------------------------
POS_BEGIN

POS_END

#endif



///////////////////////////////////////////////////////////////////////////////
//
// The Developing Procedure
// ----------------------------------------------------------------------------
/*
        Summary:
                _____________________________________________
                _____________________________________________
        Motivation:
                ___________________________________________________________
        Objective:
                ___________________________________________
                ___________________________________________
                ___________________________________________
        Sandbox, Problems, Warnings:
                _______________________________________
                _______________________________________
                _______________________________________
                _______________________________________
        Development:
                ___________________________________________________________
                ___________________________________________________________
                ___________________________________________________________
        References:
                _________________________________________________
        Achievement:
                ________________________________________
        Outgrowth & Babies, Abbreviations:
                _____________________________
                _____________________________
                _____________________________
        Acknowledgement:
                _____________________________________________
*/
