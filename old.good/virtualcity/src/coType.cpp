
#include "coType.h"

// 集合构造
	template<class oTYPE>
	coP		coSet<oTYPE>::coSet<oTYPE>() : m_count(0) {}

	template<class oTYPE>
	coP		coSet<oTYPE>::coSet<oTYPE>(const coSet<oTYPE>& o_s) {
		m_count = 0;
		*this = o_s;
	}

	template<class oTYPE>
	coP		coSet<oTYPE>::~coSet<oTYPE>() {
		m_data.RemoveAll();
		m_count = 0;
	}

// 集合运算
	// 集合赋值
	template<class oTYPE>
	coF(coSet<oTYPE>&)	coSet<oTYPE>::operator =  (const coSet<oTYPE>& o_s) {
		coINT	i;
		coINT	o_s_count = (coINT)o_s;

		if (this == &o_s) return *this;

		for (i = 0; i < m_count; ) {
			// 将不属于o_s的元素从this中减去
			if (!(o_s > (*this)[i])) (*this) -= (*this)[i];
			else i++;
		}
		for (i = 0; i < o_s_count; i++) {
			// 将不属于this的元素加入this中
			if (!(*this > o_s[i])) (*this) += o_s[i];
		}
		// m_count 将自动根据 -= / += 更新
		return (*this);
	}

	// 集合并上元素
	template <class oTYPE>
	coF(coSet<oTYPE>&)	coSet<oTYPE>::operator += (const oTYPE& o_e) {
		if (!(*this > o_e)) {
			m_data.AddTail(o_e);
			m_count++;
		}
		return *this;
	}

	// 集合并上集合
	template<class oTYPE>
	coF(coSet<oTYPE>&)	coSet<oTYPE>::operator += (const coSet<oTYPE>& o_s) {
		coINT	i;
		coINT	o_s_count = (coINT)o_s;
		for (i = 0; i < o_s_count; i++) {
			(*this) += o_s[i];
		}
		return *this;
	}

	// 集合减去元素
	template <class oTYPE>
	coF(coSet<oTYPE>&)	coSet<oTYPE>::operator -= (const oTYPE& o_e) {
		POSITION	pos;
		if (*this > o_e) {
			pos = m_data.Find(o_e);
			m_data.RemoveAt(pos);
			m_count--;
		}
		return *this;
	}

	// 集合减去集合
	template<class oTYPE>
	coF(coSet<oTYPE>&)	coSet<oTYPE>::operator -= (const coSet<oTYPE>& o_s) {
		coINT	i;
		coINT	o_s_count = (coINT)o_s;
		for (i = 0; i < o_s_count; i++) {
			(*this) -= o_s[i];
		}
		return *this;
	}

	// 集合与元素并集
	template<class oTYPE>
	coF(coSet<oTYPE>)	coSet<oTYPE>::operator +  (const oTYPE& o_e) const {
		coSet<oTYPE>	r(*this);
		r += o_e;
		return r;
	}

	// 集合与集合并集
	template<class oTYPE>
	coF(coSet<oTYPE>)	coSet<oTYPE>::operator +  (const coSet<oTYPE>& o_s) const {
		coSet<oTYPE>	r(*this);
		r += o_s;
		return r;
	}

	// 集合与元素差集
	template<class oTYPE>
	coF(coSet<oTYPE>)	coSet<oTYPE>::operator -  (const oTYPE& o_e) const {
		coSet<oTYPE>	r(*this);
		r -= o_e;
		return r;
	}

	// 集合与集合差集
	template<class oTYPE>
	coF(coSet<oTYPE>)	coSet<oTYPE>::operator -  (const coSet<oTYPE>& o_s) const {
		coSet<oTYPE>	r(*this);
		r -= o_s;
		return r;
	}

// 集合判断
	// 集合相等
	template<class oTYPE>
	coF(coBOOL)	coSet<oTYPE>::operator == (const coSet<oTYPE>& o_s) const {
		coBOOL	r = coTRUE;
		if (m_count != o_s.m_count) r = coFALSE;
		else {
			for (coINT i = 0; i < m_count; i++) {
				// 若o_s中某个元素不属于此集合, 则o_s与此集合不等
				if (*this > o_s[i]) {
					r = coFALSE;
					break;
				}
			}
		}
		return r;
	}

	// 集合不等
	template<class oTYPE>
	coF(coBOOL)	coSet<oTYPE>::operator != (const coSet<oTYPE>& o_s) const {
		return !(*this == o_s);
	}

	// 元素属于集合
	template<class oTYPE>
	coF(coBOOL)	coSet<oTYPE>::operator >  (const oTYPE& o_e) const {
		return m_data.Find(o_e) != NULL;
	}

	// 给定集合是此集合的子集
	template<class oTYPE>
	coF(coBOOL)	coSet<oTYPE>::operator >= (const coSet<oTYPE>& o_s) const {
		coBOOL	r = coTRUE;
		coINT	o_s_count = (coINT)o_s;
		for (coINT i = 0; i < o_s_count; i++) {
			// 若o_s中某个元素不属于此集合, 则o_s不是此集合的子集
			if (!(*this > o_s[i])) {
				r = coFALSE;
				break;
			}
		}
		return r;
	}

	// 此集合是给定集合的子集
	template<class oTYPE>
	coF(coBOOL)	coSet<oTYPE>::operator <= (const coSet<oTYPE>& o_s) const {
		coBOOL	r = coTRUE;
		for (coINT i = 0; i < m_count; i++) {
			// 若此集合中某个元素不属于o_s, 则此集合不是o_s的子集
			if (!(o_s > (*this)[i])) {
				r = coFALSE;
				break;
			}
		}
		return r;
	}

	// 给定集合是此集合的真子集
	template<class oTYPE>
	coF(coBOOL)	coSet<oTYPE>::operator >> (const coSet<oTYPE>& o_s) const {
		return (*this >= o_s) && (*this != o_s);
	}

	// 此集合是给定集合的真子集
	template<class oTYPE>
	coF(coBOOL)	coSet<oTYPE>::operator << (const coSet<oTYPE>& o_s) const {
		return (*this <= o_s) && (*this != o_s);
	}

// 集合转换

	// 取元素
	template<class oTYPE>
	coF(oTYPE)	coSet<oTYPE>::operator [] (const coINT index) const {
		coINT		list_index = (coINT)index;
		POSITION	pos = m_data.FindIndex(index);
		return m_data.GetAt(pos);
	}

	// 设置元素
	template<class oTYPE>
	coF(oTYPE&)	coSet<oTYPE>::operator [] (const coINT index) {
		coINT		list_index = (coINT)index;
		POSITION	pos = m_data.FindIndex(index);
		return m_data.GetAt(pos);
	}

	// 取元素个数
	template<class oTYPE>
	coP		coSet<oTYPE>::operator coINT () const {
		//return (coINT)m_data.GetCount();
		return m_count;
	}
