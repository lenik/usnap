
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
		left_assoc = 0,		// 左结合优先
		right_assoc,		// 右结合优先
		no_assoc		// 无结合优先
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
	int precedence;		// 默然优先级
	_assoc_enum assoc;	// 默然结合性

	typedef std::string symtype_type;
	symtype_type type;	// 类型描述

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
	bool cache_by_sis();		// 根据符号表建立缓存
	symbol_info *getsymbol(sym _s);
};


_LEX_END
