
//	COM\基本数据类型
//	2000.12.6

#pragma once

#include "coDef.h"

#define co_tag_type(coType)		_##coType
#define co_def_type(priType, coType)	typedef priType	coType;	co_type(coType)
#define co_type(coType)					\
	typedef coType			*coType##_r;	\
	typedef coType			*coType##_a;	\
	typedef coType##_r		*coType##_ra;	\
//	typedef coType			&coType##_R;

#define co_interface(i)					\
	interface i;					\
	co_type(i);
#define co_struct(i)					\
	struct i; 					\
	co_type(i);
#define co_class(i)					\
	class i;					\
	co_type(i);

// 原始数据类型

	#define coTRUE			1
	#define coFALSE			0
	#define coMIX			2

	#define coSET			coTRUE
	#define coUNSET			coMIX
	#define coCLEAR			coFALSE
	#define coUNCLEAR		coMIX

	#define co_isset(b)		(b & coSET)
	#define co_isclear(b)		(b & coCLEAR)
	#define co_istrue(b)		(b == coTRUE)
	#define co_isfalse(b)		(b == coFALSE)

	#define co_specified(sth)	(sth != NULL)

	co_def_type(long,		coBOOL);

	co_def_type(long,		coINT);
	co_def_type(double,		coREAL);

	co_def_type(unsigned char,	coDATA8);
	co_def_type(unsigned short,	coDATA16);
	co_def_type(unsigned long,	coDATA32);

	co_def_type(unsigned long,	coID);

	co_def_type(TCHAR,		coCHAR);
	co_def_type(LPTSTR,		coSTR);

	co_def_type(_coString,		coString);

// 基本数据类型

	// 原始数据列表类型
		co_def_type(coList(coINT), 	coListINT);
		co_def_type(coList(coREAL),	coListREAL);
		co_def_type(coList(coString),	coListString);

		co_def_type(coArray(coINT), 	coArrayINT);
		co_def_type(coArray(coREAL),	coArrayREAL);
		co_def_type(coArray(coString),	coArrayString);

	// 集合类型
	// 模板类

		// 基本集合类模板
		template <class oTYPE>
		struct coSet {
			coVF(coSet&)	operator =  (const coSet&);		// 赋值
			coVF(coSet&)	operator += (const coSet&);		// 追加
			coF(coSet&)	operator += (const oTYPE&);		// 追加
			coVF(coSet&)	operator -= (const coSet&);		// 删减
			coF(coSet&)	operator -= (const oTYPE&);		// 删减

			coVF(coSet) 	operator +  (const coSet&) const;	// 并
			coF(coSet)	operator +  (const oTYPE&) const;	// 并
			coVF(coSet) 	operator -  (const coSet&) const;	// 差
			coF(coSet) 	operator -  (const oTYPE&) const;	// 差

			coVF(coBOOL)	operator == (const coSet&) const;	// 相等
			coVF(coBOOL)	operator != (const coSet&) const;	// 不相等
			coF(coBOOL)	operator >  (const oTYPE&) const;	// 属于
			coVF(coBOOL)	operator >= (const coSet&) const;	// 子集
			coVF(coBOOL)	operator <= (const coSet&) const;	// 父集
			coVF(coBOOL)	operator >> (const coSet&) const;	// 真子集
			coVF(coBOOL)	operator << (const coSet&) const;	// 真父集

			coVF(oTYPE)	operator [] (const coINT) const;	// 取元素
			coVF(oTYPE&)	operator [] (const coINT);		// 设置元素
			coVP		operator coINT () const;		// 取元素个数
		public:
			coP		coSet();
			coP		coSet(const coSet&);
			coVP		~coSet();
		private:
			coINT		m_count;
			coList(oTYPE)	m_data;
		};
