
#pragma once

#ifndef _STARTINC_H
#define _STARTINC_H

/*
	_STARTINC_
		NODISABLE_WARNINGS
		NOCOMUTIL			comutil.h comsupp.lib
		NOSTD
		NOMACROS
		NOINLINES			__elem, __reference
		NOASSERT			ASSERT, DBGPOP
		NOSP				(Safe procedure)
		NOSAFE				SAFE_RELEASE, SAFE_DELETE, SAFE_DELETE_ARRAY
*/


#ifndef _STARTINC_NODISABLE_WARNINGS
#	pragma warning(disable: 4100)		// unreferenced formal parameter
#	pragma warning(disable: 4127)		// condition is constant
#	pragma warning(disable: 4245)		// signed/unsigned mismatch
#	pragma warning(disable: 4786)		// symbol long in debug info
#	pragma warning(disable: 4530)		// exception with /GX
#endif


#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <windows.h>
#include <windowsx.h>
#include <commdlg.h>
#include <tlhelp32.h>

#ifndef _STARTINC_NOCOMUTIL
#	pragma comment(lib, "comsupp.lib")
#	include <comutil.h>
#endif


#ifndef _STARTINC_NOSTD
#	include <iostream>
#	include <strstream>
#	include <vector>
#	include <list>
#	include <utility>

#	define __std	using namespace std

	template<class _Ty>
	_Ty *__elem(std::list<_Ty>& lst, int index) {
		std::list<_Ty>::iterator it;
		if (index >= lst.size()) return NULL;
		for (it = lst.begin(); index > 0; index--) {
			++it;
			if (it == lst.end()) {
				//__assume(false);
				return NULL;
			}
		}
		return &*it;
	}
#endif // _STARTINC_NOSTD

#ifndef _STARTINC_NOMACROS

#	ifndef _STARTINC_NOASSERT
#		ifdef _DEBUG
#			ifndef ASSERT
#				include <assert.h>
#				define ASSERT(x)	assert(x)
#			endif //ASSERT
#			ifndef VERIFY
#				include <assert.h>
#				define VERIFY(x)	assert(x)
#			endif
#			ifndef DBGPOP
#				define DBGPOP(s)	::MessageBox(NULL, s, _T("DBGPOP"), MB_OK)
#			endif //DBGPOP
#		else //_DEBUG
#			ifndef ASSERT
#				define ASSERT(x)
#			endif
#			ifndef VERIFY
#				define VERIFY(x)	x
#			endif
#			ifndef DBGPOP
#				define DBGPOP(s)
#			endif
#		endif //_DEBUG
#	endif // _STARTINC_NOASSERT

	/*
		define local function (1)

		... {
			_DEF(int, _add)(int a, int b) {
				return a + b;
			} _AS(add)

			int x = add(3, 4); // x = 7
		} ...
	*/
#	if !defined(_DEF) && !defined(_AS)
#		define _DEF(t, id)				struct _psc_##id { t operator()
#		define _AS(name)				} name;
#	endif

	/*
		define local function (2)

		... {
			_LOCAL
		} ... "winuser.h"
	*/
