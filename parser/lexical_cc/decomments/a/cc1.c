// Automation compiler 编译模板文件
// C++ 版本

// 状态常量


#define A_cc_s                   	0x00000000
#define A_cc_a                   	0x00000001
#define A_cc_n                   	0x00000002
#define A_cc_b                   	0x00000003
#define A_cc_c                   	0x00000004
#define A_cc_d                   	0x00000005
#define A_cc_e                   	0x00000006
#define A_cc_START               	0x00000000
#define A_cc_END                 	0x00000006

// 类型定义
#define A_cc_calltype	_stdcall

#include <list>
#include <stack>
using namespace std;

typedef long character;
typedef list<character> buffer;
typedef list<buffer> buffers;

typedef long state;
typedef stack<state> statestack;

typedef character (A_cc_calltype *A_cc_input_proc)(buffers& ib, int protect_level);
typedef void (A_cc_calltype *A_cc_user_proc)(state S1, state S2, character c, buffer& accept_buffer);

// 函数原型

character A_cc_calltype A_cc_getc();
character A_cc_calltype A_cc_input(buffers& ib, int pl);
state A_cc_calltype A_cc_loop(A_cc_input_proc ip, int& pl, buffers& ib, buffers& ab, statestack& ss, state& s);
bool A_cc_calltype A_cc_main();

// 用户函数原型

void A_cc_calltype A_cc_out(state S1, state S2, character c, buffer& ab);
void A_cc_calltype A_cc_clear(state S1, state S2, character c, buffer& ab);

// 默认处理

character A_cc_calltype A_cc_getc() {
	return (character)fgetc(stdin);
}

character A_cc_calltype A_cc_input(buffers& ib, int pl) {
	character r;
	if (ib.front().size() > 0) {
		r = ib.front().front();
		ib.front().pop_front();
	} else {
		r = A_cc_getc();
		if (pl > 0) {
			buffers::iterator i = ib.begin();
			++i;
			for (; i != ib.end(); ++i) {
				(*i).push_back(r);
			}
		}
	}
	return r;
}


state A_cc_calltype A_cc_loop(
	A_cc_input_proc ip,
	int& pl,		// protect level. 0 default
	buffers& ib,
	buffers& ab,
	statestack& ss,
	state& s) {
	state	old_state	= s;
	state	new_state	= s;
	state	jump_type	= 0; // none:0 j1 c2 x3
	char *	jump_switchs	= NULL;

	/* S is s */
	character c = ip(ib, pl);

// 主处理函数

// Eb

switch (s) {
case A_cc_s:
	switch (c) {
	case '/':
		jump_type	= 1;
		jump_switchs	= "-";
		new_state	= A_cc_a;
		break;
	case '!':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_cc_e;
		break;
	default:
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_cc_s;
		break;
}
break;
case A_cc_a:
	switch (c) {
	case '*':
		jump_type	= 1;
		jump_switchs	= "-";
		new_state	= A_cc_b;
		break;
	default:
		jump_type	= 1;
		jump_switchs	= "+";
		new_state	= A_cc_n;
		break;
}
break;
case A_cc_n:
	switch (c) {
	case '\ ':
	case '!':
	case '\"':
	case '#':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '(':
	case ')':
	case '*':
	case '+':
	case ',':
	case '-':
	case '\.':
	case '/':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case '\:':
	case ';':
	case '<':
	case '=':
	case '>':
	case '?':
	case '@':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '[':
	case '\\':
	case ']':
	case '^':
	case '_':
	case '`':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case '{':
	case '|':
	case '}':
	case '~':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_cc_s;
		break;
}
break;
case A_cc_b:
	switch (c) {
	case '*':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_cc_c;
		break;
	default:
		jump_type	= 1;
		jump_switchs	= "+";
		new_state	= A_cc_d;
		break;
}
break;
case A_cc_c:
	switch (c) {
	case '/':
		jump_type	= 1;
		jump_switchs	= "+*";
		new_state	= A_cc_s;
		break;
	default:
		jump_type	= 1;
		jump_switchs	= "+";
		new_state	= A_cc_d;
		break;
}
break;
case A_cc_d:
	switch (c) {
	case '\ ':
	case '!':
	case '\"':
	case '#':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '(':
	case ')':
	case '*':
	case '+':
	case ',':
	case '-':
	case '\.':
	case '/':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case '\:':
	case ';':
	case '<':
	case '=':
	case '>':
	case '?':
	case '@':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '[':
	case '\\':
	case ']':
	case '^':
	case '_':
	case '`':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case '{':
	case '|':
	case '}':
	case '~':
		jump_type	= 1;
		jump_switchs	= "-";
		new_state	= A_cc_b;
		break;
}
break;
}

		ab.front().push_front(c);
		if (jump_switchs != NULL) {
			for (char *js = jump_switchs; *js; js++) {
				switch (*js) {
				case '-':
					ib.push_front(ib.front());
					ab.push_front(ab.front());
					pl++;
					break;
				case '+':
					ib.pop_front();
					ab.pop_front();
					pl--;
					break;
				case '*':
					{
						buffer ib2 = ib.front();
						buffer ab2 = ab.front();
						ib.pop_front();
						ab.pop_front();
						ib.front() = ib2;
						ab.front() = ab2;
					}
					pl--;
					break;
				} // switch *js
			} // for js
		} // if jump_switchs

	// Ej

	if (jump_type) {
		switch (s) {
	default:
A_cc_out(s, new_state, c, ab.front());
		break;
case A_cc_c:
	switch (c) {
	case '/':
		A_cc_clear(s, new_state, c, ab.front());
		break;
	} // switch c
	break;
} // switch s
} // if jump


s	= new_state;


	// Ea

	if (jump_type) {
		switch (s) {
}
}


	// Ee

	if (jump_type) {
		switch (s) {
}
}


	return s;
}

bool A_cc_calltype A_cc_main() {
	buffers		protect_input_buffers;
	buffers		protect_accept_buffers;
	statestack	nestcall_statestack;

	state		current_state = A_cc_START;
	int		protect_level = 0;

	protect_input_buffers.push_front(*(new buffer));
	protect_accept_buffers.push_front(*(new buffer));

	do {
		A_cc_loop(
			A_cc_input,
			protect_level,
			protect_input_buffers,
			protect_accept_buffers,
			nestcall_statestack,
			current_state);
	} while (current_state != A_cc_END);			// B2
	return true;
}

void A_cc_calltype A_cc_out(state S1, state S2, character c, buffer& ab) {
	while (ab.size()) {
		character c = ab.back();
		printf("%c", c);
		ab.pop_back();
	}
	return;
}

void A_cc_calltype A_cc_clear(state S1, state S2, character c, buffer& ab) {
	ab.clear();
	return;
}


// 缺省框架

#ifdef USE_DEFAULT_FRAME
void main() {
	A_cc_main();
}
#endif