/*
		// 模糊集合类
		template<class oTYPE>
		struct coSetF : public coSet<oTYPE> {
			coVF(coSetF&)	operator =  (const coSetF&);		// 赋值
			coVF(coSetF&)	operator += (const coSetF&);		// 追加
			coF(coSetF&)	operator += (const oTYPE&);		// 追加
			coVF(coSetF&)	operator -= (const coSetF&);		// 删减
			coF(coSetF&)	operator -= (const oTYPE&);		// 删减

			// 标准模糊运算
			coVF(coSetF) 	operator +  (const coSetF&) const;	// 并
			coF(coSetF)	operator +  (const oTYPE&) const;	// 并
			coVF(coSetF) 	operator -  (const coSetF&) const;	// 差
			coF(coSetF) 	operator -  (const oTYPE&) const;	// 差

			// 爱因斯坦模糊运算
			coVF(coSetF)	add_einstein(const coSetF&) const;
			coF(coSetF)	add_einstein(const oTYPE&) const;
			coVF(coSetF)	sub_einstein(const coSetF&) const;
			coF(coSetF)	sub_einstein(const oTYPE&) const;

			//

			coVF(coBOOL)	operator == (const coSetF&) const;	// 相等
			coVF(coBOOL)	operator != (const coSetF&) const;	// 不相等
			coF(coBOOL)	operator >  (const oTYPE&) const;	// 属于
			coVF(coBOOL)	operator >= (const coSetF&) const;	// 子集
			coVF(coBOOL)	operator <= (const coSetF&) const;	// 父集
			coVF(coBOOL)	operator >> (const coSetF&) const;	// 真子集
			coVF(coBOOL)	operator << (const coSetF&) const;	// 真父集

			coVF(oTYPE)	operator [] (const coINT) const;	// 取元素
			coVF(oTYPE&)	operator [] (const coINT);		// 设置元素
			coVP		operator coINT () const;		// 取元素个数
		public:
			coP		coSetF();
			coP		coSetF(const coSetF&);
			coVP		~coSetF();
		private:
			coINT		m_count;
			struct co_item_fuzzy {
				// 元素数据
				oTYPE	item;
				// 隶属度
				coREAL	subjection;
			//public:
				// 数据操作

			};
			typedef co_item_fuzzy	coItemFuzzy;
			coList(coItemFuzzy)	m_data;
		};
*/
	// 基本集合类
		co_def_type(coSet<coBOOL>,	coSetBOOL);
		co_def_type(coSet<coINT>,	coSetINT);
		co_def_type(coSet<coREAL>,	coSetREAL);

// 空间类型

	co_struct(coPT2);
	co_struct(coPT3);
	co_type(coPT2);
	co_type(coPT3);

	struct coPT2 {
		coREAL	x;
		coREAL	y;
	public:
		// 运算
		coVF(coPT2&)		operator =  (const coPT2& p2) { x = p2.x; y = p2.y; return *this; }
		coVF(coPT2&)		operator += (const coPT2& p2) { x += p2.x; y += p2.y; return *this; }
		coVF(coPT2&)		operator -= (const coPT2& p2) { x -= p2.x; y -= p2.y; return *this; }
		coVF(coPT2)		operator +  (const coPT2& p2) const { coPT2 r(*this); r += p2; return r; }
		coVF(coPT2)		operator -  (const coPT2& p2) const { coPT2 r(*this); r -= p2; return r; }

		// 幅角
		coVF(coREAL)		arg() const { return atan2(y, x); }
		// 到原点距离
		coVF(coREAL)		disto() const { return sqrt(x * x + y * y); }
		// 到另一点的距离
		coVF(coREAL)		disto(const coPT2& p2) const { return (p2 - *this).disto(); }

		// 序号取坐标值
		coVF(coREAL)		operator [] (const coINT xyindex) const { return xyindex == 0 ? x : y; }
		coVF(coREAL&)		operator [] (const coINT xyindex) { return xyindex == 0 ? x : y; }
	public:
		coP			coPT2() : x(0), y(0) {}
		coP			coPT2(const coREAL ix, const coREAL iy) : x(ix), y(iy) {}
		coP			coPT2(const coPT2& o_o) { x = o_o.x; y = o_o.y; }
	};

	struct coPT3 {
		coREAL	x;
		coREAL	y;
		coREAL	z;
	public:
		// 到原点距离
		coVF(coREAL)		disto() const { return sqrt(x * x + y * y + z * z); }
		// 到另一点的距离
		coVF(coREAL)		disto(const coPT3& p2) const { return (p2 - *this).disto(); }
		// 运算
		coVF(coPT3&)		operator =  (const coPT3& p2) { x = p2.x; y = p2.y; z = p2.z; return *this; }
		coVF(coPT3&)		operator += (const coPT3& p2) { x += p2.x; y += p2.y; z += p2.z; return *this; }
		coVF(coPT3&)		operator -= (const coPT3& p2) { x -= p2.x; y -= p2.y; z -= p2.z; return *this; }
		coVF(coPT3)		operator +  (const coPT3& p2) const { coPT3 r(*this); r += p2; return r; }
		coVF(coPT3)		operator -  (const coPT3& p2) const { coPT3 r(*this); r -= p2; return r; }

		// 序号取坐标值
		coVF(coREAL)		operator [] (coINT xyzindex) const { return xyzindex == 0 ? x : xyzindex == 1 ? y : z; }
		coVF(coREAL&)		operator [] (coINT xyzindex) { return xyzindex == 0 ? x : xyzindex == 1 ? y : z; }
	public:
		coP			coPT3() : x(0), y(0), z(0) {}
		coP			coPT3(const coREAL ix, const coREAL iy, const coREAL iz) : x(ix), y(iy), z(iz) {}
		coP			coPT3(const coPT3& o_o) { x = o_o.x; y = o_o.y; z = o_o.z; }
	};