#	if !defined(_LOCAL)
#		ifdef _DEBUG
#			define _VTBL_NOTIMPL(fn)											\
				virtual void (_##fn)() {										\
					int iSel = MessageBox(0, _T("pure virtual function call!"),	\
						_T(#fn), MB_ABORTRETRYIGNORE);							\
					if (iSel == IDABORT) exit(-1);								\
					if (iSel == IDIGNORE) return;								\
					if (iSel == IDRETRY) ASSERT(FALSE);							\
				}
#		else
#			define _VTBL_NOTIMPL(fn)	virtual void (_##fn)() = 0;
#		endif
#		define _VTBL_NOTIMPL_10x(fx)											\
			_VTBL_NOTIMPL(fx##0)												\
			_VTBL_NOTIMPL(fx##1)												\
			_VTBL_NOTIMPL(fx##2)												\
			_VTBL_NOTIMPL(fx##3)												\
			_VTBL_NOTIMPL(fx##4)												\
			_VTBL_NOTIMPL(fx##5)												\
			_VTBL_NOTIMPL(fx##6)												\
			_VTBL_NOTIMPL(fx##7)												\
			_VTBL_NOTIMPL(fx##8)												\
			_VTBL_NOTIMPL(fx##9)
#		define _VTBL_NOTIMPL_100x(fxx)											\
			_VTBL_NOTIMPL_10x(fxx##0)											\
			_VTBL_NOTIMPL_10x(fxx##1)											\
			_VTBL_NOTIMPL_10x(fxx##2)											\
			_VTBL_NOTIMPL_10x(fxx##3)											\
			_VTBL_NOTIMPL_10x(fxx##4)											\
			_VTBL_NOTIMPL_10x(fxx##5)											\
			_VTBL_NOTIMPL_10x(fxx##6)											\
			_VTBL_NOTIMPL_10x(fxx##7)											\
			_VTBL_NOTIMPL_10x(fxx##8)											\
			_VTBL_NOTIMPL_10x(fxx##9)
#		define _VTBL_NOTIMPL_1000x(fxxx)										\
			_VTBL_NOTIMPL_100x(fxxx##0)											\
			_VTBL_NOTIMPL_100x(fxxx##1)											\
			_VTBL_NOTIMPL_100x(fxxx##2)											\
			_VTBL_NOTIMPL_100x(fxxx##3)											\
			_VTBL_NOTIMPL_100x(fxxx##4)											\
			_VTBL_NOTIMPL_100x(fxxx##5)											\
			_VTBL_NOTIMPL_100x(fxxx##6)											\
			_VTBL_NOTIMPL_100x(fxxx##7)											\
			_VTBL_NOTIMPL_100x(fxxx##8)											\
			_VTBL_NOTIMPL_100x(fxxx##9)

		class _local_base {
		public:
			_VTBL_NOTIMPL_1000x(_Vtbl)
		};

#		define _LOCAL(fn)				class _my_local : public _local_base {	\
											virtual void _Vtbl0000()
#		define _LOCAL_AS(name)			} name

#	endif // _LOCAL

#	ifndef _INIT
#		define _INIT(name)														\
			class _psi_##name {													\
			public:																\
				inline bool _init_();											\
				_psi_##name() { _init_(); }										\
			} _psi_##name##_i;													\
			inline bool _psi_##name::_init_()
#	endif

#	ifndef _TS
#		define _TS(x)			(LPCTSTR)_bstr_t(x)
#	endif

#	ifndef __offset
#		define __offset_OFF_P			0
#		define __offset(cls, basecls)	((int) ( static_cast<basecls *>((cls *)__offset_OFF_P) ) - __offset_OFF_P )
#	endif

#	define __REF(p)						((p)->AddRef() - 1, (p)->Release())

#	ifndef _STARTINC_NOCOMUTIL
		inline int __reference(IUnknown *p) {
			p->AddRef();
			return p->Release();
		}
#	endif

#	ifndef _STARTINC_NONAMESPACE
#		define FEIY_BEGIN					namespace feiy {
#		define FEIY_END						}
#		define FEIY(x)						feiy::x
#		define _FEIY						feiy::
#	else
#		define FEIY_BEGIN
#		define FEIY_END
#		define FEIY(x)
#		define _FEIY
#	endif

#	define DEFINE_OBJ(i)				CComPtr<I##i> p##i;


#	ifndef _STARTINC_NOSAFE
#		ifndef SAFE_ADDREF
#		define SAFE_ADDREF(p)			if (p) { (p)->AddRef(); }
#		endif
#		ifndef SAFE_RELEASE
#		define SAFE_RELEASE(p)			if (p) { (p)->Release(); (p) = NULL; }
#		endif
#		ifndef SAFE_DELETE
#		define SAFE_DELETE(p)			if (p) { delete (p); (p) = NULL; }
#		endif
#		ifndef SAFE_DELETE_ARRAY
#		define SAFE_DELETE_ARRAY(p)		if(p) { delete[] (p); (p) = NULL; }
#		endif
#	endif // _STARTINC_NOSAFE

#if !defined(SAFE_PROCEDURE) && !defined(_STARTINC_NOSP)
#	define SAFE_PROCEDURE
		/*
			Usage of SAFE PROCEDURE
			--------------------------------------------------------------------------------
			SP_BEGIN		or: 		"SP_BEGIN_(hr)", "SP_BEGIN_(dwError)"
			....
			SP_GATE_(is_ok(pwd))		"__sp_hr=func(); SP_GATE"
										"SP_GATEx_(magic==0x1234, E_UNEXPECTED) "
			....
			  (do some process need clean-up)
			....
			SP_GATE1_(pv != NULL)		"SP_GATEx1_(pv, E_OUTOFMEMORY) "
			....
			// if (no_clean_up) return SP_RETVAL;
			SP_BREAK_(S_OK)				"if (no_clean_up) SP_BREAK"

			SP_REV						"SP_END SP_BACK"

			SP_L						"SP_L1 SAFE_DELETE(pv)
			SP_L3						\
			SP_L2						\
			SP_L1	SAFE_DELETE(pv);	\
			SP_L0						\

			SP_LEND						SP_LEND"

			return SP_RETVAL;			"return SP_RETVAL_(DWORD); "
			---------------------------------------------------------------------------------
			copy&paste:

	SP_BEGIN_(hr)
	// SP_GATEx1_(pv, E_OUTOFMEMORY)
	// if (release_gates)
	SP_BREAK_(S_OK)
	SP_REV
	SP_L
	SP_L1
	SP_L0
	SP_LEND
	return SP_RETVAL;
		*/
#	define SP_BEGIN \
		HRESULT __sp_hr = S_OK; \
		int __sp_level = 0; \
		for (;;) {
#	define SP_BEGIN_(hr) \
		HRESULT& __sp_hr = *(HRESULT *)&hr; \
		int __sp_level = 0; \
		for (;;) {
#	define SP_BREAK break;
#	define SP_BREAK_(r)					{ __sp_hr = (HRESULT)(r); break; }
#	define SP_END						__sp_level = -1; break; }
#	define SP_GATE						if (FAILED(__sp_hr)) break;
#	define SP_GATE1						{ SP_GATE; __sp_level++; }
#	define SP_GATE2						{ SP_GATE; __sp_level+=2; }
#	define SP_GATE3						{ SP_GATE; __sp_level+=3; }
#	define SP_GATE4						{ SP_GATE; __sp_level+=4; }
#	define SP_GATE_(c)					if (!(c)) break;
#	define SP_GATE1_(c)					{ SP_GATE_(c); __sp_level++; }
#	define SP_GATE2_(c) 				{ SP_GATE_(c); __sp_level+=2; }
#	define SP_GATE3_(c) 				{ SP_GATE_(c); __sp_level+=3; }
#	define SP_GATE4_(c) 				{ SP_GATE_(c); __sp_level+=4; }
#	define SP_GATEx(x) 					if (FAILED(__sp_hr)) { __sp_hr = (HRESULT)(x); break; }
#	define SP_GATEx1(x) 				{ SP_GATEx(x); __sp_level++; }
#	define SP_GATEx2(x) 				{ SP_GATEx(x); __sp_level+=2; }
#	define SP_GATEx3(x) 				{ SP_GATEx(x); __sp_level+=3; }
#	define SP_GATEx4(x) 				{ SP_GATEx(x); __sp_level+=4; }
#	define SP_GATEx_(c,x) 				if (!(c)) { __sp_hr = (HRESULT)(x); break; }
#	define SP_GATEx1_(c,x) 				{ SP_GATEx_(c,x); __sp_level++; }
#	define SP_GATEx2_(c,x) 				{ SP_GATEx_(c,x); __sp_level+=2; }
#	define SP_GATEx3_(c,x) 				{ SP_GATEx_(c,x); __sp_level+=3; }
#	define SP_GATEx4_(c,x) 				{ SP_GATEx_(c,x); __sp_level+=4; }
#	define SP_BACK 						switch (__sp_level) {
#	define SP_REV 						SP_END SP_BACK
#	define SP_L 						default:
#	define SP_L_(n) 					case (n):
#	define SP_Lz						case 35:
#	define SP_Ly						case 34:
#	define SP_Lx 						case 33:
#	define SP_Lw 						case 32:
#	define SP_Lv						case 31:
#	define SP_Lu						case 30:
#	define SP_Lt						case 29:
#	define SP_Ls						case 28:
#	define SP_Lr						case 27:
#	define SP_Lq						case 26:
#	define SP_Lp						case 25:
#	define SP_Lo						case 24:
#	define SP_Ln						case 23:
#	define SP_Lm						case 22:
#	define SP_Ll						case 21:
#	define SP_Lk						case 20:
#	define SP_Lj						case 19:
#	define SP_Li						case 18:
#	define SP_Lh						case 17:
#	define SP_Lg						case 16:
#	define SP_Lf						case 15:
#	define SP_Le						case 14:
#	define SP_Ld						case 13:
#	define SP_Lc						case 12:
#	define SP_Lb						case 11:
#	define SP_La						case 10:
#	define SP_L39						case 39:
#	define SP_L38						case 38:
#	define SP_L37						case 37:
#	define SP_L36						case 36:
#	define SP_L35						case 35:
#	define SP_L34						case 34:
#	define SP_L33						case 33:
#	define SP_L32						case 32:
#	define SP_L31						case 31:
#	define SP_L30						case 30:
#	define SP_L29						case 29:
#	define SP_L28						case 28:
#	define SP_L27						case 27:
#	define SP_L26						case 26:
#	define SP_L25						case 25:
#	define SP_L24						case 24:
#	define SP_L23						case 23:
#	define SP_L22						case 22:
#	define SP_L21						case 21:
#	define SP_L20						case 20:
#	define SP_L19						case 19:
#	define SP_L18						case 18:
#	define SP_L17						case 17:
#	define SP_L16						case 16:
#	define SP_L15						case 15:
#	define SP_L14						case 14:
#	define SP_L13						case 13:
#	define SP_L12						case 12:
#	define SP_L11						case 11:
#	define SP_L10						case 10:
#	define SP_L9						case 9:
#	define SP_L8						case 8:
#	define SP_L7						case 7:
#	define SP_L6						case 6:
#	define SP_L5						case 5:
#	define SP_L4						case 4:
#	define SP_L3						case 3:
#	define SP_L2						case 2:
#	define SP_L1						case 1:
#	define SP_L0						case 0:
#	define SP_LEND						break; }
#	define SP_GROUP						break;
#	define SP_RETVAL					__sp_hr
#	define SP_RETVAL_(t)				((t)__sp_hr)
#	endif // _STARTINC_NOSP


#ifdef _DEBUG
#	define _DBG							if (true)
#	define _DBG_						if (false)
#else
#	define _DBG							if (false)
#	define _DBG_						if (true)
#endif

#	define _DSK							if (false)
#	define _DSKs						if (false) {
#	define _DSKs_						{
#	define _DSKe						}
#	define __debug_skip_it				_DSK
#	define __debug_skip_s				_DSKs
#	define __debug_skip_s_				_DSKs_
#	define __debug_skip_e				_DSKe

#	ifdef AfxDebugBreak
#		define __brk					AfxDebugBreak()
#	else
#		define __brk					{ __asm int 3 }
#	endif

#	define __zero(v)					memset(&(v), 0, sizeof(v))

#	ifndef _STARTINC_NOINLINES
		template<class RetT, class ParamT>
		inline RetT __cast(ParamT x) { return (RetT)x; }
#	endif

#	define WARN(uID)					{ feiy::popup_message((LPCTSTR)(uID), false); }
#	define FATAL(uID)					{ feiy::popup_message((LPCTSTR)(uID), true); }

#	define SYSWARN(errno)				{ feiy::popup_errmsg(errno, false); }
#	define SYSERR(errno)				{ feiy::popup_errmsg(errno, true); }
#	define SYSVERIFY(v)					if (!(v)) SYSERR(GetLastError())

#	ifndef _STARTINC_NOINLINES
	FEIY_BEGIN
		inline void __stdcall popup_message(LPCTSTR title, bool fatal = false) {
			TCHAR	buffer[1024];
			TCHAR	sentence[1024];

			if ((LPARAM)title < 0x10000) {
				LoadString(GetModuleHandle(NULL), (UINT)(LPARAM)title, buffer, sizeof(buffer) / sizeof(TCHAR));
			} else {
				lstrcpy(buffer, title);
			}

			_stprintf(sentence, TEXT("程序发生错误：\n\n%s\n\n请咨询系统管理员或技术人员。"),
				buffer);

			if (!fatal) {
			#ifndef __silence_message
				MessageBox(NULL, sentence, TEXT("START.INC FRAMEWORK"), MB_OK | MB_ICONINFORMATION);
			#endif
			} else {
				MSG msg;
				UINT id;

				// we remove WM_QUIT because if it is in the queue then the message box
				// won't display
				BOOL bQuit = PeekMessage(&msg, NULL, WM_QUIT, WM_QUIT, PM_REMOVE);
				id = MessageBox(NULL, sentence, TEXT("START.INC FRAMEWORK"),
					MB_ABORTRETRYIGNORE | MB_ICONERROR);
				if (bQuit) PostQuitMessage((int)msg.wParam);

				switch (id) {
					case IDABORT:
						if (!bQuit) exit(-1);
						break;
					case IDRETRY:
						__brk;
						break;
					case IDIGNORE: ;
				}
			}
		}

		inline void __stdcall popup_errmsg(DWORD errno, bool fatal = false) {
			LPTSTR lpMsgBuf;
			if (!FormatMessage(
                FORMAT_MESSAGE_ALLOCATE_BUFFER |
                FORMAT_MESSAGE_FROM_SYSTEM |
                FORMAT_MESSAGE_IGNORE_INSERTS,
                NULL,
				errno,
                MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
                (LPTSTR)&lpMsgBuf,
                0,
                NULL))
			{
				popup_message(TEXT("Unexpected: Error occured when FormatMessage!"), fatal);
			} else {
				popup_message(lpMsgBuf, fatal);
				// never executed:
				// LocalFree(lpMsgBuf);
			}
		}


#		ifndef _STARTINC_NOMODREF
#			ifdef _DEBUG
#				define _MOD_OBJECTS_	_g_mod_objects
#				define MLOCK			++FEIY(_MOD_OBJECTS_)
#				define MUNLOCK			--FEIY(_MOD_OBJECTS_)
#				define DEFINE_MODREF															\
					FEIY_BEGIN																	\
					long _MOD_OBJECTS_;															\
					struct _refchecker_on_exit_ {												\
						int _stuff;																\
						_refchecker_on_exit_() { _MOD_OBJECTS_ = 0; }							\
						~_refchecker_on_exit_() {												\
							if (_MOD_OBJECTS_ != 0) {											\
								TCHAR buf[50];													\
								_stprintf(buf,													\
									TEXT("ML-%d: Module was still locked by %d users!"),		\
									_MOD_OBJECTS_, _MOD_OBJECTS_);								\
								FATAL(buf);														\
							}																	\
						}																		\
					} _g_refchecker_on_exit_; 													\
					FEIY_END
				extern long _MOD_OBJECTS_;
#			else
#				define _MOD_OBJECTS_	_f_local_objects
#				define MLOCK
#				define MUNLOCK
#				define DEFINE_MODREF
				static long _MOD_OBJECTS_ = 0;
#			endif
#		endif // _STARTINC_NOMODREF

	FEIY_END

#	endif // _STARTINC_NOINLINES

#endif // _STARTINC_NOMACROS

#endif // _STARTINC_H
