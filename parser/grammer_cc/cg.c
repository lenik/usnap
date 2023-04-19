// Automation compiler 编译模板文件
// C++ 版本

// 状态常量


#define A_cg_s                   	0x00000000
#define A_cg_numstart            	0x00000001
#define A_cg_e                   	0x00000002
#define A_cg_START               	0x00000000
#define A_cg_END                 	0x00000002

// 类型定义
#define A_cg_calltype	_stdcall

#include <list>
#include <stack>
using namespace std;

typedef long character;
typedef list<character> buffer;
typedef list<buffer> buffers;

typedef long state;
typedef stack<state> statestack;

typedef character (A_cg_calltype *A_cg_input_proc)(buffers& ib, int protect_level);
typedef void (A_cg_calltype *A_cg_user_proc)(state S1, state S2, character c, buffer& accept_buffer);

// 函数原型

character A_cg_calltype A_cg_getc();
character A_cg_calltype A_cg_input(buffers& ib, int pl);
state A_cg_calltype A_cg_loop(A_cg_input_proc ip, int& pl, buffers& ib, buffers& ab, statestack& ss, state& s);
bool A_cg_calltype A_cg_main();

// 用户函数原型

void A_cg_calltype A_cg_ret_plus(state S1, state S2, character c, buffer& ab);
void A_cg_calltype A_cg_ret_minus(state S1, state S2, character c, buffer& ab);
void A_cg_calltype A_cg_ret_ast(state S1, state S2, character c, buffer& ab);
void A_cg_calltype A_cg_ret_slash(state S1, state S2, character c, buffer& ab);
void A_cg_calltype A_cg_ret_power(state S1, state S2, character c, buffer& ab);
void A_cg_calltype A_cg_ret_leftb(state S1, state S2, character c, buffer& ab);
void A_cg_calltype A_cg_ret_rightb(state S1, state S2, character c, buffer& ab);
void A_cg_calltype A_cg_clearB(state S1, state S2, character c, buffer& ab);
void A_cg_calltype A_cg_ret_NUM(state S1, state S2, character c, buffer& ab);

// 默认处理


character A_cg_calltype A_cg_input(buffers& ib, int pl) {
	character r;
	if (ib.front().size() > 0) {
		r = ib.front().front();
		ib.front().pop_front();
	} else {
		r = A_cg_getc();
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


state A_cg_calltype A_cg_loop(
	A_cg_input_proc ip,
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
case A_cg_s:
	switch (c) {
	case '\ ':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_cg_s;
		break;
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
		jump_type	= 1;
		jump_switchs	= "-";
		new_state	= A_cg_numstart;
		break;
	case '+':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_cg_s;
		break;
	case '-':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_cg_s;
		break;
	case '*':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_cg_s;
		break;
	case '/':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_cg_s;
		break;
	case '^':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_cg_s;
		break;
	case '(':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_cg_s;
		break;
	case ')':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_cg_s;
		break;
} // switch c
break;
case A_cg_numstart:
	switch (c) {
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
		jump_type	= 1;
		jump_switchs	= "*-";
		new_state	= A_cg_numstart;
		break;
	case '\.':
		jump_type	= 1;
		jump_switchs	= "*-";
		new_state	= A_cg_numstart;
		break;
	default:
		jump_type	= 1;
		jump_switchs	= "+";
		new_state	= A_cg_s;
		break;
} // switch c
break;
} // switch s

if (c == EOF) new_state = A_cg_e;

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
case A_cg_s:
	switch (c) {
	case '\ ':
		break;
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
		break;
	case '+':
		A_cg_ret_plus(s, new_state, c, ab.front());
		break;
	case '-':
		A_cg_ret_minus(s, new_state, c, ab.front());
		break;
	case '*':
		A_cg_ret_ast(s, new_state, c, ab.front());
		break;
	case '/':
		A_cg_ret_slash(s, new_state, c, ab.front());
		break;
	case '^':
		A_cg_ret_power(s, new_state, c, ab.front());
		break;
	case '(':
		A_cg_ret_leftb(s, new_state, c, ab.front());
		break;
	case ')':
		A_cg_ret_rightb(s, new_state, c, ab.front());
		break;
} // switch c
break;
case A_cg_numstart:
	switch (c) {
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
		break;
	case '\.':
		break;
	default:
		A_cg_ret_NUM(s, new_state, c, ab.front());
		break;
} // switch c
break;
} // switch s
} // if jump


s	= new_state;


	// Ea
		switch (s) {
case A_cg_s:
	A_cg_clearB(s, new_state, c, ab.front());
	break;
} // switch s


// Ee

if (jump_type) {
switch (old_state) {
case A_cg_s:
	switch (c) {
	case '\ ':
		break;
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
		break;
	case '+':
		break;
	case '-':
		break;
	case '*':
		break;
	case '/':
		break;
	case '^':
		break;
	case '(':
		break;
	case ')':
		break;
} // switch c
break;
case A_cg_numstart:
	switch (c) {
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
		break;
	case '\.':
		break;
	default:
		break;
} // switch c
break;
} // switch s
} // if jump


	return s;
}

bool A_cg_calltype A_cg_main() {
	buffers		protect_input_buffers;
	buffers		protect_accept_buffers;
	statestack	nestcall_statestack;

	state		current_state = A_cg_START;
	int		protect_level = 0;

	protect_input_buffers.push_front(*(new buffer));
	protect_accept_buffers.push_front(*(new buffer));

	do {
		A_cg_loop(
			A_cg_input,
			protect_level,
			protect_input_buffers,
			protect_accept_buffers,
			nestcall_statestack,
			current_state);
	} while (current_state != A_cg_END);			// B2
	return true;
}


// 缺省框架

#ifdef USE_A_cg_FRAME

void A_cg_calltype A_cg_ret_plus(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_cg_calltype A_cg_ret_minus(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_cg_calltype A_cg_ret_ast(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_cg_calltype A_cg_ret_slash(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_cg_calltype A_cg_ret_power(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_cg_calltype A_cg_ret_leftb(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_cg_calltype A_cg_ret_rightb(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_cg_calltype A_cg_clearB(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_cg_calltype A_cg_ret_NUM(state S1, state S2, character c, buffer& ab) {
	return;
}

void main() {
	A_cg_main();
}

#endif