// 返回类型 及 错误值

	// 引入错误类型
	#include "coError.h"

	// 复合返回值对象
	struct co_tag_type(coRet) {
		coBOOL			status;
		coDATA8			avail;
		union {
			HRESULT		hresult;
			coRetError	coerror;
			coRetControl	control;
		};
		union {
			coDATA32	data;
		};

		coP			co_tag_type(coRet)() : status(coCLEAR), avail(0), data(0) {}
		coVF(void) 		operator = (co_tag_type(coRet)& r_2) { memcpy(this, &r_2, sizeof(this)); }
	};
	co_def_type(co_tag_type(coRet), coRet);

	#define co_avail_hresult	0x01		// 返回值中的 hresult 部分有效
	#define co_avail_coerror	0x02		// 返回值中的 coerror 部分有效
	#define co_avail_control	0x03		// 返回值中的 control 部分有效
	#define co_avail_data_num	0x10		// 返回值中的 data 部分有效, 且为一数值
	#define co_avail_data_pointer	0x20		// 返回值中的 data 部分有效, 且为一指针
	#define co_avail_data_callback	0x30		// 返回值中的 data 部分有效, 且为一指针

	// 设置返回值
	#define co_setok(cret)		((cret).status = coCLEAR)
	#define co_seter(cret)		((cret).status = coSET)
	#define co_setce(cret, ce)	((cret).avail = co_avail_coerror, cret.coerror = (ce))
	#define co_setcn(cret, ct)	((cret).avail = co_avail_control, cret.control = (ct))
	#define co_sethr(cret, hr)	((cret).avail = co_avail_hresult, cret.hresult = (hr))
	#define co_sethe(cret, he)	((cret).avail = MAKE_RESULT(SEVERITY_ERROR, FACILITY_WINDOWS, (he)))

	// 检测返回值
	#define cook(cret)		((cret).status == coCLEAR)
	#define coerror(cret)		((cret).status == coSET)
	#define co_ishr(cret)		((cret).avail & co_avail_hresult)
	#define co_isce(cret)		((cret).avail & co_avail_coerror)
	#define co_iscn(cret)		((cret).avail & co_avail_control)

	#define co_assert(exp)		if (!(exp)) co_ASSERT(0); else

	#define co_new(var, type)					\
		if (((var) = (new (type))) == NULL) {			\
			coRet __new_fail;				\
			co_seter(__new_fail);				\
			co_sethr(__new_fail, ERROR_OUTOFMEMORY);	\
			co_ASSERT(0);					\
		} else

	#define co_del(var)		if ((var) != NULL) delete (var)
	#define co_dela(var)		if ((var) != NULL) delete[] (var)
