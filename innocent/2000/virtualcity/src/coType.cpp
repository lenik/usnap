
#include "coType.h"

// ���Ϲ���
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

// ��������
	// ���ϸ�ֵ
	template<class oTYPE>
	coF(coSet<oTYPE>&)	coSet<oTYPE>::operator =  (const coSet<oTYPE>& o_s) {
		coINT	i;
		coINT	o_s_count = (coINT)o_s;

		if (this == &o_s) return *this;

		for (i = 0; i < m_count; ) {
			// ��������o_s��Ԫ�ش�this�м�ȥ
			if (!(o_s > (*this)[i])) (*this) -= (*this)[i];
			else i++;
		}
		for (i = 0; i < o_s_count; i++) {
			// ��������this��Ԫ�ؼ���this��
			if (!(*this > o_s[i])) (*this) += o_s[i];
		}
		// m_count ���Զ����� -= / += ����
		return (*this);
	}

	// ���ϲ���Ԫ��
	template <class oTYPE>
	coF(coSet<oTYPE>&)	coSet<oTYPE>::operator += (const oTYPE& o_e) {
		if (!(*this > o_e)) {
			m_data.AddTail(o_e);
			m_count++;
		}
		return *this;
	}

	// ���ϲ��ϼ���
	template<class oTYPE>
	coF(coSet<oTYPE>&)	coSet<oTYPE>::operator += (const coSet<oTYPE>& o_s) {
		coINT	i;
		coINT	o_s_count = (coINT)o_s;
		for (i = 0; i < o_s_count; i++) {
			(*this) += o_s[i];
		}
		return *this;
	}

	// ���ϼ�ȥԪ��
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

	// ���ϼ�ȥ����
	template<class oTYPE>
	coF(coSet<oTYPE>&)	coSet<oTYPE>::operator -= (const coSet<oTYPE>& o_s) {
		coINT	i;
		coINT	o_s_count = (coINT)o_s;
		for (i = 0; i < o_s_count; i++) {
			(*this) -= o_s[i];
		}
		return *this;
	}

	// ������Ԫ�ز���
	template<class oTYPE>
	coF(coSet<oTYPE>)	coSet<oTYPE>::operator +  (const oTYPE& o_e) const {
		coSet<oTYPE>	r(*this);
		r += o_e;
		return r;
	}

	// �����뼯�ϲ���
	template<class oTYPE>
	coF(coSet<oTYPE>)	coSet<oTYPE>::operator +  (const coSet<oTYPE>& o_s) const {
		coSet<oTYPE>	r(*this);
		r += o_s;
		return r;
	}

	// ������Ԫ�ز
	template<class oTYPE>
	coF(coSet<oTYPE>)	coSet<oTYPE>::operator -  (const oTYPE& o_e) const {
		coSet<oTYPE>	r(*this);
		r -= o_e;
		return r;
	}

	// �����뼯�ϲ
	template<class oTYPE>
	coF(coSet<oTYPE>)	coSet<oTYPE>::operator -  (const coSet<oTYPE>& o_s) const {
		coSet<oTYPE>	r(*this);
		r -= o_s;
		return r;
	}

// �����ж�
	// �������
	template<class oTYPE>
	coF(coBOOL)	coSet<oTYPE>::operator == (const coSet<oTYPE>& o_s) const {
		coBOOL	r = coTRUE;
		if (m_count != o_s.m_count) r = coFALSE;
		else {
			for (coINT i = 0; i < m_count; i++) {
				// ��o_s��ĳ��Ԫ�ز����ڴ˼���, ��o_s��˼��ϲ���
				if (*this > o_s[i]) {
					r = coFALSE;
					break;
				}
			}
		}
		return r;
	}

	// ���ϲ���
	template<class oTYPE>
	coF(coBOOL)	coSet<oTYPE>::operator != (const coSet<oTYPE>& o_s) const {
		return !(*this == o_s);
	}

	// Ԫ�����ڼ���
	template<class oTYPE>
	coF(coBOOL)	coSet<oTYPE>::operator >  (const oTYPE& o_e) const {
		return m_data.Find(o_e) != NULL;
	}

	// ���������Ǵ˼��ϵ��Ӽ�
	template<class oTYPE>
	coF(coBOOL)	coSet<oTYPE>::operator >= (const coSet<oTYPE>& o_s) const {
		coBOOL	r = coTRUE;
		coINT	o_s_count = (coINT)o_s;
		for (coINT i = 0; i < o_s_count; i++) {
			// ��o_s��ĳ��Ԫ�ز����ڴ˼���, ��o_s���Ǵ˼��ϵ��Ӽ�
			if (!(*this > o_s[i])) {
				r = coFALSE;
				break;
			}
		}
		return r;
	}

	// �˼����Ǹ������ϵ��Ӽ�
	template<class oTYPE>
	coF(coBOOL)	coSet<oTYPE>::operator <= (const coSet<oTYPE>& o_s) const {
		coBOOL	r = coTRUE;
		for (coINT i = 0; i < m_count; i++) {
			// ���˼�����ĳ��Ԫ�ز�����o_s, ��˼��ϲ���o_s���Ӽ�
			if (!(o_s > (*this)[i])) {
				r = coFALSE;
				break;
			}
		}
		return r;
	}

	// ���������Ǵ˼��ϵ����Ӽ�
	template<class oTYPE>
	coF(coBOOL)	coSet<oTYPE>::operator >> (const coSet<oTYPE>& o_s) const {
		return (*this >= o_s) && (*this != o_s);
	}

	// �˼����Ǹ������ϵ����Ӽ�
	template<class oTYPE>
	coF(coBOOL)	coSet<oTYPE>::operator << (const coSet<oTYPE>& o_s) const {
		return (*this <= o_s) && (*this != o_s);
	}

// ����ת��

	// ȡԪ��
	template<class oTYPE>
	coF(oTYPE)	coSet<oTYPE>::operator [] (const coINT index) const {
		coINT		list_index = (coINT)index;
		POSITION	pos = m_data.FindIndex(index);
		return m_data.GetAt(pos);
	}

	// ����Ԫ��
	template<class oTYPE>
	coF(oTYPE&)	coSet<oTYPE>::operator [] (const coINT index) {
		coINT		list_index = (coINT)index;
		POSITION	pos = m_data.FindIndex(index);
		return m_data.GetAt(pos);
	}

	// ȡԪ�ظ���
	template<class oTYPE>
	coP		coSet<oTYPE>::operator coINT () const {
		//return (coINT)m_data.GetCount();
		return m_count;
	}
