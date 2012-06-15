// Automation compiler 编译模板文件
// C++ 版本

// 状态常量


#define A_ig2_s                   	0x00000000
#define A_ig2_v                   	0x00000001
#define A_ig2_e                   	0x00000002
#define A_ig2_START               	0x00000000
#define A_ig2_END                 	0x00000002

// 类型定义
#define A_ig2_calltype	_stdcall

#include <list>
#include <stack>
using namespace std;

typedef long character;
typedef list<character> buffer;
typedef list<buffer> buffers;

typedef long state;
typedef stack<state> statestack;

typedef character (A_ig2_calltype *A_ig2_input_proc)(buffers& ib, int protect_level);
typedef void (A_ig2_calltype *A_ig2_user_proc)(state S1, state S2, character c, buffer& accept_buffer);

// 函数原型

character A_ig2_calltype A_ig2_getc();
character A_ig2_calltype A_ig2_input(buffers& ib, int pl);
state A_ig2_calltype A_ig2_loop(A_ig2_input_proc ip, int& pl, buffers& ib, buffers& ab, statestack& ss, state& s);
bool A_ig2_calltype A_ig2_main();

// 用户函数原型

void A_ig2_calltype A_ig2_out(state S1, state S2, character c, buffer& ab);
void A_ig2_calltype A_ig2_clear(state S1, state S2, character c, buffer& ab);

// 默认处理

character A_ig2_calltype A_ig2_getc() {
	return (character)fgetc(stdin);
}

character A_ig2_calltype A_ig2_input(buffers& ib, int pl) {
	character r;
	if (ib.front().size() > 0) {
		r = ib.front().front();
		ib.front().pop_front();
	} else {
		r = A_ig2_getc();
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


state A_ig2_calltype A_ig2_loop(
	A_ig2_input_proc ip,
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
case A_ig2_s:
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
		new_state	= A_ig2_v;
		break;
}
break;
case A_ig2_v:
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
		new_state	= A_ig2_s;
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
case A_ig2_s:
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
		A_ig2_out(s, new_state, c, ab.front());
		break;
}
}
break;
case A_ig2_v:
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
		A_ig2_clear(s, new_state, c, ab.front());
		break;
}
}
break;
}


s	= new_state;


	// Ea

	if (jump_type) {
		switch (s) {
}
}

// Ee

if (jump_type) {
switch (oldstate) {
}


	return s;
}

bool A_ig2_calltype A_ig2_main() {
	buffers		protect_input_buffers;
	buffers		protect_accept_buffers;
	statestack	nestcall_statestack;

	state		current_state = A_ig2_START;
	int		protect_level = 0;

	protect_input_buffers.push_front(*(new buffer));
	protect_accept_buffers.push_front(*(new buffer));

	do {
		A_ig2_loop(
			A_ig2_input,
			protect_level,
			protect_input_buffers,
			protect_accept_buffers,
			nestcall_statestack,
			current_state);
	} while (current_state != A_ig2_END);			// B2
	return true;
}

void A_ig2_calltype A_ig2_out(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_ig2_calltype A_ig2_clear(state S1, state S2, character c, buffer& ab) {
	return;
}


// 缺省框架

#ifdef USE_A_ig2_FRAME
void main() {
	A_ig2_main();
}
#endif
