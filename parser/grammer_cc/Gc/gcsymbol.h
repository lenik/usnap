
#pragma once

#pragma warning(disable: 4786)

#include <string>
#include <list>
#include <valarray>

#define _LEX_BEGIN	namespace lex {
#define _LEX_END	};

_LEX_BEGIN

typedef int sym;
typedef std::list<sym> syms;
typedef std::list<syms> symss;

class symbol_info;
class production;

typedef std::list<production> productions;

enum _assoc_enum {
		left_assoc = 0,		// ��������
		right_assoc,		// �ҽ������
		no_assoc		// �޽������
};

//	sym ->* (f1|f2|f3|..|fn).*, first(l)=union(f1,..,fn)
//	any V ->* (l)f, follow(l)=union(f)
class production {
public:
	syms def;
	int precedence;
	_assoc_enum assoc;
protected:
	syms ts_first;
	syms ts_follow;

	// friend ...
};

class symbol_info {
public:
	sym thissym;
	int precedence;		// ĬȻ���ȼ�
	_assoc_enum assoc;	// ĬȻ�����

	typedef std::string symtype_type;
	symtype_type type;	// ��������

	productions prods;
};

// cache
class adv_symbols {
public:
	typedef std::valarray<symbol_info> symbol_infos;
	typedef std::pair<sym, symbol_info *> symentry;
	typedef std::valarray<symentry> symmap;

	symbol_infos	sis;
	symmap		cachemap;

public:
	bool cache_by_sis();		// ���ݷ��ű�������
	symbol_info *getsymbol(sym _s);
};


_LEX_END
