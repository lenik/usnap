
// �н�ɨ���㷨

// Mr.л 2002.1.4-
// HiTech @ �й��㽭

#pragma once

#include <his/hisdef.h>

#define MAXH		64
#define MAXW		64
#define MAXTH		8
#define MAXTW		8

#define CLOSED		0
#define OPENED		1
#define MARKED		2
#define WARNED		3

_HIS_BEGIN
	template<class Tkey, class Tvalue>
	class hash {
	public:
		typedef Tkey key_type;
		typedef Tvalue value_type;
		hash() : key(Tkey()), value(Tvalue()) {}
		hash(const Tkey& _k, const Tvalue& _v) : key(_k), value(_v) {}
		template<class _Tkey2, class _Tvalue2>
			hash(const hash<_Tkey2, _Tvalue2>& o_o) : key(o_o.key), value(o_o.value) {}
	public:
		Tkey	key;
		Tvalue	value;
	};

	template<class Tkey, class Tvalue>
	class hashes {
	public:
		typedef hash<Tkey, Tvalue> hash_type;
		typedef hash_type::key_type key_type;
		typedef hash_type::value_type value_type;
		typedef std::list<hash_type> hashlist;
		typedef hashlist::size_type size_type;
		hashes() : m_list(hashlist()) {}
		hashes(const hashes& o_o) : m_list(o_o.m_list) {}
	public:
		Tvalue *operator()(const Tkey& key) {
			hashlist::iterator i;
			for (i = m_list.begin(); i != m_list.end(); ++i) {
				if (i->key == key) {
					return &(i->value);
				}
			}
			return NULL;
		}
		hash_type *operator[](int i) {
			if  (i < 0 || i >= size()) return NULL;
			hashlist::iterator it;
			for (it = m_list.begin(); it != m_list.end() && i > 0; ++it, --i);

			if (i > 0) {
				__assume(0);
				return NULL;
			}
			return &*it;
		}
		size_type size() {
			return m_list.size();
		}

	public:
		hashlist	m_list;
	};

_HIS_END

class MineMap {
public:
	struct MineUnit {
		BOOL	bMined;
		int	areaCount;
		int	state;
	};

	MineUnit map[MAXH][MAXW];
	int	width;
	int	height;

	BOOL	lookt[MAXTH][MAXTW];	// �ο����ܱ�
	int	twidth;
	int	theight;
	int	tX;			// ���ĵ�
	int	tY;

	void randomMap();
	void click(int x, int y);
	// �ɸ������ҳ���ǰ���Ե�֪�Ľ�, ���û�ж����򷵻�FALSE
	BOOL hint_byprob(int& x, int& y);
	// �ɿ������ҳ���ǰ���Ե�֪�Ľ�, ���û�ж����򷵻�FALSE
	BOOL hint_byblock(int& x, int& y);

public:
	MineMap();
};
