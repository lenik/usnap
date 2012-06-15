// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__29452BC2_642C_4179_9576_4DB0F53A71F0__INCLUDED_)
#define AFX_STDAFX_H__29452BC2_642C_4179_9576_4DB0F53A71F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


// TODO: reference additional headers your program requires here
#include <stdio.h>
#include <stdlib.h>

#include <windows.h>
#include <objbase.h>

#include <list>
#include <vector>

//--
	#define DEFINE_OBJ(i)		CComPtr<I##i> p##i;

	#ifndef SAFE_RELEASE
	#define SAFE_RELEASE(p)		if (p) { (p)->Release(); (p) = NULL; }
	#endif
	#ifndef SAFE_DELETE
	#define SAFE_DELETE(p)		if (p) { delete (p); (p) = NULL; }
	#endif
	#ifndef SAFE_DELETE_ARRAY
	#define SAFE_DELETE_ARRAY(p)	if(p) { delete[] (p); (p) = NULL; }
	#endif


	#ifndef SAFE_PROCEDURE
	#define SAFE_PROCEDURE
	#define SP_BEGIN \
		HRESULT __sp_hr = S_OK; \
		int __sp_level = 0; \
		for (;;) {
	#define SP_BEGIN_(hr) \
		HRESULT& __sp_hr = hr; \
		int __sp_level = 0; \
		for (;;) {
	#define SP_BREAK break;
	#define SP_BREAK_(r) { __sp_hr = (HRESULT)(r); break; }
	#define SP_END __sp_level = -1; break; }
	#define SP_GATE if (FAILED(__sp_hr)) break;
	#define SP_GATE1 { SP_GATE; __sp_level++; }
	#define SP_GATE2 { SP_GATE; __sp_level+=2; }
	#define SP_GATE3 { SP_GATE; __sp_level+=3; }
	#define SP_GATE4 { SP_GATE; __sp_level+=4; }
	#define SP_GATE_(c) if (!(c)) break;
	#define SP_GATE1_(c) { SP_GATE_(c); __sp_level++; }
	#define SP_GATE2_(c) { SP_GATE_(c); __sp_level+=2; }
	#define SP_GATE3_(c) { SP_GATE_(c); __sp_level+=3; }
	#define SP_GATE4_(c) { SP_GATE_(c); __sp_level+=4; }
	#define SP_BACK \
		switch (__sp_level) {
	#define SP_L default:
	#define SP_L_(n) case (n):
	#define SP_Lz case 35:
	#define SP_Ly case 34:
	#define SP_Lx case 33:
	#define SP_Lw case 32:
	#define SP_Lv case 31:
	#define SP_Lu case 30:
	#define SP_Lt case 29:
	#define SP_Ls case 28:
	#define SP_Lr case 27:
	#define SP_Lq case 26:
	#define SP_Lp case 25:
	#define SP_Lo case 24:
	#define SP_Ln case 23:
	#define SP_Lm case 22:
	#define SP_Ll case 21:
	#define SP_Lk case 20:
	#define SP_Lj case 19:
	#define SP_Li case 18:
	#define SP_Lh case 17:
	#define SP_Lg case 16:
	#define SP_Lf case 15:
	#define SP_Le case 14:
	#define SP_Ld case 13:
	#define SP_Lc case 12:
	#define SP_Lb case 11:
	#define SP_La case 10:
	#define SP_L9 case 9:
	#define SP_L8 case 8:
	#define SP_L7 case 7:
	#define SP_L6 case 6:
	#define SP_L5 case 5:
	#define SP_L4 case 4:
	#define SP_L3 case 3:
	#define SP_L2 case 2:
	#define SP_L1 case 1:
	#define SP_L0 case 0:
	#define SP_EXIT break; }
	#define SP_GROUP break;
	#define SP_RETVAL __sp_hr
	#define SP_RETVAL_(t) ((t)__sp_hr)
	#endif

	#define _DSK			if (false)
	#define _DSKs			if (false) {
	#define _DSKs_			{
	#define _DSKe			}
	#define __debug_skip_it		_DSK
	#define __debug_skip_s		_DSKs
	#define __debug_skip_s_		_DSKs_
	#define __debug_skip_e		_DSKe

	#define __zero(v)		memset(&(v), 0, sizeof(v))


	template<class RetT, class ParamT>
	inline RetT __cast(ParamT x) { return (RetT)x; }


	#ifndef __HRERRDESC
	#define __HRERRDESC	//DXGetErrorDescription8
	#endif

	#define WARN(uID)	{ popup_message((UINT)(uID)); }
	// if (uID) FATAL uID else FATAL hrdesc(hr)
	#define FATAL(uID)	{ popup_message(__cast<UINT>(uID)?__cast<UINT>(uID):__cast<UINT>(__HRERRDESC(hr)), true); exit(__cast<UINT>(uID)); }

		inline void __stdcall popup_message(UINT uID, bool fatal = false) {
			TCHAR	buffer[1024];
			TCHAR	sentence[1024];
		#ifdef _DEBUG
			if (uID < 0x10000) {
				LoadString(GetModuleHandle(NULL), uID, buffer, sizeof(buffer) / sizeof(TCHAR));
			} else {
				lstrcpy(buffer, (LPTSTR)uID);
			}
		#else
			if (uID < 0x10000) {
				wsprintf(buffer, TEXT(" <<"), uID, uID);
			} else {
				lstrcpy(buffer, (LPTSTR)uID);
			}
		#endif

			TCHAR	err_prefix[1024] = TEXT("程序发生错误：\n\t%s (%d, 0x%x)\n请咨询系统管理员或技术人员。");

			// 多放几个 buffer 以应付err_prefix中多个%s。
			wsprintf(sentence, err_prefix, buffer, uID, uID, buffer, buffer);
	/*
		#ifndef __silence_message
			MessageBox(NULL, sentence, TEXT("FeiyPhoto - FrameTakeby"), MB_OK);
		#endif
	/*/
			if (!fatal) {
			#ifndef __silence_message
				MessageBox(NULL, sentence, TEXT("FeiyPhoto - FrameTakeby"), MB_OK);
			#endif
			} else {
				MessageBox(NULL, sentence, TEXT("FeiyPhoto - FrameTakeby"), MB_YESNOCANCEL);
				::DebugBreak();
			}

		}


	#pragma warning(disable: 4100)		// unreferenced formal parameter
	#pragma warning(disable: 4127)		// condition is constant
	#pragma warning(disable: 4245)		// signed/unsigned mismatch
	#pragma warning(disable: 4786)		// symbol long in debug info
	#pragma warning(disable: 4530)		// exception with /GX

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


	#ifdef _DEBUG

	#ifndef ASSERT
	#include <assert.h>
	#define ASSERT	assert
	#endif //ASSERT

	#ifndef DBGPOP
	#define DBGPOP(s)	::MessageBox(NULL, s, _T("DBGPOP"), MB_OK)
	#endif //DBGPOP

	#else //_DEBUG

	#ifndef ASSERT
	#define ASSERT(cond)
	#endif

	#ifndef DBGPOP
	#define DBGPOP(msg)
	#endif

	#endif //_DEBUG
//-->

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__29452BC2_642C_4179_9576_4DB0F53A71F0__INCLUDED_)
