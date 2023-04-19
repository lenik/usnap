
#pragma once

#include <string>
#include <list>
using namespace std;

// state table

#define CHAR_FULLRANGE	0x0100207E
#define CHAR_ELSE	0x02000000
#define CHAR_ALL	0x03000000
#define CHAR_ANY	0x10000000

typedef long character;
typedef list<long> chars;
typedef list<string> strings;

enum _jmp_type_enum {
	jmp_none,
	jmp_normal,
	jmp_call,
	jmp_exit
};
struct jmp {
	bool defined;
	chars chars;
	_jmp_type_enum type;
	string switchs;
	string target;
	string Eb;
	string Ej;
	string Ee;
	string Ea; 	// only all' jmp is valid.
};
typedef list<jmp> jmps;

struct state {
	long s_id;	// 后期分配的序号
	string name;
	jmp all;
	jmp any;
	jmp other;
	jmps jmptable;
};
typedef list<state> states;

struct userproc {
	string procname;
	string procdesc;
};
typedef list<userproc> userprocs;
userprocs ups;

states sts;
state* findsts(string name) {
	states::iterator i;
	for (i = sts.begin(); i != sts.end(); ++i) {
		if ((*i).name == name) return &(*i);
	}
	return NULL;
}
bool inrange(character in, character out) {
	if (in == out) return true;
	long i1, i2, o1, o2;
	switch (in >> 24) {
	case 0:
		i1 = i2 = in;
		break;
	case 1:
		i1	= (in & 0x0000FF00) >> 8;
		i2	= in & 0x000000FF;
		break;
	default:
		return false;
	}
	switch (out >> 24) {
	case 0:
		o1 = o2 = out;
		break;
	case 1:
		o1	= (out & 0x0000FF00) >> 8;
		o2	= out & 0x000000FF;
		break;
	default:
		return false;
	}
	return (i1 >= o1 && i2 <= o2);
}

jmp* findjmp(state *st, character c) {
	switch (c) {
	case CHAR_ALL:
		return &(st->all);
	case CHAR_ANY:
		return &(st->any);
	case CHAR_ELSE:
		return &(st->other);
	default:
		jmps::iterator i;
		for (i = st->jmptable.begin(); i != st->jmptable.end(); ++i) {
			chars::iterator j;
			for (j = (*i).chars.begin(); j != (*i).chars.end(); ++j) {
				if (inrange(c, *j)) {
					//c in st->jmptable[i].chars[j]
					return &(*i);
				}
			}
		}
	}
	return NULL;
}

void adduserproc(char *name, char *desc) {
	userproc u;
	u.procname = name;
	u.procdesc = desc;
	ups.push_back(u);
}
