
#pragma once

#include <list>

// 产生式结构

typedef int symbol;
struct production;

typedef list<symbol> symbols;
typedef list<symbols> symbolss;
typedef list<production> productions;

// l -> r
//	l ->* (f1|f2|f3|..|fn).*, first(l)=union(f1,..,fn)
//	any V ->* (l)f, follow(l)=union(f)
struct production {
	symbol	l;
	symbolss r;
	symbols	first;
	symbols	follow;
};
