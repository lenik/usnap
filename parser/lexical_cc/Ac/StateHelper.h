
#pragma once

#include <string>
#include <list>
using namespace std;

// state table

typedef long character;
typedef list<character> chars;

struct jmp {
	chars acceptchars;
	string statename;
	string beforejmp;
	string injmp;
	string afterjmp;
};
typedef list<jmp> jmps;

struct state {
	string name;
	jmps jmptable;
};
typedef list<state> states;


states sts;
state* findsts(string name) {
	states::iterator i;
	for (i = sts.begin(); i != sts.end(); ++i) {
		if ((*i).name == name) return &(*i);
	}
	return NULL;
}
