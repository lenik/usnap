
#pragma once

#include <math.h>

#define __Twindows__

#if defined(__Twindows__)

	#include <afxtempl.h>
	#define _coString	CString

	#define coList(TYPE)	CList<TYPE, TYPE>
	#define coArray(TYPE)	CArray<TYPE, TYPE>

#elif defined(__Tunix__)

	#include "list.h"
	#include "tree.h"

	#define _coString	string
	#define coList(TYPE)	list<TYPE>
	#define coArray(TYPE)	list<TYPE>

	#define ASSERT(exp)	(exp);

#endif

// 虚拟接口
#define interface	struct

// 标准函数
#define coP		_stdcall
#define coF(TYPE)	TYPE _stdcall
#define coSF		coRet _stdcall

// 抽象函数类型
#define coVP		virtual coP
#define coVF(TYPE)	virtual coF(TYPE)
#define coSVF		virtual coSF

// 低级转换(用于通用参数传递)
#define co_cast(type)	*(type *)&

// 常量

#define co_PI			3.1416

#define co_EAST			0.0
#define co_SOUTH		(-co_pi / 2)
#define co_WEST			(-co_pi)
#define co_NORTH		(-co_pi - co_pi / 2)

//
#define co_ASSERT(exp)		ASSERT(exp)

#define coA			// 附加代码
